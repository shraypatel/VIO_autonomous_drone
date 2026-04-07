"""Launch path_executor with optional RC pilot mux and common ROS 2 options.

Usage (after sourcing the workspace):

  ros2 launch path_executor path_executor.launch.py
  ros2 launch path_executor path_executor.launch.py use_rc_pilot_mux:=true
  ros2 launch path_executor path_executor.launch.py namespace:=drone1 use_sim_time:=true
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration


def _launch_setup(context, *_args, **_kwargs):
    from launch_ros.actions import Node

    mux_raw = LaunchConfiguration("use_rc_pilot_mux").perform(context).lower()
    use_mux = mux_raw in ("1", "true", "yes", "on")

    sim_raw = LaunchConfiguration("use_sim_time").perform(context).lower()
    use_sim = sim_raw in ("1", "true", "yes", "on")

    namespace = LaunchConfiguration("namespace").perform(context).strip()

    params = [
        {"use_rc_pilot_mux": use_mux},
        {"use_sim_time": use_sim},
    ]

    node_kwargs = {
        "package": "path_executor",
        "executable": "path_executor_node",
        "name": "path_executor",
        "output": "screen",
        "parameters": params,
    }
    if namespace:
        node_kwargs["namespace"] = namespace

    return [Node(**node_kwargs)]


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "namespace",
                default_value="",
                description="Optional ROS namespace for the node (empty = root).",
            ),
            DeclareLaunchArgument(
                "use_sim_time",
                default_value="false",
                description="Forward to use_sim_time parameter (set true in simulation).",
            ),
            DeclareLaunchArgument(
                "use_rc_pilot_mux",
                default_value="false",
                description=(
                    "If true, subscribe to PX4 InputRc and mux pilot sticks with path following. "
                    "If false (default), ROS path control only."
                ),
            ),
            OpaqueFunction(function=_launch_setup),
        ]
    )
