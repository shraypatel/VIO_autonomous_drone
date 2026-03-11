#!/usr/bin/env python3
"""Keyboard teleop node for X500 V2 drone control.

Control the drone using keyboard commands:
    W/S: Forward/Backward (linear.x)
    A/D: Left/Right strafe (linear.y)
    Q/E: Rotate CCW/CW (angular.z)
    R/F: Up/Down (linear.z)
    Space: Stop all motion
    T: Toggle controller enable/disable
    Esc: Exit

This node reads keyboard input and publishes Twist messages
for velocity control of the quadcopter.
"""
import sys
import select
import termios
import tty
from typing import Optional

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool


MOVE_BINDINGS = {
    'w': (1.0, 0.0, 0.0, 0.0),
    's': (-1.0, 0.0, 0.0, 0.0),
    'a': (0.0, 1.0, 0.0, 0.0),
    'd': (0.0, -1.0, 0.0, 0.0),
    'q': (0.0, 0.0, 0.0, 1.0),
    'e': (0.0, 0.0, 0.0, -1.0),
    'r': (0.0, 0.0, 1.0, 0.0),
    'f': (0.0, 0.0, -1.0, 0.0),
}

SPEED_BINDINGS = {
    'i': (1.1, 1.0),
    'k': (0.9, 1.0),
    'o': (1.0, 1.1),
    'l': (1.0, 0.9),
}

USAGE_MSG = """
╔════════════════════════════════════════════════════════════════╗
║                  X500 V2 Keyboard Teleop                       ║
╠════════════════════════════════════════════════════════════════╣
║  Movement Controls:                                             ║
║       W                                                         ║
║     A   D    - Forward/Backward/Strafe Left/Right              ║
║       S                                                         ║
║                                                                 ║
║     Q / E   - Rotate CCW / CW (Yaw)                            ║
║     R / F   - Up / Down (Altitude)                             ║
║                                                                 ║
║  Speed Controls:                                                ║
║     I / K   - Increase / Decrease linear speed                 ║
║     O / L   - Increase / Decrease angular speed                ║
║                                                                 ║
║  Other:                                                         ║
║     Space   - Stop all motion (hover)                          ║
║     T       - Toggle controller enable/disable                 ║
║     Esc     - Exit teleop                                      ║
╚════════════════════════════════════════════════════════════════╝

Current speeds: linear={linear_speed:.2f} m/s, angular={angular_speed:.2f} rad/s
Controller: {status}
"""


