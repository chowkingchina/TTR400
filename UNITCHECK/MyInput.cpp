// MyInput.cpp : 实现文件
//

#include "stdafx.h"
#include "TPJ10.h"
#include "MyInput.h"


// CMyInput 对话框

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


// CMyInput 消息处理程序

void CMyInput::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	font.CreatePointFont(20,_T("华文楷体"));
	m_timershow.SetFont(&font);
	m_inst.SetFont(&font);
	m_selGlassNum.SetItemHeight(0,30);




	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void CMyInput::setShowTime(int st)
{
	showtime=st;
}
void CMyInput::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
		sprintf(text,"您还剩 %d 秒可选",showtime-timer);
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

	// TODO:  在此更改 DC 的任何属性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
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
