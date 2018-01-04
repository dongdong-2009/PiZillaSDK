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

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

//Define this Header
#include "p2p_cms_nas_command_common.h"

//Define Other Header
#include "../../../p2p_protocol_nas.h"
#include "../../../p2p_cms_main/p2p_cms_main.h"
#include "../p2p_cms_nas_main.h"

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

static void p2p_cms_nas_command_security_system_set_action(p2p_func_client_protocol_action_status_t* Alpprotocol_action_status) {
    gettimeofday(&Alpprotocol_action_status->timeval_action_start, NULL);
    Alpprotocol_action_status->protocol_action_flag = P2P_FUNC_CLIENT_PROTOCOL_ACTION_BEGIN;
}

static void p2p_cms_nas_command_security_system_clear_action(p2p_func_client_protocol_action_status_t* Alpprotocol_action_status) {
    Alpprotocol_action_status->protocol_action_flag = P2P_FUNC_CLIENT_PROTOCOL_ACTION_END;
}

static void p2p_cms_nas_command_security_system_show_yn_resp(uint32_t Achannel_server_handle, libpiziot_core_p2p_protocol_optoin_yn_e Aoption_yn, char *Alpstractoin, char *AlpstrSG) {
    char *lpstr_yes = "YES";
    char *lpstr_no = "NO";
    char *lpstr_yn = "";
    switch (Aoption_yn) {
    case LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO: {
        lpstr_yn = lpstr_no;
    }
                                                  break;
    case LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES: {
        lpstr_yn = lpstr_yes;
    }
                                                   break;
    default: {
    }
             break;
    }
    if (Achannel_server_handle == LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA) {
        TRACEA("BROADCAST CMS NAS ZIGBEE %s %s RESP %s\n", AlpstrSG, Alpstractoin, lpstr_yn);
    }
    else {
        TRACEA("CMS NAS ZIGBEE %s %s RESP %s\n", AlpstrSG, Alpstractoin, lpstr_yn);
    }
}

static libpiziot_os_type_func_result_e p2p_cms_nas_command_security_system_recv_set_yn_resp(int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_server_t *Alpcmd, p2p_cms_nas_main_zigbee_action_general_t* Alpzigbee_action_general, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    {
        p2p_protocol_nas_command_security_system_set_yn_resp_t *lpdata_respond = (p2p_protocol_nas_command_security_system_set_yn_resp_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_respond->cmd_info.size);
        if (size != sizeof(p2p_protocol_nas_command_security_system_set_yn_resp_t)) return rval;
        {
            libpiziot_core_p2p_protocol_optoin_yn_e option_yn = mem_endian_32((uint32_t)(lpdata_respond->option_yn));
            p2p_cms_nas_command_security_system_show_yn_resp(lpdata_respond->cmd_info.channel_server_handle, option_yn, Alpstractoin, "SET");
            p2p_cms_nas_command_security_system_clear_action(&(Alpzigbee_action_general->action_set));
        }
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_cms_nas_command_security_system_send_set_yn_req(int32_t Aarray_index, p2p_protocol_nas_command_e Acmd, libpiziot_core_p2p_protocol_optoin_yn_e Aoption_yn) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_protocol_nas_command_security_system_set_yn_req_t data_request;
    data_request.cmd_info.size = mem_endian_32(sizeof(data_request));
    data_request.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
    data_request.option_yn = mem_endian_32((uint32_t)Aoption_yn);
    rval = libpiziot_core_p2p_cms_main_nas_channel_send(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, (unsigned char *) &(data_request), sizeof(data_request));
    return rval;
}

static libpiziot_os_type_func_result_e p2p_cms_nas_command_security_system_recv_get_yn_resp(int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_server_t *Alpcmd, p2p_cms_nas_main_zigbee_action_general_t* Alpzigbee_action_general, char *Alpstractoin) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    {
        p2p_protocol_nas_command_security_system_get_yn_resp_t *lpdata_respond = (p2p_protocol_nas_command_security_system_get_yn_resp_t *)Alpcmd;
        uint32_t size = mem_endian_32(lpdata_respond->cmd_info.size);
        if (size != sizeof(p2p_protocol_nas_command_security_system_get_yn_resp_t)) return rval;
        {
            libpiziot_core_p2p_protocol_optoin_yn_e option_yn = mem_endian_32((uint32_t)(lpdata_respond->option_yn));
            p2p_cms_nas_command_security_system_show_yn_resp(lpdata_respond->cmd_info.channel_server_handle, option_yn, Alpstractoin, "GET");
            p2p_cms_nas_command_security_system_clear_action(&(Alpzigbee_action_general->action_get));
        }
    }
    return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
}

static libpiziot_os_type_func_result_e p2p_cms_nas_command_security_system_send_get_yn_req(int32_t Aarray_index, p2p_protocol_nas_command_e Acmd) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_protocol_nas_command_security_system_get_yn_req_t data_request;
    data_request.cmd_info.size = mem_endian_32(sizeof(data_request));
    data_request.cmd_info.cmd = mem_endian_32(((uint32_t)Acmd));
    rval = libpiziot_core_p2p_cms_main_nas_channel_send(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, (unsigned char *) &(data_request), sizeof(data_request));
    return rval;
}

