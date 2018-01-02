#ifndef __DEF_LIBPIZBSP_HI3518_TYPE_H__
#define __DEF_LIBPIZBSP_HI3518_TYPE_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "../libpiziot_os/def_libpiziot_os_type.h"

#if defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2)

#include "../libpiziot_os/def_libpiziot_os_fifo.h"
#include "../def_libpiziot_stream_in.h"

#if !defined(__HI_TYPE_H__)
typedef unsigned char HI_U8;
typedef unsigned short HI_U16;
typedef unsigned int HI_U32;
typedef signed char HI_S8;
typedef short HI_S16;
typedef int HI_S32;
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
typedef __int64 HI_U64;
typedef __int64 HI_S64;
#else
typedef unsigned long long HI_U64;
typedef long long HI_S64;
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
typedef char HI_CHAR;
#define HI_VOID void

typedef enum {
    HI_FALSE = 0,
    HI_TRUE = 1,
}HI_BOOL;

#ifndef NULL
#define NULL 0L
#endif

#define HI_NULL 0L
#define HI_SUCCESS 0
#define HI_FAILURE (-1)

#endif //!defined(__HI_TYPE_H__)

#if defined(ENABLE_HI3518E_V1)
typedef enum sample_vi_mode_v1_e
{
    APTINA_AR0130_DC_720P_30FPS = 0,
    APTINA_9M034_DC_720P_30FPS,
    SONY_ICX692_DC_720P_30FPS,
    SONY_IMX104_DC_720P_30FPS,
    SONY_IMX138_DC_720P_30FPS,
    SONY_IMX122_DC_1080P_30FPS,
    SONY_IMX236_DC_1080P_30FPS,
    OMNI_OV9712_DC_720P_30FPS,
    APTINA_MT9P006_DC_1080P_30FPS,
    OMNI_OV2710_DC_1080P_30FPS,
    SOI_H22_DC_720P_30FPS,
    HIMAX_1375_DC_720P_30FPS,
    APTINA_AR0330_DC_1080P_30FPS,
    PIXELPLUS_3100K_DC_720P_30FPS,
    SAMPLE_VI_MODE_1_D1,
}SAMPLE_VI_MODE_V1_E;
#endif //defined(ENABLE_HI3518E_V1)

#if defined(ENABLE_HI3518E_V2)
typedef enum sample_vi_mode_v2_e
{
    APTINA_AR0130_DC_720P_30FPS = 0,
    APTINA_9M034_DC_720P_30FPS,
    APTINA_AR0230_HISPI_1080P_30FPS,
    SONY_IMX122_DC_1080P_30FPS,
    SONY_IMX122_DC_720P_30FPS,
    SAMPLE_VI_MODE_1_D1,
    SAMPLE_VI_MODE_BT1120_720P,
    SAMPLE_VI_MODE_BT1120_1080P,
    SOI_H42_DC_720P_30FPS,
}SAMPLE_VI_MODE_V2_E;

typedef enum hiWDR_MODE_E
{
    WDR_MODE_NONE = 0,
    WDR_MODE_BUILT_IN,

    WDR_MODE_2To1_LINE,
    WDR_MODE_2To1_FRAME,
    WDR_MODE_2To1_FRAME_FULL_RATE,

    WDR_MODE_3To1_LINE,
    WDR_MODE_3To1_FRAME,
    WDR_MODE_3To1_FRAME_FULL_RATE,

    WDR_MODE_4To1_LINE,
    WDR_MODE_4To1_FRAME,
    WDR_MODE_4To1_FRAME_FULL_RATE,

    WDR_MODE_BUTT,
}WDR_MODE_E;
#endif //defined(ENABLE_HI3518E_V2)

typedef enum hiH264E_NALU_TYPE_E
{
    H264E_NALU_PSLICE = 1, /*PSLICE types*/
    H264E_NALU_ISLICE = 5, /*ISLICE types*/
    H264E_NALU_SEI = 6, /*SEI types*/
    H264E_NALU_SPS = 7, /*SPS types*/
    H264E_NALU_PPS = 8, /*PPS types*/
    H264E_NALU_IPSLICE = 9,
    H264E_NALU_BUTT
}H264E_NALU_TYPE_E;

