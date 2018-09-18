#pragma once
#include "afxwin.h"


// CMyInput �Ի���

class CMyInput : public CDialog
{
	DECLARE_DYNAMIC(CMyInput)

public:
	CMyInput(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyInput();

// �Ի�������
	enum { IDD = IDD_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int glassNum;
	int showtime;
	int timer;
	bool isdropdown;
	void setShowTime(int st);
	CBrush m_brush;
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_selGlassNum;
	virtual BOOL OnInitDialog();
	CStatic m_timershow;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_inst;
};
