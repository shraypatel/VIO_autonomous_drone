//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_XFEATURES2D

#include <string>

#include "opencv2/xfeatures2d.hpp"

#include "/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/workspace/opencv-4.10.0/../opencv_contrib-4.10.0/modules/xfeatures2d/include/opencv2/xfeatures2d.hpp"
#include "/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/workspace/opencv-4.10.0/../opencv_contrib-4.10.0/modules/xfeatures2d/include/opencv2/xfeatures2d/nonfree.hpp"
#include "/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/workspace/opencv-4.10.0/../opencv_contrib-4.10.0/modules/xfeatures2d/include/opencv2/xfeatures2d/cuda.hpp"

#define LOG_TAG "org.opencv.xfeatures2d"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_xfeatures2d
static void throwJavaException(JNIEnv *env, const std::exception *e, const char *method) {
  std::string what = "unknown exception";
  jclass je = 0;

  if(e) {
    std::string exception_type = "std::exception";

    if(dynamic_cast<const cv::Exception*>(e)) {
      exception_type = "cv::Exception";
      je = env->FindClass("org/opencv/core/CvException");
    }

    what = exception_type + ": " + e->what();
  }

  if(!je) je = env->FindClass("java/lang/Exception");
  env->ThrowNew(je, what.c_str());

  LOGE("%s caught %s", method, what.c_str());
  (void)method;        // avoid "unused" warning
}

