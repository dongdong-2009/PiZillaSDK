// libpiziot_core_nas.h : libpiziot_core_nas DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clibpiziot_core_nasApp
// 這個類別的實作請參閱 libpiziot_core_nas.cpp
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
