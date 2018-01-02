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

#if defined(ENABLE_P2P_NAS)

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_clientsdk.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

//Define this Header
#include "p2p_nas_main_device.h"

//Define Other Header
#include "../p2p_func.h"
#include "../p2p_func_client.h"

#include "../p2p_protocol_nas.h"
#include "../p2p_nas_channel_server_main/nas_data/p2p_nas_device_main.h"
#include "../p2p_nas_channel_server_main/nas_data/p2p_nas_device_command.h"
#include "../p2p_nas_channel_server_main/nas_data/p2p_nas_device_other.h"

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

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#elif defined(__ESP8266X__)
#else
#define SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

typedef enum p2p_nas_main_device_thread_step_enum {
    P2P_NAS_MAIN_DEVICE_THREAD_STEP_NORMAL = 1,
#if defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)
    P2P_NAS_MAIN_DEVICE_THREAD_STEP_CHECKER = 2,
#endif //defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)
} p2p_nas_main_device_thread_step_e;

#if defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)
static int32_t p2p_nas_main_device_exist_checker_handle = -1;
#endif //defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)

char *libpiziot_core_p2p_get_nas_uid(void) {
#if defined(ENABLE_P2P_NAS) && defined(ENABLE_P2P_CMS)
    const char *lpUID = p2p_func_client_get_nas_uuid_from_mtd();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__)
    const char *lpUID = p2p_func_client_get_nas_uuid_from_mtd();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8197__)
    const char *lpUID = p2p_func_client_get_nas_uuid_from_mtd();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3520D__)
    const char *lpUID = p2p_func_client_get_nas_uuid_from_mtd();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518E__)
    const char *lpUID = p2p_func_client_p2p_get_device_mac_address();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518EV2__)
    const char *lpUID = p2p_func_client_p2p_get_device_mac_address();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_BCM28XX_RASPBERRY__)
    const char *lpUID = p2p_func_client_p2p_get_device_mac_address();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8881__)
    const char *lpUID = p2p_func_client_p2p_get_device_mac_address();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8196__)
    const char *lpUID = p2p_func_client_p2p_get_device_mac_address();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RK3328_ROCK64__)
    const char *lpUID = p2p_func_client_p2p_get_device_mac_address();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_MT7688_LINKIT__)
    const char *lpUID = p2p_func_client_p2p_get_device_mac_address();
#elif defined(ENABLE_CONFIG_APPLE_BOX007)
    const char *lpUID = p2p_func_client_get_nas_uuid_from_mtd();
#elif defined(__ESP8266X__)
    extern char* user_main_get_mac_addr(void);
    const char *lpUID = user_main_get_mac_addr();
#else
#error
#endif
    return (char *)lpUID;
}

#if defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)

static libpiziot_os_type_func_result_e p2p_nas_main_device_create_p2p_device_exist_checker(const char *AlpUID) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
#define CONNECT_SERVER_SOCKET_INFO_COUNT 1
    libpiziot_p2p_common_connect_server_socket_info_t connect_server_socket_info[CONNECT_SERVER_SOCKET_INFO_COUNT];
    libpiziot_p2p_common_connect_session_type_e select_net_type = LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_NONE;

    {
        connect_server_socket_info[0].socket_type = LIBPIZIOT_P2P_COMMON_CONNECT_SOCKET_TYPE_UDP;
        connect_server_socket_info[0].server_port = SAMPLE_CODE_P2P_SERVER_PORT_DEFAULT;
        if (strlen(SAMPLE_CODE_P2P_SERVER_ADDR) > P2P_NET_COMMON_SERVER_DOMAIN_LEN_MAX) return rval;
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

    {
        TRACEA("PIZNas:Check UID=\"%s\"\n", AlpUID);
    }
    rval = libpiziot_p2p_clientsdk_create_viewer(connect_server_socket_info, CONNECT_SERVER_SOCKET_INFO_COUNT, SAMPLE_CODE_P2P_LAN_SERVER_PORT_DEFAULT, AlpUID, select_net_type, (unsigned char *) "", (unsigned char *) "", &p2p_nas_main_device_exist_checker_handle);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        TRACEA("PIZNas:Check UID=\"%s\",error !!\n", AlpUID);
    }
    return rval;
}

