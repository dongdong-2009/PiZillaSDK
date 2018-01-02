#ifndef __DEF_LIBPIZIOT_NET_RTSP_H__
#define __DEF_LIBPIZIOT_NET_RTSP_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#include "../def_libpiziot_stream_out.h"

#ifdef __cplusplus
extern "C"
{
#endif

    extern int32_t libpiziot_net_rtsp_service_rtp_session_check_pause(void *Alpplay_session);
    extern void libpiziot_net_rtsp_service_rtp_session_pause(void *Alpplay_session);
    extern void libpiziot_net_rtsp_service_rtp_session_play(void *Alpplay_session);
    extern int32_t lib_net_rtp_utils_rtp_send(int32_t Aremote_id, libpiziot_stream_out_frame_type_e Aframe_type, void *Alpplay_session, char *pData, int32_t As32DataSize, uint32_t u32TimeStamp);

    extern void libpiziot_net_rtsp_service_UpdateSps(unsigned char *data, int len);
    extern void libpiziot_net_rtsp_service_UpdatePps(unsigned char *data, int len);

    extern void libpiziot_net_rtsp_start_thread(void);
    extern void libpiziot_net_rtsp_stop_thread(void);
    extern libpiziot_os_type_func_result_e libpiziot_net_rtsp_initialize(void);
    extern void libpiziot_net_rtsp_finalize(void);

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_NET_RTSP_H__
