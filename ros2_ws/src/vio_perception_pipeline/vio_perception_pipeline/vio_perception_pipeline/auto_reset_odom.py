#!/usr/bin/env python3
"""Auto-reset odometry node to start SLAM tracking."""

import rclpy
from rclpy.node import Node
from std_srvs.srv import Empty
import time


class AutoResetOdom(Node):
    """Node that automatically resets odometry after startup to begin SLAM tracking."""

    def __init__(self):
        super().__init__('auto_reset_odom')

        # Create client for reset_odom service
        self.client = self.create_client(Empty, '/reset_odom')

        # Wait 6 seconds for everything to be ready, then reset (one-shot timer)
        self.timer = self.create_timer(6.0, self.reset_callback)
        self.get_logger().info('Auto-reset odom node started - waiting 6 seconds...')

    def reset_callback(self):
        """Reset odometry to start SLAM tracking."""
        self.get_logger().info('Calling /reset_odom service...')

        # Cancel the timer so it doesn't repeat
        self.timer.cancel()

        # Wait for service to be available
        if not self.client.wait_for_service(timeout_sec=5.0):
            self.get_logger().error('Reset odom service not available after 5 seconds')
            return

        # Call the service
        request = Empty.Request()
        future = self.client.call_async(request)

        # Handle the response
        future.add_done_callback(self.reset_done_callback)

    def reset_done_callback(self, future):
        """Handle the reset service response."""
        try:
            response = future.result()
            self.get_logger().info('Auto-reset successful - SLAM tracking started')
        except Exception as e:
            self.get_logger().error(f'Auto-reset failed: {e}')

        # Shutdown after completing the reset
        self.get_logger().info('Auto-reset complete, shutting down node')
        self.timer.cancel()
        rclpy.shutdown()


def main(args=None):
    """Main entry point."""
    rclpy.init(args=args)
    node = AutoResetOdom()
    rclpy.spin(node)
    node.destroy_node()


if __name__ == '__main__':
    main()