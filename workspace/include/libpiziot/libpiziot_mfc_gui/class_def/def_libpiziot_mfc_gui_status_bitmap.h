#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message (" Include "__FILE__)
#endif

#ifdef USE_Compiler_Step_info
#pragma message (" Declare Class LibPIZIOTClass::LibPIZIOTGuiStatusBitmap")
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

namespace LibPIZIOTClass {
    class LibPIZIOTGuiStatusBitmap;
}

#include "def_libpiziot_mfc_gui_obj.h"

namespace LibPIZIOTClass {
    typedef LONG(WINAPI
        *EVENT_Click_LibPIZIOTGuiStatusBitmap_p)(void *AlpTarget);

    class LibPIZIOTGuiStatusBitmap : public LibPIZIOTGuiObj {
    public:

        LibPIZIOTGuiStatusBitmap(CWnd *AlpCWnd, int AiIDB_NORMAL, int AiIDB_FOCUS, int AiIDB_DOWN, int AiIDB_DISABLE, LibPIZIOTClass::EVENT_Click_LibPIZIOTGuiStatusBitmap_p AlpClick, void *AlpTarget, int AiIDC_CURSOR_HAND);

        virtual ~LibPIZIOTGuiStatusBitmap();

    private:
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiResourceBitmap> ObjRes_NORMAL;
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiResourceBitmap> ObjRes_FOCUS;
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiResourceBitmap> ObjRes_DOWN;
        LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiResourceBitmap> ObjRes_DISABLE;

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

        LibPIZIOTClass::EVENT_Click_LibPIZIOTGuiStatusBitmap_p FlpClick;

    public:

        enum DrawStatus {
            EDrawStatus_1,
            EDrawStatus_2,
            EDrawStatus_3,
            EDrawStatus_4
        };

        LibPIZIOTClass::LibPIZIOTGuiStatusBitmap::DrawStatus eDrawStatus;

        bool PtInRect(CPoint point);

        int GetLeft();

        int GetTop();

        int GetDefaultWidth();

        int GetDefaultHeight();

        bool LookUpdateCursor(UINT nFlags, CPoint point, bool AbEnabled, bool AbBusy);

        bool LookLButtonDown(const UINT &nFlags, const CPoint &point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos &AguiposButtonDown, const bool &AbEnabled, const bool &AbBusy, bool &AbFound);

        bool LookMouseMove(UINT nFlags, CPoint point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos AguiposButtonDown, bool AbEnabled, bool AbBusy, bool &AbFound);

        bool LookLButtonUp(UINT nFlags, CPoint point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos AguiposButtonDown, bool AbEnabled, bool AbBusy, bool &AbFound);

        bool LookLButtonDblClk(const UINT &nFlags, const CPoint &point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos &AguiposButtonDown, const bool &AbEnabled, const bool &AbBusy, bool &AbFound);

        void DrawCommandBitmap(CDC *AlpDC, bool AbEnabled, bool AbBusy);

        void TextOutCaption(CDC *AlpDC, CPoint ptPoint, COLORREF colorCOLORREF, CString AstrCaption);

        //virtual void SetMouseEnable(bool AbEnabled);
        //bool GetMouseIsEnable();
        void SetDrawStatus(DrawStatus AeDrawStatus);

        bool GetBusy();

        void SetCheck(bool AbChecked);

        bool GetCheck();

        void SetVisible(bool AbVisible);

        bool GetVisible();

        typedef void (CALLBACK *EVENT_Click)(void *AlpObject);
        EVENT_Click lpClick;

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
