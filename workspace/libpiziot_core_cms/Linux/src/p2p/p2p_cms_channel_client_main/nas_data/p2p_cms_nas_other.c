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

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)

//Define this Header
#include "p2p_cms_nas_other.h"

//Define Other Header
#include "../../p2p_protocol_nas.h"
#include "../../p2p_cms_main/p2p_cms_main.h"
#include "p2p_cms_nas_main.h"

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

static struct timeval p2p_cms_nas_other_send_packet_timeout = { 30, 0 };

void p2p_cms_nas_other_data_in_callback(void *Alpobject, int32_t Aviewer_handle, int32_t Achannel_client_handle, int32_t Achannel_id, struct sockaddr_in *Alpin_channel_server_ip, unsigned char *Alpdata, int32_t Adata_size) {
    p2p_cms_nas_main_thread_info_t *lpthread_info = Alpobject;
    if (lpthread_info == 0) return;
    do {
        if (Adata_size != P2P_PROTOCOL_NAS_OTHER_DEVICE_SEND_DATA_MAX_SIZE) {
            TRACEA("PIZCmsNas:data size error !\n");
            break;
        }
        {
            unsigned char *lpdata = 0;
            if (lpthread_info->enable_aes_data == P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE) {
                // Decrypt the data from channel server.
                if (lpthread_info->lpdata_dec_from_server == 0) break;
                lpdata = lpthread_info->lpdata_dec_from_server;
                {
                    libpiziot_os_aes_cbc_t *lpaes_context_channel_data = &(lpthread_info->data_aes);
                    if (libpiziot_os_aes_cbc_decrypt(&(lpaes_context_channel_data->aes_key), Adata_size, lpaes_context_channel_data->cbc_iv, Alpdata, lpdata) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                        break;
                    }
                }
            }
            else {
                lpdata = Alpdata;
            }
            {
                libpiziot_core_p2p_protocol_command_head_t *lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)lpdata;
                unsigned char *lpChar = (unsigned char *)lpdata + sizeof(libpiziot_core_p2p_protocol_command_head_t);
                int32_t data_size = Adata_size - sizeof(libpiziot_core_p2p_protocol_command_head_t);
                unsigned char c = (unsigned char)(Achannel_id + NAS_DATA_SERVER_SEND_C);
                int32_t pos;
                for (pos = 0; pos < data_size; pos++) {
                    if (lpChar[pos] != c) {
                        TRACEA("PIZCmsNas:data crc error !\n");
                        data_size = 0;
                        break;
                    }
                    c++;
                }
                if (data_size > 0) {
                    uint32_t sequence = mem_endian_32(lpprotocol_head->sequence);
                    TRACEA("PIZCmsNas:VC(%d) ChC(%d),Ch[%d] RECV DATA from nas,seq=%d,data_size(%d),from %s:%d,ok.\n", Aviewer_handle, Achannel_client_handle, Achannel_id, sequence, Adata_size, inet_ntoa(Alpin_channel_server_ip->sin_addr), (uint32_t)ntohs(Alpin_channel_server_ip->sin_port));
                }
            }
        }
    } while (0);
}


static libpiziot_os_type_func_result_e p2p_cms_nas_other_encrypt_data_callback_before_send(unsigned char *Alpdata, int32_t Adata_size, unsigned char *Alpdata_enc, unsigned char **Alppdata_send, void *Alpobject) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_cms_nas_main_thread_info_t *lpthread_info = Alpobject;
    if (lpthread_info == 0) return rval;
    if (lpthread_info->enable_aes_data == P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE) {
        // Encrypt the data.
        (*Alppdata_send) = Alpdata_enc;
        {
            libpiziot_os_aes_cbc_t *lpaes_context_channel_data = &(lpthread_info->data_aes);
            rval = libpiziot_os_aes_cbc_encrypt(&(lpaes_context_channel_data->aes_key), Adata_size, lpaes_context_channel_data->cbc_iv, Alpdata, (*Alppdata_send));
        }
    }
    else {
        (*Alppdata_send) = Alpdata;
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    }
    return rval;
}

