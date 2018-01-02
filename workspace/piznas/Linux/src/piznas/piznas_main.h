#ifndef __PIZTEST_MAIN_H__
#define __PIZTEST_MAIN_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#include "libpiziot/def_piznas.h"

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#define ENABLE_SAMPLE_CODE_NAS_AND_CMS

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)
#if defined(ENABLE_P2P_NAS)
    extern int32_t nas_viewer_ipcamera_ref;
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_NAS)
    extern int32_t nas_device_ref;
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)

    extern int32_t piznas_main_initialize(void);

    extern int32_t piznas_main_finalize(void);

#ifdef __cplusplus
}
#endif

#endif //__PIZTEST_MAIN_H__
