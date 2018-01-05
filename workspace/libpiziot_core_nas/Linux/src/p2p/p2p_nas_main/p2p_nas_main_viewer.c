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
#include "../../../include/menu_config.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"

#if defined(__ESP8266X__)
#else

#if defined(ENABLE_P2P_NAS)

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_clientsdk.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

//Define this Header
#include "p2p_nas_main_viewer.h"

//Define Other Header
#include "../p2p_func.h"
#include "../p2p_func_client.h"

#include "../p2p_protocol_ipcamera.h"
#include "../p2p_nas_channel_client_main/ipcamera_data/p2p_nas_ipcamera_channel_main.h"
#include "../p2p_nas_channel_client_main/ipcamera_data/p2p_nas_ipcamera_channel_command.h"
#include "../p2p_nas_channel_client_main/ipcamera_data/p2p_nas_ipcamera_channel_other.h"

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#include "../p2p_nas_channel_client_main/ipcamera_data/command/p2p_nas_ipcamera_channel_command_common.h"
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

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

static libpiziot_os_type_func_result_e p2p_nas_main_viewer_get_net_status(int32_t Aviewer_handle, libpiziot_p2p_common_result_e *Alpviewer_net_status) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        libpiziot_p2p_common_result_e viewer_net_result = LIBPIZIOT_P2P_COMMON_RESULT_UNKNOWN_MESSAGE_TYPE;
        rval = libpiziot_p2p_clientsdk_get_viewer_net_status(Aviewer_handle, &viewer_net_result);
        if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        if (viewer_net_result != (*Alpviewer_net_status)) {
            (*Alpviewer_net_status) = viewer_net_result;
            switch (viewer_net_result) {
            case LIBPIZIOT_P2P_COMMON_RESULT_CONNECTING: {
                TRACEA("PIZNasCam:VIEWER HANDLE:(%d) CONNECTING\n", Aviewer_handle);
            }
                                                        break;
            case LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_DEVICE_IN_LAN: {
                TRACEA("PIZNasCam:VIEWER HANDLE:(%d) LAN_DEVICE_IN_LAN\n", Aviewer_handle);
            }
                                                                    break;
            case LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_DEVICE_IN_WAN: {
                TRACEA("PIZNasCam:VIEWER HANDLE:(%d) LAN_DEVICE_IN_WAN\n", Aviewer_handle);
            }
                                                                    break;
            case LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_DEVICE: {
                TRACEA("PIZNasCam:VIEWER HANDLE:(%d) WAN_DEVICE\n", Aviewer_handle);
            }
                                                             break;
            default: {
                TRACEA("PIZNasCam:VIEWER HANDLE:(%d) ERROR !! = %d\n", Aviewer_handle, viewer_net_result);
            }
                     break;
            }
        }
    } while (0);
    return rval;
}

static void p2p_nas_main_viewer_channel_update_mode(p2p_nas_main_viewer_thread_info_t *Alpthread_info, int32_t Aviewer_handle, int32_t Achannel_id, libpiziot_os_pthread_routine_p Alppthread_routine, libpiziot_p2p_common_channel_data_in_p Alpdata_in_callback, int32_t Asend_data_max_size, int32_t Arecv_data_max_size, p2p_func_client_channel_aes_e Aenable_channel_aes, libpiziot_p2p_common_relay_data_type_e Adata_type, p2p_nas_ipcamera_channel_main_protocol_command_t *Alpprotocol_command) {
    p2p_func_client_channel_enable_e mode;
    if (Alpthread_info->update_thread_info_index >= P2P_PROTOCOL_IPCAMERA_CHANNEL_COUNT) return;
    libpiziot_os_mutex_plock_lock(&p2p_nas_main_viewer_channel_mutex);
    {
        mode = p2p_function_client_channel_check_enable(&(Alpprotocol_command->channel_enable_flag));
    }
    libpiziot_os_mutex_plock_unlock(&p2p_nas_main_viewer_channel_mutex);
    if (mode == P2P_FUNC_CLIENT_CHANNEL_ENABLE_YES) {
        p2p_nas_ipcamera_channel_main_start_thread(Alpthread_info, Aviewer_handle, Alpthread_info->update_thread_info_index, Achannel_id, Alppthread_routine, Alpdata_in_callback, Asend_data_max_size, Arecv_data_max_size, Aenable_channel_aes, Adata_type);
        {
            libpiziot_os_mutex_plock_lock(&p2p_nas_main_viewer_channel_mutex);
            {
                Alpprotocol_command->lpthread_info = Alpthread_info->lpp2p_nas_ipcamera_channel_main_thread_info[Alpthread_info->update_thread_info_index];
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
                {
                    p2p_nas_ipcamera_channel_command_common_init_action(Alpprotocol_command);
                }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
            }
            libpiziot_os_mutex_plock_unlock(&p2p_nas_main_viewer_channel_mutex);
        }
    }
    if (mode == P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO) {
        libpiziot_os_mutex_plock_lock(&p2p_nas_main_viewer_channel_mutex);
        {
            Alpprotocol_command->lpthread_info = 0;
        }
        libpiziot_os_mutex_plock_unlock(&p2p_nas_main_viewer_channel_mutex);
        p2p_nas_ipcamera_channel_main_stop_thread(Alpthread_info, Alpthread_info->update_thread_info_index);
    }
    Alpthread_info->update_thread_info_index++;
}

