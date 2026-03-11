"""Visualization-only launch for bench testing and monitoring.

Starts RViz2 with the combined config showing camera feeds, SLAM map, ESDF,
planned path, and drone TF — but does NOT start any actuator nodes.
Useful for bench testing and monitoring without commanding the drone.
"""
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    bringup_share = get_package_share_directory('x500_realworld_bringup')
    rviz_config = os.path.join(bringup_share, 'config', 'full_system.rviz')

    return LaunchDescription([
        # Static TFs for visualization
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_to_camera_tf',
            arguments=['0.1', '0.0', '0.05', '0', '0', '0',
                       'base_link', 'oak_d_s2_frame'],
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='camera_to_optical_tf',
            arguments=['0', '0', '0', '-1.5708', '0', '-1.5708',
                       'oak_d_s2_frame', 'oak_d_s2_rgb_optical_frame'],
        ),

        # RViz2 with full system config
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config],
            output='screen',
        ),
    ])
