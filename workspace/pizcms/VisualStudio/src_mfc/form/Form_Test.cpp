#include "stdafx.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"

#if defined(WIN32)

#include "./Form_Test.h"

#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

#if defined(ENABLE_MFC_GUI)

namespace LibPIZIOTClass
{

    typedef Form_Test InheritClass;

    InheritClass::Form_Test(void)
    {
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
        ASSERT(this);
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    }

    InheritClass::~Form_Test()
    {
    }
}

#endif //defined(ENABLE_MFC_GUI)

#endif //defined(WIN32)
