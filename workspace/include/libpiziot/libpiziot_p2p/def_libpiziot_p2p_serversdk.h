#ifndef __DEF_LIBPIZIOT_P2P_SERVERSDK_H__
#define __DEF_LIBPIZIOT_P2P_SERVERSDK_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_resource.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mutex.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_socket.h"
#include "def_libpiziot_p2p_common.h"

typedef libpiziot_os_type_func_result_e (*libpiziot_p2p_serversdk_device_login_p)(
    const unsigned char *Alpvendor_account, char *AlpUID
    );

typedef libpiziot_os_type_func_result_e (*libpiziot_p2p_serversdk_redir_device_address_p)(
    const unsigned char *Alpvendor_account, char *AlpUID, char *Alpredir_address, int32_t Asize_redir_address
    );

typedef libpiziot_os_type_func_result_e (*libpiziot_p2p_serversdk_write_device_ip_and_port_p)(
    const unsigned char *Alpvendor_account, char *AlpUID, struct sockaddr_in Ain_device_ip, struct timeval Atimestamp
    );

typedef libpiziot_os_type_func_result_e (*libpiziot_p2p_serversdk_read_device_ip_and_port_p)(
    const unsigned char *Alpvendor_account, char *AlpUID, struct sockaddr_in *Alpin_device_ip, struct timeval *Alptimestamp
    );

typedef struct libpiziot_p2p_serversdk_server_handler_callback_s {
    libpiziot_p2p_serversdk_device_login_p lpdevice_login;
    libpiziot_p2p_serversdk_redir_device_address_p lpredir_device_address;
    libpiziot_p2p_serversdk_write_device_ip_and_port_p lpwrite_device_ip_and_port;
    libpiziot_p2p_serversdk_read_device_ip_and_port_p lpread_device_ip_and_port;
} libpiziot_p2p_serversdk_server_handler_callback_t;

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE)

    extern libpiziot_os_type_func_result_e libpiziot_p2p_serversdk_create_uid_server(
        libpiziot_p2p_common_connect_socket_type_e socket_type, uint16_t Aserver_port, libpiziot_p2p_serversdk_server_handler_callback_t *Alpcallback, int32_t *Alpuid_server_handle
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_serversdk_server_delete_uid_server(
        int32_t Auid_server_handle
    );

    extern void libpiziot_p2p_serversdk_delete_all_uid_server(
        void
    );

#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_RELAY_MODE)

    extern libpiziot_os_type_func_result_e libpiziot_p2p_serversdk_get_relay_server_idle_count(
        int32_t Auid_server_handle, int32_t *Alptotal_relay_count, int32_t *Alpidle_relay_count
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_serversdk_create_relay_server(
        uint16_t Arelay_port, libpiziot_p2p_common_relay_connect_server_socket_info_t Alpconnect_server_socket_info[], uint32_t Aconnect_server_socket_count, const char *AlpRID, const unsigned char *Alprelay_account, const unsigned char *Alprelay_password, int32_t *Alprelay_server_handle
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_serversdk_delete_relay_server(
        int32_t Arelay_server_handle
    );

    extern void libpiziot_p2p_serversdk_delete_all_relay_server(
        void
    );

#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_RELAY_MODE)

    extern void libpiziot_p2p_serversdk_start_thread(
        void
    );

    extern void libpiziot_p2p_serversdk_stop_thread(
        void
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_serversdk_initialize(
        const unsigned char *Alpvendor_account, const unsigned char *Alpvendor_password
    );

    extern void libpiziot_p2p_serversdk_finalize(
        void
    );

#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE)

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_P2P_SERVERSDK_H__
