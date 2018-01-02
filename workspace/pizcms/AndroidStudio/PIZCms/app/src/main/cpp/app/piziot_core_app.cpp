#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

//Define Common Library

//Define Static Library
//#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"

//Define OtherHeader
//#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"
//#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_clientsdk.h"

#include "piziot_core_app.h"

//Define Debug Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

extern "C" {

JNIEXPORT jstring

JNICALL
Java_com_pppiziot_www_pizcms_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JavaVM *lppiziot_core_app_jvm = 0;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *AlpJVM, void *Alpreserved) {
    jint rval = -1;
    do {
        JNIEnv *env = NULL;
        if (AlpJVM->GetEnv((void **) &env, LIBPIZIOT_JNI_VERSION) == JNI_OK) {
            lppiziot_core_app_jvm = AlpJVM;
            rval = LIBPIZIOT_JNI_VERSION;
        } else {
            break;
        }
    } while (false);
    return rval;
}

} //extern "C"
