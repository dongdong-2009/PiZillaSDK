#include "stdafx_lib.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#include <stdio.h>
#include <stdlib.h>

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"

//Define Windows Library

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#include "libpiziot/def_func.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#include "../../../../libpiziot_core_cms/Linux/include/menu_config.h"
//#include "../../../../libpiziot_core_cms/Linux/src/p2p/p2p_ipcamera_main/p2p_ipcamera_main.h"
//#include "../../../../libpiziot_core_cms/Linux/src/p2p/p2p_nas_main/p2p_nas_main.h"
//#include "../../../../libpiziot_core_cms/Linux/src/p2p/p2p_cms_main/p2p_cms_main.h"
//#include "../../../../libpiziot_core_cms/Linux/src/p2p/p2p_gserver_main/p2p_gserver_main.h"
//#include "../../../../libpiziot_core_cms/Linux/src/p2p/p2p_gclient_main/p2p_gclient_main.h"

//#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
//#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

#include "pizcms_main.h"

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)
#if defined(ENABLE_P2P_CMS)
int32_t cms_viewer_ipcamera_ref = -1;
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_CMS)
int32_t cms_viewer_nas_ref = -1;
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)

int32_t pizcms_main_initialize(void)
{
    int32_t rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do
    {
#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_CMS)
        {
            //char *lpUID = "A0:2E:F3:00:52:89"; //RTL8881
            char *lpUID = "20:14:07:16:01:80"; //RTL8196
            //char *lpUID = "26:9b:56:b9:cf:0e"; //RK3328
            //char *lpUID = "9E:65:F9:0E:71:30"; //MT7688
            if (lpUID != 0) {
                cms_viewer_nas_ref = libpiziot_core_p2p_cms_connect_nas(lpUID);
                if (cms_viewer_nas_ref < 0) break;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
                libpiziot_core_p2p_cms_enable_nas_channel(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER);
#else
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
                libpiziot_core_p2p_cms_enable_nas_channel(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            }
        }
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)
#if defined(ENABLE_P2P_CMS)
        {
            char *lpUID = "00:12:15:5A:40:2B"; //HI3518E
            //char *lpUID = "00:12:16:81:CC:EA"; //HI3518EV2
            if (lpUID != 0) {
                cms_viewer_ipcamera_ref = libpiziot_core_p2p_cms_connect_ipcamera(lpUID);
                if (cms_viewer_ipcamera_ref < 0) break;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
                libpiziot_core_p2p_cms_enable_ipcamera_channel(cms_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER);
#else
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
                libpiziot_core_p2p_cms_enable_ipcamera_channel(cms_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            }
        }
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)

        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

int32_t pizcms_main_finalize(void)
{
    int32_t rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do
    {
#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)
#if defined(ENABLE_P2P_CMS)
        if (cms_viewer_ipcamera_ref != -1) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            libpiziot_core_p2p_cms_disable_ipcamera_channel(cms_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER);
#else
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
            libpiziot_core_p2p_cms_disable_ipcamera_channel(cms_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            libpiziot_core_p2p_cms_disconnect_ipcamera(cms_viewer_ipcamera_ref);
            cms_viewer_ipcamera_ref = -1;
        }
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_CMS)
        if (cms_viewer_nas_ref != -1) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            libpiziot_core_p2p_cms_disable_nas_channel(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER);
#else
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
            libpiziot_core_p2p_cms_disable_nas_channel(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            libpiziot_core_p2p_cms_disconnect_nas(cms_viewer_nas_ref);
            cms_viewer_nas_ref = -1;
        }
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)

        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}
