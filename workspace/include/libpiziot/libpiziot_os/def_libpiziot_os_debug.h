#ifndef __DEF_LIBPIZIOT_OS_DEBUG_H__
#define __DEF_LIBPIZIOT_OS_DEBUG_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#include <tchar.h>
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#include "def_libpiziot_os_type.h"
#include "def_libpiziot_os_mutex.h"

#define USE_INT_VALUE_CHECK

#define LIBPIZIOT_ICE_DEBUG_USLEEP_1_SECCOND 1000000
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_FREERTOS__)
#ifdef __cplusplus
extern "C"
{
#endif
    extern void libpiziot_os_debug_usleep(int waitTime, char* funcname, int line);
#ifdef __cplusplus
}
#endif
#define usleep(x) libpiziot_os_debug_usleep(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)
//#define udelay(x) libpiziot_os_debug_usleep(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_debug_usleep_1sec() libpiziot_os_debug_usleep(LIBPIZIOT_ICE_DEBUG_USLEEP_1_SECCOND, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#else

#include <unistd.h>

#define libpiziot_os_debug_usleep_1sec() usleep(LIBPIZIOT_ICE_DEBUG_USLEEP_1_SECCOND)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_FREERTOS__)

//#define TRACEA libpiziot_os_debug_thread_safe_printfA("%s:%d\n", LIBPIZIOT_OS__FUNCTION__, __LINE__);libpiziot_os_debug_thread_safe_printfA
//#define TRACEA libpiziot_os_debug_thread_safe_printfW("%s:%d\n", LIBPIZIOT_OS__FUNCTION__, __LINE__);libpiziot_os_debug_thread_safe_printfW
#if defined(__LIBPIZIOT_OS_FREERTOS__)
#define TRACEA libpiziot_os_debug_thread_safe_printfA
#define TRACEN libpiziot_os_debug_thread_non_safe_printf
#define TRACE_ERROR libpiziot_os_debug_thread_safe_printfA
#define TRACE_SUCCEED libpiziot_os_debug_thread_safe_printfA
#define FTRACEA libpiziot_os_debug_thread_safe_printfA
#define FTRACEN libpiziot_os_debug_thread_non_safe_printf
#else
#define TRACEA libpiziot_os_debug_thread_safe_printfA
#define TRACEN libpiziot_os_debug_thread_non_safe_printf
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define TRACEW libpiziot_os_debug_thread_safe_printfW
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#define TRACE_ERROR libpiziot_os_debug_thread_safe_printfA
#define TRACE_SUCCEED libpiziot_os_debug_thread_safe_printfA
#define FTRACEA libpiziot_os_debug_thread_safe_printfA
#define FTRACEN libpiziot_os_debug_thread_non_safe_printf
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#define VDBGPRINT
#define dev_err(x, str) TRACEA(str)
#define enter_panic(x) while(1){TRACEA("enter_panic\n");usleep(1000000);}
#define print_debug()

#ifdef USE_INT_VALUE_CHECK

extern int libpiziot_os_debug_func_check_int_value_by_address(unsigned int AiValue, void *AlpValueAddr, const char *file_name, unsigned int line);

#define libpiziot_os_debug_check_int_value_by_address(Value, lpValueAddr) libpiziot_os_debug_func_check_int_value_by_address(Value,lpValueAddr,__FILE__,__LINE__)

#define libpiziot_os_debug_check_align_32bit_address(x) (((os_bit_int_t)(&(x))) - ((((os_bit_int_t)(&(x))) >> 2) << 2))
#define libpiziot_os_debug_check_align_32bit_value(x) (((os_bit_int_t)(x)) - ((((os_bit_int_t)(x)) >> 2) << 2))
//#define libpiziot_os_debug_check_align_64bit_address(x) (((os_bit_int_t)(&(x))) - ((((os_bit_int_t)(&(x))) >> 3) << 3))
//#define libpiziot_os_debug_check_align_64bit_value(x) (((os_bit_int_t)(x)) - ((((os_bit_int_t)(x)) >> 3) << 3))

#endif

#ifdef __cplusplus
extern "C"
{
#endif
    extern libpiziot_os_mutex_struct_plock_t libpiziot_os_debug_mx;

    extern void libpiziot_os_debug_thread_safe_printfA(const char *format, ...);
    extern void libpiziot_os_debug_thread_non_safe_printf(const char *format, ...);

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    extern void libpiziot_os_debug_thread_safe_printfW(const TCHAR *format, ...);
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_DEBUG_H__
