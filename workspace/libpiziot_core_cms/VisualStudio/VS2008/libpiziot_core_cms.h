// libpiziot_core_cms.h : main header file for the libpiziot_core_cms DLL
//

#pragma once

#if defined(WIN32)

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clibpiziot_core_cmsApp
// See libpiziot_core_cms.cpp for the implementation of this class
//

class Clibpiziot_core_cmsApp : public CWinApp
{
public:
	Clibpiziot_core_cmsApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

#endif //defined(WIN32)
