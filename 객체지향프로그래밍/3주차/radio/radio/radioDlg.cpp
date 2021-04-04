
// radioDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "radio.h"
#include "radioDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CString region[12] = { L"서울시", L"경기도", L"충청남도", L"충청북도", L"부산시", L"제주도", L"경상남도", L"경상북도", L"전라남도", L"전라북도",
						L"대구시", L"광주시" };

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CradioDlg 대화 상자



CradioDlg::CradioDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RADIO_DIALOG, pParent)
	, mVal0(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CradioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_0, mVal0);
	DDX_Control(pDX, IDC_MALE, mCtrlMale);
	DDX_Control(pDX, IDC_FEMALE, mCtrlFemale);

	DDX_Control(pDX, IDC_CHECK1, mCtrlCheck1);
	DDX_Control(pDX, IDC_CHECK2, mCtrlCheck2);
	DDX_Control(pDX, IDC_CHECK3, mCtrlCheck3);
	DDX_Control(pDX, IDC_CHECK4, mCtrlCheck4);
	DDX_Control(pDX, IDC_0, mCtrl0);
	DDX_Control(pDX, IDC_1, mCtrl1);
	DDX_Control(pDX, IDC_2, mCtrl2);
	DDX_Control(pDX, IDC_LIST1, mCtrlList);
}

BEGIN_MESSAGE_MAP(CradioDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CradioDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CradioDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CradioDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CradioDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDOK, &CradioDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_MALE, &CradioDlg::OnBnClickedMale)
	ON_BN_CLICKED(IDC_FEMALE, &CradioDlg::OnBnClickedFemale)
	ON_BN_CLICKED(IDC_0, &CradioDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &CradioDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CradioDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_BUTTONRADIO, &CradioDlg::OnBnClickedButtonradio)
END_MESSAGE_MAP()


// CradioDlg 메시지 처리기

BOOL CradioDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	mCtrlCheck1.SetCheck(true);
	mCtrlCheck2.SetCheck(true);
	mCtrlCheck4.SetCheck(true);
	mCtrl0.EnableWindow(false);
	mCtrl1.EnableWindow(false);
	mCtrl2.EnableWindow(false);

	for (int i = 0; i < 12; i++) {
		mCtrlList.AddString(region[i]);

	}

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CradioDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CradioDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CradioDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CradioDlg::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CradioDlg::OnBnClickedCheck2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void CradioDlg::OnBnClickedCheck3()
{

	MessageBox(L"check3 pushed!");
}


void CradioDlg::OnBnClickedCheck4()
{
	if (mCtrlCheck4.GetCheck()) {
		mCtrl0.EnableWindow(false);
		mCtrl1.EnableWindow(false);
		mCtrl2.EnableWindow(false);
	}
	else {
		mCtrl0.EnableWindow(true);
		mCtrl1.EnableWindow(true);
		mCtrl2.EnableWindow(true);
	}
}


void CradioDlg::OnBnClickedOk()
{
	CString s;


	if (mCtrlCheck1.GetCheck()) {
		s.Append(L"check 1\n");
	}
	if (mCtrlCheck2.GetCheck()) {
		s.Append(L"check 2\n");
	}
	if (mCtrlCheck3.GetCheck()) {
		s.Append(L"check 3\n");
	}
	if (mCtrlCheck4.GetCheck()) {
		s.Append(L"check 4\n");
	}

	MessageBox(s);

}


void CradioDlg::OnBnClickedMale()
{
	MessageBox(L"Male pushed!");
}


void CradioDlg::OnBnClickedFemale()
{
	MessageBox(L"FeMale pushed!");
}


void CradioDlg::OnBnClicked0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CradioDlg::OnBnClicked1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CradioDlg::OnBnClicked2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}




void CradioDlg::OnBnClickedButtonradio()
{
	CString s;

	UpdateData();

	if (mCtrlMale.GetCheck()) {
		s.Append(L"Male ");
	}
	else {
		s.Append(L"Female ");
	}

	if (mCtrl0.GetCheck()) s.Append(L"radio 0 ");
	if (mCtrl1.GetCheck()) s.Append(L"radio 1 ");
	if (mCtrl2.GetCheck()) s.Append(L"radio 2 ");

	MessageBox(s);

}
