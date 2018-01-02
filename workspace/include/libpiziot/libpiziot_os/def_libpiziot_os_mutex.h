#ifndef __DEF_LIBPIZIOT_OS_MUTEX_H__
#define __DEF_LIBPIZIOT_OS_MUTEX_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#include "def_libpiziot_os_type.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#elif defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#include <pthread.h>
#elif defined(__LIBPIZIOT_OS_FREERTOS__)
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#elif defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__)
#include <pthread.h>
#else
#include <pthread.h>
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__) || defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)

#define LIBPIZIOT_OS_MUTEX_STUCT_INIT_CHECK_VALUE 0x1234

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define pthread_mutex_t void*
#define pthread_mutexattr_t int
#define pthread_rwlock_t void*
#define pthread_rwlockattr_t int
#elif defined(__LIBPIZIOT_OS_FREERTOS__)
#define pthread_mutex_t xSemaphoreHandle 
#define pthread_mutexattr_t int
//#define pthread_rwlock_t void*
//#define pthread_rwlockattr_t int
#endif

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else
#define PTHREAD_MUTEX_LIST_CHECK_LEAK

#if defined(PTHREAD_MUTEX_LIST_CHECK_LEAK)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
//#define LIBPIZIOT_OS_MUTEX_ENABLE_CHECK_FREE_COUNT
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define __CHECK_DUPLCATE_MUTEX_LOCK_P2P_DEVICE_HANDLER__
#define __CHECK_DUPLCATE_MUTEX_LOCK_P2P_RELAY_HANDLER__
#define __CHECK_DUPLCATE_MUTEX_LOCK_P2P_VIEWER_HANDLER__
#define __CHECK_DUPLCATE_MUTEX_LOCK_P2P_SERVER_HANDLER__
#define __CHECK_DUPLCATE_MUTEX_LOCK_P2P_LAN_SERVER_HANDLER__
#define __CHECK_DUPLCATE_MUTEX_LOCK_P2P_CHANNEL_SERVER_MONITOR__
#define __CHECK_DUPLCATE_MUTEX_LOCK_P2P_CHANNEL_SERVER_HANDLER__
#define __CHECK_DUPLCATE_MUTEX_LOCK_P2P_CHANNEL_CLIENT_HANDLER__
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#endif //defined(PTHREAD_MUTEX_LIST_CHECK_LEAK)

//#define __LIBPIZIOT_OS_MUTEX_CHECK_DEAD_LOCK__

#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

struct libpiziot_os_mutex_struct_plock_s {
    int32_t init;
    int32_t lock;
#if defined(__LIBPIZIOT_OS_MUTEX_CHECK_DEAD_LOCK__)
    char* lpChar;
    int32_t line;
    int32_t cnt;
#endif //defined(__LIBPIZIOT_OS_MUTEX_CHECK_DEAD_LOCK__)
#if defined(PTHREAD_MUTEX_LIST_CHECK_LEAK)
    int32_t mutex_id;
#endif //defined(PTHREAD_MUTEX_LIST_CHECK_LEAK)

#if defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_DEVICE_HANDLER__)
    int32_t duplicate_p2p_device_handler;
#endif //defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_DEVICE_HANDLER__)
#if defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_RELAY_HANDLER__)
    int32_t duplicate_p2p_relay_handler;
#endif //defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_RELAY_HANDLER__)
#if defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_VIEWER_HANDLER__)
    int32_t duplicate_p2p_viewer_handler;
#endif //defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_VIEWER_HANDLER__)
#if defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_SERVER_HANDLER__)
    int32_t duplicate_p2p_server_handler;
#endif //defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_SERVER_HANDLER__)
#if defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_LAN_SERVER_HANDLER__)
    int32_t duplicate_p2p_lan_server_handler;
#endif //defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_LAN_SERVER_HANDLER__)
#if defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_CHANNEL_SERVER_MONITOR__)
    int32_t duplicate_p2p_channel_server_monitor;
#endif //defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_CHANNEL_SERVER_MONITOR__)
#if defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_CHANNEL_SERVER_HANDLER__)
    int32_t duplicate_p2p_channel_server_handler;
#endif //defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_CHANNEL_SERVER_HANDLER__)
#if defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_CHANNEL_CLIENT_HANDLER__)
    int32_t duplicate_p2p_channel_client_handler;
#endif //defined(__CHECK_DUPLCATE_MUTEX_LOCK_P2P_CHANNEL_CLIENT_HANDLER__)

    pthread_mutex_t __mutex;
};

typedef struct libpiziot_os_mutex_struct_plock_s libpiziot_os_mutex_struct_plock_t;

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else

