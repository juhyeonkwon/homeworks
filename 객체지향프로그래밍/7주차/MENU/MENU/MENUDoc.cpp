
// MENUDoc.cpp: CMENUDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MENU.h"
#endif

#include "MENUDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMENUDoc

IMPLEMENT_DYNCREATE(CMENUDoc, CDocument)

BEGIN_MESSAGE_MAP(CMENUDoc, CDocument)
END_MESSAGE_MAP()


// CMENUDoc 생성/소멸

CMENUDoc::CMENUDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	mObjCnt = 0;


}

CMENUDoc::~CMENUDoc()
{
}

BOOL CMENUDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CMENUDoc serialization

void CMENUDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		ar << mObjCnt;
		for (int i = 0; i < mObjCnt; i++) {
			ar << Obj[i].mColor;
			ar << Obj[i].mFillColor;
			ar << Obj[i].mObjType;
			ar << Obj[i].mPoint1;
			ar << Obj[i].mPoint2;
		}
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		// TODO: 여기에 저장 코드를 추가합니다.
		ar >> mObjCnt;
		for (int i = 0; i < mObjCnt; i++) {
			ar >> Obj[i].mColor;
			ar >> Obj[i].mFillColor;
			ar >> Obj[i].mObjType;
			ar >> Obj[i].mPoint1;
			ar >> Obj[i].mPoint2;
		}

		UpdateAllViews(NULL);
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CMENUDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CMENUDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMENUDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMENUDoc 진단

#ifdef _DEBUG
void CMENUDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMENUDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMENUDoc 명령
