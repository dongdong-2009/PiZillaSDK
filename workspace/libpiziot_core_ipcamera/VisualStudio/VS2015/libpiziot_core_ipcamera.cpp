// libpiziot_core_ipcamera.cpp : 定義 DLL 的初始化常式。
//

#include "stdafx.h"
#include "libpiziot_core_ipcamera.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果這個 DLL 是動態地對 MFC DLL 連結，
//		那麼從這個 DLL 匯出的任何會呼叫
//		MFC 內部的函式，都必須在函式一開頭加上 AFX_MANAGE_STATE
//		巨集。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此處為正常函式主體
//		}
//
//		這個巨集一定要出現在每一個
//		函式中，才能夠呼叫 MFC 的內部。這意味著
//		它必須是函式內的第一個陳述式
//		，甚至必須在任何物件變數宣告前面
//		，因為它們的建構函式可能會產生對 MFC
//		DLL 內部的呼叫。
//
//		請參閱 MFC 技術提示 33 和 58 中的
//		詳細資料。
//

// Clibpiziot_core_ipcameraApp

BEGIN_MESSAGE_MAP(Clibpiziot_core_ipcameraApp, CWinApp)
END_MESSAGE_MAP()


// Clibpiziot_core_ipcameraApp construction

Clibpiziot_core_ipcameraApp::Clibpiziot_core_ipcameraApp()
{
	// TODO:  add construction code here,
	// Place all significant initialization in InitInstance
}


// // The one and only Clibpiziot_core_ipcameraApp object

Clibpiziot_core_ipcameraApp theApp;


// Clibpiziot_core_ipcameraApp initialization

BOOL Clibpiziot_core_ipcameraApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
