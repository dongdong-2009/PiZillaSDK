// stdafx.cpp : source file that includes just the standard includes
// PIZCms.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

#include "../../../Linux/src/pizcms/pizcms_config.h"
#include "../../../../libpiziot_core_cms/Linux/include/menu_config.h"

#if defined(_DEBUG)
    #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Debug/libpiziot_os_VS2008_Win32_Debug.lib")
#else
    #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Release/libpiziot_os_VS2008_Win32_Release.lib")
#endif

#if defined(ENABLE_HI3518E_V1)
    #if defined(_DEBUG)
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Debug/libpizbsp_hi3518e_VS2008_Win32_Debug.lib")
    #else
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Release/libpizbsp_hi3518e_VS2008_Win32_Release.lib")
    #endif
#endif //defined(ENABLE_HI3518E_V1)

#if defined(ENABLE_HI3518E_V2)
    #if defined(_DEBUG)
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Debug/libpizbsp_hi3518ev2_VS2008_Win32_Debug.lib")
    #else
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Release/libpizbsp_hi3518ev2_VS2008_Win32_Release.lib")
    #endif
#endif //defined(ENABLE_HI3518E_V2)

#if defined(ENABLE_RTSP_LIB)
    #if defined(_DEBUG)
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Debug/libpiziot_net_rtsp_VS2008_Win32_Debug.lib")
    #else
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Release/libpiziot_net_rtsp_VS2008_Win32_Release.lib")
    #endif // _DEBUG
#endif //defined(ENABLE_RTSP_LIB)

#if defined(ENABLE_P2P_LIB)
    #if defined(_DEBUG)
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Debug/libpiziot_p2p_common_VS2008_Win32_Debug.lib")
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Debug/libpiziot_p2p_client_VS2008_Win32_Debug.lib")
    #else
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Release/libpiziot_p2p_common_VS2008_Win32_Release.lib")
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Release/libpiziot_p2p_client_VS2008_Win32_Release.lib")
    #endif // _DEBUG
#endif //defined(ENABLE_P2P_LIB)

#if defined(ENABLE_AVI_LIB)
    #if defined(_DEBUG)
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Debug/libpiziot_file_avi_VS2008_Win32_Debug.lib")
    #else
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Release/libpiziot_file_avi_VS2008_Win32_Release.lib")
    #endif // _DEBUG
#endif //defined(ENABLE_AVI_LIB)

#if defined(ENABLE_MFC_GUI_LIB)
    #ifdef _DEBUG
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Debug/libpiziot_mfc_gui_VS2008_Win32_Debug.lib")
    #else
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Release/libpiziot_mfc_gui_VS2008_Win32_Release.lib")
    #endif // _DEBUG
#endif //defined(ENABLE_MFC_GUI_LIB)

#if 0 && defined(ENABLE_MFC_SQL_LIB)
    #ifdef _DEBUG
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Debug/libpiziot_mfc_sql_VS2008_Win32_Debug.lib")
    #else
        #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Release/libpiziot_mfc_sql_VS2008_Win32_Release.lib")
    #endif // _DEBUG
#endif //defined(ENABLE_MFC_SQL_LIB)

#if defined(_DEBUG)
    #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Debug/libpiziot_core_cms_VS2008_Win32_Debug.lib")
#else
    #pragma comment(lib,"../../../../lib/VisualStudio/VS2008/win32/Release/libpiziot_core_cms_VS2008_Win32_Release.lib")
#endif

#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"IPHLPAPI.lib")
