#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message (" Include "__FILE__)
#endif

#ifdef USE_Compiler_Step_info
#pragma message (" Declare Class LibPIZIOTClass::Form_Base")
#endif

//#include "resource.h"
//#include "../gui/dautptr.h"

//#include "../../../../libpiziot_core_test/Linux/include/menu_config.h"

//#if defined(ENABLE_MFC_GUI)

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"

#include "libpiziot/libpiziot_mfc_gui/class_def/def_libpiziot_mfc_gui_list_obj.h"
//
//#include "form_type_define.h"
//#include "Form_Base_Test.h"

namespace LibPIZIOTClass {
    class Form_Base;
}

namespace LibPIZIOTClass {
    class Form_Base {
    private:

    protected:
        CWnd *FlpCWnd;
        LibPIZIOTClass::LibPIZIOTGuiListObj *FlpObjLibPIZIOTGuiListObj;

        virtual void CreateobjButton(void);

        virtual void RemoveobjButton(void);

    public:
        Form_Base(CWnd *AlpCWnd, LibPIZIOTClass::LibPIZIOTGuiListObj *AlpObjLibPIZIOTGuiListObj);

        virtual ~Form_Base();

        void Fire_IOCTRL(unsigned int AnIOCtrlType, unsigned char *AlpChar, uint32_t Asize);

        virtual void OnTimer(void) = 0;
    };

}

//#endif //defined(ENABLE_MFC_GUI)
