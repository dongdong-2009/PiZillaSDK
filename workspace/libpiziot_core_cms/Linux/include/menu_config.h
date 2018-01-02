#ifndef __MENU_CONFIG_H__
#define __MENU_CONFIG_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#if defined(_WIN32) || defined(_WIN64)
#if !defined(__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__)
#error
#endif //!defined(__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__)
#endif //defined(_WIN32) || defined(_WIN64)

#if defined(__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__)
#include "config_x86.h"
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8197__)
#include "config_rtl8197.h"
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3520D__)
#include "config_hi3520d.h"
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518E__)
#include "config_hi3518e.h"
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518EV2__)
#include "config_hi3518ev2.h"
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_BCM28XX_RASPBERRY__)
#include "config_bcm28xx.h"
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8881__)
#include "config_rtl8881.h"
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8196__)
#include "config_rtl8196.h"
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RK3328_ROCK64__)
#include "config_rk3328.h"
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_MT7688_LINKIT__)
#include "config_mt7688.h"
#elif defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__)
#include "config_android.h"
#elif (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
#include "config_xcode.h"
#else
#error
#endif

//#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
//    #if !defined(ENABLE_IF_INTERFACE)
//        #define ENABLE_IF_INTERFACE
//    #endif //!defined(ENABLE_IF_INTERFACE)
//#else
//    #if defined(ENABLE_IF_INTERFACE)
//    #error
//    #endif // defined(ENABLE_IF_INTERFACE)
//    #define ENABLE_IF_INTERFACE
//#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
//
//#if !defined(ENABLE_IF_INTERFACE)
//    #error
//#endif //!defined(ENABLE_IF_INTERFACE)
//
//#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
//    #define MFC_TEST_BIG_ENDIAN__
//#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
//
//#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
//#define __USE_MISC 1
//#else
//#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#endif //__MENU_CONFIG_H__
