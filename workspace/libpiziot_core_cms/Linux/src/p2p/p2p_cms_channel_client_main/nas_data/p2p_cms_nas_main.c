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
#include "../../../../include/menu_config.h"

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

//Define this Header
#include "p2p_cms_nas_main.h"

//Define Other Header
#include "../../p2p_protocol_nas.h"
#include "../../p2p_cms_main/p2p_cms_main.h"

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)

#include "command/p2p_cms_nas_command_common.h"

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

#include "command/p2p_cms_nas_command_security_system.h"

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)

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

static libpiziot_p2p_clientsdk_channel_client_callback_t m_p2p_cms_nas_callback;

libpiziot_os_type_func_result_e p2p_cms_nas_main_get_net_status(int32_t Achannel_client_handle, int32_t Achannel_id, libpiziot_p2p_common_result_e *Alpnet_startus) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Achannel_client_handle < 0) return rval;
    do {
        libpiziot_p2p_common_result_e channel_net_result = LIBPIZIOT_P2P_COMMON_RESULT_UNKNOWN_MESSAGE_TYPE;
        rval = libpiziot_p2p_clientsdk_get_channel_client_net_status(Achannel_client_handle, &channel_net_result);
        if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        if (channel_net_result != (*Alpnet_startus)) {
            (*Alpnet_startus) = channel_net_result;
            switch (channel_net_result) {
            case LIBPIZIOT_P2P_COMMON_RESULT_CONNECTING: {
                TRACEA("PIZCmsNas:CHANNEL HANDLE:(%d),ID:(%d) CONNECTING\n", Achannel_client_handle, Achannel_id);
            }
                                                        break;
            case LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_CHANNEL_IN_LAN: {
                TRACEA("PIZCmsNas:CHANNEL HANDLE:(%d),ID:(%d) LAN_CHANNEL_IN_LAN\n", Achannel_client_handle, Achannel_id);
            }
                                                                     break;
            case LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_CHANNEL_IN_WAN: {
                TRACEA("PIZCmsNas:CHANNEL HANDLE:(%d),ID:(%d) LAN_CHANNEL_IN_WAN\n", Achannel_client_handle, Achannel_id);
            }
                                                                     break;
            case LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_CHANNEL_IN_PTP: {
                TRACEA("PIZCmsNas:CHANNEL HANDLE:(%d),ID:(%d) WAN_CHANNEL_IN_PTP\n", Achannel_client_handle, Achannel_id);
            }
                                                                     break;
            case LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_CHANNEL_IN_RELAY: {
                TRACEA("PIZCmsNas:CHANNEL HANDLE:(%d),ID:(%d) WAN_CHANNEL_IN_RELAY\n", Achannel_client_handle, Achannel_id);
            }
                                                                       break;
            default: {
                TRACEA("PIZCmsNas:CHANNEL HANDLE:(%d),ID:(%d) ERROR !! = %d\n", Achannel_client_handle, Achannel_id, channel_net_result);
            }
                     break;
            }
        }
    } while (0);
    return rval;
}

