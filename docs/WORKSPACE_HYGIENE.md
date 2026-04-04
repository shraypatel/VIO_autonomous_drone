# Workspace Hygiene Summary

Keeping this repository clean is not just cosmetic. It directly affects reproducibility, build correctness, and debugging speed.

## Why this matters

1. Prevents stale artifacts from polluting runtime behavior.
2. Keeps package resolution deterministic.
3. Reduces "works on my machine" failures.
4. Makes CI/local behavior easier to compare.

## Core rules

1. Delete `build`, `install`, and `log` when resetting or after major dependency/layout changes.
2. Build only from `ros2_ws` (never from nested folders like `ros2_ws/src`).
3. Keep only one active copy of this repo on the host computer.

## Practical impact of each rule

### 1) Clean `build`, `install`, `log`
- Old CMake cache and generated metadata can keep incorrect include/lib paths.
- Stale install overlays can expose outdated launch files, params, and Python entry points.
- Old logs make current failures harder to identify.

### 2) Build only in `ros2_ws`
- Colcon expects `src` to be package source and writes artifacts to workspace-level `build/install/log`.
- Building in the wrong directory can create extra artifact trees and confusing overlay behavior.
- A single build location makes troubleshooting and cleanup predictable.

### 3) Keep one repo copy per host
- Multiple copies can silently contaminate dependency search paths (CMAKE_PREFIX_PATH, PYTHONPATH, sourced setup files).
- You may accidentally run nodes/launch files from another checkout.
- Duplicate repos increase risk of mixing binaries from one workspace with sources from another.

## Recommended cleanup routine

From the repo root:

```bash
cd ros2_ws
rm -rf build install log
source /opt/ros/humble/setup.bash
colcon build
source install/setup.bash
```

## Verification checklist

1. `pwd` before build is `<repo>/ros2_ws`.
2. Only one `build/install/log` set exists for the active workspace.
3. No extra clone of this repo exists elsewhere on the device.
4. The sourced environment matches the same workspace you just built.

Following these rules prevents accidental cross-workspace dependencies and keeps the perception stack behavior consistent.
