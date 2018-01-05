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
#include "../../include/menu_config.h"

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mutex.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"

#if defined(__ESP8266X__)
#else

#include "libpiziot/libpiziot_os/def_libpiziot_os_file.h"

#endif //defined(__ESP8266X__)

#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_clientsdk.h"

//Define this Header
#include "p2p_func_client.h"

//Define Other Header
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#include "p2p_protocol_ipcamera.h"

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#if defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#include "p2p_protocol_nas.h"

#endif //efined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#if defined(ENABLE_P2P_CMS)

#include "p2p_cms_main/p2p_cms_main.h"

#endif //defined(ENABLE_P2P_CMS)

#if defined(ENABLE_P2P_NAS)

#include "p2p_nas_main/p2p_nas_main.h"

#endif //defined(ENABLE_P2P_NAS)

#if defined(ENABLE_P2P_IPCAMERA)

#include "p2p_ipcamera_main/p2p_ipcamera_main.h"

#endif //defined(ENABLE_P2P_IPCAMERA)

#if defined(ENABLE_P2P_GCLIENT)

#include "p2p_gclient_main/p2p_gclient_main.h"

#endif //defined(ENABLE_P2P_GCLIENT)

#if defined(ENABLE_P2P_GSERVER)

#include "p2p_gserver_main/p2p_gserver_main.h"

#endif //defined(ENABLE_P2P_GSERVER)

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

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)
#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
int32_t p2p_func_client_lan_server_handle = -1;
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)

#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
libpiziot_os_type_func_result_e p2p_func_client_lan_server_start_thread(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    if (p2p_func_client_lan_server_handle == -1) {
        rval = libpiziot_p2p_clientsdk_create_lan_server(SAMPLE_CODE_P2P_LAN_SERVER_PORT_DEFAULT, &p2p_func_client_lan_server_handle);
        if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            //TRACEA("PIZCam:%s:p2p_func_client_lan_server_handle=%d\n",LIBPIZIOT_OS__FUNCTION__,p2p_func_client_lan_server_handle);
        }
        else {
            TRACEA("PIZCam:create_lan_server,error !!\n");
        }
    }
    return rval;
}
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)

#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
void p2p_func_client_lan_server_stop_thread(void) {
    if (p2p_func_client_lan_server_handle >= 0) {
        libpiziot_p2p_clientsdk_delete_lan_server(p2p_func_client_lan_server_handle);
        p2p_func_client_lan_server_handle = -1;
    }
}
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)

libpiziot_os_type_func_result_e p2p_func_client_aes_init_cb(libpiziot_os_aes_cbc_t *Alpcontext_cb, char *AlpCB, char *AlpIV) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        // Allocate AES memory resource.
        libpiziot_os_aes_init(&(Alpcontext_cb->aes_key));
        {
            sprintf((char *)(Alpcontext_cb->gen_str), "%s", AlpCB);
            if (strlen((char *)(Alpcontext_cb->gen_str)) != LIBPIZIOT_OS_AES_GEN_STR_LEN) {
                break;
            }
            sprintf((char *)(Alpcontext_cb->cbc_iv), "%s", AlpIV);
            if (strlen((char *)(Alpcontext_cb->cbc_iv)) != LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN) {
                break;
            }
        }
        // Call the P2P SDK to initialize AES key.
        if (libpiziot_os_aes_create_key(&(Alpcontext_cb->aes_key), Alpcontext_cb->gen_str, 256) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            TRACEA("device_login_cb AES setkey failed\n");
            break;
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

void p2p_func_client_aes_free_cb(libpiziot_os_aes_cbc_t *Alpcontext_cb) {
    // Release AES memory resource.
    libpiziot_os_aes_free(&(Alpcontext_cb->aes_key));
}

#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)

#if defined(__ESP8266X__)
#else

static libpiziot_os_type_func_result_e sample_code_p2p_read_key_from_file_aes(char *Alpfile_name, unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&libpiziot_os_file_mx_io);
    {
        FILE *fid = NULL;
        do {
            if (Aaccount_size <= 0) break;
            if (Apassword_size <= 0) break;
            fid = fopen(Alpfile_name, "rb");
            if (fid == NULL) break;
            if (fseek(fid, 0, SEEK_END) != 0) break;
            {
                size_t fileSize = ftell(fid);
                if (fileSize != (Aaccount_size + Apassword_size)) break;
            }
            if (fseek(fid, 0, SEEK_SET) != 0) break;
            {
                size_t nSize;
                nSize = fread(Alpaccount, sizeof(char), Aaccount_size, fid);
                if (nSize != Aaccount_size) break;
                nSize = fread(Alppassword, sizeof(char), Apassword_size, fid);
                if (nSize != Apassword_size) break;
            }
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
        } while (0);
        if (fid != NULL) {
            if (fclose(fid) != 0) {
                TRACE_ERROR("%s,%s fclose,error\n", LIBPIZIOT_OS__FUNCTION__, Alpfile_name);
            }
            fid = NULL;
        }
    }
    libpiziot_os_mutex_plock_unlock(&libpiziot_os_file_mx_io);
    return rval;
}

