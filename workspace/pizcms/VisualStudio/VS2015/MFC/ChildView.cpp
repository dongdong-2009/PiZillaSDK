// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#include "PIZCms.h"
#include "ChildView.h"

#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"
#include "libpiziot/libpiziot_core_cms/def_libpiziot_core_cms.h"
#include "../../../Linux/src/pizcms/pizcms_main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#if defined(ENABLE_MFC_GUI)
static CChildView* FlpChildView = 0;
#endif //defined(ENABLE_MFC_GUI)

// CChildView
IMPLEMENT_DYNAMIC(CChildView, CWnd)

typedef CWnd BaseClass;
typedef CChildView InheritClass;

// CChildView

InheritClass::CChildView()
{
}

InheritClass::~CChildView()
{
}

void InheritClass::Init(CFrameWnd* AlpCFrameWnd)
{
#if defined(ENABLE_MFC_GUI)
	this->FlpForm_Base = 0;
	FlpChildView = this;
#endif //defined(ENABLE_MFC_GUI)

#if defined(ENABLE_MFC_GUI)
	this->ObjLibPIZIOTGuiListObj.assign(new LibPIZIOTClass::LibPIZIOTGuiListObj(this), true);
	lplibpiziot_core_cms_event = Fire_IOCTRL;
#endif //defined(ENABLE_MFC_GUI)

	if (libpiziot_core_cms_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS)
	{
		::PostMessage(pFrame->GetSafeHwnd(), WM_CLOSE, WPARAM(0), LPARAM(0));
		return;
	}
	if (pizcms_main_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
		::PostMessage(pFrame->GetSafeHwnd(), WM_CLOSE, WPARAM(0), LPARAM(0));
		return;
	}

#if defined(ENABLE_MFC_GUI)
	this->FiLastFormId = -1;
	this->LoadDebugGUI(this, this->ObjLibPIZIOTGuiListObj, 0, LibPIZIOTClass::FORM_ID_DIALOG_FORM_MAIN_LIST);
#endif //defined(ENABLE_MFC_GUI)
}

void InheritClass::DeInit(void)
{
#if defined(ENABLE_MFC_GUI)
	this->DestoryDebugGUI(this->ObjLibPIZIOTGuiListObj);
	if (this->ObjLibPIZIOTGuiListObj != 0) this->ObjLibPIZIOTGuiListObj->Destroy();
#endif //defined(ENABLE_MFC_GUI)

	libpiziot_core_cms_sigterm_handler(SIGINT);
	pizcms_main_finalize();
	libpiziot_core_cms_finalize();
}

BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
#if defined(ENABLE_MFC_GUI)
	ON_WM_TIMER()
	ON_WM_SETCURSOR()
	ON_MESSAGE(LibPIZIOTClass::WM_USER_ChangeForm, OnChangeForm)
#endif //defined(ENABLE_MFC_GUI)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL InheritClass::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

#if defined(ENABLE_MFC_GUI)
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
#else
	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
#endif //defined(ENABLE_MFC_GUI)

	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), NULL);

	return TRUE;
}

void InheritClass::OnPaint()
{

	// TODO: Add your message handler code here
#if defined(ENABLE_MFC_GUI) && defined(ENABLE_MFC_GUI)
	bool bEnabled = true;
	bool bBusy = false;

	CPaintDC dc(this);
	CDC* lpDC = &dc;

	if (this->ObjLibPIZIOTGuiListObj != 0) this->ObjLibPIZIOTGuiListObj->DrawCommandBitmap(lpDC, bEnabled, bBusy);
#else
	CPaintDC dc(this); // device context for painting
#endif //defined(ENABLE_MFC_GUI) && defined(ENABLE_MFC_GUI)

// Do not call CWnd::OnPaint() for painting messages
}

BOOL InheritClass::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	BOOL rval = TRUE;
	do
	{
		POINT p;
		RECT rc;
		if (!::GetCursorPos(&p)) break;
		if (!::ScreenToClient(pWnd->GetSafeHwnd(), &p)) break;
		pWnd->GetClientRect(&rc);
		if ((p.x < rc.left) || (p.y < rc.top) || (p.x >= rc.right) || (p.y >= rc.bottom))
		{
			rval = BaseClass::OnSetCursor(pWnd, nHitTest, message);
		}
	} while (0);
	return rval;
}

#if defined(ENABLE_MFC_GUI)
void InheritClass::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case InheritClass::TIMERID_GetDIALOGInfo:
	{
		this->KillTimer(nIDEvent);
		if (this->FlpForm_Base != 0)
		{
			this->FlpForm_Base->OnTimer();
		}
		this->SetTimer(InheritClass::TIMERID_GetDIALOGInfo, 5000, NULL);
	}
	break;
	default:
	{
	}
	break;
	}
}
#endif //defined(ENABLE_MFC_GUI)

#if defined(ENABLE_MFC_GUI)
LONG WINAPI InheritClass::Fire_IOCTRL(unsigned int AnIOCtrlType, unsigned char* AlpChar, uint32_t Asize)
{
	switch (FlpChildView->FiLastFormId)
	{
	case LibPIZIOTClass::FORM_ID_DIALOG_FORM_MAIN_LIST: {FlpChildView->ObjForm_Main_List->Fire_IOCTRL(AnIOCtrlType, AlpChar, Asize); }break;
	case LibPIZIOTClass::FORM_ID_DIALOG_FORM_MAIN_TEST: {FlpChildView->ObjForm_Main_Test->Fire_IOCTRL(AnIOCtrlType, AlpChar, Asize); }break;
	default:
	{
	}
	break;
	}
	return 0;
}
#endif //defined(ENABLE_MFC_GUI)

