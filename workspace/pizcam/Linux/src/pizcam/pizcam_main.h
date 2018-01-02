#ifndef __PIZCAM_MAIN_H__
#define __PIZCAM_MAIN_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#include "libpiziot/def_pizcam.h"

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(ENABLE_P2P_IPCAMERA)
    extern int32_t camera_device_ref;
#endif //defined(ENABLE_P2P_IPCAMERA)

    extern int32_t pizcam_main_initialize(void);

    extern int32_t pizcam_main_finalize(void);

#ifdef __cplusplus
}
#endif

#endif //__PIZCAM_MAIN_H__
