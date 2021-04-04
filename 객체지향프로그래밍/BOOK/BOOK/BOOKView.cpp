
// BOOKView.cpp: CBOOKView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "BOOK.h"
#endif

#include "BOOKDoc.h"
#include "BOOKView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBOOKView

IMPLEMENT_DYNCREATE(CBOOKView, CFormView)

BEGIN_MESSAGE_MAP(CBOOKView, CFormView)
	ON_BN_CLICKED(IDC_ADD, &CBOOKView::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SEARCH, &CBOOKView::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_LIST, &CBOOKView::OnBnClickedList)
END_MESSAGE_MAP()

// CBOOKView 생성/소멸

CBOOKView::CBOOKView() noexcept
	: CFormView(IDD_BOOK_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CBOOKView::~CBOOKView()
{
}

void CBOOKView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mCtrlList);
}

BOOL CBOOKView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CBOOKView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//시작 했을때 화면에 값을 띄웁니다.. 책이름, 키워드(5개), 책 개요(최대 200자)
	static int initialized = 0;			//처음일 경우에만...

	if (initialized == 0) {
		LV_COLUMN col;
		WCHAR col_name[8][8] = { L"책이름", L"키워드1", L"키워드2", L"키워드3", L"키워드4", L"키워드5", L"개요", L"출판년도" };
		int width[8] = { 200, 100, 100, 100, 100, 100, 400, 70 };
		for (int i = 0; i < 8; i++) {
			col.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
			col.fmt = LVCFMT_CENTER;
			col.pszText = col_name[i];
			col.cx = width[i];
			col.cchTextMax = width[i];
			mCtrlList.InsertColumn(i, &col);
		}

		mCtrlList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
		initialized = 1;
	}

	DisplayData();
}

void CBOOKView::DisplayData() {
	CBOOKDoc *p = GetDocument();
	CString s;
	mCtrlList.DeleteAllItems();

	for (int i = 0; i < p->mBookCnt; i++) {
		CString s;


		mCtrlList.InsertItem(i, p->mBook[i].book_name);
		mCtrlList.SetItemText(i, 1, p->mBook[i].keyword1);
		mCtrlList.SetItemText(i, 2, p->mBook[i].keyword2);
		mCtrlList.SetItemText(i, 3, p->mBook[i].keyword3);
		mCtrlList.SetItemText(i, 4, p->mBook[i].keyword4);
		mCtrlList.SetItemText(i, 5, p->mBook[i].keyword5);
		mCtrlList.SetItemText(i, 6, p->mBook[i].summary);

		s.Format(L"%d", p->mBook[i].year);
		mCtrlList.SetItemText(i, 7, s);
	}
}


// CBOOKView 진단

#ifdef _DEBUG
void CBOOKView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBOOKView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CBOOKDoc* CBOOKView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBOOKDoc)));
	return (CBOOKDoc*)m_pDocument;
}
#endif //_DEBUG


// CBOOKView 메시지 처리기

#include "Insert.h"

void CBOOKView::OnBnClickedAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CInsert dg;				//insert를 불러옵니다..
	CBOOKDoc *p = GetDocument();

	//OK가 들어왔을 경우..
	if (dg.DoModal() == IDOK) {
		wcscpy_s(p->mBook[p->mBookCnt].book_name, dg.mValName);		//이름
		wcscpy_s(p->mBook[p->mBookCnt].keyword1, dg.mValKeyword1);
		wcscpy_s(p->mBook[p->mBookCnt].keyword2, dg.mValKeyword2);
		wcscpy_s(p->mBook[p->mBookCnt].keyword3, dg.mValKeyword3);
		wcscpy_s(p->mBook[p->mBookCnt].keyword4, dg.mValKeyword4);
		wcscpy_s(p->mBook[p->mBookCnt].keyword5, dg.mValKeyword5);
		wcscpy_s(p->mBook[p->mBookCnt].summary, dg.mValSummary);
		p->mBook[p->mBookCnt].year = dg.year;

		CString s;


		mCtrlList.InsertItem(p->mBookCnt, p->mBook[p->mBookCnt].book_name);
		mCtrlList.SetItemText(p->mBookCnt, 1, p->mBook[p->mBookCnt].keyword1);
		mCtrlList.SetItemText(p->mBookCnt, 2, p->mBook[p->mBookCnt].keyword2);
		mCtrlList.SetItemText(p->mBookCnt, 3, p->mBook[p->mBookCnt].keyword3);
		mCtrlList.SetItemText(p->mBookCnt, 4, p->mBook[p->mBookCnt].keyword4);
		mCtrlList.SetItemText(p->mBookCnt, 5, p->mBook[p->mBookCnt].keyword5);
		mCtrlList.SetItemText(p->mBookCnt, 6, p->mBook[p->mBookCnt].summary);

		s.Format(L"%d", p->mBook[p->mBookCnt].year);
		mCtrlList.SetItemText(p->mBookCnt, 7, s);

		p->mBookCnt++;


	}
}

#include "Search.h"
//검색을 클릭시
void CBOOKView::OnBnClickedSearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSearch dg;
	CBOOKDoc *p = GetDocument();
	int search = 0;
	if (dg.DoModal() == IDOK) {
		//창을 킵니다..
		mCtrlList.DeleteAllItems();

		//키워드에 맞는걸 발견하면 printSearc를 실행시킵니다..
		for (int i = 0; i < p->mBookCnt; i++) {
			if (p->mBook[i].keyword1 == dg.mValKeyword || p->mBook[i].keyword2 == dg.mValKeyword || p->mBook[i].keyword3 == dg.mValKeyword ||
				p->mBook[i].keyword4 == dg.mValKeyword || p->mBook[i].keyword5 == dg.mValKeyword) {
				printSearch(i, search);
				search++;
			}
		}
	}

}

void CBOOKView::printSearch(int i, int search) {
	CBOOKDoc *p = GetDocument();

	CString s;

	//i번째 인덱스의 내용을 출력합니다.
	mCtrlList.InsertItem(search, p->mBook[i].book_name);
	mCtrlList.SetItemText(search, 1, p->mBook[i].keyword1);
	mCtrlList.SetItemText(search, 2, p->mBook[i].keyword2);
	mCtrlList.SetItemText(search, 3, p->mBook[i].keyword3);
	mCtrlList.SetItemText(search, 4, p->mBook[i].keyword4);
	mCtrlList.SetItemText(search, 5, p->mBook[i].keyword5);
	mCtrlList.SetItemText(search, 6, p->mBook[i].summary);

	s.Format(L"%d", p->mBook[i].year);
	mCtrlList.SetItemText(search, 7, s);
	
}


//리스트 보기 클릭시 다시 리스트를 보여줍니다..
void CBOOKView::OnBnClickedList()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DisplayData();
}
