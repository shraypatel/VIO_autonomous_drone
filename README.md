# VIO_autonomous_drone

Autonomous drone system for the **Holybro X500 V2** with **OAK-D S2** camera and **NVIDIA Jetson** companion computer.

## System Overview

All perception and autonomy functionality lives in the `vio_perception_pipeline` package, with C++ sub-packages for message definitions, ESDF collision mapping, and RRT* path planning nested inside it.

| Component | Location | Description |
|-----------|----------|-------------|
| Camera | `vio_perception_pipeline` (camera.launch.py) | OAK-D S2 via depthai_ros_driver |
| SLAM | `vio_perception_pipeline` (rtabmap.launch.py) | RTABMap with ORB + GPU + NED |
| VIO | `VINS-Fusion-ROS2-humble` | Visual-Inertial Odometry (submodule) |
| Collision Map | `vio_perception_pipeline/esdf_server` | ESDF obstacle distance field (C++) |
| Messages | `vio_perception_pipeline/esdf_msgs` | GetDistance service interface (C++) |
| Planner | `vio_perception_pipeline/rrt_star_planner` | 3D RRT* path planning with OMPL (C++) |
| Goal Relay | `vio_perception_pipeline` (goal_from_rviz) | RViz2 2D goal → 3D goal relay |
| Executor | `vio_perception_pipeline` (path_executor_node) | Waypoint following with safety hover |
| Takeoff | `vio_perception_pipeline` (takeoff_node) | Velocity-based takeoff |
| ENU→NED | `vio_perception_pipeline` (enu_to_ned_transformer) | Coordinate frame transformer |

## Architecture

```
OAK-D S2 Camera ──→ VINS-Fusion VIO ──→ RTABMap SLAM ──→ ESDF Server
                                                               │
                         RViz2 Goal ──→ RRT* Planner ←────────┘
                                            │
                                      Path Executor ──→ PX4 (via uXRCE-DDS)
```

## Hardware

- **Drone frame**: Holybro X500 V2
- **Camera**: OAK-D S2 (Luxonis)
- **Compute**: NVIDIA Jetson Orin/Xavier (ARM64, JetPack)
- **Flight controller**: PX4 Autopilot via uXRCE-DDS bridge
- **ROS 2 distro**: Humble

## Quick Start

```bash
cd ros2_ws

# Build RTABMap with CUDA (Jetson only)
./build_rtabmap_cuda.sh

# Build all packages
colcon build --symlink-install
source install/setup.bash

# Launch full system
ros2 launch vio_perception_pipeline full_system.launch.py

# Visualization only (bench testing, no actuators)
ros2 launch vio_perception_pipeline visualization_only.launch.py

# Autonomy subsystem only (ESDF + RRT* + path executor)
ros2 launch vio_perception_pipeline autonomy.launch.py
```

## Workspace Structure

```
ros2_ws/src/
├── vio_perception_pipeline/           # Main pipeline package
│   ├── vio_perception_pipeline/       # Python package (ament_python)
│   │   ├── launch/                    # All launch files
│   │   │   ├── full_system.launch.py
│   │   │   ├── visualization_only.launch.py
│   │   │   ├── autonomy.launch.py
│   │   │   ├── camera.launch.py
│   │   │   ├── rtabmap.launch.py
│   │   │   └── ...
│   │   ├── config/                    # YAML configs + RViz configs
│   │   └── vio_perception_pipeline/   # Python nodes
│   │       ├── goal_from_rviz.py
│   │       ├── takeoff_node.py
│   │       ├── path_executor_node.py
│   │       ├── enu_to_ned_transformer.py
│   │       └── ...
│   ├── esdf_msgs/                     # C++ ESDF service definitions
│   ├── esdf_server/                   # C++ ESDF obstacle map server
│   └── rrt_star_planner/              # C++ RRT* motion planner
├── depthai-ros/                       # DepthAI ROS driver (submodule)
├── rtabmap/                           # RTABMap SLAM (submodule)
├── rtabmap_ros/                       # RTABMap ROS integration (submodule)
├── VINS-Fusion-ROS2-humble/           # VIO (submodule)
└── vision_opencv/                     # OpenCV ROS bridge (submodule)
```

## Safety

⚠️ **Read `ros2_ws/src/vio_perception_pipeline/vio_perception_pipeline/SAFETY_NOTES.md` before flight testing.**

The path executor sends velocity commands to the real flight controller. Always:
1. Have an RC transmitter with kill switch
2. Test with propellers removed first
3. Use tethered testing before free flight
4. Start with conservative speed limits