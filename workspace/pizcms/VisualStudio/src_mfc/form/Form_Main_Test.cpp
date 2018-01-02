#include "stdafx.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"

#if defined(WIN32)

#include "./Form_Main_Test.h"

#include "../../../Linux/src/pizcms/pizcms_main.h"

#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

#if defined(ENABLE_MFC_GUI)

#include "MainFrm.h"

namespace LibPIZIOTClass
{
    typedef LibPIZIOTClass::Form_Base BaseClass;
    typedef Form_Main_Test InheritClass;

    InheritClass::Form_Main_Test(CWnd* AlpCWnd, LibPIZIOTClass::LibPIZIOTGuiListObj*AlpObjLibPIZIOTGuiListObj) : LibPIZIOTClass::BaseClass(AlpCWnd, AlpObjLibPIZIOTGuiListObj)
    {
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
        ASSERT(this);
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
        {
#if defined(IDB_DIALOG_TEST_NORMAL)
            {
                LibPIZIOTClass::LibPIZIOTGuiObjInfoBitmap_t m_MAIN_DIALOG_TEST = { IDC_CURSOR_HAND, 0,0,0,0,_T(""),RGB(255,255,255),0,IDB_DIALOG_TEST_NORMAL,IDB_DIALOG_TEST_FOCUS,IDB_DIALOG_TEST_DOWN,IDB_DIALOG_TEST_DISABLE,0 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiStatusBitmap(this, this->objMAIN_DIALOG_TEST, &m_MAIN_DIALOG_TEST);
            }
#endif //defined(IDB_DIALOG_TEST_NORMAL)
            {
                int pos_x = 10;
                int pos_y = 10;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfRETURN = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("<< Return"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonRETURN,DIALOG_MAIN_TEST_OBJECT_ID_RETURN,456,0,DIALOG_MAIN_TEST_OBJECT_ID_RETURN,456,0,DIALOG_MAIN_TEST_OBJECT_ID_RETURN,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonRETURN, &m_bfRETURN);
            }
#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
            {
                int pos_x = this->buttonRETURN->GetLeft() + this->buttonRETURN->GetDefaultWidth() + 10;
                int pos_y = this->buttonRETURN->GetTop();
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfMODEL = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("CAM/CMS MODEL"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonIPCAMERA_AND_CMS_MODEL,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_MODEL,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_MODEL,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_MODEL,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonIPCAMERA_AND_CMS_MODEL, &m_bfMODEL);
            }
            {
                int pos_x = this->buttonIPCAMERA_AND_CMS_MODEL->GetLeft();
                int pos_y = this->buttonIPCAMERA_AND_CMS_MODEL->GetTop() + this->buttonIPCAMERA_AND_CMS_MODEL->GetDefaultHeight() + 10;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfFWVERP2P = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("FWVERP2P"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonIPCAMERA_AND_CMS_FWVERP2P,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_FWVERP2P,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_FWVERP2P,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_FWVERP2P,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonIPCAMERA_AND_CMS_FWVERP2P, &m_bfFWVERP2P);
            }
            {
                int pos_x = this->buttonIPCAMERA_AND_CMS_MODEL->GetLeft() + this->buttonIPCAMERA_AND_CMS_MODEL->GetDefaultWidth() + 10;
                int pos_y = this->buttonIPCAMERA_AND_CMS_MODEL->GetTop();
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfREBOOT = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("REBOOT"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonIPCAMERA_AND_CMS_REBOOT,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_REBOOT,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_REBOOT,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_REBOOT,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonIPCAMERA_AND_CMS_REBOOT, &m_bfREBOOT);
            }
            {
                int pos_x = this->buttonIPCAMERA_AND_CMS_REBOOT->GetLeft();
                int pos_y = this->buttonIPCAMERA_AND_CMS_REBOOT->GetTop() + this->buttonIPCAMERA_AND_CMS_REBOOT->GetDefaultHeight() + 10;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfTIMEZONE = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("TIMEZONE"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonIPCAMERA_AND_CMS_TIMEZONE,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_TIMEZONE,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_TIMEZONE,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_TIMEZONE,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonIPCAMERA_AND_CMS_TIMEZONE, &m_bfTIMEZONE);
            }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)
#if defined(ENABLE_P2P_NAS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
            {
                int pos_x = this->buttonRETURN->GetLeft() + this->buttonRETURN->GetDefaultWidth() + 10;
                int pos_y = this->buttonRETURN->GetTop() + 100;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfMODEL = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("CAM/NAS MODEL"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonIPCAMERA_AND_NAS_MODEL,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_MODEL,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_MODEL,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_MODEL,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonIPCAMERA_AND_NAS_MODEL, &m_bfMODEL);
            }
            {
                int pos_x = this->buttonIPCAMERA_AND_NAS_MODEL->GetLeft();
                int pos_y = this->buttonIPCAMERA_AND_NAS_MODEL->GetTop() + this->buttonIPCAMERA_AND_NAS_MODEL->GetDefaultHeight() + 10;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfFWVERP2P = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("FWVERP2P"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonIPCAMERA_AND_NAS_FWVERP2P,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_FWVERP2P,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_FWVERP2P,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_FWVERP2P,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonIPCAMERA_AND_NAS_FWVERP2P, &m_bfFWVERP2P);
            }
            {
                int pos_x = this->buttonIPCAMERA_AND_NAS_MODEL->GetLeft() + this->buttonIPCAMERA_AND_NAS_MODEL->GetDefaultWidth() + 10;
                int pos_y = this->buttonIPCAMERA_AND_NAS_MODEL->GetTop();
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfREBOOT = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("REBOOT"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonIPCAMERA_AND_NAS_REBOOT,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_REBOOT,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_REBOOT,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_REBOOT,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonIPCAMERA_AND_NAS_REBOOT, &m_bfREBOOT);
            }
            {
                int pos_x = this->buttonIPCAMERA_AND_NAS_REBOOT->GetLeft();
                int pos_y = this->buttonIPCAMERA_AND_NAS_REBOOT->GetTop() + this->buttonIPCAMERA_AND_NAS_REBOOT->GetDefaultHeight() + 10;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfTIMEZONE = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("TIMEZONE"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonIPCAMERA_AND_NAS_TIMEZONE,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_TIMEZONE,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_TIMEZONE,456,0,DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_TIMEZONE,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonIPCAMERA_AND_NAS_TIMEZONE, &m_bfTIMEZONE);
            }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
            {
                int pos_x = this->buttonRETURN->GetLeft() + this->buttonRETURN->GetDefaultWidth() + 10;
                int pos_y = this->buttonRETURN->GetTop() + 200;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfMODEL = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("NAS/CMS MODEL"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonNAS_AND_CMS_MODEL,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_MODEL,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_MODEL,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_MODEL,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonNAS_AND_CMS_MODEL, &m_bfMODEL);
            }
            {
                int pos_x = this->buttonNAS_AND_CMS_MODEL->GetLeft();
                int pos_y = this->buttonNAS_AND_CMS_MODEL->GetTop() + this->buttonNAS_AND_CMS_MODEL->GetDefaultHeight() + 10;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfFWVERP2P = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("FWVERP2P"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonNAS_AND_CMS_FWVERP2P,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_FWVERP2P,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_FWVERP2P,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_FWVERP2P,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonNAS_AND_CMS_FWVERP2P, &m_bfFWVERP2P);
            }
            {
                int pos_x = this->buttonNAS_AND_CMS_MODEL->GetLeft() + this->buttonNAS_AND_CMS_MODEL->GetDefaultWidth() + 10;
                int pos_y = this->buttonNAS_AND_CMS_MODEL->GetTop();
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfREBOOT = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("REBOOT"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonNAS_AND_CMS_REBOOT,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_REBOOT,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_REBOOT,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_REBOOT,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonNAS_AND_CMS_REBOOT, &m_bfREBOOT);
            }
            {
                int pos_x = this->buttonNAS_AND_CMS_REBOOT->GetLeft();
                int pos_y = this->buttonNAS_AND_CMS_REBOOT->GetTop() + this->buttonNAS_AND_CMS_REBOOT->GetDefaultHeight() + 10;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfTIMEZONE = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("TIMEZONE"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonNAS_AND_CMS_TIMEZONE,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_TIMEZONE,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_TIMEZONE,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_TIMEZONE,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonNAS_AND_CMS_TIMEZONE, &m_bfTIMEZONE);
            }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
            {
                int pos_x = this->buttonRETURN->GetLeft() + this->buttonRETURN->GetDefaultWidth() + 10;
                int pos_y = this->buttonRETURN->GetTop() + 300;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfLOCK = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("LOCK"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonNAS_AND_CMS_LOCK,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_LOCK,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_LOCK,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_LOCK,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonNAS_AND_CMS_LOCK, &m_bfLOCK);
            }
            {
                int pos_x = this->buttonNAS_AND_CMS_LOCK->GetLeft();
                int pos_y = this->buttonNAS_AND_CMS_LOCK->GetTop() + this->buttonNAS_AND_CMS_LOCK->GetDefaultHeight() + 10;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfUNLOCK = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("UNLOCK"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonNAS_AND_CMS_UNLOCK,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNLOCK,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNLOCK,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNLOCK,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonNAS_AND_CMS_UNLOCK, &m_bfUNLOCK);
            }
            {
                int pos_x = this->buttonNAS_AND_CMS_LOCK->GetLeft() + this->buttonNAS_AND_CMS_LOCK->GetDefaultWidth() + 10;
                int pos_y = this->buttonNAS_AND_CMS_LOCK->GetTop();
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfMUTE = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("MUTE"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonNAS_AND_CMS_MUTE,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_MUTE,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_MUTE,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_MUTE,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonNAS_AND_CMS_MUTE, &m_bfMUTE);
            }
            {
                int pos_x = this->buttonNAS_AND_CMS_MUTE->GetLeft();
                int pos_y = this->buttonNAS_AND_CMS_MUTE->GetTop() + this->buttonNAS_AND_CMS_MUTE->GetDefaultHeight() + 10;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfUNMUTE = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("UNMUTE"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonNAS_AND_CMS_UNMUTE,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNMUTE,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNMUTE,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNMUTE,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonNAS_AND_CMS_UNMUTE, &m_bfUNMUTE);
            }
            {
                int pos_x = this->buttonNAS_AND_CMS_MUTE->GetLeft() + this->buttonNAS_AND_CMS_MUTE->GetDefaultWidth() + 10;
                int pos_y = this->buttonNAS_AND_CMS_MUTE->GetTop();
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfCALLOUT = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("CALLOUT"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonNAS_AND_CMS_CALLOUT,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_CALLOUT,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_CALLOUT,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_CALLOUT,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonNAS_AND_CMS_CALLOUT, &m_bfCALLOUT);
            }
            {
                int pos_x = this->buttonNAS_AND_CMS_CALLOUT->GetLeft();
                int pos_y = this->buttonNAS_AND_CMS_CALLOUT->GetTop() + this->buttonNAS_AND_CMS_CALLOUT->GetDefaultHeight() + 10;
                LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t m_bfUNCALLOUT = { IDC_CURSOR_HAND, pos_x,pos_y , 0,0,_T("UNCALLOUT"),RGB(0,0,0),0,IDB_BUTTON_NORMAL,IDB_BUTTON_FOCUS,IDB_BUTTON_DOWN,IDB_BUTTON_DISABLE,0,InheritClass::FireClick_buttonNAS_AND_CMS_UNCALLOUT,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNCALLOUT,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNCALLOUT,456,0,DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNCALLOUT,456 };
                this->FlpObjLibPIZIOTGuiListObj->CreateLibPIZIOTGuiButton(this, this->buttonNAS_AND_CMS_UNCALLOUT, &m_bfUNCALLOUT);
            }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
        }
    }

