
// Homework6Doc.h: CHomework6Doc 클래스의 인터페이스
//


#pragma once


class CHomework6Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CHomework6Doc() noexcept;
	DECLARE_DYNCREATE(CHomework6Doc)

// 특성입니다.
public:
	CPoint freeLine[100][10000];			//자유곡선
	int LinePointCnt[100];					//자유곡선안에 cnt의 갯수
	int freeLineCnt;						//자유곡선 수
	int freeCnt;							//자유곡선안의 점의갯수

	CPoint mLineStart[100], mLineEnd[100];	//직선
	int strLineCnt;							//직선 수

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CHomework6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
