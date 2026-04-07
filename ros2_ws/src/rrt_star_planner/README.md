# rrt_star_planner

3D RRT* global motion planner using OMPL and ESDF collision checking for the Holybro X500 V2 drone.

## Overview

This package provides a 4D (x, y, z, yaw) RRT* planner that:
- Uses the ESDF server's `GetDistance` service for collision checking
- Runs asynchronously at ~1-3 Hz without blocking PX4 offboard control
- Publishes `nav_msgs/Path` for the path executor
- Visualizes the RRT tree and planned path in RViz2

## Features

- **Adaptive safety margin**: Automatically relaxes/tightens collision clearance based on planning success rate
- **Dense path validation**: Post-planning collision check along path segments
- **Safe prefix fallback**: If full path fails validation, publishes the safe prefix
- **Progressive approximate solutions**: Accepts approximate solutions that make progress toward the goal

## Topics

### Subscriptions
| Topic | Type | Description |
|-------|------|-------------|
| `goal_pose` | `geometry_msgs/PoseStamped` | Goal position in map frame |

### Publications
| Topic | Type | Description |
|-------|------|-------------|
| `path` | `nav_msgs/Path` | Planned collision-free path |
| `rrt_tree` | `visualization_msgs/MarkerArray` | RRT tree visualization |
| `path_markers` | `visualization_msgs/MarkerArray` | Path visualization |
| `planning_active` | `std_msgs/Bool` | Planning status flag |

### Services (Client)
| Service | Type | Description |
|---------|------|-------------|
| `get_distance` | `esdf_msgs/srv/GetDistance` | ESDF distance query |

## Dependencies

- OMPL (Open Motion Planning Library)
- esdf_msgs (GetDistance service)
- TF2 (for map -> base_link transform)
