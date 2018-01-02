#ifndef __DEF_LIBPIZIOT_STREAM_IN_H__
#define __DEF_LIBPIZIOT_STREAM_IN_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "libpiziot_os/def_libpiziot_os_type.h"
#include "libpiziot_os/def_libpiziot_os_fifo.h"

#if !defined(__HI_COMMON_H__)
typedef enum {
    PT_H264 = 96,
    PT_MJPEG = 1002,
} PAYLOAD_TYPE_E;
#endif //!defined(__HI_COMMON_H__)

#if !defined(__HI_COMM_VIDEO_H__)
typedef enum hiPIC_SIZE_E {
    PIC_960H = 5,
    PIC_QVGA = 6, /* 320 * 240 */
    PIC_VGA = 7, /* 640 * 480 */
    PIC_WVGA = 12, /* 854 * 480 */
    PIC_HD720 = 16, /* 1280 * 720 */
    PIC_HD1080 = 17, /* 1920 * 1080 */
} PIC_SIZE_E;
#endif //!defined(__HI_COMM_VIDEO_H__)

typedef enum venc_dsp_type_enum {
    VENC_DSP_TYPE_UNKNOWN,
    VENC_DSP_TYPE_EMULATOR,
    VENC_DSP_TYPE_HI3518E,
    VENC_DSP_TYPE_HI3518EV2,
} venc_dsp_type_e;

typedef enum libpiziot_stream_in_payload_type_enum {
    STREAM_LIBPIZIOT_IN_PT_UNKNOWN,
    STREAM_LIBPIZIOT_IN_PT_H264,
    STREAM_LIBPIZIOT_IN_PT_MJPEG,
} libpiziot_stream_in_payload_type_e;

typedef enum stream_in_pic_size_enum {
    STREAM_IN_PIC_UNKNOWN,
    STREAM_IN_PIC_960H,
    STREAM_IN_PIC_QVGA, /* 320 * 240 */
    STREAM_IN_PIC_VGA, /* 640 * 480 */
    STREAM_IN_PIC_WVGA, /* 854 * 480 */
    STREAM_IN_PIC_HD720, /* 1280 * 720 */
    STREAM_IN_PIC_HD1080, /* 1920 * 1080 */
} stream_in_pic_size_e;

#define LIBPIZIOT_STREAM_IN_CHANNEL_MAX 10

typedef struct libpiziot_stream_in_source_s {
    venc_dsp_type_e venc_dsp_type;
    int venc_index;
    libpiziot_stream_in_payload_type_e stream_in_enPayLoad;
    stream_in_pic_size_e stream_in_enSize;
    libpiziot_os_fifo_buffer_info_t m_fifo_buffer_info;
    int32_t send_buff_size;
    char *lpsend_buff;
    //FILE *pFile;
    //char aszFileName[64];
} libpiziot_stream_in_source_t;

typedef struct libpiziot_stream_in_source_list_s {
    uint32_t stream_in_total;
    //HI_S32 maxfd;
    libpiziot_stream_in_source_t source_list[LIBPIZIOT_STREAM_IN_CHANNEL_MAX];
} libpiziot_stream_in_source_list_t;
extern libpiziot_stream_in_source_list_t m_libpiziot_stream_in_source_list;

typedef struct hiVENC_PACK_V_S {
    //HI_U32 u32PhyAddr; /*the physics address of stream*/
    uint8_t *pu8Addr; /*the virtual address of stream*/
    uint32_t u32Len; /*the length of stream*/

    //HI_U64 u64PTS; /*PTS*/
    //HI_BOOL bFrameEnd; /*frame end��*/

    //VENC_DATA_TYPE_U DataType; /*the type of stream*/
    uint32_t u32Offset;

    //HI_U32 u32DataNum;
    //VENC_PACK_INFO_S stPackInfo[8];
} VENC_PACK_V_S;

typedef struct hiVENC_STREAM_V_S {
    VENC_PACK_V_S *pstPack; /*stream pack attribute*/
    uint32_t u32PackCount;/*the pack number of one frame stream*/
    //HI_U32 u32Seq; /*the list number of stream*/

    //union
    //{
    // VENC_STREAM_INFO_H264_V2_S stH264Info; /*the stream info of h264*/
    // VENC_STREAM_INFO_JPEG_S stJpegInfo; /*the stream info of jpeg*/
    // VENC_STREAM_INFO_MPEG4_S stMpeg4Info; /*the stream info of mpeg4*/
    // VENC_STREAM_INFO_H265_S stH265Info; /*the stream info of h265*/
    //};
} VENC_STREAM_V_S;

typedef void (*libpiziot_stream_in_vi_write_buff_p)(VENC_STREAM_V_S *pstStream, libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index);

#endif //__DEF_LIBPIZIOT_STREAM_IN_H__
