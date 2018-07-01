#include <jni.h>
#include <string>
#include <opencv/cv.hpp>

using namespace std;
using namespace cv;
extern "C"
JNIEXPORT jintArray JNICALL
Java_com_opencv_tools_Tools_ImageBlur(JNIEnv *env, jclass type, jintArray buf, jint w, jint h) {
//    jint *cbuf; cbuf = env->GetIntArrayElements(buf, false);//JNI传递int数组的方法
//    if (cbuf == NULL)
//    {
//        return 0;
//    }
//    Mat myimg(h, w, CV_8UC4, (unsigned char*) cbuf);//java中读入的图像都是4通道的，所以这里myimg声明定义为CV_8UC4,以一个数组中的数据来建立Mat
//    Mat grayimg;
//    cvtColor(myimg,grayimg,CV_BGRA2GRAY);//将4通道的彩色图转为灰度图
//    Mat pCannyImage;
//    Canny(grayimg,pCannyImage,50,150,3);//canny检测
//
//    uchar* ptr = myimg.ptr(0);//因为灰度图最终以4通道bmp形式显示，所以将得到的灰度图grayimg的数据赋值到4通道的imageData中，
//    for(int i = 0; i < w*h; i ++){
//        //得到的canny图像原本是单通道，但java中显示bmp时只能4通道或三通道，为了使显示的图像时灰度的，把canny图像的数据值赋给一个4通道的myimg
//        //对于一个int四字节，其彩色值存储方式为：BGRA
//        ptr[4*i+1] = pCannyImage.data[i];
//        ptr[4*i+2] = pCannyImage.data[i];
//        ptr[4*i+0] = pCannyImage.data[i];
//    }
//
//    //以下部分是将得到canny图像存在数组中，以数组的形式返回
//    int size = w * h;
//    jintArray result = env->NewIntArray(size);
//    env->SetIntArrayRegion(result, 0, size, cbuf);
//    env->ReleaseIntArrayElements(buf, cbuf, 0);
//    return result;


    jboolean ptfalse = false;
    jint *srcBuf = env->GetIntArrayElements(buf, &ptfalse);
    if (srcBuf == NULL) {
        return 0;
    }
    int size = w * h;
    Mat srcImage(h, w, CV_8UC4, (unsigned char *) srcBuf);
    Mat grayImage;
    cvtColor(srcImage, grayImage, COLOR_BGRA2GRAY);
    cvtColor(grayImage, srcImage, COLOR_GRAY2BGRA);
    jintArray result = env->NewIntArray(size);
    env->SetIntArrayRegion(result, 0, size, srcBuf);
    env->ReleaseIntArrayElements(buf, srcBuf, 0);
    return result;
}extern "C"
JNIEXPORT void JNICALL
Java_com_opencv_tools_Tools_changeValue(JNIEnv *env, jclass type) {
    jfieldID id = env->GetStaticFieldID(type, "Tag", "Ljava/lang/String;");
    jstring jstr = (jstring) env->GetStaticObjectField(type, id);
    const char *chars = env->GetStringUTFChars(jstr, NULL);
    char c[20] = " wang";
    strcat(c, chars);
    jstring res = env->NewStringUTF(c);
    env->SetStaticObjectField(type, id, res);
}extern "C"
JNIEXPORT void JNICALL
Java_com_opencv_tools_Tools_changeValue2(JNIEnv *env, jobject instance) {
    jclass jclaz = env->GetObjectClass(instance);
    jfieldID id = env->GetFieldID(jclaz, "COUNT", "I");
    jint i = env->GetIntField(instance, id);
    ++i;
    env->SetIntField(instance, id, i);
}extern "C"
JNIEXPORT jint JNICALL
Java_com_opencv_tools_Tools_callRandomNumber(JNIEnv *env, jobject instance) {
    jclass jclz = env->GetObjectClass(instance);
    jmethodID jmethodId = env->GetMethodID(jclz, "randomNumber", "()I");
    jint i = env->CallIntMethod(instance, jmethodId);
    printf("i-->%d", i);
    return i;
}extern "C"
JNIEXPORT jstring JNICALL
Java_com_opencv_tools_Tools_callStaticUUID(JNIEnv *env, jclass jclz) {
    jmethodID id = env->GetStaticMethodID(jclz, "getUUID", "()Ljava/lang/String;");
    jstring jstr = (jstring) env->CallStaticObjectMethod(jclz, id);
    return jstr;
}extern "C"
JNIEXPORT jobject JNICALL
Java_com_opencv_tools_Tools_printMat(JNIEnv *env, jobject instance, jobject m) {
//    jclass jclz = env->GetObjectClass(m);
//    jfieldID pixelsId = env->GetFieldID(jclz, "pixels", "[I");
//    jfieldID wId = env->GetFieldID(jclz, "w", "I");
//    jfieldID hId = env->GetFieldID(jclz, "h", "I");
//    env->SetIntField(m, wId, 200);
//    env->SetIntField(m, hId, 400);
//    env->SetIntArrayRegion(m, pixelsId, 200);
    return m;
}