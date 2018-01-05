#ifndef __DEF_LIBPIZIOT_P2P_COMMON_H__
#define __DEF_LIBPIZIOT_P2P_COMMON_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_resource.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mutex.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_socket.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_fifo.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_aes.h"

#define LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE
#define LIBPIZIOT_P2P_COMMON_ENABLE_PTP_MODE
#define LIBPIZIOT_P2P_COMMON_ENABLE_RELAY_MODE

#define LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH -0x0022 // Invalid data input length.

#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_PTP_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_RELAY_MODE)
#define LIBPIZIOT_P2P_COMMON_ENABLE_WAN_MODE
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_PTP_MODE) || defined(LIBPIZIOT_P2P_COMMON_ENABLE_RELAY_MODE)

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#define LIBPIZIOT_P2P_COMMON_SEND_DATA_MAX_SIZE (4 * 1024)
#else
#define LIBPIZIOT_P2P_COMMON_SYSTEM_MEMORY_MINIMUM_SIZE (4 * 1024 * 1024)
#define LIBPIZIOT_P2P_COMMON_SEND_DATA_MAX_SIZE (4 * 1024 * 1024 / 8)
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

//Given the minimum MTU on the internet is 576, and the size of the IPv4 header is 20 bytes, and the UDP header 8 bytes.This leaves 548 bytes available for user data
#define LIBPIZIOT_P2P_COMMON_UDP_MTU_SIZE 576
#define LIBPIZIOT_P2P_COMMON_UDP_IPV4_HEADER_SIZE 20
#define LIBPIZIOT_P2P_COMMON_UDP_HEADER_SIZE 8
#define LIBPIZIOT_P2P_COMMON_UDP_DATA_MAX_SIZE (LIBPIZIOT_P2P_COMMON_UDP_MTU_SIZE - LIBPIZIOT_P2P_COMMON_UDP_IPV4_HEADER_SIZE - LIBPIZIOT_P2P_COMMON_UDP_HEADER_SIZE)
//#define LIBPIZIOT_P2P_COMMON_ENCRYPT_UDP_DATA_MAX_SIZE (LIBPIZIOT_P2P_COMMON_UDP_DATA_MAX_SIZE / 2)

#define LIBPIZIOT_P2P_COMMON_VENDOR_ACCOUNT_LENGTH_MAX 32
#define LIBPIZIOT_P2P_COMMON_VENDOR_PASSWORD_LENGTH_MAX 32

#define LIBPIZIOT_P2P_COMMON_UID_LENGTH_MAX 20
#define LIBPIZIOT_P2P_COMMON_RID_LENGTH_MAX 8
#define LIBPIZIOT_P2P_COMMON_DEVICE_ACCOUNT_LENGTH_MAX 32
#define LIBPIZIOT_P2P_COMMON_DEVICE_PASSWORD_LENGTH_MAX 32
#define LIBPIZIOT_P2P_COMMON_CHANNEL_ACCOUNT_LENGTH_MAX 32
#define LIBPIZIOT_P2P_COMMON_CHANNEL_PASSWORD_LENGTH_MAX 32
#define LIBPIZIOT_P2P_COMMON_RELAY_ACCOUNT_LENGTH_MAX 32
#define LIBPIZIOT_P2P_COMMON_RELAY_PASSWORD_LENGTH_MAX 32

typedef enum libpiziot_p2p_common_net_print_msg_enum {
    LIBPIZIOT_P2P_COMMON_NET_PRINT_MSG_DISABLE = 0,
    LIBPIZIOT_P2P_COMMON_NET_PRINT_MSG_ENABLE = 1,
} libpiziot_p2p_common_net_print_msg_e;

typedef enum libpiziot_p2p_common_connect_socket_type_enum {
    LIBPIZIOT_P2P_COMMON_CONNECT_SOCKET_TYPE_UDP = SOCK_DGRAM,
    //LIBPIZIOT_P2P_COMMON_CONNECT_SOCKET_TYPE_TCP = SOCK_STREAM,
} libpiziot_p2p_common_connect_socket_type_e;

