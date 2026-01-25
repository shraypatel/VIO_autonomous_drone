#!/bin/bash
#

version="4.10.0"
folder="workspace"

set -e

echo "------------------------------------"
echo "** Install additional CUDA dependencies"
echo "------------------------------------"
# Note: CUDA and cuDNN are already installed on Jetson

echo "------------------------------------"
echo "** Download opencv "${version}" (1/3)"
echo "------------------------------------"
mkdir -p $folder
cd ${folder}
curl -L https://github.com/opencv/opencv/archive/${version}.zip -o opencv-${version}.zip
curl -L https://github.com/opencv/opencv_contrib/archive/${version}.zip -o opencv_contrib-${version}.zip
unzip opencv-${version}.zip
unzip opencv_contrib-${version}.zip
rm opencv-${version}.zip opencv_contrib-${version}.zip
cd opencv-${version}/

echo "------------------------------------"
echo "** Build opencv "${version}" with CUDA (2/3)"
echo "------------------------------------"
mkdir -p release
cd release/

# Configure with CUDA support for Jetson Orin (CUDA arch 8.7)
cmake \
  -D CMAKE_BUILD_TYPE=RELEASE \
  -D CMAKE_INSTALL_PREFIX=/usr/local \
  -D CMAKE_POLICY_VERSION_MINIMUM=3.5 \
  -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-${version}/modules \
  -D WITH_CUDA=ON \
  -D WITH_CUDNN=ON \
  -D CUDA_ARCH_BIN="8.7" \
  -D CUDA_ARCH_PTX="" \
  -D CUDA_TOOLKIT_ROOT_DIR=/usr/local/cuda \
  -D ENABLE_FAST_MATH=ON \
  -D CUDA_FAST_MATH=ON \
  -D WITH_GSTREAMER=ON \
  -D WITH_LIBV4L=ON \
  -D BUILD_opencv_python3=ON \
  -D BUILD_TESTS=OFF \
  -D BUILD_PERF_TESTS=OFF \
  -D BUILD_EXAMPLES=OFF \
  -D BUILD_opencv_apps=OFF \
  -D OPENCV_GENERATE_PKGCONFIG=ON \
  ..

echo "------------------------------------"
echo "** Compile OpenCV (this will take ~30-60 minutes)"
echo "------------------------------------"
make -j$(nproc)

echo "------------------------------------"
echo "** Install opencv "${version}" (3/3)"
echo "------------------------------------"
make install

echo "------------------------------------"
echo "** Setup environment variables"
echo "------------------------------------"
echo 'export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH' >> ~/.bashrc
echo 'export PYTHONPATH=/usr/local/lib/python3.10/site-packages:$PYTHONPATH' >> ~/.bashrc
echo 'export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH' >> ~/.bashrc

# Source the new environment
source ~/.bashrc

echo "** OpenCV "${version}" with CUDA support successfully installed"
echo "** Please restart your terminal or run 'source ~/.bashrc' to load the new environment"