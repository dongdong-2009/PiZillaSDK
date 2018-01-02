// MainFrm.h : interface of the CMainFrame class
//

#pragma once

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#include "../../../../libpiziot_core_cms/Linux/include/menu_config.h"

#include "ChildView.h"

class CMainFrame: public CFrameWnd
{

public:
    CMainFrame();
protected:
    DECLARE_DYNAMIC(CMainFrame)

    // Attributes
public:

    // Operations
public:

    // Overrides
public:
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

    // Implementation
public:
    virtual ~CMainFrame();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected: // control bar embedded members
#if 0
    CStatusBar m_wndStatusBar;
    CToolBar m_wndToolBar;
#endif //0
    CChildView m_wndView;

    // Generated message map functions
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSetFocus(CWnd *pOldWnd);
    afx_msg void OnDestroy();
    afx_msg void OnClose();
    DECLARE_MESSAGE_MAP()

public:

private:
    void AdjustWindowsSize(int Ares_id);
};

