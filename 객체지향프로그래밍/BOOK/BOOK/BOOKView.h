
// BOOKView.h: CBOOKView 클래스의 인터페이스
//

#pragma once


class CBOOKView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CBOOKView() noexcept;
	DECLARE_DYNCREATE(CBOOKView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_BOOK_FORM };
#endif

// 특성입니다.
public:
	CBOOKDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CBOOKView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mCtrlList;
	afx_msg void OnBnClickedAdd();

	void DisplayData();
	void printSearch(int i, int search);
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedList();
};

#ifndef _DEBUG  // BOOKView.cpp의 디버그 버전
inline CBOOKDoc* CBOOKView::GetDocument() const
   { return reinterpret_cast<CBOOKDoc*>(m_pDocument); }
#endif

