#ifndef __DEF_LIBPIZIOT_STREAM_OUT_H__
#define __DEF_LIBPIZIOT_STREAM_OUT_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "libpiziot_os/def_libpiziot_os_type.h"
#include "libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot_os/def_libpiziot_os_resource.h"
#include "libpiziot_os/def_libpiziot_os_socket.h"
#include "def_libpiziot_stream_in.h"

typedef enum libpiziot_stream_out_url_check_enum {
    LIBPIZIOT_STREAM_OUT_URL_CHECK_OK = 0,
    LIBPIZIOT_STREAM_OUT_URL_CHECK_ERROR,
} libpiziot_stream_out_url_check_e;

typedef struct libpiziot_stream_out_thread_info_s {
    libpiziot_os_mutex_struct_plock_t instance_mutex;
    libpiziot_os_pthread_instance_t thread_instance;
} libpiziot_stream_out_thread_info_t;

typedef enum libpiziot_stream_out_frame_type_enum {
    LIBPIZIOT_STREAM_OUT_FRAME_TYPE_I,
    LIBPIZIOT_STREAM_OUT_FRAME_TYPE_P,
    LIBPIZIOT_STREAM_OUT_FRAME_TYPE_B,
} libpiziot_stream_out_frame_type_e;

typedef int32_t (*libpiziot_stream_out_play_action_p)(int32_t Aremote_id, libpiziot_stream_out_frame_type_e Aframe_type, void *Alpplay_session, char *pData, int32_t As32DataSize, uint32_t u32TimeStamp);

typedef enum libpiziot_stream_out_session_dest_enum {
    LIBPIZIOT_STREAM_OUT_SESSION_DEST_RTSP_RTP,
    LIBPIZIOT_STREAM_OUT_SESSION_DEST_P2P,
} libpiziot_stream_out_session_dest_e;

typedef struct libpiziot_stream_out_session_s {
    int32_t valid;
    int32_t BeginFrame;
    libpiziot_stream_out_session_dest_e session_type;
    void *play_session;
    libpiziot_stream_out_play_action_p play_action;
    libpiziot_stream_in_payload_type_e stream_out_enPayLoad;
    stream_in_pic_size_e stream_out_enSize;
} libpiziot_stream_out_session_t;

extern libpiziot_stream_out_session_t m_stream_out_session[LIBPIZIOT_NET_STREAM_OUT_LIST_MAX];

typedef struct libpiziot_stream_out_target_s {
    libpiziot_stream_in_payload_type_e enPayLoad;
    stream_in_pic_size_e enSize;
    libpiziot_stream_in_payload_type_e url_enPayLoad;
    stream_in_pic_size_e url_enSize;
    int need_get_client_addr;
    struct sockaddr_in in_client_ip;
    struct timeval packet_timer;
    struct timeval packet_timer_last;
    uint32_t packet_count;
    void *lpinfo_arg;
    struct libpiziot_stream_out_target_s *next;
#define RTSP_BUFFERSIZE 4096
    char buffer[RTSP_BUFFERSIZE + 1]; // +1 to control the final '\0'
} libpiziot_stream_out_target_t;

#if 0
typedef struct libipiziot_stream_out_play_args_s
{
    //struct tmplayback_time;
    //short playback_time_valid;
    float start_time;
    //short start_time_valid;
    float end_time;
}libipiziot_stream_outlibipiziot_stream_out_play_args_s_t;
#endif //0

#ifdef __cplusplus
extern "C"
{
#endif

    typedef libpiziot_stream_out_url_check_e (*libpiziot_stream_out_main_check_url_p)(libpiziot_stream_out_target_t *Alpstream_out_target, char *pFileName);
    extern libpiziot_stream_out_main_check_url_p lplibpiziot_stream_out_main_check_url;

    extern libpiziot_stream_out_url_check_e libpiziot_stream_out_main_check_url(libpiziot_stream_out_target_t *Alpstream_out_target, char *pFileName);

    extern libpiziot_os_type_func_result_e libpiziot_stream_out_main_add_session(void *Alpplay_session, libpiziot_stream_out_session_dest_e Asession_type, uint32_t AenPayLoad, uint32_t AenSize);
    extern libpiziot_os_type_func_result_e libpiziot_stream_out_main_set_session_play(int32_t Astream_out_index);
    //void stream_out_main_set_session_stop(intid);
    extern libpiziot_os_type_func_result_e libpiziot_stream_out_main_remove_session(int32_t Aid);

    extern libpiziot_os_type_func_result_e libpiziot_stream_out_main_add_target(libpiziot_stream_out_target_t **Alppstream_out_target_list, libpiziot_stream_out_target_t **Alppstream_out_target_new, void *Alpinfo_arg);
    extern void libpiziot_stream_out_main_remove_target(libpiziot_stream_out_target_t **Alppstream_out_target_list, libpiziot_stream_out_target_t *Alpstream_out_target, libpiziot_stream_out_target_t **Alppstream_out_target_next);

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_STREAM_OUT_H__
