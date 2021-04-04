// Insert.cpp: 구현 파일
//

#include "pch.h"
#include "BOOK.h"
#include "Insert.h"
#include "afxdialogex.h"


// CInsert 대화 상자

IMPLEMENT_DYNAMIC(CInsert, CDialogEx)

CInsert::CInsert(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT, pParent)
	, mValName(_T(""))
	, mValKeyword1(_T(""))
	, mValKeyword2(_T(""))
	, mValKeyword3(_T(""))
	, mValKeyword4(_T(""))
	, mValKeyword5(_T(""))
	, mValSummary(_T(""))
{

}

CInsert::~CInsert()
{
}

void CInsert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mValName);
	DDX_Text(pDX, IDC_KEYWORD1, mValKeyword1);
	DDX_Text(pDX, IDC_KEYWORD2, mValKeyword2);
	DDX_Text(pDX, IDC_KEYWORD3, mValKeyword3);
	DDX_Text(pDX, IDC_KEYWORD4, mValKeyword4);
	DDX_Text(pDX, IDC_KEYWORD5, mValKeyword5);
	//  DDX_Control(pDX, IDC_COMBO1, mCtrlYear);
	DDX_Text(pDX, IDC_EDIT3, mValSummary);
	//  DDX_Control(pDX, IDC_COMBO1, mCtrlYear);
	DDX_Control(pDX, IDC_COMBO1, mCtrlYear);
}


BEGIN_MESSAGE_MAP(CInsert, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInsert::OnBnClickedOk)
END_MESSAGE_MAP()


BOOL CInsert::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	//연도.. 1900~2020 까지 추가 합니다..
	CString s;
	for (int i = 1900; i < 2021; i++) {
		s.Format(L"%d", i);
		mCtrlYear.AddString(s);
	}

	mCtrlYear.SetCurSel(110);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


// CInsert 메시지 처리기


void CInsert::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	year = mCtrlYear.GetCurSel() + 1900;

	UpdateData();

	CDialogEx::OnOK();
}

