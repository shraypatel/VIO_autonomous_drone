import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def launch_setup(context, *args, **kwargs):
    pkg = get_package_share_directory("vio_perception_pipeline")
    esdf_pkg = get_package_share_directory("esdf_server")

    esdf_params_file = LaunchConfiguration("esdf_params_file").perform(context)
    point_cloud_topic = LaunchConfiguration("point_cloud_topic").perform(context)
    use_filter = LaunchConfiguration("use_point_cloud_filter").perform(context).lower() == "true"
    filtered_topic = LaunchConfiguration("filtered_topic").perform(context)
    map_frame_id = LaunchConfiguration("map_frame_id").perform(context)
    use_rviz = LaunchConfiguration("use_rviz").perform(context).lower() == "true"
    rviz_config = LaunchConfiguration("rviz_config").perform(context)

    esdf_input_topic = filtered_topic if use_filter else point_cloud_topic

    nodes = []

    if use_filter:
        nodes.append(
            Node(
                package="esdf_server",
                executable="point_cloud_filter_node",
                name="point_cloud_filter",
                output="screen",
                parameters=[{
                    "input_topic": point_cloud_topic,
                    "output_topic": filtered_topic,
                    "min_z_ground": 0.02,
                    "filter_ground": True,
                }],
            )
        )

    nodes.append(
        Node(
            package="esdf_server",
            executable="esdf_server_node",
            name="esdf_server",
            output="screen",
            parameters=[
                esdf_params_file,
                {
                    "point_cloud_topic": esdf_input_topic,
                    "map_frame_id": map_frame_id,
                },
            ],
        )
    )

    if use_rviz:
        nodes.append(
            Node(
                package="rviz2",
                executable="rviz2",
                name="rviz2",
                output="screen",
                arguments=["-d", rviz_config],
            )
        )

    return nodes


def generate_launch_description():
    pkg = get_package_share_directory("vio_perception_pipeline")
    esdf_pkg = get_package_share_directory("esdf_server")
    default_params = os.path.join(esdf_pkg, "config", "esdf_params.yaml")
    default_rviz = os.path.join(pkg, "config", "rviz", "esdf_voxels.rviz")

    return LaunchDescription([
        DeclareLaunchArgument(
            "point_cloud_topic",
            default_value="/cloud_map",
            description="Raw point cloud topic from RTAB-Map (or depth camera)",
        ),
        DeclareLaunchArgument(
            "use_point_cloud_filter",
            default_value="true",
            description="Run NaN / ground-plane filter before the ESDF server",
        ),
        DeclareLaunchArgument(
            "filtered_topic",
            default_value="/cloud_map_filtered",
            description="Output topic for the point cloud filter node",
        ),
        DeclareLaunchArgument(
            "map_frame_id",
            default_value="map",
            description="TF frame the ESDF voxel grid is built in",
        ),
        DeclareLaunchArgument(
            "esdf_params_file",
            default_value=default_params,
            description="Path to esdf_params.yaml (voxel size, bounds, decay, etc.)",
        ),
        DeclareLaunchArgument(
            "use_rviz",
            default_value="true",
            description="Launch RViz2 with the ESDF + RTAB-Map display config",
        ),
        DeclareLaunchArgument(
            "rviz_config",
            default_value=default_rviz,
            description="Path to .rviz config file",
        ),
        OpaqueFunction(function=launch_setup),
    ])
