#include <jni.h>
#include <string>
#include <android/log.h>
#include "andridloger.h"
//#include "andridloger.h"
using namespace std;

extern "C" JNIEXPORT jstring JNICALL
Java_com_zqg_ndklearn_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++";

    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_zqg_ndklearn_MainActivity_addNum(JNIEnv *env, jobject thiz, jint a, jint b) {
    return a + b;
}


static jint subNum(JNIEnv *env, jobject thiz, jint a, jint b) {
    return a - b;
}

static const char *className = "com/zqg/ndklearn/MainActivity";
static JNINativeMethod methods[] = {{"subNum", "(II)I", (jint *) subNum}};


JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGD("JNI_INIT");
    JNIEnv *env;
    if (vm->GetEnv((void **) (&env), JNI_VERSION_1_4) != JNI_OK) {
        return JNI_FALSE;
    }
    jclass jclass1 = env->FindClass(className);
    if (env->RegisterNatives(jclass1, methods, sizeof(methods) / sizeof(JNINativeMethod)) > 0) {
        return JNI_TRUE;
    }
    return JNI_VERSION_1_4;
}

