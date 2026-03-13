# x500_rtabmap_slam

RTAB-Map SLAM integration for the Holybro X500 V2 drone with OAK-D S2 camera.

## Overview

This package provides SLAM (Simultaneous Localization and Mapping) for real-world deployment using RTAB-Map with the OAK-D S2 depth camera.

## Differences from Simulation

- **No Gazebo**: All simulation launch files, clock bridges, and Gazebo-specific params removed
- **OAK-D S2**: Topics use `/oak_d_s2/` namespace instead of `/oak_d_lite/`
- **Real hardware**: Designed for Jetson companion computer with CUDA-enabled RTABMap
- **PX4 DDS**: Uses uXRCE-DDS bridge topics (`/fmu/in/...`, `/fmu/out/...`)

## Launch

```bash
# SLAM only with RViz2
ros2 launch x500_rtabmap_slam rtabmap_slam.launch.py

# Without RViz2
ros2 launch x500_rtabmap_slam rtabmap_slam.launch.py rviz:=false
```

## Nodes

| Node | Description |
|------|-------------|
| `goal_from_rviz_node` | Relays RViz2 goal_pose to /maze_final_goal |
| `takeoff_node` | Simple altitude takeoff via velocity commands |
| `waypoint_mission_node` | Autonomous waypoint mission (stub) |
