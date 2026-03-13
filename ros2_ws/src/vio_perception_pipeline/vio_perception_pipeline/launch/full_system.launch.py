"""Full system launch for Holybro X500 V2 real-world autonomous flight.

Composes the vio_perception_pipeline sub-launches in dependency order:
  1. Camera (OAK-D S2 via depthai_ros_driver)
  2. RTABMap SLAM (visual odometry + mapping)
  3. Autonomy (ESDF + RRT* planner + path executor + goal relay)
  4. RViz2 visualization (optional)

VINS-Fusion VIO is assumed to be launched separately (already in this repo).
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    pkg = get_package_share_directory("vio_perception_pipeline")
    launch_dir = os.path.join(pkg, "launch")
    rviz_config = os.path.join(pkg, "config", "rviz", "full_system.rviz")

    name = LaunchConfiguration("name")

    return LaunchDescription([
        # --- Arguments ---
        DeclareLaunchArgument("name", default_value="oak"),
        DeclareLaunchArgument("rviz", default_value="true",
                              description="Launch RViz2"),
        DeclareLaunchArgument("auto_takeoff", default_value="false",
                              description="Enable automatic takeoff"),
        DeclareLaunchArgument("enable_path_executor", default_value="true",
                              description="Enable the path executor"),

        # --- 1. Camera ---
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(launch_dir, "camera.launch.py"),
            ),
            launch_arguments={"name": name, "use_rviz": "false"}.items(),
        ),

        # --- 2. RTABMap SLAM ---
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(launch_dir, "rtabmap.launch.py"),
            ),
            launch_arguments={
                "name": name,
                "use_rtabmap_viz": "false",
                "use_ned_transform": "true",
            }.items(),
        ),

        # --- 3. Autonomy (ESDF + RRT* + path executor) ---
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(launch_dir, "autonomy.launch.py"),
            ),
            launch_arguments={
                "enable_path_executor": LaunchConfiguration("enable_path_executor"),
                "auto_takeoff": LaunchConfiguration("auto_takeoff"),
            }.items(),
        ),

        # --- 4. RViz2 ---
        Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            arguments=["-d", rviz_config],
            condition=IfCondition(LaunchConfiguration("rviz")),
            output="screen",
        ),
    ])
