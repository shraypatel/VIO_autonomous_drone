"""
Full VIO-to-PX4 pipeline: Camera -> RTAB-Map -> ENU-to-NED -> MAVROS -> Pixhawk.

Usage:
  ros2 launch vio_perception_pipeline full_pipeline.launch.py

  # Override serial port:
  ros2 launch vio_perception_pipeline full_pipeline.launch.py fcu_url:=serial:///dev/ttyACM0:921600

  # With QGroundControl GCS proxy:
  ros2 launch vio_perception_pipeline full_pipeline.launch.py gcs_url:=udp://:14550@

----------------------------------------------------------------------
REQUIRED PX4 EKF2 PARAMETERS (set via QGroundControl before flight):

  EKF2_EV_CTRL   = 11    # fuse horizontal pos + vertical pos + yaw from vision
  EKF2_HGT_REF   = 3     # vision as primary height source
  EKF2_EV_DELAY  = 50    # pipeline latency in ms
  EKF2_EV_POS_X  = <m>   # camera offset from IMU (forward +)
  EKF2_EV_POS_Y  = <m>   # camera offset from IMU (right +)
  EKF2_EV_POS_Z  = <m>   # camera offset from IMU (down +)
----------------------------------------------------------------------
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    pkg = get_package_share_directory("vio_perception_pipeline")
    launch_dir = os.path.join(pkg, "launch")

    # --- Shared arguments ---
    name = LaunchConfiguration("name")
    fcu_url = LaunchConfiguration("fcu_url")
    gcs_url = LaunchConfiguration("gcs_url")
    tgt_system = LaunchConfiguration("tgt_system")
    use_rtabmap_viz = LaunchConfiguration("use_rtabmap_viz")

    return LaunchDescription([
        # Common arguments
        DeclareLaunchArgument("name", default_value="oak"),
        DeclareLaunchArgument("use_rtabmap_viz", default_value="false"),

        # MAVROS arguments
        DeclareLaunchArgument(
            "fcu_url",
            # TODO: change to serial:///dev/ttyTHS1:921600 for UART when switching from USB to serial
            default_value="serial:///dev/ttyACM0:921600",
            description="MAVLink FCU connection URL",
        ),
        DeclareLaunchArgument(
            "gcs_url",
            default_value="",
            description="MAVLink GCS proxy URL (e.g. udp://:14550@)",
        ),
        DeclareLaunchArgument(
            "tgt_system",
            default_value="1",
            description="MAVLink target system ID",
        ),

        # 1) DepthAI Camera
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(launch_dir, "camera.launch.py")
            ),
            launch_arguments={"name": name}.items(),
        ),

        # 2) RTAB-Map Odometry + SLAM + ENU-to-NED transformer
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(launch_dir, "rtabmap.launch.py")
            ),
            launch_arguments={
                "name": name,
                "use_rtabmap_viz": use_rtabmap_viz,
                "use_ned_transform": "true",
            }.items(),
        ),

        # 3) MAVROS -> Pixhawk 6C
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(launch_dir, "mavros.launch.py")
            ),
            launch_arguments={
                "fcu_url": fcu_url,
                "gcs_url": gcs_url,
                "tgt_system": tgt_system,
            }.items(),
        ),
    ])