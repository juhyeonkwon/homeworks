
// MENUView.cpp: CMENUView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MENU.h"
#endif

#include "MENUDoc.h"
#include "MENUView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMENUView

IMPLEMENT_DYNCREATE(CMENUView, CView)

BEGIN_MESSAGE_MAP(CMENUView, CView)
	ON_COMMAND(ID_MENU1_MENU1, &CMENUView::OnMenu1Menu1)
	ON_COMMAND(ID_MENU1_MENU2, &CMENUView::OnMenu1Menu2)
	ON_COMMAND(ID_MENU2_MENU1, &CMENUView::OnMenu2Menu1)
	ON_COMMAND(ID_MENU2_MENU2, &CMENUView::OnMenu2Menu2)
	ON_COMMAND(IDC_BLUE, &CMENUView::OnBlue)
	ON_COMMAND(IDC_ELLIPSE, &CMENUView::OnEllipse)
	ON_COMMAND(IDC_ELLIPSE_FILL, &CMENUView::OnEllipseFill)
	ON_COMMAND(IDC_GREEN, &CMENUView::OnGreen)
	ON_COMMAND(IDC_LINE, &CMENUView::OnLine)
	ON_COMMAND(IDC_RECT, &CMENUView::OnRect)
	ON_COMMAND(IDC_RECT_FILL, &CMENUView::OnRectFill)
	ON_COMMAND(IDC_RED, &CMENUView::OnRed)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDC_FILL_BLUE, &CMENUView::OnFillBlue)
	ON_COMMAND(IDC_FILL_GREEN, &CMENUView::OnFillGreen)
	ON_COMMAND(IDC_FILL_RED, &CMENUView::OnFillRed)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDC_FOR_COLOR, &CMENUView::OnForColor)
	ON_COMMAND(IDC_BR_COLOR, &CMENUView::OnBrColor)
	ON_COMMAND(IDC_PEN_SIZE, &CMENUView::OnPenSize)
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMENUView 생성/소멸

CMENUView::CMENUView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	mColor = COLOR_RED;
	mObjType = LINE;
	mPenSize = 5;
}

CMENUView::~CMENUView()
{
}

BOOL CMENUView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMENUView 그리기

void CMENUView::OnDraw(CDC* /*pDC*/)
{
	CMENUDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	for (int i = 0; i < pDoc->mObjCnt; i++) {
		DrawObj1(pDoc->Obj[i].mColor, pDoc->Obj[i].mFillColor, pDoc->Obj[i].mObjType, pDoc->Obj[i].mPoint1, pDoc->Obj[i].mPoint2, 0);
	}

}


// CMENUView 진단

#ifdef _DEBUG
void CMENUView::AssertValid() const
{
	CView::AssertValid();
}

void CMENUView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMENUDoc* CMENUView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMENUDoc)));
	return (CMENUDoc*)m_pDocument;
}
#endif //_DEBUG


// CMENUView 메시지 처리기


void CMENUView::OnMenu1Menu1()
{
	MessageBox(L"menu1-1");
}


void CMENUView::OnMenu1Menu2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMENUView::OnMenu2Menu1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMENUView::OnMenu2Menu2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMENUView::OnBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mColor = COLOR_BLUE;
}


void CMENUView::OnEllipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mObjType = ELLIPSE;

}


void CMENUView::OnEllipseFill()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mObjType = ELLIPSE_FILL;

}


void CMENUView::OnGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mColor = COLOR_GREEN;

}


void CMENUView::OnLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mObjType = LINE;

}


void CMENUView::OnRect()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mObjType = RECT;
}


void CMENUView::OnRectFill()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mObjType = RECT_FILL;

}


void CMENUView::OnRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mColor = COLOR_RED;

}


//마우스으으
void CMENUView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	mPoint1 = point;
	mPoint2 = point;

	CView::OnLButtonDown(nFlags, point);
}


void CMENUView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//DrawObj1(mColor, mFillColor, mObjType, mPoint1, point, 0);
	DrawObj3(mPenColor, mBRColor, mObjType, mPoint1, point, 0);
	SaveObj(mColor, mFillColor, mObjType, mPoint1, point);
	CView::OnLButtonUp(nFlags, point);
}


void CMENUView::DrawObj1(int col, int fill_col, int obj_type, CPoint p1, CPoint p2, int opt) {
	//opt : 0-copy, 1-EXOR
	CPen pen;
	CBrush br;

	CClientDC dc(this);


	switch (col) {
	case COLOR_RED:
		pen.CreatePen(PS_SOLID, 5, RGB(255, 0, 0)); break;
	case COLOR_GREEN:
		pen.CreatePen(PS_SOLID, 5, RGB(0, 255, 0)); break;
	case COLOR_BLUE:
		pen.CreatePen(PS_SOLID, 5, RGB(0, 0, 255)); break;

	}

	switch (fill_col) {
	case COLOR_RED:
		br.CreateSolidBrush(RGB(255, 0, 0));
		break;
	case COLOR_GREEN:
		br.CreateSolidBrush(RGB(0, 255, 0));
		; break;
	case COLOR_BLUE:
		br.CreateSolidBrush(RGB(0, 0, 255));
		break;

	}

	if (opt == 1) dc.SetROP2(R2_XORPEN);
	dc.SelectObject(&pen);
	switch (obj_type) {
	case LINE:
		dc.MoveTo(p1);
		dc.LineTo(p2);
		break;
	case RECT:
		dc.Rectangle(p1.x, p1.y, p2.x, p2.y);
		break;
	case ELLIPSE:
		dc.Ellipse(p1.x, p1.y, p2.x, p2.y);
		break;
	case RECT_FILL:
		dc.SelectObject(&br);
		dc.Rectangle(p1.x, p1.y, p2.x, p2.y);
		break;
	case ELLIPSE_FILL:
		dc.SelectObject(&br);
		dc.Ellipse(p1.x, p1.y, p2.x, p2.y);
		break;
	}
}

