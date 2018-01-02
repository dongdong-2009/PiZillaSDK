#ifndef __DEF_LIBPIZIOT_FILE_AVI_H__
#define __DEF_LIBPIZIOT_FILE_AVI_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_type_func_result_e libpiziot_file_avi_initialize(void);
    extern void libpiziot_file_avi_finalize(void);

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_FILE_AVI_H__
