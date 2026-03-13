# x500_realworld_bringup

Top-level bringup package for the Holybro X500 V2 autonomous drone.

## Overview

This package provides master launch files that compose the `vio_perception_pipeline` and C++ autonomy packages (ESDF, RRT* planner) for real-world deployment. All perception and autonomy nodes live in `vio_perception_pipeline`; this package orchestrates them.

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
# Camera + SLAM + RViz2 — no actuators, safe for bench testing
ros2 launch x500_realworld_bringup visualization_only.launch.py
```

## System Architecture

```
vio_perception_pipeline:
  camera.launch.py  ──→  rtabmap.launch.py  ──→  autonomy.launch.py
  (OAK-D S2)            (SLAM + VIO + NED)       (ESDF + RRT* + executor)
```

## Testing Checklist

- [ ] **esdf_msgs**: `colcon build --packages-select esdf_msgs` succeeds
- [ ] **esdf_server**: ESDF server starts, `get_distance` service responds
- [ ] **rrt_star_planner**: Planner starts, produces path on goal input
- [ ] **vio_perception_pipeline**: Camera + SLAM + autonomy nodes start correctly
- [ ] **bringup**: `full_system.launch.py` starts all components in order
- [ ] **visualization_only**: Camera + SLAM + RViz2 without actuators
