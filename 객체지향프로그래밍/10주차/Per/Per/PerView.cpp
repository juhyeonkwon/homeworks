
// PerView.cpp: CPerView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Per.h"
#endif

#include "PerDoc.h"
#include "CInsert.h"
#include "PerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define HOBBYCNT 5

WCHAR gAddr1[6][8] = { L"경남", L"경북", L"부산", L"서울", L"전남", L"전북" };
int gAddr1_cnt = 6;

//경남
WCHAR gAddr2[6][7][8] = { {L"거창군", L"고성군", L"사천시", L"진주시", L"창원시", L"통영시", L"하동군"},
					  {L"경주시", L"영천시", L"영덕군", L"포항시", L"안동시"},
					  {L"사상구", L"영도구", L"동래구", L"진구"},
					  {L"강남구", L"서초구", L"관악구", L"강동구", L"영등포구", L"중구"},
				      {L"강진군", L"담양군", L"순천시", L"여수시", L"목포시"},
					  {L"임실군", L"전주시", L"익산시", L"구례군", L"남원시"} 
};
int gAddr2_cnt[6] = { 7, 5, 4, 5, 5, 5 };

WCHAR gHobby[HOBBYCNT][10] = { L"독서", L"등산", L"낚시", L"게임", L"축구" };

// CPerView

IMPLEMENT_DYNCREATE(CPerView, CFormView)

BEGIN_MESSAGE_MAP(CPerView, CFormView)
	ON_BN_CLICKED(IDC_INSERT, &CPerView::OnBnClickedInsert)
	ON_BN_CLICKED(IDC_DELETE, &CPerView::OnBnClickedDelete)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST6, &CPerView::OnItemchangedList6)
	ON_NOTIFY(NM_CLICK, IDC_LIST6, &CPerView::OnClickList6)
	ON_BN_CLICKED(IDC_UPDATE, &CPerView::OnBnClickedUpdate)
	ON_BN_CLICKED(IDM_INSERT2, &CPerView::OnInsert2)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CPerView::OnItemclickList6)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST6, &CPerView::OnColumnclickList6)
END_MESSAGE_MAP()

// CPerView 생성/소멸

CPerView::CPerView() noexcept
	: CFormView(IDD_PER_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

CPerView::~CPerView()
{
}

void CPerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST6, mCtrlList);
}

BOOL CPerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

//폼뷰에서는 OnInitialUpdate가 초기에 실행이되고, 로드가 될경우 이게 다시 불러지게된다
//폼뷰에서는 OnInitialUpdate가 초기에 실행이되고, 로드가 될경우 이게 다시 불러지게된다
//폼뷰에서는 OnInitialUpdate가 초기에 실행이되고, 로드가 될경우 이게 다시 불러지게된다

void CPerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	mListIdx = 0;
	static int initialized = 0;
	if (initialized == 0) {
		LV_COLUMN col;
		WCHAR col_name[8][6] = { L"name", L"tel1", L"tel2", L"addr", L"hobby", L"marry", L"Kids", L"Age" };
		int width[8] = { 80, 100, 100, 200, 200, 150, 70, 40 };
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

void CPerView::DisplayData() {
	
	CPerDoc *p = GetDocument();
	CString s;
	WCHAR a = 0;
	mCtrlList.DeleteAllItems();
	p->mpCur = p->mpFirst;
	for (int i = 0; i < p->mPerCnt; i++) {

		mCtrlList.InsertItem(i, p->mpCur->name);
		mCtrlList.SetItemText(i, 1, p->mpCur->tel1);
		mCtrlList.SetItemText(i, 2, p->mpCur->tel2);
		s.Format(L"%s %s %s", gAddr1[p->mpCur->addr1], gAddr2[p->mpCur->addr2], p->mpCur->addr3);
		mCtrlList.SetItemText(i, 3, s);

		s = L"";

		
		if (p->mpCur->bitData & 0x0001) { s = gHobby[0]; }
		if (p->mpCur->bitData & 0x0002) { s = s + L" " + gHobby[1]; }
		if (p->mpCur->bitData & 0x0004) { s = s + L" " + gHobby[2]; }
		if (p->mpCur->bitData & 0x0008) { s = s + L" " + gHobby[3]; }
		if (p->mpCur->bitData & 0x0010) { s = s + L" " + gHobby[4]; }

	
		mCtrlList.SetItemText(i, 4, s);

		s = (!(p->mpCur->bitData & 0x0020)) ? s = L"미혼" : L"결혼";
		mCtrlList.SetItemText(i, 5, s);

		a = (p->mpCur->bitData >> 6) & 0x0007;
		s.Format(L"%d명", a);
		if (a == 4) s = s + L"이상";
		mCtrlList.SetItemText(i, 6, s);

		a = (p->mpCur->bitData >> 9) & 0x007F;		//0000 0000 0111 1111
		s.Format(L"%d", a);
		mCtrlList.SetItemText(i, 7, s);


		p->mpCur = p->mpCur->next;
	}
}

// CPerView 진단

#ifdef _DEBUG
void CPerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPerDoc* CPerView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPerDoc)));
	return (CPerDoc*)m_pDocument;
}
#endif //_DEBUG


