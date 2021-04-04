#pragma once


// CPenSize 대화 상자

class CPenSize : public CDialogEx
{
	DECLARE_DYNAMIC(CPenSize)

public:
	CPenSize(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CPenSize();
	int mPen;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PEN_SIZE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox mCtrlList1;
	afx_msg void OnBnClickedOk();
};