static void p2p_nas_main_device_delete_p2p_device_exist_checker(void) {
    if (p2p_nas_main_device_exist_checker_handle >= 0) {
        libpiziot_p2p_clientsdk_delete_viewer(p2p_nas_main_device_exist_checker_handle);
        p2p_nas_main_device_exist_checker_handle = -1;
    }
}

#endif //defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)

static void p2p_nas_main_device_channel_update_mode(p2p_nas_main_device_thread_info_t *Alpthread_info, int32_t Adevice_handle, int32_t Achannel_id, libpiziot_os_pthread_routine_p Alppthread_routine, libpiziot_p2p_common_channel_data_in_p Alpdata_in_callback, int32_t Asend_data_max_size, int32_t Asend_buffer_size, int32_t Arecv_data_max_size, p2p_func_client_channel_aes_e Aenable_channel_aes, p2p_nas_device_main_protocol_command_t *Alpprotocol_command) {
    p2p_func_client_channel_enable_e mode;
    if (Alpthread_info->update_thread_info_index >= P2P_PROTOCOL_NAS_CHANNEL_COUNT) return;
    libpiziot_os_mutex_plock_lock(&p2p_nas_main_device_channel_mutex);
    {
        mode = p2p_function_client_channel_check_enable(&(Alpprotocol_command->channel_enable_flag));
    }
    libpiziot_os_mutex_plock_unlock(&p2p_nas_main_device_channel_mutex);
    if (mode == P2P_FUNC_CLIENT_CHANNEL_ENABLE_YES) {
        p2p_nas_device_main_start_thread(Alpthread_info, Adevice_handle, Alpthread_info->update_thread_info_index, Achannel_id, Alppthread_routine, Alpdata_in_callback, Asend_data_max_size, Asend_buffer_size, Arecv_data_max_size, Aenable_channel_aes);
        {
            libpiziot_os_mutex_plock_lock(&p2p_nas_main_device_channel_mutex);
            {
                Alpprotocol_command->lpthread_info = Alpthread_info->lpp2p_nas_device_main_thread_info[Alpthread_info->update_thread_info_index];
            }
            libpiziot_os_mutex_plock_unlock(&p2p_nas_main_device_channel_mutex);
        }
    }
    if (mode == P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO) {
        libpiziot_os_mutex_plock_lock(&p2p_nas_main_device_channel_mutex);
        {
            Alpprotocol_command->lpthread_info = 0;
        }
        libpiziot_os_mutex_plock_unlock(&p2p_nas_main_device_channel_mutex);
        p2p_nas_device_main_stop_thread(Alpthread_info, Alpthread_info->update_thread_info_index);
    }
    Alpthread_info->update_thread_info_index++;
}

