#ifndef __PIZIOT_CORE_NVR_H__
#define __PIZIOT_CORE_NVR_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
//#include "ice/ice_asm_signal.h"
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

//Define MENU_CONFIG_H Library
#include "../../include/menu_config.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern int32_t libpiziot_core_cms_need_reload_flag;
    extern int32_t libpiziot_core_cms_need_power_flag;
    extern int32_t libpiziot_core_cms_need_reset_flag;

#ifdef __cplusplus
}
#endif

#endif //__PIZIOT_CORE_NVR_H__
