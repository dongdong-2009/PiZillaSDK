// MainFrm.h : interface of the CMainFrame clas
//

#include "stdafx.h"
#include "PIZCms.h"

#include "MainFrm.h"

#include "libpiziot/libpiziot_os/def_libpiziot_os.h"

#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

#include "../../../../libpiziot_core_cms/Linux/src/piziot_core_cms/piziot_core_cms.h"
#include "../../../Linux/src/pizcms/pizcms_setting.h"

#if defined(ENABLE_MFC_GUI)
#include "../../src_mfc/form/Form_Main_Test.h"
#endif //defined(ENABLE_MFC_GUI)

//#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_DESTROY()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

#if 0
static UINT indicators[] =
{
ID_SEPARATOR, // 狀態列指示器
ID_INDICATOR_CAPS,
ID_INDICATOR_NUM,
ID_INDICATOR_SCRL,
};
#endif //0

// TODO: add member initialization code here

typedef CFrameWnd BaseClass;
typedef CMainFrame InheritClass;

InheritClass::CMainFrame()
{
	// TODO: 在此加入成員初始化程式碼
}

InheritClass::~CMainFrame()
{
}

void InheritClass::AdjustWindowsSize(int Ares_id)
{
#define ENABLE_WS_CAPTION
	//#define ENABLE_WS_SYSMENU

	{
		int nSM_CXSCREEN = GetSystemMetrics(SM_CXSCREEN);
		int nSM_CYSCREEN = GetSystemMetrics(SM_CYSCREEN);
		int nSM_CYCAPTION = ::GetSystemMetrics(SM_CYCAPTION);
		int nSM_CYMENU = ::GetSystemMetrics(SM_CYMENU);
		int nSM_CXDLGFRAME = ::GetSystemMetrics(SM_CXDLGFRAME);
		int nSM_CYDLGFRAME = ::GetSystemMetrics(SM_CYDLGFRAME);
		int nSM_CXBORDER = ::GetSystemMetrics(SM_CXBORDER);
		int nSM_CYBORDER = ::GetSystemMetrics(SM_CYBORDER);
		int nEX_CXBORDER = 0;
		int nEX_CYBORDER = 0;

#if defined(ENABLE_WS_CAPTION)
		//nSM_CXBORDER = 0;
		//nSM_CYBORDER = 0;
		nEX_CXBORDER = (nSM_CXDLGFRAME + nSM_CXBORDER) * 2;
		nEX_CYBORDER = (nSM_CYDLGFRAME + nSM_CYBORDER) * 2;
#else
		this->ModifyStyle(WS_CAPTION, 0);
		nSM_CYCAPTION = 0;
		nSM_CXDLGFRAME = 0;
		nSM_CYDLGFRAME = 0;
		nSM_CXBORDER = 0;
		nSM_CYBORDER = 0;
#endif //defined(ENABLE_WS_CAPTION)
#if defined(ENABLE_WS_SYSMENU)
#else
		this->SetMenu(NULL);
		nSM_CYMENU = 0;
#endif //defined(ENABLE_WS_SYSMENU)

		{
			RECT rc;
			GetWindowRect(&rc);
			ScreenToClient(&rc);
			{
				int width = 320;
				int height = 240;
#if defined(IDB_DIALOG_LIST_NORMAL)
				do
				{
					CBitmap FobjBitmap;
					BOOL fLoadBitmap = FobjBitmap.LoadBitmap(Ares_id);
					if (!fLoadBitmap) break;
					{
						BITMAP FresBitmap;
						int iGetBitmap = FobjBitmap.GetBitmap(&FresBitmap);
						if (iGetBitmap != 0)
						{
							width = FresBitmap.bmWidth;
							height = FresBitmap.bmHeight;
						}
					}
				} while (0);
#endif //defined(IDB_DIALOG_LIST_NORMAL)
				rc.left = (nSM_CXSCREEN - width) / 2;
				rc.top = (nSM_CYSCREEN - height) / 2;
				rc.right = rc.left + width + (nSM_CXDLGFRAME * 2) + (nSM_CXBORDER * 2) + nEX_CXBORDER;
				rc.bottom = rc.top + height + (nSM_CYDLGFRAME * 2) + nSM_CYCAPTION + nSM_CYMENU + (nSM_CYBORDER * 2) + nEX_CYBORDER;

				MoveWindow(&rc);
			}
		}
	}
}

static void libpiziot_mfc_close(void)
{
	if (pFrame != 0)
	{
		PostMessage(pFrame->GetSafeHwnd(), WM_CLOSE, WPARAM(0), LPARAM(0));
	}
}

int InheritClass::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}

	ModifyStyle(WS_MAXIMIZEBOX, 0);

#if 0
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1; // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1; // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
#endif //0

#if defined(ENABLE_MFC_GUI)
	AdjustWindowsSize(IDB_DIALOG_LIST_NORMAL);
#endif //defined(ENABLE_MFC_GUI)

	lplibpiziot_mfc_close = libpiziot_mfc_close;
	m_wndView.Init(this);

	return 0;
}

BOOL InheritClass::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	// the CREATESTRUCT cs

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.style &= (0xFFFFFFFF ^ WS_SIZEBOX);
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void InheritClass::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void InheritClass::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void InheritClass::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL InheritClass::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void InheritClass::OnDestroy()
{
	BaseClass::OnDestroy();
	// TODO: Add your message handler code here
}

void InheritClass::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	m_wndView.DeInit();

	BaseClass::OnClose();
}
