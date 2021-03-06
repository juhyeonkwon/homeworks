
// AAAView.h: CAAAView 클래스의 인터페이스
//

#pragma once


class CAAAView : public CView
{
protected: // serialization에서만 만들어집니다.
	CAAAView() noexcept;
	DECLARE_DYNCREATE(CAAAView)

// 특성입니다.
public:
	CAAADoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CAAAView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CPoint cpoint;
	CPoint p[10000];
	int pcnt = 1;
};

#ifndef _DEBUG  // AAAView.cpp의 디버그 버전
inline CAAADoc* CAAAView::GetDocument() const
   { return reinterpret_cast<CAAADoc*>(m_pDocument); }
#endif