typedef enum hiJPEGE_PACK_TYPE_E
{
    JPEGE_PACK_ECS = 5, /*ECS types*/
    JPEGE_PACK_APP = 6, /*APP types*/
    JPEGE_PACK_VDO = 7, /*VDO types*/
    JPEGE_PACK_PIC = 8, /*PIC types*/
    JPEGE_PACK_BUTT
}JPEGE_PACK_TYPE_E;

typedef enum hiMPEG4E_PACK_TYPE_E
{
    MPEG4E_PACK_VOP_P = 1, /*P VOP packet types*/
    MPEG4E_PACK_VOP_I = 5, /*I VOP packet types*/
    MPEG4E_PACK_VOS = 6, /*VOS types*/
    MPEG4E_PACK_VO = 7, /*VO types*/
    MPEG4E_PACK_VOL = 8, /*VOL types*/
    MPEG4E_PACK_GVOP = 9 /*GROUP of vop types */
}MPEG4E_PACK_TYPE_E;

typedef enum hiH265E_NALU_TYPE_E
{
    H265E_NALU_PSLICE = 1, /*P SLICE types*/
    H265E_NALU_ISLICE = 19, /*I SLICE types*/
    H265E_NALU_VPS = 32, /*VPS types*/
    H265E_NALU_SPS = 33, /*SPS types*/
    H265E_NALU_PPS = 34, /*PPS types*/
    H265E_NALU_SEI = 39, /*SEI types*/

    H265E_NALU_BUTT
}H265E_NALU_TYPE_E;

typedef union hiVENC_DATA_TYPE_U
{
    H264E_NALU_TYPE_E enH264EType; /*H264E NALU types*/
    JPEGE_PACK_TYPE_E enJPEGEType; /*JPEGE pack types*/
    MPEG4E_PACK_TYPE_E enMPEG4EType; /*MPEG4E pack types*/
    H265E_NALU_TYPE_E enH265EType; /*H264E NALU types*/
}VENC_DATA_TYPE_U;

#if defined(ENABLE_HI3518E_V1)
typedef struct hiVENC_PACK_V1_S
{
    HI_U32 u32PhyAddr[2]; /*the physics address of stream*/
    HI_U8 *pu8Addr[2]; /*the virtual address of stream*/
    HI_U32 u32Len[2]; /*the length of stream*/

    HI_U64 u64PTS; /*PTS*/
    HI_BOOL bFieldEnd; /*field end��*/
    HI_BOOL bFrameEnd; /*frame end��*/

    VENC_DATA_TYPE_U DataType; /*the type of stream*/
    HI_U32 u32Offset;
}VENC_PACK_V1_S;
#endif //defined(ENABLE_HI3518E_V1)

#if defined(ENABLE_HI3518E_V2)
typedef struct hiVENC_PACK_INFO_S
{
    VENC_DATA_TYPE_U u32PackType;
    HI_U32 u32PackOffset;
    HI_U32 u32PackLength;
}VENC_PACK_INFO_S;

typedef struct hiVENC_PACK_V2_S
{
    HI_U32 u32PhyAddr; /*the physics address of stream*/
    HI_U8 *pu8Addr; /*the virtual address of stream*/
    HI_U32 u32Len; /*the length of stream*/

    HI_U64 u64PTS; /*PTS*/
    HI_BOOL bFrameEnd; /*frame end��*/

    VENC_DATA_TYPE_U DataType; /*the type of stream*/
    HI_U32 u32Offset;

    HI_U32 u32DataNum;
    VENC_PACK_INFO_S stPackInfo[8];
}VENC_PACK_V2_S;
#endif //defined(ENABLE_HI3518E_V2)

