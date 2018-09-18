#pragma once
#include "Resource.h"


// CPWDDlg 对话框

class CPWDDlg : public CDialog
{
	DECLARE_DYNAMIC(CPWDDlg)

public:
	CPWDDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPWDDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_pwd;
	CStatic m_table;
};
