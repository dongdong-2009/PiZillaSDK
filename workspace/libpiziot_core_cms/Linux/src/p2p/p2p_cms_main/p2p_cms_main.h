#ifndef __P2P_CMS_MAIN_H__
#define __P2P_CMS_MAIN_H__

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

#include "../p2p_func.h"
#include "../p2p_func_client.h"
#include "../p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_channel_main.h"
#include "../p2p_cms_channel_client_main/nas_data/p2p_cms_nas_channel_main.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_mutex_struct_plock_t p2p_cms_main_ipcamera_channel_mutex;
    extern libpiziot_os_mutex_struct_plock_t p2p_cms_main_nas_channel_mutex;

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_get_protocol_command(int32_t Aarray_index, int32_t Achannel_id, p2p_cms_ipcamera_channel_main_protocol_command_t **Alppprotocol_command);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_get_protocol_command(int32_t Aarray_index, int32_t Achannel_id, p2p_cms_nas_channel_main_protocol_command_t **Alppprotocol_command);

    extern libpiziot_os_type_func_result_e p2p_cms_main_start_thread(void);

    extern void p2p_cms_main_stop_thread(void);

    extern libpiziot_os_type_func_result_e p2p_cms_main_initialize(void);

    extern libpiziot_os_type_func_result_e p2p_cms_main_finalize(void);

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_P2P_CMS)

#endif //defined(__ESP8266X__)

#endif //__P2P_CMS_MAIN_H__