typedef struct libpiziot_p2p_common_connect_server_socket_info_s {
    libpiziot_p2p_common_connect_socket_type_e socket_type;
    uint16_t server_port;
#define P2P_NET_COMMON_SERVER_DOMAIN_LEN_MAX 256
    char lpserver_domain[P2P_NET_COMMON_SERVER_DOMAIN_LEN_MAX + 1];
} libpiziot_p2p_common_connect_server_socket_info_t;

typedef enum libpiziot_p2p_common_relay_data_type_enum {
    LIBPIZIOT_P2P_COMMON_RELAY_DATA_TYPE_ANY = 0,
    LIBPIZIOT_P2P_COMMON_RELAY_DATA_TYPE_DATA = 1,
    LIBPIZIOT_P2P_COMMON_RELAY_DATA_TYPE_VIDEO = 2,
    LIBPIZIOT_P2P_COMMON_RELAY_DATA_TYPE_AUDIO = 3,
    LIBPIZIOT_P2P_COMMON_RELAY_DATA_TYPE_OTHER,
} libpiziot_p2p_common_relay_data_type_e;

typedef struct libpiziot_p2p_common_relay_connect_server_socket_info_s {
    libpiziot_p2p_common_connect_socket_type_e socket_type;
    uint16_t server_port;
    libpiziot_p2p_common_relay_data_type_e data_type;
#define P2P_NET_COMMON_SERVER_DOMAIN_LEN_MAX 256
    char lpserver_domain[P2P_NET_COMMON_SERVER_DOMAIN_LEN_MAX + 1];
} libpiziot_p2p_common_relay_connect_server_socket_info_t;

typedef enum libpiziot_p2p_common_connect_session_type_enum {
    LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_NONE = 0,
    LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_LAN = 0x1,
    LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_PTP = 0x2,
    LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_RELAY = 0x4,
    LIBPIZIOT_P2P_COMMON_DEVICE_CONNECT_SESSION_TYPE_AUTO = 0x7,
    LIBPIZIOT_P2P_COMMON_CHANNEL_CONNECT_SESSION_TYPE_NONE = 0,
    LIBPIZIOT_P2P_COMMON_CHANNEL_CONNECT_SESSION_TYPE_LAN = 0x1,
    LIBPIZIOT_P2P_COMMON_CHANNEL_CONNECT_SESSION_TYPE_PTP = 0x2,
    LIBPIZIOT_P2P_COMMON_CHANNEL_CONNECT_SESSION_TYPE_RELAY = 0x4,
    LIBPIZIOT_P2P_COMMON_CHANNEL_CONNECT_SESSION_TYPE_AUTO = 0x7,
    LIBPIZIOT_P2P_COMMON_CONNECT_SESSION_TYPE_AUTO_RELOGIN_WHEN_ERROR = 0x100,
} libpiziot_p2p_common_connect_session_type_e;