BOOL InheritClass::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
#if defined(ENABLE_MFC_GUI)
	return TRUE;
#else
	return BaseClass::OnEraseBkgnd(pDC);
#endif //defined(ENABLE_MFC_GUI)
}

void InheritClass::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	BaseClass::OnLButtonDown(nFlags, point);

#if defined(ENABLE_MFC_GUI)
	if (this->ObjLibPIZIOTGuiListObj != 0)
	{
		//bool bResult = this->ObjLibPIZIOTGuiListObj->UpdateCursorStatus(nFlags,point);
		this->ObjLibPIZIOTGuiListObj->OnLButtonDown(nFlags, point);
	}
#endif //defined(ENABLE_MFC_GUI)
}

void InheritClass::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	BaseClass::OnLButtonDblClk(nFlags, point);

#if defined(ENABLE_MFC_GUI)
	if (this->ObjLibPIZIOTGuiListObj != 0)
	{
		//bool bResult = this->ObjLibPIZIOTGuiListObj->UpdateCursorStatus(nFlags,point);
		this->ObjLibPIZIOTGuiListObj->OnLButtonDblClk(nFlags, point);
	}
#endif //defined(ENABLE_MFC_GUI)
}

void InheritClass::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	BaseClass::OnMouseMove(nFlags, point);

#if defined(ENABLE_MFC_GUI)
	if (this->ObjLibPIZIOTGuiListObj != 0)
	{
		this->ObjLibPIZIOTGuiListObj->OnMouseMove(nFlags, point);
	}
#endif //defined(ENABLE_MFC_GUI)
}

void InheritClass::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	BaseClass::OnLButtonUp(nFlags, point);

#if defined(ENABLE_MFC_GUI)
	if (this->ObjLibPIZIOTGuiListObj != 0)
	{
		this->ObjLibPIZIOTGuiListObj->OnLButtonUp(nFlags, point);
	}
#endif //defined(ENABLE_MFC_GUI)
}

#if defined(ENABLE_MFC_GUI)
void InheritClass::LoadDebugGUI(CWnd* AlpCWnd, LibPIZIOTClass::LibPIZIOTGuiListObj* AlpObjLibPIZIOTGuiListObj, WPARAM Alayer, WPARAM AFormId)
{
	switch (AFormId)
	{
	case LibPIZIOTClass::FORM_ID_DIALOG_FORM_MAIN_LIST: {this->ObjForm_Main_List.assign(new LibPIZIOTClass::Form_Main_List(AlpCWnd, AlpObjLibPIZIOTGuiListObj), true); this->FlpForm_Base = this->ObjForm_Main_List; }break;
	case LibPIZIOTClass::FORM_ID_DIALOG_FORM_MAIN_TEST: {this->ObjForm_Main_Test.assign(new LibPIZIOTClass::Form_Main_Test(AlpCWnd, AlpObjLibPIZIOTGuiListObj), true); this->FlpForm_Base = this->ObjForm_Main_Test; }break;
	default:
	{
	}
	break;
	}
	this->SetTimer(InheritClass::TIMERID_GetDIALOGInfo, 1, NULL);
	this->FiLastFormId = AFormId;
	this->m_ReturnFormID.push_back(AFormId);
}

void InheritClass::DestoryDebugGUI(LibPIZIOTClass::LibPIZIOTGuiListObj* AlpObjLibPIZIOTGuiListObj)
{
	switch (this->FiLastFormId)
	{
	case LibPIZIOTClass::FORM_ID_DIALOG_FORM_MAIN_LIST: {this->ObjForm_Main_List.assign(0, true); }break;
	case LibPIZIOTClass::FORM_ID_DIALOG_FORM_MAIN_TEST: {this->ObjForm_Main_Test.assign(0, true); }break;
	default:
	{
	}
	break;
	}
	this->FlpForm_Base = 0;
	this->KillTimer(InheritClass::TIMERID_GetDIALOGInfo);
	this->FiLastFormId = -1;

}

LRESULT InheritClass::OnChangeForm(WPARAM wParam, LPARAM lParam)
{
	this->DestoryDebugGUI(this->ObjLibPIZIOTGuiListObj);
	this->LoadDebugGUI(this, this->ObjLibPIZIOTGuiListObj, wParam, lParam);
	return 0;
}

WPARAM InheritClass::GetReturnFormID(void)
{
	WPARAM form_id = -1;
	if (this->m_ReturnFormID.size() >= 2)
	{
		size_t pos = this->m_ReturnFormID.size() - 2;
		std::vector<WPARAM>::const_iterator it;
		form_id = this->m_ReturnFormID.at(pos);
		it = this->m_ReturnFormID.end(); it--; this->m_ReturnFormID.erase(it);
		it = this->m_ReturnFormID.end(); it--; this->m_ReturnFormID.erase(it);
	}
	return form_id;
}

#endif //defined(ENABLE_MFC_GUI)