static void p2p_nas_main_viewer_start_channel_thread(p2p_nas_main_viewer_thread_info_t *Alpthread_info) {
    if (Alpthread_info) {
        Alpthread_info->update_thread_info_index = 0;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
        p2p_nas_main_viewer_channel_update_mode(Alpthread_info, Alpthread_info->p2p_nas_main_viewer_handle, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND, p2p_nas_ipcamera_channel_command_thread_instance_routine, p2p_nas_ipcamera_channel_command_data_in_callback, p2p_protocol_ipcamera_command_viewer_send_data_max_size, p2p_protocol_ipcamera_command_viewer_recv_data_max_size, P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE, LIBPIZIOT_P2P_COMMON_RELAY_DATA_TYPE_DATA, &(Alpthread_info->protocol_command));
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_LIVE_VIDEO_TO_APP)
        //1, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_LIVE_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_LIVE_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_LIVE_AUDIO_TO_APP)
//2, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_LIVE_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_LIVE_AUDIO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_LIVE_AUDIO_FROM_APP)
//3, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_LIVE_AUDIO_FROM_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_LIVE_AUDIO_FROM_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_PLAYBACK_VIDEO_TO_APP)
//4, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_PLAYBACK_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_PLAYBACK_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_PLAYBACK_AUDIO_TO_APP)
//5, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_PLAYBACK_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_01_PLAYBACK_AUDIO_TO_APP)

#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_LIVE_VIDEO_TO_APP)
//6, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_LIVE_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_LIVE_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_LIVE_AUDIO_TO_APP)
//7, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_LIVE_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_LIVE_AUDIO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_LIVE_AUDIO_FROM_APP)
//8, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_LIVE_AUDIO_FROM_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_LIVE_AUDIO_FROM_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_PLAYBACK_VIDEO_TO_APP)
//9, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_PLAYBACK_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_PLAYBACK_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_PLAYBACK_AUDIO_TO_APP)
//10, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_PLAYBACK_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_02_PLAYBACK_AUDIO_TO_APP)

#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_LIVE_VIDEO_TO_APP)
//11, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_LIVE_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_LIVE_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_LIVE_AUDIO_TO_APP)
//12, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_LIVE_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_LIVE_AUDIO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_LIVE_AUDIO_FROM_APP)
//13, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_LIVE_AUDIO_FROM_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_LIVE_AUDIO_FROM_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_PLAYBACK_VIDEO_TO_APP)
//14, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_PLAYBACK_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_PLAYBACK_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_PLAYBACK_AUDIO_TO_APP)
//15, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_PLAYBACK_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_03_PLAYBACK_AUDIO_TO_APP)

#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_LIVE_VIDEO_TO_APP)
//16, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_LIVE_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_LIVE_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_LIVE_AUDIO_TO_APP)
//17, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_LIVE_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_LIVE_AUDIO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_LIVE_AUDIO_FROM_APP)
//18, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_LIVE_AUDIO_FROM_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_LIVE_AUDIO_FROM_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_PLAYBACK_VIDEO_TO_APP)
//19, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_PLAYBACK_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_PLAYBACK_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_PLAYBACK_AUDIO_TO_APP)
//20, LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_PLAYBACK_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_IPCAMERA_CHANNEL_04_PLAYBACK_AUDIO_TO_APP)

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
        p2p_nas_main_viewer_channel_update_mode(Alpthread_info, Alpthread_info->p2p_nas_main_viewer_handle, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER, p2p_nas_ipcamera_channel_other_thread_instance_routine, p2p_nas_ipcamera_channel_other_data_in_callback, p2p_protocol_ipcamera_other_viewer_send_data_max_size, p2p_protocol_ipcamera_other_viewer_recv_data_max_size, P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE, LIBPIZIOT_P2P_COMMON_RELAY_DATA_TYPE_DATA, &(Alpthread_info->protocol_other));
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
    }
}

