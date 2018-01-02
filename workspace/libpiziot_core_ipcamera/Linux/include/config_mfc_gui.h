#ifndef __CONFIG_MFC_GUI_H__
#define __CONFIG_MFC_GUI_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message ("--- Include "__FILE__)
#endif

#define ENABLE_MFC_GUI

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#if defined(ENABLE_MFC_GUI)
#define ENABLE_MFC_GUI_LIB
#endif //defined(ENABLE_MFC_GUI)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#endif //__CONFIG_DIALOG_H__