static void p2p_nas_main_device_start_channel_thread(p2p_nas_main_device_thread_info_t *Alpthread_info) {
    if (Alpthread_info) {
        Alpthread_info->update_thread_info_index = 0;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
        p2p_nas_main_device_channel_update_mode(Alpthread_info, Alpthread_info->p2p_nas_main_device_handle, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND, p2p_nas_device_command_thread_instance_routine, p2p_nas_device_command_data_in_callback, p2p_protocol_nas_command_device_send_data_max_size, p2p_protocol_nas_command_device_send_data_max_size, p2p_protocol_nas_command_device_recv_data_max_size, P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE, &(Alpthread_info->protocol_command));
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_LIVE_VIDEO_TO_APP)
        //1, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_LIVE_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_LIVE_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_LIVE_AUDIO_TO_APP)
//2, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_LIVE_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_LIVE_AUDIO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_LIVE_AUDIO_FROM_APP)
//3, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_LIVE_AUDIO_FROM_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_LIVE_AUDIO_FROM_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_PLAYBACK_VIDEO_TO_APP)
//4, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_PLAYBACK_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_PLAYBACK_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_PLAYBACK_AUDIO_TO_APP)
//5, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_PLAYBACK_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_01_PLAYBACK_AUDIO_TO_APP)

#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_LIVE_VIDEO_TO_APP)
//6, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_LIVE_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_LIVE_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_LIVE_AUDIO_TO_APP)
//7, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_LIVE_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_LIVE_AUDIO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_LIVE_AUDIO_FROM_APP)
//8, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_LIVE_AUDIO_FROM_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_LIVE_AUDIO_FROM_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_PLAYBACK_VIDEO_TO_APP)
//9, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_PLAYBACK_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_PLAYBACK_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_PLAYBACK_AUDIO_TO_APP)
//10, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_PLAYBACK_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_02_PLAYBACK_AUDIO_TO_APP)

#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_LIVE_VIDEO_TO_APP)
//11, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_LIVE_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_LIVE_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_LIVE_AUDIO_TO_APP)
//12, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_LIVE_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_LIVE_AUDIO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_LIVE_AUDIO_FROM_APP)
//13, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_LIVE_AUDIO_FROM_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_LIVE_AUDIO_FROM_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_PLAYBACK_VIDEO_TO_APP)
//14, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_PLAYBACK_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_PLAYBACK_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_PLAYBACK_AUDIO_TO_APP)
//15, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_PLAYBACK_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_03_PLAYBACK_AUDIO_TO_APP)

#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_LIVE_VIDEO_TO_APP)
//16, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_LIVE_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_LIVE_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_LIVE_AUDIO_TO_APP)
//17, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_LIVE_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_LIVE_AUDIO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_LIVE_AUDIO_FROM_APP)
//18, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_LIVE_AUDIO_FROM_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_LIVE_AUDIO_FROM_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_PLAYBACK_VIDEO_TO_APP)
//19, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_PLAYBACK_VIDEO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_PLAYBACK_VIDEO_TO_APP)
#if defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_PLAYBACK_AUDIO_TO_APP)
//20, LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_PLAYBACK_AUDIO_TO_APP
#endif //defined(LIBPIZIOT_CORE_P2P_NAS_CHANNEL_04_PLAYBACK_AUDIO_TO_APP)

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
        p2p_nas_main_device_channel_update_mode(Alpthread_info, Alpthread_info->p2p_nas_main_device_handle, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER, p2p_nas_device_other_thread_instance_routine, p2p_nas_device_other_data_in_callback, P2P_PROTOCOL_NAS_OTHER_DEVICE_SEND_DATA_MAX_SIZE, P2P_PROTOCOL_NAS_OTHER_DEVICE_SEND_DATA_MAX_SIZE * 2, P2P_PROTOCOL_NAS_OTHER_DEVICE_RECV_DATA_MAX_SIZE, P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE, &(Alpthread_info->protocol_other));
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
    }
}

static void p2p_nas_main_device_stop_channel_thread(p2p_nas_main_device_thread_info_t *Alpthread_info) {
    p2p_nas_device_main_stop_thread_all(Alpthread_info);
}

