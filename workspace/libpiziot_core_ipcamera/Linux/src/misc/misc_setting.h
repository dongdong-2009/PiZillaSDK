#ifndef __MISC_SETTING_H__
#define __MISC_SETTING_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "../../include/menu_config.h"

//#include "../../../piztest/src/piztest_setting.h"
//#include "../../../piztest/src/Common/API_IceBase.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern void misc_setting_iptables_enable(void);

    extern void misc_setting_iptables_disable(void);

    extern void misc_setting_cpu_stat(void);

#ifdef __cplusplus
}
#endif

#endif //__MISC_SETTING_H__
