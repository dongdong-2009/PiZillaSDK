#ifndef __P2P_IPCAMERA_DEVICE_MAIN_H__
#define __P2P_IPCAMERA_DEVICE_MAIN_H__

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

#include "../../p2p_func.h"
#include "../../p2p_func_client.h"
#include "../../p2p_protocol_ipcamera.h"

typedef struct p2p_ipcamera_device_main_thread_info_s p2p_ipcamera_device_main_thread_info_t;

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
typedef struct p2p_ipcamera_device_main_common_action_general_s {
    p2p_func_client_protocol_action_status_t action;
} p2p_ipcamera_device_main_common_action_general_t;

typedef struct p2p_ipcamera_device_main_common_action_timezone_s {
    p2p_func_client_protocol_action_status_t action;
} p2p_ipcamera_device_main_common_action_timezone_t;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

typedef struct p2p_ipcamera_device_main_protocol_command_s {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
    p2p_ipcamera_device_main_common_action_general_t action_common_get_model;
    p2p_ipcamera_device_main_common_action_general_t action_common_get_fwverp2p;
    p2p_ipcamera_device_main_common_action_general_t action_common_set_reboot;
    libpiziot_core_p2p_protocol_optoin_timezone_e action_value_common_timezone;
    p2p_ipcamera_device_main_common_action_timezone_t action_common_set_timezone;
    p2p_ipcamera_device_main_common_action_general_t action_common_get_timezone;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
    p2p_func_client_channel_enable_flag_t channel_enable_flag;
    p2p_ipcamera_device_main_thread_info_t *lpthread_info;
} p2p_ipcamera_device_main_protocol_command_t;

#include "../../p2p_ipcamera_main/p2p_ipcamera_main.h"
#include "../../p2p_ipcamera_main/p2p_ipcamera_main_device.h"

struct p2p_ipcamera_device_main_thread_info_s {
    libpiziot_os_mutex_struct_plock_t instance_mutex;
    libpiziot_os_pthread_instance_t thread_instance;
    libpiziot_os_mutex_struct_plock_t encrypt_mutex;
    libpiziot_os_mutex_struct_plock_t data_in_mutex;
    int32_t thread_index;
    int32_t channel_id;
    int32_t p2p_channel_monitor_handle;
    libpiziot_p2p_common_result_e net_status;
    p2p_func_client_channel_aes_e enable_aes_data;
    libpiziot_os_aes_cbc_t login_aes;
    libpiziot_os_aes_cbc_t data_aes;
    uint32_t send_counter;
    unsigned char *lpdata_send_to_client;
    uint32_t data_send_to_client_max_size;
    libpiziot_os_fifo_buffer_info_t m_fifo_send_to_client;
    unsigned char *lpdata_from_client_head;
    unsigned char *lpdata_dec_from_client;
    int32_t data_dec_from_client_size;
    libpiziot_os_fifo_buffer_info_t m_fifo_recv_from_client;
    unsigned char *lpdata_recv_from_client_head;
    int32_t data_recv_from_client_head_size;
    unsigned char *lpdata_recv_from_client;
};

#ifdef __cplusplus
extern "C"
{
#endif

    extern void p2p_ipcamera_device_main_stop_thread_all(p2p_ipcamera_main_device_thread_info_t *Alpp2p_ipcamera_main_device_thread_info);

    extern libpiziot_os_type_func_result_e p2p_ipcamera_device_main_start_thread(p2p_ipcamera_main_device_thread_info_t *Alpp2p_ipcamera_main_device_thread_info, int32_t Adevice_handle, int32_t Athread_info_index, int32_t Achannel_id, libpiziot_os_pthread_routine_p Alppthread_routine, libpiziot_p2p_common_channel_data_in_p Alpdata_in_callback, int32_t Asend_data_max_size, int32_t Asend_buffer_size, int32_t Arecv_data_max_size, p2p_func_client_channel_aes_e Aenable_channel_aes);

    extern libpiziot_os_type_func_result_e p2p_ipcamera_device_main_stop_thread(p2p_ipcamera_main_device_thread_info_t *Alpp2p_ipcamera_main_device_thread_info, int32_t Athread_info_index);

    extern void p2p_ipcamera_device_main_finalize(p2p_ipcamera_main_device_thread_info_t *Alpp2p_ipcamera_main_device_thread_info);

    extern libpiziot_os_type_func_result_e p2p_ipcamera_device_main_initialize(p2p_ipcamera_main_device_thread_info_t *Alpp2p_ipcamera_main_device_thread_info);

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_P2P_IPCAMERA)

#endif //__P2P_IPCAMERA_DEVICE_MAIN_H__
