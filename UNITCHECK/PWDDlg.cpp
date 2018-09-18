// PWDDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PWDDlg.h"
#include "TPJ10.h"


// CPWDDlg 对话框

IMPLEMENT_DYNAMIC(CPWDDlg, CDialog)

CPWDDlg::CPWDDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPWDDlg::IDD, pParent)
	, m_pwd(_T(""))
{

}

CPWDDlg::~CPWDDlg()
{
}

void CPWDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_pwd);
	DDX_Control(pDX, IDC_TABLE, m_table);
}


BEGIN_MESSAGE_MAP(CPWDDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CPWDDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPWDDlg 消息处理程序

void CPWDDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_pwd=="07103340930")
	{
		m_table.SetWindowTextA("请输入密码解锁调试程序");
		((CTPJ10 *)GetParent())->rs.m_toolbar[3].Enable(true);
		((CTPJ10 *)GetParent())->mypdlg->ShowWindow(SW_HIDE);

	}
	else
	{
		m_table.SetWindowTextA("密码输入错误，请重新输入");

	}
	m_pwd="";
	UpdateData(false);
	Invalidate(false);
}
