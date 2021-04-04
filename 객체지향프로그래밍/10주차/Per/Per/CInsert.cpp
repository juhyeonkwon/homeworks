// CInsert.cpp: 구현 파일
//

#include "pch.h"
#include "Per.h"
#include "CInsert.h"
#include "afxdialogex.h"

extern WCHAR gAddr1[6][8];
extern int gAddr1_cnt;

extern WCHAR gAddr2[6][7][8];

extern int gAddr2_cnt[6];
// CInsert 대화 상자

IMPLEMENT_DYNAMIC(CInsert, CDialogEx)

CInsert::CInsert(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT, pParent)
	, mValName(_T(""))
	, mValTel1(_T(""))
	, mValTel2(_T(""))

	, mValClimbing(FALSE)
	, mValFishing(FALSE)
	, mValAddr3(_T(""))
	, mValGame(FALSE)
	, mValReading(FALSE)
	, mValSoccer(FALSE)
	, mValSingle(0)
	, mValKid0(0)
{
	mValSingle = 0;
}

CInsert::~CInsert()
{
}

void CInsert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, mValName);
	DDV_MaxChars(pDX, mValName, 18);
	DDX_Text(pDX, IDC_TEL1, mValTel1);
	DDV_MaxChars(pDX, mValTel1, 13);
	DDX_Text(pDX, IDC_TEL2, mValTel2);
	DDV_MaxChars(pDX, mValTel2, 13);

	DDX_Control(pDX, IDC_LIST2, mCtrlAddr1);
	DDX_Control(pDX, IDC_LIST3, mCtrlAddr2);
	//  DDX_Text(pDX, IDC_ADDR3, mAddr3);
	//  DDX_Check(pDX, IDC_CLIMBING, mReading);
	//  DDX_Check(pDX, IDC_FISHING, mFishing);
	//  DDX_Check(pDX, IDC_GAME, mGame);
	DDX_Check(pDX, IDC_CLIMBING, mValClimbing);
	DDX_Check(pDX, IDC_FISHING, mValFishing);
	DDX_Text(pDX, IDC_ADDR3, mValAddr3);
	DDX_Check(pDX, IDC_GAME, mValGame);
	DDX_Check(pDX, IDC_READING, mValReading);
	DDX_Check(pDX, IDC_SOCCER, mValSoccer);
	DDX_Radio(pDX, IDC_SINGLE, mValSingle);
	DDX_Radio(pDX, IDC_KID0, mValKid0);
	DDX_Control(pDX, IDC_AGE, mCtrlAge);
}


BEGIN_MESSAGE_MAP(CInsert, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInsert::OnBnClickedOk)
	ON_LBN_SELCHANGE(IDC_LIST2, &CInsert::OnLbnSelchangeList2)
	ON_BN_CLICKED(IDC_SINGLE, &CInsert::OnBnClickedSingle)
	ON_BN_CLICKED(IDC_MARRIED, &CInsert::OnBnClickedMarried)
	ON_BN_CLICKED(IDC_INSERT2, &CInsert::OnBnClickedInsert2)
END_MESSAGE_MAP()


// CInsert 메시지 처리기


void CInsert::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	mAddr1Idx = mCtrlAddr1.GetCurSel();
	mAddr2Idx = mCtrlAddr2.GetCurSel();
	mAgeIdx = mCtrlAge.GetCurSel();
	UpdateData();

	CDialogEx::OnOK();
}


BOOL CInsert::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	for (int i = 0; i < gAddr1_cnt; i++) {
		mCtrlAddr1.AddString(gAddr1[i]);
	}
	mCtrlAddr1.SetCurSel(0);

	for (int i = 0; i < gAddr2_cnt[0]; i++) {
		mCtrlAddr2.AddString(gAddr2[0][i]);
	}

	CString s;
	for (int i = 0; i < 128; i++) {
		s.Format(L"%d", i);
		mCtrlAge.AddString(s);
	}
	
	mCtrlAge.SetCurSel(mAgeIdx);

	GetDlgItem(IDC_INSERT2)->EnableWindow(mIsInsertMode);

	EnableKids(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CInsert::OnLbnSelchangeList2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	mCtrlAddr2.ResetContent();

	int idx = mCtrlAddr1.GetCurSel();
	
	for (int i = 0; i < gAddr2_cnt[idx]; i++) {
		mCtrlAddr2.AddString(gAddr2[idx][i]);
	}
	mCtrlAddr2.SetCurSel(0);

}


void CInsert::OnBnClickedSingle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EnableKids(FALSE);
}


void CInsert::OnBnClickedMarried()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EnableKids(TRUE);
}

void CInsert::EnableKids(int opt) {
	GetDlgItem(IDC_KIDS)->EnableWindow(opt);
	GetDlgItem(IDC_KID0)->EnableWindow(opt);
	GetDlgItem(IDC_KID1)->EnableWindow(opt);
	GetDlgItem(IDC_KID2)->EnableWindow(opt);
	GetDlgItem(IDC_KID3)->EnableWindow(opt);
	GetDlgItem(IDC_KID4)->EnableWindow(opt);

}

void CInsert::OnBnClickedInsert2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();

	mAddr1Idx = mCtrlAddr1.GetCurSel();
	mAddr2Idx = mCtrlAddr2.GetCurSel();
	mAgeIdx = mCtrlAge.GetCurSel();
	GetParent()->SendMessage(WM_COMMAND, IDM_INSERT2);
}
