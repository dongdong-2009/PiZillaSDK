#include "stdafx.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"

#if defined(WIN32)

#include "PIZCms.h"
#include "./Form_Main_List.h"

#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

#include "form_type_define.h"

#if defined(ENABLE_MFC_GUI)

namespace LibPIZIOTClass
{
    typedef LibPIZIOTClass::Form_Base BaseClass;
    typedef Form_Main_List InheritClass;

    InheritClass::Form_Main_List(CWnd* AlpCWnd, LibPIZIOTClass::LibPIZIOTGuiListObj*AlpObjLibPIZIOTGuiListObj) : LibPIZIOTClass::BaseClass(AlpCWnd, AlpObjLibPIZIOTGuiListObj)
    {
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
        ASSERT(this);
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

        {
            LibPIZIOTClass::LibPIZIOTGuiObjInfoBitmap_t m_MAIN_DIALOG_LIST = { IDC_CURSOR_HAND, 0,0,0,0,_T(""),RGB(255,255,255),0,IDB_DIALOG_LIST_NORMAL,IDB_DIALOG_LIST_FOCUS,IDB_DIALOG_LIST_DOWN,IDB_DIALOG_LIST_DISABLE,0 };
            this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiStatusBitmap(this, this->objMAIN_DIALOG_LIST, &m_MAIN_DIALOG_LIST);
        }

        this->CreateobjButton();

    }

    InheritClass::~Form_Main_List()
    {
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->objMAIN_DIALOG_LIST);
        //this->RemoveobjButton();
        this->FlpObjLibPIZIOTGuiListObj->RemoveAllLibPIZIOTGuiObject();
    }

    void InheritClass::CreateobjButton(void)
    {
        int pos_x = 265;
        int pos_y = 320;
        {
            LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfQUIT = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("Quit"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonQUIT,DIALOG_MAIN_TEST_OBJECT_ID_RETURN,456,0,DIALOG_MAIN_TEST_OBJECT_ID_RETURN,456,0,DIALOG_MAIN_TEST_OBJECT_ID_RETURN,456 };
            this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonQUIT, &m_bfQUIT);
        }
        {
            int pos_x = 265;
            int pos_y = 320 + buttonQUIT->GetDefaultHeight() + 10;
            LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfTest = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("Test"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonTest,DIALOG_MAIN_TEST_OBJECT_ID_RETURN,456,0,DIALOG_MAIN_TEST_OBJECT_ID_RETURN,456,0,DIALOG_MAIN_TEST_OBJECT_ID_RETURN,456 };
            this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonTest, &m_bfTest);
        }
