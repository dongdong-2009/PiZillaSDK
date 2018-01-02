#ifndef __DEF_LIBPIZIOT_OS_FIFO_H__
#define __DEF_LIBPIZIOT_OS_FIFO_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#include "def_libpiziot_os_type.h"
#include "def_libpiziot_os_mutex.h"

#define LIBPIZIOT_OS_FIFO_BUFFER_LOCK 0
#define LIBPIZIOT_OS_FIFO_BUFFER_IGNORE_LOCK 1

typedef struct libpiziot_os_fifo_buffer_info_s {
    unsigned char *m_pRB;
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
    char* lpFromFuncName;
    int32_t FromFuncLine;
#endif //#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
    int32_t m_ulSize;
    int32_t m_ulReadPos;
    int32_t m_ulTempReadPos;
    int32_t m_ulWritePos;
    int32_t m_ulTempWritePos;
    libpiziot_os_mutex_struct_plock_t fifo_mutex;
    libpiziot_os_mutex_struct_plock_t fifo_disable_destroy;
    void *m_extra;
    unsigned char *lppipe_buffer;
    int32_t pipe_buffer_size;
} libpiziot_os_fifo_buffer_info_t;

typedef struct libpiziot_os_fifo_buffer_head_s {
    uint32_t headmark;
    int32_t bs_length;
} libpiziot_os_fifo_buffer_head_t;

#ifdef __cplusplus
extern "C"
{
#endif

    int32_t libpiziot_os_fifo_mutex_init(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, char *AlpFnucName, int32_t ALine);
    int32_t libpiziot_os_fifo_free_mutex(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, char *AlpFnucName, int32_t ALine);
    extern int32_t libpiziot_os_fifo_buffer_initialize(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, unsigned char *Alppipe_buffer, uint32_t AiBufferSize, char *AlpFnucName, int32_t ALine);
    extern int32_t libpiziot_os_fifo_buffer_finalize(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, char *AlpFnucName, int32_t ALine);
    extern int32_t libpiziot_os_fifo_buffer_get_buffer_size(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, uint32_t AIgnoreLock);
    extern int32_t libpiziot_os_fifo_buffer_get_max_write_size(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, uint32_t AIgnoreLock);
    //extern int32_t libpiziot_os_fifo_buffer_get_max_end_size(libpiziot_os_fifo_buffer_info_t* AFIFO_buffer,int32_t ulLen,uint32_t AIgnoreLock);
    extern int32_t libpiziot_os_fifo_buffer_get_max_read_size(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, uint32_t AIgnoreLock);
    extern void libpiziot_os_fifo_buffer_clean(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, uint32_t AIgnoreLock);
    extern int32_t libpiziot_os_fifo_buffer_write(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, char *pData, int32_t ulLen, uint32_t AIgnoreLock);
    extern int32_t libpiziot_os_fifo_buffer_read(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, char *pData, int32_t ulLen, uint32_t AIgnoreLock);
    extern int32_t libpiziot_os_fifo_buffer_get(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, char *pData, int32_t ulLen, uint32_t AIgnoreLock);
    extern void libpiziot_os_fifo_buffer_write_align(libpiziot_os_fifo_buffer_info_t *AlpFIFO_buffer, char *Alpdata, int32_t Adata_len);
    extern int32_t libpiziot_os_fifo_buffer_read_align(libpiziot_os_fifo_buffer_info_t *AlpFIFO_buffer, char *Alpdata, int32_t Abuffer_size);

    typedef int32_t(*libpiziot_os_fifo_buffer_callback_read_routine_p)(void *AlpTargetData, unsigned char *AlpBufferFirstChunk, int32_t ulFirstChunkSize, unsigned char *AlpBufferSecondChunk, int32_t ulSecondChunkSize);
    extern int32_t libpiziot_os_fifo_buffer_callback_read(libpiziot_os_fifo_buffer_info_t *AFIFO_buffer, libpiziot_os_fifo_buffer_callback_read_routine_p AlpFIFO_buffer_callback_getRoutine, void *AlpTargetData, int32_t ulLen);

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_FIFO_H__
