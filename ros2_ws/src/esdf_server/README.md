# esdf_server

Euclidean Signed Distance Field (ESDF) server for obstacle avoidance on the Holybro X500 V2 drone.

## Overview

This package provides:
- `esdf_server_node`: OctoMap-based ESDF server that subscribes to point clouds, builds a volumetric map, and answers `GetDistance` service requests for collision checking
- `point_cloud_filter_node`: Pre-filter that removes NaN/Inf points and optional ground points

## Differences from Simulation

- **Point cloud source**: Uses `/oak_d_s2/depth/points` from the real OAK-D S2 camera (not simulated OAK-D Lite)
- **No Gazebo dependencies**: Pure point cloud consumer, no simulation-specific configuration
- **Jetson compatible**: No x86-specific intrinsics; works on ARM64 (JetPack)

## Topics

### Subscriptions
| Topic | Type | Description |
|-------|------|-------------|
| `/oak_d_s2/depth/points` | `sensor_msgs/PointCloud2` | Input point cloud |

### Services
| Service | Type | Description |
|---------|------|-------------|
| `get_distance` | `esdf_msgs/srv/GetDistance` | Query distance to nearest obstacle |

### Publications
| Topic | Type | Description |
|-------|------|-------------|
| `esdf_slice` | `visualization_msgs/MarkerArray` | ESDF visualization for RViz2 |

## Parameters

See `config/esdf_params.yaml` for all configurable parameters.
