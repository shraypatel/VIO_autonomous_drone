import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import ComposableNodeContainer, LoadComposableNodes
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    pkg = get_package_share_directory("vio_perception_pipeline")
    depthai_share = get_package_share_directory("depthai_ros_driver")

    name = LaunchConfiguration("name")
    params_file = LaunchConfiguration("params_file")
    use_rviz = LaunchConfiguration("use_rviz")

    parent_frame = LaunchConfiguration("parent_frame")
    cam_pos_x = LaunchConfiguration("cam_pos_x")
    cam_pos_y = LaunchConfiguration("cam_pos_y")
    cam_pos_z = LaunchConfiguration("cam_pos_z")
    cam_roll = LaunchConfiguration("cam_roll")
    cam_pitch = LaunchConfiguration("cam_pitch")
    cam_yaw = LaunchConfiguration("cam_yaw")

    return LaunchDescription([
        DeclareLaunchArgument("name", default_value="oak"),
        DeclareLaunchArgument(
            "params_file",
            default_value="/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/src/vio_perception_pipeline/config/depthai_camera.yaml",
        ),
        DeclareLaunchArgument("use_rviz", default_value="false"),

        DeclareLaunchArgument("parent_frame", default_value="oak-d-base-frame"),
        DeclareLaunchArgument("cam_pos_x", default_value="0.0"),
        DeclareLaunchArgument("cam_pos_y", default_value="0.0"),
        DeclareLaunchArgument("cam_pos_z", default_value="0.0"),
        DeclareLaunchArgument("cam_roll", default_value="0.0"),
        DeclareLaunchArgument("cam_pitch", default_value="0.0"),
        DeclareLaunchArgument("cam_yaw", default_value="0.0"),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(depthai_share, "launch", "camera.launch.py")
            ),
            launch_arguments={
                "name": name,
                "params_file": params_file,
                "use_rviz": use_rviz,
                "rectify_rgb": "false",
                "parent_frame": parent_frame,
                "cam_pos_x": cam_pos_x,
                "cam_pos_y": cam_pos_y,
                "cam_pos_z": cam_pos_z,
                "cam_roll": cam_roll,
                "cam_pitch": cam_pitch,
                "cam_yaw": cam_yaw,
                "rgb_resolution": "480p",
                "rgb_fps": "15.0",
            }.items(),
        ),
    ])

