#ifndef __DEF_LIBPIZIOT_IF_H__
#define __DEF_LIBPIZIOT_IF_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "def_libpiziot_os_platform.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#include <ws2tcpip.h>

#elif defined(__LIBPIZIOT_OS_FREERTOS__)
#include <freertos/FreeRTOS.h>
#else

#include <sys/ioctl.h>
#include <net/if.h>

#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_IF_H__
