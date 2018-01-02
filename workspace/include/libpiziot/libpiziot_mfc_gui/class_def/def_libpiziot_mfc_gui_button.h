#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message (" Include "__FILE__)
#endif

#ifdef USE_Compiler_Step_info
#pragma message (" Declare Class LibPIZIOTClass::LibPIZIOTGuiButton")
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

namespace LibPIZIOTClass {
    class LibPIZIOTGuiButton;
}

#include "def_libpiziot_mfc_gui_obj.h"

namespace LibPIZIOTClass {
    typedef LONG(WINAPI *EVENT_Click_LibPIZIOTGuiButton_p)(void *AlpTarget, WPARAM wParam, LPARAM lParam);
    typedef LONG(WINAPI *EVENT_DoubleClick_LibPIZIOTGuiButton_p)(void *AlpTarget, WPARAM wParam, LPARAM lParam);
    typedef LONG(WINAPI *EVENT_MouseDown_LibPIZIOTGuiButton_p)(void *AlpTarget, WPARAM wParam, LPARAM lParam);
    typedef LONG(WINAPI *EVENT_MouseUp_LibPIZIOTGuiButton_p)(void *AlpTarget, WPARAM wParam, LPARAM lParam);

    class LibPIZIOTGuiButton : public LibPIZIOTGuiObj {
    public:

        LibPIZIOTGuiButton(CWnd *AlpCWnd, int AiIDB_NORMAL, int AiIDB_FOCUS, int AiIDB_DOWN, int AiIDB_DISABLE, int AiIDB_CHECK, LibPIZIOTClass::EVENT_Click_LibPIZIOTGuiButton_p AlpClick, WPARAM AlpClick_wParam, LPARAM AlpClick_lParam, LibPIZIOTClass::EVENT_DoubleClick_LibPIZIOTGuiButton_p AlpDoubleClick, WPARAM AlpDoubleClick_wParam, LPARAM AlpDoubleClick_lParam, LibPIZIOTClass::EVENT_MouseDown_LibPIZIOTGuiButton_p AlpMouseDown, WPARAM AlpMouseDown_wParam, LPARAM AlpMouseDown_lParam, LibPIZIOTClass::EVENT_MouseUp_LibPIZIOTGuiButton_p AlpMouseUp, WPARAM AlpMouseUp_wParam, WPARAM AlpMouseUp_lParam, void *AlpTarget, int AiIDC_CURSOR_HAND);

        virtual ~LibPIZIOTGuiButton();

    private:
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiResourceBitmap> ObjRes_NORNAL;
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiResourceBitmap> ObjRes_FOCUS;
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiResourceBitmap> ObjRes_DOWN;
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiResourceBitmap> ObjRes_DISABLE;
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiResourceBitmap> ObjRes_CHECK;
        int FiIDB_CHECK;

        bool FbBusy;
        bool FbChecked;
        bool FbEnabled;

        int FiOffsetPaintLeft;
        int FiOffsetPaintTop;
        int FiOffsetPaintRight;
        int FiOffsetPaintBottom;

        LibPIZIOTClass::LibPIZIOTGuiPos FguiposToolTip;
        CString FstrToolTipCaption;
        CString FstrCaption;
        COLORREF FcolorCOLORREF;

        CFont m_Font_Caption;
        LOGFONT *m_pLF_Caption;
        int iFontSize;
        int iFontOffsetTop;

        LibPIZIOTClass::EVENT_Click_LibPIZIOTGuiButton_p FlpClick;
        WPARAM FlpClick_wParam;
        LPARAM FlpClick_lParam;
        LibPIZIOTClass::EVENT_DoubleClick_LibPIZIOTGuiButton_p FlpDoubleClick;
        WPARAM FlpDoubleClick_wParam;
        LPARAM FlpDoubleClick_lParam;
        LibPIZIOTClass::EVENT_MouseDown_LibPIZIOTGuiButton_p FlpMouseDown;
        WPARAM FlpMouseDown_wParam;
        LPARAM FlpMouseDown_lParam;
        LibPIZIOTClass::EVENT_MouseUp_LibPIZIOTGuiButton_p FlpMouseUp;
        WPARAM FlpMouseUp_wParam;
        WPARAM FlpMouseUp_lParam;

        int gettimeofday(struct timeval *tv, struct timezone *tz);

    public:

        enum DrawStatus {
            EDrawStatusNormal, //一般
            EDrawStatusFocus, //移到上方
            EDrawStatusDown, //按下
            EDrawStatusDisable //失效
        };

        LibPIZIOTClass::LibPIZIOTGuiButton::DrawStatus eDrawStatus;

        bool PtInRect(CPoint point);

        int GetLeft();

        int GetTop();

        int GetDefaultWidth();

        int GetDefaultHeight();

        bool LookUpdateCursor(UINT nFlags, CPoint point, bool AbEnabled, bool AbBusy);

        bool LookLButtonDown(const UINT &nFlags, const CPoint &point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos &AguiposButtonDown, const bool &AbEnabled, const bool &AbBusy, bool &AbFound);

        bool LookLButtonDblClk(const UINT &nFlags, const CPoint &point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos &AguiposButtonDown, const bool &AbEnabled, const bool &AbBusy, bool &AbFound);

        bool LookMouseMove(UINT nFlags, CPoint point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos AguiposButtonDown, bool AbEnabled, bool AbBusy, bool &AbFound);

        bool LookLButtonUp(UINT nFlags, CPoint point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos AguiposButtonDown, bool AbEnabled, bool AbBusy, bool &AbFound);

        void DrawCommandBitmap(CDC *AlpDC, bool AbEnabled, bool AbBusy);

        void TextOutCaption(CDC *AlpDC, CPoint ptPoint, COLORREF colorCOLORREF, CString AstrCaption);

        virtual void SetMouseEnable(bool AbEnabled);

        bool GetMouseIsEnable();

        bool GetBusy();

        void SetCheck(bool AbChecked);

        bool GetCheck();

        void SetVisible(bool AbVisible);

        bool GetVisible();

        typedef void (CALLBACK *EVENT_Click)(void *AlpObject); EVENT_Click lpClick;

        void SetToolTipInfo(LibPIZIOTClass::LibPIZIOTGuiPos AguiposToolTip, CString AstrToolTipCaption);

        void GetToolTipInfo(LibPIZIOTClass::LibPIZIOTGuiPos &AguiposToolTip, CString &AstrToolTipCaption);

        void SetCaption(CString AstrCaption);

        void GetCaption(CString &AstrCaption);

        void SetCaptionColor(COLORREF AcolorCOLORREF);

        void SetBusy(const bool &AbBusy);

        void SetOffsetPaint(const int &AiOffsetPaintLeft, const int &AiOffsetPaintTop, const int &AiOffsetPaintRight, const int &AiOffsetPaintBottom);
    };

}

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