typedef enum libpiziot_p2p_common_result_enum {
    LIBPIZIOT_P2P_COMMON_RESULT_FUNCTION_DISABLE = -3,
    LIBPIZIOT_P2P_COMMON_RESULT_USOCKET_ERROR = -2,
    LIBPIZIOT_P2P_COMMON_RESULT_UNKNOWN_MESSAGE_TYPE = -1,

    LIBPIZIOT_P2P_COMMON_RESULT_CONNECTING = 0,

    LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_DEVICE_IN_LAN = 20001,
    LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_DEVICE_IN_WAN = 20002,
    LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_DEVICE = 20003,

    LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_CHANNEL_IN_LAN = 20011,
    LIBPIZIOT_P2P_COMMON_RESULT_MODE_LAN_CHANNEL_IN_WAN = 20012,
    LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_CHANNEL_IN_PTP = 20013,
    LIBPIZIOT_P2P_COMMON_RESULT_MODE_WAN_CHANNEL_IN_RELAY = 20014,

    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_LAN_NOT_READY = -20050,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_WAN_NOT_READY = -20051,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_DOMAIN = -20100,

    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_SEND_TO = -11000,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_SEND_TO_P2PSERVER = -11001,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_SEND_TO_DEVICE = -11002,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_SEND_TO = 11003,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_SEND_TO_CHANNEL_CLIENT = 11004,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_SEND_TO_CHANNEL_CLIENT = -11005,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_SEND_TO_CHANNEL_SERVER = 11006,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_SEND_TO_CHANNEL_SERVER = -11007,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_SEND_TO_RELAY = -11008,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_SEND_TO_CHANNEL_SERVER_BUFFER = 11009,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_SERVER_BUFFER_FULL = -11010,

    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_GET_RELAY_SERVER_IP = -12010,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_DEVICE_UID_CHAR = -12011,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_RELAY_UID_CHAR = -12021,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_LOGIN_KEY = -12030,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_KEY = -12031,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_HTBEAT_DEVICE_TIME_OUT = -12050,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_UID_NOT_FOUND = -12060,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_ID_REQ = -12080,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_OUT_OF_SERVER_CHANNEL = -12081,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_NULL_SERVER_CHANNEL = -12082,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_CLIENT_STILL_CONNECTING = 12083,
    LIBPIZIOT_P2P_COMMON_RESULT_NOTIFY_CHANNEL_SERVER_ON_CREATING = 12084,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_THREAD = -12085,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_ENCRYPT_CALLBACK = -12086,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_ENCRYPT_DATA = -12087,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_IP_ERROR = -12088,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_SERVER_CHANNEL_ID_NOT_FOUND = -12089,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_VENDOR_ACCOUNT_CHAR = -12090,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_VENDOR_PASSWORD_CHAR = -12091,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_ENCRYPT_DATA_SIZE = -12092,

    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_ADD_LAN_CLIENT = -1290,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_ADD_PTP_CLIENT = -1291,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_ADD_RELAY_CLIENT = -1292,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_HTBEAT_CLIENT = -1293,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_IP_DATA_CHANNEL_CLIENT = -1294,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_DATA = -1295,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_CLIENT_IP = -1296,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_SERVER_IP = -1297,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_SERVER_NO_CLIENT = -1298,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_QUIT_CHANNEL = -1299,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CHANNEL_SERVER_CLIENT_NO_RESPONSE = -1300,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_OUTOFF_REMOTE_BUFFER_SIZE = -1301,

    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_WRITE_DB = -13000,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_READ_DB = -13001,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_DEVICE_UID_LICENSE = -13002,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_DEVICE_LOGIN_REDIR = -13003,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_VIEWER_LOGIN_REDIR = -13004,

    LIBPIZIOT_P2P_COMMON_RESULT_OK_ASK_LAN_DEVICE = 13100,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_ASK_LAN_CHANNEL = 13101,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_VIEWER_LOGIN_LAN = -13101,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_VIEWER_LOGIN_LAN = -13102,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_CONNECT_LAN_CHANNEL = 13200,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_CONNECT_LAN_CHANNEL = -13201,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_CONNECT_LAN_CHANNEL = -13202,

    LIBPIZIOT_P2P_COMMON_RESULT_OK_DEVICE_LOGIN_SERVER = 13300,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_DEVICE_LOGIN_SERVER = -13301,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_DEVICE_LOGIN_SERVER = -13302,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_DEVICE_LOGIN_REDIR = 13303,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_HTBEAT_DEVICE = 13400,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_HTBEAT_DEVICE = -13401,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_HTBEAT_DEVICE = -13402,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_VIEWER_LOGIN_SERVER = 13500,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_VIEWER_LOGIN_SERVER = -13502,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_VIEWER_LOGIN_REDIR = 13503,

    LIBPIZIOT_P2P_COMMON_RESULT_OK_RELAY_LOGIN_SERVER = 13600,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_RELAY_LOGIN_SERVER = -13601,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_ADD_RELAY = -13602,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_UPDATE_RELAY = -13603,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_RELAY_HTBEAT = 13700,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_RELAY_HTBEAT = -13701,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_RELAY_HTBEAT = -13702,

    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_ASK_LAN_CHANNEL = -13801,

    LIBPIZIOT_P2P_COMMON_RESULT_OK_ASK_PTP_CHANNEL = 13900,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_ASK_PTP_CHANNEL = -13901,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_CLONE_PTP_CHANNEL = 14000,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_ANSWER_PTP_CHANNEL = 14100,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_ANSWER_PTP_CHANNEL = -14101,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_SEND_ANSWER_PTP_CHANNEL = -14102,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_CONNECT_PTP_CHANNEL = 14200,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_CONNECT_PTP_CHANNEL = -14201,

    LIBPIZIOT_P2P_COMMON_RESULT_OK_ASK_RELAY_CHANNEL = 14300,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_ASK_RELAY_CHANNEL = -14301,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_CLONE_RELAY_CHANNEL = 14400,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_ANSWER_RELAY_CHANNEL = 14500,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_ANSWER_RELAY_CHANNEL = -14501,
    LIBPIZIOT_P2P_COMMON_RESULT_ERROR_SEND_ANSWER_RELAY_CHANNEL = -14502,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_CONNECT_RELAY_CHANNEL = 14600,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_CONNECT_RELAY_CHANNEL = -14601,

    LIBPIZIOT_P2P_COMMON_RESULT_OK_HTBEAT_CHANNEL = 14701,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_HTBEAT_CHANNEL = -14701,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_CHANNEL_CLIENT_DATA = 14711,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_CHANNEL_CLIENT_DATA = -14712,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_CHANNEL_SERVER_DATA = 14713,
    LIBPIZIOT_P2P_COMMON_RESULT_TIMEOUT_CHANNEL_SERVER_DATA = -14714,
    LIBPIZIOT_P2P_COMMON_RESULT_OK_QUIT_CHANNEL = 14721,

} libpiziot_p2p_common_result_e;

