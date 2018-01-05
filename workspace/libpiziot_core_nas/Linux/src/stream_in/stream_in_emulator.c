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

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#elif defined(__ESP8266X__)
#else

#include <limits.h>

#endif

//Define Windows Library

//Define MENU_CONFIG_H Library
#include "../../include/menu_config.h"

#if defined(ENABLE_STREAM_IN)

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"

//Define this Header
#include "stream_in_emulator.h"

//Define Other Header
#include "stream_in_main.h"

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

#if defined(ENABLE_SIMULATE_VENC)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define H264_FILE_DIR "../../../../exe/datafile/"
#elif defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#define H264_FILE_DIR "../../datafile/"
#else
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

static char *stream_in_emulator_lpMem[LIBPIZIOT_STREAM_IN_CHANNEL_MAX];
static size_t stream_in_emulator_file_seek[LIBPIZIOT_STREAM_IN_CHANNEL_MAX];
static size_t stream_in_emulator_fileSize_ch[LIBPIZIOT_STREAM_IN_CHANNEL_MAX];
static size_t stream_in_emulator_read_bytes[LIBPIZIOT_STREAM_IN_CHANNEL_MAX];
static size_t stream_in_emulator_buffer_len[LIBPIZIOT_STREAM_IN_CHANNEL_MAX];
static size_t stream_in_emulator_offset[LIBPIZIOT_STREAM_IN_CHANNEL_MAX];
#define BS_DATA_BUFFER_SIZE (2048*1024)
static char stream_in_emulator_lpbs_data[LIBPIZIOT_STREAM_IN_CHANNEL_MAX][BS_DATA_BUFFER_SIZE];

#endif //defined(ENABLE_SIMULATE_VENC)

#if defined(ENABLE_SIMULATE_VENC)

