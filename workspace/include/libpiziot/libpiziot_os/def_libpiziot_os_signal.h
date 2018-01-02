#ifndef __DEF_LIBPIZIOT_OS_SIGNAL_H__
#define __DEF_LIBPIZIOT_OS_SIGNAL_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#include "def_libpiziot_os_type.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#define SIGHUP 1
#define SIGINT 2
#define SIGQUIT 3
#define SIGILL 4
#define SIGTRAP 5
#define SIGABRT 6
#define SIGPIZIOT 6
#define SIGBUS 7
#define SIGFPE 8
#define SIGKILL 9
#define SIGUSR1 10
#define SIGSEGV 11
#define SIGUSR2 12
#define SIGPIPE 13
#define SIGALRM 14
#define SIGTERM 15
#define SIGSTKFLT 16
#define SIGCHLD 17
#define SIGCONT 18
#define SIGSTOP 19
#define SIGTSTP 20
#define SIGTTIN 21
#define SIGTTOU 22
#define SIGURG 23
#define SIGXCPU 24
#define SIGXFSZ 25
#define SIGVTALRM 26
#define SIGPROF 27
#define SIGWINCH 28
#define SIGIO 29
#define SIGPOLL SIGIO
/*
#define SIGLOST 29
*/
#define SIGPWR 30
#define SIGSYS 31
#define SIGUNUSED 31

#define SIGRTMIN 32
#define SIGRTMAX _NSIG

#define SIGSWI 32

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#ifdef __cplusplus
extern "C"
{
#endif

    extern uint32_t libpiziot_os_signal_siginit_flag;

    extern void libpiziot_os_signal_set_terminate_flag(void);
    extern uint32_t libpiziot_os_signal_get_terminate_flag(void);

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_SIGNAL_H__
