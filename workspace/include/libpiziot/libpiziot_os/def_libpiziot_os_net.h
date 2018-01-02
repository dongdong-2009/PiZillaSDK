#ifndef __DEF_LIBPIZIOT_OS_NET_H__
#define __DEF_LIBPIZIOT_OS_NET_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#include "def_libpiziot_os_platform.h"

#include "def_libpiziot_os_type.h"
#include "def_libpiziot_os_socket.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if !defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    extern char *libpiziot_os_net_ntop_host(const struct sockaddr *sa, socklen_t salen, char *str, socklen_t len);
#endif //!defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_NET_H__
