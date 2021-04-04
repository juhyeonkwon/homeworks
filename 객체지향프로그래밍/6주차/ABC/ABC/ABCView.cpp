
// ABCView.cpp: CABCView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ABC.h"
#endif

#include "ABCDoc.h"
#include "ABCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CABCView

IMPLEMENT_DYNCREATE(CABCView, CView)

BEGIN_MESSAGE_MAP(CABCView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CABCView 생성/소멸

CABCView::CABCView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CABCView::~CABCView()
{
}

BOOL CABCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CABCView 그리기

void CABCView::OnDraw(CDC* pDC)
{
	CABCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	for (int i = 0; i < pDoc->mLineCnt; i++) {
		for (int k = 0; k < pDoc->mPointCnt[i] - 1; k++) {
			pDC->MoveTo(pDoc->mPoint1[i][k]);
			pDC->LineTo(pDoc->mPoint1[i][k + 1]);
		}
	}

	for (int i = 0; i < pDoc->mStrLinCnt; i++) {
		pDC->MoveTo(pDoc->mLineStart[i]);
		pDC->LineTo(pDoc->mLineEnd[i]);
	}

}


// CABCView 진단

#ifdef _DEBUG
void CABCView::AssertValid() const
{
	CView::AssertValid();
}

void CABCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CABCDoc* CABCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CABCDoc)));
	return (CABCDoc*)m_pDocument;
}
#endif //_DEBUG


// CABCView 메시지 처리기

void CABCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CABCDoc* pDoc = GetDocument();
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	pDoc->mPoint1[pDoc->mLineCnt][pDoc->mCnt] = point;
	pDoc->mCnt++;


	//CView::OnLButtonDown(nFlags, point);
}


void CABCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CABCDoc* pDoc = GetDocument();

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pDoc->mLineCnt <= 100) {
		pDoc->mPointCnt[pDoc->mLineCnt] = pDoc->mCnt;
		pDoc->mLineCnt++;
		pDoc->mCnt = 0;
	}
	CView::OnLButtonUp(nFlags, point);
}


void CABCView::OnMouseMove(UINT nFlags, CPoint point)
{
	CABCDoc* pDoc = GetDocument();

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	if (pDoc->mCnt < 10000 && (nFlags & MK_LBUTTON) ) {
		dc.MoveTo(pDoc->mPoint1[pDoc->mLineCnt][pDoc->mCnt-1]);
		dc.LineTo(point);
		pDoc->mPoint1[pDoc->mLineCnt][pDoc->mCnt] = point;
		pDoc->mCnt++;
	}

	CView::OnMouseMove(nFlags, point);
}


void CABCView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CABCDoc* pDoc = GetDocument();

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	pDoc->mLineStart[pDoc->mStrLinCnt] = point;

	CView::OnRButtonDown(nFlags, point);
}


void CABCView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CABCDoc* pDoc = GetDocument();

	CClientDC dc(this);
	dc.MoveTo(pDoc->mLineStart[pDoc->mStrLinCnt]);
	dc.LineTo(point);

	pDoc->mLineEnd[pDoc->mStrLinCnt] = point;

	pDoc->mStrLinCnt++;

	CView::OnRButtonUp(nFlags, point);

}
