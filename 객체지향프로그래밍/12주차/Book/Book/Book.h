﻿
// Book.h: Book 응용 프로그램의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 주 기호입니다.


// CBookApp:
// 이 클래스의 구현에 대해서는 Book.cpp을(를) 참조하세요.
//

class CBookApp : public CWinApp
{
public:
	CBookApp() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBookApp theApp;