// CPerView 메시지 처리기

void CPerView::OnInsert2() {

	InsertData(mInsertDlg, -1);
}

void CPerView::OnBnClickedInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CInsert dg;
	
	dg.mAddr1Idx = 0;
	dg.mAddr2Idx = 0;
	dg.mAgeIdx = 21;
	mInsertDlg = &dg;
	dg.mIsInsertMode = TRUE;
	
	if (dg.DoModal() == IDOK) {
		InsertData(&dg, -1);
	}
}

// opt : -1(insert), 0보다 크면 업데이트
void CPerView::InsertData(CInsert *dg, int opt) {

	CPerDoc *p = GetDocument();
	WCHAR a = 0;

	int idx;
	PER *temp;
	// 링크드리스트
	if (opt == -1) {
		idx = p->mPerCnt;

		if (p->mPerCnt == 0) {
			p->mpFirst = p->mpLast = temp = (PER *)malloc(sizeof(PER));
		}
		else {
			temp = (PER *)malloc(sizeof(PER));
			p->mpLast->next = temp;
			p->mpLast = p->mpLast->next;
			//p->mPer[idx] = (PER *)malloc(sizeof(PER));
		}
		temp->next = (PER *)NULL;

	}
	else {
		idx = opt;
		temp = GetCurNode(p->mpFirst, idx, p->mPerCnt);
	}
	wcscpy_s(temp->name, dg->mValName);
	wcscpy_s(temp->tel1, dg->mValTel1);
	wcscpy_s(temp->tel2, dg->mValTel2);

	CString s;
	if(opt == -1) mCtrlList.InsertItem(idx, temp->name);
	else mCtrlList.SetItemText(idx, 0, temp->name);
	mCtrlList.SetItemText(idx, 1, temp->tel1);
	mCtrlList.SetItemText(idx, 2, temp->tel2);
	s.Format(L"%s %s %s", gAddr1[dg->mAddr1Idx], gAddr2[dg->mAddr2Idx], dg->mValAddr3);
	temp->addr1 = dg->mAddr1Idx;
	temp->addr2 = dg->mAddr2Idx;
	wcscpy_s(temp->addr3, dg->mValAddr3);
	mCtrlList.SetItemText(idx, 3, s);

	s = L"";
	if (dg->mValReading) { s = gHobby[0]; }
	if (dg->mValClimbing) { s = s + L" " + gHobby[1]; }
	if (dg->mValFishing) { s = s + L" " + gHobby[2]; }
	if (dg->mValGame) { s = s + L" " + gHobby[3]; }
	if (dg->mValSoccer) { s = s + L" " + gHobby[4]; }

	CString sb;
	temp->bitData = dg->mValReading | dg->mValClimbing << 1 | dg->mValFishing << 2 | dg->mValGame << 3
		| dg->mValSoccer << 4 | dg->mValSingle << 5
		| ((dg->mValSingle) ? dg->mValKid0 << 6 : 0) | dg->mAgeIdx << 9;
	

	mCtrlList.SetItemText(idx, 4, s);

	s = (dg->mValSingle == 0) ? s = L"미혼" : L"결혼";
	mCtrlList.SetItemText(idx, 5, s);

	//dg.mvalKid0
	s = L"";
	if (dg->mValSingle) {
		s.Format(L"%d명", dg->mValKid0);
		if (dg->mValKid0 == 4) s = s + L"이상";
	}
	else s = L"0명";
	mCtrlList.SetItemText(idx, 6, s);


	s.Format(L"%d", dg->mAgeIdx);
	mCtrlList.SetItemText(idx, 7, s);


	if(opt == -1) p->mPerCnt++;
	
	/* 배열 사용시
	if (opt == -1) {
		idx = p->mPerCnt;
		p->mPer[idx] = (PER *)malloc(sizeof(PER));
	}
	else idx = mListIdx;

	wcscpy_s(p->mPer[idx]->name, dg->mValName);
	wcscpy_s(p->mPer[idx]->tel1, dg->mValTel1);
	wcscpy_s(p->mPer[idx]->tel2, dg->mValTel2);

	CString s;
	if(opt == -1) mCtrlList.InsertItem(idx, p->mPer[idx]->name);
	else mCtrlList.SetItemText(idx, 0, p->mPer[idx]->name);
	mCtrlList.SetItemText(idx, 1, p->mPer[idx]->tel1);
	mCtrlList.SetItemText(idx, 2, p->mPer[idx]->tel2);
	s.Format(L"%s %s %s", gAddr1[dg->mAddr1Idx], gAddr2[dg->mAddr2Idx], dg->mValAddr3);
	p->mPer[idx]->addr1 = dg->mAddr1Idx;
	p->mPer[idx]->addr2 = dg->mAddr2Idx;
	wcscpy_s(p->mPer[idx]->addr3, dg->mValAddr3);
	mCtrlList.SetItemText(idx, 3, s);

	s = L"";
	if (dg->mValReading) { s = gHobby[0]; }
	if (dg->mValClimbing) { s = s + L" " + gHobby[1]; }
	if (dg->mValFishing) { s = s + L" " + gHobby[2]; }
	if (dg->mValGame) { s = s + L" " + gHobby[3]; }
	if (dg->mValSoccer) { s = s + L" " + gHobby[4]; }

	p->mPer[idx]->bitData = dg->mValReading | dg->mValClimbing << 1 | dg->mValFishing << 2 | dg->mValGame << 3
		| dg->mValSoccer << 4 | dg->mValSingle << 5
		| ((dg->mValSingle) ? dg->mValKid0 << 6 : 0) | dg->mAgeIdx << 9;

	mCtrlList.SetItemText(idx, 4, s);

	s = (dg->mValSingle == 0) ? s = L"미혼" : L"결혼";
	mCtrlList.SetItemText(idx, 5, s);

	//dg.mvalKid0
	s = L"";
	if (dg->mValSingle) {
		s.Format(L"%d명", dg->mValKid0);
		if (dg->mValKid0 == 4) s = s + L"이상";
	}
	else s = L"0명";
	mCtrlList.SetItemText(idx, 6, s);


	s.Format(L"%d", dg->mAgeIdx);
	mCtrlList.SetItemText(idx, 7, s);


	if(opt == -1) p->mPerCnt++;
	*/
}
PER* CPerView::GetCurNode(PER *pFirst, int idx, int cnt) {
	PER* temp;
	temp = pFirst;

	for (int i =idx + 1; i < cnt; i++) {
		temp = temp->next;

	}
	return (temp);
}

