// libpiziot_core_ipcamera.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"

#if defined(WIN32)

#include "libpiziot_core_ipcamera.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// Clibpiziot_core_ipcameraApp

BEGIN_MESSAGE_MAP(Clibpiziot_core_ipcameraApp, CWinApp)
END_MESSAGE_MAP()


// Clibpiziot_core_ipcameraApp construction

Clibpiziot_core_ipcameraApp::Clibpiziot_core_ipcameraApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only Clibpiziot_core_ipcameraApp object

Clibpiziot_core_ipcameraApp theApp;


// Clibpiziot_core_ipcameraApp initialization

BOOL Clibpiziot_core_ipcameraApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

#endif //defined(WIN32)
