#!/usr/bin/env python3
"""ROS 2 node for publishing OAK-D S2 camera streams.

This node interfaces with an OAK-D S2 camera using the DepthAI SDK
and publishes RGBD image streams to ROS 2 topics.

For real-world deployment on Holybro X500 V2 with Jetson companion computer.
The depthai-ros driver (already in the workspace as a submodule) provides
the full pipeline; this node is a lightweight alternative for custom publishing.

Parameters
----------
width : int, default 640
    Width of the preview output in pixels.
height : int, default 480
    Height of the preview output in pixels.
fps : float, default 30.0
    Target frame rate for the camera capture.
topic : str, default '/oak_d_s2/rgb/image_raw'
    ROS topic name to publish RGB frames on.
"""
import rclpy
from rclpy.node import Node

import depthai as dai
from cv_bridge import CvBridge
from sensor_msgs.msg import Image


class OakPublisher(Node):
    """ROS 2 node for OAK-D S2 camera RGBD stream publishing."""

    def __init__(self):
        super().__init__('oak_publisher')

        self.declare_parameter('width', 640)
        self.declare_parameter('height', 480)
        self.declare_parameter('fps', 30.0)
        self.declare_parameter('topic', '/oak_d_s2/rgb/image_raw')

        self.width = self.get_parameter('width').get_parameter_value().integer_value
        self.height = self.get_parameter('height').get_parameter_value().integer_value
        self.fps = self.get_parameter('fps').get_parameter_value().double_value
        self.topic_name = self.get_parameter('topic').get_parameter_value().string_value

        self.get_logger().info(
            f'Starting OAK-D S2 publisher at {self.width}x{self.height} '
            f'@ {self.fps}Hz on \'{self.topic_name}\''
        )

        self.bridge = CvBridge()
        self.publisher_ = self.create_publisher(Image, self.topic_name, 10)

        # Initialize DepthAI pipeline for OAK-D S2
        self.pipeline = dai.Pipeline()

        # Configure RGB camera (OAK-D S2 uses same CAM_A board socket)
        cam_rgb = self.pipeline.create(dai.node.ColorCamera)
        cam_rgb.setBoardSocket(dai.CameraBoardSocket.CAM_A)
        cam_rgb.setResolution(
            dai.ColorCameraProperties.SensorResolution.THE_1080_P
        )
        cam_rgb.setPreviewSize(self.width, self.height)
        cam_rgb.setFps(self.fps)

        # Create XLinkOut for preview stream
        xout_rgb = self.pipeline.create(dai.node.XLinkOut)
        xout_rgb.setStreamName("rgb")
        cam_rgb.preview.link(xout_rgb.input)

        # Start device
        self.device = dai.Device(self.pipeline)
        self.q_rgb = self.device.getOutputQueue(
            name="rgb", maxSize=4, blocking=False
        )

        # Timer to poll frames at specified rate
        timer_period = 1.0 / self.fps
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        """Poll for new frames and publish to ROS topic."""
        in_frame = self.q_rgb.tryGet()
        if in_frame is None:
            return

        frame = in_frame.getCvFrame()
        msg = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'oak_d_s2_rgb_optical_frame'

        self.publisher_.publish(msg)


def main(args=None):
    """Entry point for the OAK publisher node."""
    rclpy.init(args=args)
    node = OakPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
