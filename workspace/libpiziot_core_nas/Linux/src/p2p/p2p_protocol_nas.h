#ifndef __P2P_PROTOCOL_NAS_COMMAND_H__
#define __P2P_PROTOCOL_NAS_COMMAND_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../include/menu_config.h"

#if defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#include "p2p_func.h"
#include "p2p_func_client.h"

#if defined(__ESP8266X__)
#define P2P_PROTOCOL_NAS_CHANNEL_COUNT 1
#else
#define P2P_PROTOCOL_NAS_CHANNEL_COUNT 22
#endif //defined(__ESP8266X__)

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#define P2P_FUNC_NAS_ENABLE_DATA_COMMAND_DEVICE_SEND_DATA
extern int32_t p2p_protocol_nas_command_device_send_data_max_size;
#define P2P_FUNC_NAS_ENABLE_DATA_COMMAND_VIEWER_RECV_DATA
extern int32_t p2p_protocol_nas_command_viewer_recv_data_max_size;
#define P2P_FUNC_NAS_ENABLE_DATA_COMMAND_VIEWER_SEND_DATA
extern int32_t p2p_protocol_nas_command_viewer_send_data_max_size;
#define P2P_FUNC_NAS_ENABLE_DATA_COMMAND_DEVICE_RECV_DATA
extern int32_t p2p_protocol_nas_command_device_recv_data_max_size;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
extern int32_t p2p_protocol_nas_other_device_send_data_max_size;
extern int32_t p2p_protocol_nas_other_viewer_recv_data_max_size;
extern int32_t p2p_protocol_nas_other_viewer_send_data_max_size;
extern int32_t p2p_protocol_nas_other_device_recv_data_max_size;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)

extern uint32_t p2p_protocol_nas_max_send_bytes_per_second;

#define NAS_DATA_SERVER_SEND_C 200
#define NAS_DATA_CLIENT_SEND_C 701

typedef enum p2p_protocol_nas_command_enum {
    P2P_PROTOCOL_NAS_COMMAND_UNKNOWN = 0,
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
    P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_MODEL_REQ = 1,
    P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_MODEL_RESP = 2,
    P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_FWVERP2P_REQ = 3,
    P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_FWVERP2P_RESP = 4,
    P2P_PROTOCOL_NAS_COMMAND_COMMON_SET_REBOOT_REQ = 5,
    P2P_PROTOCOL_NAS_COMMAND_COMMON_SET_REBOOT_RESP = 6,
    P2P_PROTOCOL_NAS_COMMAND_COMMON_SET_TIMEZONE_REQ = 7,
    P2P_PROTOCOL_NAS_COMMAND_COMMON_SET_TIMEZONE_RESP = 8,
    P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_TIMEZONE_REQ = 9,
    P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_TIMEZONE_RESP = 10,
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_LOCK_REQ = 1001,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_LOCK_RESP = 1002,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_LOCK_REQ = 1003,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_LOCK_RESP = 1004,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_MUTE_REQ = 1005,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_MUTE_RESP = 1006,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_MUTE_REQ = 1007,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_MUTE_RESP = 1008,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_CALLOUT_REQ = 1009,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_CALLOUT_RESP = 1010,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_CALLOUT_REQ = 1011,
    P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_CALLOUT_RESP = 1012,
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
} p2p_protocol_nas_command_e;

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
typedef struct p2p_protocol_nas_command_common_get_model_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
} p2p_protocol_nas_command_common_get_model_req_t;

typedef struct p2p_protocol_nas_command_common_get_model_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
#define P2P_PROTOCOL_NAS_COMMAND_COMMON_MODEL_SIZE 32
    char lpmodel[P2P_PROTOCOL_NAS_COMMAND_COMMON_MODEL_SIZE];
} p2p_protocol_nas_command_common_get_model_resp_t;

typedef struct p2p_protocol_nas_command_common_get_fwverp2p_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
} p2p_protocol_nas_command_common_get_fwverp2p_req_t;

typedef struct p2p_protocol_nas_command_common_get_fwverp2p_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
    unsigned char lpVersion[4];
} p2p_protocol_nas_command_common_get_fwverp2p_resp_t;

typedef struct p2p_protocol_nas_command_common_set_reboot_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
} p2p_protocol_nas_command_common_set_reboot_req_t;

typedef struct p2p_protocol_nas_command_common_set_reboot_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
} p2p_protocol_nas_command_common_set_reboot_resp_t;

typedef struct p2p_protocol_nas_command_common_set_timezone_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
    libpiziot_core_p2p_protocol_optoin_timezone_e option_timezone;
} p2p_protocol_nas_command_common_set_timezone_req_t;

typedef struct p2p_protocol_nas_command_common_set_timezone_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
    libpiziot_core_p2p_protocol_optoin_timezone_e option_timezone;
} p2p_protocol_nas_command_common_set_timezone_resp_t;

typedef struct p2p_protocol_nas_command_common_get_timezone_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
} p2p_protocol_nas_command_common_get_timezone_req_t;

typedef struct p2p_protocol_nas_command_common_get_timezone_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
    libpiziot_core_p2p_protocol_optoin_timezone_e option_timezone;
} p2p_protocol_nas_command_common_get_timezone_resp_t;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
typedef struct p2p_protocol_nas_command_security_system_set_action_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
    libpiziot_core_p2p_protocol_optoin_yn_e option_yn;
} p2p_protocol_nas_command_security_system_set_yn_req_t;

typedef struct p2p_protocol_nas_command_security_system_set_action_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
    libpiziot_core_p2p_protocol_optoin_yn_e option_yn;
} p2p_protocol_nas_command_security_system_set_yn_resp_t;

typedef struct p2p_protocol_nas_command_security_system_get_action_req_s {
    libpiziot_core_p2p_cmd_head_from_client_t cmd_info;
} p2p_protocol_nas_command_security_system_get_yn_req_t;

typedef struct p2p_protocol_nas_command_security_system_get_action_resp_s {
    libpiziot_core_p2p_cmd_head_from_server_t cmd_info;
    libpiziot_core_p2p_protocol_optoin_yn_e option_yn;
} p2p_protocol_nas_command_security_system_get_yn_resp_t;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)

    extern void p2p_protocol_nas_command_init_data_max_size(void);

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#endif //__P2P_PROTOCOL_NAS_COMMAND_H__
