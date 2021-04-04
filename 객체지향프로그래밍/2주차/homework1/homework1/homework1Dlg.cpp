
// homework1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "homework1.h"
#include "homework1Dlg.h"
#include "afxdialogex.h"
#include <vector>

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


// Chomework1Dlg 대화 상자



Chomework1Dlg::Chomework1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HOMEWORK1_DIALOG, pParent)
	, mValEdit1(_T(""))
	, mValEdit2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Chomework1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mValEdit1);
	DDX_Text(pDX, IDC_EDIT2, mValEdit2);
}

BEGIN_MESSAGE_MAP(Chomework1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SORT, &Chomework1Dlg::OnBnClickedSort)
END_MESSAGE_MAP()


// Chomework1Dlg 메시지 처리기

BOOL Chomework1Dlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Chomework1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Chomework1Dlg::OnPaint()
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
HCURSOR Chomework1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Chomework1Dlg::OnBnClickedSort()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//edit의 내용을 불러옵니다
	UpdateData(true);

	mValEdit2.Empty();	//버튼을 누를때마다 Edit2의 내용을 비워줍니다 
	
	int blank[100];		//공백의 위치를 저장하는 배열
	int i = 0;			//공백을 찾을때 사용하는 변수
	int count = 0;		//공백의 갯수를 측정하는 변수

	while (i != -1) {
		i = mValEdit1.Find(L" ", i);
		
		if (i != -1) {
			blank[count] = i;		//위치를 저장합니다
			count++;				//공백을 찾으면 카운트를 증가
			i++;
		}
	}
	blank[count++] = mValEdit1.GetLength();			//맨 마지막부분도 공백으로 치게 합니다...

	int t = 0;										//숫자와 공백사이를 측정하기 위한 변수입니다
	CString *arr = new CString[count];				//각 숫자들을 저장하는 배열입니다
	for (int k = 0; k < count; k++) {
		//t 부터 공백까지의 숫자들을 배열에 저장합니다
		for (int j = t; j < blank[k]; j++) {
			arr[k].AppendChar(mValEdit1[j]);
		}
		//t를 공백 다음 숫자로 이동시킵니다
		t = blank[k] + 1;
	}

	int *iArr = new int[count];

	for (int j = 0; j < count; j++) {
		iArr[j] = _ttoi(arr[j]);			//각 저장되어있는 char값들을 숫자로 변환시킵니다.
	}

	//선택정렬을 실행시킵니다
	selectionSort(iArr, count);

	CString temp;							//mValEdit2에 값을 추가하기 위한 임시 변수입니다.

	CString b = L" ";

	for (int k = 0; k < count; k++) {
		temp.Format(L"%d", iArr[k]);		//int형을 CString으로 변환합니다
		mValEdit2.Append(temp);				//추가해줍니다
		mValEdit2.Append(b);				//공백을 추가합니다
	}

	UpdateData(false);

	   	 	
}


//선택정렬
void Chomework1Dlg::selectionSort(int *arr, int count) {
	int temp;
	int min;

	for (int i = 0; i < count - 1; i++) {
		min = i;
		for (int j = i + 1; j < count; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}