"""Autonomy stack launch: ESDF server + RRT* planner + path executor.

Launches the planning and execution components that layer on top of the
perception pipeline (camera + SLAM). Requires the perception pipeline
(camera.launch.py + rtabmap.launch.py) to already be running.

Components launched:
  1. Point cloud filter (preprocesses depth for ESDF)
  2. ESDF server (collision distance field)
  3. RRT* planner (collision-free path planning)
  4. Goal relay (RViz 2D goal → 3D goal for planner)
  5. Path executor (waypoint following, conditionally enabled)
  6. Takeoff node (conditionally enabled)
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    esdf_share = get_package_share_directory('esdf_server')
    esdf_params = os.path.join(esdf_share, 'config', 'esdf_params.yaml')

    return LaunchDescription([
        DeclareLaunchArgument('auto_takeoff', default_value='false',
                              description='Enable automatic takeoff'),
        DeclareLaunchArgument('enable_path_executor', default_value='true',
                              description='Enable the path executor (disable for bench testing)'),
        DeclareLaunchArgument('goal_altitude', default_value='1.0',
                              description='Default altitude for RViz goals'),
        DeclareLaunchArgument('point_cloud_topic',
                              default_value='/oak_d_s2/depth/points',
                              description='Input point cloud topic'),

        # --- 1. Point Cloud Filter ---
        Node(
            package='esdf_server',
            executable='point_cloud_filter_node',
            name='point_cloud_filter',
            parameters=[{
                'input_topic': LaunchConfiguration('point_cloud_topic'),
                'output_topic': '/oak_d_s2/depth/points_filtered',
                'filter_ground': True,
                'min_z_ground': 0.02,
            }],
            output='screen',
        ),

        # --- 2. ESDF Server ---
        Node(
            package='esdf_server',
            executable='esdf_server_node',
            name='esdf_server',
            parameters=[esdf_params],
            output='screen',
        ),

        # --- 3. RRT* Planner (delayed to allow ESDF to initialize) ---
        TimerAction(
            period=3.0,
            actions=[
                Node(
                    package='rrt_star_planner',
                    executable='rrt_star_planner_node',
                    name='rrt_star_planner',
                    output='screen',
                ),
            ],
        ),

        # --- 4. Goal Relay (RViz -> planner) ---
        Node(
            package='vio_perception_pipeline',
            executable='goal_from_rviz_node',
            name='goal_from_rviz',
            parameters=[{
                'goal_altitude': LaunchConfiguration('goal_altitude'),
            }],
            output='screen',
        ),

        # --- 5. Path Executor (conditionally enabled) ---
        Node(
            package='vio_perception_pipeline',
            executable='path_executor_node',
            name='path_executor',
            condition=IfCondition(LaunchConfiguration('enable_path_executor')),
            output='screen',
        ),

        # --- 6. Takeoff (conditionally enabled) ---
        Node(
            package='vio_perception_pipeline',
            executable='takeoff_node',
            name='takeoff',
            condition=IfCondition(LaunchConfiguration('auto_takeoff')),
            parameters=[{
                'target_altitude': 1.0,
                'vertical_speed': 0.5,
            }],
            output='screen',
        ),
    ])
