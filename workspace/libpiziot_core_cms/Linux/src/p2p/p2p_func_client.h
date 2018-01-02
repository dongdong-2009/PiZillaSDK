#ifndef __P2P_FUNC_CLIENT_H__
#define __P2P_FUNC_CLIENT_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../include/menu_config.h"

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"
#include "p2p_func.h"

#define P2P_FUNC_UID_LENGTH_MAX 20

#define SAMPLE_CODE_P2P_LAN_SERVER_PORT_DEFAULT 14000

#define SAMPLE_CODE_P2P_DEVICE_LOGIN_CB "678ABCefg123DEFG!@#$^&*()-abcd45"
#define SAMPLE_CODE_P2P_DEVICE_LOGIN_IV "dc$rfv!qaz@wsx#e"
#define SAMPLE_CODE_P2P_CHANNEL_DATA_CB "!@#$^&*()-ABCDEFGabcdefg12345678"
#define SAMPLE_CODE_P2P_CHANNEL_DATA_IV "!qaz@wsx#edc$rfv"

typedef enum p2p_func_client_channel_aes_enum {
    P2P_FUNC_CLIENT_CHANNEL_AES_DISABLE = 0,
    P2P_FUNC_CLIENT_CHANNEL_AES_ENABLE = 1,
} p2p_func_client_channel_aes_e;

typedef enum p2p_func_client_channel_enable_enum {
    P2P_FUNC_CLIENT_CHANNEL_ENABLE_NOTHING = 0,
    P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO = 1,
    P2P_FUNC_CLIENT_CHANNEL_ENABLE_YES = 2,
} p2p_func_client_channel_enable_e;

typedef struct p2p_func_client_channel_enable_flag_s {
    int32_t enable;
    int32_t current;
} p2p_func_client_channel_enable_flag_t;

typedef struct libpiziot_core_p2p_protocol_command_head_s {
    uint32_t identy;
    uint32_t count;
    uint32_t sequence;
} libpiziot_core_p2p_protocol_command_head_t;

typedef enum p2p_func_client_protocol_action_flag_enum {
    P2P_FUNC_CLIENT_PROTOCOL_ACTION_END = 0,
    P2P_FUNC_CLIENT_PROTOCOL_ACTION_BEGIN = 1,
    P2P_FUNC_CLIENT_PROTOCOL_ACTION_RESEND = 2,
} p2p_func_client_protocol_action_flag_e;

#define P2P_FUNC_CLIENT_ACTION_WAIT_SEC 1

typedef struct p2p_func_client_protocol_action_status_s {
    struct timeval timeval_action_start;
    p2p_func_client_protocol_action_flag_e protocol_action_flag;
} p2p_func_client_protocol_action_status_t;

//#if (defined(ENABLE_P2P_IPCAMERA) && defined(ENABLE_P2P_NAS)) || (defined(ENABLE_P2P_IPCAMERA) && defined(ENABLE_P2P_CMS)) || (defined(ENABLE_P2P_NAS) && defined(ENABLE_P2P_CMS)) || (defined(ENABLE_P2P_GSERVER) && defined(ENABLE_P2P_GCLIENT))
//#define mem_endian_32(val) (((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val >> 8) & 0xFF00) | ((val >> 24) & 0xFF))
//#else
#define mem_endian_32(x) libpiziot_os_mem_endian_32(x)
//#endif //defined(ENABLE_ENDIAN_TEST)

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)
#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
    extern int32_t p2p_func_client_lan_server_handle;
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)

    extern libpiziot_os_type_func_result_e p2p_func_client_lan_server_start_thread(void);

    extern void p2p_func_client_lan_server_stop_thread(void);

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

    extern libpiziot_os_type_func_result_e p2p_func_client_aes_init_cb(libpiziot_os_aes_cbc_t *Alpcontext_cb, char *AlpCB, char *AlpIV);

    extern void p2p_func_client_aes_free_cb(libpiziot_os_aes_cbc_t *Alpcontext_cb);

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

#if defined(ENABLE_P2P_IPCAMERA)

    extern libpiziot_os_type_func_result_e p2p_func_client_device_get_ipcamera_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

    extern libpiziot_os_type_func_result_e p2p_func_client_device_get_ipcamera_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

    extern char *p2p_func_client_get_ipcamera_uuid_from_mtd(void);

#endif //defined(ENABLE_P2P_IPCAMERA)

#if defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

    extern libpiziot_os_type_func_result_e p2p_func_client_viewer_get_ipcamera_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

    extern libpiziot_os_type_func_result_e p2p_func_client_viewer_get_ipcamera_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

#endif //defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#if defined(ENABLE_P2P_NAS)

    extern libpiziot_os_type_func_result_e p2p_func_client_device_get_nas_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

    extern libpiziot_os_type_func_result_e p2p_func_client_device_get_nas_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

    extern char *p2p_func_client_get_nas_uuid_from_mtd(void);

#endif //defined(ENABLE_P2P_NAS)

#if defined(ENABLE_P2P_CMS)

    extern libpiziot_os_type_func_result_e p2p_func_client_viewer_get_nas_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

    extern libpiziot_os_type_func_result_e p2p_func_client_viewer_get_nas_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

#endif //defined(ENABLE_P2P_CMS)

#if defined(ENABLE_P2P_GSERVER)

    extern libpiziot_os_type_func_result_e p2p_func_client_device_get_gserver_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

    extern libpiziot_os_type_func_result_e p2p_func_client_device_get_gserver_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

    extern char *p2p_func_client_get_gserver_uuid_from_mtd(void);

#endif //defined(ENABLE_P2P_GSERVER)

#if defined(ENABLE_P2P_GCLIENT)

    extern libpiziot_os_type_func_result_e p2p_func_client_viewer_get_gserver_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

    extern libpiziot_os_type_func_result_e p2p_func_client_viewer_get_gserver_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size);

#endif //defined(ENABLE_P2P_GCLIENT)

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)

    extern char *p2p_func_client_p2p_get_device_mac_address(void);

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

    extern p2p_func_client_channel_enable_e p2p_function_client_channel_check_enable(p2p_func_client_channel_enable_flag_t *Alpchannel_enable);

    extern libpiziot_os_type_func_result_e p2p_func_client_start_thread(void);

    extern libpiziot_os_type_func_result_e p2p_func_client_stop_thread(void);

    extern libpiziot_os_type_func_result_e p2p_func_client_initialize(void);

    extern void p2p_func_client_finalize(void);

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

#ifdef __cplusplus
}
#endif

#endif //__P2P_FUNC_CLIENT_H__