void CPerView::OnBnClickedDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int yesno = MessageBox(L"Do you really delete?", L"Item Deletion", MB_YESNO);
	if (yesno != IDYES) return;

	mCtrlList.DeleteItem(mListIdx);
	DeleteMemData(mListIdx);
	
}

void CPerView::DeleteMemData(int idx) {
	CPerDoc *p = GetDocument();
	if (mListIdx < 0) {
		return ;
	}
	PER* temp, *temp2;
	if (idx == 0) {
		temp = p->mpFirst->next;
		free(p->mpFirst);
		p->mpFirst = temp;

	}
	else {
		temp = GetCurNode(p->mpFirst, idx - 1, p->mPerCnt);
		temp2 = temp->next;
		temp->next = temp2->next;
		free(temp2);
	}
	p->mPerCnt--;
	/*
	for (int i = idx; i < p->mPerCnt - 1; i++) {
		memcpy((void *)&(p->mPer[i]), (void *)&(p->mPer[i + 1]), sizeof(PER));
	}
	*/

	/*
	free(p->mPer[idx]);
	p->mPer[idx] = p->mPer[p->mPerCnt - 1];
	p->mPer[p->mPerCnt - 1] = (PER *)NULL;
	   
	p->mPerCnt--;
	*/
}

void CPerView::OnItemchangedList6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CPerView::OnClickList6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	mListIdx = pNMItemActivate->iItem;

	CString s;
	s.Format(L"%d", mListIdx);

	*pResult = 0;
}



