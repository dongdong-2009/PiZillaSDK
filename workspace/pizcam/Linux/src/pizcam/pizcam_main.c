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

#include "../../../../libpiziot_core_ipcamera/Linux/include/menu_config.h"
//#include "../../../../libpiziot_core_ipcamera/Linux/src/p2p/p2p_ipcamera_main/p2p_ipcamera_main.h"
//#include "../../../../libpiziot_core_ipcamera/Linux/src/p2p/p2p_ipcamera_main/p2p_ipcamera_main_device.h"

#include "pizcam_main.h"

#if defined(ENABLE_P2P_IPCAMERA)
int32_t camera_device_ref = -1;
#endif //defined(ENABLE_P2P_IPCAMERA)

int32_t pizcam_main_initialize(void)
{
    int32_t rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do
    {
#if defined(ENABLE_P2P_IPCAMERA)
        char *lpUID = libpiziot_core_p2p_get_ipcamera_uid();
        if (lpUID == 0) break;
        camera_device_ref = libpiziot_core_p2p_create_ipcamera(lpUID);
        if (camera_device_ref < 0) break;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
        libpiziot_core_p2p_ipcamera_enable_device_channel(camera_device_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_IPCAMERA)
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

int32_t pizcam_main_finalize(void)
{
    int32_t rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do
    {
#if defined(ENABLE_P2P_IPCAMERA)
        if (camera_device_ref != -1) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
            libpiziot_core_p2p_ipcamera_disable_device_channel(camera_device_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
            libpiziot_core_p2p_delete_ipcamera(camera_device_ref);
            camera_device_ref = -1;
        }
#endif //defined(ENABLE_P2P_IPCAMERA)
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}
