
// HomeWorkView.cpp: CHomeWorkView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HomeWork.h"
#endif

#include "HomeWorkDoc.h"
#include "HomeWorkView.h"
#include <math.h>
#include <ctime>
#include <cstdlib>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHomeWorkView

IMPLEMENT_DYNCREATE(CHomeWorkView, CView)

BEGIN_MESSAGE_MAP(CHomeWorkView, CView)
	ON_COMMAND(ID_START, &CHomeWorkView::OnStart)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CHomeWorkView 생성/소멸

CHomeWorkView::CHomeWorkView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	lineLength = 20;

}

CHomeWorkView::~CHomeWorkView()
{
}

BOOL CHomeWorkView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CHomeWorkView 그리기

void CHomeWorkView::OnDraw(CDC* /*pDC*/)
{
	CHomeWorkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	drawLine();
	drawArc();
	drawRect();
}


// CHomeWorkView 진단

#ifdef _DEBUG
void CHomeWorkView::AssertValid() const
{
	CView::AssertValid();
}

void CHomeWorkView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHomeWorkDoc* CHomeWorkView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHomeWorkDoc)));
	return (CHomeWorkDoc*)m_pDocument;
}
#endif //_DEBUG


// CHomeWorkView 메시지 처리기

//직선을 그리는 함수
void CHomeWorkView::drawLine() {
	CClientDC dc(this);

	CPen pen;

	pen.CreatePen(PS_SOLID, 10, RGB(255, 255, 0)); //10pt 노랑색

	dc.SelectObject(&pen);
	
	dc.MoveTo((int)p1.x, (int)p1.y);
	dc.LineTo((int)p2.x, (int)p2.y);

}


//원을 그리는 함수입니다.
void CHomeWorkView::drawArc() {

	CClientDC dc(this);	   

	CPen pen;

	pen.CreatePen(PS_SOLID, 5, arcCol);	//둘레 색 랜덤, 선두께는 5pt

	CBrush br;

	br.CreateSolidBrush(RGB(255, 0, 0));
	dc.SelectObject(&pen);
	dc.SelectObject(&br);
	dc.Ellipse(arc1.x, arc1.y, arc2.x, arc2.y);

}

//사각형
void CHomeWorkView::drawRect() {
	CClientDC dc(this);

	CPen pen;

	//정사각형, 한변 30pt, 둘레 초록, 선두께 4, 채움 색 랜덤, 1초에 20pt
	
	pen.CreatePen(PS_SOLID, 4, RGB(0, 255, 0));

	CBrush br;

	br.CreateSolidBrush(rectCol);

	dc.SelectObject(&pen);
	dc.SelectObject(&br);

	dc.Rectangle(r1.x, r1.y, r2.x, r2.y);

}

//초기화
void CHomeWorkView::OnStart()
{


	// TODO: 여기에 명령 처리기 코드를 추가합니다.


	CRect r;
	GetClientRect(&r);
	

	//직선 두께 10, 노랑색, 1초에 10pt 움직임
	//왼쪽 변 가운데

	p1.x = r.left;
	p1.y = r.bottom / 2;

	p2.x = p1.x + lineLength;
	p2.y = p1.y;

	lineRad = setRad(4);

	//원 지름 20pt, 둘레 색 랜덤, 둘레 선 두께 5pt, 채움 색 빨강, 1초에 5pt
	//오른쪽 변 가운데

	arcCol = RGB((rand() % 256), (rand() % 256), (rand() % 256));	//둘레색 랜덤

	arc2.x = r.right;
	arc2.y = r.bottom / 2;

	arc1.x = arc2.x - 20;
	arc1.y = arc2.y - 20;

	//처음엔 왼쪽으로 가야함
	arcRad = setRad(2);


	//정사각형, 한변 30pt, 둘레 초록, 선두께 4, 채움 색 랜덤, 1초에 20pt, 아래변 가운데

	rectCol = RGB((rand() % 256), (rand() % 256), (rand() % 256));	//채움색 랜덤

	r2.x = r.right / 2;
	r2.y = r.bottom;

	r1.x = r2.x - 30;
	r1.y = r2.y - 30;

	//처음에는 위로 가야합니다.
	rectRad = setRad(3);
 

	drawLine();
	drawArc();
	drawRect();

	SetTimer(1, 100, 0);
	SetTimer(2, 200, 0);
	SetTimer(3, 50, 0);


}


