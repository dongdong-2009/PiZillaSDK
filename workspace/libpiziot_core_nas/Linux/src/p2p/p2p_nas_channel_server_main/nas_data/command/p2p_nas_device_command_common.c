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
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)

//Define this Header
#include "p2p_nas_device_command_common.h"

//Define Other Header
#include "../../../p2p_protocol_nas.h"
#include "../../../p2p_nas_main/p2p_nas_main.h"
#include "../p2p_nas_device_main.h"

//Define Common Library
#include "../p2p_nas_device_command.h"

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

static void p2p_nas_device_command_common_set_action(p2p_func_client_protocol_action_status_t* Alpprotocol_action_status) {
    gettimeofday(&Alpprotocol_action_status->timeval_action_start, NULL);
    Alpprotocol_action_status->protocol_action_flag = P2P_FUNC_CLIENT_PROTOCOL_ACTION_BEGIN;
}

static libpiziot_os_type_func_result_e p2p_nas_device_command_common_recv_get_model_req(libpiziot_core_p2p_cmd_head_from_client_t *Alpcmd, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_common_get_model_req_t *lpdata_request = (p2p_protocol_nas_command_common_get_model_req_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_request->cmd_info.size);
        if (size != sizeof(p2p_protocol_nas_command_common_get_model_req_t)) return rval;
        TRACEA("RECV NAS COMMON GET %s REQ\n", Alpstractoin);
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_nas_device_command_common_send_get_model_resp(p2p_nas_device_main_protocol_command_t *Alpprotocol_command, p2p_nas_device_main_common_action_general_t *Alpcommon_action_general, p2p_protocol_nas_command_e Acmd, libpiziot_core_p2p_data_from_client_head_t *Alphead) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_common_get_model_resp_t data_respond;
        data_respond.cmd_info.size = mem_endian_32(sizeof(data_respond));
        data_respond.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
        {
            memset(data_respond.lpmodel, 0, P2P_PROTOCOL_NAS_COMMAND_COMMON_MODEL_SIZE);
#if defined(__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-X86");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8197__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-RTL8197");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3520D__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-HI3520D");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518E__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-HI3518E");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518EV2__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-HI3518EV2");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_BCM28XX_RASPBERRY__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-PI");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8881__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-RTL8881");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8196__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-RTL8196");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RK3328_ROCK64__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-RK3328");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_MT7688_LINKIT__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-MT7688");
#elif defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__)
            sprintf(data_respond.lpmodel, "%s", "I.P.C-NAS-ANDROID");
#elif (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
            sprintf(data_respond.lpmodel, "%s", "I.P.C-NAS-XCODE");
#else
#error
#endif
        }
        data_respond.cmd_info.channel_server_handle = Alphead->channel_server_handle;
        rval = p2p_nas_device_command_send_to_channel_client(Alpprotocol_command->lpthread_info, (unsigned char *) &(data_respond), sizeof(data_respond));
        p2p_nas_device_command_common_set_action(&(Alpcommon_action_general->action_get));
    }
    return rval;
}

static libpiziot_os_type_func_result_e p2p_nas_device_command_common_recv_get_fwverp2p_req(libpiziot_core_p2p_cmd_head_from_client_t *Alpcmd, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_common_get_fwverp2p_req_t *lpdata_request = (p2p_protocol_nas_command_common_get_fwverp2p_req_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_request->cmd_info.size);
        if (size != sizeof(p2p_protocol_nas_command_common_get_fwverp2p_req_t)) return rval;
        TRACEA("RECV NAS COMMON GET %s REQ\n", Alpstractoin);
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_nas_device_command_common_send_get_fwverp2p_resp(p2p_nas_device_main_protocol_command_t *Alpprotocol_command, p2p_nas_device_main_common_action_general_t *Alpcommon_action_general, p2p_protocol_nas_command_e Acmd, libpiziot_core_p2p_data_from_client_head_t *Alphead) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_common_get_fwverp2p_resp_t data_respond;
        data_respond.cmd_info.size = mem_endian_32(sizeof(data_respond));
        data_respond.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
        {
            libpiziot_p2p_common_get_version(data_respond.lpVersion);
            TRACEA("LIBPIZIOT Version %d.%d.%d.%d\n", (int32_t)(data_respond.lpVersion[0]), (int32_t)(data_respond.lpVersion[1]), (int32_t)(data_respond.lpVersion[2]), (int32_t)(data_respond.lpVersion[3]));
        }
        data_respond.cmd_info.channel_server_handle = Alphead->channel_server_handle;
        rval = p2p_nas_device_command_send_to_channel_client(Alpprotocol_command->lpthread_info, (unsigned char *) &(data_respond), sizeof(data_respond));
        p2p_nas_device_command_common_set_action(&(Alpcommon_action_general->action_get));
    }
    return rval;
}

