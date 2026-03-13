"""RTABMap SLAM launch for X500 V2 with OAK-D S2 (real hardware).

Starts RTABMap in SLAM mode with the OAK-D S2 camera topics.
No Gazebo or simulation components.
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_share = get_package_share_directory('x500_rtabmap_slam')
    rtabmap_params = os.path.join(pkg_share, 'config', 'rtabmap_params.yaml')
    rviz_config = os.path.join(pkg_share, 'config', 'rtabmap_slam.rviz')

    return LaunchDescription([
        DeclareLaunchArgument('rviz', default_value='true',
                              description='Launch RViz2'),
        DeclareLaunchArgument('use_sim_time', default_value='false',
                              description='Use simulation time (always false for real hardware)'),

        # RTABMap SLAM node
        Node(
            package='rtabmap_slam',
            executable='rtabmap',
            name='rtabmap',
            output='screen',
            parameters=[rtabmap_params, {
                'use_sim_time': LaunchConfiguration('use_sim_time'),
            }],
            remappings=[
                ('rgb/image', '/oak_d_s2/rgb/image_raw'),
                ('depth/image', '/oak_d_s2/depth/image_raw'),
                ('rgb/camera_info', '/oak_d_s2/rgb/camera_info'),
                ('odom', '/odom'),
            ],
        ),

        # RViz2
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config],
            condition=IfCondition(LaunchConfiguration('rviz')),
            output='screen',
        ),
    ])
