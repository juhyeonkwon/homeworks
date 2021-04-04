
// Homework6View.h: CHomework6View 클래스의 인터페이스
//

#pragma once


class CHomework6View : public CView
{
protected: // serialization에서만 만들어집니다.
	CHomework6View() noexcept;
	DECLARE_DYNCREATE(CHomework6View)

// 특성입니다.
public:
	CHomework6Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CHomework6View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMenuMenu1();
	afx_msg void OnMenuMenu2();
	afx_msg void OnMenu2Menu1();
	afx_msg void OnMenu2Menu2();
};

#ifndef _DEBUG  // Homework6View.cpp의 디버그 버전
inline CHomework6Doc* CHomework6View::GetDocument() const
   { return reinterpret_cast<CHomework6Doc*>(m_pDocument); }
#endif

