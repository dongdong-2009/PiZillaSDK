#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message (" Include "__FILE__)
#endif

#ifdef USE_Compiler_Step_info
#pragma message (" Declare Class LibPIZIOTClass::LibPIZIOTGuiResourceBitmap")
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)


namespace LibPIZIOTClass {
    class LibPIZIOTGuiResourceBitmap;
}

#include "def_libpiziot_mfc_gui_pos.h"

namespace LibPIZIOTClass {

    class LibPIZIOTGuiResourceBitmap {

    public:

        LibPIZIOTGuiResourceBitmap(CDC *AlpDC, int AiIDB);

        virtual ~LibPIZIOTGuiResourceBitmap();

    private:

        bool FbInitOk;

        int FiIDB;
        CBitmap FobjBitmap;
        BITMAP FresBitmap;
        CDC Fdc;
        int FiOffsetPaintLeft;
        int FiOffsetPaintTop;
        int FiOffsetPaintRight;
        int FiOffsetPaintBottom;

        bool GDI_PaintRepeatXY(CDC *AlpDC, const int &AiLeft, const int &AiTop, const int &AiWidth, const int &AiHeight);

    public:

        int GetDefaultWidth();

        int GetDefaultHeight();

        CDC *GetFDC();

        bool Paint(CDC *AlpDC, int AiLeft, int AiTop);

        //bool PaintRepeatX(CDC* AlpDC,int AiLeft,int AiRight,int AiTop);
        //bool PaintRepeatY(CDC* AlpDC,int AiTop,int AiBottom,int AiLeft);
        bool GDI_PaintRepeatXY(CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos Aguipos);

        bool GDI_DrawBitBlt(CDC *AlpDC, LibPIZIOTClass::LibPIZIOTGuiPos Aguipos);

        static void GDI_DrawLine(CDC *AlpDC, const COLORREF &AcolorCOLORREF, const int &AiX1, const int &AiY1, const int &AiX2, const int &AiY2);

        static void GDI_DrawRectangle(CDC *AlpDC, const COLORREF &Acolor, const LibPIZIOTClass::LibPIZIOTGuiPos &Aguipos);

        static void GDI_DrawRectangle(CDC *AlpDC, const COLORREF &Acolor, const int &AiX1, const int &AiY1, const int &AiX2, const int &AiY2);

        static void GDI_FillBackground(CDC *AlpDC, const COLORREF &Acolor, const LibPIZIOTClass::LibPIZIOTGuiPos &Aguipos);

        static void GDI_FillBackground(CDC *AlpDC, const COLORREF &Acolor, const int &AiX1, const int &AiY1, const int &AiX2, const int &AiY2);

        static void GDI_GradientFillBackground(CDC *AlpDC, const COLORREF &AcolorSource, const COLORREF &AcolorDest, const LibPIZIOTClass::LibPIZIOTGuiPos &Aguipos);

        static void GDI_GradientFillBackgroundX(CDC *AlpDC, const COLORREF &AcolorSource, const COLORREF &AcolorDest, const int &AiX1, const int &AiY1, const int &AiX2, const int &AiY2);

        void SetOffsetPaint(const int &AiOffsetPaintLeft, const int &AiOffsetPaintTop, const int &AiOffsetPaintRight, const int &AiOffsetPaintBottom);
    };

}

#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