static libpiziot_os_type_func_result_e p2p_nas_device_command_common_recv_set_reboot_req(libpiziot_core_p2p_cmd_head_from_client_t *Alpcmd, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_common_set_reboot_req_t *lpdata_request = (p2p_protocol_nas_command_common_set_reboot_req_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_request->cmd_info.size);
        if (size != sizeof(p2p_protocol_nas_command_common_set_reboot_req_t)) return rval;
        TRACEA("RECV NAS COMMON SET %s REQ\n", Alpstractoin);
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_nas_device_command_common_send_set_reboot_resp(p2p_nas_device_main_protocol_command_t *Alpprotocol_command, p2p_nas_device_main_common_action_general_t *Alpcommon_action_general, p2p_protocol_nas_command_e Acmd, libpiziot_core_p2p_data_from_client_head_t *Alphead) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_common_set_reboot_resp_t data_respond;
        data_respond.cmd_info.size = mem_endian_32(sizeof(data_respond));
        data_respond.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
        data_respond.cmd_info.channel_server_handle = LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA;
        if (Alphead->channel_server_handle) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
        rval = p2p_nas_device_command_send_to_channel_client(Alpprotocol_command->lpthread_info, (unsigned char *) &(data_respond), sizeof(data_respond));
        p2p_nas_device_command_common_set_action(&(Alpcommon_action_general->action_set));
    }
    return rval;
}

