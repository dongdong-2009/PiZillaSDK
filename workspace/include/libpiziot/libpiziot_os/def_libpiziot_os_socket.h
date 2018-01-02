#ifndef __DEF_LIBPIZIOT_OS_SOCKET_H__
#define __DEF_LIBPIZIOT_OS_SOCKET_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#include "def_libpiziot_os_type.h"
#include "def_libpiziot_os_time.h"

#include "def_libpiziot_os_resource.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#elif defined(__LIBPIZIOT_OS_FREERTOS__)
#include <freertos/FreeRTOS.h>
//#include "lwipopts.h"
//#include "lwip/ip_addr.h"
#include "lwip/lwip/sockets.h" //socklen_t
#include "lwip/lwip/netdb.h" //addrinfo
#else

#include <netinet/in.h> //sockaddr_in
#include <arpa/inet.h> //socklen_t
#include <netdb.h> //addrinfo

//#include <wchar.h>

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#include "def_libpiziot_os_socket.h"
//#include "def_libpiziot_os_pthread.h"

//Define Windows Library

//#if defined(__PRAGMAPACK__)
//#error
//#else
//#define __PRAGMAPACK__
//#pragma pack(push,4)
//#endif //defined(__PRAGMAPACK__)
//
//typedef struct libpiziot_ice_net_in_addr_s
//{
// union
// {
// unsigned long S_addr;
// struct { unsigned char s_b1, s_b2, s_b3, s_b4; } S_un_b;
// struct { unsigned short s_w1, s_w2; } S_un_w;
// };
//}libpiziot_ice_net_in_addr_t, *libpiziot_ice_net_in_addr_p, *libpiziot_ice_net_in_addr_lp;
//
//#if !defined(__PRAGMAPACK__)
//#error
//#else
//#pragma pack(pop)
//#undef __PRAGMAPACK__
//#endif //!defined(__PRAGMAPACK__)

//#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
//#define s_addr S_un.S_addr /* can be used for most tcp & ip code */
//#define s_host S_un.S_un_b.s_b2 // host on imp
//#define s_net S_un.S_un_b.s_b1 // network
//#define s_imp S_un.S_un_w.s_w2 // imp
//#define s_impno S_un.S_un_b.s_b4 // imp #
//#define s_lh S_un.S_un_b.s_b3 // logical host
//#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

//typedef struct libpiziot_ice_net_sockaddr_in_s
//{
//#if(_WIN32_WINNT < 0x0600)
// short sin_family;
//#else//(_WIN32_WINNT < 0x0600)
// unsigned short sin_family;
//#endif //(_WIN32_WINNT < 0x0600)
//
// unsigned short sin_port;
// libpiziot_ice_net_in_addr_t sin_addr;
// char sin_zero[8];
//}libpiziot_ice_net_sockaddr_in_t, *libpiziot_ice_net_sockaddr_in_p;

#define LIBPIZIOT_ENABLE_OS_SOCKET

