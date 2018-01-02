#ifndef __DEF_LIBPIZIOT_CORE_GSERVER_H__
#define __DEF_LIBPIZIOT_CORE_GSERVER_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
typedef long(__stdcall *libpiziot_core_gserver_event_p)(unsigned int AnIOCtrlType, unsigned char* AlpChar, uint32_t Asize);
#else
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    extern libpiziot_core_gserver_event_p lplibpiziot_core_gserver_event;
#else
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

    extern libpiziot_os_type_func_result_e libpiziot_core_gserver_initialize(void);
    extern void libpiziot_core_gserver_finalize(void);
    extern void libpiziot_core_gserver_sigterm_handler(int sig);
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
#else
    extern void libpiziot_core_gserver_event_loop(void);
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_CORE_GSERVER_H__
