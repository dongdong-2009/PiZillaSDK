#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message (" Include "__FILE__)
#endif

#ifdef USE_Compiler_Step_info
#pragma message (" Declare Class LibPIZIOTClass::LibPIZIOTGuiObj")
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

namespace LibPIZIOTClass {
    class LibPIZIOTGuiObj;
}

#include "def_libpiziot_mfc_gui_pos.h"
#include "def_libpiziot_mfc_gui_resource_bitmap.h"

namespace LibPIZIOTClass {
    class LibPIZIOTGuiObj {
    public:

        LibPIZIOTGuiObj(CWnd *AlpCWnd, void *AlpTarget, int AiIDC_CURSOR_HAND);

        virtual ~LibPIZIOTGuiObj();

    protected:
        CWnd *FlpCWnd;
        void *FlpTarget;
        HCURSOR Fhc_ARROW; //滑鼠圖示(箭頭)
        HCURSOR Fhc_HAND; //滑鼠圖示(手)
        bool FbVisible;
        bool FbEnableLookUpdateCursor;

        virtual bool PtInRect(CPoint point) = 0;

        virtual int GetLeft() = 0;

        virtual int GetTop() = 0;

        virtual int GetDefaultWidth() = 0;

        virtual int GetDefaultHeight() = 0;

    private:
        CFont m_Font_Caption;
        LOGFONT *m_pLF_Caption;
        int iFontSize;

    public:
        LibPIZIOTClass::LibPIZIOTGuiPos guipos;

        virtual bool LookUpdateCursor(UINT nFlags, CPoint point, bool AbEnabled, bool AbBusy) = 0;

        virtual bool LookLButtonDown(const UINT &nFlags, const CPoint &point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos &AguiposButtonDown, const bool &AbEnabled, const bool &AbBusy, bool &AbFound) = 0;

        virtual bool LookMouseMove(UINT nFlags, CPoint point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos AguiposButtonDown, bool AbEnabled, bool AbBusy, bool &AbFound) = 0;

        virtual bool LookLButtonUp(UINT nFlags, CPoint point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos AguiposButtonDown, bool AbEnabled, bool AbBusy, bool &AbFound) = 0;

        virtual bool LookLButtonDblClk(const UINT &nFlags, const CPoint &point, CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos &AguiposButtonDown, const bool &AbEnabled, const bool &AbBusy, bool &AbFound) = 0;

        virtual void DrawCommandBitmap(CDC *AlpDC, bool AbEnabled, bool AbBusy) = 0;

    };

}

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
