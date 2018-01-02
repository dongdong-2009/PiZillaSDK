#ifndef __DEF_LINUX_KERNEL_MISCDEVICE_H__
#define __DEF_LINUX_KERNEL_MISCDEVICE_H__

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#include "../def_libpiziot_os_type.h"
#include "def_linux_kernel_type.h"

#define MISC_DYNAMIC_MINOR 255

struct miscdevice {
    int minor;
    const char *name;
    const struct file_operations *fops;
#if defined(LIBPIZIOT_OS_ICE_TEST__)
    struct list_head list;
    struct device *parent;
    struct device *this_device;
#else
#endif //defined(LIBPIZIOT_OS_ICE_TEST__)
};

#ifdef __cplusplus
extern "C"
{
#endif

    extern int misc_register(struct miscdevice* misc);
    extern int misc_deregister(struct miscdevice *misc);

#ifdef __cplusplus
}
#endif

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#endif //__DEF_LINUX_KERNEL_MISCDEVICE_H__
