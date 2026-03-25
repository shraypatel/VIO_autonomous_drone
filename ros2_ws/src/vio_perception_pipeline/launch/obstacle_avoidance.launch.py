"""
Launch the full obstacle-avoidance flight system.

Bring up:
  - DepthAI OAK-D camera driver
  - RTAB-Map VIO / SLAM (with ENU→NED coordinate transform)
  - MAVROS connected to PX4
  - obstacle_avoidance_flight node (after a configurable settling delay)

``mission_start_delay_s`` controls how long the system waits before launching
the flight node; this gives the VIO pipeline and PX4 EKF2 time to converge.
Once the node is running it streams zero-velocity setpoints for a further
5 seconds (the node's built-in ``mission_start_delay``) as the OFFBOARD
pre-condition before arming.

The obstacle_avoidance_flight node implements a five-phase autonomous sequence:
  1. Takeoff  – climb to ``takeoff_height`` metres in OFFBOARD mode.
  2. Forward  – move forward at ``forward_speed`` m/s.
  3. Stop     – halt when an obstacle is closer than ``obstacle_threshold`` m.
  4. Turn     – rotate 180 degrees to face away from the obstacle.
  5. Land     – descend via AUTO.LAND and wait for disarm.
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    IncludeLaunchDescription,
    TimerAction,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    pkg = get_package_share_directory('vio_perception_pipeline')

    camera_launch = os.path.join(pkg, 'launch', 'camera.launch.py')
    rtabmap_launch = os.path.join(pkg, 'launch', 'rtabmap.launch.py')
    mavros_launch = os.path.join(pkg, 'launch', 'mavros.launch.py')

    name = LaunchConfiguration('name')
    camera_params_file = LaunchConfiguration('camera_params_file')
    fcu_url = LaunchConfiguration('fcu_url')
    gcs_url = LaunchConfiguration('gcs_url')
    mission_start_delay_s = LaunchConfiguration('mission_start_delay_s')
    takeoff_height = LaunchConfiguration('takeoff_height')
    forward_speed = LaunchConfiguration('forward_speed')
    obstacle_threshold = LaunchConfiguration('obstacle_threshold')
    turn_rate = LaunchConfiguration('turn_rate')
    climb_rate = LaunchConfiguration('climb_rate')

    return LaunchDescription([
        DeclareLaunchArgument('name', default_value='oak'),
        DeclareLaunchArgument(
            'camera_params_file',
            default_value=os.path.join(pkg, 'config', 'depthai_camera.yaml'),
        ),
        DeclareLaunchArgument(
            'fcu_url',
            default_value='serial:///dev/ttyACM0:921600',
            description='PX4 flight-controller MAVLink endpoint',
        ),
        DeclareLaunchArgument(
            'gcs_url',
            default_value='',
            description='Optional MAVLink GCS forwarding endpoint',
        ),
        DeclareLaunchArgument(
            'mission_start_delay_s',
            default_value='20.0',
            description='Seconds to wait before starting the mission, '
                        'allowing VIO and EKF2 to settle',
        ),
        DeclareLaunchArgument(
            'takeoff_height',
            default_value='1.5',
            description='Target takeoff altitude in metres',
        ),
        DeclareLaunchArgument(
            'forward_speed',
            default_value='0.3',
            description='Forward flight speed in m/s',
        ),
        DeclareLaunchArgument(
            'obstacle_threshold',
            default_value='1.5',
            description='Minimum safe distance to obstacle in metres',
        ),
        DeclareLaunchArgument(
            'turn_rate',
            default_value='0.5',
            description='Yaw rotation rate for the 180-degree turn in rad/s',
        ),
        DeclareLaunchArgument(
            'climb_rate',
            default_value='0.5',
            description='Vertical climb rate during takeoff in m/s',
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(camera_launch),
            launch_arguments={
                'name': name,
                'params_file': camera_params_file,
                'use_rviz': 'false',
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(rtabmap_launch),
            launch_arguments={
                'name': name,
                'camera_params_file': camera_params_file,
                'use_rtabmap_viz': 'false',
                'use_ned_transform': 'true',
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(mavros_launch),
            launch_arguments={
                'fcu_url': fcu_url,
                'gcs_url': gcs_url,
                'tgt_system': '1',
                'log_level': 'WARN',
            }.items(),
        ),
        TimerAction(
            period=mission_start_delay_s,
            actions=[
                Node(
                    package='vio_perception_pipeline',
                    executable='obstacle_avoidance_flight',
                    name='obstacle_avoidance_flight',
                    output='screen',
                    parameters=[{
                        'takeoff_height': takeoff_height,
                        'forward_speed': forward_speed,
                        'obstacle_threshold': obstacle_threshold,
                        'turn_rate': turn_rate,
                        'climb_rate': climb_rate,
                    }],
                ),
            ],
        ),
    ])
