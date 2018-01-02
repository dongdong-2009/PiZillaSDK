// ChildView.h : interface of the CChildView class
//

#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#include "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
//#include "libpiziot/libpiziot_mfc_gui/def_libpiziot_mfc_gui.h"
#include "../../../../libpiziot_core_cms/Linux/include/menu_config.h"

#if defined(ENABLE_MFC_GUI)
#include "../../src_mfc/form/Form_Main_List.h"
#include "../../src_mfc/form/Form_Main_Test.h"
#endif //defined(ENABLE_MFC_GUI)

// CChildView window

class CChildView : public CWnd
{
    // Construction
public:
    CChildView();
protected:
    DECLARE_DYNAMIC(CChildView)

    // Attributes
public:

    // Operations
public:

    // Overrides
protected:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

    // Implementation
public:
    virtual ~CChildView();

   // Generated message map functions
protected:
    afx_msg void OnPaint();
    afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    DECLARE_MESSAGE_MAP()

private:
#if defined(ENABLE_MFC_GUI)
    LibPIZIOTClass::CAutoNode<LibPIZIOTClass::LibPIZIOTGuiListObj> ObjLibPIZIOTGuiListObj;
    static LONG WINAPI Fire_IOCTRL(unsigned int AnIOCtrlType, unsigned char* AlpChar, uint32_t Asize);
    enum TIMERID
    {
        TIMERID_GetDIALOGInfo = 123,
    };
    void LoadDebugGUI(CWnd* AlpCWnd, LibPIZIOTClass::LibPIZIOTGuiListObj* AlpObjLibPIZIOTGuiListObj, WPARAM Alayer, WPARAM AFormId);
    void DestoryDebugGUI(LibPIZIOTClass::LibPIZIOTGuiListObj* AlpObjLibPIZIOTGuiListObj);
    LibPIZIOTClass::CAutoNode<LibPIZIOTClass::Form_Main_List> ObjForm_Main_List;
    LibPIZIOTClass::CAutoNode<LibPIZIOTClass::Form_Main_Test> ObjForm_Main_Test;

    LRESULT OnChangeForm(WPARAM wParam, LPARAM lParam);
    LibPIZIOTClass::Form_Base* FlpForm_Base;
    WPARAM FiLastFormId;
    std::vector<WPARAM> m_ReturnFormID;
#endif //defined(ENABLE_MFC_GUI)

    //static LONG WINAPI FireClick_ObjButton_LED_L1_1(void* AlpTarget);
    //static LONG WINAPI FireMouseDown_ObjButton_LED_L1_1(void* AlpTarget);
    //static LONG WINAPI FireMouseUp_ObjButton_LED_L1_1(void* AlpTarget);

public:
    void Init(CFrameWnd* AlpCFrameWnd);
    void DeInit(void);
    WPARAM GetReturnFormID(void);
};

