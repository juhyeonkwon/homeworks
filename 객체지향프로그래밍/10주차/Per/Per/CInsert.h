#pragma once


// CInsert 대화 상자

class CInsert : public CDialogEx
{
	DECLARE_DYNAMIC(CInsert)

public:
	CInsert(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CInsert();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSERT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString mValName;
	CString mValTel1;
	CString mValTel2;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CListBox mCtrlAddr1;
	int mAddr1Idx;
	CListBox mCtrlAddr2;
	int mAddr2Idx;
	int mAgeIdx;
	int mIsInsertMode;
	afx_msg void OnLbnSelchangeList2();
//	CString mAddr3;
//	BOOL mReading;
//	BOOL mFishing;
//	BOOL mGame;
	BOOL mValClimbing;
	BOOL mValFishing;
	CString mValAddr3;
	BOOL mValGame;
	BOOL mValReading;
	BOOL mValSoccer;
	int mValSingle;
	afx_msg void OnBnClickedSingle();
	afx_msg void OnBnClickedMarried();
	void EnableKids(int opt);

	int mValKid0;
	CComboBox mCtrlAge;
	afx_msg void OnBnClickedInsert2();
};
