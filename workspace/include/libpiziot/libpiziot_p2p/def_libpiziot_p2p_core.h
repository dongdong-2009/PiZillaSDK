#ifndef __DEF_LIBPIZIOT_P2P_CORE_H__
#define __DEF_LIBPIZIOT_P2P_CORE_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

//#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
//#include "libpiziot/libpiziot_os/def_libpiziot_os_resource.h"
//#include "libpiziot/libpiziot_os/def_libpiziot_os_mutex.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_socket.h"
//#include "def_libpiziot_p2p_common.h"

#define LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND 100
#define LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON
//#define LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER 999

#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND 200
#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON
#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM
//#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER 9999

#define LIBPIZIOT_CORE_P2P_PROTOCOL_GSERVER_COMMAND 100
#define LIBPIZIOT_CORE_P2P_PROTOCOL_GSERVER_COMMAND_COMMON
//#define LIBPIZIOT_CORE_P2P_PROTOCOL_GSERVER_OTHER 999

typedef struct libpiziot_core_p2p_data_from_client_head_s {
    int32_t device_handle;
    int32_t channel_server_handle;
    struct sockaddr_in in_channel_client_ip;
} libpiziot_core_p2p_data_from_client_head_t;

typedef enum libpiziot_core_p2p_protocol_optoin_timezone_enum {
    LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_UNKNOWN = -9999,
    LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI = 8,
} libpiziot_core_p2p_protocol_optoin_timezone_e;

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
typedef enum libpiziot_core_p2p_protocol_optoin_yn_enum {
    LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO = 0,
    LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES = 1,
} libpiziot_core_p2p_protocol_optoin_yn_e;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

typedef struct libpiziot_core_p2p_cmd_head_from_client_s {
    uint32_t size;
    uint32_t cmd;
} libpiziot_core_p2p_cmd_head_from_client_t;

typedef struct libpiziot_core_p2p_cmd_head_from_server_s {
    uint32_t size;
    uint32_t cmd;
    uint32_t channel_server_handle;
} libpiziot_core_p2p_cmd_head_from_server_t;

