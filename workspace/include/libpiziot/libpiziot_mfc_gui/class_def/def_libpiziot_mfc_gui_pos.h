#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#ifdef USE_Compiler_Step_info
#pragma message (" Include "__FILE__)
#endif

#ifdef USE_Compiler_Step_info
#pragma message (" Declare Class LibPIZIOTClass::LibPIZIOTGuiPos")
#endif

//#include "resource.h"
#include "libpiziot/libpiziot_mfc_gui/def_libpiziot_mfc_dautptr.h"

namespace LibPIZIOTClass {
    class LibPIZIOTGuiPos;
}

namespace LibPIZIOTClass {

    class LibPIZIOTGuiPos {
    public:
        int iLeft;
        int iTop;
        int iWidth;
        int iHeight;
        CRect rectRange;

        LibPIZIOTGuiPos();

        LibPIZIOTGuiPos(int AiLeft, int AiTop, int AiWidth, int AiHeight);

        virtual ~LibPIZIOTGuiPos();

        bool PtInRect(CPoint point);
    };

}
