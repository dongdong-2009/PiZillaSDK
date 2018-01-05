#ifndef __P2P_PROTOCOL_IPCAMERA_COMMAND_H__
#define __P2P_PROTOCOL_IPCAMERA_COMMAND_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../include/menu_config.h"

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#include "p2p_func.h"
#include "p2p_func_client.h"

#define P2P_PROTOCOL_IPCAMERA_CHANNEL_COUNT 7

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#define P2P_PROTOCOL_IPCAMERA_COMMAND_DEVICE_SEND_DATA_MAX_SIZE
extern int32_t p2p_protocol_ipcamera_command_device_send_data_max_size;
#define P2P_PROTOCOL_IPCAMERA_COMMAND_VIEWER_RECV_DATA_MAX_SIZE
extern int32_t p2p_protocol_ipcamera_command_viewer_recv_data_max_size;
#define P2P_PROTOCOL_IPCAMERA_COMMAND_VIEWER_SEND_DATA_MAX_SIZE
extern int32_t p2p_protocol_ipcamera_command_viewer_send_data_max_size;
#define P2P_PROTOCOL_IPCAMERA_COMMAND_DEVICE_RECV_DATA_MAX_SIZE
extern int32_t p2p_protocol_ipcamera_command_device_recv_data_max_size;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
extern int32_t p2p_protocol_ipcamera_other_device_send_data_max_size;
extern int32_t p2p_protocol_ipcamera_other_viewer_recv_data_max_size;
extern int32_t p2p_protocol_ipcamera_other_viewer_send_data_max_size;
extern int32_t p2p_protocol_ipcamera_other_device_recv_data_max_size;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)

extern uint32_t p2p_protocol_ipcamera_max_send_bytes_per_second;

#define IPCAMERA_DATA_SERVER_SEND_C 100
#define IPCAMERA_DATA_CLIENT_SEND_C 501

typedef enum p2p_protocol_ipcamera_command_enum {
    P2P_PROTOCOL_IPCAMERA_COMMAND_UNKNOWN = 0,
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
    P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_MODEL_REQ = 1,
    P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_MODEL_RESP = 2,
    P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_FWVERP2P_REQ = 3,
    P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_FWVERP2P_RESP = 4,
    P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_SET_REBOOT_REQ = 5,
    P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_SET_REBOOT_RESP = 6,
    P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_SET_TIMEZONE_REQ = 7,
    P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_SET_TIMEZONE_RESP = 8,
    P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_TIMEZONE_REQ = 9,
    P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_TIMEZONE_RESP = 10,
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
} p2p_protocol_ipcamera_command_e;

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
typedef struct p2p_protocol_ipcamera_command_common_get_model_req_t {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
} p2p_protocol_ipcamera_command_common_get_model_req_t;

typedef struct p2p_protocol_ipcamera_command_common_get_model_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
#define P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_MODEL_SIZE 32    
    char lpmodel[P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_MODEL_SIZE];
} p2p_protocol_ipcamera_command_common_get_model_resp_t;

typedef struct p2p_protocol_ipcamera_command_common_get_fwverp2p_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
} p2p_protocol_ipcamera_command_common_get_fwverp2p_req_t;

typedef struct libpiziot_core_p2p_client_ipcamera_channel_common_get_fwverp2p_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
    unsigned char lpVersion[4];
} p2p_protocol_ipcamera_command_common_get_fwverp2p_resp_t;

typedef struct p2p_protocol_ipcamera_command_common_set_reboot_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
} p2p_protocol_ipcamera_command_common_set_reboot_req_t;

typedef struct p2p_protocol_ipcamera_command_common_set_reboot_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
} p2p_protocol_ipcamera_command_common_set_reboot_resp_t;

typedef struct p2p_protocol_ipcamera_command_common_set_timezone_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
    libpiziot_core_p2p_protocol_optoin_timezone_e option_timezone;
} p2p_protocol_ipcamera_command_common_set_timezone_req_t;

typedef struct p2p_protocol_ipcamera_command_common_set_timezone_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
    libpiziot_core_p2p_protocol_optoin_timezone_e option_timezone;
} p2p_protocol_ipcamera_command_common_set_timezone_resp_t;

typedef struct p2p_protocol_ipcamera_command_common_get_timezone_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
} p2p_protocol_ipcamera_command_common_get_timezone_req_t;

typedef struct p2p_protocol_ipcamera_command_common_get_timezone_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
    libpiziot_core_p2p_protocol_optoin_timezone_e option_timezone;
} p2p_protocol_ipcamera_command_common_get_timezone_resp_t;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

    extern void p2p_protocol_ipcamera_command_init_data_max_size(void);

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#endif //__P2P_PROTOCOL_IPCAMERA_COMMAND_H__
