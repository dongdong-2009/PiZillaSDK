#ifndef __DEF_LINUX_KERNEL_IOCTL_H__
#define __DEF_LINUX_KERNEL_IOCTL_H__

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#include "../def_libpiziot_os_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern int ice_kernel_ioctl(int __fd, unsigned long int __request, ...);

#ifdef __cplusplus
}
#endif

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#endif //__DEF_LINUX_KERNEL_IOCTL_H__
