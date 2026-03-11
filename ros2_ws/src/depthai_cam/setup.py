from setuptools import find_packages, setup
from glob import glob

package_name = 'depthai_cam'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
        ('share/' + package_name + '/config', glob('config/*.rviz')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='group7',
    maintainer_email='shraypatel@gmail.com',
    description='OAK-D S2 camera ROS 2 driver/publisher for real-world deployment',
    license='BSD-3-Clause',
    extras_require={
        'test': ['pytest'],
    },
    entry_points={
        'console_scripts': [
            'oak_publisher = depthai_cam.oak_publisher:main',
            'keyboard_teleop = depthai_cam.keyboard_teleop:main',
        ],
    },
)