void CHomeWorkView::OnTimer(UINT_PTR nIDEvent)
{
	CClientDC dc(this);
	CRect r;
	GetClientRect(&r);
	Invalidate(TRUE);
	CString s;

	

	// 선
	if (nIDEvent == 1) {
		p1.x = p1.x + cos(lineRad) * 1;
		p1.y = p1.y + sin(lineRad) * 1;

		//충돌감지
		//위에 충돌을 했을 시
		if (p1.y - 5 < r.top) {
			lineRad = setRad(1);
		}
		else if (p2.x > r.right) {
			//오른쪽에 충돌시
			lineRad = setRad(2);
		}
		else if (p1.y + 5 > r.bottom)
		{	//아래 충돌 했을시
			lineRad = setRad(3);
		}
		else if (p1.x < r.left) {
			//왼쪽에 충돌시
			lineRad = setRad(4);
		}

		p2.x = p1.x + lineLength;
		p2.y = p1.y;
	}
	else if (nIDEvent == 2) {
		//원
		arc1.x = arc1.x + cos(arcRad) * 1;
		arc1.y = arc1.y + sin(arcRad) * 1;

		//충돌감지
		//위에 충돌을 했을 시
		if (arc1.y < r.top) {
			arcRad = setRad(1);
		}
		else if (arc2.x > r.right) {
			//오른쪽에 충돌시
			arcRad = setRad(2);
		}
		else if (arc2.y > r.bottom)
		{	//아래 충돌 했을시
			arcRad = setRad(3);
		}
		else if (arc1.x < r.left) {
			//왼쪽에 충돌시
			arcRad = setRad(4);
		}

		arc2.x = arc1.x + 20;
		arc2.y = arc1.y + 20;
	}
	else if (nIDEvent == 3) {
		//사각형
		r1.x = r1.x + cos(rectRad) * 1;
		r1.y = r1.y + sin(rectRad) * 1;

		//위에 충돌을 했을 시
		if (r1.y < r.top) {
			rectRad = setRad(1);
		}
		else if (r2.x > r.right) {
			//오른쪽에 충돌시
			rectRad = setRad(2);
		}
		else if (r2.y > r.bottom)
		{	//아래 충돌 했을시
			rectRad = setRad(3);
		}
		else if (r1.x < r.left) {
			//왼쪽에 충돌시
			rectRad = setRad(4);
		}

		r2.x = r1.x + 30;
		r2.y = r1.y + 30;
	}


	CView::OnTimer(nIDEvent);
}

//위, 오른쪽, 아래쪽, 왼쪽 순으로 포지션 값을 받아와서 그 값에맞춰서 rad값을 리턴 해줍니다
double CHomeWorkView::setRad(int position) {
	/*
	위 : 1
	오른쪽 : 2
	아래 : 3
	왼쪽 : 4
	*/

	double angle;

	srand((unsigned int)time(NULL)); //rand를 진짜 랜덤으로 받기 위해...


	if (position == 1) {
		//밑으로 이동해야 하기 때문에 각도는 0 < angle < 180 인데 +60, -60 이기때문에 30 < angle < 150으로 설정
		while (true) {
			angle = rand() % 150;
			if (angle > 30 && angle < 150) {
				break;
			}
		}
		return angle * (3.14159 / 180);
	}
	else if (position == 2) {
		//왼쪽으로이동해야 하기때문에 각도는 90 < angle < 270 인데 +60, -60 이기 때문에 120 < angle < 240으로 설정
		while (true) {
			angle = rand() % 240;
			if (angle > 120 && angle < 240) {
				break;
			}
		}
		return angle * (3.14159 / 180);
	}
	else if (position == 3) {
		//위로 이동을 해야 하기 때문에 각도는 180 < angle < 360 인데 +60, -60 이기 때문에, 210 < angle < 330으로 설정
		while (true) {
			angle = rand() % 330;
			if (angle > 210 && angle < 330) {
				break;
			}
		}
		return angle * (3.14159 / 180);
	}
	else if (position == 4) {
		//오른쪽으로 이동해야 하기 때문에 각도는 0 < rad < 90 || 270 < rad < 360 이지만 +- 60이기때문에, 0 < rad < 60, 300 < rad< 360
		while (true) {
			angle = rand() % 361;
			if ((angle > 0 && angle < 60) || (angle > 300 && angle < 360)) {
				break;
			}
		}
		return angle * (3.14159 / 180);
	}

}

void CHomeWorkView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDown(nFlags, point);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.


	CRect r;
	GetClientRect(&r);


	//직선 두께 10, 노랑색, 1초에 10pt 움직임
	//왼쪽 변 가운데

	p1.x = r.left;
	p1.y = r.bottom / 2;

	p2.x = p1.x + lineLength;
	p2.y = p1.y;

	lineRad = setRad(4);

	//원 지름 20pt, 둘레 색 랜덤, 둘레 선 두께 5pt, 채움 색 빨강, 1초에 5pt
	//오른쪽 변 가운데

	arcCol = RGB((rand() % 256), (rand() % 256), (rand() % 256));	//둘레색 랜덤

	arc2.x = r.right;
	arc2.y = r.bottom / 2;

	arc1.x = arc2.x - 20;
	arc1.y = arc2.y - 20;

	//처음엔 왼쪽으로 가야함
	arcRad = setRad(2);


	//정사각형, 한변 30pt, 둘레 초록, 선두께 4, 채움 색 랜덤, 1초에 20pt, 아래변 가운데

	rectCol = RGB((rand() % 256), (rand() % 256), (rand() % 256));	//채움색 랜덤

	r2.x = r.right / 2;
	r2.y = r.bottom;

	r1.x = r2.x - 30;
	r1.y = r2.y - 30;

	//처음에는 위로 가야합니다.
	rectRad = setRad(3);


	drawLine();
	drawArc();
	drawRect();

	SetTimer(1, 100, 0);
	SetTimer(2, 200, 0);
	SetTimer(3, 50, 0);

}
