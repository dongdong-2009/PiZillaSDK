#ifndef __DEF_LINUX_KERNEL_TYPE_H__
#define __DEF_LINUX_KERNEL_TYPE_H__

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#include "../def_libpiziot_os_type.h"

#define __init
#define __exit
#define __user
#define ICE_STATIC
#define ICE_INLINE
#define printk TRACEA
#define KERN_ERR
#define MODULE_AUTHOR(x)
#define MODULE_LICENSE(x)
#define MODULE_DESCRIPTION(x)

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#endif //__DEF_LINUX_KERNEL_TYPE_H__
