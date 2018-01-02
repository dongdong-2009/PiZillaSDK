#ifndef __DEF_VIDEO_TYPE_H__
#define __DEF_VIDEO_TYPE_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "libpiziot_os/def_libpiziot_os_type.h"
#include "libpiziot_os/def_libpiziot_os_time.h"

typedef enum libpiziot_bitstream_data_type_enum {
    BitstreamDataType_Unknown,
    BitstreamDataType_Video,
    BitstreamDataType_Audio_PCM,
    BitstreamDataType_Speaker_PCM,
} libpiziot_bitstream_data_type_e;

typedef struct libpiziot_bitstream_head_video_s {
    uint32_t headmark;
    uint32_t data_type;
    int32_t bs_length;
    uint32_t is_keyframe;
    int64_t timestamp_tv_sec;
    int64_t timestamp_tv_usec;
    //int32_t width;
    //int32_t height;
    //int32_t frame_rate;
} libpiziot_bitstream_head_video_t;

typedef struct libpiziot_bitstream_head_audio_s {
    uint32_t headmark;
    uint32_t data_type;
    int32_t bs_length;
    uint32_t is_keyframe;
    int64_t timestamp_tv_sec;
    int64_t timestamp_tv_usec;
} libpiziot_bitstream_head_audio_t;

typedef struct event_streamhead_s {
    uint32_t headmark;
    uint32_t reserve1;
    uint32_t reserve2;
    int32_t bs_length;
    int64_t timestamp_tv_sec;
    int64_t timestamp_tv_usec;
} libpiziot_event_stream_head_t;

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif //__DEF_VIDEO_TYPE_H__
