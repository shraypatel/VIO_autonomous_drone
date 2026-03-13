#!/usr/bin/env python3
"""Converts RViz2 2D Goal Pose to a PoseStamped on /maze_final_goal.

Preserves the x,y from RViz goal and sets z to a configurable flight altitude.
"""
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped


class GoalFromRviz(Node):
    def __init__(self):
        super().__init__('goal_from_rviz')
        self.declare_parameter('goal_altitude', 1.0)
        self.declare_parameter('input_topic', '/goal_pose')
        self.declare_parameter('output_topic', '/maze_final_goal')

        self.altitude = self.get_parameter('goal_altitude').value
        input_topic = self.get_parameter('input_topic').value
        output_topic = self.get_parameter('output_topic').value

        self.sub = self.create_subscription(
            PoseStamped, input_topic, self.goal_callback, 10)
        self.pub = self.create_publisher(PoseStamped, output_topic, 10)
        self.get_logger().info(
            f'Goal relay: {input_topic} -> {output_topic} (altitude={self.altitude}m)')

    def goal_callback(self, msg: PoseStamped):
        out = PoseStamped()
        out.header = msg.header
        out.header.frame_id = 'map'
        out.pose.position.x = msg.pose.position.x
        out.pose.position.y = msg.pose.position.y
        out.pose.position.z = self.altitude
        out.pose.orientation = msg.pose.orientation
        self.pub.publish(out)
        self.get_logger().info(
            f'Goal relayed: ({out.pose.position.x:.2f}, '
            f'{out.pose.position.y:.2f}, {out.pose.position.z:.2f})')


def main(args=None):
    rclpy.init(args=args)
    node = GoalFromRviz()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
