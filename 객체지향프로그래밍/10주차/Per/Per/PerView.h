
// PerView.h: CPerView 클래스의 인터페이스
//

#pragma once

#include "CInsert.h"

class CPerView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CPerView() noexcept;
	DECLARE_DYNCREATE(CPerView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PER_FORM };
#endif

// 특성입니다.
public:
	CPerDoc* GetDocument() const;

// 작업입니다.
public:
	CInsert *mInsertDlg;
// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CPerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInsert();
	CListCtrl mCtrlList;
	void DisplayData();
	int mListIdx;
	void DeleteMemData(int idx);
	void InsertData(CInsert *dg, int opt);
	afx_msg void OnBnClickedDelete();
	afx_msg void OnItemchangedList6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickList6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedUpdate();

	afx_msg void OnInsert2();
	afx_msg void OnItemclickList6(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnColumnclickList6(NMHDR *pNMHDR, LRESULT *pResult);

	PER* GetCurNode(PER *pFirst, int idx, int cnt);
};

#ifndef _DEBUG  // PerView.cpp의 디버그 버전
inline CPerDoc* CPerView::GetDocument() const
   { return reinterpret_cast<CPerDoc*>(m_pDocument); }
#endif

