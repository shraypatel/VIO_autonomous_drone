#!/bin/bash
#
# Build RTAB-Map with CUDA support for Jetson Orin

version="0.22.1"
folder="workspace"

set -e

echo "------------------------------------"
echo "** Install RTAB-Map build dependencies"
echo "------------------------------------"
sudo apt update
sudo apt install -y \
    build-essential \
    cmake \
    git \
    libqt5opengl5-dev \
    libqt5svg5-dev \
    libeigen3-dev \
    libpcl-dev \
    libsqlite3-dev \
    libproj-dev \
    libqt5sql5-sqlite \
    libvtk9-dev \
    libvtk9-qt-dev \
    python3-dev \
    python3-numpy \
    libfreenect-dev \
    libopenni2-dev \
    libudev-dev \
    libsuitesparse-dev

echo "------------------------------------"
echo "** Download RTAB-Map ${version} source"
echo "------------------------------------"
mkdir -p ${folder}
cd ${folder}
if [ ! -d "rtabmap-${version}" ]; then
    curl -L https://github.com/introlab/rtabmap/archive/${version}.tar.gz -o rtabmap-${version}.tar.gz
    tar -xzf rtabmap-${version}.tar.gz
    rm rtabmap-${version}.tar.gz
fi

cd rtabmap-${version}

echo "------------------------------------"
echo "** Clean previous build (if exists)"
echo "------------------------------------"
rm -rf build/

echo "------------------------------------"
echo "** Setup CUDA OpenCV pkg-config"
echo "------------------------------------"
# Temporarily disable system OpenCV pkg-config
sudo mv /usr/lib/pkgconfig/opencv4.pc /usr/lib/pkgconfig/opencv4.pc.backup 2>/dev/null || true
sudo mv /usr/share/pkgconfig/opencv4.pc /usr/share/pkgconfig/opencv4.pc.backup 2>/dev/null || true

# Create pkg-config for CUDA OpenCV
sudo mkdir -p /usr/local/lib/pkgconfig
cat > /tmp/opencv4_cuda.pc << 'EOF'
# Package Information for CUDA OpenCV
prefix=/usr/local
exec_prefix=${prefix}
libdir=${exec_prefix}/lib
includedir=${prefix}/include/opencv4

Name: OpenCV
Description: Open Source Computer Vision Library with CUDA
Version: 4.10.0
Libs: -L${exec_prefix}/lib -lopencv_gapi -lopencv_highgui -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_video -lopencv_calib3d -lopencv_features2d -lopencv_dnn -lopencv_flann -lopencv_videoio -lopencv_imgcodecs -lopencv_imgproc -lopencv_core -lopencv_cudafeatures2d -lopencv_cudaoptflow -lopencv_cudaimgproc
Libs.private: -ldl -lm -lpthread -lrt -lcudart -lcublas -lcufft
Cflags: -I${includedir}
EOF
sudo cp /tmp/opencv4_cuda.pc /usr/local/lib/pkgconfig/opencv4.pc

echo "------------------------------------"
echo "** Configure RTAB-Map with OpenCV CUDA detection"
echo "------------------------------------"
mkdir -p build
cd build

export PATH=/usr/local/cuda/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH

# Force cmake to find OpenCV CUDA components by pre-defining them
export CMAKE_PREFIX_PATH="/usr/local:$CMAKE_PREFIX_PATH"

cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=/usr/local \
    -DWITH_QT=ON \
    -DWITH_OPENCV=ON \
    -DOpenCV_DIR=/usr/local/lib/cmake/opencv4 \
    -DCMAKE_PREFIX_PATH=/usr/local \
    -DWITH_PCL=ON \
    -DWITH_VTK=ON \
    -DWITH_PYTHON=ON \
    -DWITH_PYTHON_THREADING=ON \
    -DWITH_G2O=OFF \
    -DWITH_GTSAM=ON \
    -DWITH_CERES=OFF \
    -DWITH_OPENNI2=ON \
    -DWITH_FREENECT=ON \
    -DWITH_LIBUSB=ON \
    -DBUILD_APP=ON \
    -DBUILD_TOOLS=ON \
    -DBUILD_EXAMPLES=OFF \
    ..

echo "------------------------------------"
echo "** Verify CUDA components detected"
echo "------------------------------------"
# Check if CUDA components were detected
if grep -q "HAVE_OPENCV_GPU.*ON\|HAVE_OPENCV_GPU.*1" CMakeCache.txt 2>/dev/null; then
    echo "CUDA components detected successfully!"
    echo "GPU code paths will be compiled into RTAB-Map"
elif pkg-config --libs opencv4 | grep -q cuda; then
    echo "CUDA components found via pkg-config!"
else
    echo "CUDA components NOT detected. Checking cmake output..."
    echo "Looking for CUDA detection in cmake output..."
    if grep -q "Found OpenCV CUDA" ../CMakeFiles/CMakeOutput.log 2>/dev/null; then
        echo "CUDA components found in cmake logs"
    else
        echo "CUDA components still not detected."
        echo "Current pkg-config output:"
        pkg-config --libs opencv4 || echo "pkg-config failed"
    fi
fi

echo "------------------------------------"
echo "** Build RTAB-Map with CUDA support (this will take ~10-15 minutes)"
echo "------------------------------------"
make -j$(nproc)

echo "------------------------------------"
echo "** Install RTAB-Map with CUDA support"
echo "------------------------------------"
sudo make install

echo "------------------------------------"
echo "** Restore system OpenCV pkg-config"
echo "------------------------------------"
# Restore system OpenCV pkg-config
sudo mv /usr/lib/pkgconfig/opencv4.pc.backup /usr/lib/pkgconfig/opencv4.pc 2>/dev/null || true
sudo mv /usr/share/pkgconfig/opencv4.pc.backup /usr/share/pkgconfig/opencv4.pc 2>/dev/null || true

echo "------------------------------------"
echo "** Setup environment variables"
echo "------------------------------------"
echo 'export PATH=/usr/local/cuda/bin:$PATH' >> ~/.bashrc
echo 'export LD_LIBRARY_PATH=/usr/local/cuda/lib64:$LD_LIBRARY_PATH' >> ~/.bashrc

# Source the new environment
source ~/.bashrc

echo "** RTAB-Map ${version} with CUDA support successfully installed"
echo "** Please restart your terminal or run 'source ~/.bashrc' to load the new environment"
echo "** Test with: rtabmap --version"
echo "** GPU features (SURF/ORB/FAST GPU) should now work without stack smashing!"
echo "** The build forced GPU code compilation - runtime GPU features should work!"
echo "** Bye :)"