static libpiziot_os_type_func_result_e p2p_nas_device_command_common_recv_set_timezone_req(p2p_nas_device_main_common_action_timezone_t *Alpcommon_action_timezone, libpiziot_core_p2p_cmd_head_from_client_t *Alpcmd, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_common_set_timezone_req_t *lpdata_request = (p2p_protocol_nas_command_common_set_timezone_req_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_request->cmd_info.size);
        if (size != sizeof(p2p_protocol_nas_command_common_set_timezone_req_t)) return rval;
        {
            switch (mem_endian_32(lpdata_request->option_timezone)) {
            case LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI: {
                Alpcommon_action_timezone->option_timezone_current = mem_endian_32(lpdata_request->option_timezone);
                TRACEA("RECV NAS COMMON SET %s TAIPEI REQ\n", Alpstractoin);
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

static libpiziot_os_type_func_result_e p2p_nas_device_command_common_send_set_timezone_resp(p2p_nas_device_main_protocol_command_t *Alpprotocol_command, p2p_nas_device_main_common_action_timezone_t *Alpcommon_action_timezone, p2p_protocol_nas_command_e Acmd, libpiziot_core_p2p_data_from_client_head_t *Alphead) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_common_set_timezone_resp_t data_respond;
        data_respond.cmd_info.size = mem_endian_32(sizeof(data_respond));
        data_respond.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
        data_respond.option_timezone = mem_endian_32(((uint32_t)(Alpcommon_action_timezone->option_timezone_current)));
        data_respond.cmd_info.channel_server_handle = LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA;
        if (Alphead->channel_server_handle) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
        rval = p2p_nas_device_command_send_to_channel_client(Alpprotocol_command->lpthread_info, (unsigned char *) &(data_respond), sizeof(data_respond));
        p2p_nas_device_command_common_set_action(&(Alpcommon_action_timezone->action_set));
    }
    return rval;
}

static libpiziot_os_type_func_result_e p2p_nas_device_command_common_recv_get_timezone_req(p2p_nas_device_main_common_action_timezone_t *Alpcommon_action_timezone, libpiziot_core_p2p_cmd_head_from_client_t *Alpcmd, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_common_get_timezone_req_t *lpdata_request = (p2p_protocol_nas_command_common_get_timezone_req_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_request->cmd_info.size);
        if (size != sizeof(p2p_protocol_nas_command_common_get_timezone_req_t)) return rval;
        TRACEA("RECV NAS COMMON GET %s REQ\n", Alpstractoin);
        if (Alpcommon_action_timezone) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_nas_device_command_common_send_get_timezone_resp(p2p_nas_device_main_protocol_command_t *Alpprotocol_command, p2p_nas_device_main_common_action_timezone_t *Alpcommon_action_general, p2p_protocol_nas_command_e Acmd, libpiziot_core_p2p_data_from_client_head_t *Alphead) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    {
        p2p_protocol_nas_command_common_get_timezone_resp_t data_respond;
        data_respond.cmd_info.size = mem_endian_32(sizeof(data_respond));
        data_respond.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
        data_respond.option_timezone = mem_endian_32(((uint32_t)(Alpcommon_action_general->option_timezone_current)));
        data_respond.cmd_info.channel_server_handle = Alphead->channel_server_handle;
        rval = p2p_nas_device_command_send_to_channel_client(Alpprotocol_command->lpthread_info, (unsigned char *) &(data_respond), sizeof(data_respond));
        p2p_nas_device_command_common_set_action(&(Alpcommon_action_general->action_get));
    }
    return rval;
}

libpiziot_os_type_func_result_e p2p_nas_device_command_common_parser(p2p_protocol_nas_command_e Acmd, int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_client_t *Alpcmd, libpiziot_core_p2p_data_from_client_head_t *Alphead) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    libpiziot_os_mutex_plock_lock(&p2p_nas_main_device_channel_mutex);
    do {
        p2p_nas_device_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_nas_device_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        switch (Acmd) {
        case P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_MODEL_REQ: {
            p2p_nas_device_command_common_recv_get_model_req(Alpcmd, "MODEL");
            p2p_nas_device_command_common_send_get_model_resp(lpprotocol_command, &(lpprotocol_command->action_common_model), P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_MODEL_RESP, Alphead);
        }
                                                            break;
        case P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_FWVERP2P_REQ: {
            p2p_nas_device_command_common_recv_get_fwverp2p_req(Alpcmd, "FWVERP2P");
            p2p_nas_device_command_common_send_get_fwverp2p_resp(lpprotocol_command, &(lpprotocol_command->action_common_fwverp2p), P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_FWVERP2P_RESP, Alphead);
        }
                                                               break;
        case P2P_PROTOCOL_NAS_COMMAND_COMMON_SET_REBOOT_REQ: {
            p2p_nas_device_command_common_recv_set_reboot_req(Alpcmd, "REBOOT");
            p2p_nas_device_command_common_send_set_reboot_resp(lpprotocol_command, &(lpprotocol_command->action_common_reboot), P2P_PROTOCOL_NAS_COMMAND_COMMON_SET_REBOOT_RESP, Alphead);
        }
                                                             break;
        case P2P_PROTOCOL_NAS_COMMAND_COMMON_SET_TIMEZONE_REQ: {
            p2p_nas_device_command_common_recv_set_timezone_req(&(lpprotocol_command->action_common_timezone), Alpcmd, "TIMEZONE");
            p2p_nas_device_command_common_send_set_timezone_resp(lpprotocol_command, &(lpprotocol_command->action_common_timezone), P2P_PROTOCOL_NAS_COMMAND_COMMON_SET_TIMEZONE_RESP, Alphead);
        }
                                                               break;
        case P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_TIMEZONE_REQ: {
            p2p_nas_device_command_common_recv_get_timezone_req(&(lpprotocol_command->action_common_timezone), Alpcmd, "TIMEZONE");
            p2p_nas_device_command_common_send_get_timezone_resp(lpprotocol_command, &(lpprotocol_command->action_common_timezone), P2P_PROTOCOL_NAS_COMMAND_COMMON_GET_TIMEZONE_RESP, Alphead);
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

void p2p_nas_device_command_common_send_action(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_nas_device_main_protocol_command_t *lpprotocol_command = 0;
    libpiziot_os_mutex_plock_lock(&p2p_nas_main_device_channel_mutex);
    {
        rval = libpiziot_core_p2p_nas_device_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command);
    }
    libpiziot_os_mutex_plock_unlock(&p2p_nas_main_device_channel_mutex);
    if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
    }
}

void p2p_nas_device_command_common_init_action(p2p_nas_device_main_protocol_command_t *Alpprotocol_command) {
    memset(&(Alpprotocol_command->action_common_model), 0, sizeof(Alpprotocol_command->action_common_model));
    memset(&(Alpprotocol_command->action_common_fwverp2p), 0, sizeof(Alpprotocol_command->action_common_fwverp2p));
    memset(&(Alpprotocol_command->action_common_reboot), 0, sizeof(Alpprotocol_command->action_common_reboot));
    {
        memset(&(Alpprotocol_command->action_common_timezone), 0, sizeof(Alpprotocol_command->action_common_timezone));
        Alpprotocol_command->action_common_timezone.option_timezone_current = LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_UNKNOWN;
    }
}

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(ENABLE_P2P_NAS)
