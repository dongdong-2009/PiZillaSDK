#ifndef __DEF_LIBPIZIOT_OS_TIME_H__
#define __DEF_LIBPIZIOT_OS_TIME_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#include "def_libpiziot_os_type.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#include <time.h>
#else
#include <time.h>
#include <sys/time.h>
#endif

#include "def_libpiziot_os_windows.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    extern int gettimeofday(struct timeval* __tv, void* __tz);
    extern struct tm *localtime_r(const time_t *timep, struct tm *result);
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#else
    extern unsigned long GetTickCount(void);
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

    extern struct timeval libpiziot_os_time_get_pass(struct timeval *Alpbegin);

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_TIME_H__
