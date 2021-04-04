
// MENUView.h: CMENUView 클래스의 인터페이스
//

#pragma once


class CMENUView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMENUView() noexcept;
	DECLARE_DYNCREATE(CMENUView)

// 특성입니다.
public:
	CMENUDoc* GetDocument() const;

// 작업입니다.
public:
	int mColor, mFillColor, mObjType;
	CPoint mPoint1, mPoint2;
	COLORREF mPenColor, mBRColor;
	int mPenSize;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMENUView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenu1Menu1();
	afx_msg void OnMenu1Menu2();
	afx_msg void OnMenu2Menu1();
	afx_msg void OnMenu2Menu2();
	afx_msg void OnBlue();
	afx_msg void OnEllipse();
	afx_msg void OnEllipseFill();
	afx_msg void OnGreen();
	afx_msg void OnLine();
	afx_msg void OnRect();
	afx_msg void OnRectFill();
	afx_msg void OnRed();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	void DrawObj1(int col, int fill_col, int obj_type, CPoint p1, CPoint p2, int opt);
	void SaveObj(int col, int fill_col, int obj_type, CPoint p1, CPoint p2);
	afx_msg void OnFillBlue();
	afx_msg void OnFillGreen();
	afx_msg void OnFillRed();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnForColor();
	afx_msg void OnBrColor();

	void DrawObj3(COLORREF col, COLORREF fill_col, int obj_type, CPoint p1, CPoint p2, int opt);
	afx_msg void OnPenSize();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MENUView.cpp의 디버그 버전
inline CMENUDoc* CMENUView::GetDocument() const
   { return reinterpret_cast<CMENUDoc*>(m_pDocument); }
#endif

