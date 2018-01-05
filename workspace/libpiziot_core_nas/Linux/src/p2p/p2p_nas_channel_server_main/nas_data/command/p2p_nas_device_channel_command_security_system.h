#ifndef __P2P_NAS_DEVICE_CHANNEL_COMMAND_SECURITY_SYSTEM_H__
#define __P2P_NAS_DEVICE_CHANNEL_COMMAND_SECURITY_SYSTEM_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../../../../include/menu_config.h"

#if defined(ENABLE_P2P_NAS)

#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

#include "../../../p2p_func.h"
#include "../../../p2p_func_client.h"
#include "../../../p2p_protocol_nas.h"
#include "../../../p2p_nas_main/p2p_nas_main.h"
#include "../../../p2p_nas_main/p2p_nas_main_device.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_type_func_result_e p2p_nas_device_channel_command_security_system_parser(p2p_protocol_nas_command_e Acmd, int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_client_t *Alpcmd, libpiziot_core_p2p_data_from_client_head_t *Alphead);

    extern void p2p_nas_device_channel_command_security_system_send_action(int32_t Aarray_index);

    extern void p2p_nas_device_channel_command_security_system_init_action(p2p_nas_device_channel_main_protocol_command_t *Alpprotocol_command);

#ifdef __cplusplus
}
#endif

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(ENABLE_P2P_NAS)

#endif //__P2P_NAS_DEVICE_CHANNEL_COMMAND_SECURITY_SYSTEM_H__
