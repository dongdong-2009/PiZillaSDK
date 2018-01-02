// libpiziot_core_ipcamera.h : libpiziot_core_ipcamera DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clibpiziot_core_ipcameraApp
// 這個類別的實作請參閱 libpiziot_core_ipcamera.cpp
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