typedef enum hiH264E_REFSLICE_TYPE_E
{
    H264E_REFSLICE_FOR_1X = 1, /*Reference slice for H264E_REF_MODE_1X*/
    H264E_REFSLICE_FOR_2X = 2, /*Reference slice for H264E_REF_MODE_2X*/
    H264E_REFSLICE_FOR_4X = 5, /*Reference slice for H264E_REF_MODE_4X*/
    H264E_REFSLICE_FOR_BUTT /* slice not for reference*/
}H264E_REFSLICE_TYPE_E;

typedef enum hiH264E_REF_TYPE_E
{
    BASE_IDRSLICE = 0, //the Idr frame at Base layer
    BASE_PSLICE_REFBYBASE, //the P frame at Base layer, referenced by other frames at Base layer
    BASE_PSLICE_REFBYENHANCE, //the P frame at Base layer, referenced by other frames at Enhance layer
    ENHANCE_PSLICE_REFBYENHANCE, //the P frame at Enhance layer, referenced by other frames at Enhance layer
    ENHANCE_PSLICE_NOTFORREF, //the P frame at Enhance layer ,not referenced
    ENHANCE_PSLICE_BUTT
}H264E_REF_TYPE_E;

#if defined(ENABLE_HI3518E_V2)
typedef enum hiH264E_REF_TYPE_E H265E_REF_TYPE_E;
#endif //defined(ENABLE_HI3518E_V2)

#if defined(ENABLE_HI3518E_V1)
typedef struct hiVENC_STREAM_INFO_H264_V1_S
{
    HI_U32 u32PicBytesNum; /* the coded picture stream byte number */
    HI_U32 u32PSkipMbNum; /* the skip macroblock num */
    HI_U32 u32IpcmMbNum; /* the ipcm macroblock num */
    HI_U32 u32Inter16x8MbNum; /* the inter16x8 macroblock num */
    HI_U32 u32Inter16x16MbNum; /* the inter16x16 macroblock num */
    HI_U32 u32Inter8x16MbNum; /* the inter8x16 macroblock num */
    HI_U32 u32Inter8x8MbNum; /* the inter8x8 macroblock num */
    HI_U32 u32Intra16MbNum; /* the intra16x16 macroblock num */
    HI_U32 u32Intra8MbNum; /* the intra8x8 macroblock num */
    HI_U32 u32Intra4MbNum; /* the inter4x4 macroblock num */

    H264E_REFSLICE_TYPE_E enRefSliceType; /*the reference type of H264E slice*/
    H264E_REF_TYPE_E enRefType;
    HI_U32 u32UpdateAttrCnt;
}VENC_STREAM_INFO_H264_V1_S;
#endif //defined(ENABLE_HI3518E_V1)

#if defined(ENABLE_HI3518E_V2)
typedef struct hiVENC_STREAM_INFO_H264_V2_S
{
    HI_U32 u32PicBytesNum; /* the coded picture stream byte number */
    HI_U32 u32PSkipMbNum; /* the skip macroblock num */
    HI_U32 u32IpcmMbNum; /* the ipcm macroblock num */
    HI_U32 u32Inter16x8MbNum; /* the inter16x8 macroblock num */
    HI_U32 u32Inter16x16MbNum; /* the inter16x16 macroblock num */
    HI_U32 u32Inter8x16MbNum; /* the inter8x16 macroblock num */
    HI_U32 u32Inter8x8MbNum; /* the inter8x8 macroblock num */
    HI_U32 u32Intra16MbNum; /* the intra16x16 macroblock num */
    HI_U32 u32Intra8MbNum; /* the intra8x8 macroblock num */
    HI_U32 u32Intra4MbNum; /* the inter4x4 macroblock num */

    H264E_REFSLICE_TYPE_E enRefSliceType; /*the reference type of H264E slice*/
    H264E_REF_TYPE_E enRefType; /*Type of encoded frames in advanced frame skipping reference mode*/
    HI_U32 u32UpdateAttrCnt; /*Number of times that channel attributes or parameters (including RC parameters) are set*/
    HI_U32 u32StartQp; /*StartQP Value*/
}VENC_STREAM_INFO_H264_V2_S;
#endif //defined(ENABLE_HI3518E_V2)

