
// HomeWorkView.h: CHomeWorkView 클래스의 인터페이스
//

#pragma once

typedef struct point {
	double x;
	double y;
} point;

class CHomeWorkView : public CView
{
protected: // serialization에서만 만들어집니다.
	CHomeWorkView() noexcept;
	DECLARE_DYNCREATE(CHomeWorkView)

// 특성입니다.
public:
	CHomeWorkDoc* GetDocument() const;

// 작업입니다.
public:
	point arc1, arc2;			//원의 x,y
	COLORREF arcCol;			//원의 색깔
	double arcRad;				//원 각도 계산을 위해서

	point p1, p2;				//선의 x1, x2
	int lineLength;				//선의 길이
	double lineRad;				//선의 각도

	point r1, r2;				//사각형의 x,y
	COLORREF rectCol;			//사각형의 색깔
	double rectRad;				//사각형의 각도


// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CHomeWorkView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
	void drawArc();
	void drawLine();
	void drawRect();
	double setRad(int position);
public:
	afx_msg void OnStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // HomeWorkView.cpp의 디버그 버전
inline CHomeWorkDoc* CHomeWorkView::GetDocument() const
   { return reinterpret_cast<CHomeWorkDoc*>(m_pDocument); }
#endif

