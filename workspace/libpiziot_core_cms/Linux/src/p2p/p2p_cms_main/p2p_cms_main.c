#include "stdafx.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define C Libary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

//Define Windows Library

//Define MENU_CONFIG_H Library
#include "../../../include/menu_config.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"

#if defined(__ESP8266X__)
#else

#if defined(ENABLE_P2P_CMS)

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_clientsdk.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

//Define this Header
#include "p2p_cms_main.h"

//Define Other Header
#include "../p2p_func.h"
#include "../p2p_func_client.h"

#include "p2p_cms_main_ipcamera.h"
#include "p2p_cms_main_nas.h"
#include "../p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_command.h"
#include "../p2p_cms_channel_client_main/ipcamera_data/p2p_cms_ipcamera_other.h"
#include "../p2p_cms_channel_client_main/nas_data/p2p_cms_nas_command.h"
#include "../p2p_cms_channel_client_main/nas_data/p2p_cms_nas_other.h"

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

#define P2P_CMS_MAIN_IPCAMERA_THREAD_MAX 1
static p2p_cms_main_ipcamera_thread_info_t *lpp2p_cms_main_ipcamera_thread_info[P2P_CMS_MAIN_IPCAMERA_THREAD_MAX];
static int32_t p2p_cms_main_ipcamera_channel_mutex_flag = 0;
libpiziot_os_mutex_struct_plock_t p2p_cms_main_ipcamera_channel_mutex;

#define P2P_CMS_MAIN_NAS_THREAD_MAX 1
static p2p_cms_main_nas_thread_info_t *lpp2p_cms_main_nas_thread_info[P2P_CMS_MAIN_NAS_THREAD_MAX];
static int32_t p2p_cms_main_nas_channel_mutex_flag = 0;
libpiziot_os_mutex_struct_plock_t p2p_cms_main_nas_channel_mutex;

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_ipcamera_get_protocol_command(int32_t Aarray_index, int32_t Achannel_id, p2p_cms_ipcamera_main_protocol_command_t **Alppprotocol_command) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
    do {
        if (Aarray_index < 0 || Aarray_index >= P2P_CMS_MAIN_IPCAMERA_THREAD_MAX) break;
        {
            p2p_cms_main_ipcamera_thread_info_t *lpthread_info = lpp2p_cms_main_ipcamera_thread_info[Aarray_index];
            if (lpthread_info == 0) break;
            switch (Achannel_id) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND: {
                p2p_cms_ipcamera_main_protocol_command_t *lpprotocol_command = &(lpthread_info->protocol_command);
                if (lpprotocol_command->lpthread_info != 0) {
                    (*Alppprotocol_command) = lpprotocol_command;
                    rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
                }
            }
                                                                     break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER: {
                p2p_cms_ipcamera_main_protocol_command_t *lpprotocol_command = &(lpthread_info->protocol_other);
                if (lpprotocol_command->lpthread_info != 0) {
                    (*Alppprotocol_command) = lpprotocol_command;
                    rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
                }
            }
                                                                   break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            default: {
            }
                     break;
            }
        }
    } while (0);
