// libpiziot_core_nas.h : main header file for the libpiziot_core_nas DLL
//

#pragma once

#if defined(WIN32)

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clibpiziot_core_nasApp
// See libpiziot_core_nas.cpp for the implementation of this class
//

class Clibpiziot_core_nasApp : public CWinApp
{
public:
	Clibpiziot_core_nasApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

#endif //defined(WIN32)
