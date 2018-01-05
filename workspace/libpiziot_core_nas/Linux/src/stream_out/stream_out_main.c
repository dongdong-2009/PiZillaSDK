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
#include "../../include/menu_config.h"

#if defined(ENABLE_STREAM_OUT)

//Define Kernel Library

//Define Static Library
#include "libpiziot/def_libpiziot_stream_in.h"
#include "libpiziot/def_libpiziot_stream_out.h"
#include "libpiziot/def_video_type.h"
#include "libpiziot/libpiziot_net_rtsp/def_libpiziot_net_rtsp.h"

//Define this Header
#include "stream_out_main.h"

//Define Other Header
//#include "rtsp_service.h"
//#include "rtsp_utils.h"
//#include "ring_fifo.h"

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

libpiziot_stream_out_main_check_url_p lplibpiziot_stream_out_main_check_url = 0;
static libpiziot_stream_out_thread_info_t m_stream_out_main_thread_info;
libpiziot_stream_out_session_t m_stream_out_session[LIBPIZIOT_NET_STREAM_OUT_LIST_MAX];

static int num_conn = 0; //�s���Ӽ�

#if defined(ENABLE_STREAM_IN)

static void stream_out_main_read_data_from_buffer(libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index, libpiziot_bitstream_head_video_t *Alpbs_head) {
    unsigned int fifo_max_read_size;
    int align_byte;

    libpiziot_os_fifo_buffer_info_t *lp_fifo_buffer_video = &(Alpstream_in_info->source_list[Astream_in_index].m_fifo_buffer_info);

    Alpbs_head->bs_length = 0;

    libpiziot_os_mutex_plock_lock(&(lp_fifo_buffer_video->fifo_mutex));
    do {
        if (lp_fifo_buffer_video->m_pRB == 0) {
            break;
        }
        fifo_max_read_size = libpiziot_os_fifo_buffer_get_max_read_size(lp_fifo_buffer_video, LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK);
        if (fifo_max_read_size <= sizeof(libpiziot_bitstream_head_video_t)) {
            break;
        }
        if (libpiziot_os_fifo_buffer_read(lp_fifo_buffer_video, (char *)Alpbs_head, sizeof(libpiziot_bitstream_head_video_t), LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK) != sizeof(libpiziot_bitstream_head_video_t)) {
            while (1) {
                TRACEA("stream_out:libpiziot_os_fifo_buffer_read(lp_fifo_buffer_video,(unsigned char*)Alpbs_head,sizeof(libpiziot_bitstream_head_video_t),return size,error !! %s:%d\n", LIBPIZIOT_OS__FUNCTION__, __LINE__);
                usleep(1000000);
            }
        }
#ifdef USE_INT_VALUE_CHECK
        if (libpiziot_os_debug_check_align_32bit_address(Alpbs_head->bs_length) != 0) {
            TRACEA("stream_out:Alpbs_head->bs_length video,align,error !!\n");
        }
        if (libpiziot_os_debug_check_int_value_by_address(Alpbs_head->bs_length, &(Alpbs_head->bs_length)) != 0) {
            while (1) {
                TRACEA("stream_out:libpiziot_os_debug_check_int_value_by_address,error !! %s:%d\n", LIBPIZIOT_OS__FUNCTION__, __LINE__);
                usleep(1000000);
            }
        }
#endif
        if (Alpbs_head->headmark != 12345678) {
            while (1) {
                TRACEA("stream_out:Alpbs_head->headmark != 12345678,error !! %s:%d\n", LIBPIZIOT_OS__FUNCTION__, __LINE__);
                usleep(1000000);
            }
        }

        align_byte = libpiziot_ice_os_check_point_align(Alpbs_head->bs_length);
        if (align_byte > 0) {
            align_byte = (LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE - align_byte);
        }

        if (Alpbs_head->bs_length > 0) {
            if (Alpbs_head->bs_length <= Alpstream_in_info->source_list[Astream_in_index].send_buff_size) {
                if (libpiziot_os_fifo_buffer_read(lp_fifo_buffer_video, Alpstream_in_info->source_list[Astream_in_index].lpsend_buff, Alpbs_head->bs_length, LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK) != Alpbs_head->bs_length) {
                    while (1) {
                        TRACEA("stream_out:libpiziot_os_fifo_buffer_read(lp_fifo_buffer_video,(unsigned char*)&(bs_head),sizeof(libpiziot_bitstream_head_video_t),return size,error !! %s:%d\n", LIBPIZIOT_OS__FUNCTION__, __LINE__);
                        usleep(1000000);
                    }
                }
            }
            else {
                if (libpiziot_os_fifo_buffer_read(lp_fifo_buffer_video, 0, Alpbs_head->bs_length, LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK) != Alpbs_head->bs_length) {
                    while (1) {
                        TRACEA("stream_out:libpiziot_os_fifo_buffer_read(lp_fifo_buffer_video,(unsigned char*)&(bs_head),sizeof(libpiziot_bitstream_head_video_t),return size,error !! %s:%d\n", LIBPIZIOT_OS__FUNCTION__, __LINE__);
                        usleep(1000000);
                    }
                }
                Alpbs_head->bs_length = 0;
            }
        }

        if (align_byte > 0) {
            char lpalign_byte[LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE];
            if (libpiziot_os_fifo_buffer_read(lp_fifo_buffer_video, lpalign_byte, align_byte, LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK) != align_byte) {
                while (1) {
                    TRACEA("stream_out:libpiziot_os_fifo_buffer_read(lp_fifo_buffer_video,(unsigned char*)&(bs_head),sizeof(libpiziot_bitstream_head_video_t),return size,error !! %s:%d\n", LIBPIZIOT_OS__FUNCTION__, __LINE__);
                    usleep(1000000);
                }
            }
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&(lp_fifo_buffer_video->fifo_mutex));
}

#endif //defined(ENABLE_STREAM_IN)

#if defined(ENABLE_STREAM_IN)

static void stream_out_main_send_data(libpiziot_stream_out_thread_info_t *Alpthread_info, libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index, libpiziot_bitstream_head_video_t *Alpbs_head) {
#if 0
    if (Astream_in_index == 0)
    {
        {
            unsigned char* lpBuff = Alpstream_in_info->lpframe_data[Astream_in_index];
            if (Alpbs_head->is_keyframe)
            {
                TRACEA("Astream_in_index[%d],LIBPIZIOT_STREAM_OUT_FRAME_TYPE_I len(%d),0x%02x,0x%02x,0x%02x,0x%02x,0x%02x\n", Astream_in_index, Alpbs_head->bs_length, lpBuff[0], lpBuff[1], lpBuff[2], lpBuff[3], lpBuff[4]);
            }
            else
            {
                TRACEA("Astream_in_index[%d],....LIBPIZIOT_STREAM_OUT_FRAME_TYPE_P len(%d),0x%02x,0x%02x,0x%02x,0x%02x,0x%02x\n", Astream_in_index, Alpbs_head->bs_length, lpBuff[0], lpBuff[1], lpBuff[2], lpBuff[3], lpBuff[4]);
            }
            //if(lpBuff[0] != 0 || lpBuff[1] != 0 || lpBuff[2] != 0 || lpBuff[3] != 1)
            //{
            // int j = 0;
            //}
        }
    }
#endif

    libpiziot_os_mutex_plock_lock(&(Alpthread_info->instance_mutex));
    {
        int32_t stream_out_index = 0;
        unsigned long long mnow;
        int32_t need_break;
        for (stream_out_index = 0; stream_out_index < LIBPIZIOT_NET_STREAM_OUT_LIST_MAX; stream_out_index++) {
            if (m_stream_out_session[stream_out_index].valid != 1) continue;
            need_break = 0;
            switch (m_stream_out_session[stream_out_index].session_type) {
#if defined(ENABLE_RTSP_LIB)
            case LIBPIZIOT_STREAM_OUT_SESSION_DEST_RTSP_RTP: {
                if (libpiziot_net_rtsp_service_rtp_session_check_pause(m_stream_out_session[stream_out_index].play_session) == -1) {
                    need_break = 1;
                    break;
                }
            }
                                                            break;
#endif //defined(ENABLE_RTSP_LIB)
            default: {
            }
                     break;
            }

            if (need_break == 1) continue;

            if ((m_stream_out_session[stream_out_index].stream_out_enPayLoad == Alpstream_in_info->source_list[Astream_in_index].stream_in_enPayLoad)
                && (m_stream_out_session[stream_out_index].stream_out_enSize == Alpstream_in_info->source_list[Astream_in_index].stream_in_enSize)) {
                if (Alpbs_head->is_keyframe) {
                    m_stream_out_session[stream_out_index].BeginFrame = 1;
                }
                if (m_stream_out_session[stream_out_index].BeginFrame == 1) {
                    libpiziot_stream_out_frame_type_e frame_type;
                    if (Alpbs_head->is_keyframe) {
                        frame_type = LIBPIZIOT_STREAM_OUT_FRAME_TYPE_I;
                        //TRACEA("stream_out_index[%d],LIBPIZIOT_STREAM_OUT_FRAME_TYPE_I len(%d)\n",stream_out_index,Alpbs_head->bs_length);
                    }
                    else {
                        frame_type = LIBPIZIOT_STREAM_OUT_FRAME_TYPE_P;
                        //TRACEA("stream_out_index[%d],....LIBPIZIOT_STREAM_OUT_FRAME_TYPE_P len(%d)\n",stream_out_index,Alpbs_head->bs_length);
                    }

                    //gettimeofday(&now,NULL);
                    //mnow = (now.tv_sec * 1000 + now.tv_usec / 1000);
                    mnow = (Alpbs_head->timestamp_tv_sec * 1000 + Alpbs_head->timestamp_tv_usec / 1000);
                    if (m_stream_out_session[stream_out_index].play_action != 0) {
                        m_stream_out_session[stream_out_index].play_action(stream_out_index, frame_type, m_stream_out_session[stream_out_index].play_session, Alpstream_in_info->source_list[Astream_in_index].lpsend_buff, Alpbs_head->bs_length, (unsigned int)mnow);
                    }
                }
            }
        }
    }
    libpiziot_os_mutex_plock_unlock(&(Alpthread_info->instance_mutex));
}

#endif //defined(ENABLE_STREAM_IN)

libpiziot_stream_out_url_check_e libpiziot_stream_out_main_check_url(libpiziot_stream_out_target_t *Alpstream_out_target, char *pFileName) {
    libpiziot_stream_out_url_check_e s32NoValUrl = LIBPIZIOT_STREAM_OUT_URL_CHECK_ERROR;
    do {
        if (0) {
        }
#if defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2) || defined(ENABLE_SIMULATE_VENC)
        else if (strcmp(pFileName, "720p") == 0) {
            Alpstream_out_target->url_enPayLoad = STREAM_LIBPIZIOT_IN_PT_H264;
            Alpstream_out_target->url_enSize = STREAM_IN_PIC_HD720;
        }
        else if (strcmp(pFileName, "wvga") == 0) {
            Alpstream_out_target->url_enPayLoad = STREAM_LIBPIZIOT_IN_PT_H264;
            Alpstream_out_target->url_enSize = STREAM_IN_PIC_WVGA;
        }
        else if (strcmp(pFileName, "vga") == 0) {
            Alpstream_out_target->url_enPayLoad = STREAM_LIBPIZIOT_IN_PT_H264;
            Alpstream_out_target->url_enSize = STREAM_IN_PIC_VGA;
        }
        else if (strcmp(pFileName, "qvga") == 0) {
            Alpstream_out_target->url_enPayLoad = STREAM_LIBPIZIOT_IN_PT_H264;
            Alpstream_out_target->url_enSize = STREAM_IN_PIC_QVGA;
        }
#endif //defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2) || defined(ENABLE_SIMULATE_VENC)
        else {
            if (Alpstream_out_target) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
            if (pFileName) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
            break;
#if 0
            if (pFileName)
            {
                Alpstream_out_target->url_enPayLoad = STREAM_LIBPIZIOT_IN_PT_H264;
                Alpstream_out_target->url_enSize = STREAM_IN_PIC_HD720;
            }
#endif //0
        }

#if defined(ENABLE_STREAM_IN)
        {
            libpiziot_stream_in_source_list_t *lpstream_in_info = &(m_libpiziot_stream_in_source_list);
            uint32_t stream_in_total = lpstream_in_info->stream_in_total;
            uint32_t stream_in_index;
            for (stream_in_index = 0; stream_in_index < stream_in_total; stream_in_index++) {
                if ((lpstream_in_info->source_list[stream_in_index].stream_in_enPayLoad == Alpstream_out_target->url_enPayLoad) && (lpstream_in_info->source_list[stream_in_index].stream_in_enSize == Alpstream_out_target->url_enSize)) {
                    s32NoValUrl = LIBPIZIOT_STREAM_OUT_URL_CHECK_OK;
                    break;
                }
            }
        }
#endif //defined(ENABLE_STREAM_IN)
    } while (0);
    return s32NoValUrl;
}

//��RTP�|�ܲK�[�ischedule��,���~��^-1,���`��^schedule��C��
libpiziot_os_type_func_result_e libpiziot_stream_out_main_add_session(void *Alpplay_session, libpiziot_stream_out_session_dest_e Asession_type, uint32_t AenPayLoad, uint32_t AenSize) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_stream_out_thread_info_t *lpthread_info = &(m_stream_out_main_thread_info);
    if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return rval;
    libpiziot_os_mutex_plock_lock(&(lpthread_info->instance_mutex));
    do {
        int32_t stream_out_index;
        for (stream_out_index = 0; stream_out_index < LIBPIZIOT_NET_STREAM_OUT_LIST_MAX; ++stream_out_index) {
            //�ݬO�٨S���Q�[�J��իצ�C�����|��
            if (m_stream_out_session[stream_out_index].valid != 0) continue;

            m_stream_out_session[stream_out_index].valid = 1;
            m_stream_out_session[stream_out_index].stream_out_enPayLoad = AenPayLoad;
            m_stream_out_session[stream_out_index].stream_out_enSize = AenSize;

            //�]�m����ʧ@
            {
                m_stream_out_session[stream_out_index].session_type = Asession_type;
                m_stream_out_session[stream_out_index].play_session = Alpplay_session;
                switch (m_stream_out_session[stream_out_index].session_type) {
#if defined(ENABLE_RTSP_LIB)
                case LIBPIZIOT_STREAM_OUT_SESSION_DEST_RTSP_RTP: {
                    libpiziot_net_rtsp_service_rtp_session_pause(m_stream_out_session[stream_out_index].play_session);
                    m_stream_out_session[stream_out_index].play_action = lib_net_rtp_utils_rtp_send;
                }
                                                                break;
#endif //defined(ENABLE_RTSP_LIB)
                default: {
                    m_stream_out_session[stream_out_index].play_action = 0;
                }
                         break;
                }
            }

            rval = stream_out_index;
            break;
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&(lpthread_info->instance_mutex));
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_stream_out_main_set_session_play(int32_t Astream_out_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_stream_out_thread_info_t *lpthread_info = &(m_stream_out_main_thread_info);
    if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return rval;
    libpiziot_os_mutex_plock_lock(&(lpthread_info->instance_mutex));
    do {
        //libpiziot_stream_out_thread_info_t *lpthread_info = &(m_stream_out_main_thread_info);
        {
            ////struct timeval now;
            //double mnow;
            //gettimeofday(&now,NULL);
            //mnow=(double)now.tv_sec*1000+(double)now.tv_usec/1000;

            switch (m_stream_out_session[Astream_out_index].session_type) {
#if defined(ENABLE_RTSP_LIB)
            case LIBPIZIOT_STREAM_OUT_SESSION_DEST_RTSP_RTP: {
                libpiziot_net_rtsp_service_rtp_session_play(m_stream_out_session[Astream_out_index].play_session);
            }
                                                            break;
#endif //defined(ENABLE_RTSP_LIB)
            default: {
            }
                     break;
            }

            //���񪬺A,�j��s�h��ܦ��Τ�ݼ�����
            //g_s32DoPlay++;
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&(lpthread_info->instance_mutex));
    return rval;
}

#if 0
void stream_out_main_set_session_stop(int id)
{
    libpiziot_stream_out_thread_info_t *lpthread_info = &(m_stream_out_main_thread_info);
    if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&(lpthread_info->instance_mutex));
    do
    {

        //RTCP_send_packet(m_stream_out_session[id].play_session,SR);
        //RTCP_send_packet(m_stream_out_session[id].play_session,BYE);

    } while (0);
    libpiziot_os_mutex_plock_unlock(&(lpthread_info->instance_mutex));
}
#endif //0

libpiziot_os_type_func_result_e libpiziot_stream_out_main_remove_session(int32_t Aid) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_stream_out_thread_info_t *lpthread_info = &(m_stream_out_main_thread_info);
    if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return rval;
    libpiziot_os_mutex_plock_lock(&(lpthread_info->instance_mutex));
    do {
        m_stream_out_session[Aid].valid = 0;
        m_stream_out_session[Aid].BeginFrame = 0;
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&(lpthread_info->instance_mutex));
    return rval;
}

static libpiziot_os_pthread_dword_t stream_out_main_thread_instance_routine(void *arg) {
    libpiziot_os_pthread_instance_t *lpthread_instance = (libpiziot_os_pthread_instance_t *)arg;
#if defined(ENABLE_STREAM_IN)
    libpiziot_stream_out_thread_info_t *lpthread_info = (libpiziot_stream_out_thread_info_t *)(lpthread_instance->m_extra);
    libpiziot_bitstream_head_video_t bs_head;
    uint32_t stream_in_index;
    libpiziot_stream_in_source_list_t *lpstream_in_info = &(m_libpiziot_stream_in_source_list);
#endif //defined(ENABLE_STREAM_IN)

    TRACEB("%s:start_routine ...\n", LIBPIZIOT_OS__FUNCTION__);

    do {
        usleep(1000);
        if (libpiziot_os_pthread_check_break(lpthread_instance, LIBPIZIOT_OS__FUNCTION__, __LINE__)) {
            TRACEB("%s:BreakThread\n", LIBPIZIOT_OS__FUNCTION__);
            break;
        }

#if defined(ENABLE_STREAM_IN)
        for (stream_in_index = 0; stream_in_index < lpstream_in_info->stream_in_total; stream_in_index++) {
            stream_out_main_read_data_from_buffer(lpstream_in_info, stream_in_index, &bs_head);
            if (bs_head.bs_length == 0) continue;
            stream_out_main_send_data(lpthread_info, lpstream_in_info, stream_in_index, &bs_head);
        }
#endif //defined(ENABLE_STREAM_IN)
    } while (1);
    TRACEB("%s:end_routine ...\n", LIBPIZIOT_OS__FUNCTION__);

    return (libpiziot_os_pthread_dword_t)1234567;
}

libpiziot_os_type_func_result_e libpiziot_stream_out_main_add_target(libpiziot_stream_out_target_t **Alppstream_out_target_list, libpiziot_stream_out_target_t **Alppstream_out_target_new, void *Alpinfo_arg) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_stream_out_target_t *lpstream_out_target_new = 0;
    do {
        if (num_conn >= LIBPIZIOT_NET_STREAM_OUT_LIST_MAX) {
            TRACEA("exceed the MAX client,ignore this connecting\n");
            break;
        }

        lpstream_out_target_new = (libpiziot_stream_out_target_t *)libpiziot_os_calloc(1, sizeof(libpiziot_stream_out_target_t));
        (*Alppstream_out_target_new) = lpstream_out_target_new;
        if (lpstream_out_target_new == 0) {
            TRACEA("alloc libpiziot_stream_out_target_t error %s,%i\n", __FILE__, __LINE__);
            break;
        }
        else {
            lpstream_out_target_new->next = NULL;
            lpstream_out_target_new->lpinfo_arg = Alpinfo_arg;
        }

        //�b����Y�����J�Ĥ@�Ӥ���
        {
            if (*Alppstream_out_target_list == NULL) {
                *Alppstream_out_target_list = lpstream_out_target_new;
            }
            else {
                libpiziot_stream_out_target_t *lpstream_out_target_end = NULL;
                //�V������J�s������
                {
                    libpiziot_stream_out_target_t *lpstream_out_target_loop = NULL;
                    for (lpstream_out_target_loop = *Alppstream_out_target_list; lpstream_out_target_loop != NULL; lpstream_out_target_loop = lpstream_out_target_loop->next) {
                        lpstream_out_target_end = lpstream_out_target_loop;
                    }
                }
                //�b���������J
                if (lpstream_out_target_end != NULL) {
                    lpstream_out_target_end->next = lpstream_out_target_new;
                }
            }

            num_conn++;
            TRACEA("Connected,total count: %d\n", num_conn);

            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
        }
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        if (lpstream_out_target_new != 0) {
            libpiziot_os_free(lpstream_out_target_new);
            (*Alppstream_out_target_new) = 0;
        }
    }
    return rval;
}

