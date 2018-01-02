#ifndef __DEF_LIBPIZIOT_OS_PTHREAD_H__
#define __DEF_LIBPIZIOT_OS_PTHREAD_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#include "def_libpiziot_os_type.h"
#include "def_libpiziot_os_mutex.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_time.h"

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#define LIBPIZIOT_OS_PTHREAD_STACK_SIZE_AUTO 512

typedef enum libpiziot_os_pthread_status_enum {
    LIBPIZIOT_OS_PTHREAD_STATUS_CREATEING = 1,
    LIBPIZIOT_OS_PTHREAD_STATUS_START_ROUTINE,
    LIBPIZIOT_OS_PTHREAD_STATUS_END_ROUTINE,
    LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED,
} libpiziot_os_pthread_status_e;

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#include "libpiziot/libpiziot_os/def_libpiziot_os_windows.h"
#define libpiziot_os_pthread_dword_t DWORD
#define libpiziot_os_pthread_attr_t DWORD
#define libpiziot_os_pthread_handle_t HANDLE
#elif defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#define libpiziot_os_pthread_dword_t void*
#define libpiziot_os_pthread_attr_t pthread_attr_t
#define libpiziot_os_pthread_handle_t pthread_t
#elif defined(__LIBPIZIOT_OS_FREERTOS__)
#define libpiziot_os_pthread_dword_t void*
#define libpiziot_os_pthread_attr_t int
#define libpiziot_os_pthread_handle_t xTaskHandle
#else
#define libpiziot_os_pthread_dword_t void*
#define libpiziot_os_pthread_attr_t pthread_attr_t
#define libpiziot_os_pthread_handle_t pthread_t
#endif

typedef libpiziot_os_pthread_dword_t(*libpiziot_os_pthread_routine_p)(void *arg);
#define LIBPIZIOT_OS_PTHREAD_ROUTINE_P_NULL 0

struct libpiziot_os_pthread_instance_s {
    int32_t init;
    libpiziot_os_pthread_status_e status;
    libpiziot_os_mutex_struct_plock_t mutex;
    libpiziot_os_mutex_struct_plock_t clean_mutex;
    libpiziot_os_pthread_attr_t attr;
    libpiziot_os_pthread_dword_t dwExitCode;
    libpiziot_os_pthread_handle_t pthread_instance;
    libpiziot_os_pthread_routine_p LPSingleStep;
    int32_t m_ForceBreakSingleStep;
    void *m_extra;
};
typedef struct libpiziot_os_pthread_instance_s libpiziot_os_pthread_instance_t;

#ifdef __cplusplus
extern "C"
{
#endif

    extern libpiziot_os_type_func_result_e libpiziot_os_pthread_initialize(libpiziot_os_pthread_instance_t *AlpUserPthreadInfo, const char *Alpfunc_name, int32_t Aifunc_line);
    extern libpiziot_os_type_func_result_e libpiziot_os_pthread_finalize(libpiziot_os_pthread_instance_t *AlpUserPthreadInfo);
#if defined(__LIBPIZIOT_OS_FREERTOS__)
    extern void libpiziot_os_pthread_uxTaskGetStackHighWaterMark(libpiziot_os_pthread_handle_t Apthread_instance, struct timeval* Alplast, char *AlpTaskName);
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)
    extern int32_t libpiziot_os_pthread_create(libpiziot_os_pthread_instance_t *AlpUserPthreadInfo, libpiziot_os_pthread_routine_p Alppthread_routine, int32_t Astack_size, char *AlpTaskName);
    extern void libpiziot_os_pthread_join(libpiziot_os_pthread_instance_t *lpUserPthreadInfo);
    extern libpiziot_os_pthread_status_e libpiziot_os_pthread_get_status(libpiziot_os_pthread_instance_t *AlpUserPthreadInfo);
    extern void libpiziot_os_pthread_release(libpiziot_os_pthread_instance_t *AlpUserPthreadInfo);
    extern int32_t libpiziot_os_pthread_check_break(libpiziot_os_pthread_instance_t *AlpUserPthreadInfo, const char *Alpfunc_name, int32_t Aifunc_line);

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_PTHREAD_H__
