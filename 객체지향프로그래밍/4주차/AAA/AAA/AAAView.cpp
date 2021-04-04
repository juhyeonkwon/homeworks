
// AAAView.cpp: CAAAView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "AAA.h"
#endif

#include "AAADoc.h"
#include "AAAView.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAAAView

IMPLEMENT_DYNCREATE(CAAAView, CView)

BEGIN_MESSAGE_MAP(CAAAView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CAAAView 생성/소멸

CAAAView::CAAAView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CAAAView::~CAAAView()
{
}

BOOL CAAAView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CAAAView 그리기

void CAAAView::OnDraw(CDC* pDC)
{
	CAAADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pcnt = 0;
	pDC->MoveTo(0, 0);
	pDC->LineTo(cpoint.x, cpoint.y);


}


// CAAAView 진단

#ifdef _DEBUG
void CAAAView::AssertValid() const
{
	CView::AssertValid();
}

void CAAAView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAAADoc* CAAAView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAAADoc)));
	return (CAAADoc*)m_pDocument;
}
#endif //_DEBUG


// CAAAView 메시지 처리기


void CAAAView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDown(nFlags, point);
	
	cpoint.x = point.x;
	cpoint.y = point.y;

	p[0] = cpoint;

	CClientDC dc(this);
	CRect r;
	GetClientRect(&r);

	CPen a;

	a.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));

	dc.SelectObject(&a);

	dc.Rectangle(50, 50, 100, 100);
	dc.Ellipse(20, 20, 40, 40);

	CBrush br;

	br.CreateSolidBrush(RGB(0, 255, 0));

	dc.SelectObject(&br);

	dc.Rectangle(150, 150, 200, 200);


}


void CAAAView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnMouseMove(nFlags, point);
	CClientDC dc(this);

	/*if (nFlags & MK_LBUTTON) {
		dc.MoveTo(cpoint.x, cpoint.y);
		dc.LineTo(point);
		Invalidate();
	}*/

	if (nFlags & MK_LBUTTON) {
		dc.MoveTo(p[pcnt - 1]);
		dc.LineTo(point);
		p[pcnt] = point;
		pcnt++;

	}
	if (nFlags & MK_RBUTTON) {

		CPen ps;
		ps.CreatePen(PS_SOLID, 5, RGB(255, 0, 0));


		dc.SelectObject(&p);
		
		dc.Rectangle(p[pcnt - 1].x, p[pcnt - 1].y, point.x, point.y);

		
	}

}


void CAAAView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnTimer(nIDEvent);
	
	if (nIDEvent == 1) {
		MessageBox(L"ASDASD");
	}

}
