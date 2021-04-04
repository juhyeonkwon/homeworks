
// 1st.h: PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 주 기호입니다.


// CMy1stApp:
// 이 클래스의 구현에 대해서는 1st.cpp을(를) 참조하세요.
//

class CMy1stApp : public CWinApp
{
public:
	CMy1stApp();

// 재정의입니다.
public:
	virtual BOOL InitInstance();	//새로 정의해야함

// 구현입니다.

	DECLARE_MESSAGE_MAP()
};

extern CMy1stApp theApp;	//중요합니다-> 전역변수이기 때문에 실행되자마자 방이 잡히게 된다...
							//즉 클래스가 만들어지기 전에 메모리가 잡힘 종료가될때까지 존재
							//MFC는 theApp이 메모리상에 잡혀지기때문에 여기서부터 실행이 된다.

/**/