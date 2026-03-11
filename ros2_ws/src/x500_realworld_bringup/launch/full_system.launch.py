"""Full system launch for Holybro X500 V2 real-world autonomous flight.

Launches all autonomy stack components in dependency order:
  1. OAK-D S2 camera driver (static TFs + publisher)
  2. RTABMap SLAM
  3. ESDF server (point cloud filter + collision server)
  4. RRT* planner
  5. Path executor
  6. RViz2 visualization (optional)

VINS-Fusion VIO is assumed to be launched separately (already in this repo).
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    bringup_share = get_package_share_directory('x500_realworld_bringup')
    esdf_share = get_package_share_directory('esdf_server')
    rtabmap_share = get_package_share_directory('x500_rtabmap_slam')
    rviz_config = os.path.join(bringup_share, 'config', 'full_system.rviz')
    esdf_params = os.path.join(esdf_share, 'config', 'esdf_params.yaml')
    rtabmap_params = os.path.join(rtabmap_share, 'config', 'rtabmap_params.yaml')

    return LaunchDescription([
        DeclareLaunchArgument('rviz', default_value='true',
                              description='Launch RViz2'),
        DeclareLaunchArgument('auto_takeoff', default_value='false',
                              description='Enable automatic takeoff'),
        DeclareLaunchArgument('enable_path_executor', default_value='true',
                              description='Enable the path executor (disable for bench testing)'),

        # --- 1. Camera TFs ---
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='base_to_camera_tf',
            arguments=['0.1', '0.0', '0.05', '0', '0', '0',
                       'base_link', 'oak_d_s2_frame'],
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='camera_to_optical_tf',
            arguments=['0', '0', '0', '-1.5708', '0', '-1.5708',
                       'oak_d_s2_frame', 'oak_d_s2_rgb_optical_frame'],
        ),

        # --- 2. OAK-D S2 Camera Publisher ---
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

        # --- 3. RTABMap SLAM ---
        Node(
            package='rtabmap_slam',
            executable='rtabmap',
            name='rtabmap',
            output='screen',
            parameters=[rtabmap_params, {
                'use_sim_time': False,
            }],
            remappings=[
                ('rgb/image', '/oak_d_s2/rgb/image_raw'),
                ('depth/image', '/oak_d_s2/depth/image_raw'),
                ('rgb/camera_info', '/oak_d_s2/rgb/camera_info'),
                ('odom', '/odom'),
            ],
        ),

        # --- 4. Point Cloud Filter ---
        Node(
            package='esdf_server',
            executable='point_cloud_filter_node',
            name='point_cloud_filter',
            parameters=[{
                'input_topic': '/oak_d_s2/depth/points',
                'output_topic': '/oak_d_s2/depth/points_filtered',
                'filter_ground': True,
                'min_z_ground': 0.02,
            }],
            output='screen',
        ),

        # --- 5. ESDF Server ---
        Node(
            package='esdf_server',
            executable='esdf_server_node',
            name='esdf_server',
            parameters=[esdf_params],
            output='screen',
        ),

        # --- 6. RRT* Planner (delayed to allow ESDF to initialize) ---
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

        # --- 7. Goal Relay (RViz -> planner) ---
        Node(
            package='x500_rtabmap_slam',
            executable='goal_from_rviz_node',
            name='goal_from_rviz',
            parameters=[{'goal_altitude': 1.0}],
            output='screen',
        ),

        # --- 8. Path Executor (conditionally enabled) ---
        Node(
            package='path_executor',
            executable='path_executor_node',
            name='path_executor',
            condition=IfCondition(LaunchConfiguration('enable_path_executor')),
            output='screen',
        ),

        # --- 9. Auto Takeoff (conditionally enabled) ---
        Node(
            package='x500_rtabmap_slam',
            executable='takeoff_node',
            name='takeoff',
            condition=IfCondition(LaunchConfiguration('auto_takeoff')),
            parameters=[{
                'target_altitude': 1.0,
                'vertical_speed': 0.5,
            }],
            output='screen',
        ),

        # --- 10. RViz2 ---
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config],
            condition=IfCondition(LaunchConfiguration('rviz')),
            output='screen',
        ),
    ])
