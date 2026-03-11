#!/usr/bin/env python3
"""Takeoff node: publishes upward velocity to lift the drone to a target altitude.

Uses TF to monitor altitude and stops commanding upward velocity once target is reached.
Adapted for real PX4 hardware via uXRCE-DDS bridge.
"""
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener


class TakeoffNode(Node):
    def __init__(self):
        super().__init__('takeoff_node')
        self.declare_parameter('target_altitude', 1.0)
        self.declare_parameter('vertical_speed', 0.5)
        self.declare_parameter('altitude_tolerance', 0.1)
        self.declare_parameter('cmd_vel_topic', '/x500_v2/cmd_vel')
        self.declare_parameter('enable_topic', '/x500_v2/enable')
        self.declare_parameter('map_frame_id', 'map')
        self.declare_parameter('base_frame_id', 'base_link')
        self.declare_parameter('control_rate', 20.0)

        self.target_alt = self.get_parameter('target_altitude').value
        self.vertical_speed = self.get_parameter('vertical_speed').value
        self.alt_tolerance = self.get_parameter('altitude_tolerance').value
        cmd_vel_topic = self.get_parameter('cmd_vel_topic').value
        enable_topic = self.get_parameter('enable_topic').value
        self.map_frame = self.get_parameter('map_frame_id').value
        self.base_frame = self.get_parameter('base_frame_id').value
        control_rate = self.get_parameter('control_rate').value

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.cmd_vel_pub = self.create_publisher(Twist, cmd_vel_topic, 10)
        self.enable_pub = self.create_publisher(Bool, enable_topic, 10)

        self.takeoff_complete = False
        self.timer = self.create_timer(1.0 / control_rate, self.control_callback)
        self.get_logger().info(
            f'Takeoff node: target={self.target_alt}m, speed={self.vertical_speed}m/s')

    def control_callback(self):
        if self.takeoff_complete:
            return

        try:
            t = self.tf_buffer.lookup_transform(
                self.map_frame, self.base_frame,
                rclpy.time.Time(),
                timeout=rclpy.duration.Duration(seconds=0.2))
            current_alt = t.transform.translation.z
        except TransformException:
            return

        enable_msg = Bool()
        enable_msg.data = True
        self.enable_pub.publish(enable_msg)

        twist = Twist()
        if current_alt < self.target_alt - self.alt_tolerance:
            twist.linear.z = self.vertical_speed
        else:
            twist.linear.z = 0.0
            self.takeoff_complete = True
            self.get_logger().info(
                f'Takeoff complete at altitude {current_alt:.2f}m')
        self.cmd_vel_pub.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = TakeoffNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
