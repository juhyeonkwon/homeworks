
// Homework2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Homework2.h"
#include "Homework2Dlg.h"
#include "afxdialogex.h"
#include <vector>
#include <algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

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


// CHomework2Dlg 대화 상자



CHomework2Dlg::CHomework2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HOMEWORK2_DIALOG, pParent)
	, mValRadio(FALSE)
	, mValEdit1(_T(""))
	, mValEdit2(_T(""))
	, mValEdit3(_T(""))
	, mValResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHomework2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, mCtrlCheck1);
	DDX_Control(pDX, IDC_CHECK2, mCtrlCheck2);
	DDX_Control(pDX, IDC_CHECK3, mCtrlCheck3);
	DDX_Radio(pDX, IDC_RADIO1, mValRadio);
	DDX_Text(pDX, IDC_EDIT1, mValEdit1);
	DDX_Text(pDX, IDC_EDIT2, mValEdit2);
	DDX_Text(pDX, IDC_EDIT3, mValEdit3);
	DDX_Text(pDX, IDC_EDIT4, mValResult);
}

BEGIN_MESSAGE_MAP(CHomework2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CHomework2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CHomework2Dlg 메시지 처리기

BOOL CHomework2Dlg::OnInitDialog()
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

	mValRadio = 2;		//3번째 라디오를 처음에 체크되어 있게 하기 위해 2를 해줬습니다.

	//체크박스 
	mCtrlCheck1.SetCheck(true);
	mCtrlCheck2.SetCheck(true);
	mCtrlCheck3.SetCheck(true);

	UpdateData(false);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CHomework2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHomework2Dlg::OnPaint()
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
HCURSOR CHomework2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//button 클릭시 실행
void CHomework2Dlg::OnBnClickedOk()
{
	//값을 가져옵니다
	UpdateData(true);


	CString str = L"";	//문자를 합치기위한 변수

	//체크 되어 값들을 모두 하나의 문자열로 합칩니다.
	if (mCtrlCheck1.GetCheck()) {
		str.Append(mValEdit1);
	}
	
	str.Append(L" ");

	if (mCtrlCheck2.GetCheck()) {
		str.Append(mValEdit2);
	}

	str.Append(L" ");

	if (mCtrlCheck3.GetCheck()) {
		str.Append(mValEdit3);
	}


	vector <CString> vStr;			//나눠진 문자열을 저장하기 위한 벡터를 선언합니다

	int i = 0;

	CString temp;					//임시로 문자열을 저장할 변수

	CString blank = L"";			//공백

	//공백을 기준으로 문자열을 나눕니다.
	//afxExtractSubString이더이상 나눌 수 없을시 false를 반환합니다..	
	while (true) {
		if (AfxExtractSubString(temp, str, i, ' ') == false) {
			break;
		}	

		//공백을 저장했을시 벡터에 추가하지 않고 바로 다음으로 넘어갑니다
		if (temp == blank) {
			i++;
			continue;
		}
		vStr.push_back(temp);
		i++;

	}


	vector <int> strInt;					//정수형으로 변환하기 위한 벡터
	
	//CString을 int형으로 변환합니다
	for (int i = 0; i < vStr.size(); i++) {
		strInt.push_back(_ttoi(vStr[i]));
	}

	sort(strInt.begin(), strInt.end());		//cpp에서 제공해주는 sort함수를 이용하여 바로 정렬합니다..


	//라디오 값이 오름차순 일경우
	if (mValRadio == 0) {
		sort_asc(strInt);
	}
	//라디오 값이 가장 큰 값일 경우
	else if (mValRadio == 1) {
		cs_max(strInt);
	}
	//라디오 값이 중복 제거 후 오름 순 정렬 일 경우
	else if (mValRadio == 2) {
		sort_asc_uniq(strInt);
	}



	//다시 마지막 초기화로 돌립니다
	mValRadio = 2;
	mValEdit1.Empty();
	mValEdit2.Empty();
	mValEdit3.Empty();

	mCtrlCheck1.SetCheck(true);
	mCtrlCheck2.SetCheck(true);
	mCtrlCheck3.SetCheck(true);


	UpdateData(false);

}

//중복포함 오름차순
void CHomework2Dlg::sort_asc(vector <int> v) {
	mValResult.Empty();						//결과값을 비웁니다

	CString temp;
	for (int i = 0; i < v.size(); i++) {
		temp.Format(L"%d", v[i]);				//int 를 CString으로 바꿉니다.
		mValResult.Append(temp);				//result에 추가합니다
		mValResult.Append(L" ");				//공백에 추가합니다..
	}

}

//가장 큰값
void CHomework2Dlg::cs_max(vector <int> v) {
	mValResult.Empty();						//결과값을 비웁니다


	//가장큰값은 벡터의 맨 뒤에 있는 값입니다 (정렬을 했기 때문)

	mValResult.Format(L"%d", v.back());

}

//중복제거 오름차순
void CHomework2Dlg::sort_asc_uniq(vector <int> v) {
	mValResult.Empty();							//결과값을 비웁니다

	auto last = unique(v.begin(), v.end());		//cpp에서 제공해주는 unique함수를 이용하여 중복을 제거합니다 unique는 중복된 값들의 첫 인덱스를 반환합니다

	v.erase(last, v.end());						//중복들을 제거를 합니다

	CString temp;
	for (int i = 0; i < v.size(); i++) {
		temp.Format(L"%d", v[i]);				//int 를 CString으로 바꿉니다.
		mValResult.Append(temp);				//result에 추가합니다
		mValResult.Append(L" ");				//공백에 추가합니다..
	}
}