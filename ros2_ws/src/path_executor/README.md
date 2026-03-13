# path_executor

Path executor for the Holybro X500 V2 drone — follows `nav_msgs/Path` with velocity setpoints.

## Overview

This node executes planned waypoint paths from the RRT* planner by sending velocity commands to the flight controller. It includes:
- Waypoint tracking with configurable tolerance
- Hover-on-failure safety behavior
- Heading alignment before movement
- Altitude-first takeoff enforcement
- Body-frame velocity command support

## ⚠️ Safety

**READ `SAFETY_NOTES.md` BEFORE USING ON REAL HARDWARE.**

This is the most safety-critical package in the autonomy stack. It directly controls the drone's motion.

## Differences from Simulation

- **Topic namespace**: `/x500_v2/` instead of `/x500_depth/`
- **PX4 DDS**: Uses uXRCE-DDS bridge topics (`/fmu/in/...`, `/fmu/out/...`) — not MAVROS
- **Real sensors**: TF feedback from VINS-Fusion VIO, not simulated odometry

## Topics

### Subscriptions
| Topic | Type | Description |
|-------|------|-------------|
| `path` | `nav_msgs/Path` | Waypoints from RRT* planner |
| `planning_active` | `std_msgs/Bool` | Planning status |
| `/x500_v2/teleop_active` | `std_msgs/Bool` | Manual override |

### Publications
| Topic | Type | Description |
|-------|------|-------------|
| `/x500_v2/cmd_vel` | `geometry_msgs/Twist` | Velocity commands |
| `/x500_v2/enable` | `std_msgs/Bool` | Controller enable |

## Parameters

See the `declare_parameter` calls in `path_executor_node.py` for all configurable parameters.