struct libpiziot_os_mutex_struct_rwlock_s {
    int32_t init;
    pthread_rwlock_t __rwlock;
};
typedef struct libpiziot_os_mutex_struct_rwlock_s libpiziot_os_mutex_struct_rwlock_t;

#define spinlock_t libpiziot_os_mutex_struct_plock_t
#define spin_lock_init(x) libpiziot_os_mutex_struct_plock_init(x,0, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define spin_unlock_irqrestore(x, y) libpiziot_os_mutex_struct_plock_unlock(x)
#define spin_lock_destroy(x) libpiziot_os_mutex_struct_plock_free(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)

#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#define libpiziot_os_mutex_plock_init(x, y) libpiziot_os_mutex_struct_plock_init(x,y, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_mutex_plock_init_func_line(x, y, func_name, func_line) libpiziot_os_mutex_struct_plock_init(x,y,func_name,func_line)
#define libpiziot_os_mutex_plock_free(x) libpiziot_os_mutex_struct_plock_free(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)

#if defined(__LIBPIZIOT_OS_MUTEX_CHECK_DEAD_LOCK__)
#define libpiziot_os_mutex_plock_lock(x) libpiziot_os_mutex_struct_plock_xlock(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#else
#define libpiziot_os_mutex_plock_lock(x) libpiziot_os_mutex_struct_plock_lock(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#endif //defined(__LIBPIZIOT_OS_MUTEX_CHECK_DEAD_LOCK__)

#define libpiziot_os_mutex_plock_unlock libpiziot_os_mutex_struct_plock_unlock

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else
#define libpiziot_os_mutex_rwlock_init libpiziot_os_mutex_struct_rwlock_init
#define libpiziot_os_mutex_rwlock_free libpiziot_os_mutex_struct_rwlock_free
#define libpiziot_os_mutex_rwlock_wrlock libpiziot_os_mutex_struct_rwlock_wrlock
#define libpiziot_os_mutex_rwlock_unlock libpiziot_os_mutex_struct_rwlock_unlock
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#ifdef __cplusplus
extern "C"
{
#endif

    extern int libpiziot_os_mutex_struct_plock_init(libpiziot_os_mutex_struct_plock_t *Alpstruct_plock, const pthread_mutexattr_t *Aattr, const char *Alpfunc_name, int32_t Aifunc_line);
    extern int libpiziot_os_mutex_struct_plock_free(libpiziot_os_mutex_struct_plock_t *Alpstruct_plock, const char *Alpfunc_name, int32_t Aifunc_line);
#if defined(PTHREAD_MUTEX_LIST_CHECK_LEAK)
    extern void libpiziot_os_mutex_struct_plock_remain(void);
#endif //defined(PTHREAD_MUTEX_LIST_CHECK_LEAK)
#if defined(__LIBPIZIOT_OS_MUTEX_CHECK_DEAD_LOCK__)
    extern int libpiziot_os_mutex_struct_plock_xlock(libpiziot_os_mutex_struct_plock_t* Alpstruct_plock, const char* Alpfunc_name, int32_t Aifunc_line);
#define spin_lock_irqsave(x,y) libpiziot_os_mutex_struct_plock_xlock(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#else
    extern int libpiziot_os_mutex_struct_plock_lock(libpiziot_os_mutex_struct_plock_t *Alpstruct_plock, const char *Alpfunc_name, int32_t Aifunc_line);
#define spin_lock_irqsave(x, y) libpiziot_os_mutex_struct_plock_lock(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#endif //defined(__LIBPIZIOT_OS_MUTEX_CHECK_DEAD_LOCK__)
    extern int libpiziot_os_mutex_struct_plock_unlock(libpiziot_os_mutex_struct_plock_t *Alpstruct_plock);

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else
    extern int libpiziot_os_mutex_struct_rwlock_init(libpiziot_os_mutex_struct_rwlock_t *Alibpiziot_os_mutex_user_rwlock_struct, const pthread_rwlockattr_t *Aattr);
    extern int libpiziot_os_mutex_struct_rwlock_free(libpiziot_os_mutex_struct_rwlock_t *Alibpiziot_os_mutex_user_rwlock_struct);
    extern int libpiziot_os_mutex_struct_rwlock_wrlock(libpiziot_os_mutex_struct_rwlock_t *Alibpiziot_os_mutex_user_rwlock_struct);
    extern int libpiziot_os_mutex_struct_rwlock_unlock(libpiziot_os_mutex_struct_rwlock_t *Alibpiziot_os_mutex_user_rwlock_struct);
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#if defined(PTHREAD_MUTEX_LIST_CHECK_LEAK)
    extern void libpiziot_os_mutex_report_leaks(void);
#endif //defined(PTHREAD_MUTEX_LIST_CHECK_LEAK)

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_MUTEX_H__