typedef struct libpiziot_p2p_common_packet_link_s {
    int32_t prev;
    int32_t next;
} libpiziot_p2p_common_packet_link_t;

typedef struct libpiziot_p2p_common_packet_send_speed_s {
    int32_t bytes_per_second;
    struct timeval packet_timer;
    int32_t packet_per_check;
} libpiziot_p2p_common_packet_send_speed_t;

typedef libpiziot_os_type_func_result_e (*libpiziot_p2p_common_encrypt_data_callback_before_send_p)(unsigned char *Alpdata, int32_t Adata_size, unsigned char *Alpdata_enc, unsigned char **Alppdata_send, void *Alpobject);

typedef void (*libpiziot_p2p_common_channel_data_in_p)(void *Alpobject, int32_t Adevice_handle, int32_t Achannel_handle, int32_t Achannel_id, struct sockaddr_in *Alpin_channel_data_from_ip, unsigned char *Alpdata, int32_t Adata_size);

typedef struct libpiziot_p2p_common_break_flag_s {
    int32_t thread_break;
    int32_t send_break;
} libpiziot_p2p_common_break_flag_t;

typedef struct libpiziot_p2p_common_break_callback_s {
    void *lpthread_instance;
    libpiziot_p2p_common_break_flag_t *lpbreak_flag;
} libpiziot_p2p_common_break_callback_t;

typedef struct libpiziot_p2p_common_fifo_s {
    libpiziot_os_fifo_buffer_info_t fifo_buffer;
    char *lpsend_buff;
    int32_t buffer_size;
} libpiziot_p2p_common_fifo_t;

typedef struct libpiziot_p2p_common_fifo_data_head_s {
    uint32_t headmark;
    uint32_t reserved;
    int32_t bs_length;
} libpiziot_p2p_common_fifo_data_head_t;

