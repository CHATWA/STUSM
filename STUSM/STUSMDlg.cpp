// STUSMDlg.cpp : 实现文件

#include "stdafx.h"
#include "STUSM.h"
#include "STUSMDlg.h"
#include "afxdialogex.h"
#include "MainDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSTUSMDlg 对话框



CSTUSMDlg::CSTUSMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSTUSMDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_login);
}

void CSTUSMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON_Login, M_login);
}

BEGIN_MESSAGE_MAP(CSTUSMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MFCBUTTON_Login, &CSTUSMDlg::OnBnClickedMfcbuttonLogin)
	ON_BN_CLICKED(IDC_CHECK_Remember, &CSTUSMDlg::OnBnClickedCheckRemember)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSTUSMDlg 消息处理程序

BOOL CSTUSMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	

	//------------更改按钮背景色、文本色-------------
	M_login.m_bDontUseWinXPTheme = TRUE;
	M_login.m_bDrawFocus = false;
	M_login.SetFaceColor(RGB(0, 176, 37));
	M_login.SetTextColor(RGB(255, 255, 255));


	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSTUSMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSTUSMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//------------设置背景图片-------------
		CPaintDC   dc(this);
		CRect rect;
		GetClientRect(&rect);
		CDC   dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP_loginbg);  //对话框的背景图片  

		BITMAP   bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSTUSMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//Account
CString ACC = _T("32116160100");
//Password
CString PAS = _T("gzhucs");

void CSTUSMDlg::OnBnClickedMfcbuttonLogin()
{
	static int COUNT = 0;//错误次数
	CString account, password;
	GetDlgItemText(IDC_EDIT_Account, account);
	GetDlgItemText(IDC_EDIT_Password, password);

	//------------登录流程判断逻辑-------------
	if (COUNT >3)
	{
		MessageBox(_T("错误次数超过三次，程序退出！"), _T("提示"), MB_ICONWARNING);
		(CDialog*)AfxGetMainWnd()->DestroyWindow();
	}
	if (account == ACC&&password == PAS)
	{
		ShowWindow(SW_HIDE);
		MainDlg main;
		main.DoModal();		
	}
	else if (account == "" || password == "")
		MessageBox(_T("账号或密码不能为空"), _T("提示"), MB_ICONWARNING);
	else
	{
		MessageBox(_T("账号或密码错误!"), _T("提醒"), MB_ICONWARNING);
		COUNT++;
	}
}



void CSTUSMDlg::OnBnClickedCheckRemember()
{
	SetDlgItemText(IDC_EDIT_Account, ACC);
	SetDlgItemText(IDC_EDIT_Password, PAS);
}


HBRUSH CSTUSMDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)//将静态文本设置为透明
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	UINT id = pWnd->GetDlgCtrlID();
	if (id == IDC_STATIC || id == IDC_CHECK_Remember)
	{
		pDC->SetTextColor(RGB(90, 92, 90));//设置文本框字体颜色

		pDC->SetBkMode(TRANSPARENT);
		CRect rc;
		pWnd->GetWindowRect(&rc);
		ScreenToClient(&rc);
		CDC* dc = GetDC();
		pDC->BitBlt(0, 0, rc.Width(), rc.Height(), dc, rc.left, rc.top, SRCCOPY);  //把父窗口背景图片先画到按钮上
		ReleaseDC(dc);

		return (HBRUSH) ::GetStockObject(NULL_BRUSH);
	}

}
