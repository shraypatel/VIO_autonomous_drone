# Safety Notes — Path Executor (Real Hardware)

## ⚠️ CRITICAL: This node sends velocity commands to a real flight controller

The path executor publishes velocity/position commands that directly control the Holybro X500 V2 drone via PX4 offboard mode. Improper use can result in:
- Uncontrolled flight
- Crashes
- Property damage or injury

## Arming Preconditions

Before enabling the path executor on real hardware:

1. **RC transmitter connected and functional** — Always have manual override capability
2. **Kill switch configured** — Hardware kill switch on the RC transmitter must be tested
3. **PX4 parameters verified**:
   - `COM_RCL_EXCEPT` set appropriately for offboard mode
   - `COM_OF_LOSS_T` (offboard loss timeout) set to a safe value (e.g., 0.5s)
   - `MPC_XY_VEL_MAX` and `MPC_Z_VEL_MAX` set to safe limits
4. **Battery level checked** — Minimum 80% for testing, 50% for field ops
5. **GPS lock confirmed** (if using GPS mode)
6. **VIO/SLAM operational** — Verify VINS-Fusion and RTABMap are publishing valid odometry

## Kill Switch Expectations

- The RC transmitter **MUST** have a dedicated kill switch channel mapped to PX4's `KILL_SWITCH` function
- Kill switch should immediately disarm motors regardless of software state
- Test the kill switch on the ground before every flight session

## PX4 DDS Bridge Topics

This node uses the following PX4 uXRCE-DDS bridge topics:
- `/x500_v2/cmd_vel` — Velocity commands (mapped to PX4 offboard velocity setpoints)
- `/x500_v2/enable` — Controller enable/disable
- `/fmu/in/offboard_control_mode` — PX4 offboard mode control
- `/fmu/in/trajectory_setpoint` — PX4 trajectory setpoints

## Recommended Bench-Test Procedure

### Step 1: Desk Test (Props Off)
1. Remove all propellers
2. Power on the drone with USB connection to Jetson
3. Launch the full autonomy stack
4. Verify TF tree is publishing correctly
5. Send a test goal via RViz2
6. Monitor `/x500_v2/cmd_vel` topic — verify commands are reasonable
7. Verify kill switch disarms the drone

### Step 2: Tethered Test
1. Attach the drone to a tether/test stand
2. Install propellers
3. Launch with `max_linear_speed: 0.3` and `max_angular_speed: 0.3`
4. Test takeoff and a simple waypoint
5. Test kill switch under power
6. Test path following with a 3-waypoint path

### Step 3: Free Flight (Open Area)
1. Open area with no obstacles within 10m
2. Start with altitude-only commands (takeoff to 1m, hover, land)
3. Gradually test XY motion
4. Test obstacle avoidance with a known obstacle

## Emergency Procedures

1. **Kill switch** — Immediately disarms motors
2. **Mode switch to MANUAL/STABILIZED** — Returns manual control
3. **RC failsafe** — If RC link is lost, PX4 will execute failsafe action (RTL or land)
4. **Software E-stop** — Publish zero velocity on `/x500_v2/cmd_vel`

## Parameter Tuning for Real Hardware

Start conservative and gradually increase:
```yaml
max_linear_speed: 0.3    # Start slow (default: 0.8)
max_angular_speed: 0.3   # Start slow (default: 0.8)
waypoint_tolerance: 0.35  # Wider tolerance for real sensors
```
