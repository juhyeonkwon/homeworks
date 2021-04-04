
// Homework6View.cpp: CHomework6View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Homework6.h"
#endif

#include "Homework6Doc.h"
#include "Homework6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHomework6View

IMPLEMENT_DYNCREATE(CHomework6View, CView)

BEGIN_MESSAGE_MAP(CHomework6View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MENU_MENU1, &CHomework6View::OnMenuMenu1)
	ON_COMMAND(ID_MENU_MENU2, &CHomework6View::OnMenuMenu2)
	ON_COMMAND(ID_MENU2_MENU1, &CHomework6View::OnMenu2Menu1)
	ON_COMMAND(ID_MENU2_MENU2, &CHomework6View::OnMenu2Menu2)
END_MESSAGE_MAP()

// CHomework6View 생성/소멸

CHomework6View::CHomework6View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHomework6View::~CHomework6View()
{
}

BOOL CHomework6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CHomework6View 그리기

void CHomework6View::OnDraw(CDC* pDC)
{
	CHomework6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	
	//자유 곡선 그리기
	for (int i = 0; i < pDoc->freeLineCnt; i++) {
		for (int j = 0; j < pDoc->LinePointCnt[i] - 1; j++) {
			pDC->MoveTo(pDoc->freeLine[i][j]);
			pDC->LineTo(pDoc->freeLine[i][j + 1]);
		}
	}

	//직선 그리기
	for (int i = 0; i < pDoc->strLineCnt; i++) {
		pDC->MoveTo(pDoc->mLineStart[i]);
		pDC->LineTo(pDoc->mLineEnd[i]);
	}
}


// CHomework6View 진단

#ifdef _DEBUG
void CHomework6View::AssertValid() const
{
	CView::AssertValid();
}

void CHomework6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHomework6Doc* CHomework6View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHomework6Doc)));
	return (CHomework6Doc*)m_pDocument;
}
#endif //_DEBUG


// CHomework6View 메시지 처리기

//왼쪽 마우스를 눌렀을 경우
void CHomework6View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CHomework6Doc* pDoc = GetDocument();		//DOC call

	//현재 위치를 freeLine에 저장합니다
	pDoc->freeLine[pDoc->freeLineCnt][pDoc->freeCnt] = point;
	pDoc->freeCnt++;


	CView::OnLButtonDown(nFlags, point);
}


void CHomework6View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CHomework6Doc* pDoc = GetDocument();		//DOC call
	
	//자유곡선의 수가 100보다 작을경우만
	if (pDoc->freeLineCnt <= 100) {
		pDoc->LinePointCnt[pDoc->freeLineCnt] = pDoc->freeCnt;			//현재까지의 점의 갯수를 저장..
		pDoc->freeLineCnt++;											//라인 갯수 증가
		pDoc->freeCnt = 0;												//점의 갯수 0으로 초기화
	}


	CView::OnLButtonUp(nFlags, point);
}


void CHomework6View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CHomework6Doc* pDoc = GetDocument();		//DOC call


	//마우스 오른쪽 버튼 누를시 포인트 저장
	pDoc->mLineStart[pDoc->strLineCnt] = point;
	

	CView::OnRButtonDown(nFlags, point);
}


void CHomework6View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CHomework6Doc* pDoc = GetDocument();		//DOC call
	
	CClientDC dc(this);

	dc.MoveTo(pDoc->mLineStart[pDoc->strLineCnt]);
	dc.LineTo(point);

	//버튼 땔시 end에 저장
	pDoc->mLineEnd[pDoc->strLineCnt] = point;

	pDoc->strLineCnt++; //strLineCnt 증가
	CView::OnRButtonUp(nFlags, point);
}


//자유곡선에서 마우스 왼쪽을 누를시
void CHomework6View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	CHomework6Doc* pDoc = GetDocument();		//DOC call

	CClientDC dc(this);

	// 10000보다 작고, 마우스 왼쪽 버튼을 눌렀을 경우
	if (pDoc->freeCnt < 10000 && (nFlags & MK_LBUTTON)) {
		dc.MoveTo(pDoc->freeLine[pDoc->freeLineCnt][pDoc->freeCnt - 1]);
		dc.LineTo(point);
		pDoc->freeLine[pDoc->freeLineCnt][pDoc->freeCnt] = point;
		pDoc->freeCnt++;
	}

	CView::OnMouseMove(nFlags, point);
}

//왼쪽
void CHomework6View::OnMenuMenu1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CHomework6Doc* pDoc = GetDocument();		//DOC call

		//자유 곡선 그리기
	for (int i = 0; i < pDoc->freeLineCnt; i++) {
		for (int j = 0; j < pDoc->LinePointCnt[i]; j++) {
			pDoc->freeLine[i][j].x = pDoc->freeLine[i][j].x - 10;
			
		}
	}

	//직선 그리기
	for (int i = 0; i < pDoc->strLineCnt; i++) {
		pDoc->mLineStart[i].x = pDoc->mLineStart[i].x  - 10;
		pDoc->mLineEnd[i].x = pDoc->mLineEnd[i].x - 10;	
	}

	Invalidate(); //무효화 ondraw를 강제적으로 부른다

}

//오른쪽
void CHomework6View::OnMenuMenu2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CHomework6Doc* pDoc = GetDocument();		//DOC call

	//자유 곡선 그리기
	for (int i = 0; i < pDoc->freeLineCnt; i++) {
		for (int j = 0; j < pDoc->LinePointCnt[i]; j++) {
			pDoc->freeLine[i][j].x = pDoc->freeLine[i][j].x + 10;

		}
	}

	//직선 그리기
	for (int i = 0; i < pDoc->strLineCnt; i++) {
		pDoc->mLineStart[i].x = pDoc->mLineStart[i].x + 10;
		pDoc->mLineEnd[i].x = pDoc->mLineEnd[i].x + 10;
	}

	Invalidate(); //무효화 ondraw를 강제적으로 부른다

}


void CHomework6View::OnMenu2Menu1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CHomework6Doc* pDoc = GetDocument();		//DOC call

	//자유 곡선 그리기
	for (int i = 0; i < pDoc->freeLineCnt; i++) {
		for (int j = 0; j < pDoc->LinePointCnt[i]; j++) {
			pDoc->freeLine[i][j].y = pDoc->freeLine[i][j].y - 10;

		}
	}

	//직선 그리기
	for (int i = 0; i < pDoc->strLineCnt; i++) {
		pDoc->mLineStart[i].y = pDoc->mLineStart[i].y - 10;
		pDoc->mLineEnd[i].y = pDoc->mLineEnd[i].y - 10;
	}

	Invalidate(); //무효화 ondraw를 강제적으로 부른다


}


void CHomework6View::OnMenu2Menu2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CHomework6Doc* pDoc = GetDocument();		//DOC call

//자유 곡선 그리기
	for (int i = 0; i < pDoc->freeLineCnt; i++) {
		for (int j = 0; j < pDoc->LinePointCnt[i]; j++) {
			pDoc->freeLine[i][j].y = pDoc->freeLine[i][j].y + 10;

		}
	}

	//직선 그리기
	for (int i = 0; i < pDoc->strLineCnt; i++) {
		pDoc->mLineStart[i].y = pDoc->mLineStart[i].y + 10;
		pDoc->mLineEnd[i].y = pDoc->mLineEnd[i].y + 10;
	}

	Invalidate(); //무효화 ondraw를 강제적으로 부른다
}
