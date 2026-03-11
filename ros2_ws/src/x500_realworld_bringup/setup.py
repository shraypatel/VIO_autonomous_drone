from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'x500_realworld_bringup'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*.rviz')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='group7',
    maintainer_email='shraypatel@gmail.com',
    description='Real-world bringup for Holybro X500 V2 with full autonomy stack',
    license='BSD-3-Clause',
    tests_require=['pytest'],
    entry_points={'console_scripts': []},
)
