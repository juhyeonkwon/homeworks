
// Homework2Dlg.h: 헤더 파일
//

#pragma once
#include <vector>
using namespace std;
// CHomework2Dlg 대화 상자
class CHomework2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CHomework2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOMEWORK2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	CString mValEdit1;
//	CString mValEdit2;
//	CString mValEdit3;
	CButton mCtrlCheck1;
	CButton mCtrlCheck2;
	CButton mCtrlCheck3;
	int mValRadio;
	afx_msg void OnBnClickedOk();
	CString mValEdit1;
	CString mValEdit2;
	CString mValEdit3;

	void sort_asc(vector <int> v);
	void cs_max(vector <int> v);
	void sort_asc_uniq(vector <int> v);
	CString mValResult;
};