extern "C" {


//
//  void cv::xfeatures2d::matchGMS(Size size1, Size size2, vector_KeyPoint keypoints1, vector_KeyPoint keypoints2, vector_DMatch matches1to2, vector_DMatch& matchesGMS, bool withRotation = false, bool withScale = false, double thresholdFactor = 6.0)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_Xfeatures2d_matchGMS_10 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jlong, jlong, jlong, jlong, jboolean, jboolean, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_Xfeatures2d_matchGMS_10
  (JNIEnv* env, jclass , jdouble size1_width, jdouble size1_height, jdouble size2_width, jdouble size2_height, jlong keypoints1_mat_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong matchesGMS_mat_nativeObj, jboolean withRotation, jboolean withScale, jdouble thresholdFactor)
{
    
    static const char method_name[] = "xfeatures2d::matchGMS_10()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector<DMatch> matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_DMatch( matches1to2_mat, matches1to2 );
        std::vector<DMatch> matchesGMS;
        Mat& matchesGMS_mat = *((Mat*)matchesGMS_mat_nativeObj);
        Size size1((int)size1_width, (int)size1_height);
        Size size2((int)size2_width, (int)size2_height);
        cv::xfeatures2d::matchGMS( size1, size2, keypoints1, keypoints2, matches1to2, matchesGMS, (bool)withRotation, (bool)withScale, (double)thresholdFactor );
        vector_DMatch_to_Mat( matchesGMS, matchesGMS_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_Xfeatures2d_matchGMS_11 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jlong, jlong, jlong, jlong, jboolean, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_Xfeatures2d_matchGMS_11
  (JNIEnv* env, jclass , jdouble size1_width, jdouble size1_height, jdouble size2_width, jdouble size2_height, jlong keypoints1_mat_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong matchesGMS_mat_nativeObj, jboolean withRotation, jboolean withScale)
{
    
    static const char method_name[] = "xfeatures2d::matchGMS_11()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector<DMatch> matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_DMatch( matches1to2_mat, matches1to2 );
        std::vector<DMatch> matchesGMS;
        Mat& matchesGMS_mat = *((Mat*)matchesGMS_mat_nativeObj);
        Size size1((int)size1_width, (int)size1_height);
        Size size2((int)size2_width, (int)size2_height);
        cv::xfeatures2d::matchGMS( size1, size2, keypoints1, keypoints2, matches1to2, matchesGMS, (bool)withRotation, (bool)withScale );
        vector_DMatch_to_Mat( matchesGMS, matchesGMS_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_Xfeatures2d_matchGMS_12 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jlong, jlong, jlong, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_Xfeatures2d_matchGMS_12
  (JNIEnv* env, jclass , jdouble size1_width, jdouble size1_height, jdouble size2_width, jdouble size2_height, jlong keypoints1_mat_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong matchesGMS_mat_nativeObj, jboolean withRotation)
{
    
    static const char method_name[] = "xfeatures2d::matchGMS_12()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector<DMatch> matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_DMatch( matches1to2_mat, matches1to2 );
        std::vector<DMatch> matchesGMS;
        Mat& matchesGMS_mat = *((Mat*)matchesGMS_mat_nativeObj);
        Size size1((int)size1_width, (int)size1_height);
        Size size2((int)size2_width, (int)size2_height);
        cv::xfeatures2d::matchGMS( size1, size2, keypoints1, keypoints2, matches1to2, matchesGMS, (bool)withRotation );
        vector_DMatch_to_Mat( matchesGMS, matchesGMS_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_Xfeatures2d_matchGMS_13 (JNIEnv*, jclass, jdouble, jdouble, jdouble, jdouble, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_Xfeatures2d_matchGMS_13
  (JNIEnv* env, jclass , jdouble size1_width, jdouble size1_height, jdouble size2_width, jdouble size2_height, jlong keypoints1_mat_nativeObj, jlong keypoints2_mat_nativeObj, jlong matches1to2_mat_nativeObj, jlong matchesGMS_mat_nativeObj)
{
    
    static const char method_name[] = "xfeatures2d::matchGMS_13()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector<DMatch> matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        Mat_to_vector_DMatch( matches1to2_mat, matches1to2 );
        std::vector<DMatch> matchesGMS;
        Mat& matchesGMS_mat = *((Mat*)matchesGMS_mat_nativeObj);
        Size size1((int)size1_width, (int)size1_height);
        Size size2((int)size2_width, (int)size2_height);
        cv::xfeatures2d::matchGMS( size1, size2, keypoints1, keypoints2, matches1to2, matchesGMS );
        vector_DMatch_to_Mat( matchesGMS, matchesGMS_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::xfeatures2d::matchLOGOS(vector_KeyPoint keypoints1, vector_KeyPoint keypoints2, vector_int nn1, vector_int nn2, vector_DMatch& matches1to2)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_Xfeatures2d_matchLOGOS_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_Xfeatures2d_matchLOGOS_10
  (JNIEnv* env, jclass , jlong keypoints1_mat_nativeObj, jlong keypoints2_mat_nativeObj, jlong nn1_mat_nativeObj, jlong nn2_mat_nativeObj, jlong matches1to2_mat_nativeObj)
{
    
    static const char method_name[] = "xfeatures2d::matchLOGOS_10()";
    try {
        LOGD("%s", method_name);
        std::vector<KeyPoint> keypoints1;
        Mat& keypoints1_mat = *((Mat*)keypoints1_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints1_mat, keypoints1 );
        std::vector<KeyPoint> keypoints2;
        Mat& keypoints2_mat = *((Mat*)keypoints2_mat_nativeObj);
        Mat_to_vector_KeyPoint( keypoints2_mat, keypoints2 );
        std::vector<int> nn1;
        Mat& nn1_mat = *((Mat*)nn1_mat_nativeObj);
        Mat_to_vector_int( nn1_mat, nn1 );
        std::vector<int> nn2;
        Mat& nn2_mat = *((Mat*)nn2_mat_nativeObj);
        Mat_to_vector_int( nn2_mat, nn2 );
        std::vector<DMatch> matches1to2;
        Mat& matches1to2_mat = *((Mat*)matches1to2_mat_nativeObj);
        cv::xfeatures2d::matchLOGOS( keypoints1, keypoints2, nn1, nn2, matches1to2 );
        vector_DMatch_to_Mat( matches1to2, matches1to2_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// static Ptr_SURF_CUDA cv::cuda::SURF_CUDA::create(double _hessianThreshold, int _nOctaves = 4, int _nOctaveLayers = 2, bool _extended = false, float _keypointsRatio = 0.01f, bool _upright = false)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_10 (JNIEnv*, jclass, jdouble, jint, jint, jboolean, jfloat, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_10
  (JNIEnv* env, jclass , jdouble _hessianThreshold, jint _nOctaves, jint _nOctaveLayers, jboolean _extended, jfloat _keypointsRatio, jboolean _upright)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::cuda::SURF_CUDA> Ptr_SURF_CUDA;
        Ptr_SURF_CUDA _retval_ = cv::cuda::SURF_CUDA::create( (double)_hessianThreshold, (int)_nOctaves, (int)_nOctaveLayers, (bool)_extended, (float)_keypointsRatio, (bool)_upright );
        return (jlong)(new Ptr_SURF_CUDA(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_11 (JNIEnv*, jclass, jdouble, jint, jint, jboolean, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_11
  (JNIEnv* env, jclass , jdouble _hessianThreshold, jint _nOctaves, jint _nOctaveLayers, jboolean _extended, jfloat _keypointsRatio)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::cuda::SURF_CUDA> Ptr_SURF_CUDA;
        Ptr_SURF_CUDA _retval_ = cv::cuda::SURF_CUDA::create( (double)_hessianThreshold, (int)_nOctaves, (int)_nOctaveLayers, (bool)_extended, (float)_keypointsRatio );
        return (jlong)(new Ptr_SURF_CUDA(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_12 (JNIEnv*, jclass, jdouble, jint, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_12
  (JNIEnv* env, jclass , jdouble _hessianThreshold, jint _nOctaves, jint _nOctaveLayers, jboolean _extended)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::cuda::SURF_CUDA> Ptr_SURF_CUDA;
        Ptr_SURF_CUDA _retval_ = cv::cuda::SURF_CUDA::create( (double)_hessianThreshold, (int)_nOctaves, (int)_nOctaveLayers, (bool)_extended );
        return (jlong)(new Ptr_SURF_CUDA(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_13 (JNIEnv*, jclass, jdouble, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_13
  (JNIEnv* env, jclass , jdouble _hessianThreshold, jint _nOctaves, jint _nOctaveLayers)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::cuda::SURF_CUDA> Ptr_SURF_CUDA;
        Ptr_SURF_CUDA _retval_ = cv::cuda::SURF_CUDA::create( (double)_hessianThreshold, (int)_nOctaves, (int)_nOctaveLayers );
        return (jlong)(new Ptr_SURF_CUDA(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_14 (JNIEnv*, jclass, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_14
  (JNIEnv* env, jclass , jdouble _hessianThreshold, jint _nOctaves)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::cuda::SURF_CUDA> Ptr_SURF_CUDA;
        Ptr_SURF_CUDA _retval_ = cv::cuda::SURF_CUDA::create( (double)_hessianThreshold, (int)_nOctaves );
        return (jlong)(new Ptr_SURF_CUDA(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_15 (JNIEnv*, jclass, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_create_15
  (JNIEnv* env, jclass , jdouble _hessianThreshold)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::cuda::SURF_CUDA> Ptr_SURF_CUDA;
        Ptr_SURF_CUDA _retval_ = cv::cuda::SURF_CUDA::create( (double)_hessianThreshold );
        return (jlong)(new Ptr_SURF_CUDA(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::cuda::SURF_CUDA::descriptorSize()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_descriptorSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_descriptorSize_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::descriptorSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::cuda::SURF_CUDA>* me = (Ptr<cv::cuda::SURF_CUDA>*) self; //TODO: check for NULL
        return (*me)->descriptorSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::cuda::SURF_CUDA::defaultNorm()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_defaultNorm_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_defaultNorm_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::defaultNorm_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::cuda::SURF_CUDA>* me = (Ptr<cv::cuda::SURF_CUDA>*) self; //TODO: check for NULL
        return (*me)->defaultNorm();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// double SURF_CUDA::hessianThreshold
//

JNIEXPORT jdouble JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1hessianThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1hessianThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::get_1hessianThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::cuda::SURF_CUDA>* me = (Ptr<cv::cuda::SURF_CUDA>*) self; //TODO: check for NULL
        return (*me)->hessianThreshold;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// int SURF_CUDA::nOctaves
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1nOctaves_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1nOctaves_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::get_1nOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::cuda::SURF_CUDA>* me = (Ptr<cv::cuda::SURF_CUDA>*) self; //TODO: check for NULL
        return (*me)->nOctaves;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// int SURF_CUDA::nOctaveLayers
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1nOctaveLayers_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1nOctaveLayers_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::get_1nOctaveLayers_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::cuda::SURF_CUDA>* me = (Ptr<cv::cuda::SURF_CUDA>*) self; //TODO: check for NULL
        return (*me)->nOctaveLayers;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// bool SURF_CUDA::extended
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1extended_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1extended_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::get_1extended_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::cuda::SURF_CUDA>* me = (Ptr<cv::cuda::SURF_CUDA>*) self; //TODO: check for NULL
        return (*me)->extended;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// bool SURF_CUDA::upright
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1upright_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1upright_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::get_1upright_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::cuda::SURF_CUDA>* me = (Ptr<cv::cuda::SURF_CUDA>*) self; //TODO: check for NULL
        return (*me)->upright;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// float SURF_CUDA::keypointsRatio
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1keypointsRatio_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_get_1keypointsRatio_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::cuda;
    static const char method_name[] = "xfeatures2d::get_1keypointsRatio_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::cuda::SURF_CUDA>* me = (Ptr<cv::cuda::SURF_CUDA>*) self; //TODO: check for NULL
        return (*me)->keypointsRatio;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void Ptr<cv::cuda::SURF_CUDA>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_1CUDA_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::cuda::SURF_CUDA>*) self;
}


//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::AffineFeature2D>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_AffineFeature2D_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_AffineFeature2D_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::AffineFeature2D>*) self;
}


//
// static Ptr_BEBLID cv::xfeatures2d::BEBLID::create(float scale_factor, int n_bits = BEBLID::SIZE_512_BITS)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BEBLID_create_10 (JNIEnv*, jclass, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BEBLID_create_10
  (JNIEnv* env, jclass , jfloat scale_factor, jint n_bits)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::BEBLID> Ptr_BEBLID;
        Ptr_BEBLID _retval_ = cv::xfeatures2d::BEBLID::create( (float)scale_factor, (int)n_bits );
        return (jlong)(new Ptr_BEBLID(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BEBLID_create_11 (JNIEnv*, jclass, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BEBLID_create_11
  (JNIEnv* env, jclass , jfloat scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::BEBLID> Ptr_BEBLID;
        Ptr_BEBLID _retval_ = cv::xfeatures2d::BEBLID::create( (float)scale_factor );
        return (jlong)(new Ptr_BEBLID(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::BEBLID::setScaleFactor(float scale_factor)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BEBLID_setScaleFactor_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BEBLID_setScaleFactor_10
  (JNIEnv* env, jclass , jlong self, jfloat scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BEBLID>* me = (Ptr<cv::xfeatures2d::BEBLID>*) self; //TODO: check for NULL
        (*me)->setScaleFactor( (float)scale_factor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::BEBLID::getScaleFactor()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_BEBLID_getScaleFactor_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_BEBLID_getScaleFactor_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BEBLID>* me = (Ptr<cv::xfeatures2d::BEBLID>*) self; //TODO: check for NULL
        return (*me)->getScaleFactor();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::BEBLID::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_BEBLID_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_BEBLID_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BEBLID>* me = (Ptr<cv::xfeatures2d::BEBLID>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::BEBLID>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BEBLID_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BEBLID_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::BEBLID>*) self;
}


//
// static Ptr_BoostDesc cv::xfeatures2d::BoostDesc::create(int desc = BoostDesc::BINBOOST_256, bool use_scale_orientation = true, float scale_factor = 6.25f)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BoostDesc_create_10 (JNIEnv*, jclass, jint, jboolean, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BoostDesc_create_10
  (JNIEnv* env, jclass , jint desc, jboolean use_scale_orientation, jfloat scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::BoostDesc> Ptr_BoostDesc;
        Ptr_BoostDesc _retval_ = cv::xfeatures2d::BoostDesc::create( (int)desc, (bool)use_scale_orientation, (float)scale_factor );
        return (jlong)(new Ptr_BoostDesc(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BoostDesc_create_11 (JNIEnv*, jclass, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BoostDesc_create_11
  (JNIEnv* env, jclass , jint desc, jboolean use_scale_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::BoostDesc> Ptr_BoostDesc;
        Ptr_BoostDesc _retval_ = cv::xfeatures2d::BoostDesc::create( (int)desc, (bool)use_scale_orientation );
        return (jlong)(new Ptr_BoostDesc(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BoostDesc_create_12 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BoostDesc_create_12
  (JNIEnv* env, jclass , jint desc)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::BoostDesc> Ptr_BoostDesc;
        Ptr_BoostDesc _retval_ = cv::xfeatures2d::BoostDesc::create( (int)desc );
        return (jlong)(new Ptr_BoostDesc(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BoostDesc_create_13 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BoostDesc_create_13
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::BoostDesc> Ptr_BoostDesc;
        Ptr_BoostDesc _retval_ = cv::xfeatures2d::BoostDesc::create();
        return (jlong)(new Ptr_BoostDesc(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::BoostDesc::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_BoostDesc_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_BoostDesc_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BoostDesc>* me = (Ptr<cv::xfeatures2d::BoostDesc>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  void cv::xfeatures2d::BoostDesc::setUseScaleOrientation(bool use_scale_orientation)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BoostDesc_setUseScaleOrientation_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BoostDesc_setUseScaleOrientation_10
  (JNIEnv* env, jclass , jlong self, jboolean use_scale_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setUseScaleOrientation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BoostDesc>* me = (Ptr<cv::xfeatures2d::BoostDesc>*) self; //TODO: check for NULL
        (*me)->setUseScaleOrientation( (bool)use_scale_orientation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::BoostDesc::getUseScaleOrientation()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_BoostDesc_getUseScaleOrientation_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_BoostDesc_getUseScaleOrientation_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getUseScaleOrientation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BoostDesc>* me = (Ptr<cv::xfeatures2d::BoostDesc>*) self; //TODO: check for NULL
        return (*me)->getUseScaleOrientation();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::BoostDesc::setScaleFactor(float scale_factor)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BoostDesc_setScaleFactor_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BoostDesc_setScaleFactor_10
  (JNIEnv* env, jclass , jlong self, jfloat scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BoostDesc>* me = (Ptr<cv::xfeatures2d::BoostDesc>*) self; //TODO: check for NULL
        (*me)->setScaleFactor( (float)scale_factor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::BoostDesc::getScaleFactor()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_BoostDesc_getScaleFactor_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_BoostDesc_getScaleFactor_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BoostDesc>* me = (Ptr<cv::xfeatures2d::BoostDesc>*) self; //TODO: check for NULL
        return (*me)->getScaleFactor();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::BoostDesc>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BoostDesc_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BoostDesc_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::BoostDesc>*) self;
}


//
// static Ptr_BriefDescriptorExtractor cv::xfeatures2d::BriefDescriptorExtractor::create(int bytes = 32, bool use_orientation = false)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_create_10 (JNIEnv*, jclass, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_create_10
  (JNIEnv* env, jclass , jint bytes, jboolean use_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::BriefDescriptorExtractor> Ptr_BriefDescriptorExtractor;
        Ptr_BriefDescriptorExtractor _retval_ = cv::xfeatures2d::BriefDescriptorExtractor::create( (int)bytes, (bool)use_orientation );
        return (jlong)(new Ptr_BriefDescriptorExtractor(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_create_11 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_create_11
  (JNIEnv* env, jclass , jint bytes)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::BriefDescriptorExtractor> Ptr_BriefDescriptorExtractor;
        Ptr_BriefDescriptorExtractor _retval_ = cv::xfeatures2d::BriefDescriptorExtractor::create( (int)bytes );
        return (jlong)(new Ptr_BriefDescriptorExtractor(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_create_12 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_create_12
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::BriefDescriptorExtractor> Ptr_BriefDescriptorExtractor;
        Ptr_BriefDescriptorExtractor _retval_ = cv::xfeatures2d::BriefDescriptorExtractor::create();
        return (jlong)(new Ptr_BriefDescriptorExtractor(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::BriefDescriptorExtractor::setDescriptorSize(int bytes)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_setDescriptorSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_setDescriptorSize_10
  (JNIEnv* env, jclass , jlong self, jint bytes)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setDescriptorSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BriefDescriptorExtractor>* me = (Ptr<cv::xfeatures2d::BriefDescriptorExtractor>*) self; //TODO: check for NULL
        (*me)->setDescriptorSize( (int)bytes );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::BriefDescriptorExtractor::getDescriptorSize()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_getDescriptorSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_getDescriptorSize_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDescriptorSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BriefDescriptorExtractor>* me = (Ptr<cv::xfeatures2d::BriefDescriptorExtractor>*) self; //TODO: check for NULL
        return (*me)->getDescriptorSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::BriefDescriptorExtractor::setUseOrientation(bool use_orientation)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_setUseOrientation_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_setUseOrientation_10
  (JNIEnv* env, jclass , jlong self, jboolean use_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setUseOrientation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BriefDescriptorExtractor>* me = (Ptr<cv::xfeatures2d::BriefDescriptorExtractor>*) self; //TODO: check for NULL
        (*me)->setUseOrientation( (bool)use_orientation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::BriefDescriptorExtractor::getUseOrientation()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_getUseOrientation_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_getUseOrientation_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getUseOrientation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BriefDescriptorExtractor>* me = (Ptr<cv::xfeatures2d::BriefDescriptorExtractor>*) self; //TODO: check for NULL
        return (*me)->getUseOrientation();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::BriefDescriptorExtractor::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::BriefDescriptorExtractor>* me = (Ptr<cv::xfeatures2d::BriefDescriptorExtractor>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::BriefDescriptorExtractor>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_BriefDescriptorExtractor_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::BriefDescriptorExtractor>*) self;
}


//
// static Ptr_DAISY cv::xfeatures2d::DAISY::create(float radius = 15, int q_radius = 3, int q_theta = 8, int q_hist = 8, DAISY_NormalizationType norm = DAISY::NRM_NONE, Mat H = Mat(), bool interpolation = true, bool use_orientation = false)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_10 (JNIEnv*, jclass, jfloat, jint, jint, jint, jlong, jboolean, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_10
  (JNIEnv* env, jclass , jfloat radius, jint q_radius, jint q_theta, jint q_hist, jlong H_nativeObj, jboolean interpolation, jboolean use_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::DAISY> Ptr_DAISY;
        Mat& H = *((Mat*)H_nativeObj);
        Ptr_DAISY _retval_ = cv::xfeatures2d::DAISY::create( (float)radius, (int)q_radius, (int)q_theta, (int)q_hist, DAISY::NRM_NONE, H, (bool)interpolation, (bool)use_orientation );
        return (jlong)(new Ptr_DAISY(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_11 (JNIEnv*, jclass, jfloat, jint, jint, jint, jlong, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_11
  (JNIEnv* env, jclass , jfloat radius, jint q_radius, jint q_theta, jint q_hist, jlong H_nativeObj, jboolean interpolation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::DAISY> Ptr_DAISY;
        Mat& H = *((Mat*)H_nativeObj);
        Ptr_DAISY _retval_ = cv::xfeatures2d::DAISY::create( (float)radius, (int)q_radius, (int)q_theta, (int)q_hist, DAISY::NRM_NONE, H, (bool)interpolation );
        return (jlong)(new Ptr_DAISY(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_12 (JNIEnv*, jclass, jfloat, jint, jint, jint, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_12
  (JNIEnv* env, jclass , jfloat radius, jint q_radius, jint q_theta, jint q_hist, jlong H_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::DAISY> Ptr_DAISY;
        Mat& H = *((Mat*)H_nativeObj);
        Ptr_DAISY _retval_ = cv::xfeatures2d::DAISY::create( (float)radius, (int)q_radius, (int)q_theta, (int)q_hist, DAISY::NRM_NONE, H );
        return (jlong)(new Ptr_DAISY(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_13 (JNIEnv*, jclass, jfloat, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_13
  (JNIEnv* env, jclass , jfloat radius, jint q_radius, jint q_theta, jint q_hist)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::DAISY> Ptr_DAISY;
        Ptr_DAISY _retval_ = cv::xfeatures2d::DAISY::create( (float)radius, (int)q_radius, (int)q_theta, (int)q_hist, DAISY::NRM_NONE );
        return (jlong)(new Ptr_DAISY(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_15 (JNIEnv*, jclass, jfloat, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_15
  (JNIEnv* env, jclass , jfloat radius, jint q_radius, jint q_theta)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::DAISY> Ptr_DAISY;
        Ptr_DAISY _retval_ = cv::xfeatures2d::DAISY::create( (float)radius, (int)q_radius, (int)q_theta );
        return (jlong)(new Ptr_DAISY(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_16 (JNIEnv*, jclass, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_16
  (JNIEnv* env, jclass , jfloat radius, jint q_radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::DAISY> Ptr_DAISY;
        Ptr_DAISY _retval_ = cv::xfeatures2d::DAISY::create( (float)radius, (int)q_radius );
        return (jlong)(new Ptr_DAISY(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_17 (JNIEnv*, jclass, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_17
  (JNIEnv* env, jclass , jfloat radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_17()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::DAISY> Ptr_DAISY;
        Ptr_DAISY _retval_ = cv::xfeatures2d::DAISY::create( (float)radius );
        return (jlong)(new Ptr_DAISY(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_18 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_create_18
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_18()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::DAISY> Ptr_DAISY;
        Ptr_DAISY _retval_ = cv::xfeatures2d::DAISY::create();
        return (jlong)(new Ptr_DAISY(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::DAISY::setRadius(float radius)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setRadius_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setRadius_10
  (JNIEnv* env, jclass , jlong self, jfloat radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        (*me)->setRadius( (float)radius );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::DAISY::getRadius()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_DAISY_getRadius_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_DAISY_getRadius_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        return (*me)->getRadius();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::DAISY::setQRadius(int q_radius)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setQRadius_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setQRadius_10
  (JNIEnv* env, jclass , jlong self, jint q_radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setQRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        (*me)->setQRadius( (int)q_radius );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::DAISY::getQRadius()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_DAISY_getQRadius_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_DAISY_getQRadius_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getQRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        return (*me)->getQRadius();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::DAISY::setQTheta(int q_theta)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setQTheta_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setQTheta_10
  (JNIEnv* env, jclass , jlong self, jint q_theta)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setQTheta_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        (*me)->setQTheta( (int)q_theta );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::DAISY::getQTheta()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_DAISY_getQTheta_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_DAISY_getQTheta_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getQTheta_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        return (*me)->getQTheta();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::DAISY::setQHist(int q_hist)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setQHist_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setQHist_10
  (JNIEnv* env, jclass , jlong self, jint q_hist)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setQHist_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        (*me)->setQHist( (int)q_hist );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::DAISY::getQHist()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_DAISY_getQHist_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_DAISY_getQHist_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getQHist_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        return (*me)->getQHist();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::DAISY::setNorm(int norm)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setNorm_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setNorm_10
  (JNIEnv* env, jclass , jlong self, jint norm)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setNorm_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        (*me)->setNorm( (int)norm );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::DAISY::getNorm()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_DAISY_getNorm_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_DAISY_getNorm_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getNorm_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        return (*me)->getNorm();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::DAISY::setH(Mat H)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setH_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setH_10
  (JNIEnv* env, jclass , jlong self, jlong H_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setH_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        Mat& H = *((Mat*)H_nativeObj);
        (*me)->setH( H );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  Mat cv::xfeatures2d::DAISY::getH()
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_getH_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_DAISY_getH_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getH_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        cv::Mat _retval_ = (*me)->getH();
        return (jlong) new cv::Mat(_retval_);
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::DAISY::setInterpolation(bool interpolation)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setInterpolation_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setInterpolation_10
  (JNIEnv* env, jclass , jlong self, jboolean interpolation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setInterpolation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        (*me)->setInterpolation( (bool)interpolation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::DAISY::getInterpolation()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_DAISY_getInterpolation_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_DAISY_getInterpolation_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getInterpolation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        return (*me)->getInterpolation();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::DAISY::setUseOrientation(bool use_orientation)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setUseOrientation_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_setUseOrientation_10
  (JNIEnv* env, jclass , jlong self, jboolean use_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setUseOrientation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        (*me)->setUseOrientation( (bool)use_orientation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::DAISY::getUseOrientation()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_DAISY_getUseOrientation_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_DAISY_getUseOrientation_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getUseOrientation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        return (*me)->getUseOrientation();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::DAISY::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_DAISY_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_DAISY_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::DAISY>* me = (Ptr<cv::xfeatures2d::DAISY>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::DAISY>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_DAISY_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::DAISY>*) self;
}


//
// static Ptr_FREAK cv::xfeatures2d::FREAK::create(bool orientationNormalized = true, bool scaleNormalized = true, float patternScale = 22.0f, int nOctaves = 4, vector_int selectedPairs = std::vector<int>())
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_10 (JNIEnv*, jclass, jboolean, jboolean, jfloat, jint, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_10
  (JNIEnv* env, jclass , jboolean orientationNormalized, jboolean scaleNormalized, jfloat patternScale, jint nOctaves, jlong selectedPairs_mat_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        std::vector<int> selectedPairs;
        Mat& selectedPairs_mat = *((Mat*)selectedPairs_mat_nativeObj);
        Mat_to_vector_int( selectedPairs_mat, selectedPairs );
        typedef Ptr<cv::xfeatures2d::FREAK> Ptr_FREAK;
        Ptr_FREAK _retval_ = cv::xfeatures2d::FREAK::create( (bool)orientationNormalized, (bool)scaleNormalized, (float)patternScale, (int)nOctaves, selectedPairs );
        return (jlong)(new Ptr_FREAK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_11 (JNIEnv*, jclass, jboolean, jboolean, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_11
  (JNIEnv* env, jclass , jboolean orientationNormalized, jboolean scaleNormalized, jfloat patternScale, jint nOctaves)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::FREAK> Ptr_FREAK;
        Ptr_FREAK _retval_ = cv::xfeatures2d::FREAK::create( (bool)orientationNormalized, (bool)scaleNormalized, (float)patternScale, (int)nOctaves );
        return (jlong)(new Ptr_FREAK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_12 (JNIEnv*, jclass, jboolean, jboolean, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_12
  (JNIEnv* env, jclass , jboolean orientationNormalized, jboolean scaleNormalized, jfloat patternScale)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::FREAK> Ptr_FREAK;
        Ptr_FREAK _retval_ = cv::xfeatures2d::FREAK::create( (bool)orientationNormalized, (bool)scaleNormalized, (float)patternScale );
        return (jlong)(new Ptr_FREAK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_13 (JNIEnv*, jclass, jboolean, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_13
  (JNIEnv* env, jclass , jboolean orientationNormalized, jboolean scaleNormalized)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::FREAK> Ptr_FREAK;
        Ptr_FREAK _retval_ = cv::xfeatures2d::FREAK::create( (bool)orientationNormalized, (bool)scaleNormalized );
        return (jlong)(new Ptr_FREAK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_14 (JNIEnv*, jclass, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_14
  (JNIEnv* env, jclass , jboolean orientationNormalized)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::FREAK> Ptr_FREAK;
        Ptr_FREAK _retval_ = cv::xfeatures2d::FREAK::create( (bool)orientationNormalized );
        return (jlong)(new Ptr_FREAK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_15 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_FREAK_create_15
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::FREAK> Ptr_FREAK;
        Ptr_FREAK _retval_ = cv::xfeatures2d::FREAK::create();
        return (jlong)(new Ptr_FREAK(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::FREAK::setOrientationNormalized(bool orientationNormalized)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_FREAK_setOrientationNormalized_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_FREAK_setOrientationNormalized_10
  (JNIEnv* env, jclass , jlong self, jboolean orientationNormalized)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setOrientationNormalized_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::FREAK>* me = (Ptr<cv::xfeatures2d::FREAK>*) self; //TODO: check for NULL
        (*me)->setOrientationNormalized( (bool)orientationNormalized );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::FREAK::getOrientationNormalized()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_FREAK_getOrientationNormalized_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_FREAK_getOrientationNormalized_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getOrientationNormalized_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::FREAK>* me = (Ptr<cv::xfeatures2d::FREAK>*) self; //TODO: check for NULL
        return (*me)->getOrientationNormalized();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::FREAK::setScaleNormalized(bool scaleNormalized)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_FREAK_setScaleNormalized_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_FREAK_setScaleNormalized_10
  (JNIEnv* env, jclass , jlong self, jboolean scaleNormalized)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setScaleNormalized_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::FREAK>* me = (Ptr<cv::xfeatures2d::FREAK>*) self; //TODO: check for NULL
        (*me)->setScaleNormalized( (bool)scaleNormalized );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::FREAK::getScaleNormalized()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_FREAK_getScaleNormalized_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_FREAK_getScaleNormalized_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getScaleNormalized_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::FREAK>* me = (Ptr<cv::xfeatures2d::FREAK>*) self; //TODO: check for NULL
        return (*me)->getScaleNormalized();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::FREAK::setPatternScale(double patternScale)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_FREAK_setPatternScale_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_FREAK_setPatternScale_10
  (JNIEnv* env, jclass , jlong self, jdouble patternScale)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setPatternScale_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::FREAK>* me = (Ptr<cv::xfeatures2d::FREAK>*) self; //TODO: check for NULL
        (*me)->setPatternScale( (double)patternScale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  double cv::xfeatures2d::FREAK::getPatternScale()
//

JNIEXPORT jdouble JNICALL Java_org_opencv_xfeatures2d_FREAK_getPatternScale_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_xfeatures2d_FREAK_getPatternScale_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getPatternScale_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::FREAK>* me = (Ptr<cv::xfeatures2d::FREAK>*) self; //TODO: check for NULL
        return (*me)->getPatternScale();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::FREAK::setNOctaves(int nOctaves)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_FREAK_setNOctaves_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_FREAK_setNOctaves_10
  (JNIEnv* env, jclass , jlong self, jint nOctaves)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setNOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::FREAK>* me = (Ptr<cv::xfeatures2d::FREAK>*) self; //TODO: check for NULL
        (*me)->setNOctaves( (int)nOctaves );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::FREAK::getNOctaves()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_FREAK_getNOctaves_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_FREAK_getNOctaves_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getNOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::FREAK>* me = (Ptr<cv::xfeatures2d::FREAK>*) self; //TODO: check for NULL
        return (*me)->getNOctaves();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::FREAK::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_FREAK_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_FREAK_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::FREAK>* me = (Ptr<cv::xfeatures2d::FREAK>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::FREAK>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_FREAK_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_FREAK_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::FREAK>*) self;
}


//
// static Ptr_HarrisLaplaceFeatureDetector cv::xfeatures2d::HarrisLaplaceFeatureDetector::create(int numOctaves = 6, float corn_thresh = 0.01f, float DOG_thresh = 0.01f, int maxCorners = 5000, int num_layers = 4)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_10 (JNIEnv*, jclass, jint, jfloat, jfloat, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_10
  (JNIEnv* env, jclass , jint numOctaves, jfloat corn_thresh, jfloat DOG_thresh, jint maxCorners, jint num_layers)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector> Ptr_HarrisLaplaceFeatureDetector;
        Ptr_HarrisLaplaceFeatureDetector _retval_ = cv::xfeatures2d::HarrisLaplaceFeatureDetector::create( (int)numOctaves, (float)corn_thresh, (float)DOG_thresh, (int)maxCorners, (int)num_layers );
        return (jlong)(new Ptr_HarrisLaplaceFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_11 (JNIEnv*, jclass, jint, jfloat, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_11
  (JNIEnv* env, jclass , jint numOctaves, jfloat corn_thresh, jfloat DOG_thresh, jint maxCorners)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector> Ptr_HarrisLaplaceFeatureDetector;
        Ptr_HarrisLaplaceFeatureDetector _retval_ = cv::xfeatures2d::HarrisLaplaceFeatureDetector::create( (int)numOctaves, (float)corn_thresh, (float)DOG_thresh, (int)maxCorners );
        return (jlong)(new Ptr_HarrisLaplaceFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_12 (JNIEnv*, jclass, jint, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_12
  (JNIEnv* env, jclass , jint numOctaves, jfloat corn_thresh, jfloat DOG_thresh)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector> Ptr_HarrisLaplaceFeatureDetector;
        Ptr_HarrisLaplaceFeatureDetector _retval_ = cv::xfeatures2d::HarrisLaplaceFeatureDetector::create( (int)numOctaves, (float)corn_thresh, (float)DOG_thresh );
        return (jlong)(new Ptr_HarrisLaplaceFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_13 (JNIEnv*, jclass, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_13
  (JNIEnv* env, jclass , jint numOctaves, jfloat corn_thresh)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector> Ptr_HarrisLaplaceFeatureDetector;
        Ptr_HarrisLaplaceFeatureDetector _retval_ = cv::xfeatures2d::HarrisLaplaceFeatureDetector::create( (int)numOctaves, (float)corn_thresh );
        return (jlong)(new Ptr_HarrisLaplaceFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_14 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_14
  (JNIEnv* env, jclass , jint numOctaves)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector> Ptr_HarrisLaplaceFeatureDetector;
        Ptr_HarrisLaplaceFeatureDetector _retval_ = cv::xfeatures2d::HarrisLaplaceFeatureDetector::create( (int)numOctaves );
        return (jlong)(new Ptr_HarrisLaplaceFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_15 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_create_15
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector> Ptr_HarrisLaplaceFeatureDetector;
        Ptr_HarrisLaplaceFeatureDetector _retval_ = cv::xfeatures2d::HarrisLaplaceFeatureDetector::create();
        return (jlong)(new Ptr_HarrisLaplaceFeatureDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::HarrisLaplaceFeatureDetector::setNumOctaves(int numOctaves_)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_setNumOctaves_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_setNumOctaves_10
  (JNIEnv* env, jclass , jlong self, jint numOctaves_)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setNumOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setNumOctaves( (int)numOctaves_ );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::HarrisLaplaceFeatureDetector::getNumOctaves()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getNumOctaves_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getNumOctaves_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getNumOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getNumOctaves();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::HarrisLaplaceFeatureDetector::setCornThresh(float corn_thresh_)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_setCornThresh_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_setCornThresh_10
  (JNIEnv* env, jclass , jlong self, jfloat corn_thresh_)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setCornThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setCornThresh( (float)corn_thresh_ );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::HarrisLaplaceFeatureDetector::getCornThresh()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getCornThresh_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getCornThresh_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getCornThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getCornThresh();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::HarrisLaplaceFeatureDetector::setDOGThresh(float DOG_thresh_)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_setDOGThresh_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_setDOGThresh_10
  (JNIEnv* env, jclass , jlong self, jfloat DOG_thresh_)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setDOGThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setDOGThresh( (float)DOG_thresh_ );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::HarrisLaplaceFeatureDetector::getDOGThresh()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getDOGThresh_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getDOGThresh_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDOGThresh_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getDOGThresh();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::HarrisLaplaceFeatureDetector::setMaxCorners(int maxCorners_)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_setMaxCorners_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_setMaxCorners_10
  (JNIEnv* env, jclass , jlong self, jint maxCorners_)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setMaxCorners_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setMaxCorners( (int)maxCorners_ );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::HarrisLaplaceFeatureDetector::getMaxCorners()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getMaxCorners_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getMaxCorners_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getMaxCorners_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getMaxCorners();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::HarrisLaplaceFeatureDetector::setNumLayers(int num_layers_)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_setNumLayers_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_setNumLayers_10
  (JNIEnv* env, jclass , jlong self, jint num_layers_)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setNumLayers_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        (*me)->setNumLayers( (int)num_layers_ );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::HarrisLaplaceFeatureDetector::getNumLayers()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getNumLayers_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getNumLayers_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getNumLayers_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        return (*me)->getNumLayers();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::HarrisLaplaceFeatureDetector::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>* me = (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_HarrisLaplaceFeatureDetector_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>*) self;
}


//
// static Ptr_LATCH cv::xfeatures2d::LATCH::create(int bytes = 32, bool rotationInvariance = true, int half_ssd_size = 3, double sigma = 2.0)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LATCH_create_10 (JNIEnv*, jclass, jint, jboolean, jint, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LATCH_create_10
  (JNIEnv* env, jclass , jint bytes, jboolean rotationInvariance, jint half_ssd_size, jdouble sigma)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::LATCH> Ptr_LATCH;
        Ptr_LATCH _retval_ = cv::xfeatures2d::LATCH::create( (int)bytes, (bool)rotationInvariance, (int)half_ssd_size, (double)sigma );
        return (jlong)(new Ptr_LATCH(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LATCH_create_11 (JNIEnv*, jclass, jint, jboolean, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LATCH_create_11
  (JNIEnv* env, jclass , jint bytes, jboolean rotationInvariance, jint half_ssd_size)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::LATCH> Ptr_LATCH;
        Ptr_LATCH _retval_ = cv::xfeatures2d::LATCH::create( (int)bytes, (bool)rotationInvariance, (int)half_ssd_size );
        return (jlong)(new Ptr_LATCH(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LATCH_create_12 (JNIEnv*, jclass, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LATCH_create_12
  (JNIEnv* env, jclass , jint bytes, jboolean rotationInvariance)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::LATCH> Ptr_LATCH;
        Ptr_LATCH _retval_ = cv::xfeatures2d::LATCH::create( (int)bytes, (bool)rotationInvariance );
        return (jlong)(new Ptr_LATCH(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LATCH_create_13 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LATCH_create_13
  (JNIEnv* env, jclass , jint bytes)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::LATCH> Ptr_LATCH;
        Ptr_LATCH _retval_ = cv::xfeatures2d::LATCH::create( (int)bytes );
        return (jlong)(new Ptr_LATCH(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LATCH_create_14 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LATCH_create_14
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::LATCH> Ptr_LATCH;
        Ptr_LATCH _retval_ = cv::xfeatures2d::LATCH::create();
        return (jlong)(new Ptr_LATCH(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::LATCH::setBytes(int bytes)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LATCH_setBytes_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LATCH_setBytes_10
  (JNIEnv* env, jclass , jlong self, jint bytes)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setBytes_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LATCH>* me = (Ptr<cv::xfeatures2d::LATCH>*) self; //TODO: check for NULL
        (*me)->setBytes( (int)bytes );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::LATCH::getBytes()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_LATCH_getBytes_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_LATCH_getBytes_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getBytes_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LATCH>* me = (Ptr<cv::xfeatures2d::LATCH>*) self; //TODO: check for NULL
        return (*me)->getBytes();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::LATCH::setRotationInvariance(bool rotationInvariance)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LATCH_setRotationInvariance_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LATCH_setRotationInvariance_10
  (JNIEnv* env, jclass , jlong self, jboolean rotationInvariance)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setRotationInvariance_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LATCH>* me = (Ptr<cv::xfeatures2d::LATCH>*) self; //TODO: check for NULL
        (*me)->setRotationInvariance( (bool)rotationInvariance );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::LATCH::getRotationInvariance()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_LATCH_getRotationInvariance_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_LATCH_getRotationInvariance_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getRotationInvariance_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LATCH>* me = (Ptr<cv::xfeatures2d::LATCH>*) self; //TODO: check for NULL
        return (*me)->getRotationInvariance();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::LATCH::setHalfSSDsize(int half_ssd_size)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LATCH_setHalfSSDsize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LATCH_setHalfSSDsize_10
  (JNIEnv* env, jclass , jlong self, jint half_ssd_size)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setHalfSSDsize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LATCH>* me = (Ptr<cv::xfeatures2d::LATCH>*) self; //TODO: check for NULL
        (*me)->setHalfSSDsize( (int)half_ssd_size );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::LATCH::getHalfSSDsize()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_LATCH_getHalfSSDsize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_LATCH_getHalfSSDsize_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getHalfSSDsize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LATCH>* me = (Ptr<cv::xfeatures2d::LATCH>*) self; //TODO: check for NULL
        return (*me)->getHalfSSDsize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::LATCH::setSigma(double sigma)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LATCH_setSigma_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LATCH_setSigma_10
  (JNIEnv* env, jclass , jlong self, jdouble sigma)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setSigma_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LATCH>* me = (Ptr<cv::xfeatures2d::LATCH>*) self; //TODO: check for NULL
        (*me)->setSigma( (double)sigma );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  double cv::xfeatures2d::LATCH::getSigma()
//

JNIEXPORT jdouble JNICALL Java_org_opencv_xfeatures2d_LATCH_getSigma_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_xfeatures2d_LATCH_getSigma_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getSigma_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LATCH>* me = (Ptr<cv::xfeatures2d::LATCH>*) self; //TODO: check for NULL
        return (*me)->getSigma();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::LATCH::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_LATCH_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_LATCH_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LATCH>* me = (Ptr<cv::xfeatures2d::LATCH>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::LATCH>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LATCH_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LATCH_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::LATCH>*) self;
}


//
// static Ptr_LUCID cv::xfeatures2d::LUCID::create(int lucid_kernel = 1, int blur_kernel = 2)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LUCID_create_10 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LUCID_create_10
  (JNIEnv* env, jclass , jint lucid_kernel, jint blur_kernel)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::LUCID> Ptr_LUCID;
        Ptr_LUCID _retval_ = cv::xfeatures2d::LUCID::create( (int)lucid_kernel, (int)blur_kernel );
        return (jlong)(new Ptr_LUCID(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LUCID_create_11 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LUCID_create_11
  (JNIEnv* env, jclass , jint lucid_kernel)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::LUCID> Ptr_LUCID;
        Ptr_LUCID _retval_ = cv::xfeatures2d::LUCID::create( (int)lucid_kernel );
        return (jlong)(new Ptr_LUCID(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LUCID_create_12 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_LUCID_create_12
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::LUCID> Ptr_LUCID;
        Ptr_LUCID _retval_ = cv::xfeatures2d::LUCID::create();
        return (jlong)(new Ptr_LUCID(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::LUCID::setLucidKernel(int lucid_kernel)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LUCID_setLucidKernel_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LUCID_setLucidKernel_10
  (JNIEnv* env, jclass , jlong self, jint lucid_kernel)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setLucidKernel_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LUCID>* me = (Ptr<cv::xfeatures2d::LUCID>*) self; //TODO: check for NULL
        (*me)->setLucidKernel( (int)lucid_kernel );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::LUCID::getLucidKernel()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_LUCID_getLucidKernel_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_LUCID_getLucidKernel_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getLucidKernel_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LUCID>* me = (Ptr<cv::xfeatures2d::LUCID>*) self; //TODO: check for NULL
        return (*me)->getLucidKernel();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::LUCID::setBlurKernel(int blur_kernel)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LUCID_setBlurKernel_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LUCID_setBlurKernel_10
  (JNIEnv* env, jclass , jlong self, jint blur_kernel)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setBlurKernel_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LUCID>* me = (Ptr<cv::xfeatures2d::LUCID>*) self; //TODO: check for NULL
        (*me)->setBlurKernel( (int)blur_kernel );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::LUCID::getBlurKernel()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_LUCID_getBlurKernel_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_LUCID_getBlurKernel_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getBlurKernel_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LUCID>* me = (Ptr<cv::xfeatures2d::LUCID>*) self; //TODO: check for NULL
        return (*me)->getBlurKernel();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::LUCID::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_LUCID_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_LUCID_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::LUCID>* me = (Ptr<cv::xfeatures2d::LUCID>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::LUCID>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LUCID_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_LUCID_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::LUCID>*) self;
}


//
// static Ptr_MSDDetector cv::xfeatures2d::MSDDetector::create(int m_patch_radius = 3, int m_search_area_radius = 5, int m_nms_radius = 5, int m_nms_scale_radius = 0, float m_th_saliency = 250.0f, int m_kNN = 4, float m_scale_factor = 1.25f, int m_n_scales = -1, bool m_compute_orientation = false)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_10 (JNIEnv*, jclass, jint, jint, jint, jint, jfloat, jint, jfloat, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_10
  (JNIEnv* env, jclass , jint m_patch_radius, jint m_search_area_radius, jint m_nms_radius, jint m_nms_scale_radius, jfloat m_th_saliency, jint m_kNN, jfloat m_scale_factor, jint m_n_scales, jboolean m_compute_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::MSDDetector> Ptr_MSDDetector;
        Ptr_MSDDetector _retval_ = cv::xfeatures2d::MSDDetector::create( (int)m_patch_radius, (int)m_search_area_radius, (int)m_nms_radius, (int)m_nms_scale_radius, (float)m_th_saliency, (int)m_kNN, (float)m_scale_factor, (int)m_n_scales, (bool)m_compute_orientation );
        return (jlong)(new Ptr_MSDDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_11 (JNIEnv*, jclass, jint, jint, jint, jint, jfloat, jint, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_11
  (JNIEnv* env, jclass , jint m_patch_radius, jint m_search_area_radius, jint m_nms_radius, jint m_nms_scale_radius, jfloat m_th_saliency, jint m_kNN, jfloat m_scale_factor, jint m_n_scales)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::MSDDetector> Ptr_MSDDetector;
        Ptr_MSDDetector _retval_ = cv::xfeatures2d::MSDDetector::create( (int)m_patch_radius, (int)m_search_area_radius, (int)m_nms_radius, (int)m_nms_scale_radius, (float)m_th_saliency, (int)m_kNN, (float)m_scale_factor, (int)m_n_scales );
        return (jlong)(new Ptr_MSDDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_12 (JNIEnv*, jclass, jint, jint, jint, jint, jfloat, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_12
  (JNIEnv* env, jclass , jint m_patch_radius, jint m_search_area_radius, jint m_nms_radius, jint m_nms_scale_radius, jfloat m_th_saliency, jint m_kNN, jfloat m_scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::MSDDetector> Ptr_MSDDetector;
        Ptr_MSDDetector _retval_ = cv::xfeatures2d::MSDDetector::create( (int)m_patch_radius, (int)m_search_area_radius, (int)m_nms_radius, (int)m_nms_scale_radius, (float)m_th_saliency, (int)m_kNN, (float)m_scale_factor );
        return (jlong)(new Ptr_MSDDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_13 (JNIEnv*, jclass, jint, jint, jint, jint, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_13
  (JNIEnv* env, jclass , jint m_patch_radius, jint m_search_area_radius, jint m_nms_radius, jint m_nms_scale_radius, jfloat m_th_saliency, jint m_kNN)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::MSDDetector> Ptr_MSDDetector;
        Ptr_MSDDetector _retval_ = cv::xfeatures2d::MSDDetector::create( (int)m_patch_radius, (int)m_search_area_radius, (int)m_nms_radius, (int)m_nms_scale_radius, (float)m_th_saliency, (int)m_kNN );
        return (jlong)(new Ptr_MSDDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_14 (JNIEnv*, jclass, jint, jint, jint, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_14
  (JNIEnv* env, jclass , jint m_patch_radius, jint m_search_area_radius, jint m_nms_radius, jint m_nms_scale_radius, jfloat m_th_saliency)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::MSDDetector> Ptr_MSDDetector;
        Ptr_MSDDetector _retval_ = cv::xfeatures2d::MSDDetector::create( (int)m_patch_radius, (int)m_search_area_radius, (int)m_nms_radius, (int)m_nms_scale_radius, (float)m_th_saliency );
        return (jlong)(new Ptr_MSDDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_15 (JNIEnv*, jclass, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_15
  (JNIEnv* env, jclass , jint m_patch_radius, jint m_search_area_radius, jint m_nms_radius, jint m_nms_scale_radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::MSDDetector> Ptr_MSDDetector;
        Ptr_MSDDetector _retval_ = cv::xfeatures2d::MSDDetector::create( (int)m_patch_radius, (int)m_search_area_radius, (int)m_nms_radius, (int)m_nms_scale_radius );
        return (jlong)(new Ptr_MSDDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_16 (JNIEnv*, jclass, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_16
  (JNIEnv* env, jclass , jint m_patch_radius, jint m_search_area_radius, jint m_nms_radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::MSDDetector> Ptr_MSDDetector;
        Ptr_MSDDetector _retval_ = cv::xfeatures2d::MSDDetector::create( (int)m_patch_radius, (int)m_search_area_radius, (int)m_nms_radius );
        return (jlong)(new Ptr_MSDDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_17 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_17
  (JNIEnv* env, jclass , jint m_patch_radius, jint m_search_area_radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_17()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::MSDDetector> Ptr_MSDDetector;
        Ptr_MSDDetector _retval_ = cv::xfeatures2d::MSDDetector::create( (int)m_patch_radius, (int)m_search_area_radius );
        return (jlong)(new Ptr_MSDDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_18 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_18
  (JNIEnv* env, jclass , jint m_patch_radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_18()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::MSDDetector> Ptr_MSDDetector;
        Ptr_MSDDetector _retval_ = cv::xfeatures2d::MSDDetector::create( (int)m_patch_radius );
        return (jlong)(new Ptr_MSDDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_19 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_MSDDetector_create_19
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_19()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::MSDDetector> Ptr_MSDDetector;
        Ptr_MSDDetector _retval_ = cv::xfeatures2d::MSDDetector::create();
        return (jlong)(new Ptr_MSDDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::MSDDetector::setPatchRadius(int patch_radius)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setPatchRadius_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setPatchRadius_10
  (JNIEnv* env, jclass , jlong self, jint patch_radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setPatchRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        (*me)->setPatchRadius( (int)patch_radius );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::MSDDetector::getPatchRadius()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getPatchRadius_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getPatchRadius_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getPatchRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        return (*me)->getPatchRadius();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::MSDDetector::setSearchAreaRadius(int use_orientation)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setSearchAreaRadius_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setSearchAreaRadius_10
  (JNIEnv* env, jclass , jlong self, jint use_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setSearchAreaRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        (*me)->setSearchAreaRadius( (int)use_orientation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::MSDDetector::getSearchAreaRadius()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getSearchAreaRadius_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getSearchAreaRadius_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getSearchAreaRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        return (*me)->getSearchAreaRadius();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::MSDDetector::setNmsRadius(int nms_radius)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setNmsRadius_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setNmsRadius_10
  (JNIEnv* env, jclass , jlong self, jint nms_radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setNmsRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        (*me)->setNmsRadius( (int)nms_radius );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::MSDDetector::getNmsRadius()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getNmsRadius_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getNmsRadius_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getNmsRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        return (*me)->getNmsRadius();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::MSDDetector::setNmsScaleRadius(int nms_scale_radius)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setNmsScaleRadius_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setNmsScaleRadius_10
  (JNIEnv* env, jclass , jlong self, jint nms_scale_radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setNmsScaleRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        (*me)->setNmsScaleRadius( (int)nms_scale_radius );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::MSDDetector::getNmsScaleRadius()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getNmsScaleRadius_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getNmsScaleRadius_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getNmsScaleRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        return (*me)->getNmsScaleRadius();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::MSDDetector::setThSaliency(float th_saliency)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setThSaliency_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setThSaliency_10
  (JNIEnv* env, jclass , jlong self, jfloat th_saliency)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setThSaliency_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        (*me)->setThSaliency( (float)th_saliency );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::MSDDetector::getThSaliency()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getThSaliency_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getThSaliency_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getThSaliency_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        return (*me)->getThSaliency();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::MSDDetector::setKNN(int kNN)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setKNN_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setKNN_10
  (JNIEnv* env, jclass , jlong self, jint kNN)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setKNN_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        (*me)->setKNN( (int)kNN );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::MSDDetector::getKNN()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getKNN_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getKNN_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getKNN_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        return (*me)->getKNN();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::MSDDetector::setScaleFactor(float scale_factor)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setScaleFactor_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setScaleFactor_10
  (JNIEnv* env, jclass , jlong self, jfloat scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        (*me)->setScaleFactor( (float)scale_factor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::MSDDetector::getScaleFactor()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getScaleFactor_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getScaleFactor_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        return (*me)->getScaleFactor();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::MSDDetector::setNScales(int use_orientation)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setNScales_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setNScales_10
  (JNIEnv* env, jclass , jlong self, jint use_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setNScales_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        (*me)->setNScales( (int)use_orientation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::MSDDetector::getNScales()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getNScales_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getNScales_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getNScales_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        return (*me)->getNScales();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::MSDDetector::setComputeOrientation(bool compute_orientation)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setComputeOrientation_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_setComputeOrientation_10
  (JNIEnv* env, jclass , jlong self, jboolean compute_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setComputeOrientation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        (*me)->setComputeOrientation( (bool)compute_orientation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::MSDDetector::getComputeOrientation()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getComputeOrientation_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getComputeOrientation_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getComputeOrientation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        return (*me)->getComputeOrientation();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::MSDDetector::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_MSDDetector_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::MSDDetector>* me = (Ptr<cv::xfeatures2d::MSDDetector>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::MSDDetector>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_MSDDetector_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::MSDDetector>*) self;
}


//
// static Ptr_PCTSignatures cv::xfeatures2d::PCTSignatures::create(int initSampleCount = 2000, int initSeedCount = 400, int pointDistribution = 0)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_10 (JNIEnv*, jclass, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_10
  (JNIEnv* env, jclass , jint initSampleCount, jint initSeedCount, jint pointDistribution)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::PCTSignatures> Ptr_PCTSignatures;
        Ptr_PCTSignatures _retval_ = cv::xfeatures2d::PCTSignatures::create( (int)initSampleCount, (int)initSeedCount, (int)pointDistribution );
        return (jlong)(new Ptr_PCTSignatures(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_11 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_11
  (JNIEnv* env, jclass , jint initSampleCount, jint initSeedCount)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::PCTSignatures> Ptr_PCTSignatures;
        Ptr_PCTSignatures _retval_ = cv::xfeatures2d::PCTSignatures::create( (int)initSampleCount, (int)initSeedCount );
        return (jlong)(new Ptr_PCTSignatures(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_12 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_12
  (JNIEnv* env, jclass , jint initSampleCount)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::PCTSignatures> Ptr_PCTSignatures;
        Ptr_PCTSignatures _retval_ = cv::xfeatures2d::PCTSignatures::create( (int)initSampleCount );
        return (jlong)(new Ptr_PCTSignatures(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_13 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_13
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::PCTSignatures> Ptr_PCTSignatures;
        Ptr_PCTSignatures _retval_ = cv::xfeatures2d::PCTSignatures::create();
        return (jlong)(new Ptr_PCTSignatures(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_PCTSignatures cv::xfeatures2d::PCTSignatures::create(vector_Point2f initSamplingPoints, int initSeedCount)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_14 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_14
  (JNIEnv* env, jclass , jlong initSamplingPoints_mat_nativeObj, jint initSeedCount)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> initSamplingPoints;
        Mat& initSamplingPoints_mat = *((Mat*)initSamplingPoints_mat_nativeObj);
        Mat_to_vector_Point2f( initSamplingPoints_mat, initSamplingPoints );
        typedef Ptr<cv::xfeatures2d::PCTSignatures> Ptr_PCTSignatures;
        Ptr_PCTSignatures _retval_ = cv::xfeatures2d::PCTSignatures::create( initSamplingPoints, (int)initSeedCount );
        return (jlong)(new Ptr_PCTSignatures(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// static Ptr_PCTSignatures cv::xfeatures2d::PCTSignatures::create(vector_Point2f initSamplingPoints, vector_int initClusterSeedIndexes)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_15 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_create_15
  (JNIEnv* env, jclass , jlong initSamplingPoints_mat_nativeObj, jlong initClusterSeedIndexes_mat_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> initSamplingPoints;
        Mat& initSamplingPoints_mat = *((Mat*)initSamplingPoints_mat_nativeObj);
        Mat_to_vector_Point2f( initSamplingPoints_mat, initSamplingPoints );
        std::vector<int> initClusterSeedIndexes;
        Mat& initClusterSeedIndexes_mat = *((Mat*)initClusterSeedIndexes_mat_nativeObj);
        Mat_to_vector_int( initClusterSeedIndexes_mat, initClusterSeedIndexes );
        typedef Ptr<cv::xfeatures2d::PCTSignatures> Ptr_PCTSignatures;
        Ptr_PCTSignatures _retval_ = cv::xfeatures2d::PCTSignatures::create( initSamplingPoints, initClusterSeedIndexes );
        return (jlong)(new Ptr_PCTSignatures(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::computeSignature(Mat image, Mat& signature)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_computeSignature_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_computeSignature_10
  (JNIEnv* env, jclass , jlong self, jlong image_nativeObj, jlong signature_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::computeSignature_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        Mat& image = *((Mat*)image_nativeObj);
        Mat& signature = *((Mat*)signature_nativeObj);
        (*me)->computeSignature( image, signature );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::xfeatures2d::PCTSignatures::computeSignatures(vector_Mat images, vector_Mat signatures)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_computeSignatures_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_computeSignatures_10
  (JNIEnv* env, jclass , jlong self, jlong images_mat_nativeObj, jlong signatures_mat_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::computeSignatures_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> images;
        Mat& images_mat = *((Mat*)images_mat_nativeObj);
        Mat_to_vector_Mat( images_mat, images );
        std::vector<Mat> signatures;
        Mat& signatures_mat = *((Mat*)signatures_mat_nativeObj);
        Mat_to_vector_Mat( signatures_mat, signatures );
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->computeSignatures( images, signatures );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// static void cv::xfeatures2d::PCTSignatures::drawSignature(Mat source, Mat signature, Mat& result, float radiusToShorterSideRatio = 1.0 / 8, int borderThickness = 1)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_drawSignature_10 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_drawSignature_10
  (JNIEnv* env, jclass , jlong source_nativeObj, jlong signature_nativeObj, jlong result_nativeObj, jfloat radiusToShorterSideRatio, jint borderThickness)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::drawSignature_10()";
    try {
        LOGD("%s", method_name);
        Mat& source = *((Mat*)source_nativeObj);
        Mat& signature = *((Mat*)signature_nativeObj);
        Mat& result = *((Mat*)result_nativeObj);
        cv::xfeatures2d::PCTSignatures::drawSignature( source, signature, result, (float)radiusToShorterSideRatio, (int)borderThickness );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_drawSignature_11 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_drawSignature_11
  (JNIEnv* env, jclass , jlong source_nativeObj, jlong signature_nativeObj, jlong result_nativeObj, jfloat radiusToShorterSideRatio)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::drawSignature_11()";
    try {
        LOGD("%s", method_name);
        Mat& source = *((Mat*)source_nativeObj);
        Mat& signature = *((Mat*)signature_nativeObj);
        Mat& result = *((Mat*)result_nativeObj);
        cv::xfeatures2d::PCTSignatures::drawSignature( source, signature, result, (float)radiusToShorterSideRatio );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_drawSignature_12 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_drawSignature_12
  (JNIEnv* env, jclass , jlong source_nativeObj, jlong signature_nativeObj, jlong result_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::drawSignature_12()";
    try {
        LOGD("%s", method_name);
        Mat& source = *((Mat*)source_nativeObj);
        Mat& signature = *((Mat*)signature_nativeObj);
        Mat& result = *((Mat*)result_nativeObj);
        cv::xfeatures2d::PCTSignatures::drawSignature( source, signature, result );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// static void cv::xfeatures2d::PCTSignatures::generateInitPoints(vector_Point2f initPoints, int count, int pointDistribution)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_generateInitPoints_10 (JNIEnv*, jclass, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_generateInitPoints_10
  (JNIEnv* env, jclass , jlong initPoints_mat_nativeObj, jint count, jint pointDistribution)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::generateInitPoints_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> initPoints;
        Mat& initPoints_mat = *((Mat*)initPoints_mat_nativeObj);
        Mat_to_vector_Point2f( initPoints_mat, initPoints );
        cv::xfeatures2d::PCTSignatures::generateInitPoints( initPoints, (int)count, (int)pointDistribution );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::PCTSignatures::getSampleCount()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getSampleCount_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getSampleCount_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getSampleCount_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getSampleCount();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::xfeatures2d::PCTSignatures::getGrayscaleBits()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getGrayscaleBits_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getGrayscaleBits_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getGrayscaleBits_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getGrayscaleBits();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setGrayscaleBits(int grayscaleBits)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setGrayscaleBits_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setGrayscaleBits_10
  (JNIEnv* env, jclass , jlong self, jint grayscaleBits)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setGrayscaleBits_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setGrayscaleBits( (int)grayscaleBits );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::PCTSignatures::getWindowRadius()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWindowRadius_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWindowRadius_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getWindowRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getWindowRadius();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setWindowRadius(int radius)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWindowRadius_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWindowRadius_10
  (JNIEnv* env, jclass , jlong self, jint radius)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setWindowRadius_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setWindowRadius( (int)radius );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::PCTSignatures::getWeightX()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightX_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightX_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getWeightX_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getWeightX();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setWeightX(float weight)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightX_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightX_10
  (JNIEnv* env, jclass , jlong self, jfloat weight)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setWeightX_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setWeightX( (float)weight );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::PCTSignatures::getWeightY()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightY_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightY_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getWeightY_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getWeightY();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setWeightY(float weight)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightY_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightY_10
  (JNIEnv* env, jclass , jlong self, jfloat weight)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setWeightY_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setWeightY( (float)weight );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::PCTSignatures::getWeightL()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightL_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightL_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getWeightL_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getWeightL();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setWeightL(float weight)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightL_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightL_10
  (JNIEnv* env, jclass , jlong self, jfloat weight)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setWeightL_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setWeightL( (float)weight );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::PCTSignatures::getWeightA()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightA_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightA_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getWeightA_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getWeightA();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setWeightA(float weight)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightA_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightA_10
  (JNIEnv* env, jclass , jlong self, jfloat weight)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setWeightA_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setWeightA( (float)weight );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::PCTSignatures::getWeightB()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightB_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightB_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getWeightB_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getWeightB();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setWeightB(float weight)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightB_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightB_10
  (JNIEnv* env, jclass , jlong self, jfloat weight)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setWeightB_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setWeightB( (float)weight );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::PCTSignatures::getWeightContrast()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightContrast_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightContrast_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getWeightContrast_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getWeightContrast();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setWeightContrast(float weight)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightContrast_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightContrast_10
  (JNIEnv* env, jclass , jlong self, jfloat weight)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setWeightContrast_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setWeightContrast( (float)weight );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::PCTSignatures::getWeightEntropy()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightEntropy_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getWeightEntropy_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getWeightEntropy_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getWeightEntropy();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setWeightEntropy(float weight)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightEntropy_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeightEntropy_10
  (JNIEnv* env, jclass , jlong self, jfloat weight)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setWeightEntropy_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setWeightEntropy( (float)weight );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  vector_Point2f cv::xfeatures2d::PCTSignatures::getSamplingPoints()
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getSamplingPoints_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getSamplingPoints_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getSamplingPoints_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        std::vector<Point2f> _ret_val_vector_ = (*me)->getSamplingPoints();
        Mat* _retval_ = new Mat();
        vector_Point2f_to_Mat(_ret_val_vector_, *_retval_);
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setWeight(int idx, float value)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeight_10 (JNIEnv*, jclass, jlong, jint, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeight_10
  (JNIEnv* env, jclass , jlong self, jint idx, jfloat value)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setWeight_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setWeight( (int)idx, (float)value );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::xfeatures2d::PCTSignatures::setWeights(vector_float weights)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeights_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setWeights_10
  (JNIEnv* env, jclass , jlong self, jlong weights_mat_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setWeights_10()";
    try {
        LOGD("%s", method_name);
        std::vector<float> weights;
        Mat& weights_mat = *((Mat*)weights_mat_nativeObj);
        Mat_to_vector_float( weights_mat, weights );
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setWeights( weights );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::xfeatures2d::PCTSignatures::setTranslation(int idx, float value)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setTranslation_10 (JNIEnv*, jclass, jlong, jint, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setTranslation_10
  (JNIEnv* env, jclass , jlong self, jint idx, jfloat value)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setTranslation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setTranslation( (int)idx, (float)value );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::xfeatures2d::PCTSignatures::setTranslations(vector_float translations)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setTranslations_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setTranslations_10
  (JNIEnv* env, jclass , jlong self, jlong translations_mat_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setTranslations_10()";
    try {
        LOGD("%s", method_name);
        std::vector<float> translations;
        Mat& translations_mat = *((Mat*)translations_mat_nativeObj);
        Mat_to_vector_float( translations_mat, translations );
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setTranslations( translations );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::xfeatures2d::PCTSignatures::setSamplingPoints(vector_Point2f samplingPoints)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setSamplingPoints_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setSamplingPoints_10
  (JNIEnv* env, jclass , jlong self, jlong samplingPoints_mat_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setSamplingPoints_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Point2f> samplingPoints;
        Mat& samplingPoints_mat = *((Mat*)samplingPoints_mat_nativeObj);
        Mat_to_vector_Point2f( samplingPoints_mat, samplingPoints );
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setSamplingPoints( samplingPoints );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  vector_int cv::xfeatures2d::PCTSignatures::getInitSeedIndexes()
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getInitSeedIndexes_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getInitSeedIndexes_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getInitSeedIndexes_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        std::vector<int> _ret_val_vector_ = (*me)->getInitSeedIndexes();
        Mat* _retval_ = new Mat();
        vector_int_to_Mat(_ret_val_vector_, *_retval_);
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setInitSeedIndexes(vector_int initSeedIndexes)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setInitSeedIndexes_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setInitSeedIndexes_10
  (JNIEnv* env, jclass , jlong self, jlong initSeedIndexes_mat_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setInitSeedIndexes_10()";
    try {
        LOGD("%s", method_name);
        std::vector<int> initSeedIndexes;
        Mat& initSeedIndexes_mat = *((Mat*)initSeedIndexes_mat_nativeObj);
        Mat_to_vector_int( initSeedIndexes_mat, initSeedIndexes );
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setInitSeedIndexes( initSeedIndexes );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::PCTSignatures::getInitSeedCount()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getInitSeedCount_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getInitSeedCount_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getInitSeedCount_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getInitSeedCount();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::xfeatures2d::PCTSignatures::getIterationCount()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getIterationCount_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getIterationCount_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getIterationCount_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getIterationCount();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setIterationCount(int iterationCount)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setIterationCount_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setIterationCount_10
  (JNIEnv* env, jclass , jlong self, jint iterationCount)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setIterationCount_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setIterationCount( (int)iterationCount );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::PCTSignatures::getMaxClustersCount()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getMaxClustersCount_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getMaxClustersCount_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getMaxClustersCount_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getMaxClustersCount();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setMaxClustersCount(int maxClustersCount)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setMaxClustersCount_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setMaxClustersCount_10
  (JNIEnv* env, jclass , jlong self, jint maxClustersCount)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setMaxClustersCount_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setMaxClustersCount( (int)maxClustersCount );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::PCTSignatures::getClusterMinSize()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getClusterMinSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getClusterMinSize_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getClusterMinSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getClusterMinSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setClusterMinSize(int clusterMinSize)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setClusterMinSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setClusterMinSize_10
  (JNIEnv* env, jclass , jlong self, jint clusterMinSize)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setClusterMinSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setClusterMinSize( (int)clusterMinSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::PCTSignatures::getJoiningDistance()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getJoiningDistance_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getJoiningDistance_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getJoiningDistance_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getJoiningDistance();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setJoiningDistance(float joiningDistance)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setJoiningDistance_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setJoiningDistance_10
  (JNIEnv* env, jclass , jlong self, jfloat joiningDistance)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setJoiningDistance_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setJoiningDistance( (float)joiningDistance );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::PCTSignatures::getDropThreshold()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getDropThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getDropThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDropThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getDropThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setDropThreshold(float dropThreshold)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setDropThreshold_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setDropThreshold_10
  (JNIEnv* env, jclass , jlong self, jfloat dropThreshold)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setDropThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setDropThreshold( (float)dropThreshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::PCTSignatures::getDistanceFunction()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getDistanceFunction_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_getDistanceFunction_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDistanceFunction_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        return (*me)->getDistanceFunction();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignatures::setDistanceFunction(int distanceFunction)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setDistanceFunction_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_setDistanceFunction_10
  (JNIEnv* env, jclass , jlong self, jint distanceFunction)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setDistanceFunction_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignatures>* me = (Ptr<cv::xfeatures2d::PCTSignatures>*) self; //TODO: check for NULL
        (*me)->setDistanceFunction( (int)distanceFunction );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::PCTSignatures>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignatures_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::PCTSignatures>*) self;
}


//
// static Ptr_PCTSignaturesSQFD cv::xfeatures2d::PCTSignaturesSQFD::create(int distanceFunction = 3, int similarityFunction = 2, float similarityParameter = 1.0f)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_create_10 (JNIEnv*, jclass, jint, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_create_10
  (JNIEnv* env, jclass , jint distanceFunction, jint similarityFunction, jfloat similarityParameter)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::PCTSignaturesSQFD> Ptr_PCTSignaturesSQFD;
        Ptr_PCTSignaturesSQFD _retval_ = cv::xfeatures2d::PCTSignaturesSQFD::create( (int)distanceFunction, (int)similarityFunction, (float)similarityParameter );
        return (jlong)(new Ptr_PCTSignaturesSQFD(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_create_11 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_create_11
  (JNIEnv* env, jclass , jint distanceFunction, jint similarityFunction)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::PCTSignaturesSQFD> Ptr_PCTSignaturesSQFD;
        Ptr_PCTSignaturesSQFD _retval_ = cv::xfeatures2d::PCTSignaturesSQFD::create( (int)distanceFunction, (int)similarityFunction );
        return (jlong)(new Ptr_PCTSignaturesSQFD(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_create_12 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_create_12
  (JNIEnv* env, jclass , jint distanceFunction)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::PCTSignaturesSQFD> Ptr_PCTSignaturesSQFD;
        Ptr_PCTSignaturesSQFD _retval_ = cv::xfeatures2d::PCTSignaturesSQFD::create( (int)distanceFunction );
        return (jlong)(new Ptr_PCTSignaturesSQFD(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_create_13 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_create_13
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::PCTSignaturesSQFD> Ptr_PCTSignaturesSQFD;
        Ptr_PCTSignaturesSQFD _retval_ = cv::xfeatures2d::PCTSignaturesSQFD::create();
        return (jlong)(new Ptr_PCTSignaturesSQFD(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  float cv::xfeatures2d::PCTSignaturesSQFD::computeQuadraticFormDistance(Mat _signature0, Mat _signature1)
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_computeQuadraticFormDistance_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_computeQuadraticFormDistance_10
  (JNIEnv* env, jclass , jlong self, jlong _signature0_nativeObj, jlong _signature1_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::computeQuadraticFormDistance_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::PCTSignaturesSQFD>* me = (Ptr<cv::xfeatures2d::PCTSignaturesSQFD>*) self; //TODO: check for NULL
        Mat& _signature0 = *((Mat*)_signature0_nativeObj);
        Mat& _signature1 = *((Mat*)_signature1_nativeObj);
        return (*me)->computeQuadraticFormDistance( _signature0, _signature1 );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::PCTSignaturesSQFD::computeQuadraticFormDistances(Mat sourceSignature, vector_Mat imageSignatures, vector_float distances)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_computeQuadraticFormDistances_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_computeQuadraticFormDistances_10
  (JNIEnv* env, jclass , jlong self, jlong sourceSignature_nativeObj, jlong imageSignatures_mat_nativeObj, jlong distances_mat_nativeObj)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::computeQuadraticFormDistances_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> imageSignatures;
        Mat& imageSignatures_mat = *((Mat*)imageSignatures_mat_nativeObj);
        Mat_to_vector_Mat( imageSignatures_mat, imageSignatures );
        std::vector<float> distances;
        Mat& distances_mat = *((Mat*)distances_mat_nativeObj);
        Mat_to_vector_float( distances_mat, distances );
        Ptr<cv::xfeatures2d::PCTSignaturesSQFD>* me = (Ptr<cv::xfeatures2d::PCTSignaturesSQFD>*) self; //TODO: check for NULL
        Mat& sourceSignature = *((Mat*)sourceSignature_nativeObj);
        (*me)->computeQuadraticFormDistances( sourceSignature, imageSignatures, distances );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::PCTSignaturesSQFD>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_PCTSignaturesSQFD_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::PCTSignaturesSQFD>*) self;
}


//
// static Ptr_SURF cv::xfeatures2d::SURF::create(double hessianThreshold = 100, int nOctaves = 4, int nOctaveLayers = 3, bool extended = false, bool upright = false)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_10 (JNIEnv*, jclass, jdouble, jint, jint, jboolean, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_10
  (JNIEnv* env, jclass , jdouble hessianThreshold, jint nOctaves, jint nOctaveLayers, jboolean extended, jboolean upright)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::SURF> Ptr_SURF;
        Ptr_SURF _retval_ = cv::xfeatures2d::SURF::create( (double)hessianThreshold, (int)nOctaves, (int)nOctaveLayers, (bool)extended, (bool)upright );
        return (jlong)(new Ptr_SURF(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_11 (JNIEnv*, jclass, jdouble, jint, jint, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_11
  (JNIEnv* env, jclass , jdouble hessianThreshold, jint nOctaves, jint nOctaveLayers, jboolean extended)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::SURF> Ptr_SURF;
        Ptr_SURF _retval_ = cv::xfeatures2d::SURF::create( (double)hessianThreshold, (int)nOctaves, (int)nOctaveLayers, (bool)extended );
        return (jlong)(new Ptr_SURF(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_12 (JNIEnv*, jclass, jdouble, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_12
  (JNIEnv* env, jclass , jdouble hessianThreshold, jint nOctaves, jint nOctaveLayers)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::SURF> Ptr_SURF;
        Ptr_SURF _retval_ = cv::xfeatures2d::SURF::create( (double)hessianThreshold, (int)nOctaves, (int)nOctaveLayers );
        return (jlong)(new Ptr_SURF(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_13 (JNIEnv*, jclass, jdouble, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_13
  (JNIEnv* env, jclass , jdouble hessianThreshold, jint nOctaves)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::SURF> Ptr_SURF;
        Ptr_SURF _retval_ = cv::xfeatures2d::SURF::create( (double)hessianThreshold, (int)nOctaves );
        return (jlong)(new Ptr_SURF(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_14 (JNIEnv*, jclass, jdouble);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_14
  (JNIEnv* env, jclass , jdouble hessianThreshold)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::SURF> Ptr_SURF;
        Ptr_SURF _retval_ = cv::xfeatures2d::SURF::create( (double)hessianThreshold );
        return (jlong)(new Ptr_SURF(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_15 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_SURF_create_15
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::SURF> Ptr_SURF;
        Ptr_SURF _retval_ = cv::xfeatures2d::SURF::create();
        return (jlong)(new Ptr_SURF(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::SURF::setHessianThreshold(double hessianThreshold)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_setHessianThreshold_10 (JNIEnv*, jclass, jlong, jdouble);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_setHessianThreshold_10
  (JNIEnv* env, jclass , jlong self, jdouble hessianThreshold)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setHessianThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        (*me)->setHessianThreshold( (double)hessianThreshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  double cv::xfeatures2d::SURF::getHessianThreshold()
//

JNIEXPORT jdouble JNICALL Java_org_opencv_xfeatures2d_SURF_getHessianThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_xfeatures2d_SURF_getHessianThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getHessianThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        return (*me)->getHessianThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::SURF::setNOctaves(int nOctaves)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_setNOctaves_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_setNOctaves_10
  (JNIEnv* env, jclass , jlong self, jint nOctaves)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setNOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        (*me)->setNOctaves( (int)nOctaves );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::SURF::getNOctaves()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_getNOctaves_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_getNOctaves_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getNOctaves_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        return (*me)->getNOctaves();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::SURF::setNOctaveLayers(int nOctaveLayers)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_setNOctaveLayers_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_setNOctaveLayers_10
  (JNIEnv* env, jclass , jlong self, jint nOctaveLayers)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setNOctaveLayers_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        (*me)->setNOctaveLayers( (int)nOctaveLayers );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::SURF::getNOctaveLayers()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_getNOctaveLayers_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_SURF_getNOctaveLayers_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getNOctaveLayers_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        return (*me)->getNOctaveLayers();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::SURF::setExtended(bool extended)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_setExtended_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_setExtended_10
  (JNIEnv* env, jclass , jlong self, jboolean extended)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setExtended_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        (*me)->setExtended( (bool)extended );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::SURF::getExtended()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_SURF_getExtended_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_SURF_getExtended_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getExtended_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        return (*me)->getExtended();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::SURF::setUpright(bool upright)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_setUpright_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_setUpright_10
  (JNIEnv* env, jclass , jlong self, jboolean upright)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setUpright_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        (*me)->setUpright( (bool)upright );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::SURF::getUpright()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_SURF_getUpright_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_SURF_getUpright_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getUpright_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        return (*me)->getUpright();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::SURF::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_SURF_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_SURF_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::SURF>* me = (Ptr<cv::xfeatures2d::SURF>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::SURF>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_SURF_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::SURF>*) self;
}


//
// static Ptr_StarDetector cv::xfeatures2d::StarDetector::create(int maxSize = 45, int responseThreshold = 30, int lineThresholdProjected = 10, int lineThresholdBinarized = 8, int suppressNonmaxSize = 5)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_10 (JNIEnv*, jclass, jint, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_10
  (JNIEnv* env, jclass , jint maxSize, jint responseThreshold, jint lineThresholdProjected, jint lineThresholdBinarized, jint suppressNonmaxSize)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::StarDetector> Ptr_StarDetector;
        Ptr_StarDetector _retval_ = cv::xfeatures2d::StarDetector::create( (int)maxSize, (int)responseThreshold, (int)lineThresholdProjected, (int)lineThresholdBinarized, (int)suppressNonmaxSize );
        return (jlong)(new Ptr_StarDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_11 (JNIEnv*, jclass, jint, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_11
  (JNIEnv* env, jclass , jint maxSize, jint responseThreshold, jint lineThresholdProjected, jint lineThresholdBinarized)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::StarDetector> Ptr_StarDetector;
        Ptr_StarDetector _retval_ = cv::xfeatures2d::StarDetector::create( (int)maxSize, (int)responseThreshold, (int)lineThresholdProjected, (int)lineThresholdBinarized );
        return (jlong)(new Ptr_StarDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_12 (JNIEnv*, jclass, jint, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_12
  (JNIEnv* env, jclass , jint maxSize, jint responseThreshold, jint lineThresholdProjected)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::StarDetector> Ptr_StarDetector;
        Ptr_StarDetector _retval_ = cv::xfeatures2d::StarDetector::create( (int)maxSize, (int)responseThreshold, (int)lineThresholdProjected );
        return (jlong)(new Ptr_StarDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_13 (JNIEnv*, jclass, jint, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_13
  (JNIEnv* env, jclass , jint maxSize, jint responseThreshold)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::StarDetector> Ptr_StarDetector;
        Ptr_StarDetector _retval_ = cv::xfeatures2d::StarDetector::create( (int)maxSize, (int)responseThreshold );
        return (jlong)(new Ptr_StarDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_14 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_14
  (JNIEnv* env, jclass , jint maxSize)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::StarDetector> Ptr_StarDetector;
        Ptr_StarDetector _retval_ = cv::xfeatures2d::StarDetector::create( (int)maxSize );
        return (jlong)(new Ptr_StarDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_15 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_StarDetector_create_15
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::StarDetector> Ptr_StarDetector;
        Ptr_StarDetector _retval_ = cv::xfeatures2d::StarDetector::create();
        return (jlong)(new Ptr_StarDetector(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::StarDetector::setMaxSize(int _maxSize)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_setMaxSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_setMaxSize_10
  (JNIEnv* env, jclass , jlong self, jint _maxSize)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setMaxSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        (*me)->setMaxSize( (int)_maxSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::StarDetector::getMaxSize()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_StarDetector_getMaxSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_StarDetector_getMaxSize_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getMaxSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        return (*me)->getMaxSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::StarDetector::setResponseThreshold(int _responseThreshold)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_setResponseThreshold_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_setResponseThreshold_10
  (JNIEnv* env, jclass , jlong self, jint _responseThreshold)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setResponseThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        (*me)->setResponseThreshold( (int)_responseThreshold );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::StarDetector::getResponseThreshold()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_StarDetector_getResponseThreshold_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_StarDetector_getResponseThreshold_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getResponseThreshold_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        return (*me)->getResponseThreshold();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::StarDetector::setLineThresholdProjected(int _lineThresholdProjected)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_setLineThresholdProjected_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_setLineThresholdProjected_10
  (JNIEnv* env, jclass , jlong self, jint _lineThresholdProjected)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setLineThresholdProjected_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        (*me)->setLineThresholdProjected( (int)_lineThresholdProjected );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::StarDetector::getLineThresholdProjected()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_StarDetector_getLineThresholdProjected_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_StarDetector_getLineThresholdProjected_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getLineThresholdProjected_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        return (*me)->getLineThresholdProjected();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::StarDetector::setLineThresholdBinarized(int _lineThresholdBinarized)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_setLineThresholdBinarized_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_setLineThresholdBinarized_10
  (JNIEnv* env, jclass , jlong self, jint _lineThresholdBinarized)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setLineThresholdBinarized_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        (*me)->setLineThresholdBinarized( (int)_lineThresholdBinarized );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::StarDetector::getLineThresholdBinarized()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_StarDetector_getLineThresholdBinarized_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_StarDetector_getLineThresholdBinarized_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getLineThresholdBinarized_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        return (*me)->getLineThresholdBinarized();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::StarDetector::setSuppressNonmaxSize(int _suppressNonmaxSize)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_setSuppressNonmaxSize_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_setSuppressNonmaxSize_10
  (JNIEnv* env, jclass , jlong self, jint _suppressNonmaxSize)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setSuppressNonmaxSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        (*me)->setSuppressNonmaxSize( (int)_suppressNonmaxSize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::StarDetector::getSuppressNonmaxSize()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_StarDetector_getSuppressNonmaxSize_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_StarDetector_getSuppressNonmaxSize_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getSuppressNonmaxSize_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        return (*me)->getSuppressNonmaxSize();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::StarDetector::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_StarDetector_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_StarDetector_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::StarDetector>* me = (Ptr<cv::xfeatures2d::StarDetector>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::StarDetector>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_StarDetector_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::StarDetector>*) self;
}


//
// static Ptr_TBMR cv::xfeatures2d::TBMR::create(int min_area = 60, float max_area_relative = 0.01f, float scale_factor = 1.25f, int n_scales = -1)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TBMR_create_10 (JNIEnv*, jclass, jint, jfloat, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TBMR_create_10
  (JNIEnv* env, jclass , jint min_area, jfloat max_area_relative, jfloat scale_factor, jint n_scales)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::TBMR> Ptr_TBMR;
        Ptr_TBMR _retval_ = cv::xfeatures2d::TBMR::create( (int)min_area, (float)max_area_relative, (float)scale_factor, (int)n_scales );
        return (jlong)(new Ptr_TBMR(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TBMR_create_11 (JNIEnv*, jclass, jint, jfloat, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TBMR_create_11
  (JNIEnv* env, jclass , jint min_area, jfloat max_area_relative, jfloat scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::TBMR> Ptr_TBMR;
        Ptr_TBMR _retval_ = cv::xfeatures2d::TBMR::create( (int)min_area, (float)max_area_relative, (float)scale_factor );
        return (jlong)(new Ptr_TBMR(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TBMR_create_12 (JNIEnv*, jclass, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TBMR_create_12
  (JNIEnv* env, jclass , jint min_area, jfloat max_area_relative)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::TBMR> Ptr_TBMR;
        Ptr_TBMR _retval_ = cv::xfeatures2d::TBMR::create( (int)min_area, (float)max_area_relative );
        return (jlong)(new Ptr_TBMR(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TBMR_create_13 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TBMR_create_13
  (JNIEnv* env, jclass , jint min_area)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::TBMR> Ptr_TBMR;
        Ptr_TBMR _retval_ = cv::xfeatures2d::TBMR::create( (int)min_area );
        return (jlong)(new Ptr_TBMR(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TBMR_create_14 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TBMR_create_14
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::TBMR> Ptr_TBMR;
        Ptr_TBMR _retval_ = cv::xfeatures2d::TBMR::create();
        return (jlong)(new Ptr_TBMR(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::TBMR::setMinArea(int minArea)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TBMR_setMinArea_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TBMR_setMinArea_10
  (JNIEnv* env, jclass , jlong self, jint minArea)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setMinArea_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::TBMR>* me = (Ptr<cv::xfeatures2d::TBMR>*) self; //TODO: check for NULL
        (*me)->setMinArea( (int)minArea );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::TBMR::getMinArea()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_TBMR_getMinArea_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_TBMR_getMinArea_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getMinArea_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::TBMR>* me = (Ptr<cv::xfeatures2d::TBMR>*) self; //TODO: check for NULL
        return (*me)->getMinArea();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::TBMR::setMaxAreaRelative(float maxArea)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TBMR_setMaxAreaRelative_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TBMR_setMaxAreaRelative_10
  (JNIEnv* env, jclass , jlong self, jfloat maxArea)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setMaxAreaRelative_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::TBMR>* me = (Ptr<cv::xfeatures2d::TBMR>*) self; //TODO: check for NULL
        (*me)->setMaxAreaRelative( (float)maxArea );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::TBMR::getMaxAreaRelative()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_TBMR_getMaxAreaRelative_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_TBMR_getMaxAreaRelative_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getMaxAreaRelative_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::TBMR>* me = (Ptr<cv::xfeatures2d::TBMR>*) self; //TODO: check for NULL
        return (*me)->getMaxAreaRelative();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::TBMR::setScaleFactor(float scale_factor)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TBMR_setScaleFactor_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TBMR_setScaleFactor_10
  (JNIEnv* env, jclass , jlong self, jfloat scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::TBMR>* me = (Ptr<cv::xfeatures2d::TBMR>*) self; //TODO: check for NULL
        (*me)->setScaleFactor( (float)scale_factor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::TBMR::getScaleFactor()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_TBMR_getScaleFactor_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_TBMR_getScaleFactor_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::TBMR>* me = (Ptr<cv::xfeatures2d::TBMR>*) self; //TODO: check for NULL
        return (*me)->getScaleFactor();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::TBMR::setNScales(int n_scales)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TBMR_setNScales_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TBMR_setNScales_10
  (JNIEnv* env, jclass , jlong self, jint n_scales)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setNScales_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::TBMR>* me = (Ptr<cv::xfeatures2d::TBMR>*) self; //TODO: check for NULL
        (*me)->setNScales( (int)n_scales );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::xfeatures2d::TBMR::getNScales()
//

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_TBMR_getNScales_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_xfeatures2d_TBMR_getNScales_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getNScales_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::TBMR>* me = (Ptr<cv::xfeatures2d::TBMR>*) self; //TODO: check for NULL
        return (*me)->getNScales();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::TBMR>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TBMR_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TBMR_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::TBMR>*) self;
}


//
// static Ptr_TEBLID cv::xfeatures2d::TEBLID::create(float scale_factor, int n_bits = TEBLID::SIZE_256_BITS)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TEBLID_create_10 (JNIEnv*, jclass, jfloat, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TEBLID_create_10
  (JNIEnv* env, jclass , jfloat scale_factor, jint n_bits)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::TEBLID> Ptr_TEBLID;
        Ptr_TEBLID _retval_ = cv::xfeatures2d::TEBLID::create( (float)scale_factor, (int)n_bits );
        return (jlong)(new Ptr_TEBLID(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TEBLID_create_11 (JNIEnv*, jclass, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_TEBLID_create_11
  (JNIEnv* env, jclass , jfloat scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::TEBLID> Ptr_TEBLID;
        Ptr_TEBLID _retval_ = cv::xfeatures2d::TEBLID::create( (float)scale_factor );
        return (jlong)(new Ptr_TEBLID(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::TEBLID::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_TEBLID_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_TEBLID_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::TEBLID>* me = (Ptr<cv::xfeatures2d::TEBLID>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::TEBLID>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TEBLID_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_TEBLID_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::TEBLID>*) self;
}


//
// static Ptr_VGG cv::xfeatures2d::VGG::create(int desc = VGG::VGG_120, float isigma = 1.4f, bool img_normalize = true, bool use_scale_orientation = true, float scale_factor = 6.25f, bool dsc_normalize = false)
//

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_10 (JNIEnv*, jclass, jint, jfloat, jboolean, jboolean, jfloat, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_10
  (JNIEnv* env, jclass , jint desc, jfloat isigma, jboolean img_normalize, jboolean use_scale_orientation, jfloat scale_factor, jboolean dsc_normalize)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::VGG> Ptr_VGG;
        Ptr_VGG _retval_ = cv::xfeatures2d::VGG::create( (int)desc, (float)isigma, (bool)img_normalize, (bool)use_scale_orientation, (float)scale_factor, (bool)dsc_normalize );
        return (jlong)(new Ptr_VGG(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_11 (JNIEnv*, jclass, jint, jfloat, jboolean, jboolean, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_11
  (JNIEnv* env, jclass , jint desc, jfloat isigma, jboolean img_normalize, jboolean use_scale_orientation, jfloat scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_11()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::VGG> Ptr_VGG;
        Ptr_VGG _retval_ = cv::xfeatures2d::VGG::create( (int)desc, (float)isigma, (bool)img_normalize, (bool)use_scale_orientation, (float)scale_factor );
        return (jlong)(new Ptr_VGG(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_12 (JNIEnv*, jclass, jint, jfloat, jboolean, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_12
  (JNIEnv* env, jclass , jint desc, jfloat isigma, jboolean img_normalize, jboolean use_scale_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_12()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::VGG> Ptr_VGG;
        Ptr_VGG _retval_ = cv::xfeatures2d::VGG::create( (int)desc, (float)isigma, (bool)img_normalize, (bool)use_scale_orientation );
        return (jlong)(new Ptr_VGG(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_13 (JNIEnv*, jclass, jint, jfloat, jboolean);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_13
  (JNIEnv* env, jclass , jint desc, jfloat isigma, jboolean img_normalize)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_13()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::VGG> Ptr_VGG;
        Ptr_VGG _retval_ = cv::xfeatures2d::VGG::create( (int)desc, (float)isigma, (bool)img_normalize );
        return (jlong)(new Ptr_VGG(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_14 (JNIEnv*, jclass, jint, jfloat);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_14
  (JNIEnv* env, jclass , jint desc, jfloat isigma)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_14()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::VGG> Ptr_VGG;
        Ptr_VGG _retval_ = cv::xfeatures2d::VGG::create( (int)desc, (float)isigma );
        return (jlong)(new Ptr_VGG(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_15 (JNIEnv*, jclass, jint);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_15
  (JNIEnv* env, jclass , jint desc)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_15()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::VGG> Ptr_VGG;
        Ptr_VGG _retval_ = cv::xfeatures2d::VGG::create( (int)desc );
        return (jlong)(new Ptr_VGG(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_16 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_xfeatures2d_VGG_create_16
  (JNIEnv* env, jclass )
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::create_16()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::xfeatures2d::VGG> Ptr_VGG;
        Ptr_VGG _retval_ = cv::xfeatures2d::VGG::create();
        return (jlong)(new Ptr_VGG(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::xfeatures2d::VGG::getDefaultName()
//

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_VGG_getDefaultName_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_xfeatures2d_VGG_getDefaultName_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getDefaultName_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getDefaultName();
        return env->NewStringUTF(_retval_.c_str());
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return env->NewStringUTF("");
}



//
//  void cv::xfeatures2d::VGG::setSigma(float isigma)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_setSigma_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_setSigma_10
  (JNIEnv* env, jclass , jlong self, jfloat isigma)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setSigma_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        (*me)->setSigma( (float)isigma );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::VGG::getSigma()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_VGG_getSigma_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_VGG_getSigma_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getSigma_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        return (*me)->getSigma();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::VGG::setUseNormalizeImage(bool img_normalize)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_setUseNormalizeImage_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_setUseNormalizeImage_10
  (JNIEnv* env, jclass , jlong self, jboolean img_normalize)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setUseNormalizeImage_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        (*me)->setUseNormalizeImage( (bool)img_normalize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::VGG::getUseNormalizeImage()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_VGG_getUseNormalizeImage_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_VGG_getUseNormalizeImage_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getUseNormalizeImage_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        return (*me)->getUseNormalizeImage();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::VGG::setUseScaleOrientation(bool use_scale_orientation)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_setUseScaleOrientation_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_setUseScaleOrientation_10
  (JNIEnv* env, jclass , jlong self, jboolean use_scale_orientation)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setUseScaleOrientation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        (*me)->setUseScaleOrientation( (bool)use_scale_orientation );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::VGG::getUseScaleOrientation()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_VGG_getUseScaleOrientation_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_VGG_getUseScaleOrientation_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getUseScaleOrientation_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        return (*me)->getUseScaleOrientation();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::VGG::setScaleFactor(float scale_factor)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_setScaleFactor_10 (JNIEnv*, jclass, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_setScaleFactor_10
  (JNIEnv* env, jclass , jlong self, jfloat scale_factor)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        (*me)->setScaleFactor( (float)scale_factor );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  float cv::xfeatures2d::VGG::getScaleFactor()
//

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_VGG_getScaleFactor_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jfloat JNICALL Java_org_opencv_xfeatures2d_VGG_getScaleFactor_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getScaleFactor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        return (*me)->getScaleFactor();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::xfeatures2d::VGG::setUseNormalizeDescriptor(bool dsc_normalize)
//

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_setUseNormalizeDescriptor_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_setUseNormalizeDescriptor_10
  (JNIEnv* env, jclass , jlong self, jboolean dsc_normalize)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::setUseNormalizeDescriptor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        (*me)->setUseNormalizeDescriptor( (bool)dsc_normalize );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::xfeatures2d::VGG::getUseNormalizeDescriptor()
//

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_VGG_getUseNormalizeDescriptor_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_xfeatures2d_VGG_getUseNormalizeDescriptor_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::xfeatures2d;
    static const char method_name[] = "xfeatures2d::getUseNormalizeDescriptor_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::xfeatures2d::VGG>* me = (Ptr<cv::xfeatures2d::VGG>*) self; //TODO: check for NULL
        return (*me)->getUseNormalizeDescriptor();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  native support for java finalize()
//  static void Ptr<cv::xfeatures2d::VGG>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_xfeatures2d_VGG_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::xfeatures2d::VGG>*) self;
}



} // extern "C"

#endif // HAVE_OPENCV_XFEATURES2D
