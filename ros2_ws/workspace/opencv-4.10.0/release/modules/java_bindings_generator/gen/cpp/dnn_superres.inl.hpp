//
// This file is auto-generated. Please don't modify it!
//

#undef LOG_TAG

#include "opencv2/opencv_modules.hpp"
#ifdef HAVE_OPENCV_DNN_SUPERRES

#include <string>

#include "opencv2/dnn_superres.hpp"

#include "/home/group7/Desktop/VIO_autonomous_drone/ros2_ws/workspace/opencv-4.10.0/../opencv_contrib-4.10.0/modules/dnn_superres/include/opencv2/dnn_superres.hpp"

#define LOG_TAG "org.opencv.dnn_superres"
#include "common.h"

using namespace cv;

/// throw java exception
#undef throwJavaException
#define throwJavaException throwJavaException_dnn_superres
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
// static Ptr_DnnSuperResImpl cv::dnn_superres::DnnSuperResImpl::create()
//

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_create_10 (JNIEnv*, jclass);

JNIEXPORT jlong JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_create_10
  (JNIEnv* env, jclass )
{
    using namespace cv::dnn_superres;
    static const char method_name[] = "dnn_1superres::create_10()";
    try {
        LOGD("%s", method_name);
        typedef Ptr<cv::dnn_superres::DnnSuperResImpl> Ptr_DnnSuperResImpl;
        Ptr_DnnSuperResImpl _retval_ = cv::dnn_superres::DnnSuperResImpl::create();
        return (jlong)(new Ptr_DnnSuperResImpl(_retval_));
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  void cv::dnn_superres::DnnSuperResImpl::readModel(String path)
//

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_readModel_10 (JNIEnv*, jclass, jlong, jstring);

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_readModel_10
  (JNIEnv* env, jclass , jlong self, jstring path)
{
    using namespace cv::dnn_superres;
    static const char method_name[] = "dnn_1superres::readModel_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn_superres::DnnSuperResImpl>* me = (Ptr<cv::dnn_superres::DnnSuperResImpl>*) self; //TODO: check for NULL
        const char* utf_path = env->GetStringUTFChars(path, 0); String n_path( utf_path ? utf_path : "" ); env->ReleaseStringUTFChars(path, utf_path);
        (*me)->readModel( n_path );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn_superres::DnnSuperResImpl::setModel(String algo, int scale)
//

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_setModel_10 (JNIEnv*, jclass, jlong, jstring, jint);

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_setModel_10
  (JNIEnv* env, jclass , jlong self, jstring algo, jint scale)
{
    using namespace cv::dnn_superres;
    static const char method_name[] = "dnn_1superres::setModel_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn_superres::DnnSuperResImpl>* me = (Ptr<cv::dnn_superres::DnnSuperResImpl>*) self; //TODO: check for NULL
        const char* utf_algo = env->GetStringUTFChars(algo, 0); String n_algo( utf_algo ? utf_algo : "" ); env->ReleaseStringUTFChars(algo, utf_algo);
        (*me)->setModel( n_algo, (int)scale );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn_superres::DnnSuperResImpl::setPreferableBackend(int backendId)
//

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_setPreferableBackend_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_setPreferableBackend_10
  (JNIEnv* env, jclass , jlong self, jint backendId)
{
    using namespace cv::dnn_superres;
    static const char method_name[] = "dnn_1superres::setPreferableBackend_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn_superres::DnnSuperResImpl>* me = (Ptr<cv::dnn_superres::DnnSuperResImpl>*) self; //TODO: check for NULL
        (*me)->setPreferableBackend( (int)backendId );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn_superres::DnnSuperResImpl::setPreferableTarget(int targetId)
//

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_setPreferableTarget_10 (JNIEnv*, jclass, jlong, jint);

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_setPreferableTarget_10
  (JNIEnv* env, jclass , jlong self, jint targetId)
{
    using namespace cv::dnn_superres;
    static const char method_name[] = "dnn_1superres::setPreferableTarget_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn_superres::DnnSuperResImpl>* me = (Ptr<cv::dnn_superres::DnnSuperResImpl>*) self; //TODO: check for NULL
        (*me)->setPreferableTarget( (int)targetId );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn_superres::DnnSuperResImpl::upsample(Mat img, Mat& result)
//

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_upsample_10 (JNIEnv*, jclass, jlong, jlong, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_upsample_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong result_nativeObj)
{
    using namespace cv::dnn_superres;
    static const char method_name[] = "dnn_1superres::upsample_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn_superres::DnnSuperResImpl>* me = (Ptr<cv::dnn_superres::DnnSuperResImpl>*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        Mat& result = *((Mat*)result_nativeObj);
        (*me)->upsample( img, result );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  void cv::dnn_superres::DnnSuperResImpl::upsampleMultioutput(Mat img, vector_Mat imgs_new, vector_int scale_factors, vector_String node_names)
//

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_upsampleMultioutput_10 (JNIEnv*, jclass, jlong, jlong, jlong, jlong, jobject);

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_upsampleMultioutput_10
  (JNIEnv* env, jclass , jlong self, jlong img_nativeObj, jlong imgs_new_mat_nativeObj, jlong scale_factors_mat_nativeObj, jobject node_names_list)
{
    using namespace cv::dnn_superres;
    static const char method_name[] = "dnn_1superres::upsampleMultioutput_10()";
    try {
        LOGD("%s", method_name);
        std::vector<Mat> imgs_new;
        Mat& imgs_new_mat = *((Mat*)imgs_new_mat_nativeObj);
        Mat_to_vector_Mat( imgs_new_mat, imgs_new );
        std::vector<int> scale_factors;
        Mat& scale_factors_mat = *((Mat*)scale_factors_mat_nativeObj);
        Mat_to_vector_int( scale_factors_mat, scale_factors );
        std::vector< String > node_names;
        node_names = List_to_vector_String(env, node_names_list);
        Ptr<cv::dnn_superres::DnnSuperResImpl>* me = (Ptr<cv::dnn_superres::DnnSuperResImpl>*) self; //TODO: check for NULL
        Mat& img = *((Mat*)img_nativeObj);
        (*me)->upsampleMultioutput( img, imgs_new, scale_factors, node_names );
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
}



//
//  int cv::dnn_superres::DnnSuperResImpl::getScale()
//

JNIEXPORT jint JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_getScale_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jint JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_getScale_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::dnn_superres;
    static const char method_name[] = "dnn_1superres::getScale_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn_superres::DnnSuperResImpl>* me = (Ptr<cv::dnn_superres::DnnSuperResImpl>*) self; //TODO: check for NULL
        return (*me)->getScale();
    } catch(const std::exception &e) {
        throwJavaException(env, &e, method_name);
    } catch (...) {
        throwJavaException(env, 0, method_name);
    }
    return 0;
}



//
//  String cv::dnn_superres::DnnSuperResImpl::getAlgorithm()
//

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_getAlgorithm_10 (JNIEnv*, jclass, jlong);

JNIEXPORT jstring JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_getAlgorithm_10
  (JNIEnv* env, jclass , jlong self)
{
    using namespace cv::dnn_superres;
    static const char method_name[] = "dnn_1superres::getAlgorithm_10()";
    try {
        LOGD("%s", method_name);
        Ptr<cv::dnn_superres::DnnSuperResImpl>* me = (Ptr<cv::dnn_superres::DnnSuperResImpl>*) self; //TODO: check for NULL
        cv::String _retval_ = (*me)->getAlgorithm();
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
//  static void Ptr<cv::dnn_superres::DnnSuperResImpl>::delete( __int64 self )
//
JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_delete(JNIEnv*, jclass, jlong);

JNIEXPORT void JNICALL Java_org_opencv_dnn_1superres_DnnSuperResImpl_delete
  (JNIEnv*, jclass, jlong self)
{
    delete (Ptr<cv::dnn_superres::DnnSuperResImpl>*) self;
}



} // extern "C"

#endif // HAVE_OPENCV_DNN_SUPERRES
