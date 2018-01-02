#ifndef __DEF_LIBPIZIOT_OS_AES_H__
#define __DEF_LIBPIZIOT_OS_AES_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "def_libpiziot_os_platform.h"

#include "def_libpiziot_os_type.h"

#define LIBPIZIOT_OS_AES_INT32T_COUNT 68
#define LIBPIZIOT_OS_AES_RCON_SIZE 10

typedef struct libpiziot_os_aes_key_enc_s {
    unsigned char ENC_FSb[256];
    uint32_t ENC_FT0[256];
    uint32_t ENC_FT1[256];
    uint32_t ENC_FT2[256];
    uint32_t ENC_FT3[256];
    uint32_t ENC_RCON[LIBPIZIOT_OS_AES_RCON_SIZE];
    int ENC_nr;
    uint32_t *ENC_rk;
    uint32_t ENC_buf[LIBPIZIOT_OS_AES_INT32T_COUNT + 1];
} libpiziot_os_aes_key_enc_t;

typedef struct libpiziot_os_aes_key_dec_s {
    unsigned char DEC_RSb[256];
    uint32_t DEC_RT0[256];
    uint32_t DEC_RT1[256];
    uint32_t DEC_RT2[256];
    uint32_t DEC_RT3[256];
    uint32_t DEC_RCON[LIBPIZIOT_OS_AES_RCON_SIZE];
    int DEC_nr;
    uint32_t *DEC_rk;
    uint32_t DEC_buf[LIBPIZIOT_OS_AES_INT32T_COUNT + 1];
} libpiziot_os_aes_key_dec_t;

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#define LIBPIZIOT_OS_AES_RUNTIME
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

typedef struct libpiziot_aes_key_s {
#if defined(LIBPIZIOT_OS_AES_RUNTIME)
    unsigned char gen_key[32];
    uint32_t keybits;
#endif //defined(LIBPIZIOT_OS_AES_RUNTIME)
    libpiziot_os_aes_key_enc_t *lpenc_key;
    libpiziot_os_aes_key_dec_t *lpdec_key;
} libpiziot_os_aes_key_t;

#define LIBPIZIOT_OS_AES_GEN_STR_LEN 32

typedef struct libpiziot_aes_ecb_s {
    libpiziot_os_aes_key_t aes_key;
    unsigned char gen_str[LIBPIZIOT_OS_AES_GEN_STR_LEN + 1];
} libpiziot_os_aes_ecb_t;

#define LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN 16

typedef struct libpiziot_aes_cbc_s {
    libpiziot_os_aes_key_t aes_key;
    unsigned char cbc_iv[LIBPIZIOT_AES_CBC_IV_GEN_STR_LEN + 1];
    unsigned char gen_str[LIBPIZIOT_OS_AES_GEN_STR_LEN + 1];
} libpiziot_os_aes_cbc_t;

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_AES_H__
