#!/usr/bin/env python3
"""
ENU to NED Coordinate Transformer Node

Transforms RTAB-Map odometry output (ENU/FLU) to PX4 coordinate system (NED/FRD).

Coordinate Systems:
    RTAB-Map (ROS standard):
        - World frame: ENU (East-North-Up)
        - Body frame: FLU (Forward-Left-Up)
    
    PX4:
        - World frame: NED (North-East-Down)
        - Body frame: FRD (Forward-Right-Down)

Transformations:
    Position: ENU -> NED
        x_ned =  y_enu  (North = ENU's Y)
        y_ned =  x_enu  (East = ENU's X)
        z_ned = -z_enu  (Down = -Up)
    
    Orientation: ENU/FLU -> NED/FRD
        q_ned_frd = q_enu_to_ned * q_enu_flu * q_flu_to_frd
        where:
            q_enu_to_ned = 180° rotation about (1,1,0)/√2 axis
            q_flu_to_frd = 180° rotation about X axis
    
    Linear Velocity: Same as position
    Angular Velocity: FLU -> FRD
        wx_frd =  wx_flu  (roll unchanged)
        wy_frd = -wy_flu  (pitch flipped)
        wz_frd = -wz_flu  (yaw flipped)
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped, TwistStamped, TransformStamped
from tf2_ros import TransformBroadcaster
import numpy as np
from scipy.spatial.transform import Rotation


class EnuToNedTransformer(Node):
    """ROS2 node that transforms odometry from ENU/FLU to NED/FRD."""

    def __init__(self):
        super().__init__("enu_to_ned_transformer")

        # Declare parameters
        self.declare_parameter("input_odom_topic", "/odom")
        self.declare_parameter("output_odom_topic", "/odom_ned")
        self.declare_parameter("output_pose_topic", "/mavros/vision_pose/pose")
        self.declare_parameter("output_twist_topic", "/mavros/vision_speed/speed_twist")
        self.declare_parameter("publish_pose", True)
        self.declare_parameter("publish_twist", True)
        self.declare_parameter("publish_tf", True)
        self.declare_parameter("ned_frame_id", "odom_ned")
        self.declare_parameter("frd_child_frame_id", "base_link_frd")

        # Get parameters
        input_topic = self.get_parameter("input_odom_topic").value
        output_odom_topic = self.get_parameter("output_odom_topic").value
        output_pose_topic = self.get_parameter("output_pose_topic").value
        output_twist_topic = self.get_parameter("output_twist_topic").value
        self.publish_pose = self.get_parameter("publish_pose").value
        self.publish_twist = self.get_parameter("publish_twist").value
        self.publish_tf = self.get_parameter("publish_tf").value
        self.ned_frame_id = self.get_parameter("ned_frame_id").value
        self.frd_child_frame_id = self.get_parameter("frd_child_frame_id").value

        # QoS for subscribing to sensor data (BEST_EFFORT to match RTAB-Map output)
        sensor_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
        )
        
        # QoS for publishing (RELIABLE for compatibility with RViz2 and standard tools)
        publish_qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
        )

        # Subscriber (BEST_EFFORT to receive from RTAB-Map)
        self.odom_sub = self.create_subscription(
            Odometry, input_topic, self.odom_callback, sensor_qos
        )

        # Publishers (RELIABLE for RViz2 and ros2 topic tools)
        self.odom_pub = self.create_publisher(Odometry, output_odom_topic, publish_qos)

        if self.publish_pose:
            self.pose_pub = self.create_publisher(PoseStamped, output_pose_topic, publish_qos)

        if self.publish_twist:
            self.twist_pub = self.create_publisher(TwistStamped, output_twist_topic, publish_qos)

        # TF broadcaster for RViz2 visualization
        if self.publish_tf:
            self.tf_broadcaster = TransformBroadcaster(self)

        # Rotation quaternions for frame transformations
        # FLU -> FRD: 180° rotation around X-axis (forward axis)
        self.q_flu_to_frd = Rotation.from_quat([1.0, 0.0, 0.0, 0.0])  # (x,y,z,w) for 180° about X
        
        # ENU -> NED: 180° rotation around axis bisecting X and Y (i.e., the (1,1,0) direction)
        # This swaps X<->Y and flips Z
        sqrt2_inv = 1.0 / np.sqrt(2.0)
        self.q_enu_to_ned = Rotation.from_quat([sqrt2_inv, sqrt2_inv, 0.0, 0.0])  # 180° about (1,1,0)/√2

        # Counter for throttled warning messages
        self.invalid_quat_count = 0
        self.last_warning_time = self.get_clock().now()
        
        self.get_logger().info(
            f"ENU→NED Transformer initialized\n"
            f"  Input:  {input_topic}\n"
            f"  Output: {output_odom_topic}\n"
            f"  Pose:   {output_pose_topic if self.publish_pose else 'disabled'}\n"
            f"  Twist:  {output_twist_topic if self.publish_twist else 'disabled'}\n"
            f"  TF:     {self.ned_frame_id} → {self.frd_child_frame_id} {'enabled' if self.publish_tf else 'disabled'}"
        )

    def transform_position_enu_to_ned(self, x_enu: float, y_enu: float, z_enu: float):
        """
        Transform position from ENU to NED frame.
        
        ENU: x=East, y=North, z=Up
        NED: x=North, y=East, z=Down
        """
        x_ned = y_enu   # North = ENU's Y
        y_ned = x_enu   # East = ENU's X
        z_ned = -z_enu  # Down = -Up
        return x_ned, y_ned, z_ned

    def is_valid_quaternion(self, qx: float, qy: float, qz: float, qw: float) -> bool:
        """Check if quaternion has non-zero norm (valid for rotation)."""
        norm_sq = qx * qx + qy * qy + qz * qz + qw * qw
        return norm_sq > 1e-10  # Threshold for numerical stability

    def transform_orientation_enu_flu_to_ned_frd(self, qx: float, qy: float, qz: float, qw: float):
        """
        Transform orientation quaternion from ENU/FLU to NED/FRD.
        
        The input quaternion q_enu_flu represents: rotation from ENU world frame to FLU body frame.
        The output quaternion q_ned_frd represents: rotation from NED world frame to FRD body frame.
        
        The transformation is:
            q_ned_frd = q_enu_to_ned * q_enu_flu * q_flu_to_frd
        
        Where:
            - q_enu_to_ned: 180° rotation about (1,1,0)/√2 axis (swaps X<->Y, flips Z)
            - q_flu_to_frd: 180° rotation about X axis (flips Y and Z)
        
        Returns None if input quaternion is invalid (zero norm).
        """
        # Check for valid quaternion (RTAB-Map sends zero quaternion when tracking fails)
        if not self.is_valid_quaternion(qx, qy, qz, qw):
            return None
        
        # Original orientation: ENU world -> FLU body
        q_enu_flu = Rotation.from_quat([qx, qy, qz, qw])  # scipy uses [x, y, z, w]
        
        # Full transformation: 
        # q_ned_frd = R_enu_to_ned * R_enu_flu * R_flu_to_frd
        # In quaternion multiplication order (scipy): q_ned_frd = q_enu_to_ned * q_enu_flu * q_flu_to_frd
        q_ned_frd = self.q_enu_to_ned * q_enu_flu * self.q_flu_to_frd
        
        # Extract quaternion [x, y, z, w]
        quat = q_ned_frd.as_quat()
        return quat[0], quat[1], quat[2], quat[3]

    def transform_linear_velocity_enu_to_ned(self, vx_enu: float, vy_enu: float, vz_enu: float):
        """Transform linear velocity from ENU to NED frame (same as position)."""
        return self.transform_position_enu_to_ned(vx_enu, vy_enu, vz_enu)

    def transform_angular_velocity_flu_to_frd(self, wx_flu: float, wy_flu: float, wz_flu: float):
        """
        Transform angular velocity from FLU to FRD body frame.
        
        FLU: x=roll (forward), y=pitch (left), z=yaw (up)
        FRD: x=roll (forward), y=pitch (right), z=yaw (down)
        """
        wx_frd = wx_flu   # Roll axis unchanged (forward)
        wy_frd = -wy_flu  # Pitch axis flipped (left -> right)
        wz_frd = -wz_flu  # Yaw axis flipped (up -> down)
        return wx_frd, wy_frd, wz_frd

    def odom_callback(self, msg: Odometry):
        """Process incoming ENU odometry and publish NED transformed data."""
        
        # Transform orientation first to check validity
        # (RTAB-Map sends zero quaternion when tracking fails)
        quat_result = self.transform_orientation_enu_flu_to_ned_frd(
            msg.pose.pose.orientation.x,
            msg.pose.pose.orientation.y,
            msg.pose.pose.orientation.z,
            msg.pose.pose.orientation.w,
        )
        
        # Skip message if odometry is invalid (zero quaternion = tracking lost)
        if quat_result is None:
            self.invalid_quat_count += 1
            # Throttled warning: log every 2 seconds
            now = self.get_clock().now()
            if (now - self.last_warning_time).nanoseconds > 2e9:
                self.get_logger().warn(
                    f"Skipping {self.invalid_quat_count} messages with invalid quaternion "
                    f"(tracking lost). Move camera to regain tracking."
                )
                self.invalid_quat_count = 0
                self.last_warning_time = now
            return
        
        qx, qy, qz, qw = quat_result
        
        # Create transformed Odometry message
        odom_ned = Odometry()
        odom_ned.header.stamp = msg.header.stamp
        odom_ned.header.frame_id = self.ned_frame_id
        odom_ned.child_frame_id = self.frd_child_frame_id

        # Transform position
        x_ned, y_ned, z_ned = self.transform_position_enu_to_ned(
            msg.pose.pose.position.x,
            msg.pose.pose.position.y,
            msg.pose.pose.position.z,
        )
        odom_ned.pose.pose.position.x = x_ned
        odom_ned.pose.pose.position.y = y_ned
        odom_ned.pose.pose.position.z = z_ned

        # Set transformed orientation
        odom_ned.pose.pose.orientation.x = qx
        odom_ned.pose.pose.orientation.y = qy
        odom_ned.pose.pose.orientation.z = qz
        odom_ned.pose.pose.orientation.w = qw

        # Copy pose covariance (simplified - in practice may need rotation)
        odom_ned.pose.covariance = msg.pose.covariance

        # Transform linear velocity
        vx_ned, vy_ned, vz_ned = self.transform_linear_velocity_enu_to_ned(
            msg.twist.twist.linear.x,
            msg.twist.twist.linear.y,
            msg.twist.twist.linear.z,
        )
        odom_ned.twist.twist.linear.x = vx_ned
        odom_ned.twist.twist.linear.y = vy_ned
        odom_ned.twist.twist.linear.z = vz_ned

        # Transform angular velocity
        wx_frd, wy_frd, wz_frd = self.transform_angular_velocity_flu_to_frd(
            msg.twist.twist.angular.x,
            msg.twist.twist.angular.y,
            msg.twist.twist.angular.z,
        )
        odom_ned.twist.twist.angular.x = wx_frd
        odom_ned.twist.twist.angular.y = wy_frd
        odom_ned.twist.twist.angular.z = wz_frd

        # Copy twist covariance
        odom_ned.twist.covariance = msg.twist.covariance

        # Publish transformed odometry
        self.odom_pub.publish(odom_ned)

        # Publish PoseStamped for MAVROS vision pose
        if self.publish_pose:
            pose_msg = PoseStamped()
            pose_msg.header = odom_ned.header
            pose_msg.pose = odom_ned.pose.pose
            self.pose_pub.publish(pose_msg)

        # Publish TwistStamped for MAVROS vision speed
        if self.publish_twist:
            twist_msg = TwistStamped()
            twist_msg.header = odom_ned.header
            twist_msg.twist = odom_ned.twist.twist
            self.twist_pub.publish(twist_msg)

        # Broadcast TF transform for RViz2 visualization
        if self.publish_tf:
            tf_msg = TransformStamped()
            tf_msg.header.stamp = odom_ned.header.stamp
            tf_msg.header.frame_id = self.ned_frame_id
            tf_msg.child_frame_id = self.frd_child_frame_id
            tf_msg.transform.translation.x = odom_ned.pose.pose.position.x
            tf_msg.transform.translation.y = odom_ned.pose.pose.position.y
            tf_msg.transform.translation.z = odom_ned.pose.pose.position.z
            tf_msg.transform.rotation = odom_ned.pose.pose.orientation
            self.tf_broadcaster.sendTransform(tf_msg)


def main(args=None):
    rclpy.init(args=args)
    node = EnuToNedTransformer()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