#if defined(ENABLE_HI3518E_V2)
typedef struct hiVENC_STREAM_INFO_H265_S
{
    HI_U32 u32PicBytesNum; /* the coded picture stream byte number */
    HI_U32 u32Inter64x64CuNum; /* the num */
    HI_U32 u32Inter32x32CuNum;
    HI_U32 u32Inter16x16CuNum;
    HI_U32 u32Inter8x8CuNum;
    HI_U32 u32Intra32x32CuNum;
    HI_U32 u32Intra16x16CuNum;
    HI_U32 u32Intra8x8CuNum;
    HI_U32 u32Intra4x4CuNum;
    H265E_REF_TYPE_E enRefType; /*Type of encoded frames in advanced frame skipping reference mode*/
    HI_U32 u32UpdateAttrCnt; /*Number of times that channel attributes or parameters (including RC parameters) are set*/
    HI_U32 u32StartQp; /*StartQP Value*/
}VENC_STREAM_INFO_H265_S;
#endif //defined(ENABLE_HI3518E_V2)

typedef struct hiVENC_STREAM_INFO_JPEG_S
{
    HI_U32 u32PicBytesNum; /* the coded picture stream byte number */
    HI_U32 u32UpdateAttrCnt; /*Number of times that channel attributes or parameters (including RC parameters) are set*/
    HI_U32 u32Qfactor; /* image quality */
}VENC_STREAM_INFO_JPEG_S;

typedef struct hiVENC_STREAM_INFO_MPEG4_S
{
    HI_U32 u32PicBytesNum; /* the coded picture stream byte number */
    HI_U32 u32UpdateAttrCnt; /*Number of times that channel attributes or parameters (including RC parameters) are set*/
}VENC_STREAM_INFO_MPEG4_S;

#if defined(ENABLE_HI3518E_V1)
typedef struct hiVENC_STREAM_V1_S
{
    VENC_PACK_V1_S *pstPack; /*stream pack attribute*/
    HI_U32 u32PackCount; /*the pack number of one frame stream*/
    HI_U32 u32Seq; /*the list number of stream*/

    union
    {
        VENC_STREAM_INFO_H264_V1_S stH264Info; /*the stream info of h264*/
        VENC_STREAM_INFO_JPEG_S stJpegInfo; /*the stream info of jpeg*/
        VENC_STREAM_INFO_MPEG4_S stMpeg4Info; /*the stream info of mpeg4*/
    };
}VENC_STREAM_V1_S;
#endif //defined(ENABLE_HI3518E_V1)

#if defined(ENABLE_HI3518E_V2)
typedef struct hiVENC_STREAM_V2_S
{
    VENC_PACK_V2_S *pstPack; /*stream pack attribute*/
    HI_U32 u32PackCount; /*the pack number of one frame stream*/
    HI_U32 u32Seq; /*the list number of stream*/

    union
    {
        VENC_STREAM_INFO_H264_V2_S stH264Info; /*the stream info of h264*/
        VENC_STREAM_INFO_JPEG_S stJpegInfo; /*the stream info of jpeg*/
        VENC_STREAM_INFO_MPEG4_S stMpeg4Info; /*the stream info of mpeg4*/
        VENC_STREAM_INFO_H265_S stH265Info; /*the stream info of h265*/
    };
}VENC_STREAM_V2_S;
#endif //defined(ENABLE_HI3518E_V2)

typedef enum hiVIDEO_NORM_E
{
    VIDEO_ENCODING_MODE_PAL = 0,
    VIDEO_ENCODING_MODE_NTSC,
    VIDEO_ENCODING_MODE_AUTO,
    VIDEO_ENCODING_MODE_BUTT
}VIDEO_NORM_E;

typedef enum hiROTATE_E
{
    ROTATE_NONE = 0,
    ROTATE_90 = 1,
    ROTATE_180 = 2,
    ROTATE_270 = 3,
    ROTATE_BUTT
}ROTATE_E;

