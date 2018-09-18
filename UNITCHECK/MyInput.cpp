// MyInput.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TPJ10.h"
#include "MyInput.h"


// CMyInput �Ի���

IMPLEMENT_DYNAMIC(CMyInput, CDialog)

CMyInput::CMyInput(CWnd* pParent /*=NULL*/)
	: CDialog(CMyInput::IDD, pParent)
{
	glassNum=10;
	showtime=30;
	timer=0;
	isdropdown=false;

}

CMyInput::~CMyInput()
{
}

void CMyInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_selGlassNum);
	DDX_Control(pDX, IDC_TIMERSHOW, m_timershow);
	DDX_Control(pDX, IDC_STATIC1, m_inst);
}


BEGIN_MESSAGE_MAP(CMyInput, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMyInput::OnCbnSelchangeCombo1)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMyInput ��Ϣ�������

void CMyInput::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	glassNum=m_selGlassNum.GetCurSel()+1;
}

BOOL CMyInput::OnInitDialog()
{
	CDialog::OnInitDialog();
	CString Num;
	for(int i=0;i<10;i++)
	{
		Num.Format("%d",i+1);
		m_selGlassNum.InsertString(-1,Num);
	}
	m_selGlassNum.SetCurSel(9);
	SetTimer(1,1000,NULL);
	m_brush.CreateSolidBrush(RGB(150,200,150));
	SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,GetWindowLong(GetSafeHwnd(),GWL_EXSTYLE)|WS_EX_LAYERED);
	SetLayeredWindowAttributes(0,200,LWA_ALPHA);
	CFont font;
	font.CreatePointFont(20,_T("���Ŀ���"));
	m_timershow.SetFont(&font);
	m_inst.SetFont(&font);
	m_selGlassNum.SetItemHeight(0,30);




	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
void CMyInput::setShowTime(int st)
{
	showtime=st;
}
void CMyInput::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent==1)
	{
		if(timer<showtime)
		{
		timer++;
		if(timer>=4 && !isdropdown)
		{
			isdropdown=true;
			m_selGlassNum.ShowDropDown(true);

		}
		char text[100];
		sprintf(text,"����ʣ %d ���ѡ",showtime-timer);
		m_timershow.SetWindowText(text);
		Invalidate(false);
		}
		else
		{
			OnOK();
		}
	}


	CDialog::OnTimer(nIDEvent);
}

HBRUSH CMyInput::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	if(pWnd->GetDlgCtrlID()==IDC_TIMERSHOW)
	{
		pDC->SetTextColor(RGB(150,0,0));
	}
	if(pWnd->GetDlgCtrlID()==IDC_STATIC1)
	{
		pDC->SetTextColor(RGB(20,20,20));

	}
	pDC->SetBkColor(RGB(150,200,150));
	return m_brush;
}
