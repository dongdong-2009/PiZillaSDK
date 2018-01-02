#include "stdafx_lib.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define C Libary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#include <errno.h>
#else
#include <sys/statvfs.h>
#include <dirent.h>
#include <errno.h>
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

//Define Windows Library

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

#include "pizcms_config.h"

//Define Kernel Library

//Define Static Library

//Define this Header
#include "pizcms_setting.h"

//Define OtherHeader

//Define Common Library

//Define Debug Library

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
#else
#define TRACEB(...) {LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);} //TRACEA
#endif