void CMENUView::SaveObj(int col, int fill_col, int obj_type, CPoint p1, CPoint p2) {
	
	CMENUDoc* pDoc = GetDocument();
	
	pDoc->Obj[pDoc->mObjCnt].mColor = col;
	pDoc->Obj[pDoc->mObjCnt].mFillColor = fill_col;
	pDoc->Obj[pDoc->mObjCnt].mObjType = obj_type;
	pDoc->Obj[pDoc->mObjCnt].mPoint1 = p1;
	pDoc->Obj[pDoc->mObjCnt].mPoint2 = p2;

	pDoc->mObjCnt++;


}


void CMENUView::OnFillBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mFillColor = COLOR_BLUE;
}


void CMENUView::OnFillGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mFillColor = COLOR_GREEN;
}


void CMENUView::OnFillRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	mFillColor = COLOR_RED;

}


void CMENUView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!(nFlags & MK_LBUTTON)) return;
//	DrawObj1(mColor, mFillColor, mObjType, mPoint1, mPoint2, 1);
//	mPoint2 = point;
//	DrawObj1(mColor, mFillColor, mObjType, mPoint1, point, 1);
	DrawObj3(mPenColor, mBRColor, mObjType, mPoint1, mPoint2, 1);
	mPoint2 = point;
	DrawObj3(mPenColor, mBRColor, mObjType, mPoint1, point, 1);
	CView::OnMouseMove(nFlags, point);
}


void CMENUView::OnForColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dg;
	if (dg.DoModal() == IDOK) {
		mPenColor = dg.GetColor();
	}
}


void CMENUView::OnBrColor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dg;
	if (dg.DoModal() == IDOK) {
		mBRColor = dg.GetColor();
	}
}

void CMENUView::DrawObj3(COLORREF col, COLORREF fill_col, int obj_type, CPoint p1, CPoint p2, int opt) {
	//opt : 0-copy, 1-EXOR
	CPen pen;
	CBrush br;

	CClientDC dc(this);

	br.CreateSolidBrush(fill_col);
	pen.CreatePen(PS_SOLID, mPenSize, col);
		

	if (opt == 1) dc.SetROP2(R2_XORPEN);
	dc.SelectObject(&pen);
	switch (obj_type) {
	case LINE:
		dc.MoveTo(p1);
		dc.LineTo(p2);
		break;
	case RECT:
		dc.Rectangle(p1.x, p1.y, p2.x, p2.y);
		break;
	case ELLIPSE:
		dc.Ellipse(p1.x, p1.y, p2.x, p2.y);
		break;
	case RECT_FILL:
		dc.SelectObject(&br);
		dc.Rectangle(p1.x, p1.y, p2.x, p2.y);
		break;
	case ELLIPSE_FILL:
		dc.SelectObject(&br);
		dc.Ellipse(p1.x, p1.y, p2.x, p2.y);
		break;
	}
}

#include "CPenSize.h"

void CMENUView::OnPenSize()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CPenSize dg;
	if (dg.DoModal() == IDOK) {
		mPenSize = dg.mPen;
	}
}



void CMENUView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	CRect r;
	GetClientRect(&r);
	CString s;

	CPoint p1, p2;
	p1.x = rand() % r.right;
	p2.x = rand() % r.right;
	p1.y = rand() % r.bottom;
	p2.y = rand() % r.bottom;
	int type = rand() % 5 + 1;

	COLORREF p_color = RGB((rand() % 256), (rand() % 256), (rand() % 256));
	COLORREF b_color = RGB((rand() % 256), (rand() % 256), (rand() % 256));

	mPenSize = rand() % 10 + 1;

	if (nIDEvent == 101) {
		s.Format(L"%d, %d, %d, %d", r.left, r.top, r.right, r.bottom);
		//dc.TextOutW(100, 100, s);
		dc.DrawTextW(s, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (nIDEvent == 102) {
		DrawObj3(p_color, b_color, type, p1, p2, 0);

	}
	CView::OnTimer(nIDEvent);
	
}


void CMENUView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	static int state = 0;
	
	if (state == 0) {
		SetTimer(101, 100, 0);
		SetTimer(102, 500, 0);
		state = 1;
	}
	else {
		KillTimer(101);
		KillTimer(102);
		state = 0;
	}
	CView::OnRButtonDown(nFlags, point);
}
