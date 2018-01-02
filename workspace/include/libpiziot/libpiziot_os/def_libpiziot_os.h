#ifndef __DEF_LIBPIZIOT_OS_H__
#define __DEF_LIBPIZIOT_OS_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_debug.h"
#include "def_libpiziot_os_mutex.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
    extern libpiziot_mfc_close_p lplibpiziot_mfc_close;
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))

    extern libpiziot_os_type_func_result_e libpiziot_os_initialize(void);
    extern libpiziot_os_type_func_result_e libpiziot_os_finalize(void);

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_H__
