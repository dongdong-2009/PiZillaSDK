#ifndef __DEF_LIBPIZBSP_HI3518E_H__
#define __DEF_LIBPIZBSP_HI3518E_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "../../libpiziot_os/def_libpiziot_os_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern void libpizbsp_hi3518e_gpio_main_set_ircut(void);

    extern libpiziot_os_type_func_result_e libpizbsp_hi3518e_gpio_main_initialize(void);
    extern libpiziot_os_type_func_result_e libpizbsp_hi3518e_gpio_main_finalize(void);

    libpiziot_os_type_func_result_e libpizbsp_hi3518e_initialize(void);
    void libpizbsp_hi3518e_finalize(void);

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZBSP_HI3518E_H__
