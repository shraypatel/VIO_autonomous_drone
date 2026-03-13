"""Visualization-only launch for bench testing and monitoring.

Starts the camera + SLAM + RViz2 but does NOT start any actuator or
autonomy nodes.  Safe for bench testing and monitoring.
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    pkg = get_package_share_directory("vio_perception_pipeline")
    launch_dir = os.path.join(pkg, "launch")
    rviz_config = os.path.join(pkg, "config", "rviz", "full_system.rviz")

    name = LaunchConfiguration("name")

    return LaunchDescription([
        DeclareLaunchArgument("name", default_value="oak"),

        # Camera
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(launch_dir, "camera.launch.py"),
            ),
            launch_arguments={"name": name, "use_rviz": "false"}.items(),
        ),

        # RTABMap SLAM
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(launch_dir, "rtabmap.launch.py"),
            ),
            launch_arguments={
                "name": name,
                "use_rtabmap_viz": "false",
                "use_ned_transform": "false",
            }.items(),
        ),

        # RViz2
        Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            arguments=["-d", rviz_config],
            output="screen",
        ),
    ])
