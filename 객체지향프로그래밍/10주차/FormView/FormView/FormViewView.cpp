
// FormViewView.cpp: CFormViewView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "FormView.h"
#endif

#include "FormViewDoc.h"
#include "FormViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFormViewView

IMPLEMENT_DYNCREATE(CFormViewView, CView)

BEGIN_MESSAGE_MAP(CFormViewView, CView)
END_MESSAGE_MAP()

// CFormViewView 생성/소멸

CFormViewView::CFormViewView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CFormViewView::~CFormViewView()
{
}

BOOL CFormViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CFormViewView 그리기

void CFormViewView::OnDraw(CDC* /*pDC*/)
{
	CFormViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CFormViewView 진단

#ifdef _DEBUG
void CFormViewView::AssertValid() const
{
	CView::AssertValid();
}

void CFormViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFormViewDoc* CFormViewView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFormViewDoc)));
	return (CFormViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CFormViewView 메시지 처리기
