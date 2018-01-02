#ifndef __CONFIG_HI3518E_H__
#define __CONFIG_HI3518E_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#define ENABLE_P2P_LIB
//#define ENABLE_AVI_LIB

#define ENABLE_STREAM_IN
#define ENABLE_STREAM_OUT

#define ENABLE_HI3518E_V1

#if defined(ENABLE_STREAM_OUT)
#define ENABLE_RTSP_LIB
#endif //defined(ENABLE_STREAM_OUT)

#if defined(ENABLE_P2P_LIB)
#define ENABLE_P2P_IPCAMERA
//#define ENABLE_P2P_NAS
#endif //defined(ENABLE_P2P_LIB)

#include "config_mfc_gui.h"

#define BASE_SDA1 "/mnt/mtd/"
#define BASE_SDB1 "/mnt/sd/"

#endif //__CONFIG_HI3518E_H__
