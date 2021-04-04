
// CalDlg.h: 헤더 파일
//

#pragma once

#define PLUS 1
#define MINUS 2
#define MULTI 3
#define DIVIDE 4
#define EQUAL 5

// CCalDlg 대화 상자
class CCalDlg : public CDialogEx
{
// 생성입니다.
public:
	CCalDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	//
	int mCurValint, mOP, mAfterDot, mRealNumCnt;
	int buttonNum;
	double mPreVal, mCurValReal;


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked9();
	afx_msg void OnClicked8();
	afx_msg void OnClicked7();
	afx_msg void OnClicked6();
	afx_msg void OnClicked5();
	afx_msg void OnClicked4();
	afx_msg void OnClicked3();
	afx_msg void OnClicked2();
	afx_msg void OnClicked1();
	afx_msg void OnClicked0();


	void pushNum(int v);
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	void calOP(int op);

	afx_msg void OnBnClickedMulti();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedDot();
	double getPointNum(double num);
	int CCalDlg::getDotNum(double v);
};
