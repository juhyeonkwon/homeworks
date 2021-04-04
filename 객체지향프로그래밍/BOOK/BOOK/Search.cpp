// Search.cpp: 구현 파일
//

#include "pch.h"
#include "BOOK.h"
#include "Search.h"
#include "afxdialogex.h"


// CSearch 대화 상자

IMPLEMENT_DYNAMIC(CSearch, CDialogEx)


CSearch::CSearch(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEARCH, pParent)
	, mValKeyword(_T(""))
{

}

CSearch::~CSearch()
{
}



void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mValKeyword);
	//  DDX_Control(pDX, IDC_LIST2, mCtrlList);
}


BEGIN_MESSAGE_MAP(CSearch, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSearch::OnBnClickedOk)
END_MESSAGE_MAP()

//초기화 작업을 합니다.. BOOK 처럼...
BOOL CSearch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	UpdateData();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// CSearch 메시지 처리기

void CSearch::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	CDialogEx::OnOK();
}
