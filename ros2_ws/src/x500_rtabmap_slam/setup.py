from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'x500_rtabmap_slam'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
        (os.path.join('share', package_name, 'config'), glob('config/*.rviz')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='group7',
    maintainer_email='shraypatel@gmail.com',
    description='RTAB-Map SLAM for X500 V2 drone with OAK-D S2 (real-world, no Gazebo)',
    license='BSD-3-Clause',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'goal_from_rviz_node = rtabmap_slam.goal_from_rviz:main',
            'takeoff_node = rtabmap_slam.takeoff_node:main',
            'waypoint_mission_node = rtabmap_slam.waypoint_mission_node:main',
        ],
    },
)
