#ifndef __STREAM_IN_MAIN_H__
#define __STREAM_IN_MAIN_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../include/menu_config.h"

#if defined(ENABLE_STREAM_IN)

//Define Other Header
#include "libpiziot/def_libpiziot_stream_in.h"
#include "libpiziot/libpizbsp_hi35xx/def_hi3518_type.h"

#define NALU_TYPE_SLICE 1
#define NALU_TYPE_DPA 2
#define NALU_TYPE_DPB 3
#define NALU_TYPE_DPC 4
#define NALU_TYPE_IDR 5
#define NALU_TYPE_SEI 6
#define NALU_TYPE_SPS 7
#define NALU_TYPE_PPS 8
#define NALU_TYPE_AUD 9
#define NALU_TYPE_EOSEQ 10
#define NALU_TYPE_EOSTREAM 11
#define NALU_TYPE_FILL 12

typedef struct stream_in_main_thread_info_s {
    libpiziot_os_mutex_struct_plock_t instance_mutex;
    libpiziot_os_pthread_instance_t thread_instance;
    int32_t m_sample_venc_classic_init_flag;
} stream_in_main_thread_info_t;

extern libpiziot_stream_in_source_list_t m_libpiziot_stream_in_source_list;

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(ENABLE_HI3518E_V1)

    extern void stream_in_main_write_data_to_buffer(VENC_STREAM_V1_S *pstStream, libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index);

#elif defined(ENABLE_HI3518E_V2)
    extern void stream_in_main_write_data_to_buffer(VENC_STREAM_V2_S *pstStream, libpiziot_stream_in_source_list_t* Alpstream_in_info, uint32_t Astream_in_index);
#else

    extern void stream_in_main_write_data_to_buffer(VENC_STREAM_V_S *pstStream, libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index);

#endif //defined(ENABLE_HI3518E_V2)

    extern void stream_in_main_start_thread(void);

    extern void stream_in_main_stop_thread(void);

    extern libpiziot_os_type_func_result_e stream_in_main_initialize(void);

    extern libpiziot_os_type_func_result_e stream_in_main_finalize(void);

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_STREAM_IN)

#endif //__STREAM_IN_MAIN_H__
