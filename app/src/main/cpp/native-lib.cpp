#include <jni.h>
#include <string>

#include <assert.h>

#define JNIREG_CLASS "com/awaitu/dongtaijini/JniClient"
extern "C"{

jint add_int(JNIEnv* env, jobject jobj, jint num1, jint num2){
    return num1 + num2;
}

/**
* 方法对应表
*/
static JNINativeMethod gMethods[] = {
//        {"getStr", "()Ljava/lang/String;", (void*)get_str},
        {"addInt", "(II)I", (void*)add_int},
};

/*
* 为某一个类注册本地方法
*/
static int registerNativeMethods(JNIEnv* env
        , const char* className
        , JNINativeMethod* gMethods, int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if(env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}
/*
* 为所有类注册本地方法
*/
static int registerNatives(JNIEnv* env) {
    return registerNativeMethods(env, JNIREG_CLASS, gMethods,
                                 sizeof(gMethods) / sizeof(gMethods[0]));
}
/*
* System.loadLibrary("lib")时调用
* 如果成功返回JNI版本, 失败返回-1
*/
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env = NULL;
    jint result = -1;
    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);
    if (!registerNatives(env)) {//注册
        return -1;
    }
    //成功
    result = JNI_VERSION_1_4;
    return result;
}
};

