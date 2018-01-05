#ifndef __P2P_CMS_IPCAMERA_CHANNEL_COMMAND_COMMON_H__
#define __P2P_CMS_IPCAMERA_CHANNEL_COMMAND_COMMON_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../../../../include/menu_config.h"

#if defined(__ESP8266X__)
#else

#if defined(ENABLE_P2P_CMS)

#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)

#include "../../../p2p_func.h"
#include "../../../p2p_func_client.h"
#include "../../../p2p_protocol_ipcamera.h"
#include "../../../p2p_cms_main/p2p_cms_main.h"
#include "../../../p2p_cms_main/p2p_cms_main_ipcamera.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_parser(p2p_protocol_ipcamera_command_e Acmd, int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_server_t *Alpcmd);

    extern void p2p_cms_ipcamera_channel_command_common_send_action(int32_t Aarray_index);

    extern void p2p_cms_ipcamera_channel_command_common_init_action(p2p_cms_ipcamera_channel_main_protocol_command_t *Alpprotocol_command);

#ifdef __cplusplus
}
#endif

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_CMS)

#endif //defined(__ESP8266X__)

#endif //__P2P_CMS_IPCAMERA_CHANNEL_COMMAND_COMMON_H__