libpiziot_os_type_func_result_e p2p_cms_nas_command_security_system_parser(p2p_protocol_nas_command_e Acmd, int32_t Aarray_index, libpiziot_core_p2p_cmd_head_from_server_t *Alpcmd) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    do {
        p2p_cms_nas_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_nas_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        switch (Acmd) {
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_LOCK_RESP: {
            rval = p2p_cms_nas_command_security_system_recv_set_yn_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_zigbee_lock), "LOCK");
        }
                                                            break;
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_LOCK_RESP: {
            rval = p2p_cms_nas_command_security_system_recv_get_yn_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_zigbee_lock), "LOCK");
        }
                                                            break;
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_MUTE_RESP: {
            rval = p2p_cms_nas_command_security_system_recv_set_yn_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_zigbee_mute), "MUTE");
        }
                                                            break;
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_MUTE_RESP: {
            rval = p2p_cms_nas_command_security_system_recv_get_yn_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_zigbee_mute), "MUTE");
        }
                                                            break;
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_CALLOUT_RESP: {
            rval = p2p_cms_nas_command_security_system_recv_set_yn_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_zigbee_callout), "CALLOUT");
        }
                                                               break;
        case P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_CALLOUT_RESP: {
            rval = p2p_cms_nas_command_security_system_recv_get_yn_resp(Aarray_index, Alpcmd, &(lpprotocol_command->action_zigbee_callout), "CALLOUT");
        }
                                                               break;
        default: {
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
        }
                 break;
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
    return rval;
}

static libpiziot_os_type_func_result_e p2p_cms_nas_command_security_system_check_time_to_resend_action(p2p_func_client_protocol_action_status_t* Alpprotocol_action_status) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
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
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
    return rval;
}

void p2p_cms_nas_command_security_system_send_action(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_cms_nas_main_protocol_command_t *lpprotocol_command = 0;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    {
        rval = libpiziot_core_p2p_cms_nas_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command);
    }
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
    if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        if (p2p_cms_nas_command_security_system_check_time_to_resend_action(&(lpprotocol_command->action_zigbee_lock.action_set)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_nas_command_security_system_send_set_yn_req(Aarray_index, P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_LOCK_REQ, lpprotocol_command->action_zigbee_lock.option_yn_set);
        }
        if (p2p_cms_nas_command_security_system_check_time_to_resend_action(&(lpprotocol_command->action_zigbee_lock.action_get)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_nas_command_security_system_send_get_yn_req(Aarray_index, P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_LOCK_REQ);
        }
        if (p2p_cms_nas_command_security_system_check_time_to_resend_action(&(lpprotocol_command->action_zigbee_mute.action_set)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_nas_command_security_system_send_set_yn_req(Aarray_index, P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_MUTE_REQ, lpprotocol_command->action_zigbee_mute.option_yn_set);
        }
        if (p2p_cms_nas_command_security_system_check_time_to_resend_action(&(lpprotocol_command->action_zigbee_mute.action_get)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_nas_command_security_system_send_get_yn_req(Aarray_index, P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_MUTE_REQ);
        }
        if (p2p_cms_nas_command_security_system_check_time_to_resend_action(&(lpprotocol_command->action_zigbee_callout.action_set)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_nas_command_security_system_send_set_yn_req(Aarray_index, P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_SET_CALLOUT_REQ, lpprotocol_command->action_zigbee_callout.option_yn_set);
        }
        if (p2p_cms_nas_command_security_system_check_time_to_resend_action(&(lpprotocol_command->action_zigbee_callout.action_get)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            p2p_cms_nas_command_security_system_send_get_yn_req(Aarray_index, P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM_GET_CALLOUT_REQ);
        }
    }
}

void p2p_cms_nas_command_security_system_init_action(p2p_cms_nas_main_protocol_command_t *Alpprotocol_command) {
    memset(&(Alpprotocol_command->action_zigbee_lock), 0, sizeof(Alpprotocol_command->action_zigbee_lock));
    memset(&(Alpprotocol_command->action_zigbee_mute), 0, sizeof(Alpprotocol_command->action_zigbee_mute));
    memset(&(Alpprotocol_command->action_zigbee_callout), 0, sizeof(Alpprotocol_command->action_zigbee_callout));
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_yn_e Aoption_yn) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    do {
        p2p_cms_nas_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_nas_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_nas_command_security_system_set_action(&(lpprotocol_command->action_zigbee_lock.action_set));
        lpprotocol_command->action_zigbee_lock.option_yn_set = Aoption_yn;
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    do {
        p2p_cms_nas_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_nas_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_nas_command_security_system_set_action(&(lpprotocol_command->action_zigbee_lock.action_get));
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_yn_e Aoption_yn) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    do {
        p2p_cms_nas_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_nas_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_nas_command_security_system_set_action(&(lpprotocol_command->action_zigbee_mute.action_set));
        lpprotocol_command->action_zigbee_mute.option_yn_set = Aoption_yn;
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    do {
        p2p_cms_nas_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_nas_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_nas_command_security_system_set_action(&(lpprotocol_command->action_zigbee_mute.action_get));
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_yn_e Aoption_yn) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    do {
        p2p_cms_nas_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_nas_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_nas_command_security_system_set_action(&(lpprotocol_command->action_zigbee_callout.action_set));
        lpprotocol_command->action_zigbee_callout.option_yn_set = Aoption_yn;
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    do {
        p2p_cms_nas_main_protocol_command_t *lpprotocol_command;
        if (libpiziot_core_p2p_cms_nas_get_protocol_command(Aarray_index, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        p2p_cms_nas_command_security_system_set_action(&(lpprotocol_command->action_zigbee_callout.action_get));
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
    return rval;
}

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(ENABLE_P2P_CMS)

#endif //defined(__ESP8266X__)