libpiziot_os_type_func_result_e sample_code_p2p_write_key_to_file_aes(char *Alpdir_name, char *Alpfile_name, unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        if (Aaccount_size <= 0) break;
        if (Apassword_size <= 0) break;
        // Call the LIBPIZIOT SDK to create the key directory.
        if (libpiziot_ice_os_file_is_path_exist(Alpdir_name) == LIBPIZIOT_OS_FILE_PATH_NOT_FOUND) {
            if (libpiziot_ice_os_file_create_child_path(Alpdir_name) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
        }
        libpiziot_os_mutex_plock_lock(&libpiziot_os_file_mx_io);
        {
            FILE *fid = NULL;
            do {
                fid = fopen(Alpfile_name, "wb");
                if (fid == NULL) break;
                if (fseek(fid, 0, SEEK_SET) != 0) break;
                if (fwrite(Alpaccount, sizeof(char), Aaccount_size, fid) != Aaccount_size) break;
                if (fwrite(Alppassword, sizeof(char), Apassword_size, fid) != Apassword_size) break;
                rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
            } while (0);
            if (fid != NULL) {
                if (fclose(fid) != 0) {
                    TRACE_ERROR("%s,%s fclose,error\n", LIBPIZIOT_OS__FUNCTION__, Alpfile_name);
                }
                fid = NULL;
            }
            libpiziot_os_mutex_plock_unlock(&libpiziot_os_file_mx_io);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
        }
    } while (0);
    return rval;
}

#endif //defined(__ESP8266X__)

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)

#if defined(__ESP8266X__)
#else

libpiziot_os_type_func_result_e sample_code_p2p_read_key_from_file_txt(char *Alpfile_name, unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    libpiziot_os_mutex_plock_lock(&libpiziot_os_file_mx_io);
    {
        FILE *fid = NULL;
        do {
            fid = fopen(Alpfile_name, "rb");
            if (fid == NULL) break;
            if (fseek(fid, 0, SEEK_SET) != 0) break;
            {
#define BUFF_SIZE 128
                char buff[BUFF_SIZE + 1];
                if (fgets(buff, BUFF_SIZE, fid) == NULL) break;
                {
                    size_t l = strlen(buff);
                    size_t i;
                    if (l > BUFF_SIZE) l = BUFF_SIZE;
                    for (i = 0; i < l; i++) {
                        if (buff[i] == '\r') {
                            buff[i] = 0;
                            break;
                        }
                        else if (buff[i] == '\n') {
                            buff[i] = 0;
                            break;
                        }
                    }
                }
                if (strlen(buff) > Aaccount_size) break;
                memcpy(Alpaccount, buff, strlen(buff));
                if (fgets(buff, BUFF_SIZE, fid) == NULL) break;
                {
                    size_t l = strlen(buff);
                    size_t i;
                    if (l > BUFF_SIZE) l = BUFF_SIZE;
                    for (i = 0; i < l; i++) {
                        if (buff[i] == '\r') {
                            buff[i] = 0;
                            break;
                        }
                        else if (buff[i] == '\n') {
                            buff[i] = 0;
                            break;
                        }
                    }
                }
                if (strlen(buff) > Apassword_size) break;
                memcpy(Alppassword, buff, strlen(buff));
            }
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
        } while (0);
        if (fid != NULL) {
            if (fclose(fid) != 0) {
                TRACE_ERROR("%s,%s fclose,error\n", LIBPIZIOT_OS__FUNCTION__, Alpfile_name);
            }
            fid = NULL;
        }
    }
    libpiziot_os_mutex_plock_unlock(&libpiziot_os_file_mx_io);
    return rval;
}

#endif //defined(__ESP8266X__)

#if 0
void p2p_func_client_print_device_key(unsigned char* Alpaccount, size_t Aaccount_size, unsigned char* Alppassword, size_t Apassword_size)
{
    libpiziot_os_mutex_plock_lock(&libpiziot_os_debug_mx);
    {
        {
            int32_t p;
            int32_t crlf_cnt = 0;
            libpiziot_os_debug_thread_non_safe_printf("Alpaccount=\n");
            for (p = 0; p < Aaccount_size; p++)
            {
                libpiziot_os_debug_thread_non_safe_printf("0x%02x,", Alpaccount[p]);
                crlf_cnt++;
                if (crlf_cnt == 16)
                {
                    libpiziot_os_debug_thread_non_safe_printf("\n");
                    crlf_cnt = 0;
                }
            }
            if (crlf_cnt != 0) libpiziot_os_debug_thread_non_safe_printf("\n");
        }
        {
            int32_t p;
            int32_t crlf_cnt = 0;
            libpiziot_os_debug_thread_non_safe_printf("Alppassword=\n");
            for (p = 0; p < Apassword_size; p++)
            {
                libpiziot_os_debug_thread_non_safe_printf("0x%02x,", Alppassword[p]);
                crlf_cnt++;
                if (crlf_cnt == 16)
                {
                    libpiziot_os_debug_thread_non_safe_printf("\n");
                    crlf_cnt = 0;
                }
            }
            if (crlf_cnt != 0) libpiziot_os_debug_thread_non_safe_printf("\n");
        }
    }
    libpiziot_os_mutex_plock_unlock(&libpiziot_os_debug_mx);
}
#endif //0

#if defined(__ESP8266X__)
#else
#if defined(ENABLE_P2P_IPCAMERA)
#define P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_DIR BASE_SDA1"misc/setting/login"
#define P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_FILE_AES P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_DIR"/ipcamera_device.aes"
#define P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_FILE_TXT P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_DIR"/ipcamera_device.txt"