void libpiziot_stream_out_main_remove_target(libpiziot_stream_out_target_t **Alppstream_out_target_list, libpiziot_stream_out_target_t *Alpstream_out_target, libpiziot_stream_out_target_t **Alppstream_out_target_next) {
    num_conn--;
    TRACEA("RTSP Disconnected,remain client: %d\n", num_conn);

    if (Alpstream_out_target == *Alppstream_out_target_list) {
        *Alppstream_out_target_list = Alpstream_out_target->next;
        libpiziot_os_free(Alpstream_out_target);
        {
            (*Alppstream_out_target_next) = *Alppstream_out_target_list;
        }
    }
    else {
        libpiziot_stream_out_target_t *p = NULL;
        libpiziot_stream_out_target_t *p_last = NULL;
        for (p = (*Alppstream_out_target_list); p != NULL; p = p->next) {
            if (p == Alpstream_out_target) {
                libpiziot_stream_out_target_t *reindex = p->next;
                libpiziot_os_free(p);
                p = reindex;
                (*Alppstream_out_target_next) = reindex;
                if (p_last != NULL) {
                    p_last->next = reindex;
                }
            }
            p_last = p;
            if (p == NULL) {
                break;
            }
        }
    }
}

void stream_out_main_start_thread(void) {
    libpiziot_stream_out_thread_info_t *lpthread_info = &(m_stream_out_main_thread_info);
    if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return;
    libpiziot_os_mutex_plock_lock(&(lpthread_info->instance_mutex));
    do {
        if ((libpiziot_os_pthread_get_status(&(lpthread_info->thread_instance)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED)) {
            break;
        }
        if ((libpiziot_os_pthread_get_status(&(lpthread_info->thread_instance)) == LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED)) {
            if (libpiziot_os_pthread_create(&(lpthread_info->thread_instance), stream_out_main_thread_instance_routine, LIBPIZIOT_OS_PTHREAD_STACK_SIZE_AUTO, "stream_out") != 0) {
                TRACEA("%s:CreateUserPthread,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                break;
            }
            TRACEB("%s:Thread running ...\n", LIBPIZIOT_OS__FUNCTION__);
        }
        else {
            TRACEA("%s:already running,ignore start thread ...\n", LIBPIZIOT_OS__FUNCTION__);
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&(lpthread_info->instance_mutex));
}

void stream_out_main_stop_thread(void) {
    libpiziot_stream_out_thread_info_t *lpthread_info = &(m_stream_out_main_thread_info);
    if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return;
    {
        int32_t msg = 0;
        if (libpiziot_os_pthread_get_status(&(lpthread_info->thread_instance)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED) msg = 1;
        //if (msg == 1)
        //{
        // TRACEB("%s:libpiziot_os_pthread_release(...)\n", LIBPIZIOT_OS__FUNCTION__);
        // LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        //}
        libpiziot_os_pthread_release(&(lpthread_info->thread_instance));
        if (msg == 1) {
            TRACEB("%s:WaitUserPthread ...\n", LIBPIZIOT_OS__FUNCTION__);
            LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        }
        libpiziot_os_pthread_join(&(lpthread_info->thread_instance));
        if (msg == 1) {
            TRACEB("%s:THREAD_HANDLE_CLOSED ...\n", LIBPIZIOT_OS__FUNCTION__);
            LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        }
    }
}

static libpiziot_os_type_func_result_e stream_out_main_init(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        libpiziot_stream_out_thread_info_t *lpthread_info = &(m_stream_out_main_thread_info);
        memset_addr(libpiziot_stream_out_thread_info_t, lpthread_info, 0, sizeof(m_stream_out_main_thread_info));
        if (libpiziot_os_mutex_plock_init(&(lpthread_info->instance_mutex), NULL) != 0) {
            TRACEA("%s:mutex init &(lpthread_info->instance_mutex,error !!\n", LIBPIZIOT_OS__FUNCTION__);
            break;
        }
        {
            rval = libpiziot_os_pthread_initialize(&(lpthread_info->thread_instance), LIBPIZIOT_OS__FUNCTION__, __LINE__);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            lpthread_info->thread_instance.m_extra = &(m_stream_out_main_thread_info);
        }
        libpiziot_os_mutex_plock_lock(&(lpthread_info->instance_mutex));
        {
            //��l�Ƽƾ�
            int32_t stream_out_index;
            for (stream_out_index = 0; stream_out_index < LIBPIZIOT_NET_STREAM_OUT_LIST_MAX; ++stream_out_index) {
                m_stream_out_session[stream_out_index].play_session = 0;
                m_stream_out_session[stream_out_index].play_action = 0;
                m_stream_out_session[stream_out_index].valid = 0;
                m_stream_out_session[stream_out_index].BeginFrame = 0;
            }
        }
        libpiziot_os_mutex_plock_unlock(&(lpthread_info->instance_mutex));
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        TRACEA("stream_out_main_initialize,error !!\n");
    }
    return rval;
}

static libpiziot_os_type_func_result_e stream_out_main_deinit(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_stream_out_thread_info_t *lpthread_info = &(m_stream_out_main_thread_info);
    if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    do {
        if (libpiziot_os_pthread_finalize(&(lpthread_info->thread_instance)) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        }
        if (libpiziot_os_mutex_plock_free(&(lpthread_info->instance_mutex)) != 0) {
            TRACEA("mutex free &lpthread_info->instance_mutex,error !!\n");
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
    }
    else {
        TRACEB("%s,ok.\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

static void stream_out_main_clean_var(void) {
    stream_out_main_deinit();
}

static libpiziot_os_type_func_result_e stream_out_main_init_var(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        //int,temp;
        //struct timespec ts = { 2, 0 };
        //pthread_t id;

        lplibpiziot_stream_out_main_check_url = libpiziot_stream_out_main_check_url;

        if (stream_out_main_init() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;

        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        stream_out_main_clean_var();
    }
    return rval;
}

libpiziot_os_type_func_result_e stream_out_main_initialize(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
        if (stream_out_main_init_var() != 0) break;
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
    }
    else {
        TRACEB("%s,ok.\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

libpiziot_os_type_func_result_e stream_out_main_finalize(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
        stream_out_main_clean_var();
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    TRACEB("%s,ok.\n", LIBPIZIOT_OS__FUNCTION__);
    return rval;
}

#endif //defined(ENABLE_STREAM_OUT)
