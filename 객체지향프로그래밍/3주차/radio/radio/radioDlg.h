
// radioDlg.h: 헤더 파일
//

#pragma once


// CradioDlg 대화 상자
class CradioDlg : public CDialogEx
{
// 생성입니다.
public:
	CradioDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RADIO_DIALOG };
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
	BOOL mVal0;
	CButton mCtrlMale;
	CButton mCtrlFemale;
	CButton mCtrlCheck1;
	CButton mCtrlCheck2;
	CButton mCtrlCheck3;
	CButton mCtrlCheck4;


	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedMale();
	afx_msg void OnBnClickedFemale();
	CButton mCtrl0;
	CButton mCtrl1;
//	CButton mCtrl3;
	CButton mCtrl2;
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClickedButtonradio();
	CListBox mCtrlList;
};
