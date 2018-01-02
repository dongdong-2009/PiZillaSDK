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

#if defined(ENABLE_P2P_NAS)

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_clientsdk.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)

//Define this Header
#include "p2p_nas_device_command.h"

//Define Other Header
#include "../../p2p_protocol_nas.h"
#include "../../p2p_nas_main/p2p_nas_main.h"
#include "p2p_nas_device_main.h"
#include "command/p2p_nas_device_command_common.h"
#include "command/p2p_nas_device_command_security_system.h"

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

#if defined(P2P_FUNC_NAS_ENABLE_DATA_COMMAND_DEVICE_SEND_DATA)
static struct timeval p2p_nas_device_command_send_packet_timeout = { 30, 0 };
#endif //defined(P2P_FUNC_NAS_ENABLE_DATA_COMMAND_DEVICE_SEND_DATA)

void p2p_nas_device_command_data_in_callback(void *Alpobject, int32_t Adevice_handle, int32_t Achannel_server_handle, int32_t Achannel_id, struct sockaddr_in *Alpin_channel_client_ip, unsigned char *Alpdata, int32_t Adata_size) {
    p2p_nas_device_main_thread_info_t *lpthread_info = Alpobject;
    if (lpthread_info == 0) return;
    if (Adata_size <= 0) return;
    // Use mutex to lock memory when data callback triggered with different client ip at the same time.
    libpiziot_os_mutex_plock_lock(&(lpthread_info->data_in_mutex));
    do {
        if ((Adata_size > lpthread_info->data_dec_from_client_size) || (Adata_size & 0xF)) {
            TRACEA("PIZNas:data from channel client command size error !\n");
            break;
        }
        {
            unsigned char *lpdata = lpthread_info->lpdata_dec_from_client;
            if (lpthread_info->enable_aes_data == P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE) {
                if (Adata_size & 0xF) break;
                // Decrypt the data from channel client.
                if (lpthread_info->lpdata_dec_from_client == 0) break;
                {
                    libpiziot_os_aes_cbc_t *lpaes_context_channel_data = &(lpthread_info->data_aes);
                    if (libpiziot_os_aes_cbc_decrypt(&(lpaes_context_channel_data->aes_key), Adata_size, lpaes_context_channel_data->cbc_iv, Alpdata, lpdata) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                        break;
                    }
                }
            }
            else {
                memcpy(lpdata, Alpdata, Adata_size);
            }
            {
                libpiziot_core_p2p_protocol_command_head_t *lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)lpdata;
                //uint32_t sequence = mem_endian_32(lpprotocol_head->sequence);
                uint32_t identy = Achannel_id + NAS_DATA_CLIENT_SEND_C;
                if (mem_endian_32(lpprotocol_head->identy) != identy) {
                    TRACEA("PIZNas:data from channel client command crc error !\n");
                    break;
                }
                //TRACEA("PIZNas:DC(%d) ChS(%d),Ch[%d] RECV DATA from cms,seq=%d,data_size(%d),from %s:%d,ok.\n", Adevice_handle, Achannel_server_handle, Achannel_id, sequence, Adata_size, inet_ntoa(Alpin_channel_client_ip->sin_addr), (uint32_t)ntohs(Alpin_channel_client_ip->sin_port));
            }
            {
                libpiziot_core_p2p_data_from_client_head_t *lphead = (libpiziot_core_p2p_data_from_client_head_t *)(lpthread_info->lpdata_from_client_head);
                lphead->device_handle = Adevice_handle;
                lphead->channel_server_handle = Achannel_server_handle;
                lphead->in_channel_client_ip = (*Alpin_channel_client_ip);
                libpiziot_os_fifo_buffer_write_align(&(lpthread_info->m_fifo_recv_from_client), (char *)(lpthread_info->lpdata_from_client_head), sizeof(libpiziot_core_p2p_data_from_client_head_t) + Adata_size);
            }
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&(lpthread_info->data_in_mutex));
}

#if defined(P2P_FUNC_NAS_ENABLE_DATA_COMMAND_DEVICE_SEND_DATA)

