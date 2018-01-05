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
#include "../../../../../include/menu_config.h"

#if defined(ENABLE_P2P_NAS)

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_clientsdk.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

//Define this Header
#include "p2p_nas_device_channel_command_security_system.h"

//Define Other Header
#include "../../../p2p_protocol_nas.h"
#include "../../../p2p_nas_main/p2p_nas_main.h"
#include "../p2p_nas_device_channel_main.h"

//Define Common Library
#include "../p2p_nas_device_channel_command.h"

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

static void p2p_nas_device_channel_command_security_system_set_action(p2p_func_client_protocol_action_status_t* Alpprotocol_action_status) {
    gettimeofday(&Alpprotocol_action_status->timeval_action_start, NULL);
    Alpprotocol_action_status->protocol_action_flag = P2P_FUNC_CLIENT_PROTOCOL_ACTION_BEGIN;
}

static libpiziot_os_type_func_result_e p2p_nas_device_channel_command_security_system_recv_set_yn_req(p2p_nas_device_channel_main_zigbee_action_general_t *Alpzigbee_action_general, libpiziot_core_p2p_cmd_head_from_client_t *Alpcmd, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_security_system_set_yn_req_t *lpdata_request = (p2p_protocol_nas_command_security_system_set_yn_req_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_request->cmd_info.size);
        if (size != sizeof(p2p_protocol_nas_command_security_system_set_yn_req_t)) return rval;
        {
            switch (mem_endian_32(lpdata_request->option_yn)) {
            case LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO: {
                TRACEA("RECV NAS ZIGBEE SET %s REQ DISABLE\n", Alpstractoin);
                Alpzigbee_action_general->option_yn_current = mem_endian_32(lpdata_request->option_yn);
            }
                                                           break;
            case LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES: {
                TRACEA("RECV NAS ZIGBEE SET %s REQ ENABLE\n", Alpstractoin);
                Alpzigbee_action_general->option_yn_current = mem_endian_32(lpdata_request->option_yn);
            }
                                                            break;
            default: {
            }
                     break;
            }
        }
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_nas_device_channel_command_security_system_send_set_yn_resp(p2p_nas_device_channel_main_protocol_command_t *Alpprotocol_command, p2p_nas_device_channel_main_zigbee_action_general_t *Alpzigbee_action_general, p2p_protocol_nas_command_e Acmd, libpiziot_core_p2p_data_from_client_head_t *Alphead) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_security_system_set_yn_resp_t data_respond;
        data_respond.cmd_info.size = mem_endian_32(sizeof(data_respond));
        data_respond.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
        data_respond.option_yn = mem_endian_32(((uint32_t)(Alpzigbee_action_general->option_yn_current)));
        data_respond.cmd_info.channel_server_handle = LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA;
        if (Alphead->channel_server_handle) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
        rval = p2p_nas_device_channel_command_send_to_channel_client(Alpprotocol_command->lpthread_info, (unsigned char *) &(data_respond), sizeof(data_respond));
        p2p_nas_device_channel_command_security_system_set_action(&(Alpzigbee_action_general->action_set));
    }
    return rval;
}

static libpiziot_os_type_func_result_e p2p_nas_device_channel_command_security_system_recv_get_yn_req(p2p_nas_device_channel_main_zigbee_action_general_t *Alpzigbee_action_general, libpiziot_core_p2p_cmd_head_from_client_t *Alpcmd, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_security_system_get_yn_req_t *lpdata_request = (p2p_protocol_nas_command_security_system_get_yn_req_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_request->cmd_info.size);
        if (size != sizeof(p2p_protocol_nas_command_security_system_get_yn_req_t)) return rval;
        TRACEA("RECV NAS ZIGBEE GET %s REQ\n", Alpstractoin);
        if (Alpzigbee_action_general) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_nas_device_channel_command_security_system_send_get_yn_resp(p2p_nas_device_channel_main_protocol_command_t *Alpprotocol_command, p2p_nas_device_channel_main_zigbee_action_general_t *Alpzigbee_action_general, p2p_protocol_nas_command_e Acmd, libpiziot_core_p2p_data_from_client_head_t *Alphead) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_security_system_get_yn_resp_t data_respond;
        data_respond.cmd_info.size = mem_endian_32(sizeof(data_respond));
        data_respond.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
        data_respond.option_yn = mem_endian_32((Alpzigbee_action_general->option_yn_current));
        data_respond.cmd_info.channel_server_handle = Alphead->channel_server_handle;
        rval = p2p_nas_device_channel_command_send_to_channel_client(Alpprotocol_command->lpthread_info, (unsigned char *) &(data_respond), sizeof(data_respond));
        p2p_nas_device_channel_command_security_system_set_action(&(Alpzigbee_action_general->action_get));
    }
    return rval;
}

