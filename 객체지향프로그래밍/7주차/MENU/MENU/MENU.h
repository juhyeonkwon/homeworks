
// MENU.h: MENU 응용 프로그램의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 주 기호입니다.

#define COLOR_RED   1
#define COLOR_GREEN 2
#define COLOR_BLUE  3

#define LINE	     1
#define RECT	     2
#define ELLIPSE      3
#define RECT_FILL    4
#define ELLIPSE_FILL 5

typedef struct {
	int mColor, mFillColor, mObjType;
	CPoint mPoint1, mPoint2;
} DATA;


// CMENUApp:
// 이 클래스의 구현에 대해서는 MENU.cpp을(를) 참조하세요.
//

class CMENUApp : public CWinApp
{
public:
	CMENUApp() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMENUApp theApp;
