#ifndef __DEF_LIBPIZIOT_OS_MMAP_H__
#define __DEF_LIBPIZIOT_OS_MMAP_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else

#include "def_libpiziot_os_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern void libpiziot_os_mmap_free(void);

#ifdef __cplusplus
}
#endif

#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#endif //__DEF_LIBPIZIOT_OS_MMAP_H__
