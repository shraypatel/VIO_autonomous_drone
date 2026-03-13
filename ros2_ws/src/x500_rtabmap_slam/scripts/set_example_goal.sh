#!/bin/bash
# Send an example goal to the planner via ROS 2 topic
# Usage: ./set_example_goal.sh [x] [y] [z]
X=${1:-5.0}
Y=${2:-0.0}
Z=${3:-1.0}
echo "Sending goal: x=$X, y=$Y, z=$Z"
ros2 topic pub --once /maze_final_goal geometry_msgs/msg/PoseStamped \
  "{header: {frame_id: 'map'}, pose: {position: {x: $X, y: $Y, z: $Z}, orientation: {w: 1.0}}}"
