"""Full system launch for Holybro X500 V2 real-world autonomous flight.

Launches all autonomy stack components via the vio_perception_pipeline:
  1. OAK-D S2 camera driver (via vio_perception_pipeline/camera.launch.py)
  2. RTABMap SLAM + Visual Odometry (via vio_perception_pipeline/rtabmap.launch.py)
  3. Autonomy stack: ESDF + RRT* + path executor (via vio_perception_pipeline/autonomy.launch.py)
  4. RViz2 visualization (optional)

VINS-Fusion VIO can be launched separately if needed (already in this repo).
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
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
        DeclareLaunchArgument('rviz', default_value='true',
                              description='Launch RViz2'),
        DeclareLaunchArgument('auto_takeoff', default_value='false',
                              description='Enable automatic takeoff'),
        DeclareLaunchArgument('enable_path_executor', default_value='true',
                              description='Enable the path executor (disable for bench testing)'),
        DeclareLaunchArgument('camera_name', default_value='oak',
                              description='Camera name (used as topic namespace)'),
        DeclareLaunchArgument('use_ned_transform', default_value='true',
                              description='Enable ENU to NED coordinate transformation'),

        # --- 1. OAK-D S2 Camera (via vio_perception_pipeline) ---
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(pipeline_share, 'launch', 'camera.launch.py')
            ),
            launch_arguments={
                'name': LaunchConfiguration('camera_name'),
            }.items(),
        ),

        # --- 2. RTABMap SLAM + VIO (via vio_perception_pipeline) ---
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(pipeline_share, 'launch', 'rtabmap.launch.py')
            ),
            launch_arguments={
                'name': LaunchConfiguration('camera_name'),
                'use_ned_transform': LaunchConfiguration('use_ned_transform'),
            }.items(),
        ),

        # --- 3. Autonomy Stack: ESDF + RRT* + Path Executor (via vio_perception_pipeline) ---
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(pipeline_share, 'launch', 'autonomy.launch.py')
            ),
            launch_arguments={
                'auto_takeoff': LaunchConfiguration('auto_takeoff'),
                'enable_path_executor': LaunchConfiguration('enable_path_executor'),
            }.items(),
        ),

        # --- 4. RViz2 ---
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config],
            condition=IfCondition(LaunchConfiguration('rviz')),
            output='screen',
        ),
    ])
