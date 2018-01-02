#include "stdafx.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define C Libary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
//#include <sys/stat.h>

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#else
#include <signal.h>
#endif

//Define Windows Library

//Define MENU_CONFIG_H Library
#include "../../include/menu_config.h"

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"
//#include "libpiziot/libpiziot_os/def_libpiziot_os_time.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
//#include "libpiziot/libpiziot_os/def_libpiziot_os_socket.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_misc.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mmap.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_file.h"
#include "libpiziot/def_video_type.h"
#include "libpiziot/libpiziot_core_ipcamera/def_libpiziot_core_ipcamera.h"
#include "libpiziot/def_pizcam.h"

#if defined(ENABLE_HI3518E_V1)

#include "libpiziot/libpizbsp_hi35xx/libpizbsp_hi3518e/def_libpizbsp_hi3518e.h"

#endif //defined(ENABLE_HI3518E_V1)

#if defined(ENABLE_HI3518E_V2)

#include "libpiziot/libpizbsp_hi35xx/libpizbsp_hi3518ev2/def_libpizbsp_hi3518ev2.h"

#endif //defined(ENABLE_HI3518E_V2)

#if defined(ENABLE_RTSP_LIB)

#include "libpiziot/libpiziot_net_rtsp/def_libpiziot_net_rtsp.h"

#endif //defined(ENABLE_RTSP_LIB)

#if defined(ENABLE_P2P_LIB)

#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_clientsdk.h"

#endif //defined(ENABLE_P2P_LIB)

#if defined(ENABLE_AVI_LIB)

#include "libpiziot/libpiziot_file_avi/def_libpiziot_file_avi.h"

#endif //defined(ENABLE_AVI_LIB)

//Define this Header
#include "piziot_core_ipcamera.h"

//Define OtherHeader
//#include "busybox/busybox.h"
#include "../misc/misc_setting.h"
#include "../p2p/p2p_func.h"
#include "../p2p/p2p_func_client.h"

#if defined(ENABLE_P2P_IPCAMERA)

#include "../p2p/p2p_ipcamera_main/p2p_ipcamera_main.h"

#endif //defined(ENABLE_P2P_IPCAMERA)

#if defined(ENABLE_P2P_NAS)

#include "../p2p/p2p_nas_main/p2p_nas_main.h"

#endif //defined(ENABLE_P2P_NAS)

#if defined(ENABLE_STREAM_IN)

#include "../stream_in/stream_in_main.h"

#endif //defined(ENABLE_STREAM_IN)

#if defined(ENABLE_STREAM_OUT)

#include "../stream_out/stream_out_main.h"

#endif //defined(ENABLE_STREAM_OUT)

#if defined(ENABLE_OPENSSL)

#include "../openssl/openssl_main.h"

#endif //defined(ENABLE_OPENSSL)

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
#else
#define TRACEB(...) {LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);} //TRACEA
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define APPLICATION_RUNNING "../../pizcam_running"
#elif defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#define APPLICATION_RUNNING "pizcam_running"
#elif defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__)
#elif (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
#else
#define APPLICATION_RUNNING "/tmp/pizcam_running"
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

static int32_t libpiziot_core_ipcamera_initialize_flag = 0;

int32_t libpiziot_core_ipcamera_need_reload_flag = 0;
int32_t libpiziot_core_ipcamera_need_power_flag = 0;
int32_t libpiziot_core_ipcamera_need_reset_flag = 0;

struct m_libpiziot_core_ipcamera_event_loop_thread_s {
    libpiziot_os_pthread_instance_t thread_instance_libpiziot_core_ipcamera_1000ms;
    int32_t thread_init_flag_libpiziot_core_ipcamera_1000ms;
    libpiziot_os_pthread_instance_t thread_instance_libpiziot_core_ipcamera_500ms;
    int32_t thread_init_flag_libpiziot_core_ipcamera_500ms;
};
typedef struct m_libpiziot_core_ipcamera_event_loop_thread_s m_libpiziot_core_ipcamera_event_loop_thread_t;
static m_libpiziot_core_ipcamera_event_loop_thread_t m_libpiziot_core_ipcamera_event_loop_thread;

