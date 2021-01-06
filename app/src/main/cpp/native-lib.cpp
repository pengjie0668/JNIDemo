#include <jni.h>
#include <string>
#include <android/log.h>

#define LOGD(FORMAT, ...) __android_log_print(ANDROID_LOG_DEBUG,"pengjie0668",FORMAT,##__VA_ARGS__);
extern "C" JNIEXPORT jstring JNICALL
Java_com_pengjie0668_demo_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "你好 from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_pengjie0668_demo_myapplication_MainActivity_callJavaMethodTest(JNIEnv *env, jobject thiz,jstring text) {
    //通过传进来的对象找到该类
    jclass javaClass = env->GetObjectClass(thiz);
    if (javaClass == 0) {
        return;
    }
    //获取要回调的方法ID,回调java方法
    jmethodID javaMethodId = env->GetMethodID( javaClass, "callJavaMethod", "(Ljava/lang/String;)V");
    env->CallVoidMethod( thiz, javaMethodId ,text);
}