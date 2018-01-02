#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message (" Include "__FILE__)
#endif

#ifdef USE_Compiler_Step_info
#pragma message (" Declare Class LibPIZIOTClass::LibPIZIOTGuiListObj")
#endif

//#include "resource.h"

#include "libpiziot/libpiziot_mfc_gui/def_libpiziot_mfc_dautptr.h"
#include <vector>

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#include <afxmt.h>
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#include "def_libpiziot_mfc_gui_button.h"
#include "def_libpiziot_mfc_gui_status_bitmap.h"
#include "def_libpiziot_mfc_gui_label.h"

namespace LibPIZIOTClass {
    class LibPIZIOTGuiListObj;
}

namespace LibPIZIOTClass {
    typedef enum LibPIZIOTGuiObjType_enum {
        ResourceType_LibPIZIOTGuiButton,
        ResourceType_LibPIZIOTGuiStatusBitmap,
        ResourceType_LibPIZIOTGuiLabel,
    } LibPIZIOTGuiObjType_e;

    typedef struct LibPIZIOTGuiObjInfoLabel_s {
        int iIDC_CURSOR_HAND;
        int Left;
        int Top;
        int Width;
        int Height;
        CString strCaption;
        COLORREF colorCOLORREF;
        COLORREF backgroundCOLORREF;
        LibPIZIOTClass::EVENT_Click_LibPIZIOTGuiLabel_p lpClick;
    } LibPIZIOTGuiObjInfoLabel_t;

    typedef struct LibPIZIOTGuiObjInfoBitmap_s {
        int iIDC_CURSOR_HAND;
        int Left;
        int Top;
        int Width;
        int Height;
        CString strCaption;
        COLORREF colorCOLORREF;
        COLORREF backgroundCOLORREF;
        int iIDB_NORMAL;
        int iIDB_FOCUS;
        int iIDB_DOWN;
        int iIDB_DISABLE;
        LibPIZIOTClass::EVENT_Click_LibPIZIOTGuiStatusBitmap_p lpClick;
    } LibPIZIOTGuiObjInfoBitmap_t;

    typedef struct LibPIZIOTGuiObjInfoButton_s {
        int iIDC_CURSOR_HAND;
        int Left;
        int Top;
        int Width;
        int Height;
        CString strCaption;
        COLORREF colorCOLORREF;
        COLORREF backgroundCOLORREF;
        int iIDB_NORMAL;
        int iIDB_FOCUS;
        int iIDB_DOWN;
        int iIDB_DISABLE;
        int iIDB_CHECK;
        LibPIZIOTClass::EVENT_Click_LibPIZIOTGuiButton_p lpClick;
        WPARAM lpClick_wParam;
        LPARAM lpClick_lParam;
        LibPIZIOTClass::EVENT_DoubleClick_LibPIZIOTGuiButton_p lpDoubleClick;
        WPARAM lpDoubleClick_wParam;
        LPARAM lpDoubleClick_lParam;
        LibPIZIOTClass::EVENT_MouseDown_LibPIZIOTGuiButton_p lpMouseDown;
        WPARAM lpMouseDown_wParam;
        LPARAM lpMouseDown_lParam;
        LibPIZIOTClass::EVENT_MouseUp_LibPIZIOTGuiButton_p lpMouseUp;
        WPARAM lpMouseUp_wParam;
        LPARAM lpMouseUp_lParam;
    } LibPIZIOTGuiObjInfoButton_t;

    class LibPIZIOTGuiListObj {
    private:
        std::vector<void *> m_ResourceObjLists;
        std::vector<LibPIZIOTGuiObjType_e> m_ResourceTypeLists;
        CWnd *FlpCWnd;
        LibPIZIOTClass::LibPIZIOTGuiPos guiposButtonDown;
        LibPIZIOTClass::LibPIZIOTGuiObj *lpLibPIZIOTGuiObjMouseDown;
        bool SetCapture;
        CCriticalSection mCriticalSection;

    public:
        LibPIZIOTGuiListObj(CWnd *AlpCWnd);

        virtual ~LibPIZIOTGuiListObj();

        void LibPIZIOTGuiListObj::RemoveLibPIZIOTGuiObject(LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> &AObj);

        void LibPIZIOTGuiListObj::RemoveLibPIZIOTGuiObject(LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiStatusBitmap> &AObj);

        void RemoveLibPIZIOTGuiObject(void *AlpObj);

        void RemoveAllLibPIZIOTGuiObject(void);

        void CreateLibPIZIOTGuiLabel(void *AlpTarget, LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiLabel> &AObj, LibPIZIOTClass::LibPIZIOTGuiObjInfoLabel_t *AlpLibPIZIOTGuiObjInfo);

        void CreateLibPIZIOTGuiStatusBitmap(void *AlpTarget, LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiStatusBitmap> &AObjButton, LibPIZIOTClass::LibPIZIOTGuiObjInfoBitmap_t *AlpLibPIZIOTGuiObjInfo);

        void CreateLibPIZIOTGuiButton(void *AlpTarget, LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiButton> &AObjButton, LibPIZIOTClass::LibPIZIOTGuiObjInfoButton_t *AlpLibPIZIOTGuiObjInfo);

        void Destroy();

        void LibPIZIOTGuiListObj::DrawCommandBitmap(CDC *AlpDC, bool AbEnabled, bool AbBusy);

        bool UpdateCursorStatus(UINT nFlags, CPoint point);

        void OnLButtonDown(UINT nFlags, CPoint point);

        void OnLButtonDblClk(UINT nFlags, CPoint point);

        void OnMouseMove(UINT nFlags, CPoint point);

        void OnLButtonUp(UINT nFlags, CPoint point);

    };

}
