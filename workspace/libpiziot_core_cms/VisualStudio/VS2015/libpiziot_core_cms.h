// libpiziot_core_cms.h : libpiziot_core_cms DLL 的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clibpiziot_core_cmsApp
// 這個類別的實作請參閱 libpiziot_core_cms.cpp
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
