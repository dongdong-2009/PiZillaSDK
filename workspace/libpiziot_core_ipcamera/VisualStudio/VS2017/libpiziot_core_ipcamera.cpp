// libpiziot_core_ipcamera.cpp : �w�q DLL ����l�Ʊ`���C
//

#include "stdafx.h"
#include "libpiziot_core_ipcamera.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  �p�G�o�� DLL �O�ʺA�a�� MFC DLL �s���A
//		����q�o�� DLL �ץX������|�I�s
//		MFC �������禡�A�������b�禡�@�}�Y�[�W AFX_MANAGE_STATE
//		�����C
//
//		�Ҧp: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// ���B�����`�禡�D��
//		}
//
//		�o�ӥ����@�w�n�X�{�b�C�@��
//		�禡���A�~����I�s MFC �������C�o�N����
//		�������O�禡�����Ĥ@�ӳ��z��
//		�A�Ʀܥ����b���󪫥��ܼƫŧi�e��
//		�A�]�����̪��غc�禡�i��|���͹� MFC
//		DLL �������I�s�C
//
//		�аѾ\ MFC �޳N���� 33 �M 58 ����
//		�ԲӸ�ơC
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
