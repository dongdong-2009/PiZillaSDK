#include "stdafx.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define C Libary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//hisp #include <fcntl.h> //O_RDONLY,O_WRONLY
//hisp #include <errno.h>

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

//Define Windows Library

//Define MENU_CONFIG_H Library
#include "../../include/menu_config.h"

#if defined(ENABLE_STREAM_IN)

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"

#if defined(ENABLE_STREAM_OUT)

#include "libpiziot/libpiziot_net_rtsp/def_libpiziot_net_rtsp.h"

#endif //defined(ENABLE_STREAM_OUT)

#include "libpiziot/def_video_type.h"

//Define this Header
#include "stream_in_main.h"

//Define Other Header
#include "stream_in_emulator.h"

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

static stream_in_main_thread_info_t m_stream_in_main_thread_info;
libpiziot_stream_in_source_list_t m_libpiziot_stream_in_source_list;
static char align_char_video[7] = { 0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD };

#if defined(ENABLE_HI3518E_V1)

void stream_in_main_write_data_to_buffer(VENC_STREAM_V1_S *pstStream, libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index)
#elif defined(ENABLE_HI3518E_V2)
void stream_in_main_write_data_to_buffer(VENC_STREAM_V2_S *pstStream, libpiziot_stream_in_source_list_t* Alpstream_in_info, uint32_t Astream_in_index)
#else

