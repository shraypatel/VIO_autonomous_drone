"""Autonomy launch: ESDF server + RRT* planner + path executor + goal relay.

This launch file brings up the autonomy subsystem that sits on top of the
perception pipeline (camera + SLAM).  It is designed to be included from
the full_system or full_pipeline launch files via IncludeLaunchDescription.
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    pkg = get_package_share_directory("vio_perception_pipeline")
    esdf_pkg = get_package_share_directory("esdf_server")
    esdf_params = os.path.join(esdf_pkg, "config", "esdf_params.yaml")

    return LaunchDescription([
        # --- Arguments ---
        DeclareLaunchArgument(
            "enable_path_executor", default_value="true",
            description="Enable the path executor (disable for bench testing)",
        ),
        DeclareLaunchArgument(
            "auto_takeoff", default_value="false",
            description="Enable automatic velocity-based takeoff",
        ),
        DeclareLaunchArgument(
            "point_cloud_topic", default_value="/cloud_map",
            description="Raw point cloud topic from RTABMap",
        ),
        DeclareLaunchArgument(
            "filtered_topic", default_value="/cloud_map_filtered",
            description="Filtered point cloud topic for ESDF",
        ),
        DeclareLaunchArgument(
            "goal_altitude", default_value="1.0",
            description="Default altitude for RViz2 goals",
        ),
        DeclareLaunchArgument(
            "target_altitude", default_value="1.0",
            description="Takeoff target altitude (m)",
        ),

        # --- Point Cloud Filter ---
        Node(
            package="esdf_server",
            executable="point_cloud_filter_node",
            name="point_cloud_filter",
            output="screen",
            parameters=[{
                "input_topic": LaunchConfiguration("point_cloud_topic"),
                "output_topic": LaunchConfiguration("filtered_topic"),
                "min_z_ground": 0.02,
                "filter_ground": True,
            }],
        ),

        # --- ESDF Server ---
        Node(
            package="esdf_server",
            executable="esdf_server_node",
            name="esdf_server",
            output="screen",
            parameters=[
                esdf_params,
                {"point_cloud_topic": LaunchConfiguration("filtered_topic")},
            ],
        ),

        # --- RRT* Planner (delayed to allow ESDF to initialize) ---
        TimerAction(
            period=3.0,
            actions=[
                Node(
                    package="rrt_star_planner",
                    executable="rrt_star_planner_node",
                    name="rrt_star_planner",
                    output="screen",
                ),
            ],
        ),

        # --- Goal Relay (RViz -> planner) ---
        Node(
            package="vio_perception_pipeline",
            executable="goal_from_rviz_node",
            name="goal_from_rviz",
            output="screen",
            parameters=[{
                "goal_altitude": LaunchConfiguration("goal_altitude"),
            }],
        ),

        # --- Path Executor ---
        Node(
            package="vio_perception_pipeline",
            executable="path_executor_node",
            name="path_executor",
            output="screen",
            condition=IfCondition(LaunchConfiguration("enable_path_executor")),
        ),

        # --- Auto Takeoff ---
        Node(
            package="vio_perception_pipeline",
            executable="takeoff_node",
            name="takeoff",
            output="screen",
            condition=IfCondition(LaunchConfiguration("auto_takeoff")),
            parameters=[{
                "target_altitude": LaunchConfiguration("target_altitude"),
                "vertical_speed": 0.5,
            }],
        ),
    ])
