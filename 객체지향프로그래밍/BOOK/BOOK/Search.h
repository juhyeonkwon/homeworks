#pragma once

// CSearch 대화 상자
#include "BOOKDoc.h"
#include "afx.h"
#include "afxwin.h"

class CSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CSearch)

public:
	CSearch(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSearch();

	CBOOKDoc * GetDocument() const;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.


	DECLARE_MESSAGE_MAP()
public:
	CString mValKeyword;
//	afx_msg void OnBnClickedSearchbtn();
	virtual BOOL OnInitDialog();
//	CListCtrl mCtrlList;
	void printBook(int i);
	BOOK_STR *p;
	int cnt;
	afx_msg void OnBnClickedOk();
};
