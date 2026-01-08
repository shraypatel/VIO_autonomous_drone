import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import LoadComposableNodes, Node
from launch_ros.descriptions import ComposableNode


def launch_setup(context, *args, **kwargs):
    name = LaunchConfiguration("name").perform(context)
    if name is None:
        name = "oak"

    # Try to get package share directory, fallback to absolute path if not found
    try:
        pkg = get_package_share_directory("vio_perception_pipeline")
        if pkg is None:
            # Fallback: use absolute path to installed package
            pkg = "/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/install/vio_perception_pipeline/share/vio_perception_pipeline"
    except:
        pkg = "/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/install/vio_perception_pipeline/share/vio_perception_pipeline"

    # Use your DepthAI config for the camera
    camera_params_file = LaunchConfiguration("camera_params_file")
    if camera_params_file is None:
        camera_params_file = os.path.join(pkg, "config", "depthai_camera.yaml")

    # RTAB-Map params yaml (optional; you can also keep parameters inline)
    rtabmap_params_file = LaunchConfiguration("rtabmap_params_file")
    if rtabmap_params_file is None:
        rtabmap_params_file = os.path.join(pkg, "config", "rtabmap_rgbd.yaml")

    # Common parameters passed to RTAB-Map nodes (you can move these into yaml)
    parameters = [{
        "frame_id": str(name) if name is not None else "oak",
        "subscribe_rgb": True,
        "subscribe_depth": True,
        "subscribe_odom_info": True,
        "approx_sync": True,
        "Rtabmap/DetectionRate": "3.5",
        # If you want to load more params from yaml:
        # "config_path": str(rtabmap_params_file) if rtabmap_params_file is not None else "",  # some setups use this; depends on RTAB-Map version
    }]

    # DepthAI -> RTAB-Map input remaps (matches Luxonis RGBD pipeline)
    remappings = [
        ("rgb/image",       f"{name}/rgb/image_rect"),
        ("rgb/camera_info", f"{name}/rgb/camera_info"),
        ("depth/image",     f"{name}/stereo/image_raw"),
    ]

    return [
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(pkg, "launch", "camera.launch.py")),
            launch_arguments={
                "name": name,
                "params_file": camera_params_file,
                "use_rviz": "false",
            }.items(),
        ),

        LoadComposableNodes(
            target_container=f"{name}_container",
            composable_node_descriptions=[
                ComposableNode(
                    package="rtabmap_odom",
                    plugin="rtabmap_odom::RGBDOdometry",
                    name="rgbd_odometry",
                    parameters=parameters,
                    remappings=remappings,
                ),
            ],
        ),

        LoadComposableNodes(
            target_container=f"{name}_container",
            composable_node_descriptions=[
                ComposableNode(
                    package="rtabmap_slam",
                    plugin="rtabmap_slam::CoreWrapper",
                    name="rtabmap",
                    parameters=parameters,
                    remappings=remappings,
                ),
            ],
        ),

        Node(
            package="rtabmap_viz",
            executable="rtabmap_viz",
            output="screen",
            parameters=parameters,
            remappings=remappings,
        ),
    ]


def generate_launch_description():
    pkg = get_package_share_directory("vio_perception_pipeline")

    return LaunchDescription([
        DeclareLaunchArgument("name", default_value="oak"),

        DeclareLaunchArgument(
            "camera_params_file",
            default_value=os.path.join(pkg, "config", "depthai_camera.yaml"),
        ),
        DeclareLaunchArgument(
            "rtabmap_params_file",
            default_value=os.path.join(pkg, "config", "rtabmap_rgbd.yaml"),
        ),

        OpaqueFunction(function=launch_setup),
    ])