#else
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (Achannel_id) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (Alppprotocol_command) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_main_ipcamera_channel_send(int32_t Aarray_index, int32_t Achannel_id, unsigned char *Alpdata_send, int32_t Adata_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    do {
        switch (Achannel_id) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
        case LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND: {
            p2p_cms_ipcamera_main_protocol_command_t *lpprotocol_command;
            if (libpiziot_core_p2p_cms_ipcamera_get_protocol_command(Aarray_index, Achannel_id, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (lpprotocol_command->lpthread_info != 0) {
                rval = p2p_cms_ipcamera_command_send_to_channel_server(lpprotocol_command->lpthread_info, Alpdata_send, Adata_size);
            }
        }
                                                                 break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
        case LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER: {
            p2p_cms_ipcamera_main_protocol_command_t *lpprotocol_command;
            if (libpiziot_core_p2p_cms_ipcamera_get_protocol_command(Aarray_index, Achannel_id, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (lpprotocol_command->lpthread_info != 0) {
                rval = p2p_cms_ipcamera_other_send_to_channel_server(lpprotocol_command->lpthread_info, Alpdata_send, Adata_size);
            }
        }
                                                               break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
        default: {
        }
                 break;
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
#else
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (Achannel_id) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (Alpdata_send) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (Adata_size) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
    return rval;
}

void libpiziot_core_p2p_cms_enable_ipcamera_channel(int32_t Aarray_index, int32_t Achannel_id) {
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    do {
        if (Aarray_index < 0 || Aarray_index >= P2P_CMS_MAIN_IPCAMERA_THREAD_MAX) break;
        {
            p2p_cms_main_ipcamera_thread_info_t *lpthread_info = lpp2p_cms_main_ipcamera_thread_info[Aarray_index];
            if (lpthread_info == 0) break;
            switch (Achannel_id) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND: {
                lpthread_info->protocol_command.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_YES;
            }
                                                                     break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER: {
                lpthread_info->protocol_other.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_YES;
            }
                                                                   break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            default: {
            }
                     break;
            }
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
}

void libpiziot_core_p2p_cms_disable_ipcamera_channel(int32_t Aarray_index, int32_t Achannel_id) {
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_ipcamera_channel_mutex);
    do {
        if (Aarray_index < 0 || Aarray_index >= P2P_CMS_MAIN_IPCAMERA_THREAD_MAX) break;
        {
            p2p_cms_main_ipcamera_thread_info_t *lpthread_info = lpp2p_cms_main_ipcamera_thread_info[Aarray_index];
            if (lpthread_info == 0) break;
            switch (Achannel_id) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND: {
                lpthread_info->protocol_command.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            }
                                                                     break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER: {
                lpthread_info->protocol_other.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            }
                                                                   break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_OTHER)
            default: {
            }
                     break;
            }
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_ipcamera_channel_mutex);
}

int32_t libpiziot_core_p2p_cms_connect_ipcamera(const char *AlpUID) {
    int32_t array_index = -1;
    {
        uint32_t thread_info_index;
        for (thread_info_index = 0; thread_info_index < P2P_CMS_MAIN_IPCAMERA_THREAD_MAX; thread_info_index++) {
            if (lpp2p_cms_main_ipcamera_thread_info[thread_info_index] != 0) continue;
            if (p2p_cms_main_ipcamera_initialize(&(lpp2p_cms_main_ipcamera_thread_info[thread_info_index])) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (p2p_cms_main_ipcamera_connect_device(lpp2p_cms_main_ipcamera_thread_info[thread_info_index], AlpUID) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            array_index = thread_info_index;
            break;
        }
    }
    return array_index;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_disconnect_ipcamera(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        if (Aarray_index < 0 || Aarray_index >= P2P_CMS_MAIN_IPCAMERA_THREAD_MAX) break;
        p2p_cms_main_ipcamera_disconnect_device(lpp2p_cms_main_ipcamera_thread_info[Aarray_index]);
        if (p2p_cms_main_ipcamera_finalize(&(lpp2p_cms_main_ipcamera_thread_info[Aarray_index])) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
        break;
    } while (0);
    return rval;
}

static void p2p_cms_main_disconnect_ipcamera_all(void) {
    uint32_t thread_info_index;
    for (thread_info_index = 0; thread_info_index < P2P_CMS_MAIN_IPCAMERA_THREAD_MAX; thread_info_index++) {
        p2p_cms_main_ipcamera_disconnect_device(lpp2p_cms_main_ipcamera_thread_info[thread_info_index]);
        if (p2p_cms_main_ipcamera_finalize(&(lpp2p_cms_main_ipcamera_thread_info[thread_info_index])) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_nas_get_protocol_command(int32_t Aarray_index, int32_t Achannel_id, p2p_cms_nas_main_protocol_command_t **Alppprotocol_command) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
    do {
        if (Aarray_index < 0 || Aarray_index >= P2P_CMS_MAIN_NAS_THREAD_MAX) break;
        {
            p2p_cms_main_nas_thread_info_t *lpthread_info = lpp2p_cms_main_nas_thread_info[Aarray_index];
            if (lpthread_info == 0) break;
            switch (Achannel_id) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND: {
                p2p_cms_nas_main_protocol_command_t *lpprotocol_command = &(lpthread_info->protocol_command);
                if (lpprotocol_command->lpthread_info != 0) {
                    (*Alppprotocol_command) = lpprotocol_command;
                    rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
                }
            }
                                                                break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER: {
                p2p_cms_nas_main_protocol_command_t *lpprotocol_command = &(lpthread_info->protocol_other);
                if (lpprotocol_command->lpthread_info != 0) {
                    (*Alppprotocol_command) = lpprotocol_command;
                    rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
                }
            }
                                                              break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            default: {
            }
                     break;
            }
        }
    } while (0);
#else
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (Achannel_id) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (Alppprotocol_command) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
    return rval;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_main_nas_channel_send(int32_t Aarray_index, int32_t Achannel_id, unsigned char *Alpdata_send, int32_t Adata_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    do {
        switch (Achannel_id) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
        case LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND: {
            p2p_cms_nas_main_protocol_command_t *lpprotocol_command;
            if (libpiziot_core_p2p_cms_nas_get_protocol_command(Aarray_index, Achannel_id, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (lpprotocol_command->lpthread_info != 0) {
                rval = p2p_cms_nas_command_send_to_channel_server(lpprotocol_command->lpthread_info, Alpdata_send, Adata_size);
            }
        }
                                                            break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
        case LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER: {
            p2p_cms_nas_main_protocol_command_t *lpprotocol_command;
            if (libpiziot_core_p2p_cms_nas_get_protocol_command(Aarray_index, Achannel_id, &lpprotocol_command) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (lpprotocol_command->lpthread_info != 0) {
                rval = p2p_cms_nas_other_send_to_channel_server(lpprotocol_command->lpthread_info, Alpdata_send, Adata_size);
            }
        }
                                                          break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
        default: {
        }
                 break;
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
#else
    if (Aarray_index) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (Achannel_id) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (Alpdata_send) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
    if (Adata_size) { LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0); }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND) || defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
    return rval;
}

void libpiziot_core_p2p_cms_enable_nas_channel(int32_t Aarray_index, int32_t Achannel_id) {
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    do {
        if (Aarray_index < 0 || Aarray_index >= P2P_CMS_MAIN_NAS_THREAD_MAX) break;
        {
            p2p_cms_main_nas_thread_info_t *lpthread_info = lpp2p_cms_main_nas_thread_info[Aarray_index];
            if (lpthread_info == 0) break;
            switch (Achannel_id) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND: {
                lpthread_info->protocol_command.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_YES;
            }
                                                                break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER: {
                lpthread_info->protocol_other.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_YES;
            }
                                                              break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            default: {
            }
                     break;
            }
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
}

void libpiziot_core_p2p_cms_disable_nas_channel(int32_t Aarray_index, int32_t Achannel_id) {
    libpiziot_os_mutex_plock_lock(&p2p_cms_main_nas_channel_mutex);
    do {
        if (Aarray_index < 0 || Aarray_index >= P2P_CMS_MAIN_NAS_THREAD_MAX) break;
        {
            p2p_cms_main_nas_thread_info_t *lpthread_info = lpp2p_cms_main_nas_thread_info[Aarray_index];
            if (lpthread_info == 0) break;
            switch (Achannel_id) {
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND: {
                lpthread_info->protocol_command.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            }
                                                                break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            case LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER: {
                lpthread_info->protocol_other.channel_enable_flag.enable = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NO;
            }
                                                              break;
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_OTHER)
            default: {
            }
                     break;
            }
        }
    } while (0);
    libpiziot_os_mutex_plock_unlock(&p2p_cms_main_nas_channel_mutex);
}

int32_t libpiziot_core_p2p_cms_connect_nas(const char *AlpUID) {
    int32_t array_index = -1;
    {
        uint32_t thread_info_index;
        for (thread_info_index = 0; thread_info_index < P2P_CMS_MAIN_NAS_THREAD_MAX; thread_info_index++) {
            if (lpp2p_cms_main_nas_thread_info[thread_info_index] != 0) continue;
            if (p2p_cms_main_nas_initialize(&(lpp2p_cms_main_nas_thread_info[thread_info_index])) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (p2p_cms_main_nas_connect_device(lpp2p_cms_main_nas_thread_info[thread_info_index], AlpUID) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            array_index = thread_info_index;
            break;
        }
    }
    return array_index;
}

libpiziot_os_type_func_result_e libpiziot_core_p2p_cms_disconnect_nas(int32_t Aarray_index) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        if (Aarray_index < 0 || Aarray_index >= P2P_CMS_MAIN_NAS_THREAD_MAX) break;
        p2p_cms_main_nas_disconnect_device(lpp2p_cms_main_nas_thread_info[Aarray_index]);
        if (p2p_cms_main_nas_finalize(&(lpp2p_cms_main_nas_thread_info[Aarray_index])) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
        break;
    } while (0);
    return rval;
}

static void p2p_cms_main_disconnect_nas_all(void) {
    uint32_t thread_info_index;
    for (thread_info_index = 0; thread_info_index < P2P_CMS_MAIN_NAS_THREAD_MAX; thread_info_index++) {
        p2p_cms_main_nas_disconnect_device(lpp2p_cms_main_nas_thread_info[thread_info_index]);
        if (p2p_cms_main_nas_finalize(&(lpp2p_cms_main_nas_thread_info[thread_info_index])) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}

static libpiziot_os_type_func_result_e p2p_cms_main_ipcamera_deinit_array(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
        {
            if (p2p_cms_main_ipcamera_channel_mutex_flag != 0) {
                if (libpiziot_os_mutex_plock_free(&(p2p_cms_main_ipcamera_channel_mutex)) != 0) {
                    TRACEA("%s:mutex free channel_mutex,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                }
                p2p_cms_main_ipcamera_channel_mutex_flag = 0;
            }
        }
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

static libpiziot_os_type_func_result_e p2p_cms_main_ipcamera_init_array(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
        {
            if (libpiziot_os_mutex_plock_init(&(p2p_cms_main_ipcamera_channel_mutex), NULL) != 0) {
                TRACEA("%s:mutex init channel_mutex,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                break;
            }
            p2p_cms_main_ipcamera_channel_mutex_flag = 1;
        }
        {
            uint32_t thread_info_index;
            for (thread_info_index = 0; thread_info_index < P2P_CMS_MAIN_IPCAMERA_THREAD_MAX; thread_info_index++) {
                lpp2p_cms_main_ipcamera_thread_info[thread_info_index] = 0;
            }
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
        p2p_cms_main_ipcamera_deinit_array();
    }
    else {
        TRACEB("%s,ok.\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

static libpiziot_os_type_func_result_e p2p_cms_main_nas_deinit_array(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
        {
            if (p2p_cms_main_nas_channel_mutex_flag != 0) {
                if (libpiziot_os_mutex_plock_free(&(p2p_cms_main_nas_channel_mutex)) != 0) {
                    TRACEA("%s:mutex free channel_mutex,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                }
                p2p_cms_main_nas_channel_mutex_flag = 0;
            }
        }
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

static libpiziot_os_type_func_result_e p2p_cms_main_nas_init_array(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        TRACEB("%s ...\n", LIBPIZIOT_OS__FUNCTION__);
        {
            if (libpiziot_os_mutex_plock_init(&(p2p_cms_main_nas_channel_mutex), NULL) != 0) {
                TRACEA("%s:mutex init channel_mutex,error !!\n", LIBPIZIOT_OS__FUNCTION__);
                break;
            }
            p2p_cms_main_nas_channel_mutex_flag = 1;
        }
        {
            uint32_t thread_info_index;
            for (thread_info_index = 0; thread_info_index < P2P_CMS_MAIN_NAS_THREAD_MAX; thread_info_index++) {
                lpp2p_cms_main_nas_thread_info[thread_info_index] = 0;
            }
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        TRACEA("%s,error !!\n", LIBPIZIOT_OS__FUNCTION__);
        p2p_cms_main_nas_deinit_array();
    }
    else {
        TRACEB("%s,ok.\n", LIBPIZIOT_OS__FUNCTION__);
    }
    return rval;
}

void p2p_cms_main_stop_thread(void) {
    p2p_cms_main_disconnect_nas_all();
    p2p_cms_main_disconnect_ipcamera_all();
}

libpiziot_os_type_func_result_e p2p_cms_main_start_thread(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

libpiziot_os_type_func_result_e p2p_cms_main_finalize(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    if (p2p_cms_main_nas_deinit_array() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    }
    if (p2p_cms_main_ipcamera_deinit_array() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    }
    return rval;
}

libpiziot_os_type_func_result_e p2p_cms_main_initialize(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    do {
        rval = p2p_cms_main_ipcamera_init_array();
        if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
        rval = p2p_cms_main_nas_init_array();
        if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
    } while (0);
    if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        p2p_cms_main_finalize();
    }
    return rval;
}

#endif //defined(ENABLE_P2P_CMS)

#endif //defined(__ESP8266X__)
