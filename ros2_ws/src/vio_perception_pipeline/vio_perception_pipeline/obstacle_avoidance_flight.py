#!/usr/bin/env python3
"""
Obstacle avoidance flight node.

Implements a five-phase autonomous flight sequence via MAVROS OFFBOARD mode:

  1. Takeoff  – climb to a configured altitude.
  2. Forward  – move forward at a slow, configurable speed.
  3. Stop     – halt all motion when an obstacle is detected within the
                configured distance threshold.
  4. Turn     – rotate 180 degrees about the yaw axis to face away from the
                obstacle.
  5. Land     – descend via AUTO.LAND and wait for disarm.

Obstacle detection uses the 5th-percentile depth value inside the central
quarter of the OAK-D stereo depth image.  This filters sparse noise while
remaining sensitive to real obstacles.

MAVROS plugins required in the allowlist:
  ``setpoint_velocity`` – velocity setpoint streaming for OFFBOARD control
  ``local_position``    – altitude feedback from PX4 EKF2
  ``command``           – arm, land commands
  ``sys_status``        – armed / flight-mode feedback
"""

import math

import numpy as np
import rclpy
from cv_bridge import CvBridge
from geometry_msgs.msg import PoseStamped, TwistStamped
from mavros_msgs.msg import State
from mavros_msgs.srv import CommandBool, CommandTOL, SetMode
from rclpy.node import Node
from sensor_msgs.msg import Image