static libpiziot_os_type_func_result_e stream_in_emulator_open_test_file(libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index, int32_t Avenc_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        FILE *fid_ch = 0;
        char enc_file_name[LIBPIZIOT_ICE_TYPE_PATH_MAX + 1] = { 0 };
        {
            char enc_res_name[50] = { 0 };
            int frame_rate = 0;
            char enc_quality_name[50] = { 0 };
            char enc_codec_name[50] = { 0 };
            switch (Alpstream_in_info->source_list[Astream_in_index].stream_in_enPayLoad) {
            case STREAM_LIBPIZIOT_IN_PT_H264: {
                switch (Alpstream_in_info->source_list[Astream_in_index].stream_in_enSize) {
                case STREAM_IN_PIC_HD720: {
                    sprintf(enc_res_name, "%s", "720P");
                    frame_rate = 30;
                    sprintf(enc_quality_name, "%s", "FQ");
                    sprintf(enc_codec_name, "%s", "h264");
                }
                                          break;
                case STREAM_IN_PIC_WVGA: {
                    sprintf(enc_res_name, "%s", "FWVGA");
                    frame_rate = 30;
                    sprintf(enc_quality_name, "%s", "FQ");
                    sprintf(enc_codec_name, "%s", "h264");
                }
                                         break;
                case STREAM_IN_PIC_VGA: {
                    sprintf(enc_res_name, "%s", "nHD");
                    frame_rate = 30;
                    sprintf(enc_quality_name, "%s", "FQ");
                    sprintf(enc_codec_name, "%s", "h264");
                }
                                        break;
                case STREAM_IN_PIC_QVGA: {
                    sprintf(enc_res_name, "%s", "QVGA");
                    frame_rate = 30;
                    sprintf(enc_quality_name, "%s", "FQ");
                    sprintf(enc_codec_name, "%s", "h264");
                }
                                         break;
                default: {
                    while (1) {
                        TRACEA("error !!\n");
                        usleep(1000000);
                    }
                }
                         break;
                }
            }
                                             break;
            default: {
                while (1) {
                    TRACEA("error !!\n");
                    usleep(1000000);
                }
            }
                     break;
            }
            sprintf(enc_file_name, "%stest_%s_%d_%s.%s", H264_FILE_DIR, enc_res_name, frame_rate, enc_quality_name, enc_codec_name);
        }
        fid_ch = fopen(enc_file_name, "rb");
        if (fid_ch == NULL) {
            TRACEA("%s not found,error !!\n", enc_file_name);
            usleep(1000000);
            break;
        }
        if (fseek(fid_ch, 0, SEEK_END) != 0) break;
        stream_in_emulator_fileSize_ch[Avenc_index] = ftell(fid_ch);
        if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
        stream_in_emulator_read_bytes[Avenc_index] = 0;
        stream_in_emulator_buffer_len[Avenc_index] = 0;
        {
            stream_in_emulator_lpMem[Avenc_index] = libpiziot_os_malloc(stream_in_emulator_fileSize_ch[Avenc_index]);
            if (stream_in_emulator_lpMem[Avenc_index] == 0) {
                break;
            }
            {
                size_t iReadSize = fread(stream_in_emulator_lpMem[Avenc_index], 1, stream_in_emulator_fileSize_ch[Avenc_index], fid_ch);
                if (iReadSize != stream_in_emulator_fileSize_ch[Avenc_index]) break;
                stream_in_emulator_file_seek[Avenc_index] = 0;
            }

        }
        if (fid_ch != 0) {
            if (fclose(fid_ch) != 0) {
                while (1) {
                    TRACEA("fclose(fid_ch0_0) error !! %s:%d\n", LIBPIZIOT_OS__FUNCTION__, __LINE__);
                    usleep(1000000);
                }
            }
            fid_ch = 0;
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

libpiziot_os_type_func_result_e stream_in_emulator_close_test_file(int32_t Avenc_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        if (stream_in_emulator_lpMem[Avenc_index] != 0) {
            libpiziot_os_free(stream_in_emulator_lpMem[Avenc_index]);
            stream_in_emulator_lpMem[Avenc_index] = 0;
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

static uint32_t stream_in_emulator_find_next_start_code(unsigned char *Buf, int bufpos, size_t bufsize, size_t *Alpnext_start_pos) {
    size_t tSTART = bufpos;
    uint32_t find = 0;

    while (tSTART < bufsize - 4) {
        if ((Buf[tSTART + 0] != 0) || (Buf[tSTART + 1] != 0) || (Buf[tSTART + 2] != 0) || (Buf[tSTART + 3] != 1)) {
            tSTART++;
            continue;
        }
        //if(Buf[tSTART + 4] == 0x65 || Buf[tSTART + 4] == 0x61)
        {
            *Alpnext_start_pos = tSTART;
            find = 1;
            break;
        }
        //tSTART++;
    }
    return find;
}

#if defined(ENABLE_HI3518E_V1)

static libpiziot_os_type_func_result_e stream_in_emulator_read_test_h264(VENC_STREAM_V1_S *pstStream, int32_t Avenc_index)
#elif defined(ENABLE_HI3518E_V2)
static libpiziot_os_type_func_result_e stream_in_emulator_read_test_h264(VENC_STREAM_V2_S *pstStream, int32_t Avenc_index)
#else

static libpiziot_os_type_func_result_e stream_in_emulator_read_test_h264(VENC_STREAM_V_S *pstStream, int32_t Avenc_index)
#endif
{
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        uint32_t u32PackCount_Max = pstStream->u32PackCount;
        uint32_t i;
        size_t readsize;

        //gettimeofday(&(Adata->bs.timestamp),&tz);
#if defined(ENABLE_HI3518E_V1)
        for (i = 0; i < pstStream->u32PackCount; i++) {
            pstStream->pstPack[i].u32Len[0] = 0;
            pstStream->pstPack[i].u32Len[1] = 0;
        }
#elif defined(ENABLE_HI3518E_V2)
        for (i = 0; i < pstStream->u32PackCount; i++)
        {
            pstStream->pstPack[i].u32Offset = 0;
            pstStream->pstPack[i].u32Len = 0;
        }
#else
        for (i = 0; i < pstStream->u32PackCount; i++) {
            pstStream->pstPack[i].u32Offset = 0;
            pstStream->pstPack[i].u32Len = 0;
        }
#endif //defined(ENABLE_HI3518E_V2)

        //Adata->bs.length = 0;
        //Adata->bs.is_keyframe = 0;
        if (stream_in_emulator_lpMem[Avenc_index] == 0) {
            break;
        }

        pstStream->u32PackCount = 0;
        stream_in_emulator_offset[Avenc_index] = 0;
        do {
            if (pstStream->u32PackCount >= u32PackCount_Max) {
                break;
            }

            {
                // struct timezone tz;
                size_t remain = stream_in_emulator_fileSize_ch[Avenc_index] - stream_in_emulator_read_bytes[Avenc_index];
                readsize = 256 * 1024;
                if (readsize > remain) {
                    readsize = remain;
                }
            }

            if (stream_in_emulator_buffer_len[Avenc_index] + readsize <= BS_DATA_BUFFER_SIZE) {
                if (stream_in_emulator_read_bytes[Avenc_index] == stream_in_emulator_fileSize_ch[Avenc_index]) {
                    stream_in_emulator_file_seek[Avenc_index] = 0;
                    stream_in_emulator_read_bytes[Avenc_index] = 0;
                }
                else if (stream_in_emulator_read_bytes[Avenc_index] > stream_in_emulator_fileSize_ch[Avenc_index]) {
                    TRACEA("data error\n");
                    break;
                }
                if (readsize > 0) {
                    memcpy(stream_in_emulator_lpbs_data[Avenc_index] + stream_in_emulator_buffer_len[Avenc_index], stream_in_emulator_lpMem[Avenc_index] + stream_in_emulator_file_seek[Avenc_index], readsize);
                    stream_in_emulator_file_seek[Avenc_index] += readsize;
                    stream_in_emulator_read_bytes[Avenc_index] += readsize;
                    stream_in_emulator_buffer_len[Avenc_index] += readsize;
                }
            }
            if (stream_in_emulator_buffer_len[Avenc_index] > 0) {
                uint32_t finresult;
                size_t nal_len = 0;
                finresult = stream_in_emulator_find_next_start_code((unsigned char *)stream_in_emulator_lpbs_data[Avenc_index] + stream_in_emulator_offset[Avenc_index], 1, stream_in_emulator_buffer_len[Avenc_index], &nal_len);
                if (finresult != 1) {
                    TRACEA("stream_in_emulator_find_next_start_code not found,error !!\n");
                    break;
                }
                {
#if defined(ENABLE_HI3518E_V1)
                    pstStream->pstPack[pstStream->u32PackCount].pu8Addr[0] = (HI_U8 *) &(stream_in_emulator_lpbs_data[Avenc_index][stream_in_emulator_offset[Avenc_index]]);
                    pstStream->pstPack[pstStream->u32PackCount].u32Len[0] = nal_len;
                    pstStream->pstPack[pstStream->u32PackCount].pu8Addr[1] = NULL;
                    pstStream->pstPack[pstStream->u32PackCount].u32Len[1] = 0;
                    //TRACEA("len=(%d)",pstStream->pstPack[pstStream->u32PackCount].u32Len[0]);
#elif defined(ENABLE_HI3518E_V2)
                    pstStream->pstPack[pstStream->u32PackCount].pu8Addr = (HI_U8*)&(stream_in_emulator_lpbs_data[Avenc_index][stream_in_emulator_offset[Avenc_index]]);
                    pstStream->pstPack[pstStream->u32PackCount].u32Offset = 0;
                    pstStream->pstPack[pstStream->u32PackCount].u32Len = (HI_U32)nal_len;
                    //TRACEA("len=(%d)",pstStream->pstPack[pstStream->u32PackCount].u32Len);
#else
                    pstStream->pstPack[pstStream->u32PackCount].pu8Addr = (uint8_t *) &(stream_in_emulator_lpbs_data[Avenc_index][stream_in_emulator_offset[Avenc_index]]);
                    pstStream->pstPack[pstStream->u32PackCount].u32Offset = 0;
                    pstStream->pstPack[pstStream->u32PackCount].u32Len = (uint32_t)nal_len;
                    //TRACEA("len=(%d)",pstStream->pstPack[pstStream->u32PackCount].u32Len);
#endif //defined(ENABLE_HI3518E_V2)

                    pstStream->u32PackCount++;
                    stream_in_emulator_offset[Avenc_index] += nal_len;

                    {
                        //int32_t j;
                        //libpiziot_os_mutex_plock_lock(&libpiziot_os_debug_mx);
                        //{
                        // for(j = 0;j < pstStream->pstPack[pstStream->u32PackCount - 1].u32Len;j++)
                        // {
                        // libpiziot_os_debug_thread_non_safe_printf("0x%02x,",pstStream->pstPack[pstStream->u32PackCount - 1].pu8Addr[j]);
                        // if(j >= 10) break;
                        // }
                        // libpiziot_os_debug_thread_non_safe_printf("\n");
                        //}
                        //libpiziot_os_mutex_plock_unlock(&libpiziot_os_debug_mx);
                        {
#if defined(ENABLE_HI3518E_V1)
                            HI_U8 frame_type = (pstStream->pstPack[pstStream->u32PackCount - 1].pu8Addr[0][4]) & 0x1F;
#elif defined(ENABLE_HI3518E_V2)
                            HI_U8 frame_type = (pstStream->pstPack[pstStream->u32PackCount - 1].pu8Addr[4]) & 0x1F;
#else
                            uint8_t frame_type = (pstStream->pstPack[pstStream->u32PackCount - 1].pu8Addr[4]) & 0x1F;
#endif //defined(ENABLE_HI3518E_V2)

                            if (frame_type == NALU_TYPE_IDR) {
                                break;
                            }
                            if (frame_type == NALU_TYPE_SLICE) {
                                break;
                            }
                        }
                    }
                }

#if 0
                {
                    unsigned char* lpNalType = stream_in_emulator_lpbs_data + 4;
                    char nal_unit_type = (lpNalType[0]) & 0x1f;
                    //char nal_reference_idc = (lpNalType[0]>>5) & 3;
                    //char forbidden_bit = (lpNalType[0]>>7) & 1;

                    switch (nal_unit_type)
                    {
                    case NALU_TYPE_SPS:
                        Adata->bs.is_keyframe = 1;
                        break;
                    case NALU_TYPE_PPS:
                        Adata->bs.is_keyframe = 1;
                        break;
                    case NALU_TYPE_IDR:
                        Adata->bs.is_keyframe = 1;
                        break;
                    }

                    //switch(nal_unit_type)
                    //{
                    //case NALU_TYPE_SLICE: TRACEA("SLICE"); break;
                    ////case NALU_TYPE_DPA: TRACEA("DPA "); break;
                    ////case NALU_TYPE_DPB: TRACEA("DPB "); break;
                    ////case NALU_TYPE_DPC: TRACEA("DPC "); break;
                    //case NALU_TYPE_IDR: TRACEA("IDR "); break;
                    ////case NALU_TYPE_SEI: TRACEA("SEI "); break;
                    //case NALU_TYPE_SPS: TRACEA("SPS "); break;
                    //case NALU_TYPE_PPS: TRACEA("PPS "); break;
                    ////case NALU_TYPE_AUD: TRACEA("AUD "); break;
                    ////case NALU_TYPE_EOSEQ: TRACEA("EOSEQ"); break;
                    ////case NALU_TYPE_EOSTREAM: TRACEA("EOSTREAM"); break;
                    ////case NALU_TYPE_FILL : TRACEA("FILL"); break;
                    //default:
                    // TRACEA("Unknown(%d)\n",nal_unit_type);
                    // break;
                    //}
                    //TRACEA(" %02x %02x %02x %02x (%d),(fobidden=%d),(nal_reference_idc=%d)"
                    // ,stream_in_emulator_lpbs_data[Alpstream_in_info->nal_offset[Avenc_index]]
                    //,stream_in_emulator_lpbs_data[Alpstream_in_info->nal_offset[Avenc_index] + 1]
                    //,stream_in_emulator_lpbs_data[Alpstream_in_info->nal_offset[Avenc_index] + 2]
                    //,stream_in_emulator_lpbs_data[Alpstream_in_info->nal_offset[Avenc_index] + 3]
                    //,nal_BUFSIZE,forbidden_bit,nal_reference_idc);

                    //TRACEA(" \n");
                }

                Adata->bs.length = nal_BUFSIZE;
                memcpy(user_mmap_buffer_fd[Aenc_data->ch_num] + Adata->bs.offset + Asub_buff_offset, stream_in_emulator_lpbs_data, Adata->bs.length);
                Alpstream_in_info->nal_offset[Avenc_index] = Alpstream_in_info->nal_offset_next[Avenc_index];
#endif
            }
        } while (1);

        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        stream_in_emulator_close_test_file(Avenc_index);
    }
    return rval;
}

#if 0
#if defined(ENABLE_HI3518E_V1)
static libpiziot_os_type_func_result_e stream_in_emulator_read_test_mjpeg(VENC_STREAM_V1_S* pstStream, int32_t Avenc_index)
#elif defined(ENABLE_HI3518E_V2)
static libpiziot_os_type_func_result_e stream_in_emulator_read_test_mjpeg(VENC_STREAM_V2_S *pstStream, int32_t Avenc_index)
#else
static libpiziot_os_type_func_result_e stream_in_emulator_read_test_mjpeg(VENC_STREAM_V_S *pstStream, int32_t Avenc_index)
#endif //defined(ENABLE_HI3518E_V2)
{
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
#if 0
    struct timezone tz;
    ReproduceBitStream *repd;
    static int content_type_len = 0;
    static int content_length_len = 0;
#define CONTENT_TYPE "Content-Type: image/jpeg\r\n"
#define CONTENT_LENGTH "Content-Length: "

    if (content_type_len == 0) content_type_len = strlen(CONTENT_TYPE);
    if (content_length_len == 0) content_length_len = strlen(CONTENT_LENGTH);

    repd = &(Aenc_data->repd[Astream]);
    do
    {
        int remain = stream_in_emulator_fileSize_ch[Avenc_index] - stream_in_emulator_read_bytes[Avenc_index];

        if (repd->enc_type != ENC_TYPE_MJPEG) break;
        gettimeofday(&(Adata->bs.timestamp), &tz);
        Adata->bs.length = 0;
        Adata->bs.is_keyframe = 0;
        if (stream_in_emulator_lpMem[Avenc_index] == 0)
        {
            break;
        }
        if (remain <= content_type_len)
        {
            if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
            stream_in_emulator_read_bytes[Avenc_index] = 0;
            continue;
        }
        if (fseek(fid_ch, stream_in_emulator_read_bytes[Avenc_index], SEEK_SET) != 0) break;
        iReadSize = fread(stream_in_emulator_lpbs_data, 1, content_type_len, fid_ch);
        if (iReadSize != content_type_len)
        {
            TRACEA("data error\n");
            if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
            stream_in_emulator_read_bytes[Avenc_index] = 0;
        }
        remain -= content_type_len;
        if (strncmp(stream_in_emulator_lpbs_data, CONTENT_TYPE, content_type_len) != 0)
        {
            if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
            stream_in_emulator_read_bytes[Avenc_index] = 0;
            continue;
        }

        if (remain <= content_length_len)
        {
            if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
            stream_in_emulator_read_bytes[Avenc_index] = 0;
            continue;
        }
        iReadSize = fread(stream_in_emulator_lpbs_data, 1, content_length_len, fid_ch);
        if (iReadSize != content_length_len)
        {
            TRACEA("data error\n");
            if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
            stream_in_emulator_read_bytes[Avenc_index] = 0;
            break;
        }
        remain -= content_length_len;
        if (strncmp(stream_in_emulator_lpbs_data, CONTENT_LENGTH, content_length_len) != 0)
        {
            if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
            stream_in_emulator_read_bytes[Avenc_index] = 0;
            continue;
        }
        {
            int content_offset = stream_in_emulator_fileSize_ch[Avenc_index] - remain;
            int read_size = remain;
            if (read_size > 50) read_size = 50;
            iReadSize = fread(stream_in_emulator_lpbs_data, 1, read_size, fid_ch);
            if (iReadSize != 50)
            {
                TRACEA("data error\n");
                if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
                stream_in_emulator_read_bytes[Avenc_index] = 0;
                break;
            }
            {
                int i;
                unsigned char* Buf = stream_in_emulator_lpbs_data;
                int content_size = 0;
                for (i = 0; i < read_size; i++)
                {
                    if (Buf[i] == '\r' && Buf[i + 1] == '\n')
                    {
                        Buf[i] = 0;
                        content_size = atoi(Buf);
                        if (content_size > remain)
                        {
                            content_size = 0;
                            break;
                        }
                        content_offset += 2;
                        remain -= 2;
                        break;
                    }
                    content_offset++;
                    remain--;
                }
                if (content_size == 0)
                {
                    if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
                    stream_in_emulator_read_bytes[Avenc_index] = 0;
                    continue;
                }
                if (content_size > BS_DATA_BUFFER_SIZE)
                {
                    if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
                    stream_in_emulator_read_bytes[Avenc_index] = 0;
                    continue;
                }
                if (fseek(fid_ch, content_offset, SEEK_SET) != 0)
                {
                    if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
                    stream_in_emulator_read_bytes[Avenc_index] = 0;
                    break;
                }
                iReadSize = fread(stream_in_emulator_lpbs_data, 1, content_size, fid_ch);
                if (iReadSize != content_size)
                {
                    TRACEA("data error\n");
                    if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
                    stream_in_emulator_read_bytes[Avenc_index] = 0;
                    break;
                }
                Adata->bs.length = content_size;
                Adata->bs.is_keyframe = 1;
                memcpy(user_mmap_buffer_fd[Aenc_data->ch_num] + Adata->bs.offset + Asub_buff_offset, stream_in_emulator_lpbs_data, Adata->bs.length);
                remain -= content_size;
                stream_in_emulator_read_bytes[Avenc_index] = stream_in_emulator_fileSize_ch[Avenc_index] - remain;
                if (remain == 0)
                {
                    if (fseek(fid_ch, 0, SEEK_SET) != 0) break;
                    stream_in_emulator_read_bytes[Avenc_index] = 0;
                }
            }
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
        break;
    } while (1);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS)
    {
        stream_in_emulator_close_test_file(Avenc_index);
    }
#endif
    return rval;
}
#endif //0

#if defined(ENABLE_HI3518E_V1)

libpiziot_os_type_func_result_e stream_in_emulator_GetH264DataFromEmulator(VENC_STREAM_V1_S *pstStream, libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index, int32_t Avenc_index)
#elif defined(ENABLE_HI3518E_V2)
libpiziot_os_type_func_result_e stream_in_emulator_GetH264DataFromEmulator(VENC_STREAM_V2_S *pstStream, libpiziot_stream_in_source_list_t* Alpstream_in_info, uint32_t Astream_in_index, int32_t Avenc_index)
#else

libpiziot_os_type_func_result_e stream_in_emulator_GetH264DataFromEmulator(VENC_STREAM_V_S *pstStream, libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index, int32_t Avenc_index)
#endif //defined(ENABLE_HI3518E_V2)
{
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        if (stream_in_emulator_lpMem[Avenc_index] == 0) {
            if (stream_in_emulator_open_test_file(Alpstream_in_info, Astream_in_index, Avenc_index) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
        }
        switch (Alpstream_in_info->source_list[Astream_in_index].stream_in_enPayLoad) {
        case STREAM_LIBPIZIOT_IN_PT_H264: {
            rval = stream_in_emulator_read_test_h264(pstStream, Avenc_index);
        }
                                         break;
#if 0
        case STREAM_LIBPIZIOT_IN_PT_MJPEG:
        {
            rval = stream_in_emulator_read_test_mjpeg(pstStream, Avenc_index);
        }
        break;
#endif //0
        default: {
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
        }
                 break;
        }
    } while (0);
    return rval;
}

#if defined(ENABLE_HI3518E_V1)

void stream_in_emulator_NextH264DataFromEmulator(int32_t Avenc_index)
#elif defined(ENABLE_HI3518E_V2)
void stream_in_emulator_NextH264DataFromEmulator(int32_t Avenc_index)
#else

void stream_in_emulator_NextH264DataFromEmulator(int32_t Avenc_index)
#endif //defined(ENABLE_HI3518E_V2)
{
    if (stream_in_emulator_offset[Avenc_index] > 0) {
        size_t remain_len = stream_in_emulator_buffer_len[Avenc_index] - stream_in_emulator_offset[Avenc_index];
        memcpy(&(stream_in_emulator_lpbs_data[Avenc_index][0]), &(stream_in_emulator_lpbs_data[Avenc_index][stream_in_emulator_offset[Avenc_index]]), remain_len);
        stream_in_emulator_buffer_len[Avenc_index] -= stream_in_emulator_offset[Avenc_index];
        usleep(8000);
    }
}

#endif //defined(ENABLE_SIMULATE_VENC)

#endif //defined(ENABLE_STREAM_IN)
