// libpiziot_core_cms.h : libpiziot_core_cms DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clibpiziot_core_cmsApp
// �o�����O����@�аѾ\ libpiziot_core_cms.cpp
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
