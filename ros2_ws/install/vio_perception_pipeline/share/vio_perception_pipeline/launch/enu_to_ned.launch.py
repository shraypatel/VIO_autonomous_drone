"""
Launch file for ENU to NED coordinate transformer.

This node transforms RTAB-Map odometry (ENU/FLU) to PX4 coordinates (NED/FRD).
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    pkg = get_package_share_directory("vio_perception_pipeline")

    return LaunchDescription([
        # Input/Output topic configuration
        DeclareLaunchArgument(
            "input_odom_topic",
            default_value="/odom",
            description="Input odometry topic from RTAB-Map (ENU/FLU)",
        ),
        DeclareLaunchArgument(
            "output_odom_topic",
            default_value="/odom_ned",
            description="Output odometry topic in NED/FRD",
        ),
        DeclareLaunchArgument(
            "output_pose_topic",
            default_value="/mavros/vision_pose/pose",
            description="Output PoseStamped topic for MAVROS",
        ),
        DeclareLaunchArgument(
            "output_twist_topic",
            default_value="/mavros/vision_speed/speed_twist",
            description="Output TwistStamped topic for MAVROS",
        ),
        
        # Feature toggles
        DeclareLaunchArgument(
            "publish_pose",
            default_value="true",
            description="Publish PoseStamped for MAVROS vision pose",
        ),
        DeclareLaunchArgument(
            "publish_twist",
            default_value="true",
            description="Publish TwistStamped for MAVROS vision speed",
        ),
        
        # Frame IDs
        DeclareLaunchArgument(
            "ned_frame_id",
            default_value="odom_ned",
            description="Frame ID for NED odometry",
        ),
        DeclareLaunchArgument(
            "frd_child_frame_id",
            default_value="base_link_frd",
            description="Child frame ID for FRD body frame",
        ),

        # Transformer node
        Node(
            package="vio_perception_pipeline",
            executable="enu_to_ned_transformer",
            name="enu_to_ned_transformer",
            output="screen",
            parameters=[{
                "input_odom_topic": LaunchConfiguration("input_odom_topic"),
                "output_odom_topic": LaunchConfiguration("output_odom_topic"),
                "output_pose_topic": LaunchConfiguration("output_pose_topic"),
                "output_twist_topic": LaunchConfiguration("output_twist_topic"),
                "publish_pose": LaunchConfiguration("publish_pose"),
                "publish_twist": LaunchConfiguration("publish_twist"),
                "ned_frame_id": LaunchConfiguration("ned_frame_id"),
                "frd_child_frame_id": LaunchConfiguration("frd_child_frame_id"),
            }],
        ),
    ])
