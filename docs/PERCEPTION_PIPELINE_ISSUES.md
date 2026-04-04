# Perception pipeline — known issues and run notes

Last verified: 2026-03-30 (ROS 2 Humble, workspace under `ros2_ws/`).

## Build / workspace

**Run `colcon` from `ros2_ws`, not the repo root.**

If you run `colcon build` from `VIO_autonomous_drone/`, the install prefix is `.../VIO_autonomous_drone/install/`, which may not contain RTAB-Map packages (`rtabmap_odom`, `rtabmap_slam`, …). Those are installed under `ros2_ws/install/` when the workspace is built from `ros2_ws`.

```bash
cd ~/Desktop/brandon-testing/VIO_autonomous_drone/ros2_ws
source /opt/ros/humble/setup.bash
colcon build --packages-select vio_perception_pipeline
source install/setup.bash
```

Optional: remove stray `build/`, `install/`, `log/` next to `ros2_ws/` if you no longer use a second workspace layout at the repo root.

---

## Launch: `vio_perception_pipeline` + RTAB-Map

### Deprecation: `queue_size` → `sync_queue_size`

Both `rgbd_odometry` and `rtabmap` warn that `queue_size` was renamed to `sync_queue_size`. The value is still applied; updating `rtabmap.launch.py` to use `sync_queue_size` removes the warning.

### RTAB-Map: `Mem/UseOdomFeatures` vs detector settings

You may see:

`Memory.cpp: ... Mem/UseOdomFeatures is enabled, but Vis/FeatureType and Kp/DetectorStrategy parameters are not the same! Disabling Mem/UseOdomFeatures...`

This comes from mixing ORB-based VO (`Vis/FeatureType` = ORB) with a different `Kp/DetectorStrategy` on the SLAM side. RTAB-Map disables `Mem/UseOdomFeatures` automatically; it is informational unless you rely on that feature.

### `rtabmap_viz` without a display (SIGSEGV)

With `use_rtabmap_viz:=true` and **no** `DISPLAY` (typical on SSH or some IDE terminals), `rtabmap_viz` often exits immediately with **exit code -11** (SIGSEGV), because it uses OpenGL.

**Mitigations:**

- Use `use_rtabmap_viz:=false` (default) and use **RViz** on a machine with a GUI, or  
- On the robot/desktop session: `export DISPLAY=:0` (or the correct display) before launching.

`rgbd_odometry` and `rtabmap` can keep running even when `rtabmap_viz` dies; checking `ros2 node list` may show only `/rtabmap_viz` missing while `/rtabmap` is still present (or the opposite if SLAM crashes separately).

### Wrong topic on `depth/image` (possible SIGSEGV)

RTAB-Map expects **`depth/image`** to be a real **depth map** (`16UC1` in mm or `32FC1` in meters). If you remap it to a **stereo left/right** or **BGR** stream (e.g. `stereo/image_raw` when that is not depth), decoding can fail badly enough to **segfault**.

**Check:** `ros2 topic list | grep oak` and `ros2 topic echo /oak/stereo/depth --once` (or your depth topic) — **`encoding`** should be `16UC1` or `32FC1`, not `bgr8` / `mono8`.

The launch file remaps **`depth/image` → `oak/stereo/depth`** (aligned with `rtabmap_examples` DepthAI examples). If your driver only publishes depth on another name, change the remap to match.

### `/rtabmap` (SLAM) exit -11 (SIGSEGV) — observed

**`-11` is SIGSEGV** (segmentation fault). The same exit code as headless `rtabmap_viz`, but here it is the **`rtabmap_slam` / `rtabmap` process** that crashes — not the GUI.

Example from launch (processes start, then SLAM dies within a few seconds):

```text
[rtabmap-2]: process started with pid [58797]
...
[ERROR] [rtabmap-2]: process has died [pid 58797, exit code -11, cmd '.../rtabmap_slam/rtabmap --ros-args ...']
```

This pattern has been observed **on Jetson (Tegra)** when running the stack from `vio_perception_pipeline`.