static void p2p_nas_main_viewer_stop_channel_thread(p2p_nas_main_viewer_thread_info_t *Alpthread_info) {
    p2p_nas_ipcamera_channel_main_stop_thread_all(Alpthread_info);
}

static void p2p_nas_main_viewer_create_p2p_viewer(p2p_nas_main_viewer_thread_info_t *Alpthread_info, const char *AlpUID) {
    unsigned char device_account[LIBPIZIOT_P2P_COMMON_DEVICE_ACCOUNT_LENGTH_MAX + 1];
    unsigned char device_password[LIBPIZIOT_P2P_COMMON_DEVICE_PASSWORD_LENGTH_MAX + 1];

    TRACEA("PIZNasCam:UID=\"%s\"\n", AlpUID);

    {
#define CONNECT_SERVER_SOCKET_INFO_COUNT 1
        libpiziot_p2p_common_connect_server_socket_info_t connect_server_socket_info[CONNECT_SERVER_SOCKET_INFO_COUNT];
        libpiziot_p2p_common_connect_session_type_e select_net_type = LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_NONE;

        {
            connect_server_socket_info[0].socket_type = LIBPIZIOT_P2P_COMMON_CONNECT_SOCKET_TYPE_UDP;
            connect_server_socket_info[0].server_port = SAMPLE_CODE_P2P_SERVER_PORT_DEFAULT;
            if (strlen(SAMPLE_CODE_P2P_SERVER_ADDR) > P2P_NET_COMMON_SERVER_DOMAIN_LEN_MAX) return;
            memset_addr(char, connect_server_socket_info[0].lpserver_domain, 0, P2P_NET_COMMON_SERVER_DOMAIN_LEN_MAX);
            sprintf(connect_server_socket_info[0].lpserver_domain, "%s", SAMPLE_CODE_P2P_SERVER_ADDR);
        }

        {
            //select_net_type |= LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_LAN;
            //select_net_type |= LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_PTP;
            //select_net_type |= LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_RELAY;
            select_net_type |= LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_AUTO;
            select_net_type |= LIBPIZIOT_P2P_COMMON_CONNECT_SESSION_TYPE_AUTO_RELOGIN_WHEN_ERROR;
        }

        if (p2p_func_client_viewer_get_ipcamera_device_key(&(Alpthread_info->login_aes.aes_key), Alpthread_info->login_aes.cbc_iv, device_account, LIBPIZIOT_P2P_COMMON_DEVICE_ACCOUNT_LENGTH_MAX, device_password, LIBPIZIOT_P2P_COMMON_DEVICE_PASSWORD_LENGTH_MAX) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) return;

        if (libpiziot_p2p_clientsdk_create_viewer(connect_server_socket_info, CONNECT_SERVER_SOCKET_INFO_COUNT, SAMPLE_CODE_P2P_LAN_SERVER_PORT_DEFAULT, AlpUID, select_net_type, device_account, device_password, &(Alpthread_info->p2p_nas_main_viewer_handle)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}

static void p2p_nas_main_viewer_delete_p2p_viewer(p2p_nas_main_viewer_thread_info_t *Alpthread_info) {
    p2p_nas_main_viewer_stop_channel_thread(Alpthread_info);
    if (Alpthread_info->p2p_nas_main_viewer_handle >= 0) {
        libpiziot_p2p_clientsdk_delete_viewer(Alpthread_info->p2p_nas_main_viewer_handle);
        Alpthread_info->p2p_nas_main_viewer_handle = -1;
    }
}

static libpiziot_os_pthread_dword_t p2p_nas_main_viewer_thread_instance_routine(void *arg) {
    libpiziot_os_pthread_instance_t *lpthread_instance = (libpiziot_os_pthread_instance_t *)arg;
    p2p_nas_main_viewer_thread_info_t *lpthread_info = (p2p_nas_main_viewer_thread_info_t *)(lpthread_instance->m_extra);

    TRACEB("%s:start_routine ...\n", LIBPIZIOT_OS__FUNCTION__);

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    usleep(1000000);
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

    {
        libpiziot_p2p_common_result_e viewer_net_result = LIBPIZIOT_P2P_COMMON_RESULT_UNKNOWN_MESSAGE_TYPE;
        do {
            usleep(1000);
            if (libpiziot_os_pthread_check_break(lpthread_instance, LIBPIZIOT_OS__FUNCTION__, __LINE__)) {
                TRACEB("%s:BreakThread\n", LIBPIZIOT_OS__FUNCTION__);
                break;
            }
            if (lpthread_info->p2p_nas_main_viewer_handle == -1) {
                usleep(1000000);
                p2p_nas_main_viewer_create_p2p_viewer(lpthread_info, lpthread_info->lpuuid);
                continue;
            }
            else {
                p2p_nas_main_viewer_start_channel_thread(lpthread_info);
            }
            do {
                libpiziot_os_type_func_result_e rval = p2p_nas_main_viewer_get_net_status(lpthread_info->p2p_nas_main_viewer_handle, &viewer_net_result);
                if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                    usleep(500000);
                    break;
                }
            } while (0);
        } while (1);
    }

    TRACEB("%s:end_routine ...\n", LIBPIZIOT_OS__FUNCTION__);

    p2p_nas_main_viewer_delete_p2p_viewer(lpthread_info);

    return (libpiziot_os_pthread_dword_t)1234567;
}

libpiziot_os_type_func_result_e p2p_nas_main_viewer_connect_device(p2p_nas_main_viewer_thread_info_t *Alpthread_info, const char *AlpUID) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Alpthread_info == 0) return rval;
    {
        if (Alpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return rval;
        libpiziot_os_mutex_plock_lock(&(Alpthread_info->instance_mutex));
        do {
            if ((libpiziot_os_pthread_get_status(&(Alpthread_info->thread_instance)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED)) {
                break;
            }
            if ((libpiziot_os_pthread_get_status(&(Alpthread_info->thread_instance)) == LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED)) {
                {
                    size_t len = strlen(AlpUID);
                    if (len > P2P_FUNC_UID_LENGTH_MAX) break;
                    memcpy(Alpthread_info->lpuuid, AlpUID, len);
                    Alpthread_info->lpuuid[len] = 0;
                }
                if (libpiziot_os_pthread_create(&(Alpthread_info->thread_instance), p2p_nas_main_viewer_thread_instance_routine, LIBPIZIOT_OS_PTHREAD_STACK_SIZE_AUTO, "core_nas_viewer") != 0) {
                    TRACEA("%s:CreateUserPthread,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                    break;
                }
                TRACEB("%s:Thread running ...\n", LIBPIZIOT_OS__FUNCTION__);
            }
            else {
                TRACEA("%s:already running,ignore start thread ...\n", LIBPIZIOT_OS__FUNCTION__);
            }
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
        } while (0);
        libpiziot_os_mutex_plock_unlock(&(Alpthread_info->instance_mutex));
    }
    return rval;
}

void p2p_nas_main_viewer_disconnect_device(p2p_nas_main_viewer_thread_info_t *Alpthread_info) {
    if (Alpthread_info == 0) return;
    {
        if (Alpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return;
        {
            int32_t msg = 0;
            if (libpiziot_os_pthread_get_status(&(Alpthread_info->thread_instance)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED) msg = 1;
            //if (msg == 1)
            //{
            // TRACEB("%s:libpiziot_os_pthread_release(...)\n", LIBPIZIOT_OS__FUNCTION__);
            // LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            //}
            libpiziot_os_pthread_release(&(Alpthread_info->thread_instance));
            if (msg == 1) {
                TRACEB("%s:WaitUserPthread ...\n", LIBPIZIOT_OS__FUNCTION__);
                LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            }
            libpiziot_os_pthread_join(&(Alpthread_info->thread_instance));
            if (msg == 1) {
                TRACEB("%s:THREAD_HANDLE_CLOSED ...\n", LIBPIZIOT_OS__FUNCTION__);
                LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            }
        }
    }
}

libpiziot_os_type_func_result_e p2p_nas_main_viewer_finalize(p2p_nas_main_viewer_thread_info_t **Alpp_thread_info) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    do {
        p2p_nas_main_viewer_thread_info_t *lpthread_info = (*Alpp_thread_info);
        if (lpthread_info == 0) break;
        if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) break;
        {
            p2p_nas_ipcamera_channel_main_finalize(lpthread_info);
        }
        {
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            p2p_func_client_aes_free_cb(&(lpthread_info->login_aes));
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        {
            if (libpiziot_os_pthread_finalize(&(lpthread_info->thread_instance)) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
            }
            if (libpiziot_os_mutex_plock_free(&(lpthread_info->instance_mutex)) != 0) {
                TRACEA("%s:mutex free &lpthread_info->instance_mutex,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
            }
        }
        {
            libpiziot_os_free(lpthread_info);
            (*Alpp_thread_info) = 0;
        }
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

libpiziot_os_type_func_result_e p2p_nas_main_viewer_initialize(p2p_nas_main_viewer_thread_info_t **Alpp_thread_info) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_nas_main_viewer_thread_info_t *lpthread_info = 0;
    do {
        if ((*Alpp_thread_info) != 0) {
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
            break;
        }
#if (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
#elif defined(__ESP8266X__)
#else
        {
            uint64_t free_memory_size = libpiziot_os_mem_get_system_total_free_memory();
            if ((free_memory_size + sizeof(p2p_nas_main_viewer_thread_info_t)) < LIBPIZIOT_P2P_COMMON_SYSTEM_MEMORY_MINIMUM_SIZE) {
                //TRACEA("channel client out of memory when add client,error !!\n");
                break;
            }
        }
#endif //(defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
        lpthread_info = (p2p_nas_main_viewer_thread_info_t *)libpiziot_os_malloc(sizeof(p2p_nas_main_viewer_thread_info_t));
        if (lpthread_info == 0) {
            TRACEA("%s:out of memory,error !!\n", LIBPIZIOT_OS__FUNCTION__);
            break;
        }
        (*Alpp_thread_info) = lpthread_info;
        {
            memset_addr(p2p_nas_main_viewer_thread_info_t, lpthread_info, 0, sizeof(p2p_nas_main_viewer_thread_info_t));
            lpthread_info->p2p_nas_main_viewer_handle = -1;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
            lpthread_info->protocol_command.channel_enable_flag.current = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            lpthread_info->protocol_command.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            lpthread_info->protocol_command.lpthread_info = 0;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            lpthread_info->protocol_other.channel_enable_flag.current = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            lpthread_info->protocol_other.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            lpthread_info->protocol_other.lpthread_info = 0;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            if (libpiziot_os_mutex_plock_init(&(lpthread_info->instance_mutex), NULL) != 0) {
                TRACEA("%s:mutex init instance_mutex,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                break;
            }
            rval = libpiziot_os_pthread_initialize(&(lpthread_info->thread_instance), LIBPIZIOT_OS__FUNCTION__, __LINE__);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            lpthread_info->thread_instance.m_extra = lpthread_info;
            {
                {
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
                    rval = p2p_func_client_aes_init_cb(&(lpthread_info->login_aes), SAMPLE_CODE_P2P_DEVICE_LOGIN_CB, SAMPLE_CODE_P2P_DEVICE_LOGIN_IV);
                    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
                }
                {
                    if (p2p_nas_ipcamera_channel_main_initialize(lpthread_info) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                        break;
                    }
                }
            }
        }
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        p2p_nas_main_viewer_finalize(Alpp_thread_info);
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

#endif //defined(ENABLE_P2P_NAS)

#endif //defined(__ESP8266X__)
