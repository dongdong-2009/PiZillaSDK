#ifndef __DEF_LINUX_KERNEL_FILE_H__
#define __DEF_LINUX_KERNEL_FILE_H__

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#include "../def_libpiziot_os_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern int ice_kernel_open(const char* __file, int __oflag, ...);
    extern int ice_kernel_close(int __fd);
    extern long int ice_kernel_read(int __fd, void* __buf, long unsigned int __nbytes);
    extern long int ice_kernel_write(int __fd, const void* __buf, long unsigned int __n);

#ifdef __cplusplus
}
#endif

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#endif //__DEF_LINUX_KERNEL_FILE_H__