static void p2p_nas_main_device_create_p2p_nas(p2p_nas_main_device_thread_info_t *Alpthread_info, const char *AlpUID) {
    uint16_t device_port = 0;
    TRACEA("PIZNas:UID=\"%s\"\n", AlpUID);

#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
    if (p2p_func_client_lan_server_handle == -1) {
        device_port = SAMPLE_CODE_P2P_LAN_SERVER_PORT_DEFAULT;
    }
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)

    {
#define CONNECT_SERVER_SOCKET_INFO_COUNT 1
        libpiziot_p2p_common_connect_server_socket_info_t connect_server_socket_info[CONNECT_SERVER_SOCKET_INFO_COUNT];
        libpiziot_p2p_common_connect_session_type_e select_net_type = LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_NONE;
        unsigned char device_account[LIBPIZIOT_P2P_COMMON_DEVICE_ACCOUNT_LENGTH_MAX + 1];
        unsigned char device_password[LIBPIZIOT_P2P_COMMON_DEVICE_PASSWORD_LENGTH_MAX + 1];

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
        if (p2p_func_client_device_get_nas_device_key(&(Alpthread_info->login_aes.aes_key), Alpthread_info->login_aes.cbc_iv, device_account, LIBPIZIOT_P2P_COMMON_DEVICE_ACCOUNT_LENGTH_MAX, device_password, LIBPIZIOT_P2P_COMMON_DEVICE_PASSWORD_LENGTH_MAX) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) return;

        if (libpiziot_p2p_clientsdk_create_device(connect_server_socket_info, CONNECT_SERVER_SOCKET_INFO_COUNT, device_port, AlpUID, select_net_type, device_account, device_password, &(Alpthread_info->p2p_nas_main_device_handle)) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}

static void p2p_nas_main_device_delete_p2p_device(p2p_nas_main_device_thread_info_t *Alpthread_info) {
    p2p_nas_main_device_stop_channel_thread(Alpthread_info);
    if (Alpthread_info->p2p_nas_main_device_handle >= 0) {
        libpiziot_p2p_clientsdk_delete_device(Alpthread_info->p2p_nas_main_device_handle);
        Alpthread_info->p2p_nas_main_device_handle = -1;
    }
}

static libpiziot_os_pthread_dword_t p2p_nas_main_device_thread_instance_routine(void *arg) {
    libpiziot_os_pthread_instance_t *lpthread_instance = (libpiziot_os_pthread_instance_t *)arg;
    p2p_nas_main_device_thread_info_t *lpthread_info = (p2p_nas_main_device_thread_info_t *)(lpthread_instance->m_extra);
#if defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)
    libpiziot_p2p_common_result_e viewer_net_result_last = LIBPIZIOT_P2P_COMMON_RESULT_UNKNOWN_MESSAGE_TYPE;
    p2p_nas_main_device_thread_step_e thread_step = P2P_NAS_MAIN_DEVICE_THREAD_STEP_CHECKER;
#else
    p2p_nas_main_device_thread_step_e thread_step = P2P_NAS_MAIN_DEVICE_THREAD_STEP_NORMAL;
#endif //defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)

    TRACEB("%s:start_routine ...\n", LIBPIZIOT_OS__FUNCTION__);

    do {
        //Sleep 500ms to reduce the CPU usage.
        usleep(500000);
        //Check if thread need to end.
        if (libpiziot_os_pthread_check_break(lpthread_instance, LIBPIZIOT_OS__FUNCTION__, __LINE__)) {
            TRACEB("%s:BreakThread\n", LIBPIZIOT_OS__FUNCTION__);
            break;
        }
        switch (thread_step) {
        case P2P_NAS_MAIN_DEVICE_THREAD_STEP_NORMAL: {
            if (lpthread_info->p2p_nas_main_device_handle == -1) {
                // Call the P2P SDK to create device with UID.
                p2p_nas_main_device_create_p2p_nas(lpthread_info, lpthread_info->lpuuid);
                continue;
            }
            else {
                p2p_nas_main_device_start_channel_thread(lpthread_info);
            }
        }
                                                     break;
#if defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)
        case P2P_NAS_MAIN_DEVICE_THREAD_STEP_CHECKER: {
            if (p2p_nas_main_device_exist_checker_handle == -1) {
                // Call the P2P SDK to create a viewer to check if duplicate UID device exist.
                if (p2p_nas_main_device_create_p2p_device_exist_checker(lpthread_info->lpuuid) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                    TRACEA("Create duplicate UID device,error !!\n");
                    libpiziot_os_signal_set_terminate_flag();
                    break;
                }
                continue;
            }
            //Check if duplicate UID device exist after viewer create.
            {
                libpiziot_p2p_common_result_e viewer_net_result = LIBPIZIOT_P2P_COMMON_RESULT_UNKNOWN_MESSAGE_TYPE;
                // Call the P2P SDK to get the viewer job stage
                libpiziot_os_type_func_result_e rval = libpiziot_p2p_clientsdk_get_viewer_net_status(p2p_nas_main_device_exist_checker_handle, &viewer_net_result);
                //OK ?
                if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                    //Check the job stage change ?
                    if (viewer_net_result != viewer_net_result_last) {
                        //Update the newer job stage as last stage.
                        viewer_net_result_last = viewer_net_result;
                        //Check job stage
                        switch (viewer_net_result) {
                        case LIBPIZIOT_P2P_COMMON_RESULT_CONNECTING: {
                            //The viewer is still connecting.
                        }
                                                                     break;
                        case LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_DEVICE_IN_LAN:
                        case LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_DEVICE_IN_WAN:
                        case LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_DEVICE: {
                            //Duplicate UID device found !!

                            // Call the P2P SDK to delete viewer.
                            p2p_nas_main_device_delete_p2p_device_exist_checker();
                            //Show the duplicate UID device exist message.
                            TRACEA("Duplicate UID device,error !!\n");
#if 0
                            {
                                //Set the flag to notify all thread terminate.
                                libpiziot_os_signal_set_terminate_flag();
                            }
#else
                            usleep(5000000);
#endif //0
                        }
                                                                          break;
                        default: {
                            //Duplicate UID device not found.

                            // Call the P2P SDK to delete viewer.
                            p2p_nas_main_device_delete_p2p_device_exist_checker();

                            // Call the P2P SDK to create device.
                            p2p_nas_main_device_create_p2p_nas(lpthread_info, lpthread_info->lpuuid);
                            if (lpthread_info->p2p_nas_main_device_handle == -1) {
                                usleep(30 * 1000000);
                                continue;
                            }
                            else {
                                thread_step = P2P_NAS_MAIN_DEVICE_THREAD_STEP_NORMAL;
                            }
                        }
                                 break;
                        }
                    }
                }
            }
        }
                                                      break;
#endif //defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)
        default: {

        }
                 break;
        }
    } while (1);
    TRACEB("%s:end_routine ...\n", LIBPIZIOT_OS__FUNCTION__);

    // Call the P2P SDK to delete device.
    p2p_nas_main_device_delete_p2p_device(lpthread_info);

#if defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)
    //if thread break before first get viewer status, the viewer is still running, it is need to call the P2P SDK to delete viewer.
    p2p_nas_main_device_delete_p2p_device_exist_checker();
#endif //defined(SAMPLE_CODE_ENABLE_DEVICE_EXIST_CHECKER)

    return (libpiziot_os_pthread_dword_t)1234567;
}

