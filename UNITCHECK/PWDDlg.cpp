// PWDDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PWDDlg.h"
#include "TPJ10.h"


// CPWDDlg �Ի���

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


// CPWDDlg ��Ϣ�������

void CPWDDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if(m_pwd=="07103340930")
	{
		m_table.SetWindowTextA("����������������Գ���");
		((CTPJ10 *)GetParent())->rs.m_toolbar[3].Enable(true);
		((CTPJ10 *)GetParent())->mypdlg->ShowWindow(SW_HIDE);

	}
	else
	{
		m_table.SetWindowTextA("���������������������");

	}
	m_pwd="";
	UpdateData(false);
	Invalidate(false);
}
