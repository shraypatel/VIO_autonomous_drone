#!/usr/bin/env python3
"""Simple MAVSDK mission: arm, takeoff, hover for N seconds, then land."""

import asyncio
import sys
from typing import Optional

import rclpy
from rclpy.node import Node


class MavsdkTakeoffHoverLand(Node):
    """Execute a one-shot takeoff/hover/land sequence via MAVSDK."""

    def __init__(self) -> None:
        super().__init__("mavsdk_takeoff_hover_land")

        self.declare_parameter("system_address", "udp://:14550")
        self.declare_parameter("takeoff_height_m", 1.5)
        self.declare_parameter("hover_duration_s", 8.0)
        self.declare_parameter("land_timeout_s", 30.0)
        self.declare_parameter("connect_timeout_s", 20.0)

        self.system_address: str = str(self.get_parameter("system_address").value)
        self.takeoff_height_m: float = float(self.get_parameter("takeoff_height_m").value)
        self.hover_duration_s: float = float(self.get_parameter("hover_duration_s").value)
        self.land_timeout_s: float = float(self.get_parameter("land_timeout_s").value)
        self.connect_timeout_s: float = float(self.get_parameter("connect_timeout_s").value)

    async def run(self) -> int:
        try:
            from mavsdk import System
        except ImportError:
            self.get_logger().error(
                "MAVSDK is not installed. Install with: python3 -m pip install mavsdk"
            )
            return 1

        drone = System()
        self.get_logger().info(f"Connecting to MAVSDK system at {self.system_address}")
        await drone.connect(system_address=self.system_address)

        connected = await self._wait_for_connection(drone, self.connect_timeout_s)
        if not connected:
            self.get_logger().error("Timed out waiting for MAVSDK connection.")
            return 1

        self.get_logger().info("Waiting for vehicle to become armable...")
        armable = await self._wait_until_armable(drone, timeout_s=30.0)
        if not armable:
            self.get_logger().error(
                "Vehicle did not become armable. Check EKF status and preflight checks."
            )
            return 1

        self.get_logger().info(
            f"Arming and taking off to {self.takeoff_height_m:.2f} m, then hovering "
            f"for {self.hover_duration_s:.1f} s."
        )
        await drone.action.set_takeoff_altitude(self.takeoff_height_m)
        await drone.action.arm()
        await drone.action.takeoff()

        await asyncio.sleep(self.hover_duration_s)

        self.get_logger().info("Landing...")
        await drone.action.land()

        landed = await self._wait_until_landed(drone, timeout_s=self.land_timeout_s)
        if not landed:
            self.get_logger().warn("Land timeout reached; vehicle may still be landing.")
            return 1

        self.get_logger().info("Sequence complete: landed.")
        return 0

    async def _wait_for_connection(self, drone, timeout_s: float) -> bool:
        async def _inner() -> bool:
            async for state in drone.core.connection_state():
                if state.is_connected:
                    return True
            return False

        return await self._await_with_timeout(_inner(), timeout_s)

    async def _wait_until_armable(self, drone, timeout_s: float) -> bool:
        async def _inner() -> bool:
            async for health in drone.telemetry.health():
                if health.is_armable and health.is_local_position_ok:
                    return True
            return False

        return await self._await_with_timeout(_inner(), timeout_s)

    async def _wait_until_landed(self, drone, timeout_s: float) -> bool:
        async def _inner() -> bool:
            async for in_air in drone.telemetry.in_air():
                if not in_air:
                    return True
            return False

        return await self._await_with_timeout(_inner(), timeout_s)

    async def _await_with_timeout(self, awaitable, timeout_s: float) -> bool:
        try:
            return bool(await asyncio.wait_for(awaitable, timeout=timeout_s))
        except asyncio.TimeoutError:
            return False
        except Exception as exc:  # pylint: disable=broad-except
            self.get_logger().error(f"MAVSDK stream error: {exc}")
            return False


def main(args: Optional[list[str]] = None) -> None:
    rclpy.init(args=args)
    node = MavsdkTakeoffHoverLand()
    try:
        exit_code = asyncio.run(node.run())
    except KeyboardInterrupt:
        node.get_logger().info("Interrupted by user.")
        exit_code = 130
    except Exception as exc:  # pylint: disable=broad-except
        node.get_logger().error(f"Unhandled error: {exc}")
        exit_code = 1
    finally:
        node.destroy_node()
        rclpy.shutdown()

    sys.exit(exit_code)