static libpiziot_os_type_func_result_e p2p_nas_device_command_encrypt_data_callback_before_send(unsigned char *Alpdata, int32_t Adata_size, unsigned char *Alpdata_enc, unsigned char **Alppdata_send, void *Alpobject) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    p2p_nas_device_main_thread_info_t *lpthread_info = Alpobject;
    if (lpthread_info == 0) return rval;
    if (lpthread_info->enable_aes_data == P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE) {
        libpiziot_os_mutex_plock_lock(&(lpthread_info->encrypt_mutex));
        do {
            // Encrypt the data.
            (*Alppdata_send) = Alpdata_enc;
            {
                libpiziot_os_aes_cbc_t *lpaes_context_channel_data = &(lpthread_info->data_aes);
                rval = libpiziot_os_aes_cbc_encrypt(&(lpaes_context_channel_data->aes_key), Adata_size, lpaes_context_channel_data->cbc_iv, Alpdata, (*Alppdata_send));
            }
        } while (0);
        libpiziot_os_mutex_plock_unlock(&(lpthread_info->encrypt_mutex));
    }
    else {
        (*Alppdata_send) = Alpdata;
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    }
    return rval;
}

static libpiziot_os_type_func_result_e p2p_nas_device_command_send(p2p_nas_device_main_thread_info_t *Alpthread_info, uint32_t Achannel_server_handle, unsigned char *Alpdata_send, int32_t Adata_size, libpiziot_p2p_common_encrypt_data_callback_before_send_p Alpencrypt_data_callback) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&(Alpthread_info->instance_mutex));
    do {
        if (Alpthread_info->thread_index < 0) {
            break;
        }
        if (Alpthread_info->p2p_channel_monitor_handle < 0) {
            break;
        }
        // Send data to channel client.
        if (Alpthread_info->enable_aes_data == P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE) {
            if (Adata_size & 0xF) {
                rval = LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH;
                break;
            }
        }
#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
        {
            libpiziot_core_p2p_protocol_command_head_t *lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)Alpdata_send;
            uint32_t send_packet_bytes_per_second = P2P_PROTOCOL_NAS_MAX_SEND_BYTES_PER_SECOND;
            {
                uint32_t identy = Alpthread_info->channel_id + NAS_DATA_SERVER_SEND_C;
                lpprotocol_head->identy = mem_endian_32(identy);
            }
            lpprotocol_head->sequence = mem_endian_32(Alpthread_info->send_counter);
            rval = libpiziot_p2p_clientsdk_channel_server_send_data(Alpthread_info->p2p_channel_monitor_handle, Achannel_server_handle, Alpdata_send, Adata_size, send_packet_bytes_per_second, p2p_nas_device_command_send_packet_timeout, Alpencrypt_data_callback, Alpthread_info, &(Alpthread_info->net_status));
        }
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
    } while (0);
    {
        int32_t set_counter = 0;
        if (((int32_t)rval) == LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH) {
            TRACEA("PIZNas:DT(%d),ChS(%d),Ch[%d] SEND DATA to cms LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH,error.\n", Alpthread_info->thread_index, Alpthread_info->p2p_channel_monitor_handle, Alpthread_info->channel_id);
            usleep(500000);
        }
        else if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            //TRACEA("PIZNas:DT(%d),ChS(%d),Ch[%d] SEND DATA to cms,seq=%d,ok.\n", Alpthread_info->thread_index, Alpthread_info->p2p_channel_monitor_handle, Alpthread_info->channel_id, Alpthread_info->send_counter);
            switch (Alpthread_info->net_status) {
            case LIBPIZIOT_P2P_COMMON_RESULT_OK_SEND_TO_CHANNEL_SERVER_BUFFER: {
            }
                                                                              break;
            case LIBPIZIOT_P2P_COMMON_RESULT_NOTIFY_CHANNEL_SERVER_ON_CREATING: {
            }
                                                                               break;
            case LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_CLIENT_STILL_CONNECTING: {
            }
                                                                                   break;
            default: {
                TRACEA("PIZNas:DT(%d),ChS(%d),Ch[%d] SEND DATA to cms,seq=%d,error !!\n", Alpthread_info->thread_index, Alpthread_info->p2p_channel_monitor_handle, Alpthread_info->channel_id, Alpthread_info->send_counter);
            }
                     break;
            }
            set_counter = 1;
        }
        else {
            if (libpiziot_os_signal_get_terminate_flag() == 0) {
                switch (Alpthread_info->net_status) {
                case LIBPIZIOT_P2P_COMMON_RESULT_CONNECTING: {
                }
                                                            break;
                case LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_SERVER_NO_CLIENT: {
                }
                                                                                break;
                case LIBPIZIOT_P2P_COMMON_RESULT_NOTIFY_CHANNEL_SERVER_ON_CREATING: {
                }
                                                                                   break;
                case LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_CLIENT_STILL_CONNECTING: {
                }
                                                                                       break;
                case LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_SERVER_BUFFER_FULL: {
                }
                                                                                  break;
                default: {
                    set_counter = 1;
                    TRACEA("PIZNas:DT(%d),ChS(%d),Ch[%d] SEND DATA to cms return(%d),error !!\n", Alpthread_info->thread_index, Alpthread_info->p2p_channel_monitor_handle, Alpthread_info->channel_id, Alpthread_info->net_status);
                }
                         break;
                }
                usleep(500000);
            }
        }
        if (set_counter == 1) {
            Alpthread_info->send_counter++;
            //usleep(1000000);
        }
    }
    libpiziot_os_mutex_plock_unlock(&(Alpthread_info->instance_mutex));
    return rval;
}

