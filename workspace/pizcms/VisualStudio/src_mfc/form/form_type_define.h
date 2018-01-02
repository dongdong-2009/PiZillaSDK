#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message (" Include "__FILE__)
#endif

#ifdef USE_Compiler_Step_info
#pragma message (" Declare Class LibPIZIOTClass::Form_Main_List")
#endif

#include "resource.h"
#include "libpiziot/libpiziot_mfc_gui/def_libpiziot_mfc_dautptr.h"

#include "../../../../libpiziot_core_cms/Linux/include/menu_config.h"

#if defined(ENABLE_MFC_GUI)

namespace LibPIZIOTClass
{
}

namespace LibPIZIOTClass
{
    enum WM_USER_MESSAGE
    {
        WM_USER_ChangeForm = WM_USER + 4000,
    };

    enum FORM_ID_DIALOG
    {
        FORM_ID_DIALOG_FORM_MAIN_LIST = 1000,
        FORM_ID_DIALOG_FORM_MAIN_TEST,
    };

}

#endif //defined(ENABLE_MFC_GUI)