#ifdef __cplusplus
extern "C"
{
#endif

    // ==== Initialize AES context // AES ���c�غc
    extern libpiziot_os_type_func_result_e libpiziot_os_aes_init(
        libpiziot_os_aes_key_t *Alpctx // Alpctx: AES context to be initialized
    );

    // ==== Clear AES context // AES ���c�Ѻc
    extern libpiziot_os_type_func_result_e libpiziot_os_aes_free(
        libpiziot_os_aes_key_t *Alpctx // Alpctx: AES context to be cleared
    );

    // ==== AES key set key
    // Alpctx: AES context to be set key
    // Alpkey: 32 bytes key
    // Akeybits: must be 128, 192 or 256
    // return: 0 if successful, or P2P_AES_COMMON_ERR_INVALID_KEY_LENGTH
    extern int32_t libpiziot_os_aes_create_key(
        libpiziot_os_aes_key_t *Alpctx, const unsigned char *Alpkey, const uint32_t Akeybits
    );

    // ==== AES-ECB block encryption
    // Alpctx AES context
    // Ainput[16]: 16-byte input block
    // Aoutput[16]: 16-byte output block
    extern void libpiziot_os_aes_ecb_encrypt(
        const libpiziot_os_aes_key_t* Alpaes_key, const unsigned char Ainput[16], unsigned char Aoutput[16]
    );

    // ==== AES-ECB block decryption
    // Alpctx AES context
    // Ainput[16]: 16-byte input block
    // Aoutput[16]: 16-byte output block
    extern void libpiziot_os_aes_ecb_decrypt(
        const libpiziot_os_aes_key_t* Alpaes_key, const unsigned char Ainput[16], unsigned char Aoutput[16]
    );

    // ==== AES-CBC block encryption
    // Alpctx AES context
    // param Alength: length of the input data
    // param Aiv[16]: initialization vector (updated after use)
    // Ainput[16]: 16-byte input block
    // Aoutput[16]: 16-byte output block
    // return: 0 if successful, or LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH
    extern int32_t libpiziot_os_aes_cbc_encrypt(
        const libpiziot_os_aes_key_t* Alpaes_key, const size_t Alength, const unsigned char Alpiv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN], const unsigned char *Alpinput, unsigned char *Alpoutput
    );

    // ==== AES-CBC block decryption
    // Alpctx AES context
    // param Alength: length of the input data
    // param Aiv[16]: initialization vector (updated after use)
    // Ainput[16]: buffer holding the input data
    // Aoutput[16]: buffer holding the output data
    // return: 0 if successful, or LIBPIZIOT_P2P_COMMON_ERR_INVALID_INPUT_LENGTH
    extern int32_t libpiziot_os_aes_cbc_decrypt(
        const libpiziot_os_aes_key_t* Alpaes_key, const size_t Alength, const unsigned char Alpiv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN], const unsigned char *Alpinput, unsigned char *Alpoutput
    );

    extern void libpiziot_p2p_common_deinit_fifo_buffer(
        libpiziot_p2p_common_fifo_t *Alplibpiziot_p2p_common_fifo
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_common_init_fifo_buffer(
        libpiziot_p2p_common_fifo_t *Alplibpiziot_p2p_common_fifo, int32_t Abuffer_size
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_common_write_data_to_buffer(
        libpiziot_os_fifo_buffer_info_t *Alpfifo_buffer, char *Alpbuff, int32_t Asize
    );

    extern void libpiziot_p2p_common_read_data_from_buffer(
        libpiziot_os_fifo_buffer_info_t *Alpfifo_buffer, int32_t Abuffer_max_size, char *Alpbuff, int32_t *Alpsize
    );

    extern void libpiziot_p2p_common_start_thread(
        void
    );

    extern void libpiziot_p2p_common_stop_thread(
        void
    );

    extern void libpiziot_p2p_common_get_version(
        unsigned char AlpVersion[4]
    );

    extern void libpiziot_p2p_common_set_net_print_msg(
        libpiziot_p2p_common_net_print_msg_e Aenable
    );

    extern libpiziot_os_type_func_result_e libpiziot_p2p_common_initialize(
        int32_t Asend_data_max_size
    );

    extern void libpiziot_p2p_common_finalize(
        void
    );

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_P2P_COMMON_H__
