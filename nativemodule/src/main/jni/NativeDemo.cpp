#include "cn_taoweiji_nativemodule_NativeDemo.h"
#include <android/log.h>
#include <string>
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, "tag_joyrun", __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, "tag_joyrun", __VA_ARGS__)


JNIEXPORT jint JNICALL Java_cn_taoweiji_nativemodule_NativeDemo_add(JNIEnv *, jclass, jint param1, jint param2)
{
    jint result = param1 + param2;
    //输出Logcat
    __android_log_print(ANDROID_LOG_INFO, "tag", "Hello World");
    LOGE("NativeDemo_add");
    return result;
}
JNIEXPORT void JNICALL Java_cn_taoweiji_nativemodule_NativeDemo_say(JNIEnv *env, jclass, jstring param)
{
    // std::string -> jstring
    const char *param_char = env->GetStringUTFChars(param, NULL);
    std::string str = param_char;
    LOGE(param_char);
}

JNIEXPORT jstring JNICALL Java_cn_taoweiji_nativemodule_NativeDemo_getInfo(JNIEnv *env, jclass)
{
    // jstring -> std::string
    std::string str = "Hi,I am C++.";
    jstring result =  env->NewStringUTF(str.c_str());
    return result;
}

JNIEXPORT void JNICALL Java_cn_taoweiji_nativemodule_NativeDemo_nativeToJava(JNIEnv * env, jclass, jobject obj)
{
    // 调用Java方法
    jclass cls = env->FindClass("cn/taoweiji/nativemodule/NativeDemo");
    //int subtract(int param1, int param2) -> (II)I
    jmethodID mid = env->GetMethodID(cls, "subtract", "(II)I");
    int result = (int) env->CallIntMethod(obj, mid, 10, 2);

    //常见类型转换例子
    //String getInfo();
    //-> ()Ljava/lang/String;

    //PackageInfo getPackageInfo(String packageName, int flags);
    //-> (Ljava/lang/String;I)Landroid/content/pm/PackageInfo;;


}