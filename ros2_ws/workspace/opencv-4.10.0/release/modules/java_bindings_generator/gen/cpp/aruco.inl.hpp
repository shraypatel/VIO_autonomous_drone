//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_ARUCO

#include <string>

#include "opencv2/aruco.hpp"

#include "/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/workspace/opencv-4.10.0/../opencv_contrib-4.10.0/modules/aruco/include/opencv2/aruco.hpp"
#include "/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/workspace/opencv-4.10.0/../opencv_contrib-4.10.0/modules/aruco/include/opencv2/aruco/aruco_calib.hpp"
#include "/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/workspace/opencv-4.10.0/../opencv_contrib-4.10.0/modules/aruco/include/opencv2/aruco/charuco.hpp"

#define LOG_TAG "org.opencv.aruco"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_aruco
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
//  void cv::aruco::detectMarkers(Mat image, Ptr_Dictionary dictionary, vector_Mat& corners, Mat& ids, Ptr_DetectorParameters parameters = makePtr<DetectorParameters>(), vector_Mat& rejectedImgPoints = vector_Mat())
//

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectMarkers_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectMarkers_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong dictionary_nativeObj, jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong parameters_nativeObj, jlong rejectedImgPoints_mat_nativeObj)
{
    
    static const char method_name[] = "aruco::detectMarkers_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        std::vector<Mat> rejectedImgPoints;
        Mat& rejectedImgPoints_mat = *((Mat*)rejectedImgPoints_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& ids = *((Mat*)ids_nativeObj);
        cv::aruco::detectMarkers( image, *((Ptr<cv::aruco::Dictionary>*)dictionary_nativeObj), corners, ids, *((Ptr<cv::aruco::DetectorParameters>*)parameters_nativeObj), rejectedImgPoints );
        vector_Mat_to_Mat( corners, corners_mat );
        vector_Mat_to_Mat( rejectedImgPoints, rejectedImgPoints_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectMarkers_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectMarkers_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong dictionary_nativeObj, jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong parameters_nativeObj)
{
    
    static const char method_name[] = "aruco::detectMarkers_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& ids = *((Mat*)ids_nativeObj);
        cv::aruco::detectMarkers( image, *((Ptr<cv::aruco::Dictionary>*)dictionary_nativeObj), corners, ids, *((Ptr<cv::aruco::DetectorParameters>*)parameters_nativeObj) );
        vector_Mat_to_Mat( corners, corners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectMarkers_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectMarkers_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong dictionary_nativeObj, jlong corners_mat_nativeObj, jlong ids_nativeObj)
{
    
    static const char method_name[] = "aruco::detectMarkers_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& ids = *((Mat*)ids_nativeObj);
        cv::aruco::detectMarkers( image, *((Ptr<cv::aruco::Dictionary>*)dictionary_nativeObj), corners, ids );
        vector_Mat_to_Mat( corners, corners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::aruco::refineDetectedMarkers(Mat image, Ptr_Board board, vector_Mat& detectedCorners, Mat& detectedIds, vector_Mat& rejectedCorners, Mat cameraMatrix = Mat(), Mat distCoeffs = Mat(), float minRepDistance = 10.f, float errorCorrectionRate = 3.f, bool checkAllOrders = true, Mat& recoveredIdxs = Mat(), Ptr_DetectorParameters parameters = makePtr<DetectorParameters>())
//

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jfloat, jfloat, jboolean, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong board_nativeObj, jlong detectedCorners_mat_nativeObj, jlong detectedIds_nativeObj, jlong rejectedCorners_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jfloat minRepDistance, jfloat errorCorrectionRate, jboolean checkAllOrders, jlong recoveredIdxs_nativeObj, jlong parameters_nativeObj)
{
    
    static const char method_name[] = "aruco::refineDetectedMarkers_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> detectedCorners;
        Mat& detectedCorners_mat = *((Mat*)detectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( detectedCorners_mat, detectedCorners );
        std::vector<Mat> rejectedCorners;
        Mat& rejectedCorners_mat = *((Mat*)rejectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( rejectedCorners_mat, rejectedCorners );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& detectedIds = *((Mat*)detectedIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& recoveredIdxs = *((Mat*)recoveredIdxs_nativeObj);
        cv::aruco::refineDetectedMarkers( image, *((Ptr<cv::aruco::Board>*)board_nativeObj), detectedCorners, detectedIds, rejectedCorners, cameraMatrix, distCoeffs, (float)minRepDistance, (float)errorCorrectionRate, (bool)checkAllOrders, recoveredIdxs, *((Ptr<cv::aruco::DetectorParameters>*)parameters_nativeObj) );
        vector_Mat_to_Mat( detectedCorners, detectedCorners_mat );
        vector_Mat_to_Mat( rejectedCorners, rejectedCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jfloat, jfloat, jboolean, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong board_nativeObj, jlong detectedCorners_mat_nativeObj, jlong detectedIds_nativeObj, jlong rejectedCorners_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jfloat minRepDistance, jfloat errorCorrectionRate, jboolean checkAllOrders, jlong recoveredIdxs_nativeObj)
{
    
    static const char method_name[] = "aruco::refineDetectedMarkers_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> detectedCorners;
        Mat& detectedCorners_mat = *((Mat*)detectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( detectedCorners_mat, detectedCorners );
        std::vector<Mat> rejectedCorners;
        Mat& rejectedCorners_mat = *((Mat*)rejectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( rejectedCorners_mat, rejectedCorners );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& detectedIds = *((Mat*)detectedIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& recoveredIdxs = *((Mat*)recoveredIdxs_nativeObj);
        cv::aruco::refineDetectedMarkers( image, *((Ptr<cv::aruco::Board>*)board_nativeObj), detectedCorners, detectedIds, rejectedCorners, cameraMatrix, distCoeffs, (float)minRepDistance, (float)errorCorrectionRate, (bool)checkAllOrders, recoveredIdxs );
        vector_Mat_to_Mat( detectedCorners, detectedCorners_mat );
        vector_Mat_to_Mat( rejectedCorners, rejectedCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jfloat, jfloat, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong board_nativeObj, jlong detectedCorners_mat_nativeObj, jlong detectedIds_nativeObj, jlong rejectedCorners_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jfloat minRepDistance, jfloat errorCorrectionRate, jboolean checkAllOrders)
{
    
    static const char method_name[] = "aruco::refineDetectedMarkers_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> detectedCorners;
        Mat& detectedCorners_mat = *((Mat*)detectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( detectedCorners_mat, detectedCorners );
        std::vector<Mat> rejectedCorners;
        Mat& rejectedCorners_mat = *((Mat*)rejectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( rejectedCorners_mat, rejectedCorners );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& detectedIds = *((Mat*)detectedIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        cv::aruco::refineDetectedMarkers( image, *((Ptr<cv::aruco::Board>*)board_nativeObj), detectedCorners, detectedIds, rejectedCorners, cameraMatrix, distCoeffs, (float)minRepDistance, (float)errorCorrectionRate, (bool)checkAllOrders );
        vector_Mat_to_Mat( detectedCorners, detectedCorners_mat );
        vector_Mat_to_Mat( rejectedCorners, rejectedCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jfloat, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_13
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong board_nativeObj, jlong detectedCorners_mat_nativeObj, jlong detectedIds_nativeObj, jlong rejectedCorners_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jfloat minRepDistance, jfloat errorCorrectionRate)
{
    
    static const char method_name[] = "aruco::refineDetectedMarkers_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> detectedCorners;
        Mat& detectedCorners_mat = *((Mat*)detectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( detectedCorners_mat, detectedCorners );
        std::vector<Mat> rejectedCorners;
        Mat& rejectedCorners_mat = *((Mat*)rejectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( rejectedCorners_mat, rejectedCorners );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& detectedIds = *((Mat*)detectedIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        cv::aruco::refineDetectedMarkers( image, *((Ptr<cv::aruco::Board>*)board_nativeObj), detectedCorners, detectedIds, rejectedCorners, cameraMatrix, distCoeffs, (float)minRepDistance, (float)errorCorrectionRate );
        vector_Mat_to_Mat( detectedCorners, detectedCorners_mat );
        vector_Mat_to_Mat( rejectedCorners, rejectedCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jfloat);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_14
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong board_nativeObj, jlong detectedCorners_mat_nativeObj, jlong detectedIds_nativeObj, jlong rejectedCorners_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jfloat minRepDistance)
{
    
    static const char method_name[] = "aruco::refineDetectedMarkers_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> detectedCorners;
        Mat& detectedCorners_mat = *((Mat*)detectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( detectedCorners_mat, detectedCorners );
        std::vector<Mat> rejectedCorners;
        Mat& rejectedCorners_mat = *((Mat*)rejectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( rejectedCorners_mat, rejectedCorners );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& detectedIds = *((Mat*)detectedIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        cv::aruco::refineDetectedMarkers( image, *((Ptr<cv::aruco::Board>*)board_nativeObj), detectedCorners, detectedIds, rejectedCorners, cameraMatrix, distCoeffs, (float)minRepDistance );
        vector_Mat_to_Mat( detectedCorners, detectedCorners_mat );
        vector_Mat_to_Mat( rejectedCorners, rejectedCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_15 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_15
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong board_nativeObj, jlong detectedCorners_mat_nativeObj, jlong detectedIds_nativeObj, jlong rejectedCorners_mat_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj)
{
    
    static const char method_name[] = "aruco::refineDetectedMarkers_15()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> detectedCorners;
        Mat& detectedCorners_mat = *((Mat*)detectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( detectedCorners_mat, detectedCorners );
        std::vector<Mat> rejectedCorners;
        Mat& rejectedCorners_mat = *((Mat*)rejectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( rejectedCorners_mat, rejectedCorners );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& detectedIds = *((Mat*)detectedIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        cv::aruco::refineDetectedMarkers( image, *((Ptr<cv::aruco::Board>*)board_nativeObj), detectedCorners, detectedIds, rejectedCorners, cameraMatrix, distCoeffs );
        vector_Mat_to_Mat( detectedCorners, detectedCorners_mat );
        vector_Mat_to_Mat( rejectedCorners, rejectedCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_16 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_16
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong board_nativeObj, jlong detectedCorners_mat_nativeObj, jlong detectedIds_nativeObj, jlong rejectedCorners_mat_nativeObj, jlong cameraMatrix_nativeObj)
{
    
    static const char method_name[] = "aruco::refineDetectedMarkers_16()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> detectedCorners;
        Mat& detectedCorners_mat = *((Mat*)detectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( detectedCorners_mat, detectedCorners );
        std::vector<Mat> rejectedCorners;
        Mat& rejectedCorners_mat = *((Mat*)rejectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( rejectedCorners_mat, rejectedCorners );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& detectedIds = *((Mat*)detectedIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        cv::aruco::refineDetectedMarkers( image, *((Ptr<cv::aruco::Board>*)board_nativeObj), detectedCorners, detectedIds, rejectedCorners, cameraMatrix );
        vector_Mat_to_Mat( detectedCorners, detectedCorners_mat );
        vector_Mat_to_Mat( rejectedCorners, rejectedCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_17 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_refineDetectedMarkers_17
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong board_nativeObj, jlong detectedCorners_mat_nativeObj, jlong detectedIds_nativeObj, jlong rejectedCorners_mat_nativeObj)
{
    
    static const char method_name[] = "aruco::refineDetectedMarkers_17()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> detectedCorners;
        Mat& detectedCorners_mat = *((Mat*)detectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( detectedCorners_mat, detectedCorners );
        std::vector<Mat> rejectedCorners;
        Mat& rejectedCorners_mat = *((Mat*)rejectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( rejectedCorners_mat, rejectedCorners );
        Mat& image = *((Mat*)image_nativeObj);
        Mat& detectedIds = *((Mat*)detectedIds_nativeObj);
        cv::aruco::refineDetectedMarkers( image, *((Ptr<cv::aruco::Board>*)board_nativeObj), detectedCorners, detectedIds, rejectedCorners );
        vector_Mat_to_Mat( detectedCorners, detectedCorners_mat );
        vector_Mat_to_Mat( rejectedCorners, rejectedCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::aruco::drawPlanarBoard(Ptr_Board board, Size outSize, Mat& img, int marginSize, int borderBits)
//

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_drawPlanarBoard_10 (JNIEnv*, jclass, jlong, jdouble, jdouble, jlong, jint, jint);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_drawPlanarBoard_10
  (JNIEnv* env, jclass , jlong board_nativeObj, jdouble outSize_width, jdouble outSize_height, jlong img_nativeObj, jint marginSize, jint borderBits)
{
    
    static const char method_name[] = "aruco::drawPlanarBoard_10()";
    try {
        LOGD("%s", method_name);
        Size outSize((int)outSize_width, (int)outSize_height);
        Mat& img = *((Mat*)img_nativeObj);
        cv::aruco::drawPlanarBoard( *((Ptr<cv::aruco::Board>*)board_nativeObj), outSize, img, (int)marginSize, (int)borderBits );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::aruco::getBoardObjectAndImagePoints(Ptr_Board board, vector_Mat detectedCorners, Mat detectedIds, Mat& objPoints, Mat& imgPoints)
//

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_getBoardObjectAndImagePoints_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_getBoardObjectAndImagePoints_10
  (JNIEnv* env, jclass , jlong board_nativeObj, jlong detectedCorners_mat_nativeObj, jlong detectedIds_nativeObj, jlong objPoints_nativeObj, jlong imgPoints_nativeObj)
{
    
    static const char method_name[] = "aruco::getBoardObjectAndImagePoints_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> detectedCorners;
        Mat& detectedCorners_mat = *((Mat*)detectedCorners_mat_nativeObj);
        Mat_to_vector_Mat( detectedCorners_mat, detectedCorners );
        Mat& detectedIds = *((Mat*)detectedIds_nativeObj);
        Mat& objPoints = *((Mat*)objPoints_nativeObj);
        Mat& imgPoints = *((Mat*)imgPoints_nativeObj);
        cv::aruco::getBoardObjectAndImagePoints( *((Ptr<cv::aruco::Board>*)board_nativeObj), detectedCorners, detectedIds, objPoints, imgPoints );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::aruco::estimatePoseBoard(vector_Mat corners, Mat ids, Ptr_Board board, Mat cameraMatrix, Mat distCoeffs, Mat& rvec, Mat& tvec, bool useExtrinsicGuess = false)
//

JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_estimatePoseBoard_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jboolean);

JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_estimatePoseBoard_10
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong board_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jboolean useExtrinsicGuess)
{
    
    static const char method_name[] = "aruco::estimatePoseBoard_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        Mat& ids = *((Mat*)ids_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::aruco::estimatePoseBoard( corners, ids, *((Ptr<cv::aruco::Board>*)board_nativeObj), cameraMatrix, distCoeffs, rvec, tvec, (bool)useExtrinsicGuess );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_estimatePoseBoard_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_estimatePoseBoard_11
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong board_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj)
{
    
    static const char method_name[] = "aruco::estimatePoseBoard_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        Mat& ids = *((Mat*)ids_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::aruco::estimatePoseBoard( corners, ids, *((Ptr<cv::aruco::Board>*)board_nativeObj), cameraMatrix, distCoeffs, rvec, tvec );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  bool cv::aruco::estimatePoseCharucoBoard(Mat charucoCorners, Mat charucoIds, Ptr_CharucoBoard board, Mat cameraMatrix, Mat distCoeffs, Mat& rvec, Mat& tvec, bool useExtrinsicGuess = false)
//

JNIEXPORT jboolean JNICALL Java_org_opencv_aruco_Aruco_estimatePoseCharucoBoard_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jboolean);

JNIEXPORT jboolean JNICALL Java_org_opencv_aruco_Aruco_estimatePoseCharucoBoard_10
  (JNIEnv* env, jclass , jlong charucoCorners_nativeObj, jlong charucoIds_nativeObj, jlong board_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj, jboolean useExtrinsicGuess)
{
    
    static const char method_name[] = "aruco::estimatePoseCharucoBoard_10()";
    try {
        LOGD("%s", method_name);
        Mat& charucoCorners = *((Mat*)charucoCorners_nativeObj);
        Mat& charucoIds = *((Mat*)charucoIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::aruco::estimatePoseCharucoBoard( charucoCorners, charucoIds, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), cameraMatrix, distCoeffs, rvec, tvec, (bool)useExtrinsicGuess );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jboolean JNICALL Java_org_opencv_aruco_Aruco_estimatePoseCharucoBoard_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_aruco_Aruco_estimatePoseCharucoBoard_11
  (JNIEnv* env, jclass , jlong charucoCorners_nativeObj, jlong charucoIds_nativeObj, jlong board_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvec_nativeObj, jlong tvec_nativeObj)
{
    
    static const char method_name[] = "aruco::estimatePoseCharucoBoard_11()";
    try {
        LOGD("%s", method_name);
        Mat& charucoCorners = *((Mat*)charucoCorners_nativeObj);
        Mat& charucoIds = *((Mat*)charucoIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvec = *((Mat*)rvec_nativeObj);
        Mat& tvec = *((Mat*)tvec_nativeObj);
        return cv::aruco::estimatePoseCharucoBoard( charucoCorners, charucoIds, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), cameraMatrix, distCoeffs, rvec, tvec );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::aruco::estimatePoseSingleMarkers(vector_Mat corners, float markerLength, Mat cameraMatrix, Mat distCoeffs, Mat& rvecs, Mat& tvecs, Mat& objPoints = Mat(), Ptr_EstimateParameters estimateParameters = makePtr<EstimateParameters>())
//

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_estimatePoseSingleMarkers_10 (JNIEnv*, jclass, jlong, jfloat, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_estimatePoseSingleMarkers_10
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jfloat markerLength, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_nativeObj, jlong tvecs_nativeObj, jlong objPoints_nativeObj, jlong estimateParameters_nativeObj)
{
    
    static const char method_name[] = "aruco::estimatePoseSingleMarkers_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvecs = *((Mat*)rvecs_nativeObj);
        Mat& tvecs = *((Mat*)tvecs_nativeObj);
        Mat& objPoints = *((Mat*)objPoints_nativeObj);
        cv::aruco::estimatePoseSingleMarkers( corners, (float)markerLength, cameraMatrix, distCoeffs, rvecs, tvecs, objPoints, *((Ptr<cv::aruco::EstimateParameters>*)estimateParameters_nativeObj) );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_estimatePoseSingleMarkers_11 (JNIEnv*, jclass, jlong, jfloat, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_estimatePoseSingleMarkers_11
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jfloat markerLength, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_nativeObj, jlong tvecs_nativeObj, jlong objPoints_nativeObj)
{
    
    static const char method_name[] = "aruco::estimatePoseSingleMarkers_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvecs = *((Mat*)rvecs_nativeObj);
        Mat& tvecs = *((Mat*)tvecs_nativeObj);
        Mat& objPoints = *((Mat*)objPoints_nativeObj);
        cv::aruco::estimatePoseSingleMarkers( corners, (float)markerLength, cameraMatrix, distCoeffs, rvecs, tvecs, objPoints );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_estimatePoseSingleMarkers_12 (JNIEnv*, jclass, jlong, jfloat, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_estimatePoseSingleMarkers_12
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jfloat markerLength, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_nativeObj, jlong tvecs_nativeObj)
{
    
    static const char method_name[] = "aruco::estimatePoseSingleMarkers_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& rvecs = *((Mat*)rvecs_nativeObj);
        Mat& tvecs = *((Mat*)tvecs_nativeObj);
        cv::aruco::estimatePoseSingleMarkers( corners, (float)markerLength, cameraMatrix, distCoeffs, rvecs, tvecs );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  bool cv::aruco::testCharucoCornersCollinear(Ptr_CharucoBoard board, Mat charucoIds)
//

JNIEXPORT jboolean JNICALL Java_org_opencv_aruco_Aruco_testCharucoCornersCollinear_10 (JNIEnv*, jclass, jlong, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_aruco_Aruco_testCharucoCornersCollinear_10
  (JNIEnv* env, jclass , jlong board_nativeObj, jlong charucoIds_nativeObj)
{
    
    static const char method_name[] = "aruco::testCharucoCornersCollinear_10()";
    try {
        LOGD("%s", method_name);
        Mat& charucoIds = *((Mat*)charucoIds_nativeObj);
        return cv::aruco::testCharucoCornersCollinear( *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), charucoIds );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::aruco::calibrateCameraAruco(vector_Mat corners, Mat ids, Mat counter, Ptr_Board board, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs, vector_Mat& tvecs, Mat& stdDeviationsIntrinsics, Mat& stdDeviationsExtrinsics, Mat& perViewErrors, int flags = 0, TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraArucoExtended_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraArucoExtended_10
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong counter_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong perViewErrors_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    
    static const char method_name[] = "aruco::calibrateCameraArucoExtended_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& ids = *((Mat*)ids_nativeObj);
        Mat& counter = *((Mat*)counter_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        double _retval_ = cv::aruco::calibrateCameraAruco( corners, ids, counter, *((Ptr<cv::aruco::Board>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors, (int)flags, criteria );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraArucoExtended_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraArucoExtended_11
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong counter_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong perViewErrors_nativeObj, jint flags)
{
    
    static const char method_name[] = "aruco::calibrateCameraArucoExtended_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& ids = *((Mat*)ids_nativeObj);
        Mat& counter = *((Mat*)counter_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        double _retval_ = cv::aruco::calibrateCameraAruco( corners, ids, counter, *((Ptr<cv::aruco::Board>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors, (int)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraArucoExtended_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraArucoExtended_12
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong counter_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong perViewErrors_nativeObj)
{
    
    static const char method_name[] = "aruco::calibrateCameraArucoExtended_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& ids = *((Mat*)ids_nativeObj);
        Mat& counter = *((Mat*)counter_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        double _retval_ = cv::aruco::calibrateCameraAruco( corners, ids, counter, *((Ptr<cv::aruco::Board>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::aruco::calibrateCameraAruco(vector_Mat corners, Mat ids, Mat counter, Ptr_Board board, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs = vector_Mat(), vector_Mat& tvecs = vector_Mat(), int flags = 0, TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraAruco_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraAruco_10
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong counter_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    
    static const char method_name[] = "aruco::calibrateCameraAruco_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& ids = *((Mat*)ids_nativeObj);
        Mat& counter = *((Mat*)counter_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        double _retval_ = cv::aruco::calibrateCameraAruco( corners, ids, counter, *((Ptr<cv::aruco::Board>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, (int)flags, criteria );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraAruco_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraAruco_11
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong counter_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jint flags)
{
    
    static const char method_name[] = "aruco::calibrateCameraAruco_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& ids = *((Mat*)ids_nativeObj);
        Mat& counter = *((Mat*)counter_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        double _retval_ = cv::aruco::calibrateCameraAruco( corners, ids, counter, *((Ptr<cv::aruco::Board>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, (int)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraAruco_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraAruco_12
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong counter_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj)
{
    
    static const char method_name[] = "aruco::calibrateCameraAruco_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Mat& ids = *((Mat*)ids_nativeObj);
        Mat& counter = *((Mat*)counter_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        double _retval_ = cv::aruco::calibrateCameraAruco( corners, ids, counter, *((Ptr<cv::aruco::Board>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraAruco_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraAruco_13
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong counter_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj)
{
    
    static const char method_name[] = "aruco::calibrateCameraAruco_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        Mat& ids = *((Mat*)ids_nativeObj);
        Mat& counter = *((Mat*)counter_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        double _retval_ = cv::aruco::calibrateCameraAruco( corners, ids, counter, *((Ptr<cv::aruco::Board>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraAruco_14 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraAruco_14
  (JNIEnv* env, jclass , jlong corners_mat_nativeObj, jlong ids_nativeObj, jlong counter_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj)
{
    
    static const char method_name[] = "aruco::calibrateCameraAruco_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> corners;
        Mat& corners_mat = *((Mat*)corners_mat_nativeObj);
        Mat_to_vector_Mat( corners_mat, corners );
        Mat& ids = *((Mat*)ids_nativeObj);
        Mat& counter = *((Mat*)counter_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        return cv::aruco::calibrateCameraAruco( corners, ids, counter, *((Ptr<cv::aruco::Board>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::aruco::calibrateCameraCharuco(vector_Mat charucoCorners, vector_Mat charucoIds, Ptr_CharucoBoard board, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs, vector_Mat& tvecs, Mat& stdDeviationsIntrinsics, Mat& stdDeviationsExtrinsics, Mat& perViewErrors, int flags = 0, TermCriteria criteria = TermCriteria( TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharucoExtended_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharucoExtended_10
  (JNIEnv* env, jclass , jlong charucoCorners_mat_nativeObj, jlong charucoIds_mat_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong perViewErrors_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    
    static const char method_name[] = "aruco::calibrateCameraCharucoExtended_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> charucoCorners;
        Mat& charucoCorners_mat = *((Mat*)charucoCorners_mat_nativeObj);
        Mat_to_vector_Mat( charucoCorners_mat, charucoCorners );
        std::vector<Mat> charucoIds;
        Mat& charucoIds_mat = *((Mat*)charucoIds_mat_nativeObj);
        Mat_to_vector_Mat( charucoIds_mat, charucoIds );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        double _retval_ = cv::aruco::calibrateCameraCharuco( charucoCorners, charucoIds, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors, (int)flags, criteria );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharucoExtended_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharucoExtended_11
  (JNIEnv* env, jclass , jlong charucoCorners_mat_nativeObj, jlong charucoIds_mat_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong perViewErrors_nativeObj, jint flags)
{
    
    static const char method_name[] = "aruco::calibrateCameraCharucoExtended_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> charucoCorners;
        Mat& charucoCorners_mat = *((Mat*)charucoCorners_mat_nativeObj);
        Mat_to_vector_Mat( charucoCorners_mat, charucoCorners );
        std::vector<Mat> charucoIds;
        Mat& charucoIds_mat = *((Mat*)charucoIds_mat_nativeObj);
        Mat_to_vector_Mat( charucoIds_mat, charucoIds );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        double _retval_ = cv::aruco::calibrateCameraCharuco( charucoCorners, charucoIds, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors, (int)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharucoExtended_12 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharucoExtended_12
  (JNIEnv* env, jclass , jlong charucoCorners_mat_nativeObj, jlong charucoIds_mat_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jlong stdDeviationsIntrinsics_nativeObj, jlong stdDeviationsExtrinsics_nativeObj, jlong perViewErrors_nativeObj)
{
    
    static const char method_name[] = "aruco::calibrateCameraCharucoExtended_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> charucoCorners;
        Mat& charucoCorners_mat = *((Mat*)charucoCorners_mat_nativeObj);
        Mat_to_vector_Mat( charucoCorners_mat, charucoCorners );
        std::vector<Mat> charucoIds;
        Mat& charucoIds_mat = *((Mat*)charucoIds_mat_nativeObj);
        Mat_to_vector_Mat( charucoIds_mat, charucoIds );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        Mat& stdDeviationsIntrinsics = *((Mat*)stdDeviationsIntrinsics_nativeObj);
        Mat& stdDeviationsExtrinsics = *((Mat*)stdDeviationsExtrinsics_nativeObj);
        Mat& perViewErrors = *((Mat*)perViewErrors_nativeObj);
        double _retval_ = cv::aruco::calibrateCameraCharuco( charucoCorners, charucoIds, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, stdDeviationsIntrinsics, stdDeviationsExtrinsics, perViewErrors );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  double cv::aruco::calibrateCameraCharuco(vector_Mat charucoCorners, vector_Mat charucoIds, Ptr_CharucoBoard board, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs, vector_Mat& rvecs = vector_Mat(), vector_Mat& tvecs = vector_Mat(), int flags = 0, TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON))
//

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharuco_10 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jint, jint, jint, jdouble);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharuco_10
  (JNIEnv* env, jclass , jlong charucoCorners_mat_nativeObj, jlong charucoIds_mat_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jint flags, jint criteria_type, jint criteria_maxCount, jdouble criteria_epsilon)
{
    
    static const char method_name[] = "aruco::calibrateCameraCharuco_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> charucoCorners;
        Mat& charucoCorners_mat = *((Mat*)charucoCorners_mat_nativeObj);
        Mat_to_vector_Mat( charucoCorners_mat, charucoCorners );
        std::vector<Mat> charucoIds;
        Mat& charucoIds_mat = *((Mat*)charucoIds_mat_nativeObj);
        Mat_to_vector_Mat( charucoIds_mat, charucoIds );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        TermCriteria criteria(criteria_type, criteria_maxCount, criteria_epsilon);
        double _retval_ = cv::aruco::calibrateCameraCharuco( charucoCorners, charucoIds, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, (int)flags, criteria );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharuco_11 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharuco_11
  (JNIEnv* env, jclass , jlong charucoCorners_mat_nativeObj, jlong charucoIds_mat_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj, jint flags)
{
    
    static const char method_name[] = "aruco::calibrateCameraCharuco_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> charucoCorners;
        Mat& charucoCorners_mat = *((Mat*)charucoCorners_mat_nativeObj);
        Mat_to_vector_Mat( charucoCorners_mat, charucoCorners );
        std::vector<Mat> charucoIds;
        Mat& charucoIds_mat = *((Mat*)charucoIds_mat_nativeObj);
        Mat_to_vector_Mat( charucoIds_mat, charucoIds );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        double _retval_ = cv::aruco::calibrateCameraCharuco( charucoCorners, charucoIds, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, (int)flags );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharuco_12 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharuco_12
  (JNIEnv* env, jclass , jlong charucoCorners_mat_nativeObj, jlong charucoIds_mat_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj, jlong tvecs_mat_nativeObj)
{
    
    static const char method_name[] = "aruco::calibrateCameraCharuco_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> charucoCorners;
        Mat& charucoCorners_mat = *((Mat*)charucoCorners_mat_nativeObj);
        Mat_to_vector_Mat( charucoCorners_mat, charucoCorners );
        std::vector<Mat> charucoIds;
        Mat& charucoIds_mat = *((Mat*)charucoIds_mat_nativeObj);
        Mat_to_vector_Mat( charucoIds_mat, charucoIds );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        std::vector<Mat> tvecs;
        Mat& tvecs_mat = *((Mat*)tvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        double _retval_ = cv::aruco::calibrateCameraCharuco( charucoCorners, charucoIds, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs, tvecs );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        vector_Mat_to_Mat( tvecs, tvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharuco_13 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharuco_13
  (JNIEnv* env, jclass , jlong charucoCorners_mat_nativeObj, jlong charucoIds_mat_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong rvecs_mat_nativeObj)
{
    
    static const char method_name[] = "aruco::calibrateCameraCharuco_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> charucoCorners;
        Mat& charucoCorners_mat = *((Mat*)charucoCorners_mat_nativeObj);
        Mat_to_vector_Mat( charucoCorners_mat, charucoCorners );
        std::vector<Mat> charucoIds;
        Mat& charucoIds_mat = *((Mat*)charucoIds_mat_nativeObj);
        Mat_to_vector_Mat( charucoIds_mat, charucoIds );
        std::vector<Mat> rvecs;
        Mat& rvecs_mat = *((Mat*)rvecs_mat_nativeObj);
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        double _retval_ = cv::aruco::calibrateCameraCharuco( charucoCorners, charucoIds, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs, rvecs );
        vector_Mat_to_Mat( rvecs, rvecs_mat );
        return _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharuco_14 (JNIEnv*, jclass, jlong, jlong, jlong, jdouble, jdouble, jlong, jlong);

JNIEXPORT jdouble JNICALL Java_org_opencv_aruco_Aruco_calibrateCameraCharuco_14
  (JNIEnv* env, jclass , jlong charucoCorners_mat_nativeObj, jlong charucoIds_mat_nativeObj, jlong board_nativeObj, jdouble imageSize_width, jdouble imageSize_height, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj)
{
    
    static const char method_name[] = "aruco::calibrateCameraCharuco_14()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> charucoCorners;
        Mat& charucoCorners_mat = *((Mat*)charucoCorners_mat_nativeObj);
        Mat_to_vector_Mat( charucoCorners_mat, charucoCorners );
        std::vector<Mat> charucoIds;
        Mat& charucoIds_mat = *((Mat*)charucoIds_mat_nativeObj);
        Mat_to_vector_Mat( charucoIds_mat, charucoIds );
        Size imageSize((int)imageSize_width, (int)imageSize_height);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        return cv::aruco::calibrateCameraCharuco( charucoCorners, charucoIds, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), imageSize, cameraMatrix, distCoeffs );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  int cv::aruco::interpolateCornersCharuco(vector_Mat markerCorners, Mat markerIds, Mat image, Ptr_CharucoBoard board, Mat& charucoCorners, Mat& charucoIds, Mat cameraMatrix = Mat(), Mat distCoeffs = Mat(), int minMarkers = 2)
//

JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_interpolateCornersCharuco_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jint);

JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_interpolateCornersCharuco_10
  (JNIEnv* env, jclass , jlong markerCorners_mat_nativeObj, jlong markerIds_nativeObj, jlong image_nativeObj, jlong board_nativeObj, jlong charucoCorners_nativeObj, jlong charucoIds_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jint minMarkers)
{
    
    static const char method_name[] = "aruco::interpolateCornersCharuco_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> markerCorners;
        Mat& markerCorners_mat = *((Mat*)markerCorners_mat_nativeObj);
        Mat_to_vector_Mat( markerCorners_mat, markerCorners );
        Mat& markerIds = *((Mat*)markerIds_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& charucoCorners = *((Mat*)charucoCorners_nativeObj);
        Mat& charucoIds = *((Mat*)charucoIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        return cv::aruco::interpolateCornersCharuco( markerCorners, markerIds, image, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), charucoCorners, charucoIds, cameraMatrix, distCoeffs, (int)minMarkers );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_interpolateCornersCharuco_11 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_interpolateCornersCharuco_11
  (JNIEnv* env, jclass , jlong markerCorners_mat_nativeObj, jlong markerIds_nativeObj, jlong image_nativeObj, jlong board_nativeObj, jlong charucoCorners_nativeObj, jlong charucoIds_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj)
{
    
    static const char method_name[] = "aruco::interpolateCornersCharuco_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> markerCorners;
        Mat& markerCorners_mat = *((Mat*)markerCorners_mat_nativeObj);
        Mat_to_vector_Mat( markerCorners_mat, markerCorners );
        Mat& markerIds = *((Mat*)markerIds_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& charucoCorners = *((Mat*)charucoCorners_nativeObj);
        Mat& charucoIds = *((Mat*)charucoIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        return cv::aruco::interpolateCornersCharuco( markerCorners, markerIds, image, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), charucoCorners, charucoIds, cameraMatrix, distCoeffs );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_interpolateCornersCharuco_12 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_interpolateCornersCharuco_12
  (JNIEnv* env, jclass , jlong markerCorners_mat_nativeObj, jlong markerIds_nativeObj, jlong image_nativeObj, jlong board_nativeObj, jlong charucoCorners_nativeObj, jlong charucoIds_nativeObj, jlong cameraMatrix_nativeObj)
{
    
    static const char method_name[] = "aruco::interpolateCornersCharuco_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> markerCorners;
        Mat& markerCorners_mat = *((Mat*)markerCorners_mat_nativeObj);
        Mat_to_vector_Mat( markerCorners_mat, markerCorners );
        Mat& markerIds = *((Mat*)markerIds_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& charucoCorners = *((Mat*)charucoCorners_nativeObj);
        Mat& charucoIds = *((Mat*)charucoIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        return cv::aruco::interpolateCornersCharuco( markerCorners, markerIds, image, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), charucoCorners, charucoIds, cameraMatrix );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_interpolateCornersCharuco_13 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_aruco_Aruco_interpolateCornersCharuco_13
  (JNIEnv* env, jclass , jlong markerCorners_mat_nativeObj, jlong markerIds_nativeObj, jlong image_nativeObj, jlong board_nativeObj, jlong charucoCorners_nativeObj, jlong charucoIds_nativeObj)
{
    
    static const char method_name[] = "aruco::interpolateCornersCharuco_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> markerCorners;
        Mat& markerCorners_mat = *((Mat*)markerCorners_mat_nativeObj);
        Mat_to_vector_Mat( markerCorners_mat, markerCorners );
        Mat& markerIds = *((Mat*)markerIds_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& charucoCorners = *((Mat*)charucoCorners_nativeObj);
        Mat& charucoIds = *((Mat*)charucoIds_nativeObj);
        return cv::aruco::interpolateCornersCharuco( markerCorners, markerIds, image, *((Ptr<cv::aruco::CharucoBoard>*)board_nativeObj), charucoCorners, charucoIds );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::aruco::detectCharucoDiamond(Mat image, vector_Mat markerCorners, Mat markerIds, float squareMarkerLengthRate, vector_Mat& diamondCorners, Mat& diamondIds, Mat cameraMatrix = Mat(), Mat distCoeffs = Mat(), Ptr_Dictionary dictionary = makePtr<Dictionary> (getPredefinedDictionary(PredefinedDictionaryType::DICT_4X4_50)))
//

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectCharucoDiamond_10 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jlong, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectCharucoDiamond_10
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong markerCorners_mat_nativeObj, jlong markerIds_nativeObj, jfloat squareMarkerLengthRate, jlong diamondCorners_mat_nativeObj, jlong diamondIds_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj, jlong dictionary_nativeObj)
{
    
    static const char method_name[] = "aruco::detectCharucoDiamond_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> markerCorners;
        Mat& markerCorners_mat = *((Mat*)markerCorners_mat_nativeObj);
        Mat_to_vector_Mat( markerCorners_mat, markerCorners );
        std::vector<Mat> diamondCorners;
        Mat& diamondCorners_mat = *((Mat*)diamondCorners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& markerIds = *((Mat*)markerIds_nativeObj);
        Mat& diamondIds = *((Mat*)diamondIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        cv::aruco::detectCharucoDiamond( image, markerCorners, markerIds, (float)squareMarkerLengthRate, diamondCorners, diamondIds, cameraMatrix, distCoeffs, *((Ptr<cv::aruco::Dictionary>*)dictionary_nativeObj) );
        vector_Mat_to_Mat( diamondCorners, diamondCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectCharucoDiamond_11 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jlong, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectCharucoDiamond_11
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong markerCorners_mat_nativeObj, jlong markerIds_nativeObj, jfloat squareMarkerLengthRate, jlong diamondCorners_mat_nativeObj, jlong diamondIds_nativeObj, jlong cameraMatrix_nativeObj, jlong distCoeffs_nativeObj)
{
    
    static const char method_name[] = "aruco::detectCharucoDiamond_11()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> markerCorners;
        Mat& markerCorners_mat = *((Mat*)markerCorners_mat_nativeObj);
        Mat_to_vector_Mat( markerCorners_mat, markerCorners );
        std::vector<Mat> diamondCorners;
        Mat& diamondCorners_mat = *((Mat*)diamondCorners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& markerIds = *((Mat*)markerIds_nativeObj);
        Mat& diamondIds = *((Mat*)diamondIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        Mat& distCoeffs = *((Mat*)distCoeffs_nativeObj);
        cv::aruco::detectCharucoDiamond( image, markerCorners, markerIds, (float)squareMarkerLengthRate, diamondCorners, diamondIds, cameraMatrix, distCoeffs );
        vector_Mat_to_Mat( diamondCorners, diamondCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectCharucoDiamond_12 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectCharucoDiamond_12
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong markerCorners_mat_nativeObj, jlong markerIds_nativeObj, jfloat squareMarkerLengthRate, jlong diamondCorners_mat_nativeObj, jlong diamondIds_nativeObj, jlong cameraMatrix_nativeObj)
{
    
    static const char method_name[] = "aruco::detectCharucoDiamond_12()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> markerCorners;
        Mat& markerCorners_mat = *((Mat*)markerCorners_mat_nativeObj);
        Mat_to_vector_Mat( markerCorners_mat, markerCorners );
        std::vector<Mat> diamondCorners;
        Mat& diamondCorners_mat = *((Mat*)diamondCorners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& markerIds = *((Mat*)markerIds_nativeObj);
        Mat& diamondIds = *((Mat*)diamondIds_nativeObj);
        Mat& cameraMatrix = *((Mat*)cameraMatrix_nativeObj);
        cv::aruco::detectCharucoDiamond( image, markerCorners, markerIds, (float)squareMarkerLengthRate, diamondCorners, diamondIds, cameraMatrix );
        vector_Mat_to_Mat( diamondCorners, diamondCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectCharucoDiamond_13 (JNIEnv*, jclass, jlong, jlong, jlong, jfloat, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_Aruco_detectCharucoDiamond_13
  (JNIEnv* env, jclass , jlong image_nativeObj, jlong markerCorners_mat_nativeObj, jlong markerIds_nativeObj, jfloat squareMarkerLengthRate, jlong diamondCorners_mat_nativeObj, jlong diamondIds_nativeObj)
{
    
    static const char method_name[] = "aruco::detectCharucoDiamond_13()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> markerCorners;
        Mat& markerCorners_mat = *((Mat*)markerCorners_mat_nativeObj);
        Mat_to_vector_Mat( markerCorners_mat, markerCorners );
        std::vector<Mat> diamondCorners;
        Mat& diamondCorners_mat = *((Mat*)diamondCorners_mat_nativeObj);
        Mat& image = *((Mat*)image_nativeObj);
        Mat& markerIds = *((Mat*)markerIds_nativeObj);
        Mat& diamondIds = *((Mat*)diamondIds_nativeObj);
        cv::aruco::detectCharucoDiamond( image, markerCorners, markerIds, (float)squareMarkerLengthRate, diamondCorners, diamondIds );
        vector_Mat_to_Mat( diamondCorners, diamondCorners_mat );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//   cv::aruco::EstimateParameters::EstimateParameters()
//

JNIEXPORT jlong JNICALL Java_org_opencv_aruco_EstimateParameters_EstimateParameters_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_aruco_EstimateParameters_EstimateParameters_10
  (JNIEnv* env, jclass )
{
    using namespace cv::aruco;
    static const char method_name[] = "aruco::EstimateParameters_10()";
    try {
        LOGD("%s", method_name);
        cv::aruco::EstimateParameters* _retval_ = new cv::aruco::EstimateParameters();
        return (jlong) _retval_;
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// bool EstimateParameters::useExtrinsicGuess
//

JNIEXPORT jboolean JNICALL Java_org_opencv_aruco_EstimateParameters_get_1useExtrinsicGuess_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jboolean JNICALL Java_org_opencv_aruco_EstimateParameters_get_1useExtrinsicGuess_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::aruco;
    static const char method_name[] = "aruco::get_1useExtrinsicGuess_10()";
    try {
        LOGD("%s", method_name);
        cv::aruco::EstimateParameters* me = (cv::aruco::EstimateParameters*) self; //TODO: check for NULL
        return me->useExtrinsicGuess;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void EstimateParameters::useExtrinsicGuess
//

JNIEXPORT void JNICALL Java_org_opencv_aruco_EstimateParameters_set_1useExtrinsicGuess_10 (JNIEnv*, jclass, jlong, jboolean);

JNIEXPORT void JNICALL Java_org_opencv_aruco_EstimateParameters_set_1useExtrinsicGuess_10
  (JNIEnv* env, jclass , jlong self, jboolean useExtrinsicGuess)
{
    using namespace cv::aruco;
    static const char method_name[] = "aruco::set_1useExtrinsicGuess_10()";
    try {
        LOGD("%s", method_name);
        cv::aruco::EstimateParameters* me = (cv::aruco::EstimateParameters*) self; //TODO: check for NULL
        me->useExtrinsicGuess = ( (bool)useExtrinsicGuess );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
// int EstimateParameters::solvePnPMethod
//

JNIEXPORT jint JNICALL Java_org_opencv_aruco_EstimateParameters_get_1solvePnPMethod_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_aruco_EstimateParameters_get_1solvePnPMethod_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::aruco;
    static const char method_name[] = "aruco::get_1solvePnPMethod_10()";
    try {
        LOGD("%s", method_name);
        cv::aruco::EstimateParameters* me = (cv::aruco::EstimateParameters*) self; //TODO: check for NULL
        return me->solvePnPMethod;//();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
// void EstimateParameters::solvePnPMethod
//

JNIEXPORT void JNICALL Java_org_opencv_aruco_EstimateParameters_set_1solvePnPMethod_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_aruco_EstimateParameters_set_1solvePnPMethod_10
  (JNIEnv* env, jclass , jlong self, jint solvePnPMethod)
{
    using namespace cv::aruco;
    static const char method_name[] = "aruco::set_1solvePnPMethod_10()";
    try {
        LOGD("%s", method_name);
        cv::aruco::EstimateParameters* me = (cv::aruco::EstimateParameters*) self; //TODO: check for NULL
        me->solvePnPMethod = ( (int)solvePnPMethod );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  native support for java finalize()
//  static void cv::aruco::EstimateParameters::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_aruco_EstimateParameters_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_aruco_EstimateParameters_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (cv::aruco::EstimateParameters*) self;
}



} // extern "C"

#endif // HAVE_OPENCV_ARUCO
