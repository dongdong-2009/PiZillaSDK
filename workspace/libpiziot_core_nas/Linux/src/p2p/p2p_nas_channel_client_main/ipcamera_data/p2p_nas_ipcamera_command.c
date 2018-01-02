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

#if defined(ENABLE_P2P_NAS)

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_time.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_clientsdk.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

//Define this Header
#include "p2p_nas_ipcamera_command.h"

//Define Other Header
#include "../../p2p_protocol_ipcamera.h"
#include "../../p2p_nas_main/p2p_nas_main.h"
#include "p2p_nas_ipcamera_main.h"
#include "command/p2p_nas_ipcamera_command_common.h"

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

#if defined(P2P_PROTOCOL_IPCAMERA_COMMAND_VIEWER_SEND_DATA_MAX_SIZE)
static struct timeval p2p_nas_ipcamera_command_send_packet_timeout = { 30, 0 };
#endif //defined(P2P_PROTOCOL_IPCAMERA_COMMAND_VIEWER_SEND_DATA_MAX_SIZE)

void p2p_nas_ipcamera_command_data_in_callback(void *Alpobject, int32_t Aviewer_handle, int32_t Achannel_client_handle, int32_t Achannel_id, struct sockaddr_in *Alpin_channel_server_ip, unsigned char *Alpdata, int32_t Adata_size) {
    p2p_nas_ipcamera_main_thread_info_t *lpthread_info = Alpobject;
    if (lpthread_info == 0) return;
    if (Adata_size <= 0) return;
    do {
        if ((Adata_size > lpthread_info->data_dec_from_server_size) || (Adata_size & 0xF)) {
            TRACEA("PIZNasCam:data from channel server command size error !\n");
            break;
        }
        {
            unsigned char *lpdata = 0;
            if (lpthread_info->enable_aes_data == P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE) {
                if (Adata_size & 0xF) break;
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
                //uint32_t sequence = mem_endian_32(lpprotocol_head->sequence);
                uint32_t identy = Achannel_id + IPCAMERA_DATA_SERVER_SEND_C;
                if (mem_endian_32(lpprotocol_head->identy) != identy) {
                    TRACEA("PIZNasCam:data from channel server command crc error !\n");
                    break;
                }
                //TRACEA("PIZNasCam:VC(%d) ChC(%d),Ch[%d] RECV DATA from ipcamera,seq=%d,data_size(%d),from %s:%d,ok.\n", Aviewer_handle, Achannel_client_handle, Achannel_id, sequence, Adata_size, inet_ntoa(Alpin_channel_server_ip->sin_addr), (uint32_t)ntohs(Alpin_channel_server_ip->sin_port));
            }
            libpiziot_os_fifo_buffer_write_align(&(lpthread_info->m_fifo_recv_from_server), (char *)lpdata, Adata_size);

            if (Achannel_client_handle) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
            if (Aviewer_handle) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
            if (Alpin_channel_server_ip) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
        }
    } while (0);
}

#if defined(P2P_PROTOCOL_IPCAMERA_COMMAND_VIEWER_SEND_DATA_MAX_SIZE)

static libpiziot_os_type_func_result_e p2p_nas_ipcamera_command_encrypt_data_callback_before_send(unsigned char *Alpdata, int32_t Adata_size, unsigned char *Alpdata_enc, unsigned char **Alppdata_send, void *Alpobject) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_nas_ipcamera_main_thread_info_t *lpthread_info = Alpobject;
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

