// libpiziot_core_ipcamera.h : main header file for the libpiziot_core_ipcamera DLL
//

#pragma once

#if defined(WIN32)

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clibpiziot_core_ipcameraApp
// See libpiziot_core_ipcamera.cpp for the implementation of this class
//

class Clibpiziot_core_ipcameraApp : public CWinApp
{
public:
	Clibpiziot_core_ipcameraApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

#endif //defined(WIN32)
