#pragma once
#include "Draw.h"
#include "PWDDlg.h"
#include "Photo.h"


// CTPJ10 �Ի���

class CTPJ10 : public CDialog
{
	DECLARE_DYNAMIC(CTPJ10)

public:
	CTPJ10(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTPJ10();

// �Ի�������
	enum { IDD = IDD_MAINDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CDraw rs;
	CPWDDlg *mypdlg;

public:
	afx_msg void OnPaint();
	LRESULT  OnHotKey(WPARAM wParam,LPARAM lParam);
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnClose();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	int imageProcess(); //ͼ������
	int  PhotoTest(CString str);
public:
	CPhoto* m_p;
	int px;  //roi left
	int py;   //roi top
	int px2;  //roi  right
	int py2;  //roi  bottom
	int huidu; //�Ҷȷ�ֵ
	int Fix;   //Ĩ̵����
	int FixMin; //Ĩ̵����
	int FixMax; //Ĩ̵����
	int PhotoT; //Ĩ̵����
	
};