libpiziot_os_type_func_result_e p2p_nas_main_device_listen(p2p_nas_main_device_thread_info_t *Alpthread_info, const char *AlpUID) {
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
                if (libpiziot_os_pthread_create(&(Alpthread_info->thread_instance), p2p_nas_main_device_thread_instance_routine, LIBPIZIOT_OS_PTHREAD_STACK_SIZE_AUTO, "core_nas_device") != 0) {
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

void p2p_nas_main_device_unlisten(p2p_nas_main_device_thread_info_t *Alpthread_info) {
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

libpiziot_os_type_func_result_e p2p_nas_main_device_finalize(p2p_nas_main_device_thread_info_t **Alpp_thread_info) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    do {
        p2p_nas_main_device_thread_info_t *lpthread_info = (*Alpp_thread_info);
        if (lpthread_info == 0) break;
        if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) break;
        {
            // Finalize channel server thread.
            p2p_nas_device_main_finalize(lpthread_info);
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
            free(lpthread_info);
            (*Alpp_thread_info) = 0;
        }
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

libpiziot_os_type_func_result_e p2p_nas_main_device_initialize(p2p_nas_main_device_thread_info_t **Alpp_thread_info) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_nas_main_device_thread_info_t *lpthread_info = 0;
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
            if ((free_memory_size + sizeof(p2p_nas_main_device_thread_info_t)) < LIBPIZIOT_P2P_COMMON_SYSTEM_MEMORY_MINIMUM_SIZE) {
                //TRACEA("channel client out of memory when add client,error !!\n");
                break;
            }
        }
#endif //(defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
        lpthread_info = (p2p_nas_main_device_thread_info_t *)malloc(sizeof(p2p_nas_main_device_thread_info_t));
        if (lpthread_info == 0) {
            TRACEA("%s:out of memory,error !!\n", LIBPIZIOT_OS__FUNCTION__);
            break;
        }
        (*Alpp_thread_info) = lpthread_info;
        {
            memset_addr(p2p_nas_main_device_thread_info_t, lpthread_info, 0, sizeof(p2p_nas_main_device_thread_info_t));
            lpthread_info->p2p_nas_main_device_handle = -1;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
            lpthread_info->protocol_command.channel_enable_flag.current = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            lpthread_info->protocol_command.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            lpthread_info->protocol_command.lpthread_info = 0;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            lpthread_info->protocol_other.channel_enable_flag.current = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            lpthread_info->protocol_other.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            lpthread_info->protocol_other.lpthread_info = 0;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
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
                    if (p2p_nas_device_main_initialize(lpthread_info) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                        break;
                    }
                }
            }
        }
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        p2p_nas_main_device_finalize(Alpp_thread_info);
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

#endif //defined(ENABLE_P2P_NAS)
