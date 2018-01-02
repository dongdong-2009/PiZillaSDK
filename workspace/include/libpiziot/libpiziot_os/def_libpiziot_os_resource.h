#ifndef __DEF_LIBPIZIOT_OS_RESOURCE_H__
#define __DEF_LIBPIZIOT_OS_RESOURCE_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//The following are library definitions and can not be changed.

#include "def_libpiziot_os_platform.h"

#include "def_libpiziot_os_type.h"

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else

#define LIBPIZIOT_NET_STREAM_OUT_LIST_MAX 10

//rtsp
#define LIBPIZIOT_NET_RTSP_SOCKET_LISTEN_COUNT 1
#define LIBPIZIOT_NET_RTSP_SOCKET_ACCEPT_COUNT 5
#define LIBPIZIOT_NET_RTSP_SOCKET_UDP_COUNT LIBPIZIOT_NET_RTSP_SOCKET_ACCEPT_COUNT
#define LIBPIZIOT_NET_RTSP_SOCKET_COUNT (LIBPIZIOT_NET_RTSP_SOCKET_LISTEN_COUNT + LIBPIZIOT_NET_RTSP_SOCKET_ACCEPT_COUNT + LIBPIZIOT_NET_RTSP_SOCKET_UDP_COUNT)

//p2p resource
#define LIBPIZIOT_P2P_COMMON_SERVER_HANDLER_MAX 1
#define LIBPIZIOT_P2P_COMMON_RELAY_HANDLER_MAX 6
#define LIBPIZIOT_P2P_COMMON_SERVER_RELAY_LIST_MAX 128

#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#define LIBPIZIOT_P2P_COMMON_LAN_SERVER_HANDLER_BASE 1
#define LIBPIZIOT_P2P_COMMON_LAN_SERVER_HANDLER_MAX 1

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#define LIBPIZIOT_P2P_COMMON_DEVICE_HANDLER_MAX 1
#define LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_HANDLER_COUNT_PER_MON 1
#define LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_CONCURRENT_COUNT 3
#define LIBPIZIOT_P2P_COMMON_VIEWER_COUNT (1)
#else
#define LIBPIZIOT_P2P_COMMON_DEVICE_HANDLER_MAX 32
#define LIBPIZIOT_P2P_COMMON_VIEWER_COUNT (32 + 1)
#define LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_HANDLER_COUNT_PER_MON (16 * 4)
#define LIBPIZIOT_P2P_COMMON_CHANNEL_CLIENT_HANDLER_COUNT (16 * 6)
#define LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_CONCURRENT_COUNT 3
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)
#define LIBPIZIOT_P2P_COMMON_LAN_SEARCH_COUNT 1
#define LIBPIZIOT_P2P_COMMON_VIEWER_HANDLER_MAX (LIBPIZIOT_P2P_COMMON_VIEWER_COUNT + LIBPIZIOT_P2P_COMMON_LAN_SEARCH_COUNT)

#define LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_MONITOR_MAX (LIBPIZIOT_P2P_COMMON_DEVICE_HANDLER_MAX * LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_HANDLER_COUNT_PER_MON)
#define LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_HANDLER_MAX ((LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_HANDLER_COUNT_PER_MON * LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_CONCURRENT_COUNT) + 0)

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else
#define LIBPIZIOT_P2P_COMMON_CHANNEL_CLIENT_HANDLER_MAX ((LIBPIZIOT_P2P_COMMON_VIEWER_COUNT * LIBPIZIOT_P2P_COMMON_CHANNEL_CLIENT_HANDLER_COUNT) + 0)
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#define P2P_CHANNEL_SERVER_MAIN_THREAD_MAX LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_MONITOR_MAX

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else
#define P2P_CHANNEL_CLIENT_MAIN_THREAD_MAX LIBPIZIOT_P2P_COMMON_CHANNEL_CLIENT_HANDLER_MAX
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#define LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_MONITOR_THREAD_MAX 1

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#define LIBPIZIOT_P2P_COMMON_SOCKET_MAX (LIBPIZIOT_P2P_COMMON_LAN_SERVER_HANDLER_MAX + LIBPIZIOT_P2P_COMMON_DEVICE_HANDLER_MAX + LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_HANDLER_MAX + LIBPIZIOT_P2P_COMMON_VIEWER_HANDLER_MAX)
#else
#define LIBPIZIOT_P2P_COMMON_SOCKET_MAX (LIBPIZIOT_P2P_COMMON_SERVER_HANDLER_MAX + LIBPIZIOT_P2P_COMMON_RELAY_HANDLER_MAX + LIBPIZIOT_P2P_COMMON_LAN_SERVER_HANDLER_MAX + LIBPIZIOT_P2P_COMMON_DEVICE_HANDLER_MAX + LIBPIZIOT_P2P_COMMON_VIEWER_HANDLER_MAX + LIBPIZIOT_P2P_COMMON_CHANNEL_SERVER_HANDLER_MAX + LIBPIZIOT_P2P_COMMON_CHANNEL_CLIENT_HANDLER_MAX)
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

//socket
#if defined(__LIBPIZIOT_OS_FREERTOS__)
#define LIBPIZIOT_OS_SOCKET_OBJECT_MAX (LIBPIZIOT_P2P_COMMON_SOCKET_MAX + 1)
#else
#define LIBPIZIOT_OS_SOCKET_OBJECT_MAX (LIBPIZIOT_NET_RTSP_SOCKET_COUNT + LIBPIZIOT_P2P_COMMON_SOCKET_MAX + 1)
#endif //defined(__LIBPIZIOT_OS_FREERTOS__)

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

#endif //__DEF_LIBPIZIOT_OS_RESOURCE_H__
