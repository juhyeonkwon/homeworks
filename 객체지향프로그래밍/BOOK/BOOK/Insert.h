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
	CString mValKeyword1;
	CString mValKeyword2;
	CString mValKeyword3;
	CString mValKeyword4;
	CString mValKeyword5;
	int year;			//year
//	CComboBox mCtrlYear;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CString mValSummary;
//	int mCtrlYear;
	CComboBox mCtrlYear;
};
