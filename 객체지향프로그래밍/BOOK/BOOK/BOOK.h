
// BOOK.h: BOOK 응용 프로그램의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 주 기호입니다.

//Book에대한 구조체입니다
typedef struct {
	WCHAR book_name[50];
	WCHAR keyword1[10];
	WCHAR keyword2[10];
	WCHAR keyword3[10];
	WCHAR keyword4[10];
	WCHAR keyword5[10];
	WCHAR summary[100];
	int year;
} BOOK_STR;


// CBOOKApp:
// 이 클래스의 구현에 대해서는 BOOK.cpp을(를) 참조하세요.
//

class CBOOKApp : public CWinApp
{
public:
	CBOOKApp() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBOOKApp theApp;
