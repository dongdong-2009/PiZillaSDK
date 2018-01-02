
// PIZCms.h : PIZCms main header file for the MFCApplication1 application
//
#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols

#include "MainFrm.h"

// CPIZCmsApp:
// See PIZCms.cpp for the implementation of this class
//

class CPIZCmsApp : public CWinApp
{
public:
    CPIZCmsApp();


    // Overrides
public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();

    // Implementation

public:
    afx_msg void OnAppAbout();
    DECLARE_MESSAGE_MAP()
};

extern CPIZCmsApp theApp;
extern CMainFrame* pFrame;
