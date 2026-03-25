"""
Launch file for MAVROS connected to PX4 Pixhawk 6C via serial/USB.

Uses a standard Node (not composable) for reliability — avoids the
allocator and topic-collision bugs in Humble's composable container.

Publishes MAVLink bridge so that VIO data on:
  /mavros/vision_pose/pose       (PoseStamped, NED)
  /mavros/vision_speed/speed_twist (TwistStamped, NED)
is forwarded to PX4 as VISION_POSITION_ESTIMATE / VISION_SPEED_ESTIMATE.

----------------------------------------------------------------------
REQUIRED PX4 EKF2 PARAMETERS (set via QGroundControl before flight):

  EKF2_EV_CTRL   = 11    # bits 0+1+3: fuse horizontal pos + vertical pos + yaw from vision
  EKF2_HGT_REF   = 3     # use vision as primary height source
  EKF2_EV_DELAY  = 50    # pipeline latency in ms (tune: increase if position oscillates)
  EKF2_EV_POS_X  = <m>   # camera X offset from IMU in body frame (forward positive)
  EKF2_EV_POS_Y  = <m>   # camera Y offset from IMU in body frame (right positive)
  EKF2_EV_POS_Z  = <m>   # camera Z offset from IMU in body frame (down positive)
----------------------------------------------------------------------
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def launch_setup(context, *args, **kwargs):
    mavros_share = get_package_share_directory("mavros")

    px4_config = os.path.join(mavros_share, "launch", "px4_config.yaml")

    fcu_url = LaunchConfiguration("fcu_url").perform(context)
    gcs_url = LaunchConfiguration("gcs_url").perform(context)
    tgt_system = int(LaunchConfiguration("tgt_system").perform(context))
    log_level = LaunchConfiguration("log_level").perform(context)

    mavros_node = Node(
        package="mavros",
        executable="mavros_node",
        name="mavros",
        namespace="",
        output="screen",
        parameters=[
            px4_config,
            {
                "fcu_url": fcu_url,
                "gcs_url": gcs_url,
                "target_system_id": tgt_system,
                "target_component_id": 1,
                "fcu_protocol": "v2.0",
                "plugin_allowlist": [
                    "sys_status",          # heartbeat, armed state, flight mode
                    "sys_time",            # FCU time synchronization
                    "command",             # arm, disarm, set mode, reboot
                    "param",               # read/write PX4 parameters
                    "vision_pose",         # send VIO pose to PX4 EKF2
                    "vision_speed",        # send VIO velocity to PX4 EKF2
                    "imu",                 # read IMU data
                    "local_position",      # read EKF2 local position / altitude
                    "setpoint_velocity",   # stream velocity setpoints (OFFBOARD)
                ],
            },
        ],
        arguments=["--ros-args", "--log-level", log_level],
    )

    return [mavros_node]


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            "fcu_url",
            # TODO: change to serial:///dev/ttyTHS1:921600 for UART when switching from USB to serial
            default_value="serial:///dev/ttyACM0:921600",
            description="MAVLink FCU connection URL (serial:///dev/ttyXXX:BAUD or udp://...)",
        ),
        DeclareLaunchArgument(
            "gcs_url",
            default_value="",
            description="MAVLink GCS proxy URL (e.g. udp://:14550@ for QGroundControl)",
        ),
        DeclareLaunchArgument(
            "tgt_system",
            default_value="1",
            description="MAVLink target system ID of the FCU",
        ),
        DeclareLaunchArgument(
            "log_level",
            default_value="WARN",
            description="MAVROS log level (DEBUG, INFO, WARN, ERROR)",
        ),
        OpaqueFunction(function=launch_setup),
    ])
