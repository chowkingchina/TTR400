#pragma once
#include "Resource.h"


// CPWDDlg �Ի���

class CPWDDlg : public CDialog
{
	DECLARE_DYNAMIC(CPWDDlg)

public:
	CPWDDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPWDDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_pwd;
	CStatic m_table;
};
