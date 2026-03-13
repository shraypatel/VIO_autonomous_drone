import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
from launch_ros.actions import Node

def launch_setup(context, *args, **kwargs):
    name = LaunchConfiguration("name").perform(context)
    use_ned_transform = LaunchConfiguration("use_ned_transform").perform(context).lower() == "true"
    pkg = get_package_share_directory("vio_perception_pipeline")

    camera_params_file = LaunchConfiguration("camera_params_file").perform(context)

    parameters = [{
        "frame_id": name,
        "subscribe_rgb": True,
        "subscribe_depth": True,
        "subscribe_odom_info": True,
        "approx_sync": True,
        "approx_sync_max_interval": 0.05,
        "queue_size": 10,

        # Visual Odometry
        "Vis/CorNNType": "1",
        "Odom/GuessMotion": "true",        
        "Odom/MinInliers": "20",           
        "Odom/InlierDistance": "0.1",      
        "Odom/Iterations": "30",           
        "Odom/ResetCountdown": "0",        
        "Odom/Force3DoF": "false",
        "Odom/ImageDecimation": "1",
        "ORB/WTA_K": "2",
        "Odom/KeyFrameThr": "0.3",
        
        # Feature Detector (ORB Specific)       
        "Kp/CorNNType": "3",
        "Kp/MaxFeatures": "300",                      
        "ORB/ScaleFactor": "1.2",
        "ORB/NLevels": "8",

        "Kp/DictionaryPath": "",           
        "Mem/BinDataKept": "true",         

        # Performance & Sync
        "Rtabmap/ImagesAlreadyRectified": "true",    
        "Rtabmap/TimeThr": "0",            
        "Rtabmap/PublishStats": "true",
        
        "Mem/STMSize": "30",
        "Rtabmap/MemoryThr": "500",      

        # GPU Acceleration Flags
        "SURF/GpuVersion": "true",        
        "FAST/GpuVersion": "true",
        "OdomBOW/GpuVersion": "true",
        "always_process_most_recent_frame": True,
    }]

    odom_parameters = [{
            **parameters[0], 
            "Vis/FeatureType": "10",      
            "ORB/Gpu": "true",             
            "Odom/Strategy": "0",          
            "Vis/MaxFeatures": "300",
            "OdomF2M/BundleAdjustment": "0",     # disable local BA to save CPU
        }]

        # SLAM PARAMETERS
    slam_parameters = [{
        **parameters[0],
        "Kp/DetectorStrategy": "8",     
        "Vis/FeatureType": "10",        
        "Rtabmap/DetectionRate": "1.0", 
        "Mem/IncrementalMemory": "true",
    }]

    remappings = [
        ("rgb/image",       f"{name}/rgb/image_raw"),
        ("rgb/camera_info", f"{name}/rgb/camera_info"),
        ("depth/image",     f"{name}/stereo/image_raw"),
    ]

    nodes = [

        Node(
            package="rtabmap_odom",
            executable="rgbd_odometry",
            name="rgbd_odometry",
            output="screen",
            parameters=odom_parameters,
            remappings=remappings,
    #        arguments=["--udebug"]
        ),

        Node(
            package="rtabmap_slam",
            executable="rtabmap",
            name="rtabmap",
            output="screen",
            parameters=slam_parameters,
            remappings=remappings,
        ),

        Node(
            package="rtabmap_viz",
            executable="rtabmap_viz",
            output="screen",
            parameters=slam_parameters,
            remappings=remappings,
            condition=IfCondition(LaunchConfiguration("use_rtabmap_viz")),
        ),
    ]

    if use_ned_transform:
        nodes.append(
            Node(
                package="vio_perception_pipeline",
                executable="enu_to_ned_transformer",
                name="enu_to_ned_transformer",
                output="screen",
                parameters=[{
                    "input_odom_topic": "/odom",
                    "output_odom_topic": "/odom_ned",
                    "output_pose_topic": "/mavros/vision_pose/pose",
                    "output_twist_topic": "/mavros/vision_speed/speed_twist",
                    "publish_pose": True,
                    "publish_twist": True,
                    "publish_tf": True,
                    "publish_odom": True,
                    "ned_frame_id": "odom_ned",
                    "frd_child_frame_id": "base_link_frd",
                }],
            )
        )

    return nodes

def generate_launch_description():
    pkg = get_package_share_directory("vio_perception_pipeline")

    return LaunchDescription([
        DeclareLaunchArgument("name", default_value="oak"),
        DeclareLaunchArgument("camera_params_file", default_value="/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/src/vio_perception_pipeline/config/depthai_camera.yaml"),
        #DeclareLaunchArgument("camera_params_file", default_value=os.path.join(pkg, "config", "depthai_camera.yaml")),
        DeclareLaunchArgument("use_rtabmap_viz", default_value="false"),
        DeclareLaunchArgument("use_ned_transform", default_value="true"),
        OpaqueFunction(function=launch_setup),
    ])