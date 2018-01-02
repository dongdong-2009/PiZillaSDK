#ifndef __P2P_FUNC_H__
#define __P2P_FUNC_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../include/menu_config.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_HTSERVER) || defined(ENABLE_P2P_UIDSERVER) || defined(ENABLE_P2P_RELAY) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

#define SAMPLE_CODE_P2P_SERVER_PORT_DEFAULT 12000
#define SAMPLE_CODE_P2P_RELAY_PORT_DEFAULT 13000

#define SAMPLE_CODE_ENABLE_CUSTOMIZE_CALLBACK

//#define SAMPLE_CODE_HTSERVER_LOCALHOST "localhost"
#define SAMPLE_CODE_HTSERVER_PIZILLA_ORG "168.63.211.125"

#define SAMPLE_CODE_P2P_SERVER_ADDR (SAMPLE_CODE_HTSERVER_PIZILLA_ORG)

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_HTSERVER) || defined(ENABLE_P2P_UIDSERVER) || defined(ENABLE_P2P_RELAY) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

#endif //__P2P_FUNC_H__
