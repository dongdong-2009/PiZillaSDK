#ifndef __P2P_NAS_MAIN_VIEWER_H__
#define __P2P_NAS_MAIN_VIEWER_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../../include/menu_config.h"

#if defined(__ESP8266X__)
#else

#if defined(ENABLE_P2P_NAS)

#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#include "../p2p_func.h"
#include "../p2p_func_client.h"

typedef struct p2p_nas_main_viewer_thread_info_s p2p_nas_main_viewer_thread_info_t;

#include "p2p_nas_main.h"
#include "../p2p_nas_channel_client_main/ipcamera_data/p2p_nas_ipcamera_main.h"

struct p2p_nas_main_viewer_thread_info_s {
    libpiziot_os_mutex_struct_plock_t instance_mutex;
    libpiziot_os_pthread_instance_t thread_instance;
    int32_t thread_init_flag;
    char lpuuid[P2P_FUNC_UID_LENGTH_MAX + 1];
    int32_t p2p_nas_main_viewer_handle;
    libpiziot_os_aes_cbc_t login_aes;
#define P2P_NAS_CHANNEL_CLIENT_IPCAMERA_DATA_MAIN_THREAD_MAX P2P_PROTOCOL_IPCAMERA_CHANNEL_COUNT
    p2p_nas_ipcamera_main_thread_info_t *lpp2p_nas_ipcamera_main_thread_info[P2P_NAS_CHANNEL_CLIENT_IPCAMERA_DATA_MAIN_THREAD_MAX];
    int32_t update_thread_info_index;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
    p2p_nas_ipcamera_main_protocol_command_t protocol_command;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
    p2p_nas_ipcamera_main_protocol_command_t protocol_other;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
};

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_type_func_result_e p2p_nas_main_viewer_connect_device(p2p_nas_main_viewer_thread_info_t *Alpthread_info, const char *AlpUID);

    extern void p2p_nas_main_viewer_disconnect_device(p2p_nas_main_viewer_thread_info_t *Alpthread_info);

    extern libpiziot_os_type_func_result_e p2p_nas_main_viewer_initialize(p2p_nas_main_viewer_thread_info_t **Alpp_thread_info);

    extern libpiziot_os_type_func_result_e p2p_nas_main_viewer_finalize(p2p_nas_main_viewer_thread_info_t **Alpp_thread_info);

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_P2P_NAS)

#endif //defined(__ESP8266X__)

#endif //__P2P_NAS_MAIN_VIEWER_H__