typedef enum sample_vi_chn_set_e
{
    VI_CHN_SET_NORMAL = 0, /* mirror, flip close */
    VI_CHN_SET_MIRROR, /* open MIRROR */
    VI_CHN_SET_FLIP, /* open filp */
    VI_CHN_SET_FLIP_MIRROR /* mirror, flip */
}SAMPLE_VI_CHN_SET_E;

#if defined(ENABLE_HI3518E_V1)
typedef struct sample_vi_config_v1_s
{
    SAMPLE_VI_MODE_V1_E enViMode;
    VIDEO_NORM_E enNorm; /*DC: VIDEO_ENCODING_MODE_AUTO */
    ROTATE_E enRotate;
    SAMPLE_VI_CHN_SET_E enViChnSet;
}SAMPLE_VI_CONFIG_V1_S;
#endif //defined(ENABLE_HI3518E_V1)

#if defined(ENABLE_HI3518E_V2)
typedef struct sample_vi_config_v2_s
{
    SAMPLE_VI_MODE_V2_E enViMode;
    VIDEO_NORM_E enNorm; /*DC: VIDEO_ENCODING_MODE_AUTO */
    ROTATE_E enRotate;
    SAMPLE_VI_CHN_SET_E enViChnSet;
    WDR_MODE_E enWDRMode;
}SAMPLE_VI_CONFIG_V2_S;
#endif //defined(ENABLE_HI3518E_V2)

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_type_func_result_e SAMPLE_COMM_ISP_initialize(void);
    extern libpiziot_os_type_func_result_e SAMPLE_COMM_ISP_finalize(void);

#if defined(ENABLE_HI3518E_V1)
    typedef void (*VI_WRITE_BUFF_FUNC_V1_t)(VENC_STREAM_V1_S* pstStream, libpiziot_stream_in_source_list_t* Alpstream_in_info, uint32_t Astream_in_index);
    extern void SAMPLE_VENC_ADD_CHANNEL(libpiziot_stream_in_source_list_t* Alpstream_in_info);
    extern HI_VOID* SAMPLE_VENC_CLASSIC_INIT(libpiziot_stream_in_source_list_t* Alpstream_in_info);
    extern HI_VOID* SAMPLE_VENC_CLASSIC_EXIT(libpiziot_stream_in_source_list_t* Alpstream_in_info);
    extern HI_S32 SAMPLE_COMM_VENC_GetVencStreamProc(HI_VOID* p, uint32_t Astream_in_index, int32_t Avenc_index, VI_WRITE_BUFF_FUNC_V1_t lpCallBackFunc);
#endif //defined(ENABLE_HI3518E_V1)
#if defined(ENABLE_HI3518E_V2)
    typedef void (*VI_WRITE_BUFF_FUNC_V2_t)(VENC_STREAM_V2_S *pstStream, libpiziot_stream_in_source_list_t* Alpstream_in_info, uint32_t Astream_in_index);
    extern void SAMPLE_VENC_ADD_CHANNEL(libpiziot_stream_in_source_list_t* Alpstream_in_info);
    extern HI_VOID* SAMPLE_VENC_CLASSIC_INIT(libpiziot_stream_in_source_list_t* Alpstream_in_info);
    extern HI_VOID* SAMPLE_VENC_CLASSIC_EXIT(libpiziot_stream_in_source_list_t* Alpstream_in_info);
    extern HI_S32 SAMPLE_COMM_VENC_GetVencStreamProc(HI_VOID* p, uint32_t Astream_in_index, int32_t Avenc_index, VI_WRITE_BUFF_FUNC_V2_t lpCallBackFunc);
#endif //defined(ENABLE_HI3518E_V2)

    extern HI_S32 SAMPLE_COMM_VENC_GetVencStreamProc_Init(HI_VOID* p);
    extern HI_S32 SAMPLE_COMM_VENC_GetVencStreamProc_Exit(HI_VOID* p);

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_HI3518E_V1) || defined(ENABLE_HI3518E_V2)

#endif //__DEF_LIBPIZBSP_HI3518_TYPE_H__
