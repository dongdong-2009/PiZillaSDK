#include "stdafx_lib.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#include <stdio.h>
#include <stdlib.h>

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"

//Define Windows Library

//#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
//#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
//#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#include "libpiziot/def_func.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#include "../../../../libpiziot_core_nas/Linux/include/menu_config.h"
//#include "../../../../libpiziot_core_nas/Linux/src/p2p/p2p_nas_main/p2p_nas_main.h"

#include "piznas_main.h"

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS) || defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)
#if defined(ENABLE_P2P_IPCAMERA)
int32_t camera_device_ref = -1;
#endif //defined(ENABLE_P2P_IPCAMERA)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS) || defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)
#if defined(ENABLE_P2P_NAS)
int32_t nas_viewer_ipcamera_ref = -1;
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_NAS)
int32_t nas_device_ref = -1;
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)

#if defined(ENABLE_SAMPLE_CODE_GSERVER_AND_GCLIENT)
#if defined(ENABLE_P2P_GSERVER)
int32_t gserver_device_ref = -1;
#endif //defined(ENABLE_P2P_GSERVER)
#endif //defined(ENABLE_SAMPLE_CODE_GSERVER_AND_GCLIENT)

#if defined(ENABLE_SAMPLE_CODE_GSERVER_AND_GCLIENT)
#if defined(ENABLE_P2P_GCLIENT)
int32_t gclient_viewer_gserver_ref = -1;
#endif //defined(ENABLE_P2P_GCLIENT)
#endif //defined(ENABLE_SAMPLE_CODE_GSERVER_AND_GCLIENT)

int32_t piznas_main_initialize(void)
{
    int32_t rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do
    {
#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)
#if defined(ENABLE_P2P_NAS)
        {
#if defined(ENABLE_P2P_IPCAMERA) && defined(ENABLE_P2P_NAS)
            //char *lpUID = "FRPU9954PXFWAHPGUHF1"; //for self test only
            char *lpUID = "DDDDDDDDDDDDDDDDDDDD"; //for self test only
#else
            char* lpUID = "00:12:15:5A:40:2B"; //HI3518E
            //char *lpUID = "00:12:16:81:CC:EA"; //HI3518EV2
#endif //defined(ENABLE_P2P_IPCAMERA) && defined(ENABLE_P2P_NAS)
            if (lpUID != 0) {
                nas_viewer_ipcamera_ref = libpiziot_core_p2p_nas_connect_ipcamera(lpUID);
                if (nas_viewer_ipcamera_ref < 0) break;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
                libpiziot_core_p2p_nas_enable_viewer_channel(nas_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER);
#else
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
                libpiziot_core_p2p_nas_enable_viewer_channel(nas_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            }
        }
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_NAS)
        {
            char *lpUID = libpiziot_core_p2p_get_nas_uid();
            if (lpUID == 0) break;
            {
                nas_device_ref = libpiziot_core_p2p_create_nas(lpUID);
                if (nas_device_ref < 0) break;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
                libpiziot_core_p2p_nas_enable_device_channel(nas_device_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER);
#else
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
                libpiziot_core_p2p_nas_enable_device_channel(nas_device_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            }
        }
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)

        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

int32_t piznas_main_finalize(void)
{
    int32_t rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do
    {
#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)
#if defined(ENABLE_P2P_NAS)
        if (nas_viewer_ipcamera_ref != -1) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            libpiziot_core_p2p_nas_disable_viewer_channel(nas_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER);
#else
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
            libpiziot_core_p2p_nas_disable_viewer_channel(nas_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            libpiziot_core_p2p_nas_disconnect_ipcamera(nas_viewer_ipcamera_ref);
            nas_viewer_ipcamera_ref = -1;
        }
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_NAS)
        if (nas_device_ref != -1) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            libpiziot_core_p2p_nas_disable_device_channel(nas_device_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER);
#else
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
            libpiziot_core_p2p_nas_disable_device_channel(nas_device_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            libpiziot_core_p2p_delete_nas(nas_device_ref);
            nas_device_ref = -1;
        }
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)

        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}
