
// HHHView.cpp: CHHHView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HHH.h"
#endif

#include "HHHDoc.h"
#include "HHHView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHHHView

IMPLEMENT_DYNCREATE(CHHHView, CView)

BEGIN_MESSAGE_MAP(CHHHView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CHHHView 생성/소멸

CHHHView::CHHHView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHHHView::~CHHHView()
{
}

BOOL CHHHView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CHHHView 그리기

void CHHHView::OnDraw(CDC* /*pDC*/)
{
	CHHHDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CHHHView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHHHView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHHHView 진단

#ifdef _DEBUG
void CHHHView::AssertValid() const
{
	CView::AssertValid();
}

void CHHHView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHHHDoc* CHHHView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHHHDoc)));
	return (CHHHDoc*)m_pDocument;
}
#endif //_DEBUG


// CHHHView 메시지 처리기