#if 0
        bool bBoxStatusOn = true;
        //buttonONOFF
        {
            int pos_x = 265;
            int pos_y = 320;
            {
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfQUIT_ON = { IDC_CURSOR_HAND, 0,0,0,0,_T("Quit"),RGB(0,0,0),0,IDB_BUTTON_ON_NORMAL,IDB_BUTTON_ON_FOCUS,IDB_BUTTON_ON_DOWN,IDB_BUTTON_ON_DISABLE,0,InheritClass::FireClick_buttonONOFF,123,456,0,123,456,0,123,456 };
                m_bfQUIT_ON.Left = pos_x; m_bfQUIT_ON.Top = pos_y; this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonONOFF.ObjON, &m_bfQUIT_ON);
            }
            {
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfQUIT_OFF = { IDC_CURSOR_HAND, 0,0,0,0,_T("Quit"),RGB(0,0,0),0,IDB_BUTTON_OFF_NORMAL,IDB_BUTTON_OFF_FOCUS,IDB_BUTTON_OFF_DOWN,IDB_BUTTON_OFF_DISABLE,0,InheritClass::FireClick_buttonONOFF,123,456,0,123,456,0,123,456 };
                m_bfQUIT_OFF.Left = pos_x; m_bfQUIT_OFF.Top = pos_y; this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonONOFF.ObjOFF, &m_bfQUIT_OFF);
            }
            if (bBoxStatusOn)
            {
                this->buttonONOFF.ObjON->SetVisible(true);
                this->buttonONOFF.ObjOFF->SetVisible(false);
            }
            else
            {
                this->buttonONOFF.ObjON->SetVisible(false);
                this->buttonONOFF.ObjOFF->SetVisible(true);
            }
        }
        //buttonTest
        {
            int pos_x = 265;
            int pos_y = 320 + this->buttonONOFF.ObjON->GetDefaultHeight() + 10;
            {
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfTest_ON = { IDC_CURSOR_HAND, 0,0,0,0,_T("Test"),RGB(0,0,0),0,IDB_BUTTON_ON_NORMAL,IDB_BUTTON_ON_FOCUS,IDB_BUTTON_ON_DOWN,IDB_BUTTON_ON_DISABLE,0,InheritClass::FireClick_buttonTest,123,456,0,123,456,0,123,456 };
                m_bfTest_ON.Left = pos_x; m_bfTest_ON.Top = pos_y; this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonTest.ObjON, &m_bfTest_ON);
            }
            {
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfTest_OFF = { IDC_CURSOR_HAND, 0,0,0,0,_T("Test"),RGB(0,0,0),0,IDB_BUTTON_OFF_NORMAL,IDB_BUTTON_OFF_FOCUS,IDB_BUTTON_OFF_DOWN,IDB_BUTTON_OFF_DISABLE,0,InheritClass::FireClick_buttonTest,123,456,0,123,456,0,123,456 };
                m_bfTest_OFF.Left = pos_x; m_bfTest_OFF.Top = pos_y; this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonTest.ObjOFF, &m_bfTest_OFF);
            }
            if (bBoxStatusOn)
            {
                this->buttonTest.ObjON->SetVisible(true);
                this->buttonTest.ObjOFF->SetVisible(false);
            }
            else
            {
                this->buttonTest.ObjON->SetVisible(false);
                this->buttonTest.ObjOFF->SetVisible(true);
            }
        }
#endif //0
    }

    void InheritClass::RemoveobjButton(void)
    {
        this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonQUIT);
        this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonTest);
#if 0
        //buttonONOFF
        {
            this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonONOFF.ObjON);
            this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonONOFF.ObjOFF);
        }
        //buttonTest
        {
            this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonTest.ObjON);
            this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonTest.ObjOFF);
        }
#endif //0
    }

    LONG WINAPI InheritClass::FireClick_buttonQUIT(void*AlpTarget, WPARAM AobjID, LPARAM AlParam)
    {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonQUIT_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonQUIT_OnClick(WPARAM AobjID, LPARAM AlParam)
    {
        //::SendMessage(this->FlpCWnd->GetSafeHwnd(),LibPIZIOTClass::WM_USER_ChangeForm,WPARAM(0),LPARAM(FORM_ID_DIALOG_FORM_MAIN_TEST));
        //::SendMessage(this->FlpCWnd->GetSafeHwnd(), WM_CLOSE, WPARAM(0), LPARAM(0));
        ::PostMessage(pFrame->GetSafeHwnd(), WM_CLOSE, WPARAM(0), LPARAM(0));
    }

    LONG WINAPI InheritClass::FireClick_buttonTest(void*AlpTarget, WPARAM AobjID, LPARAM AlParam)
    {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonTest_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonTest_OnClick(WPARAM AobjID, LPARAM AlParam)
    {
        ::SendMessage(this->FlpCWnd->GetSafeHwnd(), LibPIZIOTClass::WM_USER_ChangeForm, WPARAM(0), LPARAM(FORM_ID_DIALOG_FORM_MAIN_TEST));
    }

    void InheritClass::OnTimer(void)
    {
        //this->theForm_XXX->UpdateBoxListInfo();
    }
}

#endif //defined(ENABLE_MFC_GUI)

#endif //defined(WIN32)
