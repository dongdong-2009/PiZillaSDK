#ifndef __STREAM_OUT_MAIN_H__
#define __STREAM_OUT_MAIN_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "../../include/menu_config.h"

#if defined(ENABLE_STREAM_OUT)

#ifdef __cplusplus
extern "C"
{
#endif

    extern void stream_out_main_start_thread(void);

    extern void stream_out_main_stop_thread(void);

    extern libpiziot_os_type_func_result_e stream_out_main_initialize(void);

    extern libpiziot_os_type_func_result_e stream_out_main_finalize(void);

#ifdef __cplusplus
}
#endif

#endif //defined(ENABLE_STREAM_OUT)

#endif //__STREAM_OUT_MAIN_H__
