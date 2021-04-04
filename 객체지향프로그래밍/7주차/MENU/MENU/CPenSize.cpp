// CPenSize.cpp: 구현 파일
//

#include "pch.h"
#include "MENU.h"
#include "CPenSize.h"
#include "afxdialogex.h"


// CPenSize 대화 상자

IMPLEMENT_DYNAMIC(CPenSize, CDialogEx)

CPenSize::CPenSize(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PEN_SIZE, pParent)
{

}

CPenSize::~CPenSize()
{
}

void CPenSize::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mCtrlList1);
}


BEGIN_MESSAGE_MAP(CPenSize, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPenSize::OnBnClickedOk)
END_MESSAGE_MAP()


// CPenSize 메시지 처리기


BOOL CPenSize::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString s;

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	for (int i = 0; i < 10; i++) {
		s.Format(L"%d", i + 1);
		mCtrlList1.AddString(s);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CPenSize::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	mPen = mCtrlList1.GetCurSel() + 1;


	CDialogEx::OnOK();
}
