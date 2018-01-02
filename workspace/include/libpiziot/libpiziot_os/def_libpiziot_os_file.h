#ifndef __DEF_LIBPIZIOT_OS_FILE_H__
#define __DEF_LIBPIZIOT_OS_FILE_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else

#include "def_libpiziot_os_type.h"
#include "def_libpiziot_os_mutex.h"

#define LIBPIZIOT_OS_FILE_PATH_NOT_FOUND 0
#define LIBPIZIOT_OS_FILE_PATH_EXIST 1
#define LIBPIZIOT_OS_FILE_FILE_NOT_FOUND 0
#define LIBPIZIOT_OS_FILE_FILE_EXIST 1

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_mutex_struct_plock_t libpiziot_os_file_mx_free_space;
    extern libpiziot_os_mutex_struct_plock_t libpiziot_os_file_mx_io;

    extern void libpiziot_ice_os_file_proc_sys_vm_drop_caches(void);
    extern int32_t libpiziot_ice_os_file_get_free_space(uint64_t *AlpFreeSpaceValue, char *Alppath);

    extern int32_t libpiziot_ice_os_file_is_path_exist(char *AlpPathName);
    extern int32_t libpiziot_ice_os_file_create_child_path(char *AlpPathName);
    extern FILE *libpiziot_ice_os_file_lock_fopen(char *AlpFileName, char *AlpMode);
    extern int32_t libpiziot_ice_os_file_lock_fclose(FILE *AlpFile);
    extern int32_t libpiziot_ice_os_file_lock_fcheck(char *AlpFileName);

#ifdef __cplusplus
}
#endif

#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#endif //__DEF_LIBPIZIOT_OS_FILE_H__