libpiziot_os_type_func_result_e p2p_nas_device_channel_command_security_system_parser(p2p_protocol_nas_command_e Acmd, int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_client_t *Alpcmd, libpiziot_core_p2p_data_from_client_head_t *Alphead) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    libpiziot_os_mutex_plock_lock(&p2p_nas_main_device_channel_mutex);
    do {
        p2p_nas_device_channel_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_nas_device_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        switch (Acmd) {
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_LOCK_REQ: {
            p2p_nas_device_channel_command_security_system_recv_set_yn_req(&(lpprotocol_command->action_zigbee_lock), Alpcmd, "LOCK");
            p2p_nas_device_channel_command_security_system_send_set_yn_resp(lpprotocol_command, &(lpprotocol_command->action_zigbee_lock), P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_LOCK_RESP, Alphead);
        }
                                                                    break;
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_LOCK_REQ: {
            p2p_nas_device_channel_command_security_system_recv_get_yn_req(&(lpprotocol_command->action_zigbee_lock), Alpcmd, "LOCK");
            p2p_nas_device_channel_command_security_system_send_get_yn_resp(lpprotocol_command, &(lpprotocol_command->action_zigbee_lock), P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_LOCK_RESP, Alphead);
        }
                                                                    break;
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_MUTE_REQ: {
            p2p_nas_device_channel_command_security_system_recv_set_yn_req(&(lpprotocol_command->action_zigbee_mute), Alpcmd, "MUTE");
            p2p_nas_device_channel_command_security_system_send_set_yn_resp(lpprotocol_command, &(lpprotocol_command->action_zigbee_mute), P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_MUTE_RESP, Alphead);
        }
                                                                    break;
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_MUTE_REQ: {
            p2p_nas_device_channel_command_security_system_recv_get_yn_req(&(lpprotocol_command->action_zigbee_mute), Alpcmd, "MUTE");
            p2p_nas_device_channel_command_security_system_send_get_yn_resp(lpprotocol_command, &(lpprotocol_command->action_zigbee_mute), P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_MUTE_RESP, Alphead);
        }
                                                                    break;
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_CALLOUT_REQ: {
            p2p_nas_device_channel_command_security_system_recv_set_yn_req(&(lpprotocol_command->action_zigbee_callout), Alpcmd, "CALLOUT");
            p2p_nas_device_channel_command_security_system_send_set_yn_resp(lpprotocol_command, &(lpprotocol_command->action_zigbee_callout), P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_CALLOUT_RESP, Alphead);
        }
                                                                       break;
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_CALLOUT_REQ: {
            p2p_nas_device_channel_command_security_system_recv_get_yn_req(&(lpprotocol_command->action_zigbee_callout), Alpcmd, "CALLOUT");
            p2p_nas_device_channel_command_security_system_send_get_yn_resp(lpprotocol_command, &(lpprotocol_command->action_zigbee_callout), P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_CALLOUT_RESP, Alphead);
        }
                                                                       break;
        default: {
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
        }
                 break;
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_nas_main_device_channel_mutex);
    return rval;
}

void p2p_nas_device_channel_command_security_system_send_action(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_nas_device_channel_main_protocol_command_t *lpprotocol_command = 0;
    libpiziot_os_mutex_plock_lock(&p2p_nas_main_device_channel_mutex);
    {
        rval = libpiziot_core_p2p_nas_device_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command);
    }
    libpiziot_os_mutex_plock_unlock(&p2p_nas_main_device_channel_mutex);
    if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
    }
}

void p2p_nas_device_channel_command_security_system_init_action(p2p_nas_device_channel_main_protocol_command_t *Alpprotocol_command) {
    {
        memset(&(Alpprotocol_command->action_zigbee_lock), 0, sizeof(Alpprotocol_command->action_zigbee_lock));
        Alpprotocol_command->action_zigbee_lock.option_yn_current = LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES;
    }
    {
        memset(&(Alpprotocol_command->action_zigbee_mute), 0, sizeof(Alpprotocol_command->action_zigbee_mute));
        Alpprotocol_command->action_zigbee_mute.option_yn_current = LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO;
    }
    {
        memset(&(Alpprotocol_command->action_zigbee_callout), 0, sizeof(Alpprotocol_command->action_zigbee_callout));
        Alpprotocol_command->action_zigbee_callout.option_yn_current = LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO;
    }
}

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(ENABLE_P2P_NAS)
