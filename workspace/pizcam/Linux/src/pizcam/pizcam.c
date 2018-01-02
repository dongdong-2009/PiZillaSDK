//============================================================================
// Name : pizcam.cpp
// Author : Sparkler
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#error
#else

#ifdef __cplusplus
#include <iostream>
using namespace std;
#endif

#include <stdio.h>
#include <stdlib.h>

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"

#include "libpiziot/libpiziot_core_ipcamera/def_libpiziot_core_ipcamera.h"

#include "pizcam_main.h"

int main(int argc, char *argv[]) {
    do
    {
        if (libpiziot_core_ipcamera_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
        if (pizcam_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) break;
        libpiziot_core_ipcamera_event_loop();
    } while (0);
    pizcam_main_finalize();
    libpiziot_core_ipcamera_finalize();
    return EXIT_SUCCESS;
}

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