libpiziot_os_type_func_result_e p2p_func_client_device_get_ipcamera_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        // Read the key from aes file.
        rval = sample_code_p2p_read_key_from_file_aes(P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
        if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        {
            // Read the key from txt file.
            rval = sample_code_p2p_read_key_from_file_txt(P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_FILE_TXT, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                // Use default account as the key
                {
                    const char *lpdevice_account = "HelloKitty";
                    if (strlen(lpdevice_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpdevice_account, strlen(lpdevice_account));
                }
                {
                    const char *lpdevice_password = "kitty1234";
                    if (strlen(lpdevice_password) > Apassword_size) break;
                    memcpy(Alppassword, lpdevice_password, strlen(lpdevice_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            rval = sample_code_p2p_write_key_to_file_aes(P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_DIR, P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
            //if (_unlink(P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_FILE_TXT) == 0) {}
#else
            if (unlink(P2P_FUNC_CFG_LOGIN_IPCAMERA_DEVICE_FILE_TXT) == 0) {
                LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            }
#endif
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
#if 0
    if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS)
    {
        p2p_func_client_print_device_key(Alpaccount, Aaccount_size, Alppassword, Apassword_size);
    }
#endif //0
    return rval;
}

#define P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_DIR BASE_SDA1"misc/setting/login"
#define P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_FILE_AES P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_DIR"/ipcamera_channel.aes"
#define P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_FILE_TXT P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_DIR"/ipcamera_channel.txt"

libpiziot_os_type_func_result_e p2p_func_client_device_get_ipcamera_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        // Read the key from aes file.
        rval = sample_code_p2p_read_key_from_file_aes(P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
        if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        {
            // Read the key from txt file.
            rval = sample_code_p2p_read_key_from_file_txt(P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_FILE_TXT, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                // Use default account as the key
                {
                    const char *lpchannel_account = "HelloChannel";
                    if (strlen(lpchannel_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpchannel_account, strlen(lpchannel_account));
                }
                {
                    const char *lpchannel_password = "channel1234";
                    if (strlen(lpchannel_password) > Apassword_size) break;
                    memcpy(Alppassword, lpchannel_password, strlen(lpchannel_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            rval = sample_code_p2p_write_key_to_file_aes(P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_DIR, P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
            //if (_unlink(P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_FILE_TXT) == 0) {}
#else
            if (unlink(P2P_FUNC_CFG_LOGIN_IPCAMERA_CHANNEL_FILE_TXT) == 0) {
                LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            }
#endif
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

#endif //defined(ENABLE_P2P_IPCAMERA)
#endif //defined(__ESP8266X__)

#if defined(__ESP8266X__)
#else
#if defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

libpiziot_os_type_func_result_e p2p_func_client_viewer_get_ipcamera_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
        {
            {
                // Use default account as the key
                {
                    const char *lpdevice_account = "HelloKitty";
                    if (strlen(lpdevice_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpdevice_account, strlen(lpdevice_account));
                }
                {
                    const char *lpdevice_password = "kitty1234";
                    if (strlen(lpdevice_password) > Apassword_size) break;
                    memcpy(Alppassword, lpdevice_password, strlen(lpdevice_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
#if 0
    if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS)
    {
        p2p_func_client_print_device_key(Alpaccount, Aaccount_size, Alppassword, Apassword_size);
    }
#endif //0
    return rval;
}

libpiziot_os_type_func_result_e p2p_func_client_viewer_get_ipcamera_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
        {
            {
                // Use default account as the key
                {
                    const char *lpchannel_account = "HelloChannel";
                    if (strlen(lpchannel_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpchannel_account, strlen(lpchannel_account));
                }
                {
                    const char *lpchannel_password = "channel1234";
                    if (strlen(lpchannel_password) > Apassword_size) break;
                    memcpy(Alppassword, lpchannel_password, strlen(lpchannel_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

#endif //defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)
#endif //defined(__ESP8266X__)

#if defined(ENABLE_P2P_NAS)
#if defined(__ESP8266X__)
#else
#define P2P_FUNC_CFG_LOGIN_NAS_DEVICE_DIR BASE_SDA1"misc/setting/login"
#define P2P_FUNC_CFG_LOGIN_NAS_DEVICE_FILE_AES P2P_FUNC_CFG_LOGIN_NAS_DEVICE_DIR"/nas_device.aes"
#define P2P_FUNC_CFG_LOGIN_NAS_DEVICE_FILE_TXT P2P_FUNC_CFG_LOGIN_NAS_DEVICE_DIR"/nas_device.txt"
#endif //defined(__ESP8266X__)

libpiziot_os_type_func_result_e p2p_func_client_device_get_nas_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        // Read the key from aes file.
#if defined(__ESP8266X__)
#else
        rval = sample_code_p2p_read_key_from_file_aes(P2P_FUNC_CFG_LOGIN_NAS_DEVICE_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
        if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
#endif //defined(__ESP8266X__)

#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        {
            // Read the key from txt file.
#if defined(__ESP8266X__)
#else
            rval = sample_code_p2p_read_key_from_file_txt(P2P_FUNC_CFG_LOGIN_NAS_DEVICE_FILE_TXT, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
#endif //defined(__ESP8266X__)
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                // Use default account as the key
                {
                    const char *lpdevice_account = "HelloKitty";
                    if (strlen(lpdevice_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpdevice_account, strlen(lpdevice_account));
                }
                {
                    const char *lpdevice_password = "kitty1234";
                    if (strlen(lpdevice_password) > Apassword_size) break;
                    memcpy(Alppassword, lpdevice_password, strlen(lpdevice_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#if defined(__ESP8266X__)
#else
            rval = sample_code_p2p_write_key_to_file_aes(P2P_FUNC_CFG_LOGIN_NAS_DEVICE_DIR, P2P_FUNC_CFG_LOGIN_NAS_DEVICE_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#endif //defined(__ESP8266X__)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
            //if (_unlink(P2P_FUNC_CFG_LOGIN_NAS_DEVICE_FILE_TXT) == 0) {}
#else
#if defined(__ESP8266X__)
#else
            if (unlink(P2P_FUNC_CFG_LOGIN_NAS_DEVICE_FILE_TXT) == 0) {
                LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            }
#endif //defined(__ESP8266X__)
#endif
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
#if 0
    if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS)
    {
        p2p_func_client_print_device_key(Alpaccount, Aaccount_size, Alppassword, Apassword_size);
    }
#endif //0
    return rval;
}

#if defined(__ESP8266X__)
#else
#define P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_DIR BASE_SDA1"misc/setting/login"
#define P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_FILE_AES P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_DIR"/nas_channel.aes"
#define P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_FILE_TXT P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_DIR"/nas_channel.txt"
#endif //defined(__ESP8266X__)

libpiziot_os_type_func_result_e p2p_func_client_device_get_nas_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        // Read the key from aes file.
#if defined(__ESP8266X__)
#else
        rval = sample_code_p2p_read_key_from_file_aes(P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
        if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
#endif //defined(__ESP8266X__)
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        {
            // Read the key from txt file.
#if defined(__ESP8266X__)
#else
            rval = sample_code_p2p_read_key_from_file_txt(P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_FILE_TXT, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
#endif //defined(__ESP8266X__)
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                // Use default account as the key
                {
                    const char *lpchannel_account = "HelloChannel";
                    if (strlen(lpchannel_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpchannel_account, strlen(lpchannel_account));
                }
                {
                    const char *lpchannel_password = "channel1234";
                    if (strlen(lpchannel_password) > Apassword_size) break;
                    memcpy(Alppassword, lpchannel_password, strlen(lpchannel_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#if defined(__ESP8266X__)
#else
            rval = sample_code_p2p_write_key_to_file_aes(P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_DIR, P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#endif //defined(__ESP8266X__)
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
            //if (_unlink(P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_FILE_TXT) == 0) {}
#else
#if defined(__ESP8266X__)
#else
            if (unlink(P2P_FUNC_CFG_LOGIN_NAS_CHANNEL_FILE_TXT) == 0) {
                LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            }
#endif //defined(__ESP8266X__)
#endif
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

#endif //defined(ENABLE_P2P_NAS)

#if defined(__ESP8266X__)
#else
#if defined(ENABLE_P2P_CMS)

libpiziot_os_type_func_result_e p2p_func_client_viewer_get_nas_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
        {
            {
                // Use default account as the key
                {
                    const char *lpdevice_account = "HelloKitty";
                    if (strlen(lpdevice_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpdevice_account, strlen(lpdevice_account));
                }
                {
                    const char *lpdevice_password = "kitty1234";
                    if (strlen(lpdevice_password) > Apassword_size) break;
                    memcpy(Alppassword, lpdevice_password, strlen(lpdevice_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
#if 0
    if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS)
    {
        p2p_func_client_print_device_key(Alpaccount, Aaccount_size, Alppassword, Apassword_size);
    }
#endif //0
    return rval;
}

libpiziot_os_type_func_result_e p2p_func_client_viewer_get_nas_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
        {
            {
                // Use default account as the key
                {
                    const char *lpchannel_account = "HelloChannel";
                    if (strlen(lpchannel_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpchannel_account, strlen(lpchannel_account));
                }
                {
                    const char *lpchannel_password = "channel1234";
                    if (strlen(lpchannel_password) > Apassword_size) break;
                    memcpy(Alppassword, lpchannel_password, strlen(lpchannel_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

#endif //defined(ENABLE_P2P_CMS)
#endif //defined(__ESP8266X__)

#if defined(__ESP8266X__)
#else
#if defined(ENABLE_P2P_GSERVER)
#define P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_DIR BASE_SDA1"misc/setting/login"
#define P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_FILE_AES P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_DIR"/gserver_device.aes"
#define P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_FILE_TXT P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_DIR"/gserver_device.txt"

libpiziot_os_type_func_result_e p2p_func_client_device_get_gserver_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        // Read the key from aes file.
        rval = sample_code_p2p_read_key_from_file_aes(P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
        if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        {
            // Read the key from txt file.
            rval = sample_code_p2p_read_key_from_file_txt(P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_FILE_TXT, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                // Use default account as the key
                {
                    const char *lpdevice_account = "HelloKitty";
                    if (strlen(lpdevice_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpdevice_account, strlen(lpdevice_account));
                }
                {
                    const char *lpdevice_password = "kitty1234";
                    if (strlen(lpdevice_password) > Apassword_size) break;
                    memcpy(Alppassword, lpdevice_password, strlen(lpdevice_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            rval = sample_code_p2p_write_key_to_file_aes(P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_DIR, P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
            //if (_unlink(P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_FILE_TXT) == 0) {}
#else
            if (unlink(P2P_FUNC_CFG_LOGIN_GSERVER_DEVICE_FILE_TXT) == 0) {
                LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            }
#endif
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
#if 0
    if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS)
    {
        p2p_func_client_print_device_key(Alpaccount, Aaccount_size, Alppassword, Apassword_size);
    }
#endif //0
    return rval;
}

#define P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_DIR BASE_SDA1"misc/setting/login"
#define P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_FILE_AES P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_DIR"/gserver_channel.aes"
#define P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_FILE_TXT P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_DIR"/gserver_channel.txt"

libpiziot_os_type_func_result_e p2p_func_client_device_get_gserver_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        // Read the key from aes file.
        rval = sample_code_p2p_read_key_from_file_aes(P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
        if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            break;
        }
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        {
            // Read the key from txt file.
            rval = sample_code_p2p_read_key_from_file_txt(P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_FILE_TXT, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                // Use default account as the key
                {
                    const char *lpchannel_account = "HelloChannel";
                    if (strlen(lpchannel_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpchannel_account, strlen(lpchannel_account));
                }
                {
                    const char *lpchannel_password = "channel1234";
                    if (strlen(lpchannel_password) > Apassword_size) break;
                    memcpy(Alppassword, lpchannel_password, strlen(lpchannel_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            rval = sample_code_p2p_write_key_to_file_aes(P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_DIR, P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_FILE_AES, Alpaccount, Aaccount_size, Alppassword, Apassword_size);
            if (rval != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
            //if (_unlink(P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_FILE_TXT) == 0) {}
#else
            if (unlink(P2P_FUNC_CFG_LOGIN_GSERVER_CHANNEL_FILE_TXT) == 0) {
                LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
            }
#endif
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

#endif //defined(ENABLE_P2P_GSERVER)
#endif //defined(__ESP8266X__)

#if defined(__ESP8266X__)
#else
#if defined(ENABLE_P2P_GCLIENT)

libpiziot_os_type_func_result_e p2p_func_client_viewer_get_gserver_device_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
        {
            {
                // Use default account as the key
                {
                    const char *lpdevice_account = "HelloKitty";
                    if (strlen(lpdevice_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpdevice_account, strlen(lpdevice_account));
                }
                {
                    const char *lpdevice_password = "kitty1234";
                    if (strlen(lpdevice_password) > Apassword_size) break;
                    memcpy(Alppassword, lpdevice_password, strlen(lpdevice_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
#if 0
    if (rval == LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS)
    {
        p2p_func_client_print_device_key(Alpaccount, Aaccount_size, Alppassword, Apassword_size);
    }
#endif //0
    return rval;
}

libpiziot_os_type_func_result_e p2p_func_client_viewer_get_gserver_channel_key(const libpiziot_os_aes_key_t *Alpaes_key, unsigned char Alpcbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1], unsigned char *Alpaccount, size_t Aaccount_size, unsigned char *Alppassword, size_t Apassword_size) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
        memset_addr(unsigned char, Alpaccount, 0, Aaccount_size);
        memset_addr(unsigned char, Alppassword, 0, Apassword_size);
        {
            {
                // Use default account as the key
                {
                    const char *lpchannel_account = "HelloChannel";
                    if (strlen(lpchannel_account) > Aaccount_size) break;
                    memcpy(Alpaccount, lpchannel_account, strlen(lpchannel_account));
                }
                {
                    const char *lpchannel_password = "channel1234";
                    if (strlen(lpchannel_password) > Apassword_size) break;
                    memcpy(Alppassword, lpchannel_password, strlen(lpchannel_password));
                }
            }
#if defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Aaccount_size, Alpcbc_iv, Alpaccount, Alpaccount) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
            if (libpiziot_os_aes_cbc_encrypt(Alpaes_key, Apassword_size, Alpcbc_iv, Alppassword, Alppassword) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                break;
            }
#endif //defined(SAMPLE_CODE_P2P_DEVICE_LOGIN_CB)
        }
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

#endif //defined(ENABLE_P2P_GCLIENT)
#endif //defined(__ESP8266X__)

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

#if defined(__ESP8266X__)
#else
#if defined(ENABLE_P2P_IPCAMERA)
#define P2P_FUNC_UID_LENGTH_READ_MAX 27
char lpp2p_func_mtd_ipcamera_uuid[P2P_FUNC_UID_LENGTH_READ_MAX + 1];
#define P2P_FUNC_CFG_IPCAMERA_UUID_DIR BASE_SDA1"misc/setting"
#if defined(ENABLE_P2P_IPCAMERA) && (defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS))
#define P2P_FUNC_CFG_IPCAMERA_UUID_FILE P2P_FUNC_CFG_IPCAMERA_UUID_DIR"/UUID/device_uuid.cfg"
#else
#define P2P_FUNC_CFG_IPCAMERA_UUID_FILE P2P_FUNC_CFG_IPCAMERA_UUID_DIR"/UUID/uuid.cfg"
#endif //defined(ENABLE_P2P_IPCAMERA) && (defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS))
#define P2P_FUNC_UID_LENGTH_MAX 20

char *p2p_func_client_get_ipcamera_uuid_from_mtd(void) {
    char *lpUID = 0;
    FILE *fid = NULL;

    memset_addr(char, lpp2p_func_mtd_ipcamera_uuid, 0, sizeof(lpp2p_func_mtd_ipcamera_uuid));

    do {
        // Open file.
        {
            fid = fopen(P2P_FUNC_CFG_IPCAMERA_UUID_FILE, "rb");
            if (fid == NULL) {
                // Call the LIBPIZIOT SDK to create the UUID directory.
                if (libpiziot_ice_os_file_is_path_exist(P2P_FUNC_CFG_IPCAMERA_UUID_DIR) == LIBPIZIOT_OS_FILE_PATH_NOT_FOUND) {
                    if (libpiziot_ice_os_file_create_child_path(P2P_FUNC_CFG_IPCAMERA_UUID_DIR) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                        break;
                    }
                }
                break;
            }
        }
        {
            // Get read size.
            size_t readSize = 0;
            {
                size_t fileSize = 0;
                // Get file size.
                {
                    if (fseek(fid, 0, SEEK_END) != 0) break;
                    fileSize = ftell(fid);
                }
                // Get read size.
                {
                    readSize = fileSize;
                    if (readSize < 8) break;
                    if (readSize > P2P_FUNC_UID_LENGTH_READ_MAX) readSize = P2P_FUNC_UID_LENGTH_READ_MAX;
                }
            }
            // Read data.
            {
                size_t nSize = 0;
                if (fseek(fid, 0, SEEK_SET) != 0) break;
                nSize = fread(&lpp2p_func_mtd_ipcamera_uuid, sizeof(char), readSize, fid);
                if (nSize != readSize) break;
            }
            // Check data format.
            {
                if (lpp2p_func_mtd_ipcamera_uuid[4] != '=') break;
                if (lpp2p_func_mtd_ipcamera_uuid[5] != '"') break;
                lpUID = lpp2p_func_mtd_ipcamera_uuid + 6;
                lpUID[P2P_FUNC_UID_LENGTH_MAX] = 0;
                {
                    char *pos = strstr(lpUID, "\"");
                    if (pos != 0) {
                        *pos = 0;
                    }
                }
            }
        }
    } while (0);
    // Close file
    if (fid != NULL) {
        if (fclose(fid) != 0) {
            TRACE_ERROR("sample_code_p2p_get_device_uuid_from_mtd fclose(fid) != 0,error !!\n");
        }
        fid = NULL;
    }
    if (lpUID == 0) {
        TRACE_ERROR("%s open,error !!\n", P2P_FUNC_CFG_IPCAMERA_UUID_FILE);
    }
    return lpUID;
}

#endif //defined(ENABLE_P2P_IPCAMERA)
#endif //defined(__ESP8266X__)

#if defined(ENABLE_P2P_NAS)

#if defined(__ESP8266X__)
#else
#define P2P_FUNC_UID_LENGTH_READ_MAX 27
char lpp2p_func_mtd_nas_uuid[P2P_FUNC_UID_LENGTH_READ_MAX + 1];
#define P2P_FUNC_CFG_NAS_UUID_DIR BASE_SDA1"misc/setting"
#if defined(ENABLE_P2P_IPCAMERA) && (defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS))
#define P2P_FUNC_CFG_NAS_UUID_FILE P2P_FUNC_CFG_NAS_UUID_DIR"/UUID/nas_uuid.cfg"
#elif defined(ENABLE_P2P_NAS) && defined(ENABLE_P2P_CMS)
#define P2P_FUNC_CFG_NAS_UUID_FILE P2P_FUNC_CFG_NAS_UUID_DIR"/UUID/nas_uuid.cfg"
#else
#define P2P_FUNC_CFG_NAS_UUID_FILE P2P_FUNC_CFG_NAS_UUID_DIR"/UUID/uuid.cfg"
#endif //defined(ENABLE_P2P_IPCAMERA) && (defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS))
#endif //defined(__ESP8266X__)

#if defined(__ESP8266X__)
#else

char *p2p_func_client_get_nas_uuid_from_mtd(void) {
    char *lpUID = 0;
    FILE *fid = NULL;

    memset_addr(char, lpp2p_func_mtd_nas_uuid, 0, sizeof(lpp2p_func_mtd_nas_uuid));

    do {
        // Open file.
        {
            fid = fopen(P2P_FUNC_CFG_NAS_UUID_FILE, "rb");
            if (fid == NULL) {
                // Call the LIBPIZIOT SDK to create the UUID directory.
                if (libpiziot_ice_os_file_is_path_exist(P2P_FUNC_CFG_NAS_UUID_DIR) == LIBPIZIOT_OS_FILE_PATH_NOT_FOUND) {
                    if (libpiziot_ice_os_file_create_child_path(P2P_FUNC_CFG_NAS_UUID_DIR) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                        break;
                    }
                }
                break;
            }
        }
        {
            // Get read size.
            size_t readSize = 0;
            {
                size_t fileSize = 0;
                // Get file size.
                {
                    if (fseek(fid, 0, SEEK_END) != 0) break;
                    fileSize = ftell(fid);
                }
                // Get read size.
                {
                    readSize = fileSize;
                    if (readSize < 8) break;
                    if (readSize > P2P_FUNC_UID_LENGTH_READ_MAX) readSize = P2P_FUNC_UID_LENGTH_READ_MAX;
                }
            }
            // Read data.
            {
                size_t nSize = 0;
                if (fseek(fid, 0, SEEK_SET) != 0) break;
                nSize = fread(&lpp2p_func_mtd_nas_uuid, sizeof(char), readSize, fid);
                if (nSize != readSize) break;
            }
            // Check data format.
            {
                if (lpp2p_func_mtd_nas_uuid[4] != '=') break;
                if (lpp2p_func_mtd_nas_uuid[5] != '"') break;
                lpUID = lpp2p_func_mtd_nas_uuid + 6;
                lpUID[P2P_FUNC_UID_LENGTH_MAX] = 0;
                {
                    char *pos = strstr(lpUID, "\"");
                    if (pos != 0) {
                        *pos = 0;
                    }
                }
            }
        }
    } while (0);
    // Close file
    if (fid != NULL) {
        if (fclose(fid) != 0) {
            TRACE_ERROR("sample_code_p2p_get_uuid_from_mtd fclose(fid) != 0,error !!\n");
        }
        fid = NULL;
    }
    if (lpUID == 0) {
        TRACE_ERROR("%s open,error !!\n", P2P_FUNC_CFG_NAS_UUID_FILE);
    }
    return lpUID;
}

#endif //defined(__ESP8266X__)

#endif //defined(ENABLE_P2P_NAS)

#if defined(__ESP8266X__)
#else
#if defined(ENABLE_P2P_GSERVER)
#define P2P_FUNC_UID_LENGTH_READ_MAX 27
char lpp2p_func_mtd_gserver_uuid[P2P_FUNC_UID_LENGTH_READ_MAX + 1];
#define P2P_FUNC_CFG_GSERVER_UUID_DIR BASE_SDA1"misc/setting"
#if defined(ENABLE_P2P_GSERVER) && defined(ENABLE_P2P_GCLIENT)
#define P2P_FUNC_CFG_GSERVER_UUID_FILE P2P_FUNC_CFG_GSERVER_UUID_DIR"/UUID/gserver_uuid.cfg"
#else
#define P2P_FUNC_CFG_GSERVER_UUID_FILE P2P_FUNC_CFG_GSERVER_UUID_DIR"/UUID/uuid.cfg"
#endif //defined(ENABLE_P2P_GSERVER)) && defined(ENABLE_P2P_CLIENT))

char *p2p_func_client_get_gserver_uuid_from_mtd(void) {
    char *lpUID = 0;
    FILE *fid = NULL;

    memset_addr(char, lpp2p_func_mtd_gserver_uuid, 0, sizeof(lpp2p_func_mtd_gserver_uuid));

    do {
        // Open file.
        {
            fid = fopen(P2P_FUNC_CFG_GSERVER_UUID_FILE, "rb");
            if (fid == NULL) {
                // Call the LIBPIZIOT SDK to create the UUID directory.
                if (libpiziot_ice_os_file_is_path_exist(P2P_FUNC_CFG_GSERVER_UUID_DIR) == LIBPIZIOT_OS_FILE_PATH_NOT_FOUND) {
                    if (libpiziot_ice_os_file_create_child_path(P2P_FUNC_CFG_GSERVER_UUID_DIR) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                        break;
                    }
                }
                break;
            }
        }
        {
            // Get read size.
            size_t readSize = 0;
            {
                int32_t fileSize = 0;
                // Get file size.
                {
                    if (fseek(fid, 0, SEEK_END) != 0) break;
                    fileSize = ftell(fid);
                }
                // Get read size.
                {
                    readSize = fileSize;
                    if (readSize < 8) break;
                    if (readSize > P2P_FUNC_UID_LENGTH_READ_MAX) readSize = P2P_FUNC_UID_LENGTH_READ_MAX;
                }
            }
            // Read data.
            {
                size_t nSize = 0;
                if (fseek(fid, 0, SEEK_SET) != 0) break;
                nSize = fread(&lpp2p_func_mtd_gserver_uuid, sizeof(char), readSize, fid);
                if (nSize != readSize) break;
            }
            // Check data format.
            {
                if (lpp2p_func_mtd_gserver_uuid[4] != '=') break;
                if (lpp2p_func_mtd_gserver_uuid[5] != '"') break;
                lpUID = lpp2p_func_mtd_gserver_uuid + 6;
                lpUID[P2P_FUNC_UID_LENGTH_MAX] = 0;
                {
                    char *pos = strstr(lpUID, "\"");
                    if (pos != 0) {
                        *pos = 0;
                    }
                }
            }
        }
    } while (0);
    // Close file
    if (fid != NULL) {
        if (fclose(fid) != 0) {
            TRACE_ERROR("sample_code_p2p_get_uuid_from_mtd fclose(fid) != 0,error !!\n");
        }
        fid = NULL;
    }
    if (lpUID == 0) {
        TRACE_ERROR("%s open,error !!\n", P2P_FUNC_CFG_GSERVER_UUID_FILE);
    }
    return lpUID;
}

#endif //defined(ENABLE_P2P_GSERVER)
#endif //defined(__ESP8266X__)

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)
#define P2P_FUNC_MAC_LENGTH_MAX 17
char lpp2p_func_mac[P2P_FUNC_MAC_LENGTH_MAX + 1];

#if defined(__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8197__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3520D__)
#elif defined(ENABLE_CONFIG_APPLE_BOX007)
#else

char *p2p_func_client_p2p_get_device_mac_address(void) {
    FILE *fd = NULL;
    char *lpMAC = 0;
    memset_addr(char, lpp2p_func_mac, 0, sizeof(lpp2p_func_mac));

    do {
        char line[256];
#if defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518E__)
        fd = popen("ifconfig eth0 | grep HWaddr | awk -F'HWaddr ' '{print $2}'", "r");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518EV2__)
        fd = popen("ifconfig eth0 | grep HWaddr | awk -F'HWaddr ' '{print $2}'", "r");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_BCM28XX_RASPBERRY__)
        fd = popen("cat /sys/class/net/eth0/address", "r");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8881__)
        fd = popen("ifconfig eth1 | grep HWaddr | awk -F'HWaddr ' '{print $2}'", "r");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8196__)
        fd = popen("ifconfig eth1 | grep HWaddr | awk -F'HWaddr ' '{print $2}'", "r");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RK3328_ROCK64__)
        fd = popen("/sbin/ifconfig eth0 | grep HWaddr | awk -F'HWaddr ' '{print $2}'", "r");
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_MT7688_LINKIT__)
        fd = popen("ifconfig apcli0 | grep HWaddr | awk -F'HWaddr ' '{print $2}'", "r");
#else
#error
#endif
        if (fd == NULL) {
            TRACEA("ifconfig unknown UID\n");
            break;
        }
        while (fgets(line, sizeof(line), fd)) {
            size_t len = strlen(line);
            if (len < 17) continue;
            if (line[2] != ':') continue;
            if (line[5] != ':') continue;
            if (line[8] != ':') continue;
            if (line[11] != ':') continue;
            if (line[14] != ':') continue;
            line[17] = 0;
            memcpy(lpp2p_func_mac, line, 17);
            lpMAC = lpp2p_func_mac;
            break;
        }
    } while (0);
    if (fd != NULL) {
#if defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518E__)
        pclose(fd);
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518EV2__)
        pclose(fd);
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8881__)
        pclose(fd);
#else
        LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);
#endif
    }
    return lpMAC;
}

#endif

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

libpiziot_os_type_func_result_e p2p_func_client_start_thread(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)
#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
        if (p2p_func_client_lan_server_start_thread() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)
#if defined(ENABLE_P2P_IPCAMERA)
        p2p_ipcamera_main_start_thread();
#endif //defined(ENABLE_P2P_IPCAMERA)
#if defined(ENABLE_P2P_NAS)
        p2p_nas_main_start_thread();
#endif //defined(ENABLE_P2P_NAS)
#if defined(ENABLE_P2P_CMS)
        p2p_cms_main_start_thread();
#endif //defined(ENABLE_P2P_CMS)
#if defined(ENABLE_P2P_GSERVER)
        p2p_gserver_main_start_thread();
#endif //defined(ENABLE_P2P_GSERVER)
#if defined(ENABLE_P2P_GCLIENT)
        p2p_gclient_main_start_thread();
#endif //defined(ENABLE_P2P_GCLIENT)
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

libpiziot_os_type_func_result_e p2p_func_client_stop_thread(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
#if defined(ENABLE_P2P_GCLIENT)
        p2p_gclient_main_stop_thread();
#endif //defined(ENABLE_P2P_GCLIENT)
#if defined(ENABLE_P2P_GSERVER)
        p2p_gserver_main_stop_thread();
#endif //defined(ENABLE_P2P_GSERVER)
#if defined(ENABLE_P2P_CMS)
        p2p_cms_main_stop_thread();
#endif //defined(ENABLE_P2P_CMS)
#if defined(ENABLE_P2P_NAS)
        p2p_nas_main_stop_thread();
#endif //defined(ENABLE_P2P_NAS)
#if defined(ENABLE_P2P_IPCAMERA)
        p2p_ipcamera_main_stop_thread();
#endif //defined(ENABLE_P2P_IPCAMERA)
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)
#if defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
        p2p_func_client_lan_server_stop_thread();
#endif //defined(LIBPIZIOT_P2P_COMMON_ENABLE_LAN_MODE)
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_GSERVER)
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)

p2p_func_client_channel_enable_e p2p_function_client_channel_check_enable(p2p_func_client_channel_enable_flag_t *Alpchannel_enable) {
    p2p_func_client_channel_enable_e mode = P2P_FUNC_CLIENT_CHANNEL_ENABLE_NOTHING;
    if (Alpchannel_enable->current != Alpchannel_enable->enable) {
        Alpchannel_enable->current = Alpchannel_enable->enable;
        mode = Alpchannel_enable->current;
    }
    return mode;
}

libpiziot_os_type_func_result_e p2p_func_client_initialize(void) {
    libpiziot_os_type_func_result_e rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
    do {
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
        p2p_protocol_ipcamera_command_init_data_max_size();
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#if defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
        p2p_protocol_nas_command_init_data_max_size();
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //efined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#if defined(ENABLE_P2P_IPCAMERA)
        if (p2p_ipcamera_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_P2P_IPCAMERA)
#if defined(ENABLE_P2P_NAS)
        if (p2p_nas_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_P2P_NAS)
#if defined(ENABLE_P2P_CMS)
        if (p2p_cms_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_P2P_CMS)
#if defined(ENABLE_P2P_GSERVER)
        if (p2p_gserver_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_P2P_GSERVER)
#if defined(ENABLE_P2P_GCLIENT)
        if (p2p_gclient_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
#endif //defined(ENABLE_P2P_GCLIENT)
        rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
    } while (0);
    return rval;
}

void p2p_func_client_finalize(void) {
#if defined(ENABLE_P2P_GCLIENT)
    p2p_gclient_main_finalize();
#endif //defined(ENABLE_P2P_GCLIENT)
#if defined(ENABLE_P2P_GSERVER)
    p2p_gserver_main_finalize();
#endif //defined(ENABLE_P2P_GSERVER)
#if defined(ENABLE_P2P_CMS)
    p2p_cms_main_finalize();
#endif //defined(ENABLE_P2P_CMS)
#if defined(ENABLE_P2P_NAS)
    p2p_nas_main_finalize();
#endif //defined(ENABLE_P2P_NAS)
#if defined(ENABLE_P2P_IPCAMERA)
    p2p_ipcamera_main_finalize();
#endif //defined(ENABLE_P2P_IPCAMERA)
}

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_GSERVER) || defined(ENABLE_P2P_GCLIENT)
