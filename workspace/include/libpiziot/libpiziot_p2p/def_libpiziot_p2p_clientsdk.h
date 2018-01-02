#ifndef __DEF_LIBPIZIOT_P2P_CLIENTSDK_H__
#define __DEF_LIBPIZIOT_P2P_CLIENTSDK_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_resource.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mutex.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_socket.h"
#include "def_libpiziot_p2p_common.h"

#define LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_BROADCAST_DATA 0xFFFFFFFF

typedef struct libpiziot_p2p_clientsdk_channel_server_callback_s {
    void *lpobject;
    libpiziot_p2p_common_break_callback_t break_callback;
    libpiziot_p2p_common_channel_data_in_p lpdata_in_callback;
} libpiziot_p2p_clientsdk_channel_server_callback_t;

typedef struct libpiziot_p2p_common_channel_client_callback_s {
    void *lpobject;
    libpiziot_p2p_common_break_callback_t break_callback;
    libpiziot_p2p_common_channel_data_in_p lpdata_in_callback;
#if defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__)
    void *lprecv_call_back_class_ref;
    char *lprecv_call_back_func_name;
    libpiziot_os_aes_key_t *lpaes_context;
    int32_t enable_aes_data;
    unsigned char lpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1];
    int32_t max_data_recv_size;
    int32_t max_data_send_size;
    unsigned char *lpdata_dec_from_server;
    unsigned char *lpdata_enc_to_server;
    struct sockaddr_in in_channel_server_ip;
    unsigned char *lpdata;
    int32_t data_size;
#endif //defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__)
} libpiziot_p2p_clientsdk_channel_client_callback_t;

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_create_lan_server(
        uint16_t Alan_server_port, int32_t *Alplan_server_handle
    );

    extern void libpiziot_p2p_clientsdk_delete_lan_server(
        int32_t Alan_server_handle
    );

    extern void libpiziot_p2p_clientsdk_delete_all_lan_server(
        void
    );

#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_create_device(
        libpiziot_p2p_common_connect_server_socket_info_t Alpconnect_server_socket_info[], uint32_t Aconnect_server_socket_count, uint16_t Adevice_port, const char *AlpUID, libpiziot_p2p_common_connect_session_type_e Aselect_net_type, const unsigned char *Alpdevice_account, const unsigned char *Alpdevice_password, int32_t *Alpdevice_handle
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_delete_device(
        int32_t Adevice_handle
    );

    extern void libpiziot_p2p_clientsdk_delete_all_device(
        void
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_create_viewer(
        libpiziot_p2p_common_connect_server_socket_info_t Alpconnect_server_socket_info[], uint32_t Aconnect_server_socket_count, uint16_t Alan_server_port, const char *AlpUID, libpiziot_p2p_common_connect_session_type_e Aselect_net_type, const unsigned char *Alpdevice_account, const unsigned char *Alpdevice_password, int32_t *Alpviewer_handle
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_delete_viewer(
        int32_t Aviewer_handle
    );

    extern void libpiziot_p2p_clientsdk_delete_all_viewer(
        void
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_get_viewer_net_status(
        int32_t Aviewer_handle, libpiziot_p2p_common_result_e *Alpviewer_net_status
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_listen_channel_server(
        int32_t Adevice_handle, int32_t Achannel_id, const unsigned char *Alpchannel_account, const unsigned char *Alpchannel_password, libpiziot_p2p_clientsdk_channel_server_callback_t *Alpcallback, int32_t Asend_data_max_size, int32_t Asend_buffer_size, int32_t Arecv_data_max_size, int32_t *Alpchannel_server_monitor_handle
    );

    extern void libpiziot_p2p_clientsdk_unlisten_channel_server(
        int32_t Achannel_server_monitor_handle
    );

    extern void libpiziot_p2p_clientsdk_unlisten_all_channel_server(
        void
    );

#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_channel_server_send_data(
        int32_t Achannel_server_monitor_handle, uint32_t Achannel_server_handle, unsigned char *Alpdata, int32_t Adata_size, uint32_t Abytes_per_second, struct timeval Apacket_timeout, libpiziot_p2p_common_encrypt_data_callback_before_send_p Alpencrypt_data_callback, void *Alpobject, libpiziot_p2p_common_result_e *Alpnet_startus
    );

#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_create_channel_client(
        int32_t Aviewer_handle, int32_t Achannel_id, libpiziot_p2p_common_connect_session_type_e Aselect_net_type, libpiziot_p2p_common_relay_data_type_e Adata_type, const unsigned char *Alpchannel_account, const unsigned char *Alpchannel_password, libpiziot_p2p_clientsdk_channel_client_callback_t *Alpcallback, int32_t Arecv_data_max_size, int32_t *Alpchannel_client_handle
    );

    extern void libpiziot_p2p_clientsdk_delete_channel_client(
        int32_t Achannel_client_handle
    );

    extern void libpiziot_p2p_clientsdk_delete_all_channel_client(
        void
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_get_channel_client_net_status(
        int32_t Achannel_client_handle, libpiziot_p2p_common_result_e *Alpchannel_client_net_status
    );

#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_channel_client_send_data(
        int32_t Achannel_client_handle, unsigned char *Alpdata, int32_t Adata_size, unsigned char *Alpdata_enc, uint32_t Abytes_per_second, struct timeval Apacket_timeout, libpiziot_p2p_common_encrypt_data_callback_before_send_p Alpencrypt_data_callback, void *Alpobject
    );

#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)

    extern void libpiziot_p2p_clientsdk_start_thread(
        void
    );

    extern void libpiziot_p2p_clientsdk_stop_thread(
        void
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_clientsdk_initialize(
        const unsigned char *Alpvendor_account, const unsigned char *Alpvendor_password
    );

    extern void libpiziot_p2p_clientsdk_finalize(
        void
    );

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_P2P_CLIENTSDK_H__