void stream_in_main_write_data_to_buffer(VENC_STREAM_V_S *pstStream, libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index)
#endif
{
    uint32_t i;
    //HI_S32 j;
    int32_t len = 0;
    //HI_S32 len2 = 2;
    unsigned char *pstr;
    int iframe = 0;
    libpiziot_os_fifo_buffer_info_t *lpVideoEncoder_FIFO_buffer = &(Alpstream_in_info->source_list[Astream_in_index].m_fifo_buffer_info);

    for (i = 0; i < pstStream->u32PackCount; i++) {
#if defined(ENABLE_HI3518E_V1)
        len += pstStream->pstPack[i].u32Len[0];
        if (pstStream->pstPack[i].u32Len[1] > 0) {
            len += pstStream->pstPack[i].u32Len[1];
        }
#elif defined(ENABLE_HI3518E_V2)
        len += pstStream->pstPack[i].u32Len - pstStream->pstPack[i].u32Offset;
#else
        len += pstStream->pstPack[i].u32Len - pstStream->pstPack[i].u32Offset;
#endif

        //check frame type
#if defined(ENABLE_HI3518E_V1)
        pstr = pstStream->pstPack[i].pu8Addr[0];
#elif defined(ENABLE_HI3518E_V2)
        pstr = pstStream->pstPack[i].pu8Addr + pstStream->pstPack[i].u32Offset;
#else
        pstr = pstStream->pstPack[i].pu8Addr + pstStream->pstPack[i].u32Offset;
#endif

        {
            uint8_t frame_type = pstr[4] & 0x1F;
            if (frame_type == NALU_TYPE_SPS) {
#if defined(ENABLE_STREAM_OUT) && defined(ENABLE_RTSP_LIB)
                libpiziot_net_rtsp_service_UpdateSps(pstr, 9);
#endif //defined(ENABLE_STREAM_OUT) && defined(ENABLE_RTSP_LIB)

                iframe = 1;
            }
            else if (frame_type == NALU_TYPE_PPS) {
#if defined(ENABLE_STREAM_OUT) && defined(ENABLE_RTSP_LIB)
                libpiziot_net_rtsp_service_UpdatePps(pstr, 4);
#endif //defined(ENABLE_STREAM_OUT) && defined(ENABLE_RTSP_LIB)
            }
        }
    }

    libpiziot_os_mutex_plock_lock(&(lpVideoEncoder_FIFO_buffer->fifo_mutex));
    do {
        int fifo_max_write_size;
        int align_byte;
        libpiziot_bitstream_head_video_t bs_head;

        if (len == 0) break;

        if (lpVideoEncoder_FIFO_buffer->m_pRB == 0) {
            //TRACEA("VideoBuffer[%d]->m_pRB == 0\n",Astream_in_index);
            break;
        }
        memset_addr(libpiziot_bitstream_head_video_t, &(bs_head), 0, sizeof(bs_head));

        //check buffer size
        {
            fifo_max_write_size = libpiziot_os_fifo_buffer_get_max_write_size(lpVideoEncoder_FIFO_buffer, LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK);
            //TRACEA("size[%d]=%d\n",Astream_in_index,sizeof(bs_head) + (int)(len + (LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE - 1)));
            if ((int)(sizeof(bs_head) + (len + (LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE - 1))) > fifo_max_write_size) {
                if ((int32_t)(sizeof(bs_head) + len + (LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE - 1)) > lpVideoEncoder_FIFO_buffer->m_ulSize) {
                    TRACEA("VideoBuffer[%d],head(%d) + ((len + align)=%d) = %d > lpfifo_extra->buffer_size(%d)\n", Astream_in_index, sizeof(bs_head), len + (LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE - 1), sizeof(bs_head) + len + (LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE - 1), lpVideoEncoder_FIFO_buffer->m_ulSize);
                }
                else {
                    //TRACEA("out of VideoBuffer[%d],head(%d) + len+3(%d) = %d\n",Astream_in_index,sizeof(bs_head),len + (LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE - 1),sizeof(bs_head) + len + (LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE - 1));
                }
                break;
            }
        }

        //write head
        {
            bs_head.bs_length = len;
            bs_head.headmark = 12345678;
            {
                struct timeval timestamp;
                gettimeofday(&timestamp, NULL);
                bs_head.timestamp_tv_sec = timestamp.tv_sec;
                bs_head.timestamp_tv_usec = timestamp.tv_usec;
            }
            bs_head.data_type = BitstreamDataType_Video;

#ifdef USE_INT_VALUE_CHECK
            if (libpiziot_os_debug_check_align_32bit_address(bs_head.bs_length) != 0) {
                TRACEA("bs_head.bs_length,align,error !!\n");
            }
            if (libpiziot_os_debug_check_int_value_by_address(bs_head.bs_length, &(bs_head.bs_length)) != 0) {
                TRACEA("bs_head.bs_length,value align,error !!\n");
            }
#else
#error
#endif //USE_INT_VALUE_CHECK

            if (iframe) {
                bs_head.is_keyframe = 1;
                //TRACEA("LIBPIZIOT_STREAM_OUT_FRAME_TYPE_I len(%d)\n",len);
            }
            else {
                bs_head.is_keyframe = 0;
                //TRACEA("LIBPIZIOT_STREAM_OUT_FRAME_TYPE_P len(%d)\n",len);
            }

            if (libpiziot_os_fifo_buffer_write(lpVideoEncoder_FIFO_buffer, (char *) &(bs_head), sizeof(bs_head), LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK) != sizeof(bs_head)) {
                while (1) {
                    TRACEA("VideoBuffer[%d],libpiziot_os_fifo_buffer_write size error sizeof(bs_head)=%d %s:%d\n", Astream_in_index, sizeof(bs_head), LIBPIZIOT_OS__FUNCTION__, __LINE__);
                    usleep(1000000);
                }
            }
        }

        {
            for (i = 0; i < pstStream->u32PackCount; i++) {
#if defined(ENABLE_HI3518E_V1)
                {
                    int32_t copy_size = pstStream->pstPack[i].u32Len[0];
                    pstr = pstStream->pstPack[i].pu8Addr[0];
                    if (copy_size > 0) {
                        {
                            if (libpiziot_os_fifo_buffer_write(lpVideoEncoder_FIFO_buffer, (char *)(pstr), copy_size, LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK) != copy_size) {
                                while (1) {
                                    TRACEA("VideoBuffer[%d],libpiziot_os_fifo_buffer_write size error %s:%d\n", Astream_in_index, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                                    usleep(1000000);
                                }
                            }
                        }
                    }
                }
#elif defined(ENABLE_HI3518E_V2)
                {
                    int32_t copy_size = pstStream->pstPack[i].u32Len - pstStream->pstPack[i].u32Offset;
                    pstr = pstStream->pstPack[i].pu8Addr + pstStream->pstPack[i].u32Offset;
                    if (copy_size > 0)
                    {
                        if (libpiziot_os_fifo_buffer_write(lpVideoEncoder_FIFO_buffer, (char*)(pstr), copy_size, LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK) != copy_size)
                        {
                            while (1)
                            {
                                TRACEA("VideoBuffer[%d],libpiziot_os_fifo_buffer_write size error %s:%d\n", Astream_in_index, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                                usleep(1000000);
                            }
                        }
                    }
                }
#else
                {
                    int32_t copy_size = pstStream->pstPack[i].u32Len - pstStream->pstPack[i].u32Offset;
                    pstr = pstStream->pstPack[i].pu8Addr + pstStream->pstPack[i].u32Offset;
                    if (copy_size > 0) {
                        if (libpiziot_os_fifo_buffer_write(lpVideoEncoder_FIFO_buffer, (char *)(pstr), copy_size, LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK) != copy_size) {
                            while (1) {
                                TRACEA("VideoBuffer[%d],libpiziot_os_fifo_buffer_write size error %s:%d\n", Astream_in_index, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                                usleep(1000000);
                            }
                        }
                    }
                }
#endif

                {
#if defined(ENABLE_HI3518E_V1)
                    int32_t copy_size = pstStream->pstPack[i].u32Len[1];
                    if (copy_size > 0) {
                        //TRACEA("u32Len[1] > 0\n");
                        pstr = pstStream->pstPack[i].pu8Addr[1];
                        if (libpiziot_os_fifo_buffer_write(lpVideoEncoder_FIFO_buffer, (char *)(pstr), copy_size, LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK) != copy_size) {
                            while (1) {
                                TRACEA("VideoBuffer[%d],libpiziot_os_fifo_buffer_write size error %s:%d\n", Astream_in_index, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                                usleep(1000000);
                            }
                        }
                    }

                    //TRACEA("0x%02x,len(%d)\n",pstr[4],pstStream->pstPack[i].u32Len[0] + pstStream->pstPack[i].u32Len[1]);

#endif //defined(ENABLE_HI3518E_V1)
                }
            }

            //write align byte
            {
                align_byte = libpiziot_ice_os_check_point_align(bs_head.bs_length);
                if (align_byte > 0) {
                    align_byte = (LIBPIZIOT_ICE_OS_CHECK_POINT_ALIGN_SIZE - align_byte);
                }
                if (align_byte > 0) {
                    if (libpiziot_os_fifo_buffer_write(lpVideoEncoder_FIFO_buffer, align_char_video, align_byte, LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK) != align_byte) {
                        while (1) {
                            TRACEA("VideoBuffer[%d],libpiziot_os_fifo_buffer_write size error align_byte=%d %s:%d\n", Astream_in_index, align_byte, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                            usleep(1000000);
                        }
                    }
                }
            }

        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&(lpVideoEncoder_FIFO_buffer->fifo_mutex));
}

static libpiziot_os_pthread_dword_t stream_in_main_thread_instance_routine_get_frame(void *arg) {
    libpiziot_os_pthread_instance_t *lpthread_instance = (libpiziot_os_pthread_instance_t *)arg;
    stream_in_main_thread_info_t *lpthread_info = (stream_in_main_thread_info_t *)(lpthread_instance->m_extra);
    //hisp sonix_queue_get_video_t data;
    libpiziot_stream_in_source_list_t *lpstream_in_info = &(m_libpiziot_stream_in_source_list);
    int32_t venc_index;


#if defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2)
    lpthread_info->m_sample_venc_classic_init_flag = 1;
    {
        SAMPLE_VENC_CLASSIC_INIT(lpstream_in_info);
        if (SAMPLE_COMM_VENC_GetVencStreamProc_Init(lpstream_in_info) != HI_SUCCESS) {
            lpthread_info->m_sample_venc_classic_init_flag = 2;
        }
    }
#else
    lpthread_info->m_sample_venc_classic_init_flag = 1;
#endif //defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2)

    if (lpthread_info->m_sample_venc_classic_init_flag == 1) {
        uint32_t stream_in_index;
        uint32_t stream_in_total = lpstream_in_info->stream_in_total;
        do {
            usleep(1000);
            if (libpiziot_os_pthread_check_break(lpthread_instance, LIBPIZIOT_OS__FUNCTION__, __LINE__)) {
                TRACEB("Video Encoder Channel SRC[%d],BreakThread\n", Astream_in_index);
                break;
            }

            for (stream_in_index = 0; stream_in_index < stream_in_total; stream_in_index++) {
                venc_index = lpstream_in_info->source_list[stream_in_index].venc_index;
                if (venc_index < 0) continue;

                switch (lpstream_in_info->source_list[stream_in_index].venc_dsp_type) {
                case VENC_DSP_TYPE_EMULATOR: {
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#if defined(ENABLE_SIMULATE_VENC)
                    {
#define VENC_PACK_COUNT 5

#if defined(ENABLE_HI3518E_V1)
                        VENC_STREAM_V1_S stStream;
                        VENC_PACK_V1_S venc_pack[VENC_PACK_COUNT];
#elif defined(ENABLE_HI3518E_V2)
                        VENC_STREAM_V2_S stStream;
                        VENC_PACK_V2_S venc_pack[VENC_PACK_COUNT];
#else
                        VENC_STREAM_V_S stStream;
                        VENC_PACK_V_S venc_pack[VENC_PACK_COUNT];
#endif //defined(ENABLE_HI3518E_V2)

                        stStream.pstPack = venc_pack;
                        stStream.u32PackCount = VENC_PACK_COUNT;

                        {
                            if (stream_in_emulator_GetH264DataFromEmulator(&stStream, lpstream_in_info, stream_in_index, venc_index) == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                                stream_in_main_write_data_to_buffer(&stStream, lpstream_in_info, stream_in_index);
                                stream_in_emulator_NextH264DataFromEmulator(venc_index);
                            }
                        }
                    }
#endif //defined(ENABLE_SIMULATE_VENC)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
                }
                                             break;
                case VENC_DSP_TYPE_HI3518E: {
#if !defined(__LIBPIZIOT_OS_PLATFORM_MFC__) && !defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#if defined(ENABLE_HI3518E_V1)
                    VI_WRITE_BUFF_FUNC_V1_t lpCallBackFunc = stream_in_main_write_data_to_buffer;
                    if (SAMPLE_COMM_VENC_GetVencStreamProc(lpstream_in_info, stream_in_index, lpstream_in_info->source_list[stream_in_index].venc_index, lpCallBackFunc) != HI_SUCCESS) {
                        break;
                    }
#endif //defined(ENABLE_HI3518E_V1)
#endif //!defined(__LIBPIZIOT_OS_PLATFORM_MFC__) && !defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
                }
                                            break;
                case VENC_DSP_TYPE_HI3518EV2: {
#if !defined(__LIBPIZIOT_OS_PLATFORM_MFC__) && !defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#if defined(ENABLE_HI3518E_V2)
                    VI_WRITE_BUFF_FUNC_V2_t lpCallBackFunc = stream_in_main_write_data_to_buffer;
                    if (SAMPLE_COMM_VENC_GetVencStreamProc(lpstream_in_info, stream_in_index, lpstream_in_info->source_list[stream_in_index].venc_index, lpCallBackFunc) != HI_SUCCESS) {
                        break;
                    }
#endif //defined(ENABLE_HI3518E_V2)
#endif //!defined(__LIBPIZIOT_OS_PLATFORM_MFC__) && !defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
                }
                                              break;
                default: {

                }
                         break;
                }
            }
        } while (1);
    }

#if defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2)
    if (lpthread_info->m_sample_venc_classic_init_flag != 0) {
        SAMPLE_COMM_VENC_GetVencStreamProc_Exit(lpstream_in_info);
        SAMPLE_VENC_CLASSIC_EXIT(lpstream_in_info);
    }
    lpthread_info->m_sample_venc_classic_init_flag = 0;
#else
    lpthread_info->m_sample_venc_classic_init_flag = 0;
#endif //defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2)

    //libpiziot_os_mutex_plock_lock(&(lpthread_info->instance_mutex));
    //{
    // //libpiziot_os_mutex_plock_lock(&(m_libpiziot_stream_in_source_list_main_mutex));
    // //{
    // //}
    // //libpiziot_os_mutex_plock_unlock(&(m_libpiziot_stream_in_source_list_main_mutex));
    //}
    //libpiziot_os_mutex_plock_unlock(&(lpthread_info->instance_mutex));

    //TRACEA("Video Encoder Channel SRC,get_DVR_frame end_routine ...\n");

    return (libpiziot_os_pthread_dword_t)1234567;
}

static libpiziot_os_type_func_result_e stream_in_main_open_thread_one(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    stream_in_main_thread_info_t *Alpthread_info = &(m_stream_in_main_thread_info);
    libpiziot_os_mutex_plock_lock(&(Alpthread_info->instance_mutex));
    do {
        if (Alpthread_info->m_sample_venc_classic_init_flag == 2) {
            break;
        }
        if ((libpiziot_os_pthread_get_status(&(Alpthread_info->thread_instance)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED)) {
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
            break;
        }
        if ((libpiziot_os_pthread_get_status(&(Alpthread_info->thread_instance)) == LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED)) {
            if (libpiziot_os_pthread_create(&(Alpthread_info->thread_instance), stream_in_main_thread_instance_routine_get_frame, LIBPIZIOT_OS_PTHREAD_STACK_SIZE_AUTO, "stream_in") != 0) {
                TRACEA("%s:CreateUserPthread,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                break;
            }
            TRACEB("%s:Thread running ...\n", LIBPIZIOT_OS__FUNCTION__);
        }
        else {
            TRACEA("%s:already running,ignore start thread ...\n", LIBPIZIOT_OS__FUNCTION__);
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    libpiziot_os_mutex_plock_unlock(&(Alpthread_info->instance_mutex));
    return rval;
}

static libpiziot_os_type_func_result_e stream_in_main_close_thread_one(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    stream_in_main_thread_info_t *Alpthread_info = &(m_stream_in_main_thread_info);
    if (Alpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    {
        int32_t msg = 0;
        if (libpiziot_os_pthread_get_status(&(Alpthread_info->thread_instance)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED) msg = 1;
        //if (msg == 1)
        //{
        // TRACEB("%s:libpiziot_os_pthread_release(...)\n", LIBPIZIOT_OS__FUNCTION__);
        // LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        //}
        libpiziot_os_pthread_release(&(Alpthread_info->thread_instance));
        if (msg == 1) {
            TRACEB("%s:WaitUserPthread ...\n", LIBPIZIOT_OS__FUNCTION__);
            LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        }
        libpiziot_os_pthread_join(&(Alpthread_info->thread_instance));
        if (msg == 1) {
            TRACEB("%s:THREAD_HANDLE_CLOSED ...\n", LIBPIZIOT_OS__FUNCTION__);
            LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    }
    return rval;
}

static void stream_in_main_deinit_fifo_buffer(libpiziot_stream_in_source_list_t *Alpstream_in_info) {
    uint32_t stream_in_index;
    for (stream_in_index = 0; stream_in_index < Alpstream_in_info->stream_in_total; stream_in_index++) {
        {
            libpiziot_os_fifo_buffer_info_t *lp_fifo_buffer_video = &(Alpstream_in_info->source_list[stream_in_index].m_fifo_buffer_info);
            if (libpiziot_os_fifo_buffer_finalize(lp_fifo_buffer_video, LIBPIZIOT_OS__FUNCTION__, __LINE__) != 0) {
            }
            libpiziot_os_fifo_free_mutex(lp_fifo_buffer_video, LIBPIZIOT_OS__FUNCTION__, __LINE__);
        }

        {
            if (Alpstream_in_info->source_list[stream_in_index].lpsend_buff != 0) {
                free(Alpstream_in_info->source_list[stream_in_index].lpsend_buff);
                Alpstream_in_info->source_list[stream_in_index].lpsend_buff = 0;
            }
        }
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#if defined(ENABLE_SIMULATE_VENC)
        {
            stream_in_emulator_close_test_file(stream_in_index);
        }
#endif //defined(ENABLE_SIMULATE_VENC)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
    }
}

static libpiziot_os_type_func_result_e stream_in_main_init_fifo_buffer(libpiziot_stream_in_source_list_t *Alpstream_in_info) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    uint32_t stream_in_index;
    for (stream_in_index = 0; stream_in_index < Alpstream_in_info->stream_in_total; stream_in_index++) {
        int32_t buffer_size = 0;
        switch (Alpstream_in_info->source_list[stream_in_index].stream_in_enSize) {
        case STREAM_IN_PIC_HD720: {
            buffer_size = (int32_t)(1280 * 720 / 4.9);
            //TRACEA("Video[720P] buffer size=%d\n",buffer_size);
        }
                                  break;
        case STREAM_IN_PIC_WVGA: {
            buffer_size = (int32_t)(854 * 480 / 3.9);
            //TRACEA("Video[VGA] buffer size=%d\n",buffer_size);
        }
                                 break;
        case STREAM_IN_PIC_VGA: {
            buffer_size = (int32_t)(640 * 480 / 2.6);
            //TRACEA("Video[VGA] buffer size=%d\n",buffer_size);
        }
                                break;
        case STREAM_IN_PIC_QVGA: {
            buffer_size = (int32_t)(320 * 240 / 2.5);
            //TRACEA("Video[QVGA] buffer size=%d\n",buffer_size);
        }
                                 break;
        default: {
        }
                 break;
        }

        {
            Alpstream_in_info->source_list[stream_in_index].send_buff_size = buffer_size;
            if (buffer_size != 0) {
                Alpstream_in_info->source_list[stream_in_index].lpsend_buff = (char *)malloc(buffer_size);
                if (Alpstream_in_info->source_list[stream_in_index].lpsend_buff == 0) {
                    TRACEA("%s,malloc lpsend_buff = 0,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                    rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
                    break;
                }
            }
        }

        {
            libpiziot_os_fifo_buffer_info_t *lp_fifo_buffer_video = &(Alpstream_in_info->source_list[stream_in_index].m_fifo_buffer_info);
            memset_addr(libpiziot_os_fifo_buffer_info_t, lp_fifo_buffer_video, 0, sizeof(libpiziot_os_fifo_buffer_info_t));
            libpiziot_os_fifo_mutex_init(lp_fifo_buffer_video, LIBPIZIOT_OS__FUNCTION__, __LINE__);
            if (libpiziot_os_fifo_buffer_initialize(lp_fifo_buffer_video, 0, buffer_size, LIBPIZIOT_OS__FUNCTION__, __LINE__) != 0) {
                rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
                break;
            }
        }
    }
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        stream_in_main_deinit_fifo_buffer(Alpstream_in_info);
    }
    return rval;
}

#if defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2)
#else
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#if defined(ENABLE_SIMULATE_VENC)
static void sample_venc_add_emulator_one_channel(libpiziot_stream_in_source_list_t* Alpstream_in_info, uint32_t *Alpstream_in_index, libpiziot_stream_in_payload_type_e Astream_in_payload_type, stream_in_pic_size_e Astream_in_pic_size)
{
    Alpstream_in_info->source_list[(*Alpstream_in_index)].venc_dsp_type = VENC_DSP_TYPE_EMULATOR;
    Alpstream_in_info->source_list[(*Alpstream_in_index)].venc_index = (*Alpstream_in_index);
    Alpstream_in_info->source_list[(*Alpstream_in_index)].stream_in_enPayLoad = Astream_in_payload_type;
    Alpstream_in_info->source_list[(*Alpstream_in_index)].stream_in_enSize = Astream_in_pic_size;
    (*Alpstream_in_index)++;
}

static void sample_venc_add_emulator_channels(libpiziot_stream_in_source_list_t* Alpstream_in_info)
{
    uint32_t stream_in_index = Alpstream_in_info->stream_in_total;
    sample_venc_add_emulator_one_channel(Alpstream_in_info, &stream_in_index, STREAM_LIBPIZIOT_IN_PT_H264, STREAM_IN_PIC_HD720);
    sample_venc_add_emulator_one_channel(Alpstream_in_info, &stream_in_index, STREAM_LIBPIZIOT_IN_PT_H264, STREAM_IN_PIC_WVGA);
    sample_venc_add_emulator_one_channel(Alpstream_in_info, &stream_in_index, STREAM_LIBPIZIOT_IN_PT_H264, STREAM_IN_PIC_VGA);
    sample_venc_add_emulator_one_channel(Alpstream_in_info, &stream_in_index, STREAM_LIBPIZIOT_IN_PT_H264, STREAM_IN_PIC_QVGA);
    Alpstream_in_info->stream_in_total = stream_in_index;
}
#endif //defined(ENABLE_SIMULATE_VENC)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#endif //defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2)

static void stream_in_main_sample_venc_add_channel(libpiziot_stream_in_source_list_t *Alpstream_in_info) {
    //if(LIBPIZIOT_STREAM_IN_CHANNEL_MAX >= 4)
    //{
    // Alpstream_in_info->stream_in_total = LIBPIZIOT_STREAM_IN_CHANNEL_MAX - 4;
    //}

#if defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2)
    {
        SAMPLE_VENC_ADD_CHANNEL(Alpstream_in_info);
    }
#else
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#if defined(ENABLE_SIMULATE_VENC)
    {
        sample_venc_add_emulator_channels(Alpstream_in_info);
    }
#endif //defined(ENABLE_SIMULATE_VENC)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#endif //defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2)
}

static void stream_in_main_clean_var(void) {
    libpiziot_stream_in_source_list_t *lpstream_in_info = &(m_libpiziot_stream_in_source_list);
    stream_in_main_thread_info_t *lpthread_info = &(m_stream_in_main_thread_info);
    if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return;
    {
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#if defined(ENABLE_SIMULATE_VENC)
        {
            uint32_t stream_in_index;
            for (stream_in_index = 0; stream_in_index < LIBPIZIOT_STREAM_IN_CHANNEL_MAX; stream_in_index++) {
                stream_in_emulator_close_test_file(stream_in_index);
            }
        }
#endif //defined(ENABLE_SIMULATE_VENC)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
    }
    {
        stream_in_main_deinit_fifo_buffer(lpstream_in_info);
        if (libpiziot_os_pthread_finalize(&(lpthread_info->thread_instance)) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        }
        if (libpiziot_os_mutex_plock_free(&(lpthread_info->instance_mutex)) != 0) {
            TRACEA("mutex free &lpthread_info->instance_mutex,error !!\n");
        }
    }
}

static libpiziot_os_type_func_result_e stream_in_main_init_var(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        stream_in_main_thread_info_t *lpthread_info = &(m_stream_in_main_thread_info);
        memset_addr(stream_in_main_thread_info_t, lpthread_info, 0, sizeof(stream_in_main_thread_info_t));
        if (libpiziot_os_mutex_plock_init(&(lpthread_info->instance_mutex), NULL) != 0) {
            TRACEA("%s:mutex init &(lpthread_info->instance_mutex,error !!\n", LIBPIZIOT_OS__FUNCTION__);
            break;
        }
        {
            libpiziot_stream_in_source_list_t *lpstream_in_info = &(m_libpiziot_stream_in_source_list);
            uint32_t stream_in_index;
            memset_addr(libpiziot_stream_in_source_list_t, lpstream_in_info, 0, sizeof(m_libpiziot_stream_in_source_list));
            for (stream_in_index = 0; stream_in_index < LIBPIZIOT_STREAM_IN_CHANNEL_MAX; stream_in_index++) {
                lpstream_in_info->source_list[stream_in_index].stream_in_enSize = -1;
                lpstream_in_info->source_list[stream_in_index].venc_dsp_type = VENC_DSP_TYPE_UNKNOWN;
                lpstream_in_info->source_list[stream_in_index].venc_index = -1;
            }
            stream_in_main_sample_venc_add_channel(lpstream_in_info);
            if (stream_in_main_init_fifo_buffer(lpstream_in_info) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
        }
        {
            rval = libpiziot_os_pthread_initialize(&(lpthread_info->thread_instance), LIBPIZIOT_OS__FUNCTION__, __LINE__);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            lpthread_info->thread_instance.m_extra = &(m_stream_in_main_thread_info);
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
        stream_in_main_clean_var();
    }
    else {
        TRACEB("%s,ok.\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

void stream_in_main_start_thread(void) {
    stream_in_main_thread_info_t *lpthread_info = &(m_stream_in_main_thread_info);
    if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return;;
    do {
        if (stream_in_main_open_thread_one() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
    } while (0);
}

void stream_in_main_stop_thread(void) {
    stream_in_main_thread_info_t *lpthread_info = &(m_stream_in_main_thread_info);
    if (lpthread_info->instance_mutex.init != LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE) return;
    do {
        if (stream_in_main_close_thread_one() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    } while (0);
}

libpiziot_os_type_func_result_e stream_in_main_finalize(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#if defined(ENABLE_HI3518E_V1)
        if (SAMPLE_COMM_ISP_finalize() != 0) {}
#elif defined(ENABLE_HI3518E_V2)
        if (SAMPLE_COMM_ISP_finalize() != 0) {}
#endif
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
        stream_in_main_clean_var();
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

libpiziot_os_type_func_result_e stream_in_main_initialize(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
        if (stream_in_main_init_var() != 0) break;
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#if defined(ENABLE_HI3518E_V1)
        if (SAMPLE_COMM_ISP_initialize() != 0) break;
#elif defined(ENABLE_HI3518E_V2)
        if (SAMPLE_COMM_ISP_initialize() != 0) break;
#endif
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
        stream_in_main_finalize();
    }
    else {
        TRACEB("%s,ok.\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

#endif //defined(ENABLE_STREAM_IN)
