# VIO_autonomous_drone

Autonomous drone system for the **Holybro X500 V2** with **OAK-D S2** camera and **NVIDIA Jetson** companion computer.

## System Overview

This repo provides a full autonomy stack for real-world drone operation, centered on the `vio_perception_pipeline` package:

| Component | Package | Description |
|-----------|---------|-------------|
| **Pipeline** | `vio_perception_pipeline` | Core pipeline: camera, SLAM, VIO, coordinate transform, goal relay, takeoff, path execution |
| Collision Map | `esdf_server` | ESDF obstacle distance field (C++) |
| Messages | `esdf_msgs` | GetDistance service interface |
| Planner | `rrt_star_planner` | 3D RRT* path planning with OMPL (C++) |
| Bringup | `x500_realworld_bringup` | Master launch files |

## Architecture

```
OAK-D S2 Camera ──→ RTABMap VIO + SLAM ──→ ENU→NED Transform ──→ PX4/MAVROS
                           │
                     Point Cloud ──→ ESDF Server
                                         │
                  RViz2 Goal ──→ RRT* Planner ←──┘
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
ros2 launch x500_realworld_bringup full_system.launch.py

# Visualization only (bench testing, no actuators)
ros2 launch x500_realworld_bringup visualization_only.launch.py
```

## Workspace Structure

```
ros2_ws/src/
├── vio_perception_pipeline/  # Core pipeline: camera, SLAM, autonomy nodes, launch files
│   ├── launch/
│   │   ├── camera.launch.py          # OAK-D S2 via depthai_ros_driver
│   │   ├── rtabmap.launch.py         # RTABMap SLAM + VIO + ENU→NED
│   │   ├── autonomy.launch.py        # ESDF + RRT* + path executor
│   │   ├── mavros.launch.py          # PX4 MAVROS connection
│   │   └── autonomous_hover.launch.py
│   └── vio_perception_pipeline/
│       ├── enu_to_ned_transformer.py  # ENU→NED coordinate transform
│       ├── goal_from_rviz.py          # RViz 2D goal → 3D goal relay
│       ├── takeoff_node.py            # Velocity-based takeoff
│       ├── path_executor_node.py      # Waypoint following + safety
│       └── auto_reset_odom.py         # Odometry reset helper
├── esdf_msgs/                # ESDF service definitions (C++)
├── esdf_server/              # ESDF obstacle map server (C++)
├── rrt_star_planner/         # RRT* motion planner (C++)
├── depthai-ros/              # DepthAI ROS driver (submodule)
├── rtabmap/                  # RTABMap SLAM (submodule)
├── rtabmap_ros/              # RTABMap ROS integration
├── VINS-Fusion-ROS2-humble/  # VIO (submodule)
├── vision_opencv/            # OpenCV ROS bridge
└── x500_realworld_bringup/   # Master launch files
```

## Safety

⚠️ **Read `ros2_ws/src/vio_perception_pipeline/SAFETY_NOTES.md` before flight testing.**

The path executor sends velocity commands to the real flight controller. Always:
1. Have an RC transmitter with kill switch
2. Test with propellers removed first
3. Use tethered testing before free flight
4. Start with conservative speed limits