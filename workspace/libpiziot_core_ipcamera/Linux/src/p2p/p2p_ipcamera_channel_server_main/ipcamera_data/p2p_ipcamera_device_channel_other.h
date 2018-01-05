#ifndef __P2P_IPCAMERA_DEVICE_CHANNEL_OTHER_H__
#define __P2P_IPCAMERA_DEVICE_CHANNEL_OTHER_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../../../include/menu_config.h"

#if defined(ENABLE_P2P_IPCAMERA)

#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)

#include "../../p2p_func.h"
#include "../../p2p_func_client.h"
#include "../../p2p_protocol_ipcamera.h"
#include "../../p2p_ipcamera_main/p2p_ipcamera_main.h"
#include "../../p2p_ipcamera_main/p2p_ipcamera_main_device.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_type_func_result_e p2p_ipcamera_device_channel_other_send_to_channel_client(p2p_ipcamera_device_channel_main_thread_info_t *Alpthread_info, uint32_t Achannel_server_handle, unsigned char *Alpdata_send, int32_t Adata_size);

    extern void p2p_ipcamera_device_channel_other_data_in_callback(void *Alpobject, int32_t Adevice_handle, int32_t Achannel_server_handle, int32_t Achannel_id, struct sockaddr_in *Alpin_channel_client_ip, unsigned char *Alpdata, int32_t Adata_size);

    extern libpiziot_os_pthread_dword_t p2p_ipcamera_device_channel_other_thread_instance_routine(void *arg);

#ifdef __cplusplus
}
#endif

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
#endif //defined(ENABLE_P2P_IPCAMERA)

#endif //__P2P_IPCAMERA_DEVICE_CHANNEL_OTHER_H__
