#ifndef __DEF_LIBPIZIOT_OS_PLATFORM_H__
#define __DEF_LIBPIZIOT_OS_PLATFORM_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    #error __LIBPIZIOT_OS_PLATFORM_MFC__
#elif defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__)
    #error __LIBPIZIOT_OS_PLATFORM_XCODE_IOS__
#elif defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__)
    #error __LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__
#elif defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__)
    #error __LIBPIZIOT_OS_PLATFORM_ANDROID__
#elif defined(__LIBPIZIOT_OS_PLATFORM_LINUX_EMBEDDED__)
    #error __LIBPIZIOT_OS_PLATFORM_LINUX_EMBEDDED__
#endif

#if defined(_WIN32) || defined(_WIN64)
    #define __LIBPIZIOT_OS_PLATFORM_MFC__
#elif defined(__APPLE__) && defined(__MACH__)
    #include "TargetConditionals.h"
    #if TARGET_OS_IPHONE
        #define __LIBPIZIOT_OS_PLATFORM_XCODE_IOS__
    #elif TARGET_OS_OSX
        #define __LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__
    #else
        #error unknown apple os
    #endif
#elif defined(__ANDROID__)
    #define __LIBPIZIOT_OS_PLATFORM_ANDROID__
#elif defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#elif defined(__linux__)
    #define __LIBPIZIOT_OS_PLATFORM_LINUX_EMBEDDED__
#elif defined(__ESP8266X__)
    #define __LIBPIZIOT_OS_PLATFORM_LINUX_EMBEDDED__
#else
    #error unknown LIBPIZIOT_OS_PLATFORM
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    #if defined(_M_IX86)
        #define __LIBPIZIOT_OS_ARCH_I686__
    #elif defined(_WIN64)
        #define __LIBPIZIOT_OS_ARCH_X86_64__
#else
        #error unknown LIBPIZIOT_OS_ARCH
    #endif
#elif defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_EMBEDDED__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
    #if defined(__mips64__)
        #define __LIBPIZIOT_OS_ARCH_MIPS64__
    #elif defined(__mips__)
        #define __LIBPIZIOT_OS_ARCH_MIPS__
    #elif defined(__i386__)
        #define __LIBPIZIOT_OS_ARCH_i386__
    #elif defined(__x86_64__)
        #define __LIBPIZIOT_OS_ARCH_X86_64__
    #elif defined(__i686__)
        #define __LIBPIZIOT_OS_ARCH_I686__
    #elif defined(__aarch64__)
        #define __LIBPIZIOT_OS_ARCH_AARCH64__
    #elif defined(__ARM_ARCH_2__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_2__
    #elif defined(__ARM_ARCH_3__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_3__
    #elif defined(__ARM_ARCH_3M__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_3M__
    #elif defined(__ARM_ARCH_4T__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_4T__
    #elif defined(__TARGET_ARM_4T)
    #error __LIBPIZIOT_OS_ARCH__TARGET_ARM_4T
    #elif defined(__ARM_ARCH_5__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_5__
    #elif defined(__ARM_ARCH_5E__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_5E__
    #elif defined(__ARM_ARCH_5T__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_5T__
    #elif defined(__ARM_ARCH_5TE__)
        #define __LIBPIZIOT_OS_ARCH_ARM_ARCH_5TE__
    #elif defined(__ARM_ARCH_5TEJ__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_5TEJ__
    #elif defined(__ARM_ARCH_6__)
        #define __LIBPIZIOT_OS_ARCH_ARM_ARCH_6__
    #elif defined(__ARM_ARCH_6J__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_6J__
    #elif defined(__ARM_ARCH_6K__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_6K__
    #elif defined(__ARM_ARCH_6Z__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_6Z__
    #elif defined(__ARM_ARCH_6ZK__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_6ZK__
    #elif defined(__ARM_ARCH_6T2__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_6T2__
    #elif defined(__ARM_ARCH_7__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_7__
    #elif defined(__ARM_ARCH_7A__)
        #define __LIBPIZIOT_OS_ARCH_ARM_ARCH_7A__
    #elif defined(__ARM_ARCH_7R__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_7R__
    #elif defined(__ARM_ARCH_7M__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_7M__
    #elif defined(__ARM_ARCH_7S__)
    #error __LIBPIZIOT_OS_ARCH_ARM_ARCH_7S__
    #elif defined(__ESP8266X__)
        #define __LIBPIZIOT_OS_ARCH_ESP8266__
        #define __LIBPIZIOT_OS_FREERTOS__
    #else
        #error unknown LIBPIZIOT_OS_ARCH
    #endif
#else
    #error unknown LIBPIZIOT_OS_PLATFORM
#endif

#if defined(__LIBPIZIOT_OS_ENDIAN_BIG__)
    #error __LIBPIZIOT_OS_ENDIAN_BIG__
