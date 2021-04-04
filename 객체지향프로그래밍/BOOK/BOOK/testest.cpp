// testest.cpp: 구현 파일
//

#include "pch.h"
#include "BOOK.h"
#include "testest.h"


// testest

IMPLEMENT_DYNCREATE(testest, CFormView)

testest::testest()
	: CFormView(IDD_DIALOG1)
{

}

testest::~testest()
{
}

void testest::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(testest, CFormView)
END_MESSAGE_MAP()


// testest 진단

#ifdef _DEBUG
void testest::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void testest::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// testest 메시지 처리기