    InheritClass::~Form_Main_Test()
    {
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->objMAIN_DIALOG_TEST);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonRETURN);
#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonIPCAMERA_AND_CMS_MODEL);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonIPCAMERA_AND_CMS_FWVERP2P);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonIPCAMERA_AND_CMS_REBOOT);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonIPCAMERA_AND_CMS_TIMEZONE);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)
#if defined(ENABLE_P2P_NAS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonIPCAMERA_AND_NAS_MODEL);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonIPCAMERA_AND_NAS_FWVERP2P);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonIPCAMERA_AND_NAS_REBOOT);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonIPCAMERA_AND_NAS_TIMEZONE);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonNAS_AND_CMS_MODEL);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonNAS_AND_CMS_FWVERP2P);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonNAS_AND_CMS_REBOOT);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonNAS_AND_CMS_TIMEZONE);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonNAS_AND_CMS_LOCK);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonNAS_AND_CMS_UNLOCK);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonNAS_AND_CMS_MUTE);
        //this->FlpObjLibPIZIOTGuiListObj->RemoveLibPIZIOTGuiObject(this->buttonNAS_AND_CMS_CALLOUT);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
        this->FlpObjLibPIZIOTGuiListObj->RemoveAllLibPIZIOTGuiObject();
    }

    LONG WINAPI InheritClass::FireClick_buttonRETURN(void*AlpTarget, WPARAM AobjID, LPARAM AlParam)
    {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonRETURN_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonRETURN_OnClick(WPARAM AobjID, LPARAM AlParam)
    {
        CChildView* lpMainFrm = (CChildView*)(this->FlpCWnd);
        WPARAM form_id = lpMainFrm->GetReturnFormID();
        ::SendMessage(this->FlpCWnd->GetSafeHwnd(), LibPIZIOTClass::WM_USER_ChangeForm, WPARAM(0), LPARAM(form_id));
    }

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)

    void InheritClass::buttonIPCAMERA_AND_CMS_MODEL_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_ipcamera_channel_common_get_model(cms_viewer_ipcamera_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonIPCAMERA_AND_CMS_MODEL(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonIPCAMERA_AND_CMS_MODEL_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonIPCAMERA_AND_CMS_FWVERP2P_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_ipcamera_channel_common_get_fwverp2p(cms_viewer_ipcamera_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonIPCAMERA_AND_CMS_FWVERP2P(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonIPCAMERA_AND_CMS_FWVERP2P_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonIPCAMERA_AND_CMS_REBOOT_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_ipcamera_channel_common_set_reboot(cms_viewer_ipcamera_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonIPCAMERA_AND_CMS_REBOOT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonIPCAMERA_AND_CMS_REBOOT_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonIPCAMERA_AND_CMS_TIMEZONE_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_ipcamera_channel_common_set_timezone(cms_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_ipcamera_channel_common_get_timezone(cms_viewer_ipcamera_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonIPCAMERA_AND_CMS_TIMEZONE(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonIPCAMERA_AND_CMS_TIMEZONE_OnClick(AobjID, AlParam);
        return 0;
    }

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)
#if defined(ENABLE_P2P_NAS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)

    void InheritClass::buttonIPCAMERA_AND_NAS_MODEL_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_nas_viewer_channel_common_get_model(nas_viewer_ipcamera_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonIPCAMERA_AND_NAS_MODEL(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonIPCAMERA_AND_NAS_MODEL_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonIPCAMERA_AND_NAS_FWVERP2P_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_nas_viewer_channel_common_get_fwverp2p(nas_viewer_ipcamera_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonIPCAMERA_AND_NAS_FWVERP2P(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonIPCAMERA_AND_NAS_FWVERP2P_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonIPCAMERA_AND_NAS_REBOOT_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_nas_viewer_channel_common_set_reboot(nas_viewer_ipcamera_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonIPCAMERA_AND_NAS_REBOOT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonIPCAMERA_AND_NAS_REBOOT_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonIPCAMERA_AND_NAS_TIMEZONE_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_nas_viewer_channel_common_set_timezone(nas_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_nas_viewer_channel_common_get_timezone(nas_viewer_ipcamera_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonIPCAMERA_AND_NAS_TIMEZONE(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonIPCAMERA_AND_NAS_TIMEZONE_OnClick(AobjID, AlParam);
        return 0;
    }

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)

    void InheritClass::buttonNAS_AND_CMS_MODEL_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_nas_channel_common_get_model(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonNAS_AND_CMS_MODEL(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonNAS_AND_CMS_MODEL_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonNAS_AND_CMS_FWVERP2P_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_nas_channel_common_get_fwverp2p(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonNAS_AND_CMS_FWVERP2P(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonNAS_AND_CMS_FWVERP2P_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonNAS_AND_CMS_REBOOT_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_nas_channel_common_set_reboot(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonNAS_AND_CMS_REBOOT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonNAS_AND_CMS_REBOOT_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonNAS_AND_CMS_TIMEZONE_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_nas_channel_common_set_timezone(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_nas_channel_common_get_timezone(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonNAS_AND_CMS_TIMEZONE(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonNAS_AND_CMS_TIMEZONE_OnClick(AobjID, AlParam);
        return 0;
    }

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

    void InheritClass::buttonNAS_AND_CMS_LOCK_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonNAS_AND_CMS_LOCK(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonNAS_AND_CMS_LOCK_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonNAS_AND_CMS_UNLOCK_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonNAS_AND_CMS_UNLOCK(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonNAS_AND_CMS_UNLOCK_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonNAS_AND_CMS_MUTE_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonNAS_AND_CMS_MUTE(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonNAS_AND_CMS_MUTE_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonNAS_AND_CMS_UNMUTE_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonNAS_AND_CMS_UNMUTE(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonNAS_AND_CMS_UNMUTE_OnClick(AobjID, AlParam);
        return 0;
    }


    void InheritClass::buttonNAS_AND_CMS_CALLOUT_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonNAS_AND_CMS_CALLOUT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonNAS_AND_CMS_CALLOUT_OnClick(AobjID, AlParam);
        return 0;
    }

    void InheritClass::buttonNAS_AND_CMS_UNCALLOUT_OnClick(WPARAM AobjID, LPARAM AlParam) {
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }

    LONG WINAPI InheritClass::FireClick_buttonNAS_AND_CMS_UNCALLOUT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam) {
        InheritClass* lpTarget = (InheritClass*)AlpTarget;
        lpTarget->buttonNAS_AND_CMS_UNCALLOUT_OnClick(AobjID, AlParam);
        return 0;
    }

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)

    void InheritClass::OnTimer(void)
    {
#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)

        if (libpiziot_core_p2p_cms_ipcamera_channel_common_set_timezone(cms_viewer_ipcamera_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_ipcamera_channel_common_get_timezone(cms_viewer_ipcamera_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)

        if (libpiziot_core_p2p_cms_nas_channel_common_set_timezone(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_nas_channel_common_get_timezone(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)

        if (libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock(cms_viewer_nas_ref, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if (libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock(cms_viewer_nas_ref) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }

#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
    }
}

#endif //defined(ENABLE_MFC_GUI)

#endif //defined(WIN32)
