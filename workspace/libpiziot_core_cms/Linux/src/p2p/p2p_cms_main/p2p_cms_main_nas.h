#ifndef __P2P_CMS_MAIN_NAS_H__
#define __P2P_CMS_MAIN_NAS_H__

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

#if defined(ENABLE_P2P_CMS)

#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#include "../p2p_func.h"
#include "../p2p_func_client.h"

typedef struct p2p_cms_main_nas_thread_info_s p2p_cms_main_nas_thread_info_t;

#include "p2p_cms_main.h"
#include "../p2p_cms_channel_client_main/nas_data/p2p_cms_nas_main.h"

struct p2p_cms_main_nas_thread_info_s {
    libpiziot_os_mutex_struct_plock_t instance_mutex;
    libpiziot_os_pthread_instance_t thread_instance;
    int32_t thread_init_flag;
    char lpuuid[P2P_FUNC_UID_LENGTH_MAX + 1];
    int32_t p2p_cms_main_nas_handle;
    libpiziot_os_aes_cbc_t login_aes;
#define P2P_CMS_NAS_MAIN_THREAD_MAX P2P_PROTOCOL_NAS_CHANNEL_COUNT
    p2p_cms_nas_main_thread_info_t *lpp2p_cms_nas_main_thread_info[P2P_CMS_NAS_MAIN_THREAD_MAX];
    int32_t update_thread_info_index;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
    p2p_cms_nas_main_protocol_command_t protocol_command;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
    p2p_cms_nas_main_protocol_command_t protocol_other;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
};

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_type_func_result_e p2p_cms_main_nas_connect_device(p2p_cms_main_nas_thread_info_t *Alpthread_info, const char *AlpUID);

    extern void p2p_cms_main_nas_disconnect_device(p2p_cms_main_nas_thread_info_t *Alpthread_info);

    extern libpiziot_os_type_func_result_e p2p_cms_main_nas_initialize(p2p_cms_main_nas_thread_info_t **Alpp_thread_info);

    extern libpiziot_os_type_func_result_e p2p_cms_main_nas_finalize(p2p_cms_main_nas_thread_info_t **Alpp_thread_info);

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_P2P_CMS)

#endif //defined(__ESP8266X__)

#endif //__P2P_CMS_MAIN_NAS_H__