class KeyboardTeleopNode(Node):
    """ROS2 node for keyboard-based velocity control."""

    def __init__(self):
        super().__init__('keyboard_teleop')

        self.declare_parameter('linear_speed', 1.0)
        self.declare_parameter('angular_speed', 1.0)
        self.declare_parameter('cmd_vel_topic', '/x500_v2/cmd_vel')
        self.declare_parameter('enable_topic', '/x500_v2/enable')
        self.declare_parameter('manual_override_topic', '/x500_v2/teleop_active')
        self.declare_parameter('publish_rate', 20.0)

        self.linear_speed = self.get_parameter('linear_speed').value
        self.angular_speed = self.get_parameter('angular_speed').value
        cmd_vel_topic = self.get_parameter('cmd_vel_topic').value
        enable_topic = self.get_parameter('enable_topic').value
        manual_override_topic = self.get_parameter('manual_override_topic').value
        publish_rate = self.get_parameter('publish_rate').value

        self.cmd_vel_pub = self.create_publisher(Twist, cmd_vel_topic, 10)
        self.enable_pub = self.create_publisher(Bool, enable_topic, 10)
        self.manual_override_pub = self.create_publisher(
            Bool, manual_override_topic, 10
        )

        self.timer = self.create_timer(1.0 / publish_rate, self.timer_callback)

        self.linear_x = 0.0
        self.linear_y = 0.0
        self.linear_z = 0.0
        self.angular_z = 0.0
        self.enabled = False
        self.settings: Optional[list] = None

        self.get_logger().info(f'Publishing velocity to: {cmd_vel_topic}')
        self.get_logger().info(f'Enable topic: {enable_topic}')
        self.get_logger().info(
            f'Manual override topic: {manual_override_topic}'
        )

    def get_key(self, timeout: float = 0.1) -> str:
        """Read a single keypress with timeout."""
        if select.select([sys.stdin], [], [], timeout)[0]:
            return sys.stdin.read(1)
        return ''

    def timer_callback(self):
        """Publish current velocity command."""
        if not self.enabled:
            return
        twist = Twist()
        twist.linear.x = self.linear_x * self.linear_speed
        twist.linear.y = self.linear_y * self.linear_speed
        twist.linear.z = self.linear_z * self.linear_speed
        twist.angular.z = self.angular_z * self.angular_speed
        self.cmd_vel_pub.publish(twist)

    def toggle_enable(self):
        """Toggle the controller enabled state."""
        self.enabled = not self.enabled
        msg = Bool()
        msg.data = self.enabled
        self.enable_pub.publish(msg)
        override_msg = Bool()
        override_msg.data = self.enabled
        self.manual_override_pub.publish(override_msg)
        if not self.enabled:
            self.linear_x = 0.0
            self.linear_y = 0.0
            self.linear_z = 0.0
            self.angular_z = 0.0
            self.timer_callback()
        status = "ENABLED" if self.enabled else "DISABLED"
        self.get_logger().info(f'Controller {status}')

    def print_status(self):
        """Print the usage message with current settings."""
        status = "ENABLED" if self.enabled else "DISABLED"
        print(USAGE_MSG.format(
            linear_speed=self.linear_speed,
            angular_speed=self.angular_speed,
            status=status
        ))

    def run(self):
        """Main loop: read keys and update velocity commands."""
        self.settings = termios.tcgetattr(sys.stdin)
        try:
            tty.setraw(sys.stdin.fileno())
            self.print_status()
            while rclpy.ok():
                rclpy.spin_once(self, timeout_sec=0)
                key = self.get_key(timeout=0.05)
                if key == '':
                    continue
                if key == '\x1b':
                    self.get_logger().info('Exiting keyboard teleop...')
                    break
                if key == '\x03':
                    break
                key_lower = key.lower()
                if key_lower in MOVE_BINDINGS:
                    x, y, z, az = MOVE_BINDINGS[key_lower]
                    self.linear_x = x
                    self.linear_y = y
                    self.linear_z = z
                    self.angular_z = az
                elif key_lower in SPEED_BINDINGS:
                    lin_mult, ang_mult = SPEED_BINDINGS[key_lower]
                    self.linear_speed *= lin_mult
                    self.angular_speed *= ang_mult
                    self.linear_speed = max(0.1, min(5.0, self.linear_speed))
                    self.angular_speed = max(0.1, min(3.0, self.angular_speed))
                elif key == ' ':
                    self.linear_x = 0.0
                    self.linear_y = 0.0
                    self.linear_z = 0.0
                    self.angular_z = 0.0
                elif key_lower == 't':
                    self.toggle_enable()
        except Exception as e:
            self.get_logger().error(f'Error: {e}')
        finally:
            self.linear_x = 0.0
            self.linear_y = 0.0
            self.linear_z = 0.0
            self.angular_z = 0.0
            self.timer_callback()
            disable_msg = Bool()
            disable_msg.data = False
            self.enable_pub.publish(disable_msg)
            self.manual_override_pub.publish(disable_msg)
            if self.settings is not None:
                termios.tcsetattr(
                    sys.stdin, termios.TCSADRAIN, self.settings
                )


def main(args=None):
    """Entry point for the keyboard teleop node."""
    print("Starting X500 V2 Keyboard Teleop...")
    print("Press 'T' to enable controller, then use WASD/RF/QE to control.")
    print("Press 'Esc' to exit.\n")
    rclpy.init(args=args)
    node = KeyboardTeleopNode()
    try:
        node.run()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