class ObstacleAvoidanceFlight(Node):
    """State-machine node for obstacle-aware autonomous flight via MAVROS.

    The node drives the drone through:
    INIT → ARMING → TAKEOFF → FORWARD → STOPPING → TURNING → LANDING → DONE.
    """

    # State identifiers
    _ST_INIT = 'INIT'
    _ST_ARMING = 'ARMING'
    _ST_TAKEOFF = 'TAKEOFF'
    _ST_FORWARD = 'FORWARD'
    _ST_STOPPING = 'STOPPING'
    _ST_TURNING = 'TURNING'
    _ST_LANDING = 'LANDING'
    _ST_DONE = 'DONE'

    def __init__(self):
        super().__init__('obstacle_avoidance_flight')

        # ------------------------------------------------------------------
        # Parameters
        # ------------------------------------------------------------------
        self.declare_parameter('takeoff_height', 1.5)       # metres
        self.declare_parameter('forward_speed', 0.3)        # m/s
        self.declare_parameter('obstacle_threshold', 1.5)   # metres
        self.declare_parameter('turn_rate', 0.5)            # rad/s
        self.declare_parameter('climb_rate', 0.5)           # m/s
        self.declare_parameter('mission_start_delay', 5.0)  # seconds

        self._takeoff_height = self.get_parameter('takeoff_height').value
        self._forward_speed = self.get_parameter('forward_speed').value
        self._obs_threshold = self.get_parameter('obstacle_threshold').value
        self._turn_rate = self.get_parameter('turn_rate').value
        self._climb_rate = self.get_parameter('climb_rate').value
        self._start_delay = self.get_parameter('mission_start_delay').value

        # ------------------------------------------------------------------
        # Internal state
        # ------------------------------------------------------------------
        self._state = self._ST_INIT
        self._bridge = CvBridge()
        self._mavros_state = State()
        self._current_alt = 0.0
        self._obstacle_close = False
        self._init_count = 0        # zero-setpoints streamed before arming
        self._phase_start = None    # clock time when current state began
        self._node_start = self.get_clock().now()

        # ------------------------------------------------------------------
        # Publishers
        # ------------------------------------------------------------------
        self._vel_pub = self.create_publisher(
            TwistStamped, '/mavros/setpoint_velocity/cmd_vel', 10)

        # ------------------------------------------------------------------
        # Subscribers
        # ------------------------------------------------------------------
        self.create_subscription(
            State, '/mavros/state', self._mavros_state_cb, 10)
        self.create_subscription(
            PoseStamped, '/mavros/local_position/pose', self._pose_cb, 10)
        self.create_subscription(
            Image, '/oak/stereo/image_raw', self._depth_cb, 10)

        # ------------------------------------------------------------------
        # Service clients
        # ------------------------------------------------------------------
        self._arming_cli = self.create_client(CommandBool, '/mavros/cmd/arming')
        self._mode_cli = self.create_client(SetMode, '/mavros/set_mode')
        self._land_cli = self.create_client(CommandTOL, '/mavros/cmd/land')

        # ------------------------------------------------------------------
        # 20 Hz control loop
        # ------------------------------------------------------------------
        self.create_timer(0.05, self._loop)
        self.get_logger().info('obstacle_avoidance_flight node started')

    # ----------------------------------------------------------------------
    # ROS callbacks
    # ----------------------------------------------------------------------

    def _mavros_state_cb(self, msg: State) -> None:
        """Store latest MAVROS system state."""
        self._mavros_state = msg

    def _pose_cb(self, msg: PoseStamped) -> None:
        """Store current altitude from PX4 local position (ENU z, metres)."""
        self._current_alt = msg.pose.position.z

    def _depth_cb(self, msg: Image) -> None:
        """Detect obstacles from the forward-facing depth image.

        Active only in the FORWARD state.  Sets ``_obstacle_close`` when the
        5th-percentile valid depth inside the central image ROI is below
        ``_obs_threshold``.
        """
        if self._state != self._ST_FORWARD:
            return
        try:
            img = self._bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
            h, w = img.shape[:2]
            # Middle half of the image in each dimension as the forward-facing ROI
            r0, r1 = h // 4, 3 * h // 4
            c0, c1 = w // 4, 3 * w // 4
            roi = img[r0:r1, c0:c1].astype(np.float32)
            valid = roi[roi > 0]
            if valid.size == 0:
                return
            # 16UC1 depth is in millimetres; 32FC1 is in metres
            factor = 1e-3 if msg.encoding == '16UC1' else 1.0
            min_dist = float(np.percentile(valid, 5)) * factor
            if min_dist < self._obs_threshold:
                if not self._obstacle_close:
                    self.get_logger().info(
                        f'Obstacle detected at {min_dist:.2f} m '
                        f'(threshold {self._obs_threshold} m)')
                self._obstacle_close = True
        except Exception as exc:
            self.get_logger().error(f'Depth image processing error: {exc}')

    # ----------------------------------------------------------------------
    # Main control loop
    # ----------------------------------------------------------------------

    def _loop(self) -> None:
        """20 Hz state-machine tick."""
        now = self.get_clock().now()
        uptime = (now - self._node_start).nanoseconds * 1e-9

        if self._state == self._ST_INIT:
            # Stream zero setpoints so PX4 accepts the OFFBOARD mode switch
            self._publish_vel(0.0, 0.0, 0.0)
            self._init_count += 1
            if uptime >= self._start_delay and self._init_count >= 20:
                self.get_logger().info('Initial setpoints ready – arming...')
                self._enter(self._ST_ARMING, now)

        elif self._state == self._ST_ARMING:
            self._publish_vel(0.0, 0.0, 0.0)
            if not self._mavros_state.armed:
                self._call_arm(True)
            elif self._mavros_state.mode != 'OFFBOARD':
                self._call_set_mode('OFFBOARD')
            else:
                self.get_logger().info(
                    f'Armed and OFFBOARD – climbing to {self._takeoff_height:.1f} m...')
                self._enter(self._ST_TAKEOFF, now)

        elif self._state == self._ST_TAKEOFF:
            if self._current_alt < self._takeoff_height - 0.1:
                self._publish_vel(0.0, 0.0, self._climb_rate)
            else:
                self._publish_vel(0.0, 0.0, 0.0)
                self.get_logger().info(
                    f'Reached {self._current_alt:.2f} m – moving forward...')
                self._enter(self._ST_FORWARD, now)

        elif self._state == self._ST_FORWARD:
            if self._obstacle_close:
                self.get_logger().info('Obstacle detected – stopping forward motion...')
                self._enter(self._ST_STOPPING, now)
            else:
                self._publish_vel(self._forward_speed, 0.0, 0.0)

        elif self._state == self._ST_STOPPING:
            self._publish_vel(0.0, 0.0, 0.0)
            if self._phase_elapsed(now) >= 1.0:
                self.get_logger().info('Stopped – turning 180 degrees...')
                self._enter(self._ST_TURNING, now)

        elif self._state == self._ST_TURNING:
            # Rotate at turn_rate rad/s for exactly pi radians (180 deg)
            turn_dur = math.pi / self._turn_rate
            if self._phase_elapsed(now) < turn_dur:
                self._publish_vel(0.0, 0.0, 0.0, yaw_rate=self._turn_rate)
            else:
                self._publish_vel(0.0, 0.0, 0.0)
                self.get_logger().info('Turn complete – landing...')
                self._enter(self._ST_LANDING, now)
                self._call_land()

        elif self._state == self._ST_LANDING:
            # Keep streaming setpoints so MAVROS does not time out
            self._publish_vel(0.0, 0.0, 0.0)
            if not self._mavros_state.armed:
                self.get_logger().info('Landed and disarmed – mission complete.')
                self._enter(self._ST_DONE, now)

        # _ST_DONE: nothing left to do

    # ----------------------------------------------------------------------
    # Helpers
    # ----------------------------------------------------------------------

    def _enter(self, new_state: str, now) -> None:
        """Transition to *new_state* and record the transition time."""
        self._state = new_state
        self._phase_start = now

    def _phase_elapsed(self, now) -> float:
        """Return seconds elapsed since the current state was entered."""
        if self._phase_start is None:
            return 0.0
        return (now - self._phase_start).nanoseconds * 1e-9

    def _publish_vel(
        self, vx: float, vy: float, vz: float, yaw_rate: float = 0.0
    ) -> None:
        """Publish a TwistStamped velocity setpoint to MAVROS."""
        msg = TwistStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'base_link'
        msg.twist.linear.x = vx
        msg.twist.linear.y = vy
        msg.twist.linear.z = vz
        msg.twist.angular.z = yaw_rate
        self._vel_pub.publish(msg)

    def _call_arm(self, value: bool) -> None:
        """Request arm/disarm via MAVROS service (fire-and-forget)."""
        if not self._arming_cli.service_is_ready():
            return
        req = CommandBool.Request()
        req.value = value
        self._arming_cli.call_async(req)

    def _call_set_mode(self, mode: str) -> None:
        """Request a PX4 flight mode change via MAVROS service."""
        if not self._mode_cli.service_is_ready():
            return
        req = SetMode.Request()
        req.custom_mode = mode
        self._mode_cli.call_async(req)

    def _call_land(self) -> None:
        """Request AUTO.LAND via MAVROS command service."""
        if not self._land_cli.service_is_ready():
            return
        self._land_cli.call_async(CommandTOL.Request())


def main(args=None):
    """Entry point for the obstacle_avoidance_flight console script."""
    rclpy.init(args=args)
    node = ObstacleAvoidanceFlight()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