static libpiziot_os_type_func_result_e p2p_cms_nas_main_free(p2p_cms_main_nas_thread_info_t *Alpp2p_cms_main_nas_thread_info, int32_t Athread_info_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    do {
        p2p_cms_nas_main_thread_info_t *lpthread_info = Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[Athread_info_index];
        if (lpthread_info == 0) break;
        if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) continue;
        {
            {
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
                p2p_func_client_aes_free_cb(&(lpthread_info->login_aes));
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
#if defined(SAMPLE_CODE_P2P_CHANNEL_DATA_CB)
                p2p_func_client_aes_free_cb(&(lpthread_info->data_aes));
#endif //defined(SAMPLE_CODE_P2P_CHANNEL_DATA_CB)
            }
            if (libpiziot_os_pthread_finalize(&(lpthread_info->thread_instance)) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
            }
            if (libpiziot_os_mutex_plock_free(&(lpthread_info->instance_mutex)) != 0) {
                TRACEA("%s:mutex free &lpthread_info->instance_mutex,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
            }
            {
                if (lpthread_info->lpdata_send_to_server != 0) {
                    free(lpthread_info->lpdata_send_to_server);
                    lpthread_info->lpdata_send_to_server = 0;
                }
                {
                    libpiziot_os_fifo_buffer_info_t *lp_fifo_send_to_server = &(lpthread_info->m_fifo_send_to_server);
                    if (libpiziot_os_fifo_buffer_finalize(lp_fifo_send_to_server, LIBPIZIOT_OS__FUNCTION__, __LINE__) != 0) {
                    }
                    libpiziot_os_fifo_free_mutex(lp_fifo_send_to_server, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                }
                if (lpthread_info->lpdata_enc_to_server != 0) {
                    free(lpthread_info->lpdata_enc_to_server);
                    lpthread_info->lpdata_enc_to_server = 0;
                }
                if (lpthread_info->lpdata_dec_from_server != 0) {
                    free(lpthread_info->lpdata_dec_from_server);
                    lpthread_info->lpdata_dec_from_server = 0;
                }
                {
                    libpiziot_os_fifo_buffer_info_t *lp_fifo_recv_from_server = &(lpthread_info->m_fifo_recv_from_server);
                    if (libpiziot_os_fifo_buffer_finalize(lp_fifo_recv_from_server, LIBPIZIOT_OS__FUNCTION__, __LINE__) != 0) {
                    }
                    libpiziot_os_fifo_free_mutex(lp_fifo_recv_from_server, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                }
                if (lpthread_info->lpdata_recv_from_server != 0) {
                    free(lpthread_info->lpdata_recv_from_server);
                    lpthread_info->lpdata_recv_from_server = 0;
                }
            }
        }
        {
            free(lpthread_info);
            Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[Athread_info_index] = 0;
        }
    } while (0);
    return rval;
}

static libpiziot_os_type_func_result_e p2p_cms_nas_main_malloc(p2p_cms_main_nas_thread_info_t *Alpp2p_cms_main_nas_thread_info, int32_t Athread_info_index, uint32_t Asend_data_max_size, uint32_t Arecv_data_max_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_cms_nas_main_thread_info_t *lpthread_info = 0;
    do {
        int32_t protocol_head_len = (sizeof(libpiziot_core_p2p_protocol_command_head_t) + 0xF) & 0xFFFFFFF0;
        int32_t align_byte = LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE;
        uint32_t fifo_send_data_max_size = sizeof(libpiziot_os_fifo_buffer_head_t) + Asend_data_max_size + align_byte;
        uint32_t fifo_recv_data_max_size = sizeof(libpiziot_os_fifo_buffer_head_t) + protocol_head_len + Arecv_data_max_size + align_byte;
        if (Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[Athread_info_index] != 0) {
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
            break;
        }
#if (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
#elif defined(__ESP8266X__)
#else
        {
            uint64_t free_memory_size = libpiziot_os_mem_get_system_total_free_memory();
            uint64_t check_size = sizeof(p2p_cms_nas_main_thread_info_t);
            check_size += Asend_data_max_size; //lpdata_send_to_server
            check_size += fifo_send_data_max_size; //lp_fifo_send_to_server
            check_size += Asend_data_max_size; //lpdata_enc_to_server
            check_size += Arecv_data_max_size; //lpdata_dec_from_server
            check_size += fifo_recv_data_max_size; //lp_fifo_recv_from_server
            check_size += Arecv_data_max_size; //lpdata_recv_from_server
            if ((free_memory_size + check_size) < LIBPIZIOT_P2P_COMMON_SYSTEM_MEMORY_MINIMUM_SIZE) {
                //TRACEA("channel client out of memory when add client,error !!\n");
                break;
            }
        }
#endif //(defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
        lpthread_info = (p2p_cms_nas_main_thread_info_t *)malloc(sizeof(p2p_cms_nas_main_thread_info_t));
        if (lpthread_info == 0) {
            TRACEA("%s:out of memory,error !!\n", LIBPIZIOT_OS__FUNCTION__);
            break;
        }
        Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[Athread_info_index] = lpthread_info;
        {
            memset_addr(p2p_cms_nas_main_thread_info_t, lpthread_info, 0, sizeof(p2p_cms_nas_main_thread_info_t));
            lpthread_info->p2p_cms_channel_client_handle = -1;
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
#if defined(SAMPLE_CODE_P2P_CHANNEL_DATA_CB)
                    rval = p2p_func_client_aes_init_cb(&(lpthread_info->data_aes), SAMPLE_CODE_P2P_CHANNEL_DATA_CB, SAMPLE_CODE_P2P_CHANNEL_DATA_IV);
                    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(SAMPLE_CODE_P2P_CHANNEL_DATA_CB)
                }
            }
            {
                {
                    lpthread_info->data_send_to_server_max_size = protocol_head_len + Asend_data_max_size;
                    {
                        lpthread_info->lpdata_send_to_server = malloc(lpthread_info->data_send_to_server_max_size);
                        if (lpthread_info->lpdata_send_to_server == 0) break;
                    }
                    {
                        libpiziot_os_fifo_buffer_info_t *lp_fifo_send_to_server = &(lpthread_info->m_fifo_send_to_server);
                        memset_addr(libpiziot_os_fifo_buffer_info_t, lp_fifo_send_to_server, 0, sizeof(libpiziot_os_fifo_buffer_info_t));
                        libpiziot_os_fifo_mutex_init(lp_fifo_send_to_server, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                        if (libpiziot_os_fifo_buffer_initialize(lp_fifo_send_to_server, 0, fifo_send_data_max_size, LIBPIZIOT_OS__FUNCTION__, __LINE__) != 0) {
                            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
                            break;
                        }
                    }
                    {
                        lpthread_info->lpdata_enc_to_server = malloc(lpthread_info->data_send_to_server_max_size);
                        if (lpthread_info->lpdata_enc_to_server == 0) break;
                    }
                }
                {
                    {
                        lpthread_info->data_dec_from_server_size = protocol_head_len + Arecv_data_max_size;
                        lpthread_info->lpdata_dec_from_server = malloc(lpthread_info->data_dec_from_server_size);
                        if (lpthread_info->lpdata_dec_from_server == 0) break;
                    }
                    {
                        libpiziot_os_fifo_buffer_info_t *lp_fifo_recv_from_server = &(lpthread_info->m_fifo_recv_from_server);
                        memset_addr(libpiziot_os_fifo_buffer_info_t, lp_fifo_recv_from_server, 0, sizeof(libpiziot_os_fifo_buffer_info_t));
                        libpiziot_os_fifo_mutex_init(lp_fifo_recv_from_server, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                        if (libpiziot_os_fifo_buffer_initialize(lp_fifo_recv_from_server, 0, fifo_recv_data_max_size, LIBPIZIOT_OS__FUNCTION__, __LINE__) != 0) {
                            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
                            break;
                        }
                    }
                    {
                        lpthread_info->data_recv_from_server_size = protocol_head_len + Arecv_data_max_size;;
                        lpthread_info->lpdata_recv_from_server = malloc(lpthread_info->data_recv_from_server_size);
                        if (lpthread_info->lpdata_recv_from_server == 0) break;
                    }
                }
            }
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
            {
                p2p_cms_nas_command_common_init_action(Athread_info_index);
            }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
            {
                p2p_cms_nas_command_security_system_init(Athread_info_index);
            }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        p2p_cms_nas_main_free(Alpp2p_cms_main_nas_thread_info, Athread_info_index);
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

static void p2p_cms_nas_main_start_thread_one(p2p_cms_main_nas_thread_info_t *Alpp2p_cms_main_nas_thread_info, int32_t Athread_info_index, libpiziot_os_pthread_routine_p Alppthread_routine) {
    if (Alppthread_routine == 0) return;
    if (Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[Athread_info_index] == 0) return;
    {
        p2p_cms_nas_main_thread_info_t *lpthread_info = Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[Athread_info_index];
        if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return;
        libpiziot_os_mutex_plock_lock(&(lpthread_info->instance_mutex));
        do {
            if ((libpiziot_os_pthread_get_status(&(lpthread_info->thread_instance)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED)) {
                break;
            }
            if ((libpiziot_os_pthread_get_status(&(lpthread_info->thread_instance)) == LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED)) {
                if (libpiziot_os_pthread_create(&(lpthread_info->thread_instance), Alppthread_routine, LIBPIZIOT_OS_PTHREAD_STACK_SIZE_AUTO, "core_cms_nas_chc") != 0) {
                    TRACEA("%s:CreateUserPthread,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                    break;
                }
                TRACEB("%s:Thread running ...\n", LIBPIZIOT_OS__FUNCTION__);
            }
            else {
                TRACEA("%s:already running,ignore start thread ...\n", LIBPIZIOT_OS__FUNCTION__);
            }
        } while (0);
        libpiziot_os_mutex_plock_unlock(&(lpthread_info->instance_mutex));
    }
}

static void p2p_cms_nas_main_stop_thread_one(p2p_cms_main_nas_thread_info_t *Alpp2p_cms_main_nas_thread_info, int32_t Athread_info_index) {
    if (Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[Athread_info_index] == 0) return;
    {
        p2p_cms_nas_main_thread_info_t *lpthread_info = Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[Athread_info_index];
        if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return;
        {
            int32_t msg = 0;
            if (libpiziot_os_pthread_get_status(&(lpthread_info->thread_instance)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED) msg = 1;
            //if (msg == 1)
            //{
            // TRACEB("%s:libpiziot_os_pthread_release(...)\n", LIBPIZIOT_OS__FUNCTION__);
            // LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            //}
            libpiziot_os_pthread_release(&(lpthread_info->thread_instance));
            if (msg == 1) {
                TRACEB("%s:WaitUserPthread ...\n", LIBPIZIOT_OS__FUNCTION__);
                LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            }
            libpiziot_os_pthread_join(&(lpthread_info->thread_instance));
            if (msg == 1) {
                TRACEB("%s:THREAD_HANDLE_CLOSED ...\n", LIBPIZIOT_OS__FUNCTION__);
                LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            }
        }
    }
}

void p2p_cms_nas_main_stop_thread_all(p2p_cms_main_nas_thread_info_t *Alpp2p_cms_main_nas_thread_info) {
    {
        uint32_t thread_info_index;
        for (thread_info_index = 0; thread_info_index < P2P_CMS_NAS_MAIN_THREAD_MAX; thread_info_index++) {
            p2p_cms_nas_main_stop_thread_one(Alpp2p_cms_main_nas_thread_info, thread_info_index);
        }
    }
    {
        uint32_t thread_info_index;
        for (thread_info_index = 0; thread_info_index < P2P_CMS_NAS_MAIN_THREAD_MAX; thread_info_index++) {
            p2p_cms_nas_main_thread_info_t *lpthread_info = Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[thread_info_index];
            if (lpthread_info == 0) continue;
            if (lpthread_info->p2p_cms_channel_client_handle >= 0) {
                libpiziot_p2p_clientsdk_delete_channel_client(lpthread_info->p2p_cms_channel_client_handle);
                lpthread_info->p2p_cms_channel_client_handle = -1;
            }
        }
    }
    {
        uint32_t thread_info_index;
        for (thread_info_index = 0; thread_info_index < P2P_CMS_NAS_MAIN_THREAD_MAX; thread_info_index++) {
            if (p2p_cms_nas_main_free(Alpp2p_cms_main_nas_thread_info, thread_info_index) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
}

static void p2p_cms_nas_main_init_callback(p2p_cms_nas_main_thread_info_t *Alpthread_info, libpiziot_p2p_common_channel_data_in_p Alpdata_in_callback) {
    memset_addr(libpiziot_p2p_clientsdk_channel_client_callback_t, &(m_p2p_cms_nas_callback), 0, sizeof(m_p2p_cms_nas_callback));
    {
        m_p2p_cms_nas_callback.lpobject = Alpthread_info;
        m_p2p_cms_nas_callback.break_callback.lpthread_instance = &(Alpthread_info->thread_instance);
        m_p2p_cms_nas_callback.lpdata_in_callback = Alpdata_in_callback;
    }
}

libpiziot_os_type_func_result_e p2p_cms_nas_main_start_thread(p2p_cms_main_nas_thread_info_t *Alpp2p_cms_main_nas_thread_info, int32_t Aviewer_handle, int32_t Athread_info_index, int32_t Achannel_id, libpiziot_os_pthread_routine_p Alppthread_routine, libpiziot_p2p_common_channel_data_in_p Alpdata_in_callback, int32_t Asend_data_max_size, int32_t Arecv_data_max_size, p2p_func_client_channel_aes_e Aenable_channel_aes, libpiziot_p2p_common_relay_data_type_e Adata_type) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Athread_info_index >= P2P_CMS_NAS_MAIN_THREAD_MAX) {
        return rval;
    }
    do {
        if (p2p_cms_nas_main_malloc(Alpp2p_cms_main_nas_thread_info, Athread_info_index, Asend_data_max_size, Arecv_data_max_size) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        {
            p2p_cms_nas_main_thread_info_t *lpthread_info = Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[Athread_info_index];
            if (lpthread_info->p2p_cms_channel_client_handle != -1) {
                rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
                break;
            }
            {
                libpiziot_p2p_common_connect_session_type_e select_net_type = LIBPIZIOT_P2P_COMMON_CHANNEL_CONNECT_SESSION_TYPE_NONE;
                //select_net_type |= LIBPIZIOT_P2P_COMMON_CHANNEL_CONNECT_SESSION_TYPE_LAN;
                //select_net_type |= LIBPIZIOT_P2P_COMMON_CHANNEL_CONNECT_SESSION_TYPE_PTP;
                //select_net_type |= LIBPIZIOT_P2P_COMMON_CHANNEL_CONNECT_SESSION_TYPE_RELAY;
                select_net_type |= LIBPIZIOT_P2P_COMMON_CHANNEL_CONNECT_SESSION_TYPE_AUTO;
                select_net_type |= LIBPIZIOT_P2P_COMMON_CONNECT_SESSION_TYPE_AUTO_RELOGIN_WHEN_ERROR;
                lpthread_info->channel_id = Achannel_id;
                lpthread_info->enable_aes_data = Aenable_channel_aes;
                p2p_cms_nas_main_init_callback(lpthread_info, Alpdata_in_callback);
                lpthread_info->thread_index = Athread_info_index;
                {
                    unsigned char channel_account[LIBPIZIOT_P2P_COMMON_CHANNEL_ACCOUNT_LENGTH_MAX + 1];
                    unsigned char channel_password[LIBPIZIOT_P2P_COMMON_CHANNEL_PASSWORD_LENGTH_MAX + 1];
                    if (p2p_func_client_viewer_get_nas_channel_key(&(lpthread_info->login_aes.aes_key), lpthread_info->login_aes.cbc_iv, channel_account, LIBPIZIOT_P2P_COMMON_CHANNEL_ACCOUNT_LENGTH_MAX, channel_password, LIBPIZIOT_P2P_COMMON_CHANNEL_PASSWORD_LENGTH_MAX) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
                    // Call the P2P SDK to create a new channel client socket.
                    {
                        int32_t protocol_head_len = (sizeof(libpiziot_core_p2p_protocol_command_head_t) + 0xF) & 0xFFFFFFF0;
                        int32_t recv_data_max_size = protocol_head_len + Arecv_data_max_size;
                        if (libpiziot_p2p_clientsdk_create_channel_client(Aviewer_handle, Achannel_id, select_net_type, Adata_type, channel_account, channel_password, &(m_p2p_cms_nas_callback), recv_data_max_size, &(lpthread_info->p2p_cms_channel_client_handle)) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                            TRACEA("PIZCmsNas:create_channel_client,error !!\n");
                            break;
                        }
                    }
                }
                if (Alppthread_routine != 0) {
                    p2p_cms_nas_main_start_thread_one(Alpp2p_cms_main_nas_thread_info, Athread_info_index, Alppthread_routine);
                }
            }
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

libpiziot_os_type_func_result_e p2p_cms_nas_main_stop_thread(p2p_cms_main_nas_thread_info_t *Alpp2p_cms_main_nas_thread_info, int32_t Athread_info_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        p2p_cms_nas_main_stop_thread_one(Alpp2p_cms_main_nas_thread_info, Athread_info_index);
        {
            p2p_cms_nas_main_thread_info_t *lpthread_info = Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[Athread_info_index];
            if (lpthread_info == 0) continue;
            if (lpthread_info->p2p_cms_channel_client_handle >= 0) {
                libpiziot_p2p_clientsdk_delete_channel_client(lpthread_info->p2p_cms_channel_client_handle);
                lpthread_info->p2p_cms_channel_client_handle = -1;
            }
        }
        if (p2p_cms_nas_main_free(Alpp2p_cms_main_nas_thread_info, Athread_info_index) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

// Finalize channel client thread.
void p2p_cms_nas_main_finalize(p2p_cms_main_nas_thread_info_t *Alpp2p_cms_main_nas_thread_info) {
    if (Alpp2p_cms_main_nas_thread_info) {
        LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
    }
}

// Initialize channel client thread.
libpiziot_os_type_func_result_e p2p_cms_nas_main_initialize(p2p_cms_main_nas_thread_info_t *Alpp2p_cms_main_nas_thread_info) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    do {
        {
            // Initialize channel client thread.
            uint32_t thread_info_index;
            for (thread_info_index = 0; thread_info_index < P2P_CMS_NAS_MAIN_THREAD_MAX; thread_info_index++) {
                Alpp2p_cms_main_nas_thread_info->lpp2p_cms_nas_main_thread_info[thread_info_index] = 0;
            }
        }
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        p2p_cms_nas_main_finalize(Alpp2p_cms_main_nas_thread_info);
    }
    return rval;
}

#endif //defined(ENABLE_P2P_CMS)

#endif //defined(__ESP8266X__)