static libpiziot_os_type_func_result_e p2p_nas_ipcamera_command_send(p2p_nas_ipcamera_main_thread_info_t *Alpthread_info, unsigned char *Alpdata_send, int32_t Adata_size, unsigned char *Alpdata_enc_to_server, libpiziot_p2p_common_encrypt_data_callback_before_send_p Alpencrypt_data_callback) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&(Alpthread_info->instance_mutex));
    do {
        if (Alpthread_info->thread_index < 0) {
            break;
        }
        if (Alpthread_info->p2p_nas_channel_client_handle < 0) {
            break;
        }
        {
            rval = p2p_nas_ipcamera_main_get_net_status(Alpthread_info->p2p_nas_channel_client_handle, Alpthread_info->channel_id, &(Alpthread_info->net_status));
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
                        uint32_t send_packet_bytes_per_second = P2P_PROTOCOL_IPCAMERA_MAX_SEND_BYTES_PER_SECOND;
                        {
                            uint32_t identy = Alpthread_info->channel_id + IPCAMERA_DATA_CLIENT_SEND_C;
                            lpprotocol_head->identy = mem_endian_32(identy);
                        }
                        lpprotocol_head->sequence = mem_endian_32(Alpthread_info->send_counter);
                        rval = libpiziot_p2p_clientsdk_channel_client_send_data(Alpthread_info->p2p_nas_channel_client_handle, Alpdata_send, Adata_size, lpdata_enc, send_packet_bytes_per_second, p2p_nas_ipcamera_command_send_packet_timeout, Alpencrypt_data_callback, Alpthread_info);
                    }
                }
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
            } while (0);
            if (((int32_t)rval) == LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH) {
                TRACEA("PIZNasCam:VT(%d),ChC(%d),Ch[%d] SEND DATA to ipcamera LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH,error !!\n", Alpthread_info->thread_index, Alpthread_info->p2p_nas_channel_client_handle, Alpthread_info->channel_id);
                usleep(500000);
            }
            else if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                //TRACEA("PIZNasCam:VT(%d),ChC(%d),Ch[%d] SEND DATA to ipcamera,seq=%d,ok.\n", Alpthread_info->thread_index, Alpthread_info->p2p_nas_channel_client_handle, Alpthread_info->channel_id, Alpthread_info->send_counter);
                //usleep(1000000);
            }
            else {
                if (libpiziot_os_signal_get_terminate_flag() == 0) {
                    TRACEA("PIZNasCam:VT(%d),ChC(%d),Ch[%d] SEND DATA to ipcamera,error !!\n", Alpthread_info->thread_index, Alpthread_info->p2p_nas_channel_client_handle, Alpthread_info->channel_id);
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

libpiziot_os_type_func_result_e p2p_nas_ipcamera_command_send_to_channel_server(p2p_nas_ipcamera_main_thread_info_t *Alpthread_info, unsigned char *Alpdata_send, int32_t Adata_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Alpdata_send == 0 || Adata_size <= 0) return rval;
    if (Adata_size > 0) {
        int32_t enc_size = (Adata_size + 0xF) & 0xFFFFFFF0;
        if (enc_size > p2p_protocol_ipcamera_command_viewer_send_data_max_size) {
            TRACEA("out of command size(%d) - %d = %d\n", enc_size, p2p_protocol_ipcamera_command_viewer_send_data_max_size, enc_size - p2p_protocol_ipcamera_command_viewer_send_data_max_size);
            return rval;
        }
        libpiziot_os_fifo_buffer_write_align(&(Alpthread_info->m_fifo_send_to_server), (char *)Alpdata_send, Adata_size);
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    }
    return rval;
}

libpiziot_os_pthread_dword_t p2p_nas_ipcamera_command_thread_instance_routine(void *arg) {
    libpiziot_os_pthread_instance_t *lpthread_instance = (libpiziot_os_pthread_instance_t *)arg;
    p2p_nas_ipcamera_main_thread_info_t *lpthread_info = (p2p_nas_ipcamera_main_thread_info_t *)(lpthread_instance->m_extra);
    TRACEB("%s:start_routine ...\n", LIBPIZIOT_OS__FUNCTION__);
    do {
        usleep(1000);
        if (libpiziot_os_pthread_check_break(lpthread_instance, LIBPIZIOT_OS__FUNCTION__, __LINE__)) {
            TRACEB("%s:BreakThread\n", LIBPIZIOT_OS__FUNCTION__);
            break;
        }
#if defined(P2P_PROTOCOL_IPCAMERA_COMMAND_VIEWER_SEND_DATA_MAX_SIZE)

        if (lpthread_info->lpdata_recv_from_server != 0) {
            int32_t align_data_len = libpiziot_os_fifo_buffer_read_align(&(lpthread_info->m_fifo_recv_from_server), (char *)(lpthread_info->lpdata_recv_from_server), lpthread_info->data_recv_from_server_size);
            if (align_data_len > 0) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
                uint32_t cmd_index;
                int32_t protocol_head_len = (sizeof(libpiziot_core_p2p_protocol_command_head_t) + 0xF) & 0xFFFFFFF0;
                int32_t offset = protocol_head_len;
                libpiziot_core_p2p_protocol_command_head_t *lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)(lpthread_info->lpdata_recv_from_server);
                uint32_t cmd_count = mem_endian_32(lpprotocol_head->count);
                for (cmd_index = 0; cmd_index < cmd_count; cmd_index++) {
                    libpiziot_core_p2p_cmd_head_from_server_t *lpcmd = (libpiziot_core_p2p_cmd_head_from_server_t *)(lpthread_info->lpdata_recv_from_server + offset);
                    if (offset >= align_data_len) break;
                    {
                        int32_t cmd_len = mem_endian_32(lpcmd->size);
                        p2p_protocol_ipcamera_command_e cmd = mem_endian_32(lpcmd->cmd);
                        int32_t cmd_encrypt_len = (cmd_len + 0xF) & 0xFFFFFFF0;
                        offset += cmd_encrypt_len;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
                        if (p2p_nas_ipcamera_command_common_parser(cmd, lpthread_info->thread_index, lpcmd) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) continue;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
                    }
                }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
            }
        }

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

        {
            libpiziot_os_mutex_plock_lock(&(lpthread_info->instance_mutex));
            do {
                if (lpthread_info->thread_index < 0) {
                    break;
                }
                if (lpthread_info->p2p_nas_channel_client_handle < 0) {
                    break;
                }
                {
                    libpiziot_os_type_func_result_e ret = p2p_nas_ipcamera_main_get_net_status(lpthread_info->p2p_nas_channel_client_handle, lpthread_info->channel_id, &(lpthread_info->net_status));
                    if (ret != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                        break;
                    }
                }
                switch (lpthread_info->net_status) {
                case LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_CHANNEL_IN_LAN:
                case LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_CHANNEL_IN_WAN:
                case LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_CHANNEL_IN_PTP:
                case LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_CHANNEL_IN_RELAY: {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)

                    p2p_nas_ipcamera_command_common_send_action(lpthread_info->thread_index);

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
                }
                                                                           break;
                default: {
                }
                         break;
                }
            } while (0);
            libpiziot_os_mutex_plock_unlock(&(lpthread_info->instance_mutex));

        }

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

        if (lpthread_info->lpdata_send_to_server != 0 && lpthread_info->lpdata_enc_to_server != 0) {
            libpiziot_core_p2p_protocol_command_head_t *lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)(lpthread_info->lpdata_send_to_server);
            int32_t protocol_head_len = (sizeof(libpiziot_core_p2p_protocol_command_head_t) + 0xF) & 0xFFFFFFF0;
            int32_t cmd_len = 1;
            uint32_t cmd_count = 0;
            int32_t offset = protocol_head_len;
            while (cmd_len > 0) {
                char *lpoffset = ((char *)(lpthread_info->lpdata_send_to_server)) + offset;
                cmd_len = libpiziot_os_fifo_buffer_read_align(&(lpthread_info->m_fifo_send_to_server), lpoffset, lpthread_info->data_send_to_server_max_size - offset);
                if (cmd_len > 0) {
                    int32_t cmd_encrypt_len = (cmd_len + 0xF) & 0xFFFFFFF0;
                    offset += cmd_encrypt_len;
                    cmd_count++;
                    {
                        int fifo_max_read_size = libpiziot_os_fifo_buffer_get_max_read_size(&(lpthread_info->m_fifo_send_to_server), LIBPIZIOT_OS_FIFO_BUFFER_LOCK);
                        if (fifo_max_read_size <= sizeof(libpiziot_os_fifo_buffer_head_t)) {
                            break;
                        }
                        cmd_encrypt_len = (fifo_max_read_size + 0xF) & 0xFFFFFFF0;
                        if ((offset + cmd_encrypt_len) >= p2p_protocol_ipcamera_command_viewer_send_data_max_size) {
                            break;
                        }
                    }
                }
            }
            if (cmd_count > 0) {
                int32_t data_len = (offset + 0xF) & 0xFFFFFFF0;
                lpprotocol_head->count = mem_endian_32(cmd_count);
                p2p_nas_ipcamera_command_send(lpthread_info, (unsigned char *)lpprotocol_head, data_len, lpthread_info->lpdata_enc_to_server, p2p_nas_ipcamera_command_encrypt_data_callback_before_send);
            }
        }
#endif //defined(P2P_PROTOCOL_IPCAMERA_COMMAND_VIEWER_SEND_DATA_MAX_SIZE)
    } while (1);
    TRACEB("%s:end_routine ...\n", LIBPIZIOT_OS__FUNCTION__);
    return (libpiziot_os_pthread_dword_t)1234567;
}

#endif //defined(P2P_PROTOCOL_IPCAMERA_COMMAND_VIEWER_SEND_DATA_MAX_SIZE)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)

#endif //defined(ENABLE_P2P_NAS)

#endif //defined(__ESP8266X__)