**Why the log can look empty besides “process has died … -11”:** a **SIGSEGV** stops the process immediately. Buffered log lines may never flush to disk, and the per-node file under `~/.ros/log/...` can be **short or empty** for `rtabmap`. That is common — you are not necessarily missing a hidden error line; the crash often **does not** leave a neat RTAB-Map message before exit.

**What it usually is not:** a normal ROS “shutdown”; this is a **native crash** inside RTAB-Map (or linked libraries).

**Things to try when debugging:**

1. **Check `~/.ros/log/<timestamp>-.../`** for any `rtabmap*` files — if they only repeat what you already saw, use the steps below.
2. **Fresh database:** rename/remove `~/.ros/rtabmap.db` or start with RTAB-Map’s delete-DB flag once, in case a bad DB tickles a bug path.
3. **GPU / OpenCL / CUDA (Jetson):** the launch file sets GPU-oriented parameters (`SURF/GpuVersion`, `FAST/GpuVersion`, `ORB/Gpu`, `OdomBOW/GpuVersion`). You can edit `rtabmap.launch.py` to set those to `"false"` and test whether **-11** stops (points at GPU/CUDA paths). **Still `-11` with GPU off:** observed on Jetson — then the fault is likely elsewhere (CPU OpenCV, DB, optimizers, etc.). Next steps: **(a)** fresh `~/.ros/rtabmap.db` or `-d` once; **(b)** **`gdb` / core backtrace**; **(c)** try **`OMP_NUM_THREADS=1`**; **(d)** align **`Kp/DetectorStrategy`** with **`Vis/FeatureType`** if you change detectors.
4. **Core dump + backtrace:** run `ulimit -c unlimited` in the shell before launch; after crash, use `coredumpctl gdb` (systemd) or inspect `core`. Or run `rtabmap` under **`gdb --args`** with the same `--ros-args` as in the error line, then `run` and `bt` after SIGSEGV.
5. **Run the node on the terminal:** `ros2 run rtabmap_slam rtabmap --ros-args ...` with the same remaps/params so stdout/stderr are not split — sometimes more appears before the crash.

Do **not** assume “-11 always means no DISPLAY” — check **which process name** appears in the `[ERROR]` line (`rtabmap` vs `rtabmap_viz`).

### Stale RTAB-Map database (historical / intermittent)

Symptoms have included:

- `VWDictionary` / “Not found word” / empty dictionary messages  
- `Memory.cpp` / `addLink()` / `getWeight() >= 0` leading to process abort  
- SQLite **“database is locked”** if two nodes write the same DB

**Mitigations:** start from a fresh DB (e.g. remove or rename `~/.ros/rtabmap.db`, or pass RTAB-Map’s delete-db-on-start flag), avoid two writers on one DB, and keep VO/SLAM feature settings consistent with the DB you load.

---

## Frames and topics (quick reference)

| Name | Role |
|------|------|
| `oak` | Default camera namespace / `frame_id` for VO; TF chain `odom` → `oak`. |
| `/odom` | Visual odometry from `rgbd_odometry`; input to `enu_to_ned_transformer` when used. |
| `odom_local_map` | `PointCloud2` from **visual odometry** (debug / RViz); not required for PX4 fusion. |

---

## Commands used for the last smoke test

```bash
cd ~/Desktop/brandon-testing/VIO_autonomous_drone/ros2_ws
source /opt/ros/humble/setup.bash && source install/setup.bash
# Stable: no RTAB-Map GUI
timeout 75 ros2 launch vio_perception_pipeline rtabmap.launch.py use_rtabmap_viz:=false
```

Observed on that run: no `ERROR` / `FATAL` / `process has died` for `rgbd_odometry` or `rtabmap` (camera connected). Warnings: `queue_size` deprecation and `Mem/UseOdomFeatures` as above.

```bash
# Reproduces rtabmap_viz crash when DISPLAY is unset:
unset DISPLAY
timeout 20 ros2 launch vio_perception_pipeline rtabmap.launch.py use_rtabmap_viz:=true
# Expect: [ERROR] [rtabmap_viz-...]: process has died ... exit code -11
```