void libpiziot_core_ipcamera_sigterm_handler(int sig) {
    switch (sig) {
    case SIGINT:
        libpiziot_os_signal_set_terminate_flag();
        TRACEA("Get signal SIGINT\n");
        break;
    case SIGTERM:
        libpiziot_os_signal_set_terminate_flag();
        TRACEA("Get signal SIGTERM\n");
        break;
    case SIGKILL:
        libpiziot_os_signal_set_terminate_flag();
        TRACEA("Get signal SIGKILL\n");
        break;
    case SIGUSR2:
        TRACEA("Get Signal SIGUSR2\n");
        break;
    case SIGUSR1:
        TRACEA("Get Signal SIGUSR1\n");
        break;
    default:
        TRACEA("Get Signal ID=%d\n", sig);
        break;
    }
}

static void libpiziot_core_ipcamera_signal(void) {
#if !defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    signal(SIGINT, libpiziot_core_ipcamera_sigterm_handler);
    signal(SIGTERM, libpiziot_core_ipcamera_sigterm_handler);
    signal(SIGKILL, libpiziot_core_ipcamera_sigterm_handler);
    signal(SIGUSR1, libpiziot_core_ipcamera_sigterm_handler);
    signal(SIGUSR2, libpiziot_core_ipcamera_sigterm_handler);
    signal(SIGHUP, SIG_IGN);
#endif //!defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
}

