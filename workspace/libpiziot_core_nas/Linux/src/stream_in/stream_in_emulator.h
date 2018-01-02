#ifndef __STREAM_IN_EMULATOR_H__
#define __STREAM_IN_EMULATOR_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../include/menu_config.h"

#if defined(ENABLE_STREAM_IN)

#include "libpiziot/def_libpiziot_stream_in.h"
#include "libpiziot/libpizbsp_hi35xx/def_hi3518_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(ENABLE_SIMULATE_VENC)

    extern libpiziot_os_type_func_result_e stream_in_emulator_close_test_file(int32_t Avenc_index);

#if defined(ENABLE_HI3518E_V1)

    extern libpiziot_os_type_func_result_e stream_in_emulator_GetH264DataFromEmulator(VENC_STREAM_V1_S *pstStream, libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index, int32_t Avenc_index);

    extern void stream_in_emulator_NextH264DataFromEmulator(int32_t Avenc_index);

#elif defined(ENABLE_HI3518E_V2)
    extern libpiziot_os_type_func_result_e stream_in_emulator_GetH264DataFromEmulator(VENC_STREAM_V2_S *pstStream, libpiziot_stream_in_source_list_t* Alpstream_in_info, uint32_t Astream_in_index, int32_t Avenc_index);
    extern void stream_in_emulator_NextH264DataFromEmulator(int32_t Avenc_index);
#else

    extern libpiziot_os_type_func_result_e stream_in_emulator_GetH264DataFromEmulator(VENC_STREAM_V_S *pstStream, libpiziot_stream_in_source_list_t *Alpstream_in_info, uint32_t Astream_in_index, int32_t Avenc_index);

    extern void stream_in_emulator_NextH264DataFromEmulator(int32_t Avenc_index);

#endif //defined(ENABLE_HI3518E_V2)

#endif //defined(ENABLE_SIMULATE_VENC)

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_STREAM_IN)

#endif //__STREAM_IN_EMULATOR_H__
