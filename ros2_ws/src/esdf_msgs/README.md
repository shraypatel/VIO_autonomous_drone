# esdf_msgs

Custom ROS 2 message and service definitions for ESDF (Euclidean Signed Distance Field) distance queries.

## Overview

This package provides the `GetDistance` service interface used for 3D collision checking by the autonomy stack. It is a generic interface that supports multiple backends:

- **OctoMap** (default, implemented in `esdf_server`)
- **NVBlox** (future, NVIDIA Jetson-optimized)
- **Voxblox** (future)

## Service Definition

### `GetDistance.srv`

**Request:**
| Field | Type | Description |
|-------|------|-------------|
| `x` | `float64` | Query X coordinate in map frame |
| `y` | `float64` | Query Y coordinate in map frame |
| `z` | `float64` | Query Z coordinate in map frame |

**Response:**
| Field | Type | Description |
|-------|------|-------------|
| `distance` | `float64` | Signed distance to nearest obstacle (positive = free space, negative = inside obstacle) |
| `valid` | `bool` | `false` if the query point is outside the map bounds or the map is not yet ready |

## Usage

```python
# Python client example
from esdf_msgs.srv import GetDistance
client = node.create_client(GetDistance, '/esdf_server/get_distance')
request = GetDistance.Request()
request.x, request.y, request.z = 1.0, 2.0, 1.5
future = client.call_async(request)
```

## Build

```bash
cd ros2_ws
colcon build --packages-select esdf_msgs
source install/setup.bash
```