static libpiziot_os_type_func_result_e p2p_cms_nas_other_send(p2p_cms_nas_main_thread_info_t *Alpthread_info, unsigned char *Alpdata_send, int32_t Adata_size, unsigned char *Alpdata_enc_to_server, libpiziot_p2p_common_encrypt_data_callback_before_send_p Alpencrypt_data_callback) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&(Alpthread_info->instance_mutex));
    do {
        if (Adata_size <= 0) {
            break;
        }
        if (Alpthread_info->thread_index < 0) {
            break;
        }
        if (Alpthread_info->p2p_cms_channel_client_handle < 0) {
            break;
        }
        {
            rval = p2p_cms_nas_main_get_net_status(Alpthread_info->p2p_cms_channel_client_handle, Alpthread_info->channel_id, &(Alpthread_info->net_status));
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
        }
        switch (Alpthread_info->net_status) {
        case LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_CHANNEL_IN_LAN:
        case LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_CHANNEL_IN_WAN:
        case LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_CHANNEL_IN_PTP:
        case LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_CHANNEL_IN_RELAY: {
            do {
                // Send data to channel server.
                if (Alpthread_info->enable_aes_data == P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE) {
                    if (Adata_size & 0xF) {
                        rval = LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH;
                        break;
                    }
                }
#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
                {
                    unsigned char *lpdata_enc;
#if defined(SAMPLE_CODE_P2P_CHANNEL_DATA_CB)
                    // Encrypt the data.
                    lpdata_enc = Alpdata_enc_to_server;
#else
                    lpdata_enc = 0;
#endif //defined(SAMPLE_CODE_P2P_CHANNEL_DATA_CB)
                    {
                        libpiziot_core_p2p_protocol_command_head_t *lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)Alpdata_send;
                        uint32_t send_packet_bytes_per_second = P2P_PROTOCOL_NAS_MAX_SEND_BYTES_PER_SECOND;
                        lpprotocol_head->sequence = mem_endian_32(Alpthread_info->send_counter);
                        rval = libpiziot_p2p_clientsdk_channel_client_send_data(Alpthread_info->p2p_cms_channel_client_handle, Alpdata_send, Adata_size, lpdata_enc, send_packet_bytes_per_second, p2p_cms_nas_other_send_packet_timeout, Alpencrypt_data_callback, Alpthread_info);
                    }
                }
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
            } while (0);
            if (((int32_t)rval) == LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH) {
                TRACEA("PIZCmsNas:VT(%d),ChC(%d),Ch[%d] SEND DATA to nas LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH,error !!\n", Alpthread_info->thread_index, Alpthread_info->p2p_cms_channel_client_handle, Alpthread_info->channel_id);
                usleep(500000);
            }
            else if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                TRACEA("PIZCmsNas:VT(%d),ChC(%d),Ch[%d] SEND DATA to nas,seq=%d,ok.\n", Alpthread_info->thread_index, Alpthread_info->p2p_cms_channel_client_handle, Alpthread_info->channel_id, Alpthread_info->send_counter);
                usleep(1000000);
            }
            else {
                if (libpiziot_os_signal_get_terminate_flag() == 0) {
                    TRACEA("PIZCmsNas:VT(%d),ChC(%d),Ch[%d] SEND DATA to nas,error !!\n", Alpthread_info->thread_index, Alpthread_info->p2p_cms_channel_client_handle, Alpthread_info->channel_id);
                    usleep(500000);
                }
            }
            Alpthread_info->send_counter++;
        }
                                                                   break;
        default: {
            usleep(500000);
        }
                 break;
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&(Alpthread_info->instance_mutex));
    return rval;
}

static void p2p_cms_nas_other_init_data(int32_t Achannel_id, unsigned char *Alpdata_send, int32_t Adata_size) {
    int32_t pos;
    unsigned char c = (unsigned char)(Achannel_id + NAS_DATA_CLIENT_SEND_C);
    libpiziot_core_p2p_protocol_command_head_t *lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)Alpdata_send;
    unsigned char *lpChar = (unsigned char *)lpprotocol_head + sizeof(libpiziot_core_p2p_protocol_command_head_t);
    int32_t max_size = Adata_size - sizeof(libpiziot_core_p2p_protocol_command_head_t);
    for (pos = 0; pos < max_size; pos++) {
        lpChar[pos] = c;
        c++;
    }
    {
        lpprotocol_head->sequence = mem_endian_32(0);
    }
}

libpiziot_os_type_func_result_e p2p_cms_nas_other_send_to_channel_server(p2p_cms_nas_main_thread_info_t *Alpthread_info, unsigned char *Alpdata_send, int32_t Adata_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Adata_size > P2P_PROTOCOL_NAS_OTHER_VIEWER_SEND_DATA_MAX_SIZE) return rval;
    rval = p2p_cms_nas_other_send(Alpthread_info, Alpdata_send, Adata_size, Alpthread_info->lpdata_enc_to_server, p2p_cms_nas_other_encrypt_data_callback_before_send);
    return rval;
}

libpiziot_os_pthread_dword_t p2p_cms_nas_other_thread_instance_routine(void *arg) {
    libpiziot_os_pthread_instance_t *lpthread_instance = (libpiziot_os_pthread_instance_t *)arg;
    p2p_cms_nas_main_thread_info_t *lpthread_info = (p2p_cms_nas_main_thread_info_t *)(lpthread_instance->m_extra);

    if (lpthread_info->lpdata_send_to_server != 0 && lpthread_info->lpdata_enc_to_server != 0) {
        p2p_cms_nas_other_init_data(lpthread_info->channel_id, lpthread_info->lpdata_send_to_server, P2P_PROTOCOL_NAS_OTHER_VIEWER_SEND_DATA_MAX_SIZE);
    }

    TRACEB("%s:start_routine ...\n", LIBPIZIOT_OS__FUNCTION__);
    do {
        usleep(1000);
        if (libpiziot_os_pthread_check_break(lpthread_instance, LIBPIZIOT_OS__FUNCTION__, __LINE__)) {
            TRACEB("%s:BreakThread\n", LIBPIZIOT_OS__FUNCTION__);
            break;
        }

        if (lpthread_info->lpdata_send_to_server != 0 && lpthread_info->lpdata_enc_to_server != 0) {
            p2p_cms_nas_other_send(lpthread_info, lpthread_info->lpdata_send_to_server, P2P_PROTOCOL_NAS_OTHER_VIEWER_SEND_DATA_MAX_SIZE, lpthread_info->lpdata_enc_to_server, p2p_cms_nas_other_encrypt_data_callback_before_send);
        }
#if 0
        if (lpthread_info->net_status < 0)
        {
            TRACEA("PIZCmsNas:DISCONNECT CHANNEL HANDLE:(%d),ID:(%d)\n", lpthread_info->p2p_cms_channel_client_handle, lpthread_info->channel_id);
            libpiziot_p2p_clientsdk_delete_channel_client(lpthread_info->p2p_cms_channel_client_handle);
            lpthread_info->p2p_cms_channel_client_handle = -1;
        }
#endif //0

    } while (1);
    TRACEB("%s:end_routine ...\n", LIBPIZIOT_OS__FUNCTION__);
    return (libpiziot_os_pthread_dword_t)1234567;
}

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)

#endif //defined(ENABLE_P2P_CMS)

#endif //defined(__ESP8266X__)