static libpiziot_os_type_func_result_e libpiziot_core_ipcamera_initialize_libpiziot(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        if (libpiziot_os_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#if defined(ENABLE_HI3518E_V1)
        if (libpizbsp_hi3518e_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
        if (libpizbsp_hi3518e_gpio_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_HI3518E_V1)
#if defined(ENABLE_HI3518E_V2)
        if (libpizbsp_hi3518ev2_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
        if (libpizbsp_hi3518ev2_gpio_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_HI3518E_V2)
#if defined(ENABLE_AVI_LIB)
        if (libpiziot_file_avi_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_AVI_LIB)
#if defined(ENABLE_P2P_LIB)
        if (libpiziot_p2p_common_initialize(LIBPIZIOT_P2P_COMMON_SEND_DATA_MAX_SIZE) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
        if (libpiziot_p2p_clientsdk_initialize((const unsigned char *) "vendorname", (const unsigned char *) "vendorpassword") != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
        libpiziot_p2p_common_set_net_print_msg(LIBPIZIOT_P2P_COMMON_NET_PRINT_MSG_ENABLE);
#endif //defined(ENABLE_P2P_LIB)
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

static void libpiziot_core_ipcamera_finalize_libpiziot(void) {
#if defined(ENABLE_P2P_LIB)
    libpiziot_p2p_clientsdk_finalize();
    libpiziot_p2p_common_finalize();
#endif //defined(ENABLE_P2P_LIB)
#if defined(ENABLE_AVI_LIB)
    libpiziot_file_avi_finalize();
#endif //defined(ENABLE_AVI_LIB)
#if defined(ENABLE_HI3518E_V2)
    libpizbsp_hi3518ev2_gpio_main_finalize();
    libpizbsp_hi3518ev2_finalize();
#endif //defined(ENABLE_HI3518E_V2)
#if defined(ENABLE_HI3518E_V1)
    libpizbsp_hi3518e_gpio_main_finalize();
    libpizbsp_hi3518e_finalize();
#endif //defined(ENABLE_HI3518E_V1)
    libpiziot_os_mmap_free();
    libpiziot_ice_os_file_proc_sys_vm_drop_caches();
#if defined(LIBPIZIOT_ENABLE_OS_MEM)
    libpiziot_os_mem_report_leaks();
#endif //defined(LIBPIZIOT_ENABLE_OS_MEM)
    if (libpiziot_os_finalize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
    }
#if defined(PTHREAD_MUTEX_LIST_CHECK_LEAK)
    libpiziot_os_mutex_report_leaks();
#endif //defined(PTHREAD_MUTEX_LIST_CHECK_LEAK)
#if defined(LIBPIZIOT_ENABLE_OS_SOCKET)
    libpiziot_os_socket_report_leaks();
#endif //defined(LIBPIZIOT_ENABLE_OS_SOCKET)
}

static void libpiziot_core_ipcamera_start_thread_libpiziot(void) {
#if defined(ENABLE_P2P_LIB)
    libpiziot_p2p_common_start_thread();
    libpiziot_p2p_clientsdk_start_thread();
#endif //defined(ENABLE_P2P_LIB)
}

static void libpiziot_core_ipcamera_stop_thread_libpiziot(void) {
#if defined(ENABLE_P2P_LIB)
    libpiziot_p2p_clientsdk_stop_thread();
    libpiziot_p2p_common_stop_thread();
#endif //defined(ENABLE_P2P_LIB)
}

static libpiziot_os_pthread_dword_t libpiziot_core_ipcamera_loop_routine_1000ms(void *arg) {
    libpiziot_os_pthread_instance_t *lpthread_info = (libpiziot_os_pthread_instance_t *)arg;
    if (lpthread_info != 0) {
        do {
            if (libpiziot_os_signal_get_terminate_flag()) break;

            misc_setting_cpu_stat();

#if defined(ENABLE_HI3518E_V1)
            libpizbsp_hi3518e_gpio_main_set_ircut();
#elif defined(ENABLE_HI3518E_V2)
            libpizbsp_hi3518ev2_gpio_main_set_ircut();
#endif //defined(ENABLE_HI3518E_V1)

            usleep(1000000);
        } while (1);
    }
    return (libpiziot_os_pthread_dword_t)1234567;
}

static libpiziot_os_pthread_dword_t libpiziot_core_ipcamera_loop_routine_500ms(void *arg) {
    libpiziot_os_pthread_instance_t *lpthread_info = (libpiziot_os_pthread_instance_t *)arg;
    if (lpthread_info != 0) {
        do {
            if (libpiziot_os_signal_get_terminate_flag()) break;

            usleep(500000);
        } while (1);
    }
    do {

        if (libpiziot_core_ipcamera_need_power_flag == 1) {
            break;
        }
        if (libpiziot_core_ipcamera_need_reset_flag == 1) {
            break;
        }

        //if(libpiziot_core_ipcamera_need_reload_flag == 1)
        //{
        // break;
        //}
    } while (0);

    return (libpiziot_os_pthread_dword_t)1234567;
}

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))

static libpiziot_os_pthread_dword_t libpiziot_core_ipcamera_event_loop(void *arg) {
    libpiziot_os_pthread_dword_t rval = libpiziot_core_ipcamera_loop_routine_1000ms(arg);
    {
        libpiziot_mfc_close_p lpmfc_close = lplibpiziot_mfc_close;
        lplibpiziot_mfc_close = 0;
        if (lpmfc_close != 0) lpmfc_close();
    }
    return rval;
}

#else
void libpiziot_core_ipcamera_event_loop(void)
{
    libpiziot_core_ipcamera_loop_routine_1000ms(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_1000ms));
}
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))

static void libpiziot_core_ipcamera_read_cfg(void) {
}

libpiziot_os_type_func_result_e libpiziot_core_ipcamera_initialize_all_lib(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        misc_setting_iptables_enable();
        // Initialize
        // libpizbspxxx -> streamin -> streamout -> rtsp & p2p
#if defined(ENABLE_STREAM_IN)
        if (stream_in_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_STREAM_IN)
#if defined(ENABLE_STREAM_OUT)
        if (stream_out_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_STREAM_OUT)
#if defined(ENABLE_RTSP_LIB)
        if (libpiziot_net_rtsp_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_RTSP_LIB)
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
        if (p2p_func_client_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_ipcamera_start_all_thread(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        libpiziot_core_ipcamera_start_thread_libpiziot();
#if defined(ENABLE_STREAM_IN)
        stream_in_main_start_thread();
#endif //defined(ENABLE_STREAM_IN)
#if defined(ENABLE_STREAM_OUT)
        stream_out_main_start_thread();
#endif //defined(ENABLE_STREAM_OUT)
#if defined(ENABLE_RTSP_LIB)
        libpiziot_net_rtsp_start_thread();
#endif //defined(ENABLE_RTSP_LIB)
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
        if (p2p_func_client_start_thread() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_ipcamera_stop_all_thread(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
        p2p_func_client_stop_thread();
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
#if defined(ENABLE_RTSP_LIB)
        libpiziot_net_rtsp_stop_thread();
#endif //defined(ENABLE_RTSP_LIB)
#if defined(ENABLE_STREAM_OUT)
        stream_out_main_stop_thread();
#endif //defined(ENABLE_STREAM_OUT)
#if defined(ENABLE_STREAM_IN)
        stream_in_main_stop_thread();
#endif //defined(ENABLE_STREAM_IN)
        libpiziot_core_ipcamera_stop_thread_libpiziot();
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_ipcamera_finalize_all_lib(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        // Finialize
        //rtsp & p2p -> streamout -> streamin -> libpizbspxxx
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
        p2p_func_client_finalize();
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
#if defined(ENABLE_RTSP_LIB)
        libpiziot_net_rtsp_finalize();
#endif //defined(ENABLE_RTSP_LIB)
#if defined(ENABLE_STREAM_OUT)
        stream_out_main_finalize();
#endif //defined(ENABLE_STREAM_OUT)
#if defined(ENABLE_STREAM_IN)
        stream_in_main_finalize();
#endif //defined(ENABLE_STREAM_IN)
        misc_setting_iptables_disable();
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

#if defined(LIBPIZIOT_ENABLE_OS_MEM_CHECK_STRUCT_SIZE)

static libpiziot_os_type_func_result_e libpiziot_core_ipcamera_check_struct_size(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        if (libpiziot_os_mem_check_struct_size("libpiziot_bitstream_head_video_t", sizeof(libpiziot_bitstream_head_video_t), 32) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
        if (libpiziot_os_mem_check_struct_size("libpiziot_bitstream_head_audio_t", sizeof(libpiziot_bitstream_head_audio_t), 32) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
        if (libpiziot_os_mem_check_struct_size("libpiziot_event_stream_head_t", sizeof(libpiziot_event_stream_head_t), 32) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;

        {
            struct timeval timestamp;
            time_t timep;
            struct tm m_timeinfo_sec;
            gettimeofday(&timestamp, NULL);
            timep = (time_t)(timestamp.tv_sec);
            localtime_r(&(timep), &(m_timeinfo_sec));
            {
                char buffer[80];
                strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", &(m_timeinfo_sec));
                TRACEA("\nLocal Time: %s\n", buffer);
            }
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

#endif //defined(LIBPIZIOT_ENABLE_OS_MEM_CHECK_STRUCT_SIZE)

static void libpiziot_core_ipcamera_stop_event_loop_thread(void) {
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
    if (m_libpiziot_core_ipcamera_event_loop_thread.thread_init_flag_libpiziot_core_ipcamera_1000ms == 1) {
        int32_t msg = 0;
        libpiziot_os_pthread_instance_t *lpthread_info_libpiziot_core_ipcamera_1000ms = &(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_1000ms);
        if (libpiziot_os_pthread_get_status(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_1000ms)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED) msg = 1;
        //if (msg == 1)
        //{
        // TRACEA("%s:libpiziot_core_ipcamera_1000ms,libpiziot_os_pthread_release(...)\n", LIBPIZIOT_OS__FUNCTION__);
        // LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        //}
        libpiziot_os_pthread_release(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_1000ms));
        if (msg == 1) {
            TRACEB("%s:1000ms,WaitUserPthread ...\n", LIBPIZIOT_OS__FUNCTION__);
            LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        }
        libpiziot_os_pthread_join(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_1000ms));
        //if (msg == 1)
        //{
        // TRACEA("%s:libpiziot_core_ipcamera_1000ms,THREAD_HANDLE_CLOSED ...\n", LIBPIZIOT_OS__FUNCTION__);
        // LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        //}
        if (libpiziot_os_pthread_finalize(lpthread_info_libpiziot_core_ipcamera_1000ms) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        m_libpiziot_core_ipcamera_event_loop_thread.thread_init_flag_libpiziot_core_ipcamera_1000ms = 0;
    }
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
    if (m_libpiziot_core_ipcamera_event_loop_thread.thread_init_flag_libpiziot_core_ipcamera_500ms == 1) {
        int32_t msg = 0;
        libpiziot_os_pthread_instance_t *lpthread_info_libpiziot_core_ipcamera_500ms = &(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_500ms);
        if (libpiziot_os_pthread_get_status(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_500ms)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED) msg = 1;
        //if (msg == 1)
        //{
        // TRACEA("%s:libpiziot_core_ipcamera_500ms,libpiziot_os_pthread_release(...)\n", LIBPIZIOT_OS__FUNCTION__);
        // LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        //}
        libpiziot_os_pthread_release(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_500ms));
        if (msg == 1) {
            TRACEB("%s:500ms,WaitUserPthread ...\n", LIBPIZIOT_OS__FUNCTION__);
            LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        }
        libpiziot_os_pthread_join(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_500ms));
        //if (msg == 1)
        //{
        // TRACEA("%s:libpiziot_core_ipcamera_500ms,THREAD_HANDLE_CLOSED ...\n", LIBPIZIOT_OS__FUNCTION__);
        // LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        //}
        if (libpiziot_os_pthread_finalize(lpthread_info_libpiziot_core_ipcamera_500ms) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        m_libpiziot_core_ipcamera_event_loop_thread.thread_init_flag_libpiziot_core_ipcamera_500ms = 0;
    }
}

static libpiziot_os_type_func_result_e libpiziot_core_ipcamera_start_event_loop_thread(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    //TRACEA("%s....\n", LIBPIZIOT_OS__FUNCTION__);
    do {
        {
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
            memset_addr(m_libpiziot_core_ipcamera_event_loop_thread_t, &(m_libpiziot_core_ipcamera_event_loop_thread), 0xCC, sizeof(m_libpiziot_core_ipcamera_event_loop_thread_t));
            {
                libpiziot_os_pthread_instance_t *lpthread_info_libpiziot_core_ipcamera_1000ms = &(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_1000ms);
                rval = libpiziot_os_pthread_initialize(lpthread_info_libpiziot_core_ipcamera_1000ms, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                    break;
                }
                lpthread_info_libpiziot_core_ipcamera_1000ms->m_extra = (void *) &(m_libpiziot_core_ipcamera_event_loop_thread);
                m_libpiziot_core_ipcamera_event_loop_thread.thread_init_flag_libpiziot_core_ipcamera_1000ms = 1;
            }
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
            {
                libpiziot_os_pthread_instance_t *lpthread_info_libpiziot_core_ipcamera_500ms = &(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_500ms);
                rval = libpiziot_os_pthread_initialize(lpthread_info_libpiziot_core_ipcamera_500ms, LIBPIZIOT_OS__FUNCTION__, __LINE__);
                if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                    break;
                }
                lpthread_info_libpiziot_core_ipcamera_500ms->m_extra = (void *) &(m_libpiziot_core_ipcamera_event_loop_thread);
                m_libpiziot_core_ipcamera_event_loop_thread.thread_init_flag_libpiziot_core_ipcamera_500ms = 1;
            }
        }
        {
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
            if ((libpiziot_os_pthread_get_status(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_1000ms)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED)
                || libpiziot_os_pthread_create(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_1000ms), libpiziot_core_ipcamera_event_loop, LIBPIZIOT_OS_PTHREAD_STACK_SIZE_AUTO, "loop_1000ms") != 0) {
                TRACEA("%s:libpiziot_core_ipcamera_1000ms CreateUserPthread,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                break;
            }
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__) || (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
            if ((libpiziot_os_pthread_get_status(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_500ms)) != LIBPIZIOT_OS_PTHREAD_STATUS_CLOSED)
                || libpiziot_os_pthread_create(&(m_libpiziot_core_ipcamera_event_loop_thread.thread_instance_libpiziot_core_ipcamera_500ms), libpiziot_core_ipcamera_loop_routine_500ms, LIBPIZIOT_OS_PTHREAD_STACK_SIZE_AUTO, "loop_500ms") != 0) {
                TRACEA("%s:libpiziot_core_ipcamera_500ms CreateUserPthread,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                break;
            }
        }
    } while (0);
    return rval;
}

void libpiziot_core_ipcamera_finalize(void) {
    libpiziot_os_signal_set_terminate_flag();

    libpiziot_core_ipcamera_stop_event_loop_thread();

    TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
    if (libpiziot_core_ipcamera_stop_all_thread() != 0) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (libpiziot_core_ipcamera_finalize_all_lib() != 0) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    TRACEA("%s:Ok.\n", LIBPIZIOT_OS__FUNCTION__);

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
    //libpiziot_os_busybox_system("rmmod cpe-wdt");
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

    libpiziot_core_ipcamera_finalize_libpiziot();

#if defined(APPLICATION_RUNNING)
    {
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
        if (_unlink(APPLICATION_RUNNING) == 0) {
            LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        }
#else
        if (unlink(APPLICATION_RUNNING) == 0)
        {
            LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
        }
#endif
    }
#endif //defined(APPLICATION_RUNNING)

    do {
        if (libpiziot_core_ipcamera_need_power_flag == 1) {
#if (!defined(__LIBPIZIOT_OS_PLATFORM_MFC__) && !defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__))
            if (system("umount /mnt/sd") == -1) {LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
            if (system("reboot") == -1) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
#endif //(!defined(__LIBPIZIOT_OS_PLATFORM_MFC__) && !defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__))
            break;
        }

        if (libpiziot_core_ipcamera_need_reset_flag == 1) {
#if (!defined(__LIBPIZIOT_OS_PLATFORM_MFC__) && !defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__))
            if (system("/etc/init.d/rc.reset") == -1) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
            if (system("umount /mnt/sd") == -1) {LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
            if (system("reboot") == -1) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
#endif //(!defined(__LIBPIZIOT_OS_PLATFORM_MFC__) && !defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__))
            break;
        }
    } while (0);
    libpiziot_core_ipcamera_initialize_flag = 0;
}

libpiziot_os_type_func_result_e libpiziot_core_ipcamera_initialize(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        if (libpiziot_core_ipcamera_initialize_flag == 1) {
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
            break;
        }

        if (libpiziot_core_ipcamera_initialize_libpiziot() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;

#if defined(ENABLE_P2P_LIB)
        {
            unsigned char lpVersion[4];
            libpiziot_p2p_common_get_version(lpVersion);
            TRACEA("LIBPIZIOT Version %d.%d.%d.%d\n", (int32_t)(lpVersion[0]), (int32_t)(lpVersion[1]), (int32_t)(lpVersion[2]), (int32_t)(lpVersion[3]));
        }
#endif //defined(ENABLE_P2P_LIB)

        libpiziot_core_ipcamera_signal();

#if defined(LIBPIZIOT_ENABLE_OS_MEM_CHECK_STRUCT_SIZE)
        if (libpiziot_core_ipcamera_check_struct_size() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(LIBPIZIOT_ENABLE_OS_MEM_CHECK_STRUCT_SIZE)

#if defined(APPLICATION_RUNNING)
        {
            FILE *fid;
            fid = fopen(APPLICATION_RUNNING, "wb");
            if (fid == NULL) break;
            if (fclose(fid) != 0) break;
        }
#endif //defined(APPLICATION_RUNNING)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
        //libpiziot_os_busybox_system("insmod /lib/modules/cpe-wdt.ko");
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

        libpiziot_core_ipcamera_read_cfg();

        if (libpiziot_core_ipcamera_initialize_all_lib() != 0) break;
        if (libpiziot_core_ipcamera_start_all_thread() != 0) break;

        if (libpiziot_core_ipcamera_start_event_loop_thread() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;

        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        libpiziot_os_signal_set_terminate_flag();
    }
    return rval;
}

//int main(int argc, char *argv[]) {
//// int argc_index;
//// puts("!!!Hello AVServer!!!"); /* prints !!!Hello World!!! */
//
//// TRACEA("main(argc=%d)\n",argc);
//// for(argc_index = 0;argc_index < argc;argc_index++)
//// {
//// TRACEA("%s\n",argv[argc_index]);
//// }
//
//#ifdef __cplusplus
// std::cout << "!!!Hello World!!!" << std::endl; // prints !!!Hello World!!!
//#endif
// return EXIT_SUCCESS;
//}
