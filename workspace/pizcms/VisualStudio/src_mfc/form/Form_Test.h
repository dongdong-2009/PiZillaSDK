#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message (" Include "__FILE__)
#endif

#ifdef USE_Compiler_Step_info
#pragma message (" Declare Class LibPIZIOTClass::Form_Test")
#endif

#include "resource.h"
#include "libpiziot/libpiziot_mfc_gui/def_libpiziot_mfc_dautptr.h"

#include "../../../../libpiziot_core_cms/Linux/include/menu_config.h"

#if defined(ENABLE_MFC_GUI)

#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"
#include "../../../../libpiziot_core_cms/Linux/src/piziot_core_cms/piziot_core_cms.h"

#if defined(MFC_TEST_BIG_ENDIAN__)
#define dwAppEndian_u32(x) libpiziot_os_mem_endian_u32(x)
#define dwAppEndian_u16(x) libpiziot_os_mem_endian_u16(x)
#define dwAppEndian_32(x) libpiziot_os_mem_endian_32(x)
#define dwAppEndian_16(x) libpiziot_os_mem_endian_16(x)
#else
#define dwAppEndian_u32(x) (x)
#define dwAppEndian_u16(x) (x)
#define dwAppEndian_32(x) (x)
#define dwAppEndian_16(x) (x)
#endif //defined(MFC_TEST_BIG_ENDIAN__)

namespace LibPIZIOTClass
{
    class Form_Test;
}

namespace LibPIZIOTClass
{
    class Form_Test
    {
    protected:

    public:
        Form_Test(void);
        virtual ~Form_Test();
    };

}

#endif //defined(ENABLE_MFC_GUI)
