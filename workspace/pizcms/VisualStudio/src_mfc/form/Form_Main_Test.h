#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message (" Include "__FILE__)
#endif

#ifdef USE_Compiler_Step_info
#pragma message (" Declare Class LibPIZIOTClass::Form_Main_Test")
#endif

#include "resource.h"
#include "libpiziot/libpiziot_mfc_gui/def_libpiziot_mfc_dautptr.h"

#include "../../../../libpiziot_core_cms/Linux/include/menu_config.h"

#if defined(ENABLE_MFC_GUI)

#include "libpiziot/libpiziot_mfc_gui/def_libpiziot_mfc_gui.h"
#include "form_type_define.h"
#include "libpiziot/libpiziot_mfc_gui/class_def/def_libpiziot_mfc_gui_status_bitmap.h"
#include "libpiziot/libpiziot_mfc_gui/class_def/def_libpiziot_mfc_gui_button.h"
#include "libpiziot/libpiziot_mfc_gui/class_def/def_libpiziot_mfc_gui_Form_Base.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#include "../../../Linux/src/pizcms/pizcms_main.h"

namespace LibPIZIOTClass
{
    class Form_Main_Test;
}

namespace LibPIZIOTClass
{
    enum DIALOG_MAIN_TEST_OBJECT_ID
    {
        DIALOG_MAIN_TEST_OBJECT_ID_RETURN = 2000,
#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
        DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_MODEL,
        DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_FWVERP2P,
        DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_REBOOT,
        DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_CMS_TIMEZONE,
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)
#if defined(ENABLE_P2P_NAS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
        DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_MODEL,
        DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_FWVERP2P,
        DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_REBOOT,
        DIALOG_MAIN_TEST_OBJECT_ID_IPCAMERA_AND_NAS_TIMEZONE,
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
        DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_MODEL,
        DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_FWVERP2P,
        DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_REBOOT,
        DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_TIMEZONE,
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
        DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_LOCK,
        DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNLOCK,
        DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_MUTE,
        DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNMUTE,
        DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_CALLOUT,
        DIALOG_MAIN_TEST_OBJECT_ID_NAS_AND_CMS_UNCALLOUT,
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
    };

    class Form_Main_Test : public LibPIZIOTClass::Form_Base
    {
    private:

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiStatusBitmap> objMAIN_DIALOG_TEST;

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonRETURN;
        void buttonRETURN_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonRETURN(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonIPCAMERA_AND_CMS_MODEL;
        void buttonIPCAMERA_AND_CMS_MODEL_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonIPCAMERA_AND_CMS_MODEL(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonIPCAMERA_AND_CMS_FWVERP2P;
        void buttonIPCAMERA_AND_CMS_FWVERP2P_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonIPCAMERA_AND_CMS_FWVERP2P(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonIPCAMERA_AND_CMS_REBOOT;
        void buttonIPCAMERA_AND_CMS_REBOOT_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonIPCAMERA_AND_CMS_REBOOT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonIPCAMERA_AND_CMS_TIMEZONE;
        void buttonIPCAMERA_AND_CMS_TIMEZONE_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonIPCAMERA_AND_CMS_TIMEZONE(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_CMS)

#if defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)
#if defined(ENABLE_P2P_NAS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonIPCAMERA_AND_NAS_MODEL;
        void buttonIPCAMERA_AND_NAS_MODEL_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonIPCAMERA_AND_NAS_MODEL(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonIPCAMERA_AND_NAS_FWVERP2P;
        void buttonIPCAMERA_AND_NAS_FWVERP2P_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonIPCAMERA_AND_NAS_FWVERP2P(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonIPCAMERA_AND_NAS_REBOOT;
        void buttonIPCAMERA_AND_NAS_REBOOT_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonIPCAMERA_AND_NAS_REBOOT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonIPCAMERA_AND_NAS_TIMEZONE;
        void buttonIPCAMERA_AND_NAS_TIMEZONE_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonIPCAMERA_AND_NAS_TIMEZONE(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND_COMMON)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
#endif //defined(ENABLE_P2P_NAS)
#endif //defined(ENABLE_SAMPLE_CODE_IPCAMERA_AND_NAS)

#if defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)
#if defined(ENABLE_P2P_CMS)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonNAS_AND_CMS_MODEL;
        void buttonNAS_AND_CMS_MODEL_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonNAS_AND_CMS_MODEL(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonNAS_AND_CMS_FWVERP2P;
        void buttonNAS_AND_CMS_FWVERP2P_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonNAS_AND_CMS_FWVERP2P(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonNAS_AND_CMS_REBOOT;
        void buttonNAS_AND_CMS_REBOOT_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonNAS_AND_CMS_REBOOT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonNAS_AND_CMS_TIMEZONE;
        void buttonNAS_AND_CMS_TIMEZONE_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonNAS_AND_CMS_TIMEZONE(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_COMMON)
#if defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonNAS_AND_CMS_LOCK;
        void buttonNAS_AND_CMS_LOCK_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonNAS_AND_CMS_LOCK(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonNAS_AND_CMS_UNLOCK;
        void buttonNAS_AND_CMS_UNLOCK_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonNAS_AND_CMS_UNLOCK(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonNAS_AND_CMS_MUTE;
        void buttonNAS_AND_CMS_MUTE_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonNAS_AND_CMS_MUTE(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonNAS_AND_CMS_UNMUTE;
        void buttonNAS_AND_CMS_UNMUTE_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonNAS_AND_CMS_UNMUTE(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonNAS_AND_CMS_CALLOUT;
        void buttonNAS_AND_CMS_CALLOUT_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonNAS_AND_CMS_CALLOUT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);

        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> buttonNAS_AND_CMS_UNCALLOUT;
        void buttonNAS_AND_CMS_UNCALLOUT_OnClick(WPARAM AobjID, LPARAM AlParam);
        static LONG WINAPI FireClick_buttonNAS_AND_CMS_UNCALLOUT(void* AlpTarget, WPARAM AobjID, LPARAM AlParam);
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND_SECURITY_SYSTEM)
#endif //defined(LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
#endif //defined(ENABLE_P2P_CMS)
#endif //defined(ENABLE_SAMPLE_CODE_NAS_AND_CMS)

    public:
        Form_Main_Test(CWnd* AlpCWnd, LibPIZIOTClass::LibPIZIOTGuiListObj* AlpObjLibPIZIOTGuiListObj);
        virtual ~Form_Main_Test();

        void OnTimer(void);
    };

}

#endif //defined(ENABLE_MFC_GUI)