#elif defined(__LIBPIZIOT_OS_ENDIAN_LITTLE__)
    #error __LIBPIZIOT_OS_ENDIAN_LITTLE__
#endif

#if defined(__LIBPIZIOT_OS_ARCH_MIPS64__)
    #define __LIBPIZIOT_OS_ENDIAN_BIG__
#elif defined(__LIBPIZIOT_OS_ARCH_MIPS__)
    #if defined(__LIBPIZIOT_OS_PLATFORM_LINUX_OPENWRT_MT7688_LITTLE__)
        #define __LIBPIZIOT_OS_ENDIAN_LITTLE__
    #else
        #define __LIBPIZIOT_OS_ENDIAN_BIG__
    #endif
#elif defined(__LIBPIZIOT_OS_ARCH_i386__)
    #define __LIBPIZIOT_OS_ENDIAN_LITTLE__
#elif defined(__LIBPIZIOT_OS_ARCH_X86_64__)
    #define __LIBPIZIOT_OS_ENDIAN_LITTLE__
#elif defined(__LIBPIZIOT_OS_ARCH_I686__)
    #define __LIBPIZIOT_OS_ENDIAN_LITTLE__
#elif defined(__LIBPIZIOT_OS_ARCH_AARCH64__)
    #define __LIBPIZIOT_OS_ENDIAN_LITTLE__
#elif defined(__LIBPIZIOT_OS_ARCH_ARM_ARCH_7A__)
    #define __LIBPIZIOT_OS_ENDIAN_LITTLE__
#elif defined(__LIBPIZIOT_OS_ARCH_ARM_ARCH_5TE__)
    #define __LIBPIZIOT_OS_ENDIAN_LITTLE__
#elif defined(__LIBPIZIOT_OS_ARCH_ARM_ARCH_6__)
    #define __LIBPIZIOT_OS_ENDIAN_LITTLE__
#elif defined(__LIBPIZIOT_OS_ARCH_ESP8266__)
    #define __LIBPIZIOT_OS_ENDIAN_LITTLE__
#else
    #unknown LIBPIZIOT_OS_ENDIAN
#endif

#if defined(__LIBPIZIOT_OS_ENDIAN_BIG__) && defined(__LIBPIZIOT_OS_ENDIAN_LITTLE__)
    #error duplicate defined LIBPIZIOT_OS_ENDIAN
#endif
#if !defined(__LIBPIZIOT_OS_ENDIAN_BIG__) && !defined(__LIBPIZIOT_OS_ENDIAN_LITTLE__)
    #error LIBPIZIOT_OS_ENDIAN not defined
#endif

#if defined(__LIBPIZIOT_OS_BIT_64__)
    #error __LIBPIZIOT_OS_BIT_64__
#elif defined(__LIBPIZIOT_OS_BIT_32__)
    #error __LIBPIZIOT_OS_BIT_32__
#endif

#if defined(__LIBPIZIOT_OS_ARCH_MIPS64__)
    #define __LIBPIZIOT_OS_BIT_64__
#elif defined(__LIBPIZIOT_OS_ARCH_MIPS__)
    #define __LIBPIZIOT_OS_BIT_32__
#elif defined(__LIBPIZIOT_OS_ARCH_i386__)
    #define __LIBPIZIOT_OS_BIT_32__
#elif defined(__LIBPIZIOT_OS_ARCH_X86_64__)
    #define __LIBPIZIOT_OS_BIT_64__
#elif defined(__LIBPIZIOT_OS_ARCH_I686__)
    #define __LIBPIZIOT_OS_BIT_32__
#elif defined(__LIBPIZIOT_OS_ARCH_AARCH64__)
    #define __LIBPIZIOT_OS_BIT_64__
#elif defined(__LIBPIZIOT_OS_ARCH_ARM_ARCH_7A__)
    #define __LIBPIZIOT_OS_BIT_32__
#elif defined(__LIBPIZIOT_OS_ARCH_ARM_ARCH_5TE__)
    #define __LIBPIZIOT_OS_BIT_32__
#elif defined(__LIBPIZIOT_OS_ARCH_ARM_ARCH_6__)
    #define __LIBPIZIOT_OS_BIT_32__
#elif defined(__LIBPIZIOT_OS_ARCH_ESP8266__)
    #define __LIBPIZIOT_OS_BIT_32__
#else
    #error unknown LIBPIZIOT_OS_BIT
#endif

#if defined(__LIBPIZIOT_OS_BIT_32__) && defined(__LIBPIZIOT_OS_BIT_64__)
#error duplicate defined LIBPIZIOT_OS_BIT
#endif
#if !defined(__LIBPIZIOT_OS_BIT_32__) && !defined(__LIBPIZIOT_OS_BIT_64__)
#error LIBPIZIOT_OS_BIT not defined
#endif

#endif //__DEF_LIBPIZIOT_OS_PLATFORM_H__
