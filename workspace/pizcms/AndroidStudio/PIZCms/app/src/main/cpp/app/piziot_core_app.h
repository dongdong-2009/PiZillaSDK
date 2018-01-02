#ifndef __PIZIOT_CORE_CMS_H__
#define __PIZIOT_CORE_CMS_H__

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#define LIBPIZIOT_JNI_VERSION JNI_VERSION_1_6

#ifdef __cplusplus
extern "C"
{
#endif

extern JavaVM *lppiziot_core_app_jvm;

#ifdef __cplusplus
}
#endif

#endif //__PIZIOT_CORE_CMS_H__
