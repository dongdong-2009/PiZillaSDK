#include "stdafx.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define C Libary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

//Define Windows Library

//Define MENU_CONFIG_H Library
#include "../../include/menu_config.h"

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_HTSERVER) || defined(ENABLE_P2P_UIDSERVER) || defined(ENABLE_P2P_RELAY) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

//Define Kernel Library

//Define Static Library
//#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
//#include "libpiziot/libpiziot_os/def_libpiziot_os_time.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_file.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"

//Define this Header
#include "p2p_func.h"

//Define Other Header
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

#include "p2p_func_client.h"

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

//Define Common Library

//Define Debug Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

//Define new
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if 0
#define TRACEB TRACEA
#define ENABLE_TRACEB
#else
#define TRACEB(...) {LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);} //TRACEA
#endif

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_HTSERVER) || defined(ENABLE_P2P_UIDSERVER) || defined(ENABLE_P2P_RELAY) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
