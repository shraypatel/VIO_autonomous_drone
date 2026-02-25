import os
from glob import glob
from setuptools import setup, find_packages

package_name = "vio_perception_pipeline"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name, "launch"), glob("launch/*.launch.py")),
        (os.path.join("share", package_name, "config"), glob("config/*.yaml")),
        (os.path.join("share", package_name, "config", "rviz"), glob("config/rviz/*.rviz")),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="group7",
    maintainer_email="shraypatel@gmail.com",
    description="DepthAI + RTAB-Map perception pipeline with PX4 coordinate transformation",
    license="MIT",
    entry_points={
        "console_scripts": [
            "enu_to_ned_transformer = vio_perception_pipeline.enu_to_ned_transformer:main",
            "auto_reset_odom = vio_perception_pipeline.auto_reset_odom:main",
            "mavsdk_takeoff_hover_land = vio_perception_pipeline.mavsdk_takeoff_hover_land:main",
        ],
    },
)
