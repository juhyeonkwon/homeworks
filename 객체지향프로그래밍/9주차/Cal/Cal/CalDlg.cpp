
// CalDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Cal.h"
#include "CalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CCalDlg 대화 상자



CCalDlg::CCalDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CAL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_9, &CCalDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_8, &CCalDlg::OnClicked8)
	ON_BN_CLICKED(IDC_7, &CCalDlg::OnClicked7)
	ON_BN_CLICKED(IDC_6, &CCalDlg::OnClicked6)
	ON_BN_CLICKED(IDC_5, &CCalDlg::OnClicked5)
	ON_BN_CLICKED(IDC_4, &CCalDlg::OnClicked4)
	ON_BN_CLICKED(IDC_3, &CCalDlg::OnClicked3)
	ON_BN_CLICKED(IDC_2, &CCalDlg::OnClicked2)
	ON_BN_CLICKED(IDC_1, &CCalDlg::OnClicked1)
	ON_BN_CLICKED(IDC_0, &CCalDlg::OnClicked0)
	ON_BN_CLICKED(IDC_PLUS, &CCalDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_MINUS, &CCalDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MULTI, &CCalDlg::OnBnClickedMulti)
	ON_BN_CLICKED(IDC_DIVIDE, &CCalDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_BACK, &CCalDlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_CLEAR, &CCalDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_EQUAL, &CCalDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_DOT, &CCalDlg::OnBnClickedDot)
END_MESSAGE_MAP()


// CCalDlg 메시지 처리기

BOOL CCalDlg::OnInitDialog()
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
	SetDlgItemTextW(IDC_RESULT, L"0");

	mCurValint = 0;
	mAfterDot = 0;
	mRealNumCnt = 0;
	mPreVal = mCurValReal = 0.0;
	mOP = PLUS;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCalDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalDlg::OnPaint()
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
HCURSOR CCalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalDlg::OnBnClicked9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pushNum(9);
	buttonNum = 9;
}


void CCalDlg::OnClicked8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pushNum(8);
	buttonNum = 8;
}


void CCalDlg::OnClicked7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pushNum(7);
	buttonNum = 7;
}


void CCalDlg::OnClicked6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pushNum(6);
	buttonNum = 6;
}


void CCalDlg::OnClicked5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pushNum(5);
	buttonNum = 5;
}


void CCalDlg::OnClicked4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pushNum(4);
	buttonNum = 4;
}


void CCalDlg::OnClicked3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pushNum(3);
	buttonNum = 3;

}


void CCalDlg::OnClicked2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pushNum(2);
	buttonNum = 2;
}


void CCalDlg::OnClicked1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pushNum(1);
	buttonNum = 1;
}


void CCalDlg::OnClicked0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pushNum(0);
	buttonNum = 0;

}


void CCalDlg::pushNum(int v) {

	if (mOP == EQUAL) {
		mPreVal = 0;
		mOP = PLUS;
	}

	if(mAfterDot == 0) mCurValint = mCurValint * 10 + v;
	else {
		mRealNumCnt++;
		mCurValReal = mCurValReal + v * pow(10, -mRealNumCnt);
	}
	CString s, s2;

	double t;
	t = mCurValint + mCurValReal;
	s2.Format(L"%%.%dlf", mRealNumCnt);
	s.Format(s2, t);
	SetDlgItemTextW(IDC_RESULT, s);
}

void CCalDlg::OnBnClickedPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	calOP(PLUS);
}


void CCalDlg::OnBnClickedMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	calOP(MINUS);
}

void CCalDlg::calOP(int op) {
	switch (mOP) {
	case PLUS:
		mPreVal = mPreVal + mCurValint + mCurValReal; break;
	case MINUS:
		mPreVal = mPreVal - (mCurValint + mCurValReal) ; break;
	case MULTI:
		mPreVal = mPreVal * (mCurValint + mCurValReal); break;
	case DIVIDE:
		if (mCurValint == 0) return; //0으로 나눌때...
		mPreVal = mPreVal / (mCurValint + mCurValReal); break;
	case EQUAL:
		break;
	}

	CString s, s2;
	//s2.Format(L"%%.%dlf", getDotNum(mPreVal));

	s.Format(L"%lf", mPreVal);
	SetDlgItemTextW(IDC_RESULT, s);
	mOP = op;
	mCurValint = 0;
	mAfterDot = 0;
	mRealNumCnt = 0;
	mCurValReal = 0.0;
}



int CCalDlg::getDotNum(double v) {
	
	int t;
	int cnt = 0;
	t = (int)v;
	v = v - t;
	while (v != 0) {
		cnt++;
		v = v * 10;
		t = int(v);
		v = v - t;
	}
	return cnt;

}


void CCalDlg::OnBnClickedMulti()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	calOP(MULTI);

}


void CCalDlg::OnBnClickedDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	calOP(DIVIDE);

}


void CCalDlg::OnBnClickedBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (mCurValint == 0) return;

	//만약 dot이 없다면은 그대로 진행 합니다. 	
	if (mAfterDot == 0) {
		mCurValint = mCurValint / 10;
	}
	else if (mAfterDot = 1) {
		mCurValReal = mCurValReal - getPointNum(buttonNum);
		mRealNumCnt--;										//소수점 부분을 지울때 자리값을 증가 시켜줍니다..
		
		//만약 소수부분을 다 지웠다면 mAfterDot을 0으로 돌려 정수를 다시입력받게 합니다..
		if (mRealNumCnt == 0) {
			mAfterDot = 0;
			mCurValReal = 0.0;
		}
	}


	CString s, s2;
	double t;
	t = mCurValint + mCurValReal;
	s2.Format(L"%%.%dlf", mRealNumCnt);
	s.Format(s2, t);
	SetDlgItemTextW(IDC_RESULT, s);
}


//마지막에 입력받은 수에 현재 소수 자리수부분을 곱해서 그 자리수 부분을 만들어 줍니다. 그후 현재 수에서 그 소수를 빼게 되어 마치 없어진것 같이 만들었습니다.
double CCalDlg::getPointNum(double num) {

	return num * pow(10, -mRealNumCnt);
}

void CCalDlg::OnBnClickedClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	mCurValReal = mPreVal = 0;
	mCurValint = 0;
	mAfterDot = 0;
	mRealNumCnt = 0;
	SetDlgItemTextW(IDC_RESULT, L"0");
	mOP = PLUS;

}


void CCalDlg::OnBnClickedEqual()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	calOP(EQUAL);

}


void CCalDlg::OnBnClickedDot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	mAfterDot = 1;

}