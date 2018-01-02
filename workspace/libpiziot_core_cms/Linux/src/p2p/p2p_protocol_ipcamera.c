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

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

//Define Kernel Library

//Define Static Library
//#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
//#include "libpiziot/libpiziot_os/def_libpiziot_os_time.h"
//#include "libpiziot/libpiziot_os/def_libpiziot_os_file.h"
//#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"

//Define this Header
#include "p2p_protocol_ipcamera.h"

//Define Other Header

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

int32_t p2p_protocol_ipcamera_command_device_send_data_max_size = 0;
int32_t p2p_protocol_ipcamera_command_viewer_recv_data_max_size = 0;
int32_t p2p_protocol_ipcamera_command_viewer_send_data_max_size = 0;
int32_t p2p_protocol_ipcamera_command_device_recv_data_max_size = 0;

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(__ESP8266X__)
#else

static void p2p_protocol_ipcamera_command_init_data_set_max_size(int32_t *Alpmax_struct_size, int32_t Adata_size) {
    int32_t protocol_head_len = (sizeof(libpiziot_core_p2p_protocol_command_head_t) + 0xF) & 0xFFFFFFF0;
    int32_t data_size = (Adata_size + 0xF) & 0xFFFFFFF0;
    if ((*Alpmax_struct_size) < (protocol_head_len + data_size)) {
        (*Alpmax_struct_size) = (protocol_head_len + data_size);
    }
}

#endif //defined(__ESP8266X__)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

void p2p_protocol_ipcamera_command_init_data_max_size(void) {
#if defined(__ESP8266X__)
    p2p_protocol_ipcamera_command_device_send_data_max_size = 64;
    p2p_protocol_ipcamera_command_viewer_send_data_max_size = 32;
#else
    p2p_protocol_ipcamera_command_device_send_data_max_size = LIBPIZIOT_P2P_COMMON_SEND_DATA_MAX_SIZE;
    p2p_protocol_ipcamera_command_viewer_send_data_max_size = LIBPIZIOT_P2P_COMMON_SEND_DATA_MAX_SIZE;
#endif //defined(__ESP8266X__)

#if defined(__ESP8266X__)
#else
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
    p2p_protocol_ipcamera_command_init_data_set_max_size(&p2p_protocol_ipcamera_command_viewer_send_data_max_size, sizeof(p2p_protocol_ipcamera_command_common_get_model_req_t));
    p2p_protocol_ipcamera_command_init_data_set_max_size(&p2p_protocol_ipcamera_command_viewer_send_data_max_size, sizeof(p2p_protocol_ipcamera_command_common_get_fwverp2p_req_t));
    p2p_protocol_ipcamera_command_init_data_set_max_size(&p2p_protocol_ipcamera_command_viewer_send_data_max_size, sizeof(p2p_protocol_ipcamera_command_common_set_reboot_req_t));
    p2p_protocol_ipcamera_command_init_data_set_max_size(&p2p_protocol_ipcamera_command_viewer_send_data_max_size, sizeof(p2p_protocol_ipcamera_command_common_set_timezone_req_t));
    p2p_protocol_ipcamera_command_init_data_set_max_size(&p2p_protocol_ipcamera_command_viewer_send_data_max_size, sizeof(p2p_protocol_ipcamera_command_common_get_timezone_req_t));

    p2p_protocol_ipcamera_command_init_data_set_max_size(&p2p_protocol_ipcamera_command_device_send_data_max_size, sizeof(p2p_protocol_ipcamera_command_common_get_model_resp_t));
    p2p_protocol_ipcamera_command_init_data_set_max_size(&p2p_protocol_ipcamera_command_device_send_data_max_size, sizeof(p2p_protocol_ipcamera_command_common_get_fwverp2p_resp_t));
    p2p_protocol_ipcamera_command_init_data_set_max_size(&p2p_protocol_ipcamera_command_device_send_data_max_size, sizeof(p2p_protocol_ipcamera_command_common_set_reboot_resp_t));
    p2p_protocol_ipcamera_command_init_data_set_max_size(&p2p_protocol_ipcamera_command_device_send_data_max_size, sizeof(p2p_protocol_ipcamera_command_common_set_timezone_resp_t));
    p2p_protocol_ipcamera_command_init_data_set_max_size(&p2p_protocol_ipcamera_command_device_send_data_max_size, sizeof(p2p_protocol_ipcamera_command_common_get_timezone_resp_t));
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(__ESP8266X__)

    p2p_protocol_ipcamera_command_viewer_recv_data_max_size = p2p_protocol_ipcamera_command_device_send_data_max_size;
    p2p_protocol_ipcamera_command_device_recv_data_max_size = p2p_protocol_ipcamera_command_viewer_send_data_max_size;
}

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)