libpiziot_os_type_func_result_e p2p_nas_device_command_send_to_channel_client(p2p_nas_device_main_thread_info_t *Alpthread_info, unsigned char *Alpdata_send, int32_t Adata_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (Alpdata_send == 0 || Adata_size <= 0) return rval;
    if (Adata_size > 0) {
        int32_t enc_size = (Adata_size + 0xF) & 0xFFFFFFF0;
        if (enc_size > p2p_protocol_nas_command_device_send_data_max_size) {
            TRACEA("out of command size(%d) - %d = %d\n", enc_size, p2p_protocol_nas_command_device_send_data_max_size, enc_size - p2p_protocol_nas_command_device_send_data_max_size);
            return rval;
        }
        libpiziot_os_fifo_buffer_write_align(&(Alpthread_info->m_fifo_send_to_client), (char *)Alpdata_send, Adata_size);
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    }
    return rval;

}

libpiziot_os_pthread_dword_t p2p_nas_device_command_thread_instance_routine(void *arg) {
    libpiziot_os_pthread_instance_t *lpthread_instance = (libpiziot_os_pthread_instance_t *)arg;
    p2p_nas_device_main_thread_info_t *lpthread_info = (p2p_nas_device_main_thread_info_t *)(lpthread_instance->m_extra);
    TRACEB("%s:start_routine ...\n", LIBPIZIOT_OS__FUNCTION__);
    do {
        usleep(1000);
        if (libpiziot_os_pthread_check_break(lpthread_instance, LIBPIZIOT_OS__FUNCTION__, __LINE__)) {
            TRACEB("%s:BreakThread\n", LIBPIZIOT_OS__FUNCTION__);
            break;
        }
#if defined(P2P_FUNC_NAS_ENABLE_DATA_COMMAND_DEVICE_SEND_DATA)
        if (lpthread_info->lpdata_recv_from_client != 0) {
            int32_t align_data_len = libpiziot_os_fifo_buffer_read_align(&(lpthread_info->m_fifo_recv_from_client), (char *)(lpthread_info->lpdata_recv_from_client_head), lpthread_info->data_recv_from_client_head_size);
            if (align_data_len > 0) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
                uint32_t cmd_index;
                int32_t protocol_head_len = (sizeof(libpiziot_core_p2p_protocol_command_head_t) + 0xF) & 0xFFFFFFF0;
                int32_t offset = protocol_head_len;
                libpiziot_core_p2p_protocol_command_head_t *lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)(lpthread_info->lpdata_recv_from_client);
                uint32_t cmd_count = mem_endian_32(lpprotocol_head->count);
                align_data_len -= sizeof(libpiziot_core_p2p_data_from_client_head_t);
                for (cmd_index = 0; cmd_index < cmd_count; cmd_index++) {
                    libpiziot_core_p2p_cmd_head_from_client_t *lpcmd = (libpiziot_core_p2p_cmd_head_from_client_t *)(lpthread_info->lpdata_recv_from_client + offset);
                    if (offset >= align_data_len) break;
                    {
                        int32_t cmd_len = mem_endian_32(lpcmd->size);
                        p2p_protocol_nas_command_e cmd = mem_endian_32(lpcmd->cmd);
                        int32_t cmd_encrypt_len = (cmd_len + 0xF) & 0xFFFFFFF0;
                        libpiziot_core_p2p_data_from_client_head_t *lphead = (libpiziot_core_p2p_data_from_client_head_t *)lpthread_info->lpdata_recv_from_client_head;
                        offset += cmd_encrypt_len;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
                        if (p2p_nas_device_command_common_parser(cmd, lpthread_info->thread_index, lpcmd, lphead) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) continue;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
                        if (p2p_nas_device_command_security_system_parser(cmd, lpthread_info->thread_index, lpcmd, lphead) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) continue;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
                    }
                }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
            }
        }

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
        {
            libpiziot_os_mutex_plock_lock(&(lpthread_info->instance_mutex));
            do {
                if (lpthread_info->thread_index < 0) {
                    break;
                }
                if (lpthread_info->p2p_channel_monitor_handle < 0) {
                    break;
                }
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
                p2p_nas_device_command_common_send_action(lpthread_info->thread_index);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
                p2p_nas_device_command_security_system_send_action(lpthread_info->thread_index);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
            } while (0);
            libpiziot_os_mutex_plock_unlock(&(lpthread_info->instance_mutex));

        }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

        if (lpthread_info->lpdata_send_to_client != 0) {
            libpiziot_core_p2p_protocol_command_head_t *lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)(lpthread_info->lpdata_send_to_client);
            int32_t protocol_head_len = (sizeof(libpiziot_core_p2p_protocol_command_head_t) + 0xF) & 0xFFFFFFF0;
            int32_t cmd_len = 1;
            uint32_t cmd_count = 0;
            int32_t offset = protocol_head_len;
            while (cmd_len > 0) {
                char *lpoffset = ((char *)(lpthread_info->lpdata_send_to_client)) + offset;
                cmd_len = libpiziot_os_fifo_buffer_read_align(&(lpthread_info->m_fifo_send_to_client), lpoffset, lpthread_info->data_send_to_client_max_size - offset);
                if (cmd_len > 0) {
                    libpiziot_core_p2p_cmd_head_from_server_t *lpcmd_info = (libpiziot_core_p2p_cmd_head_from_server_t *)lpoffset;
                    if (lpcmd_info->channel_server_handle != LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA) {
                        if (cmd_count > 0) {
                            int32_t data_len = (offset + 0xF) & 0xFFFFFFF0;
                            lpprotocol_head->count = mem_endian_32(cmd_count);
                            p2p_nas_device_command_send(lpthread_info, LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA, (unsigned char *)lpprotocol_head, data_len, p2p_nas_device_command_encrypt_data_callback_before_send);
                            cmd_count = 0;
                        }
                        {
                            int32_t cmd_encrypt_len = (cmd_len + 0xF) & 0xFFFFFFF0;
                            int32_t data_len = ((protocol_head_len + cmd_encrypt_len) + 0xF) & 0xFFFFFFF0;
                            cmd_count++;
                            {
                                lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)(lpthread_info->lpdata_send_to_client + offset - protocol_head_len);
                                lpprotocol_head->count = mem_endian_32(cmd_count);
                                p2p_nas_device_command_send(lpthread_info, lpcmd_info->channel_server_handle, (unsigned char *)lpprotocol_head, data_len, p2p_nas_device_command_encrypt_data_callback_before_send);
                                cmd_count = 0;
                                offset = protocol_head_len;
                                lpprotocol_head = (libpiziot_core_p2p_protocol_command_head_t *)(lpthread_info->lpdata_send_to_client);
                            }
                        }
                        continue;
                    }
                    {
                        int32_t cmd_encrypt_len = (cmd_len + 0xF) & 0xFFFFFFF0;
                        offset += cmd_encrypt_len;
                        cmd_count++;
                        {
                            int fifo_max_read_size = libpiziot_os_fifo_buffer_get_max_read_size(&(lpthread_info->m_fifo_send_to_client), LIBPIZIOT_OS_FIFO_BUFFER_LOCK);
                            if (fifo_max_read_size <= sizeof(libpiziot_os_fifo_buffer_head_t)) {
                                break;
                            }
                            cmd_encrypt_len = (fifo_max_read_size + 0xF) & 0xFFFFFFF0;
                            if ((offset + cmd_encrypt_len) >= p2p_protocol_nas_command_device_send_data_max_size) {
                                break;
                            }
                        }
                    }
                }
            }
            if (cmd_count > 0) {
                int32_t data_len = (offset + 0xF) & 0xFFFFFFF0;
                lpprotocol_head->count = mem_endian_32(cmd_count);
                p2p_nas_device_command_send(lpthread_info, LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA, (unsigned char *)lpprotocol_head, data_len, p2p_nas_device_command_encrypt_data_callback_before_send);
            }
        }
#endif //defined(P2P_FUNC_NAS_ENABLE_DATA_COMMAND_DEVICE_SEND_DATA)
    } while (1);
    TRACEB("%s:end_routine ...\n", LIBPIZIOT_OS__FUNCTION__);
    return (libpiziot_os_pthread_dword_t)1234567;
}

#endif //defined(P2P_FUNC_NAS_ENABLE_DATA_COMMAND_DEVICE_SEND_DATA)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)

#endif //defined(ENABLE_P2P_NAS)
