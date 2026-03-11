"""Launch file for OAK-D S2 camera on real hardware with RViz2 visualization.

Starts only the camera driver node (using depthai-ros) and optionally RViz2.
No Gazebo or simulation components.
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_share = get_package_share_directory('depthai_cam')
    rviz_config = os.path.join(pkg_share, 'config', 'oak_d_s2_hw.rviz')

    return LaunchDescription([
        DeclareLaunchArgument('rviz', default_value='true',
                              description='Launch RViz2 for visualization'),

        # Static TF: base_link -> camera_link (adjust offsets for X500 V2)
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_to_camera_tf',
            arguments=['0.1', '0.0', '0.05', '0', '0', '0',
                       'base_link', 'oak_d_s2_frame'],
        ),

        # Static TF: camera_link -> optical frame
        # (ROS convention: Z forward, X right, Y down)
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='camera_to_optical_tf',
            arguments=['0', '0', '0', '-1.5708', '0', '-1.5708',
                       'oak_d_s2_frame', 'oak_d_s2_rgb_optical_frame'],
        ),

        # OAK-D S2 custom publisher node
        Node(
            package='depthai_cam',
            executable='oak_publisher',
            name='oak_d_s2_publisher',
            parameters=[{
                'width': 640,
                'height': 480,
                'fps': 30.0,
                'topic': '/oak_d_s2/rgb/image_raw',
            }],
            output='screen',
        ),

        # RViz2 visualization
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config],
            condition=IfCondition(LaunchConfiguration('rviz')),
            output='screen',
        ),
    ])