void CPerView::OnBnClickedUpdate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (mListIdx < 0) return;

	CPerDoc *p = GetDocument();
	WCHAR a = 0;
	CInsert dg;

	PER *temp = GetCurNode(p->mpFirst, mListIdx, p->mPerCnt);

	
	dg.mValName = temp->name;
	dg.mValTel1 = temp->tel1;
	dg.mValTel2 = temp->tel2;

	dg.mValName = temp->name;
	dg.mValTel1 = temp->tel1;
	dg.mValTel2 = temp->tel2;
	dg.mAddr1Idx = temp->addr1;
	dg.mAddr2Idx = temp->addr2;
	dg.mValAddr3 = temp->addr3;

	dg.mValReading = temp->bitData & 0x0001;
	dg.mValClimbing = (temp->bitData >> 1) & 0x0001;
	dg.mValFishing = (temp->bitData >> 2) & 0x0001;
	dg.mValGame = (temp->bitData >> 3) & 0x0001;
	dg.mValSoccer = (temp->bitData >> 4) & 0x0001;
	dg.mValSingle = (temp->bitData >> 5) & 0x0001;
	dg.mValKid0 = (temp->bitData >> 6) & 0x0007;	// 0111
	dg.mAgeIdx = (temp->bitData >> 9) & 0x007F;		// 0111 1111

	

	/* 배열
	dg.mValName = p->mPer[mListIdx]->name;
	dg.mValTel1 = p->mPer[mListIdx]->tel1;
	dg.mValTel2 = p->mPer[mListIdx]->tel2;

	dg.mValName = p->mPer[mListIdx]->name;
	dg.mValTel1 = p->mPer[mListIdx]->tel1;
	dg.mValTel2 = p->mPer[mListIdx]->tel2;
	dg.mAddr1Idx = p->mPer[mListIdx]->addr1;
	dg.mAddr2Idx = p->mPer[mListIdx]->addr2;
	dg.mValAddr3 = p->mPer[mListIdx]->addr3;

	dg.mValReading = p->mPer[mListIdx]->bitData & 0x0001;
	dg.mValClimbing = (p->mPer[mListIdx]->bitData >> 1) & 0x0001;
	dg.mValFishing = (p->mPer[mListIdx]->bitData >> 2) & 0x0001;
	dg.mValGame = (p->mPer[mListIdx]->bitData >> 3) & 0x0001;
	dg.mValSoccer = (p->mPer[mListIdx]->bitData >> 4) & 0x0001;
	dg.mValSingle = (p->mPer[mListIdx]->bitData >> 5) & 0x0001;
	dg.mValKid0 = (p->mPer[mListIdx]->bitData >> 6) & 0x0007;	// 0111
	dg.mAgeIdx = (p->mPer[mListIdx]->bitData >> 9) & 0x007F;		// 0111 1111

	*/
	dg.mIsInsertMode = FALSE;
	if (dg.DoModal() == IDOK) InsertData(&dg, mListIdx);


}


void CPerView::OnItemclickList6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CPerView::OnColumnclickList6(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	CPerDoc *p = GetDocument();
	PER* mp;

	/*
	//이름
	if (pNMLV->iItem == -1 && pNMLV->iSubItem == 0) {
		for (int i = 0; i < p->mPerCnt - 1; i++) {
			for (int j = i + 1; j < p->mPerCnt; j++) {
				if (StrCmpCW(p->mPer[i]->name, p->mPer[j]->name) > 0) {
					mp = p->mPer[i];
					p->mPer[i] = p->mPer[j];
					p->mPer[j] = mp;
				}
			}
		}	DisplayData();

	}
	//전화번호
	else if (pNMLV->iItem == -1 && pNMLV->iSubItem == 1) {
		for (int i = 0; i < p->mPerCnt - 1; i++) {
			for (int j = i + 1; j < p->mPerCnt; j++) {
				if (StrCmpCW(p->mPer[i]->tel1, p->mPer[j]->tel1) > 0) {
					mp = p->mPer[i];
					p->mPer[i] = p->mPer[j];
					p->mPer[j] = mp;
				}
			}
		}	DisplayData();

	}
	//나이
	else if (pNMLV->iItem == -1 && pNMLV->iSubItem == 7) {
		for (int i = 0; i < p->mPerCnt - 1; i++) {
			for (int j = i + 1; j < p->mPerCnt; j++) {
				if (((p->mPer[i]->bitData >> 9) & 0x007F) > ((p->mPer[j]->bitData >> 9) & 0x007F)) {
					mp = p->mPer[i];
					p->mPer[i] = p->mPer[j];
					p->mPer[j] = mp;
}
			}
		}	DisplayData();

	}
	*/
}
