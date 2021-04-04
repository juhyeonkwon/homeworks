
// Per.h: Per 응용 프로그램의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 주 기호입니다.

struct PER1 {
	WCHAR name[20];
	WCHAR tel1[14];
	WCHAR tel2[14];
	WCHAR addr1, addr2, addr3[20];
	WCHAR bitData;
	struct PER1* next;
};

typedef struct PER1 PER;
// CPerApp:
// 이 클래스의 구현에 대해서는 Per.cpp을(를) 참조하세요.
//

class CPerApp : public CWinApp
{
public:
	CPerApp() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPerApp theApp;
