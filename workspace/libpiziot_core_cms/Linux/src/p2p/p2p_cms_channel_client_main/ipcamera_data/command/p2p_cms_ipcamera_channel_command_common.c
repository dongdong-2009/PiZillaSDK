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

#if defined(__ESP8266X__)
#else

#if defined(ENABLE_P2P_CMS)

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_clientsdk.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)

//Define this Header
#include "p2p_cms_ipcamera_channel_command_common.h"

//Define Other Header
#include "../../../p2p_protocol_ipcamera.h"
#include "../../../p2p_cms_main/p2p_cms_main.h"
#include "../p2p_cms_ipcamera_channel_main.h"

//Define Common Library

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

static void p2p_cms_ipcamera_channel_command_common_set_action(p2p_func_client_protocol_action_status_t* Alpprotocol_action_status) {
    gettimeofday(&Alpprotocol_action_status->timeval_action_start, NULL);
    Alpprotocol_action_status->protocol_action_flag = P2P_FUNC_CLIENT_PROTOCOL_ACTION_BEGIN;
}

static void p2p_cms_ipcamera_channel_command_common_clear_action(p2p_func_client_protocol_action_status_t* Alpprotocol_action_status) {
    Alpprotocol_action_status->protocol_action_flag = P2P_FUNC_CLIENT_PROTOCOL_ACTION_END;
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_recv_get_model_resp(int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_server_t *Alpcmd, p2p_cms_ipcamera_channel_main_common_action_general_t* Alpcommon_action_general, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    {
        p2p_protocol_ipcamera_command_common_get_model_resp_t *lpdata_respond = (p2p_protocol_ipcamera_command_common_get_model_resp_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_respond->cmd_info.size);
        if (size != sizeof(p2p_protocol_ipcamera_command_common_get_model_resp_t)) return rval;
        {
            if (lpdata_respond->cmd_info.channel_server_handle == LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA) {
                TRACEA("BROADCAST CMS IPCAMERA COMMON GET %s RESP [s]\n", Alpstractoin, lpdata_respond->lpmodel);
            }
            else {
                TRACEA("CMS IPCAMERA COMMON GET %s RESP [%s]\n", Alpstractoin, lpdata_respond->lpmodel);
            }
            p2p_cms_ipcamera_channel_command_common_clear_action(&(Alpcommon_action_general->action_get));
        }
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_send_get_model_req(int32_t Aarray_index, p2p_protocol_ipcamera_command_e Acmd) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_protocol_ipcamera_command_common_get_model_req_t data_request;
    data_request.cmd_info.size = mem_endian_32(sizeof(data_request));
    data_request.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
    rval = libpiziot_core_p2p_cms_main_ipcamera_channel_send(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, (unsigned char *) &(data_request), sizeof(data_request));
    return rval;
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_recv_get_fwverp2p_resp(int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_server_t *Alpcmd, p2p_cms_ipcamera_channel_main_common_action_general_t *Alpcommon_action_general, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    {
        p2p_protocol_ipcamera_command_common_get_fwverp2p_resp_t *lpdata_respond = (p2p_protocol_ipcamera_command_common_get_fwverp2p_resp_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_respond->cmd_info.size);
        if (size != sizeof(p2p_protocol_ipcamera_command_common_get_fwverp2p_resp_t)) return rval;
        {
            if (lpdata_respond->cmd_info.channel_server_handle == LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA) {
                TRACEA("BROADCAST CMS IPCAMERA COMMON GET %s RESP %d.%d.%d.%d\n", Alpstractoin, (int32_t)(lpdata_respond->lpVersion[0]), (int32_t)(lpdata_respond->lpVersion[1]), (int32_t)(lpdata_respond->lpVersion[2]), (int32_t)(lpdata_respond->lpVersion[3]));
            }
            else {
                TRACEA("CMS IPCAMERA COMMON GET %s RESP %d.%d.%d.%d\n", Alpstractoin, (int32_t)(lpdata_respond->lpVersion[0]), (int32_t)(lpdata_respond->lpVersion[1]), (int32_t)(lpdata_respond->lpVersion[2]), (int32_t)(lpdata_respond->lpVersion[3]));
            }
            p2p_cms_ipcamera_channel_command_common_clear_action(&(Alpcommon_action_general->action_get));
        }
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_send_get_fwverp2p_req(int32_t Aarray_index, p2p_protocol_ipcamera_command_e Acmd) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_protocol_ipcamera_command_common_get_fwverp2p_req_t data_request;
    data_request.cmd_info.size = mem_endian_32(sizeof(data_request));
    data_request.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
    rval = libpiziot_core_p2p_cms_main_ipcamera_channel_send(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, (unsigned char *) &(data_request), sizeof(data_request));
    return rval;
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_recv_set_reboot_resp(int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_server_t *Alpcmd, p2p_cms_ipcamera_channel_main_common_action_general_t *Alpcommon_action_general, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    {
        p2p_protocol_ipcamera_command_common_set_reboot_resp_t *lpdata_respond = (p2p_protocol_ipcamera_command_common_set_reboot_resp_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_respond->cmd_info.size);
        if (size != sizeof(p2p_protocol_ipcamera_command_common_set_reboot_resp_t)) return rval;
        {
            if (lpdata_respond->cmd_info.channel_server_handle == LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA) {
                TRACEA("BROADCAST CMS IPCAMERA COMMON SET %s RESP\n", Alpstractoin);
            }
            else {
                TRACEA("CMS IPCAMERA COMMON SET %s RESP\n", Alpstractoin);
            }
            p2p_cms_ipcamera_channel_command_common_clear_action(&(Alpcommon_action_general->action_set));
        }
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_send_set_reboot_req(int32_t Aarray_index, p2p_protocol_ipcamera_command_e Acmd) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_protocol_ipcamera_command_common_set_reboot_req_t data_request;
    data_request.cmd_info.size = mem_endian_32(sizeof(data_request));
    data_request.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
    rval = libpiziot_core_p2p_cms_main_ipcamera_channel_send(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, (unsigned char *) &(data_request), sizeof(data_request));
    return rval;
}

static void p2p_cms_ipcamera_channel_command_common_show_timezone_resp(uint32_t Achannel_server_handle, libpiziot_core_p2p_protocol_optoin_timezone_e Atimezone, char *Alpstractoin, char *AlpstrSG) {
    char *lpstr_taipei = "TAIPEI";
    char *lpstr_timezone = "";
    switch (Atimezone) {
    case LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI: {
        lpstr_timezone = lpstr_taipei;
    }
                                                            break;
    default: {
    }
             break;
    }
    if (Achannel_server_handle == LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA) {
        TRACEA("BROADCAST CMS IPCAMERA COMMON %s %s RESP %s\n", AlpstrSG, Alpstractoin, lpstr_timezone);
    }
    else {
        TRACEA("CMS IPCAMERA COMMON %s %s RESP %s\n", AlpstrSG, Alpstractoin, lpstr_timezone);
    }
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_recv_set_timezone_resp(int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_server_t *Alpcmd, p2p_cms_ipcamera_channel_main_common_action_timezone_t* Alpcommon_action_timezone, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    {
        p2p_protocol_ipcamera_command_common_set_timezone_resp_t *lpdata_respond = (p2p_protocol_ipcamera_command_common_set_timezone_resp_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_respond->cmd_info.size);
        if (size != sizeof(p2p_protocol_ipcamera_command_common_set_timezone_resp_t)) return rval;
        {
            Alpcommon_action_timezone->option_timezone_current = mem_endian_32((uint32_t)(lpdata_respond->option_timezone));
            p2p_cms_ipcamera_channel_command_common_show_timezone_resp(lpdata_respond->cmd_info.channel_server_handle, Alpcommon_action_timezone->option_timezone_current, Alpstractoin, "SET");
            p2p_cms_ipcamera_channel_command_common_clear_action(&(Alpcommon_action_timezone->action_set));
        }
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_send_set_timezone_req(int32_t Aarray_index, p2p_protocol_ipcamera_command_e Acmd, libpiziot_core_p2p_protocol_optoin_timezone_e Aoption_timezone) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_protocol_ipcamera_command_common_set_timezone_req_t data_request;
    data_request.cmd_info.size = mem_endian_32(sizeof(data_request));
    data_request.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
    data_request.option_timezone = mem_endian_32((uint32_t)Aoption_timezone);
    rval = libpiziot_core_p2p_cms_main_ipcamera_channel_send(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, (unsigned char *) &(data_request), sizeof(data_request));
    return rval;
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_recv_get_timezone_resp(int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_server_t *Alpcmd, p2p_cms_ipcamera_channel_main_common_action_timezone_t *Alpcommon_action_timezone, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    {
        p2p_protocol_ipcamera_command_common_get_timezone_resp_t *lpdata_respond = (p2p_protocol_ipcamera_command_common_get_timezone_resp_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_respond->cmd_info.size);
        if (size != sizeof(p2p_protocol_ipcamera_command_common_get_timezone_resp_t)) return rval;
        {
            Alpcommon_action_timezone->option_timezone_current = mem_endian_32((uint32_t)(lpdata_respond->option_timezone));
            p2p_cms_ipcamera_channel_command_common_show_timezone_resp(lpdata_respond->cmd_info.channel_server_handle, Alpcommon_action_timezone->option_timezone_current, Alpstractoin, "GET");
            p2p_cms_ipcamera_channel_command_common_clear_action(&(Alpcommon_action_timezone->action_get));
        }
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_send_get_timezone_req(int32_t Aarray_index, p2p_protocol_ipcamera_command_e Acmd) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_protocol_ipcamera_command_common_get_timezone_req_t data_request;
    data_request.cmd_info.size = mem_endian_32(sizeof(data_request));
    data_request.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
    rval = libpiziot_core_p2p_cms_main_ipcamera_channel_send(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, (unsigned char *) &(data_request), sizeof(data_request));
    return rval;
}

libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_parser(p2p_protocol_ipcamera_command_e Acmd, int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_server_t *Alpcmd) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    do {
        p2p_cms_ipcamera_channel_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_ipcamera_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        switch (Acmd) {
        case P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_MODEL_RESP: {
            p2p_cms_ipcamera_channel_command_common_recv_get_model_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_common_model), "MODEL");
        }
                                                                  break;
        case P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_FWVERP2P_RESP: {
            p2p_cms_ipcamera_channel_command_common_recv_get_fwverp2p_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_common_fwverp2p), "FWVERP2P");
        }
                                                                     break;
        case P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_SET_REBOOT_RESP: {
            p2p_cms_ipcamera_channel_command_common_recv_set_reboot_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_common_reboot), "REBOOT");
        }
                                                                   break;
        case P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_SET_TIMEZONE_RESP: {
            p2p_cms_ipcamera_channel_command_common_recv_set_timezone_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_common_timezone), "TIMEZONE");
        }
                                                                     break;
        case P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_TIMEZONE_RESP: {
            p2p_cms_ipcamera_channel_command_common_recv_get_timezone_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_common_timezone), "TIMEZONE");
        }
                                                                     break;
        default: {
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
        }
                 break;
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
    return rval;
}

static libpiziot_os_type_func_result_e p2p_cms_ipcamera_channel_command_common_check_time_to_resend_action(p2p_func_client_protocol_action_status_t* Alpprotocol_action_status) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    do {
        if (Alpprotocol_action_status->protocol_action_flag == P2P_FUNC_CLIENT_PROTOCOL_ACTION_BEGIN) {
            Alpprotocol_action_status->protocol_action_flag = P2P_FUNC_CLIENT_PROTOCOL_ACTION_RESEND;
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
        }
        else if (Alpprotocol_action_status->protocol_action_flag == P2P_FUNC_CLIENT_PROTOCOL_ACTION_RESEND) {
            struct timeval pass = libpiziot_os_time_get_pass(&(Alpprotocol_action_status->timeval_action_start));
            if (pass.tv_sec > P2P_FUNC_CLIENT_ACTION_WAIT_SEC) {
                gettimeofday(&Alpprotocol_action_status->timeval_action_start, NULL);
                rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
            }
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
    return rval;
}

void p2p_cms_ipcamera_channel_command_common_send_action(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_cms_ipcamera_channel_main_protocol_command_t *lpprotocol_command = 0;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    {
        rval = libpiziot_core_p2p_cms_ipcamera_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, &lpprotocol_command);
    }
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
    if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        if (p2p_cms_ipcamera_channel_command_common_check_time_to_resend_action(&(lpprotocol_command->action_common_model.action_get)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_ipcamera_channel_command_common_send_get_model_req(Aarray_index, P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_MODEL_REQ);
        }
        if (p2p_cms_ipcamera_channel_command_common_check_time_to_resend_action(&(lpprotocol_command->action_common_fwverp2p.action_get)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_ipcamera_channel_command_common_send_get_fwverp2p_req(Aarray_index, P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_FWVERP2P_REQ);
        }
        if (p2p_cms_ipcamera_channel_command_common_check_time_to_resend_action(&(lpprotocol_command->action_common_reboot.action_set)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_ipcamera_channel_command_common_send_set_reboot_req(Aarray_index, P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_SET_REBOOT_REQ);
        }
        if (p2p_cms_ipcamera_channel_command_common_check_time_to_resend_action(&(lpprotocol_command->action_common_timezone.action_set)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_ipcamera_channel_command_common_send_set_timezone_req(Aarray_index, P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_SET_TIMEZONE_REQ, lpprotocol_command->action_common_timezone.option_timezone_set);
        }
        if (p2p_cms_ipcamera_channel_command_common_check_time_to_resend_action(&(lpprotocol_command->action_common_timezone.action_get)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_ipcamera_channel_command_common_send_get_timezone_req(Aarray_index, P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON_GET_TIMEZONE_REQ);
        }
    }
}

void p2p_cms_ipcamera_channel_command_common_init_action(p2p_cms_ipcamera_channel_main_protocol_command_t *Alpprotocol_command) {
    memset(&(Alpprotocol_command->action_common_model), 0, sizeof(Alpprotocol_command->action_common_model));
    memset(&(Alpprotocol_command->action_common_fwverp2p), 0, sizeof(Alpprotocol_command->action_common_fwverp2p));
    memset(&(Alpprotocol_command->action_common_reboot), 0, sizeof(Alpprotocol_command->action_common_reboot));
    {
        memset(&(Alpprotocol_command->action_common_timezone), 0, sizeof(Alpprotocol_command->action_common_timezone));
        Alpprotocol_command->action_common_timezone.option_timezone_current = LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_UNKNOWN;
    }
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_channel_common_get_model(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    do {
        p2p_cms_ipcamera_channel_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_ipcamera_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_ipcamera_channel_command_common_set_action(&(lpprotocol_command->action_common_model.action_get));
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_channel_common_get_fwverp2p(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    do {
        p2p_cms_ipcamera_channel_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_ipcamera_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_ipcamera_channel_command_common_set_action(&(lpprotocol_command->action_common_fwverp2p.action_get));
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_channel_common_set_reboot(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    do {
        p2p_cms_ipcamera_channel_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_ipcamera_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_ipcamera_channel_command_common_set_action(&(lpprotocol_command->action_common_reboot.action_set));
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_channel_common_set_timezone(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_timezone_e Aoption_timezone) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    do {
        p2p_cms_ipcamera_channel_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_ipcamera_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_ipcamera_channel_command_common_set_action(&(lpprotocol_command->action_common_timezone.action_set));
        lpprotocol_command->action_common_timezone.option_timezone_set = Aoption_timezone;
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_channel_common_get_timezone(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    do {
        p2p_cms_ipcamera_channel_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_ipcamera_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_ipcamera_channel_command_common_set_action(&(lpprotocol_command->action_common_timezone.action_get));
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
    return rval;
}

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_CMS)

#endif //defined(__ESP8266X__)
