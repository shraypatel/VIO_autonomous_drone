# x500_realworld_bringup

Top-level bringup package for the Holybro X500 V2 autonomous drone with full autonomy stack.

## Overview

This package provides master launch files that compose all autonomy packages in the correct order for real-world deployment.

## Hardware Prerequisites

- **Drone**: Holybro X500 V2 frame
- **Camera**: OAK-D S2 (Luxonis) mounted on the drone
- **Compute**: NVIDIA Jetson (Orin/Xavier) companion computer
- **Flight Controller**: PX4 Autopilot via uXRCE-DDS bridge
- **RC Transmitter**: With kill switch configured

## Jetson Setup

1. Install JetPack (Ubuntu 22.04 + CUDA)
2. Install ROS 2 Humble
3. Build the workspace:
   ```bash
   cd ros2_ws
   # Build RTABMap with CUDA support
   ./build_rtabmap_cuda.sh
   # Build all packages
   colcon build --symlink-install
   source install/setup.bash
   ```

## Launch Files

### Full System
```bash
# Full autonomy stack (camera + SLAM + ESDF + planner + executor)
ros2 launch x500_realworld_bringup full_system.launch.py

# With auto takeoff
ros2 launch x500_realworld_bringup full_system.launch.py auto_takeoff:=true

# Without path executor (bench testing)
ros2 launch x500_realworld_bringup full_system.launch.py enable_path_executor:=false
```

### Visualization Only (Bench Testing)
```bash
# Just RViz2 with TFs — no actuators, safe for bench testing
ros2 launch x500_realworld_bringup visualization_only.launch.py
```

## System Architecture

```
OAK-D S2 Camera ──→ RTABMap SLAM ──→ Point Cloud Filter ──→ ESDF Server
                                                                    │
                        RViz2 Goal ──→ Goal Relay ──→ RRT* Planner ←┘
                                                          │
                                                    Path Executor ──→ PX4 (cmd_vel)
```

## Per-Phase Testing Checklist

- [ ] **Phase 1 (esdf_msgs)**: `colcon build --packages-select esdf_msgs` succeeds
- [ ] **Phase 2 (depthai_cam)**: Camera node starts, publishes to `/oak_d_s2/rgb/image_raw`
- [ ] **Phase 3 (x500_rtabmap_slam)**: RTABMap SLAM starts with correct topic remappings
- [ ] **Phase 4 (esdf_server)**: ESDF server starts, `get_distance` service responds
- [ ] **Phase 5 (rrt_star_planner)**: Planner starts, produces path on goal input
- [ ] **Phase 6 (path_executor)**: Executor starts, publishes velocity commands (props off)
- [ ] **Phase 7 (bringup)**: Full system launch starts all components in order