#if defined(LIBPIZIOT_ENABLE_OS_SOCKET)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
//#define LIBPIZIOT_OS_SOCKET_ENABLE_CHECK_FREE_COUNT
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define libpiziot_os_socket_open(x,y,z) libpiziot_os_socket_user_open(x,y,z, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_socket_close(x) libpiziot_os_socket_user_close(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_socket_accept(x,y,z) libpiziot_os_socket_user_accept(x,y,z, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_socket_read(x,y,z) _read(x,y,z)
#define libpiziot_os_socket_write(x,y,z) _write(x,y,z)
#elif defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#define libpiziot_os_socket_open(x,y,z) libpiziot_os_socket_user_open(x,y,z, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_socket_close(x) libpiziot_os_socket_user_close(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_socket_accept(x,y,z) libpiziot_os_socket_user_accept(x,y,z, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_socket_read(x,y,z) read(x,y,z)
#define libpiziot_os_socket_write(x,y,z) write(x,y,z)
#else
#define libpiziot_os_socket_open(x, y, z) libpiziot_os_socket_user_open(x,y,z, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_socket_close(x) libpiziot_os_socket_user_close(x, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_socket_accept(x, y, z) libpiziot_os_socket_user_accept(x,y,z, LIBPIZIOT_OS__FUNCTION__, __LINE__)
#define libpiziot_os_socket_read(x, y, z) read(x,y,z)
#define libpiziot_os_socket_write(x, y, z) write(x,y,z)
#endif

#else

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#define libpiziot_os_socket_open(x,y,z) socket(x,y,z)
#define libpiziot_os_socket_close(x) closesocket(x)
#define libpiziot_os_socket_accept(x,y,z) accept(x,y,z)
#define libpiziot_os_socket_read(x,y,z) _read(x,y,z)
#define libpiziot_os_socket_write(x,y,z) _write(x,y,z)
#elif defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#define libpiziot_os_socket_open(x,y,z) socket(x,y,z)
#define libpiziot_os_socket_close(x) close(x)
#define libpiziot_os_socket_accept(x,y,z) accept(x,y,z)
#define libpiziot_os_socket_read(x,y,z) read(x,y,z)
#define libpiziot_os_socket_write(x,y,z) write(x,y,z)
#else
#define libpiziot_os_socket_open(x,y,z) socket(x,y,z)
#define libpiziot_os_socket_close(x) close(x)
#define libpiziot_os_socket_accept(x,y,z) accept(x,y,z)
#define libpiziot_os_socket_read(x,y,z) read(x,y,z)
#define libpiziot_os_socket_write(x,y,z) write(x,y,z)
#endif
#endif //defined(LIBPIZIOT_ENABLE_OS_SOCKET)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#else
//#define PSOCKADDR struct sockaddr*
//#define SOCKADDR_IN struct sockaddr_in
//#define IN_ADDR struct in_addr

//#define LPHOSTENT struct hostent*
//typedef void* (*USER_START_ROUTINE)(void *arg);
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

typedef SOCKET(*libpiziot_net_socket_utils_tcp_listen_p)(uint16_t port);

typedef SOCKET(*libpiziot_net_socket_utils_tcp_accept_p)(SOCKET fd);

typedef int32_t(*libpiziot_net_socket_utils_socket_close_p)(SOCKET s);

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(LIBPIZIOT_OS_SOCKET_ENABLE_CHECK_FREE_COUNT)
    extern int32_t libpiziot_os_socket_plock_remain(void);
#endif //defined(LIBPIZIOT_OS_SOCKET_ENABLE_CHECK_FREE_COUNT)

#if defined(LIBPIZIOT_ENABLE_OS_SOCKET)
    extern SOCKET libpiziot_os_socket_user_open(int32_t af, int32_t type, int32_t protocol, const char *Alpfunc_name, int32_t Aifunc_line);
    extern int32_t libpiziot_os_socket_user_close(SOCKET s_close, const char *Alpfunc_name, int32_t Aifunc_line);
    extern SOCKET libpiziot_os_socket_user_accept(SOCKET s_listen, struct sockaddr *Alpremoteaddr, socklen_t *Alpsocketlen, const char *Alpfunc_name, int32_t Aifunc_line);
    extern void libpiziot_os_socket_report_leaks(void);
#endif //defined(LIBPIZIOT_ENABLE_OS_SOCKET)
    extern int32_t libpiziot_os_socket_tcp_read(SOCKET Asockfd, unsigned char *AlpSockBuffer, uint32_t dwCount, struct timeval *Alptv);
    extern int32_t libpiziot_os_socket_tcp_write(SOCKET Asockfd, unsigned char *AlpSockBuffer, uint32_t dwCount, struct timeval *Alptv);

    extern SOCKET libpiziot_os_net_socket_utils_tcp_listen(uint16_t port);
    extern SOCKET libpiziot_os_net_socket_utils_tcp_accept(SOCKET fd);
    extern int32_t libpiziot_os_net_socket_utils_socket_close(SOCKET s);

#if 0
    extern int socket_utils_tcp_read(int fd, void *buffer, int nbytes, struct sockaddr_in* Addr);
    extern int socket_utils_tcp_write(int connectSocketId, char *dataBuf, int dataSize);
    extern SOCKET socket_utils_tcp_connect(uint16_t port, char *addr);
#endif //0

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_SOCKET_H__
