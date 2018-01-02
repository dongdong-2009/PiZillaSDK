#ifndef __DEF_LIBPIZIOT_OS_TYPE_H__
#define __DEF_LIBPIZIOT_OS_TYPE_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#if defined(__LIBPIZIOT_OS_ENDIAN_BIG__) && defined(__LIBPIZIOT_OS_ENDIAN_LITTLE__)
#error duplicate defined ENDIAN
#endif
#if !defined(__LIBPIZIOT_OS_ENDIAN_BIG__) && !defined(__LIBPIZIOT_OS_ENDIAN_LITTLE__)
#error ENDIAN not defined
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
__pragma(warning(disable:4127))
__pragma(warning(disable:4214))
__pragma(warning(disable:4201))
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
//typedef unsigned int uint32_t;
typedef unsigned __int32 uint32_t;
//typedef unsigned long long uint64_t;
typedef unsigned __int64 uint64_t;
typedef long int lont_int32_t;
#else

#include <stdint.h>

#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#elif defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_EMBEDDED__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#define SOCKET int
#define INVALID_SOCKET (int)(~0)
#define SOCKET_ERROR (-1)
#else
#error SOCKET not defined
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define T_FMT_64D "%I64u"
#elif defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_EMBEDDED__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#define T_FMT_64D "%"PRId64
#else
#error T_FMT_64D not defined
#endif

#if 0
#ifndef u64
typedef unsigned long long u64;
#endif
#ifndef s64
typedef long long s64;
#endif
#ifndef u32
typedef unsigned int u32;
#endif
#ifndef s32
typedef int s32;
#endif
#ifndef u16
typedef unsigned short u16;
#endif
#ifndef s16
typedef short s16;
#endif
#ifndef u8
typedef unsigned char u8;
#endif
#ifndef s8
typedef char s8;
#endif
#endif //0

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#if __GNUC__ >= 3
#error __GNUC__
#ifndef __packed
#define __packed __attribute__ ((packed))
#endif
#ifndef __align
#define __align(x) __attribute__ ((aligned (x)))
#endif
#else
#define __attribute__
#define __packed
#define __align(x)
#endif
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if defined(__LIBPIZIOT_OS_ENDIAN_BIG__)
#define LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(x) do{}while(x)
#else
#define LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(x) {}
#endif //defined(__LIBPIZIOT_OS_ENDIAN_BIG__)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
typedef int32_t BOOL;
typedef int socklen_t;
//#define I2C_SLAVE 0x0703
//#define I2C_SLAVE_FORCE 0x0706
#else
#if defined(__LIBPIZIOT_OS_FREERTOS__)
#define LWIP_TIMEVAL_PRIVATE 0
//typedef int socklen_t;
//#include <stddef.h>
//#include "espressif/c_types.h"
//#include "espressif/esp_libc.h"
//#include "espressif/esp_misc.h"
//#include "espressif/esp_common.h"
//#include "espressif/esp_wifi.h"
//#include "espressif/esp_sta.h"
//#include "espressif/esp_softap.h"
//#include "wifi_state_machine.h"
#else
#ifndef NULL
#error
#define NULL 0
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#if (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
#else
typedef int32_t BOOL;
#endif //!(defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
typedef uint32_t DWORD;
typedef unsigned char UCHAR;
typedef uint16_t USHORT;
typedef uint32_t ULONG;

#define _tcslen wcslen

#define LOBYTE(w) ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w) ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))
#define INFINITE 0xFFFFFFFF // Infinite timeout
#endif //__LIBPIZIOT_OS_FREERTOS__
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if defined(__LIBPIZIOT_OS_BIT_64__)
#define os_bit_int_t uint64_t
#elif defined(__LIBPIZIOT_OS_BIT_32__)
#define os_bit_int_t uint32_t
#else
#error os_bit_int_t not defined
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#if defined(__LIBPIZIOT_OS_BIT_64__)
//#define os_bit_int_t uint64_t
//#define __SQUAD_TYPE long int
//#define __UQUAD_TYPE unsigned long int
#define __SWORD_TYPE long int
//#define __UWORD_TYPE unsigned long int
#elif defined(__LIBPIZIOT_OS_BIT_32__)
//#define os_bit_int_t uint32_t
//#define __SQUAD_TYPE __quad_t
//#define __UQUAD_TYPE __u_quad_t
#define __SWORD_TYPE int32_t
//#define __UWORD_TYPE unsigned int
//#define __SLONG32_TYPE long int
//#define __ULONG32_TYPE unsigned long int
//#define __S64_TYPE __quad_t
//#define __U64_TYPE __u_quad_t
#else
#error __SWORD_TYPE not defined
#endif

#define __SSIZE_T_TYPE __SWORD_TYPE
typedef __SSIZE_T_TYPE __ssize_t;
typedef __ssize_t ssize_t;
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

//#ifndef PATH_MAX
// #if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
// #define PATH_MAX MAX_PATH
// #else
// //#define PATH_MAX PATH_MAX
/// #endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
//#endif //PATH_MAX

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define LIBPIZIOT_ICE_TYPE_PATH_MAX MAX_PATH
#else
#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else
#define LIBPIZIOT_ICE_TYPE_PATH_MAX PATH_MAX
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if defined(__LIBPIZIOT_OS_BIT_32__)
#define libpiziot_ice_os_check_point_align(x) (x & 3)
#define LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE 4
#elif defined(__LIBPIZIOT_OS_BIT_64__)
#define libpiziot_ice_os_check_point_align(x) (x & 7)
#define LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE 8
#else
#error
#endif //defined(__LIBPIZIOT_OS_BIT_64__)

typedef enum libpiziot_os_type_func_result_enum {
#if defined(EXIT_SUCCESS) && defined(EXIT_FAILURE)
    LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS = EXIT_SUCCESS,
    LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE = EXIT_FAILURE,
#else
    LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS = 0,
    LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE = 1,
#endif //defined(EXIT_SUCCESS) && defined(EXIT_FAILURE)
} libpiziot_os_type_func_result_e;

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define LIBPIZIOT_OS__FUNCTION__ ((char*)__FUNCTION__)
#else
#define LIBPIZIOT_OS__FUNCTION__ ((char*)__FUNCTION__)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

typedef void(*libpiziot_mfc_close_p)(void);

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_TYPE_H__
