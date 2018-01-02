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

//Define Debug Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_pppiziot_www_libpiziot_1core_1cms_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
