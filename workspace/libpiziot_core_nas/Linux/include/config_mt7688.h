#ifndef __CONFIG_MT7688_H__
#define __CONFIG_MT7688_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#define ENABLE_P2P_LIB
//#define ENABLE_AVI_LIB

//#define ENABLE_STREAM_IN
#define ENABLE_STREAM_OUT

#if defined(ENABLE_STREAM_OUT)
//#define ENABLE_RTSP_LIB
#endif //defined(ENABLE_STREAM_OUT)

#if defined(ENABLE_P2P_LIB)
#define ENABLE_P2P_NAS
#endif //defined(ENABLE_P2P_LIB)

#include "config_mfc_gui.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define PLATFORM_PATH_ROOT ""
#elif defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#define PLATFORM_PATH_ROOT ""
#else
#define PLATFORM_PATH_ROOT ""
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#define BASE_SDA1 PLATFORM_PATH_ROOT"sda1/"
#define BASE_SDB1 PLATFORM_PATH_ROOT"sdb1/"

#endif //__CONFIG_MT7688_H__
