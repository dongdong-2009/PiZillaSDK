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

#include "libpiziot/libpiziot_mfc_gui/def_libpiziot_mfc_gui.h"

#include "form_type_define.h"
#include "libpiziot/libpiziot_mfc_gui/class_def/def_libpiziot_mfc_gui_button.h"
#include "libpiziot/libpiziot_mfc_gui/class_def/def_libpiziot_mfc_gui_Form_Base.h"

namespace LibPIZIOTClass
{
    class Form_Main_List;
}

namespace LibPIZIOTClass
{
    typedef struct OBJ_SIMPLE_BUTTON_s
    {
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> ObjON;
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> ObjOFF;
    }OBJ_SIMPLE_BUTTON_t;

    class Form_Main_List : public LibPIZIOTClass::Form_Base
    {
    private:
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiStatusBitmap> objMAIN_DIALOG_LIST;

        //OBJ_SIMPLE_BUTTON_t buttonONOFF;
        //void buttonONOFF_OnClick(WPARAM AobjID, LPARAM AlParam);
        //static LONG WINAPI FireClick_buttonONOFF(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonQUIT;
        void buttonQUIT_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonQUIT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonTest;
        void buttonTest_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonTest(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        virtual void CreateobjButton(void);
        virtual void RemoveobjButton(void);

    public:
        Form_Main_List(CWnd* AlpCWnd, LibPIZIOTClass::LibPIZIOTGuiListObj* AlpObjLibPIZIOTGuiListObj);
        virtual ~Form_Main_List();

        virtual void OnTimer(void);
    };

}

#endif //defined(ENABLE_MFC_GUI)
