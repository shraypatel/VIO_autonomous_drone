# depthai_cam

OAK-D S2 camera ROS 2 driver and publisher for real-world deployment on the Holybro X500 V2 drone.

## Overview

This package provides:
- A lightweight OAK-D S2 RGB publisher node (`oak_publisher`)
- A keyboard teleoperation node (`keyboard_teleop`) for manual velocity control
- A hardware launch file with RViz2 visualization

## Hardware

- **Camera**: OAK-D S2 (Luxonis)
- **Compute**: NVIDIA Jetson (companion computer)
- **Drone**: Holybro X500 V2

## Dependencies

This package works alongside `depthai-ros` (already a submodule in `ros2_ws/src/depthai-ros`) which provides the full depthai ROS 2 driver stack.

## Launch

```bash
# Start OAK-D S2 camera with RViz2
ros2 launch depthai_cam oak_d_s2_hw.launch.py

# Without RViz2
ros2 launch depthai_cam oak_d_s2_hw.launch.py rviz:=false
```

## Topics

| Topic | Type | Description |
|-------|------|-------------|
| `/oak_d_s2/rgb/image_raw` | `sensor_msgs/Image` | RGB camera stream |
| `/oak_d_s2/depth/image_raw` | `sensor_msgs/Image` | Depth image |
| `/oak_d_s2/depth/points` | `sensor_msgs/PointCloud2` | Depth point cloud |

## Differences from Simulation

- **No Gazebo**: All simulation files (models/, worlds/, sim launch) have been removed
- **OAK-D S2 vs OAK-D Lite**: Updated topic namespace from `/oak_d_lite/` to `/oak_d_s2/`
- **Real hardware**: Direct DepthAI SDK integration for OAK-D S2 camera
