"""Bring up VIO + MAVROS and run a one-shot MAVSDK takeoff/hover/land sequence."""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    pkg = get_package_share_directory("vio_perception_pipeline")

    camera_launch = os.path.join(pkg, "launch", "camera.launch.py")
    rtabmap_launch = os.path.join(pkg, "launch", "rtabmap.launch.py")
    mavros_launch = os.path.join(pkg, "launch", "mavros.launch.py")

    name = LaunchConfiguration("name")
    camera_params_file = LaunchConfiguration("camera_params_file")
    fcu_url = LaunchConfiguration("fcu_url")
    gcs_url = LaunchConfiguration("gcs_url")
    takeoff_height_m = LaunchConfiguration("takeoff_height_m")
    hover_duration_s = LaunchConfiguration("hover_duration_s")
    mission_start_delay_s = LaunchConfiguration("mission_start_delay_s")
    mavsdk_system_address = LaunchConfiguration("mavsdk_system_address")

    return LaunchDescription([
        DeclareLaunchArgument("name", default_value="oak"),
        DeclareLaunchArgument(
            "camera_params_file",
            default_value=os.path.join(pkg, "config", "depthai_camera.yaml"),
        ),
        DeclareLaunchArgument(
            "fcu_url",
            default_value="serial:///dev/ttyACM0:921600",
            description="PX4 flight-controller MAVLink endpoint",
        ),
        DeclareLaunchArgument(
            "gcs_url",
            default_value="udp://@127.0.0.1:14550",
            description="MAVROS MAVLink forwarding endpoint used by MAVSDK",
        ),
        DeclareLaunchArgument(
            "mavsdk_system_address",
            default_value="udp://:14550",
            description="MAVSDK system address to connect to MAVROS-forwarded MAVLink",
        ),
        DeclareLaunchArgument("takeoff_height_m", default_value="1.5"),
        DeclareLaunchArgument("hover_duration_s", default_value="8.0"),
        DeclareLaunchArgument(
            "mission_start_delay_s",
            default_value="20.0",
            description="Delay before mission starts, to allow VIO and EKF to settle",
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(camera_launch),
            launch_arguments={
                "name": name,
                "params_file": camera_params_file,
                "use_rviz": "false",
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(rtabmap_launch),
            launch_arguments={
                "name": name,
                "camera_params_file": camera_params_file,
                "use_rtabmap_viz": "false",
                "use_ned_transform": "true",
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(mavros_launch),
            launch_arguments={
                "fcu_url": fcu_url,
                "gcs_url": gcs_url,
                "tgt_system": "1",
                "log_level": "WARN",
            }.items(),
        ),
        TimerAction(
            period=mission_start_delay_s,
            actions=[
                Node(
                    package="vio_perception_pipeline",
                    executable="mavsdk_takeoff_hover_land",
                    name="mavsdk_takeoff_hover_land",
                    output="screen",
                    parameters=[
                        {
                            "system_address": mavsdk_system_address,
                            "takeoff_height_m": takeoff_height_m,
                            "hover_duration_s": hover_duration_s,
                        }
                    ],
                ),
            ],
        ),
    ])
