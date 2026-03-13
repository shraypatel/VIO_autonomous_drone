"""Visualization-only launch for bench testing and monitoring.

Starts the camera + SLAM via vio_perception_pipeline and RViz2 for
visualization, but does NOT start any actuator or autonomy nodes.
Useful for bench testing and monitoring without commanding the drone.
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    bringup_share = get_package_share_directory('x500_realworld_bringup')
    pipeline_share = get_package_share_directory('vio_perception_pipeline')
    rviz_config = os.path.join(bringup_share, 'config', 'full_system.rviz')

    return LaunchDescription([
        DeclareLaunchArgument('camera_name', default_value='oak',
                              description='Camera name (used as topic namespace)'),

        # Camera (via vio_perception_pipeline)
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(pipeline_share, 'launch', 'camera.launch.py')
            ),
            launch_arguments={
                'name': LaunchConfiguration('camera_name'),
            }.items(),
        ),

        # RTABMap SLAM (via vio_perception_pipeline, no NED transform needed for viz)
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(pipeline_share, 'launch', 'rtabmap.launch.py')
            ),
            launch_arguments={
                'name': LaunchConfiguration('camera_name'),
                'use_ned_transform': 'false',
            }.items(),
        ),

        # RViz2
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config],
            output='screen',
        ),
    ])
