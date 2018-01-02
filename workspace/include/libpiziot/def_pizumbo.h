#ifndef __DEF_PIZUMBO_H__
#define __DEF_PIZUMBO_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "libpiziot_os/def_libpiziot_os_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern int32_t pizumbo_main_enable_extra_lib(void);
    extern int32_t pizumbo_main_initialize(void);
    extern int32_t pizumbo_main_finalize(void);
    extern int32_t pizumbo_main_idle_per_1000ms(void);

#ifdef __cplusplus
}
#endif

#endif //__DEF_PIZUMBO_H__
