// libpiziot_core_ipcamera.h : libpiziot_core_ipcamera DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clibpiziot_core_ipcameraApp
// �o�����O����@�аѾ\ libpiziot_core_ipcamera.cpp
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
