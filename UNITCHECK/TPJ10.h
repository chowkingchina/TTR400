#pragma once
#include "Draw.h"
#include "PWDDlg.h"
#include "Photo.h"


// CTPJ10 对话框

class CTPJ10 : public CDialog
{
	DECLARE_DYNAMIC(CTPJ10)

public:
	CTPJ10(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTPJ10();

// 对话框数据
	enum { IDD = IDD_MAINDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
	int imageProcess(); //图像处理函数
	int  PhotoTest(CString str);
public:
	CPhoto* m_p;
	int px;  //roi left
	int py;   //roi top
	int px2;  //roi  right
	int py2;  //roi  bottom
	int huidu; //灰度阀值
	int Fix;   //抹痰参数
	int FixMin; //抹痰参数
	int FixMax; //抹痰参数
	int PhotoT; //抹痰参数
	
};
