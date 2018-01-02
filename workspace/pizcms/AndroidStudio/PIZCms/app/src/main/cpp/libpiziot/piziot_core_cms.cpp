#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"

//Define Common Library

//Define Debug Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

//Define Static Library

//Define OtherHeader
#if defined(USE_PIZIOT_CORE_CMS)

#include "libpiziot/libpiziot_core_cms/def_libpiziot_core_cms.h"

#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

extern "C"
{

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1core_1cms_libpiziot_1core_1p2p_1cms_1connect_1ipcamera(JNIEnv *env, jclass type, jstring ConnectUID_) {
    int32_t array_index = -1;
    const char *ConnectUID = env->GetStringUTFChars(ConnectUID_, 0);
    array_index = libpiziot_core_p2p_cms_connect_ipcamera(ConnectUID);
    env->ReleaseStringUTFChars(ConnectUID_, ConnectUID);
    return array_index;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1core_1cms_libpiziot_1core_1p2p_1cms_1disconnect_1ipcamera(JNIEnv *env, jclass type, jint Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Aarray_index != -1) {
        rval = libpiziot_core_p2p_cms_disconnect_ipcamera(Aarray_index);
    }
    return ((jint) rval);
}

JNIEXPORT void JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1core_1cms_libpiziot_1core_1p2p_1cms_1enable_1ipcamera_1channel(JNIEnv *env, jclass type, jint Aarray_index, jint Achannel_id) {
    libpiziot_core_p2p_cms_enable_ipcamera_channel(Aarray_index, Achannel_id);
}

JNIEXPORT void JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1core_1cms_libpiziot_1core_1p2p_1cms_1disable_1ipcamera_1channel(JNIEnv *env, jclass type, jint Aarray_index, jint Achannel_id) {
    libpiziot_core_p2p_cms_disable_ipcamera_channel(Aarray_index, Achannel_id);
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1core_1cms_libpiziot_1core_1p2p_1cms_1connect_1nas(JNIEnv *env, jclass type, jstring ConnectUID_) {
    int32_t array_index = -1;
    const char *ConnectUID = env->GetStringUTFChars(ConnectUID_, 0);
    array_index = libpiziot_core_p2p_cms_connect_nas(ConnectUID);
    env->ReleaseStringUTFChars(ConnectUID_, ConnectUID);
    return array_index;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1core_1cms_libpiziot_1core_1p2p_1cms_1disconnect_1nas(JNIEnv *env, jclass type, jint Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Aarray_index != -1) {
        rval = libpiziot_core_p2p_cms_disconnect_nas(Aarray_index);
    }
    return ((jint) rval);
}

JNIEXPORT void JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1core_1cms_libpiziot_1core_1p2p_1cms_1enable_1nas_1channel(JNIEnv *env, jclass type, jint Aarray_index, jint Achannel_id) {
    libpiziot_core_p2p_cms_enable_nas_channel(Aarray_index, Achannel_id);
}

JNIEXPORT void JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1core_1cms_libpiziot_1core_1p2p_1cms_1disable_1nas_1channel(JNIEnv *env, jclass type, jint Aarray_index, jint Achannel_id) {
    libpiziot_core_p2p_cms_disable_nas_channel(Aarray_index, Achannel_id);
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1common_1get_1model(JNIEnv *env, jclass type, jint Aviewer_handle) {
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_common_get_model(Aviewer_handle);
    return (jint) rval;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1common_1get_1fwverp2p(JNIEnv *env, jclass type, jint Aviewer_handle) {
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_common_get_fwverp2p(Aviewer_handle);
    return (jint) rval;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1common_1set_1reboot(JNIEnv *env, jclass type, jint Aviewer_handle) {
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_common_set_reboot(Aviewer_handle);
    return (jint) rval;

}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1common_1set_1timezone(JNIEnv *env, jclass type, jint Aviewer_handle, jint Atimezone) {
    libpiziot_core_p2p_protocol_optoin_timezone_e timezone = (libpiziot_core_p2p_protocol_optoin_timezone_e) Atimezone;
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_common_set_timezone(Aviewer_handle, timezone);
    return (jint) rval;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1common_1get_1timezone(JNIEnv *env, jclass type, jint Aviewer_handle) {
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_common_get_timezone(Aviewer_handle);
    return (jint) rval;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1zigbee_1set_1lock(JNIEnv *env, jclass type, jint Aviewer_handle, jint Alock_mode) {
    libpiziot_core_p2p_protocol_optoin_yn_e lock_mode = (libpiziot_core_p2p_protocol_optoin_yn_e) Alock_mode;
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock(Aviewer_handle, lock_mode);
    return (jint) rval;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1zigbee_1get_1lock(JNIEnv *env, jclass type, jint Aviewer_handle) {
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock(Aviewer_handle);
    return (jint) rval;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1zigbee_1set_1mute(JNIEnv *env, jclass type, jint Aviewer_handle, jint Amute_mode) {
    libpiziot_core_p2p_protocol_optoin_yn_e mute_mode = (libpiziot_core_p2p_protocol_optoin_yn_e) Amute_mode;
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute(Aviewer_handle, mute_mode);
    return (jint) rval;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1zigbee_1get_1mute(JNIEnv *env, jclass type, jint Aviewer_handle) {
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute(Aviewer_handle);
    return (jint) rval;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1zigbee_1set_1callout(JNIEnv *env, jclass type, jint Aviewer_handle, jint Acallout_mode) {
    libpiziot_core_p2p_protocol_optoin_yn_e callout_mode = (libpiziot_core_p2p_protocol_optoin_yn_e) Acallout_mode;
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout(Aviewer_handle, callout_mode);
    return (jint) rval;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1p2p_1device_libpiziot_1core_1p2p_1cms_1nas_1channel_1zigbee_1get_1callout(JNIEnv *env, jclass type, jint Aviewer_handle) {
    libpiziot_os_type_func_result_e rval = libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout(Aviewer_handle);
    return (jint) rval;
}

JNIEXPORT jint JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1core_1cms_libpiziot_1core_1cms_1initialize(JNIEnv *env, jclass type) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    rval = libpiziot_core_cms_initialize();
    return (jint) rval;
}

JNIEXPORT void JNICALL
Java_com_pppiziot_www_libpiziot_jpiziot_1core_1cms_libpiziot_1core_1cms_1finalize(JNIEnv *env, jclass type) {
    libpiziot_core_cms_finalize();
}

} // extern "C"

#endif //defined(USE_PIZIOT_CORE_CMS)