#ifdef __cplusplus
extern "C"
{
#endif

    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_LIVE_VIDEO_TO_APP 101
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_LIVE_AUDIO_TO_APP 102
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_LIVE_AUDIO_FROM_APP 103
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_PLAYBACK_VIDEO_TO_APP 104
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_PLAYBACK_AUDIO_TO_APP 105

//PIZCam
    extern char *libpiziot_core_p2p_get_ipcamera_uid(void); //libpiziot_core_p2p_ipcamera_main_get_device_uid

    extern int32_t libpiziot_core_p2p_create_ipcamera(const char *AlpUID); //libpiziot_core_p2p_ipcamera_main_create_ipcamera

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_delete_ipcamera(int32_t Aarray_index); //libpiziot_core_p2p_ipcamera_main_delete_ipcamera

    extern void libpiziot_core_p2p_ipcamera_enable_device_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern void libpiziot_core_p2p_ipcamera_disable_device_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_ipcamera_main_device_channel_send(int32_t Aarray_index, int32_t Achannel_id, unsigned char *Alpdata_send, int32_t Adata_size);

    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_01_LIVE_VIDEO_TO_APP 1001
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_01_LIVE_AUDIO_TO_APP 1002
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_01_LIVE_AUDIO_FROM_APP 1003
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_01_PLAYBACK_VIDEO_TO_APP 1004
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_01_PLAYBACK_AUDIO_TO_APP 1005

    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_02_LIVE_VIDEO_TO_APP 2001
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_02_LIVE_AUDIO_TO_APP 2002
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_02_LIVE_AUDIO_FROM_APP 2003
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_02_PLAYBACK_VIDEO_TO_APP 2004
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_02_PLAYBACK_AUDIO_TO_APP 2005

    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_03_LIVE_VIDEO_TO_APP 3001
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_03_LIVE_AUDIO_TO_APP 3002
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_03_LIVE_AUDIO_FROM_APP 3003
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_03_PLAYBACK_VIDEO_TO_APP 3004
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_03_PLAYBACK_AUDIO_TO_APP 3005

    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_04_LIVE_VIDEO_TO_APP 4001
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_04_LIVE_AUDIO_TO_APP 4002
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_04_LIVE_AUDIO_FROM_APP 4003
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_04_PLAYBACK_VIDEO_TO_APP 4004
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_04_PLAYBACK_AUDIO_TO_APP 4005

    extern char *libpiziot_core_p2p_get_nas_uid(void);

    //NPIZNas device
    extern int32_t libpiziot_core_p2p_create_nas(const char *AlpUID);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_delete_nas(int32_t Aarray_index);

    extern void libpiziot_core_p2p_nas_enable_device_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern void libpiziot_core_p2p_nas_disable_device_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_nas_main_device_channel_send(int32_t Aarray_index, int32_t Achannel_id, unsigned char *Alpdata_send, int32_t Adata_size);

    //NPIZNas viewer
    extern int32_t libpiziot_core_p2p_nas_connect_ipcamera(const char *AlpUID);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_nas_disconnect_ipcamera(int32_t Aarray_index);

    extern void libpiziot_core_p2p_nas_enable_viewer_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern void libpiziot_core_p2p_nas_disable_viewer_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_nas_main_viewer_channel_send(int32_t Aarray_index, int32_t Achannel_id, unsigned char *Alpdata_send, int32_t Adata_size);

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_nas_viewer_channel_common_get_model(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_nas_viewer_channel_common_get_fwverp2p(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_nas_viewer_channel_common_set_reboot(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_nas_viewer_channel_common_set_timezone(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_timezone_e Aoption_timezone);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_nas_viewer_channel_common_get_timezone(int32_t Aarray_index);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)

    //PIZCms ipcamera
    extern int32_t libpiziot_core_p2p_cms_connect_ipcamera(const char *AlpUID);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_disconnect_ipcamera(int32_t Aarray_index);

    extern void libpiziot_core_p2p_cms_enable_ipcamera_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern void libpiziot_core_p2p_cms_disable_ipcamera_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_main_ipcamera_channel_send(int32_t Aarray_index, int32_t Achannel_id, unsigned char *Alpdata_send, int32_t Adata_size);

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_channel_common_get_model(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_channel_common_get_fwverp2p(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_channel_common_set_reboot(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_channel_common_set_timezone(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_timezone_e Aoption_timezone);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_channel_common_get_timezone(int32_t Aarray_index);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)

    //PIZCms nas
    extern int32_t libpiziot_core_p2p_cms_connect_nas(const char *AlpUID);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_disconnect_nas(int32_t Aarray_index);

    extern void libpiziot_core_p2p_cms_enable_nas_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern void libpiziot_core_p2p_cms_disable_nas_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_main_nas_channel_send(int32_t Aarray_index, int32_t Achannel_id, unsigned char *Alpdata_send, int32_t Adata_size);

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_common_get_model(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_common_get_fwverp2p(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_common_set_reboot(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_common_set_timezone(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_timezone_e Aoption_timezone);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_common_get_timezone(int32_t Aarray_index);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_yn_e Aoption_yn);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_yn_e Amute_mode);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_yn_e Acallout_mode);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout(int32_t Aarray_index);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

    //PIZGserver
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_GSERVER_COMMAND_LIVE_VIDEO_TO_APP 101
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_GSERVER_COMMAND_LIVE_AUDIO_TO_APP 102
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_GSERVER_COMMAND_LIVE_AUDIO_FROM_APP 103
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_GSERVER_COMMAND_PLAYBACK_VIDEO_TO_APP 104
    //#define LIBPIZIOT_CORE_P2P_PROTOCOL_GSERVER_COMMAND_PLAYBACK_AUDIO_TO_APP 105

    //PIZCam
    extern char *libpiziot_core_p2p_get_gserver_uid(void); //libpiziot_core_p2p_gserver_main_get_device_uid

    extern int32_t libpiziot_core_p2p_create_gserver(const char *AlpUID); //libpiziot_core_p2p_gserver_main_create_gserver

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_delete_gserver(int32_t Aarray_index); //libpiziot_core_p2p_gserver_main_delete_gserver

    extern void libpiziot_core_p2p_gserver_enable_device_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern void libpiziot_core_p2p_gserver_disable_device_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_gserver_main_device_channel_send(int32_t Aarray_index, int32_t Achannel_id, unsigned char *Alpdata_send, int32_t Adata_size);

    //PIZGclient
    //PIZGclient gserver
    extern int32_t libpiziot_core_p2p_gclient_connect_gserver(const char *AlpUID);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_gclient_disconnect_gserver(int32_t Aarray_index);

    extern void libpiziot_core_p2p_gclient_enable_gserver_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern void libpiziot_core_p2p_gclient_disable_gserver_channel(int32_t Aarray_index, int32_t Achannel_id);

    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_gclient_main_gserver_channel_send(int32_t Aarray_index, int32_t Achannel_id, unsigned char *Alpdata_send, int32_t Adata_size);

#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_GSERVER_COMMAND_COMMON)
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_gclient_gserver_channel_common_get_model(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_gclient_gserver_channel_common_get_fwverp2p(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_gclient_gserver_channel_common_set_reboot(int32_t Aarray_index);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_gclient_gserver_channel_common_set_timezone(int32_t Aarray_index, libpiziot_core_p2p_protocol_optoin_timezone_e Aoption_timezone);
    extern libpiziot_os_type_func_result_e libpiziot_core_p2p_gclient_gserver_channel_common_get_timezone(int32_t Aarray_index);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_GSERVER_COMMAND_COMMON)

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_P2P_CORE_H__
