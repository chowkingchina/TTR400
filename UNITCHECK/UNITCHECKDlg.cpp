
// UNITCHECKDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "UNITCHECK.h"
#include "UNITCHECKDlg.h"
#include "TPJ10.h"





#ifdef _DEBUG
#define new DEBUG_NEW
#endif d


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框


DWORD WINAPI chaneCheck( LPVOID pParam )
{
	CUNITCHECKDlg* pDlg=( CUNITCHECKDlg*)pParam;
	while(!pDlg->endflag)
	{
		for(int i=0;i<theApp.inputnum;i++)
		{
			if(pDlg->endflag)
				break;
			((CButton *)(pDlg->GetDlgItem(IDC_CHECK1+i)))->SetCheck(theApp.status[i]);
		}
		for(int i=0;i<theApp.chipnum;i++)
		{
			if(pDlg->endflag)
				break;
			((CButton *)(pDlg->GetDlgItem(IDC_CHECK1+i+theApp.inputnum)))->SetCheck(theApp.status[i+theApp.inputnum]);
		}
		Sleep(2);
	}
	pDlg->showthreaddone=true;
	return -1;
}
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CUNITCHECKDlg 对话框




CUNITCHECKDlg::CUNITCHECKDlg(CWnd* pParent /*=NULL*/)
: CDialog(CUNITCHECKDlg::IDD, pParent)
, m_unox_hspeedh(0)
, m_unox_hspeedm(0)
, m_unox_hspeedl(0)
, m_unox_lspeedh(0)
, m_unox_lspeedm(0)
, m_unox_lspeedl(0)
, m_unoy_hspeedh(0)
, m_unoy_hspeedm(0)
, m_unoy_hspeedl(0)
, m_unoy_lspeedl(0)
, m_unoy_lspeedm(0)
, m_unoy_lspeedh(0)
, m_unoz_hspeedh(0)
, m_unoz_hspeedm(0)
, m_unoz_hspeedl(0)
, m_unoz_lspeedl(0)
, m_unoz_lspeedm(0)
, m_unoz_lspeedh(0)
, m_unok_hspeedh(0)
, m_unok_hspeedm(0)
, m_unok_hspeedl(0)
, m_unok_lspeedl(0)
, m_unok_lspeedm(0)
, m_unok_lspeedh(0)
, m_a_x_pos(0)
, m_a_x_step(0)
, m_a_y_pos(0)
, m_a_y_step(0)
, m_a_z_pos(0)
, m_a_z_step(0)
, m_a_k_pos(0)
, m_a_k_step(0)
, m_unol_hspeedh(0)
, m_unol_lspeedh(0)
, m_unol_hspeedm(0)
, m_unol_lspeedm(0)
, m_unol_hspeedl(0)
, m_unol_lspeedl(0)
, m_a_l_pos(0)
, m_a_l_step(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_ICON1);
	showthreaddone=false;
	endflag=false;
	initcheck=false;
	scpcheck=false;
	startcheck=false;
	changemodecheck=false;
}
CUNITCHECKDlg::~CUNITCHECKDlg()
{
	theApp.endflag=true;

}
void CUNITCHECKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_unox_hspeedh);
	DDV_MinMaxInt(pDX, m_unox_hspeedh, 0,1000);
	DDX_Text(pDX, IDC_EDIT2, m_unox_hspeedm);
	DDV_MinMaxInt(pDX, m_unox_hspeedm, 0,1000);
	DDX_Text(pDX, IDC_EDIT3, m_unox_hspeedl);
	DDV_MinMaxInt(pDX, m_unox_hspeedl, 0,1000);
	DDX_Text(pDX, IDC_EDIT4, m_unox_lspeedh);
	DDV_MinMaxInt(pDX, m_unox_lspeedh, 0,1000);
	DDX_Text(pDX, IDC_EDIT5, m_unox_lspeedm);
	DDV_MinMaxInt(pDX, m_unox_lspeedm, 0,1000);
	DDX_Text(pDX, IDC_EDIT6, m_unox_lspeedl);
	DDV_MinMaxInt(pDX, m_unox_lspeedl, 0,1000);
	DDX_Text(pDX, IDC_EDIT7, m_unoy_hspeedh);
	DDV_MinMaxInt(pDX, m_unoy_hspeedh, 0,1000);
	DDX_Text(pDX, IDC_EDIT8, m_unoy_hspeedm);
	DDV_MinMaxInt(pDX, m_unoy_hspeedm, 0,1000);
	DDX_Text(pDX, IDC_EDIT9, m_unoy_hspeedl);
	DDV_MinMaxInt(pDX, m_unoy_hspeedl, 0,1000);
	DDX_Text(pDX, IDC_EDIT10, m_unoy_lspeedh);
	DDV_MinMaxInt(pDX, m_unoy_lspeedh, 0,1000);
	DDX_Text(pDX, IDC_EDIT11, m_unoy_lspeedm);
	DDV_MinMaxInt(pDX, m_unoy_lspeedm, 0,1000);
	DDX_Text(pDX, IDC_EDIT12, m_unoy_lspeedl);
	DDV_MinMaxInt(pDX, m_unoy_lspeedl, 0,1000);

	DDX_Text(pDX, IDC_EDIT13, m_unoz_hspeedh);
	DDV_MinMaxInt(pDX, m_unoz_hspeedh, 0,1000);
	DDX_Text(pDX, IDC_EDIT14, m_unoz_hspeedm);
	DDV_MinMaxInt(pDX, m_unoz_hspeedm, 0,1000);
	DDX_Text(pDX, IDC_EDIT15, m_unoz_hspeedl);
	DDV_MinMaxInt(pDX, m_unoz_hspeedl, 0,1000);
	DDX_Text(pDX, IDC_EDIT16, m_unoz_lspeedh);
	DDV_MinMaxInt(pDX, m_unoz_lspeedh, 0,1000);
	DDX_Text(pDX, IDC_EDIT17, m_unoz_lspeedm);
	DDV_MinMaxInt(pDX, m_unoz_lspeedm, 0,1000);
	DDX_Text(pDX, IDC_EDIT18, m_unoz_lspeedl);
	DDV_MinMaxInt(pDX, m_unoz_lspeedl, 0,1000);

	DDX_Text(pDX, IDC_EDIT19, m_unok_hspeedh);
	DDV_MinMaxInt(pDX, m_unok_hspeedh, 0,1000);
	DDX_Text(pDX, IDC_EDIT20, m_unok_hspeedm);
	DDV_MinMaxInt(pDX, m_unok_hspeedm, 0,1000);
	DDX_Text(pDX, IDC_EDIT21, m_unok_hspeedl);
	DDV_MinMaxInt(pDX, m_unok_hspeedl, 0,1000);
	DDX_Text(pDX, IDC_EDIT22, m_unok_lspeedh);
	DDV_MinMaxInt(pDX, m_unok_lspeedh, 0,1000);
	DDX_Text(pDX, IDC_EDIT23, m_unok_lspeedm);
	DDV_MinMaxInt(pDX, m_unok_lspeedm, 0,1000);
	DDX_Text(pDX, IDC_EDIT24, m_unok_lspeedl);
	DDV_MinMaxInt(pDX, m_unok_lspeedl, 0,1000);
	DDX_Text(pDX, IDC_EDIT25, m_a_x_pos);
	DDX_Text(pDX, IDC_EDIT26, m_a_x_step);
	DDX_Text(pDX, IDC_EDIT27, m_a_y_pos);
	DDX_Text(pDX, IDC_EDIT28, m_a_y_step);
	DDX_Text(pDX, IDC_EDIT29, m_a_z_pos);
	DDX_Text(pDX, IDC_EDIT30, m_a_z_step);
	DDX_Text(pDX, IDC_EDIT31, m_a_k_pos);
	DDX_Text(pDX, IDC_EDIT32, m_a_k_step);
	DDX_Text(pDX, IDC_EDIT33, m_unol_hspeedh);
	DDX_Text(pDX, IDC_EDIT36, m_unol_lspeedh);
	DDX_Text(pDX, IDC_EDIT34, m_unol_hspeedm);
	DDX_Text(pDX, IDC_EDIT37, m_unol_lspeedm);
	DDX_Text(pDX, IDC_EDIT35, m_unol_hspeedl);
	DDX_Text(pDX, IDC_EDIT38, m_unol_lspeedl);
	DDX_Text(pDX, IDC_EDIT39, m_a_l_pos);
	DDX_Text(pDX, IDC_EDIT40, m_a_l_step);
}

BEGIN_MESSAGE_MAP(CUNITCHECKDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(IDC_COMBO1, &CUNITCHECKDlg::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CUNITCHECKDlg::OnCbnSelchangeCombo5)
	ON_CBN_SELCHANGE(IDC_COMBO9, &CUNITCHECKDlg::OnCbnSelchangeCombo9)
	ON_CBN_SELCHANGE(IDC_COMBO13, &CUNITCHECKDlg::OnCbnSelchangeCombo13)
	ON_BN_CLICKED(IDC_BUTTON4, &CUNITCHECKDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CUNITCHECKDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON12, &CUNITCHECKDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON16, &CUNITCHECKDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON1, &CUNITCHECKDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, &CUNITCHECKDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CUNITCHECKDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CUNITCHECKDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CUNITCHECKDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CUNITCHECKDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON9, &CUNITCHECKDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CUNITCHECKDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CUNITCHECKDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CUNITCHECKDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CUNITCHECKDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CUNITCHECKDlg::OnBnClickedButton15)
	ON_CBN_SELCHANGE(IDC_COMBO18, &CUNITCHECKDlg::OnCbnSelchangeCombo18)
	ON_BN_CLICKED(IDC_BUTTON17, &CUNITCHECKDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CUNITCHECKDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CUNITCHECKDlg::OnBnClickedButton19)
	ON_CBN_SELCHANGE(IDC_COMBO22, &CUNITCHECKDlg::OnCbnSelchangeCombo22)
	ON_CBN_SELCHANGE(IDC_COMBO21, &CUNITCHECKDlg::OnCbnSelchangeCombo21)
	ON_BN_CLICKED(IDC_BUTTON20, &CUNITCHECKDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CUNITCHECKDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CUNITCHECKDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CUNITCHECKDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CUNITCHECKDlg::OnBnClickedButton24)
	ON_CBN_SELCHANGE(IDC_COMBO23, &CUNITCHECKDlg::OnCbnSelchangeCombo23)
	ON_BN_CLICKED(IDC_BUTTON25, &CUNITCHECKDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CUNITCHECKDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CUNITCHECKDlg::OnBnClickedButton27)
	ON_CBN_SELCHANGE(IDC_COMBO24, &CUNITCHECKDlg::OnCbnSelchangeCombo24)
	ON_BN_CLICKED(IDC_BUTTON28, &CUNITCHECKDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON29, &CUNITCHECKDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &CUNITCHECKDlg::OnBnClickedButton30)
	ON_CBN_SELCHANGE(IDC_COMBO25, &CUNITCHECKDlg::OnCbnSelchangeCombo25)
	ON_BN_CLICKED(IDC_BUTTON31, &CUNITCHECKDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON32, &CUNITCHECKDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON33, &CUNITCHECKDlg::OnBnClickedButton33)
	//	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON34, &CUNITCHECKDlg::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON35, &CUNITCHECKDlg::OnBnClickedButton35)
	ON_BN_CLICKED(IDC_BUTTON39, &CUNITCHECKDlg::OnBnClickedButton39)
	ON_CBN_SELCHANGE(IDC_COMBO8, &CUNITCHECKDlg::OnCbnSelchangeCombo8)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CUNITCHECKDlg::OnCbnSelchangeCombo4)
	ON_EN_CHANGE(IDC_EDIT8, &CUNITCHECKDlg::OnEnChangeEdit8)
	ON_CBN_SELCHANGE(IDC_COMBO17, &CUNITCHECKDlg::OnCbnSelchangeCombo17)
	ON_CBN_SELCHANGE(IDC_COMBO19, &CUNITCHECKDlg::OnCbnSelchangeCombo19)
	ON_CBN_SELCHANGE(IDC_COMBO20, &CUNITCHECKDlg::OnCbnSelchangeCombo20)
	ON_CBN_SELCHANGE(IDC_COMBO27, &CUNITCHECKDlg::OnCbnSelchangeCombo27)
	ON_CBN_SELCHANGE(IDC_COMBO28, &CUNITCHECKDlg::OnCbnSelchangeCombo28)
	ON_CBN_SELCHANGE(IDC_COMBO26, &CUNITCHECKDlg::OnCbnSelchangeCombo26)
	ON_CBN_SELCHANGE(IDC_COMBO29, &CUNITCHECKDlg::OnCbnSelchangeCombo29)
	ON_CBN_SELCHANGE(IDC_COMBO14, &CUNITCHECKDlg::OnCbnSelchangeCombo14)
	ON_BN_CLICKED(IDC_BUTTON41, &CUNITCHECKDlg::OnBnClickedButton41)
	ON_BN_CLICKED(IDC_BUTTON42, &CUNITCHECKDlg::OnBnClickedButton42)
	ON_CBN_SELCHANGE(IDC_COMBO30, &CUNITCHECKDlg::OnCbnSelchangeCombo30)
	ON_BN_CLICKED(IDC_BUTTON43, &CUNITCHECKDlg::OnBnClickedButton43)
	ON_CBN_SELCHANGE(IDC_COMBO31, &CUNITCHECKDlg::OnCbnSelchangeCombo31)
	ON_BN_CLICKED(IDC_BUTTON44, &CUNITCHECKDlg::OnBnClickedButton44)
	ON_BN_CLICKED(IDC_BUTTON45, &CUNITCHECKDlg::OnBnClickedButton45)
	ON_BN_CLICKED(IDC_BUTTON46, &CUNITCHECKDlg::OnBnClickedButton46)
	ON_BN_CLICKED(IDC_BUTTON36, &CUNITCHECKDlg::OnBnClickedButton36)
END_MESSAGE_MAP()


// CUNITCHECKDlg 消息处理程序

BOOL CUNITCHECKDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标



	// TODO: 在此添加额外的初始化代码

	file.open("log.txt",ios::out|ios::trunc);
	CString temp;
	OnBnClickedButton32();
	((CComboBox *)GetDlgItem(IDC_COMBO1))->InsertString(-1,"有");
	((CComboBox *)GetDlgItem(IDC_COMBO1))->InsertString(-1,"无");
	((CComboBox *)GetDlgItem(IDC_COMBO1))->SetCurSel(0);

	((CComboBox *)GetDlgItem(IDC_COMBO5))->InsertString(-1,"有");
	((CComboBox *)GetDlgItem(IDC_COMBO5))->InsertString(-1,"无");
	((CComboBox *)GetDlgItem(IDC_COMBO5))->SetCurSel(0);

	((CComboBox *)GetDlgItem(IDC_COMBO9))->InsertString(-1,"有");
	((CComboBox *)GetDlgItem(IDC_COMBO9))->InsertString(-1,"无");
	((CComboBox *)GetDlgItem(IDC_COMBO9))->SetCurSel(0);

	((CComboBox *)GetDlgItem(IDC_COMBO13))->InsertString(-1,"有");
	((CComboBox *)GetDlgItem(IDC_COMBO13))->InsertString(-1,"无");
	((CComboBox *)GetDlgItem(IDC_COMBO13))->SetCurSel(0);

	((CComboBox *)GetDlgItem(IDC_COMBO26))->InsertString(-1,"有");
	((CComboBox *)GetDlgItem(IDC_COMBO26))->InsertString(-1,"无");
	((CComboBox *)GetDlgItem(IDC_COMBO26))->SetCurSel(0);

	((CComboBox *)GetDlgItem(IDC_COMBO17))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO17))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO17))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO17))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO18))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO18))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO18))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO18))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO19))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO19))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO19))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO19))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO20))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO20))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO20))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO20))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO22))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO22))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO22))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO22))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO23))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO23))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO23))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO23))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO24))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO24))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO24))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO24))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO25))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO25))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO25))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO25))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO25))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO25))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO25))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO25))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO30))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO30))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO30))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO30))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO31))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO31))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO31))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO31))->SetCurSel(2);
	int pinMax=17;
	for(int i=1;i<=15;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO21))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO2))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO3))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO4))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO6))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO7))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO8))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO10))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO11))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO12))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO14))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO15))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO16))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO27))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO28))->InsertString(-1,temp);
	}
	for(int i=0;i<=pinMax;i++)
	{
		temp.Format("%d",i);
		((CComboBox *)GetDlgItem(IDC_COMBO29))->InsertString(-1,temp);
	}
	hThread=CreateThread(NULL,0,chaneCheck,this,0,NULL);





	;  // 除非将焦点设置到控件，否则返回 TRUE
	return TRUE;
}
bool CUNITCHECKDlg::pincheck()
{
	UpdateData(true);
	bool checkres=true;
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");
		checkres=false;
	}
	int pinArray[18];
	for(int i=0;i<18;i++)
		pinArray[i]=0;
	int realPin[15];
	for(int i=0;i<15;i++)
		realPin[i]=-1;
	CString temp;
	((CComboBox *)GetDlgItem(IDC_COMBO1))->GetWindowTextA(temp);
	if(temp=="有")
	{
		realPin[0]=((CComboBox *)GetDlgItem(IDC_COMBO2))->GetCurSel();
		realPin[1]=((CComboBox *)GetDlgItem(IDC_COMBO3))->GetCurSel();
		realPin[2]=((CComboBox *)GetDlgItem(IDC_COMBO4))->GetCurSel();
		if(realPin[0]<0||realPin[1]<0||realPin[2]<0)
		{
			AfxMessageBox("UNO X轴还有引脚没选择");
			checkres=false;
		}
		if(!(m_unox_hspeedh && m_unox_hspeedm &&m_unox_hspeedl && m_unox_lspeedh&&m_unox_lspeedm&&m_unox_lspeedl))
		{
			AfxMessageBox("UNO X轴还有速度没有填");
			checkres=false;
		}

	}
	((CComboBox *)GetDlgItem(IDC_COMBO5))->GetWindowTextA(temp);
	if(temp=="有")
	{
		realPin[3]=((CComboBox *)GetDlgItem(IDC_COMBO6))->GetCurSel();
		realPin[4]=((CComboBox *)GetDlgItem(IDC_COMBO7))->GetCurSel();
		realPin[5]=((CComboBox *)GetDlgItem(IDC_COMBO8))->GetCurSel();
		if(realPin[3]<0||realPin[4]<0||realPin[5]<0)
		{
			AfxMessageBox("UNO Y轴还有引脚没选择");
			checkres=false;
		}
		if(!(m_unoy_hspeedh && m_unoy_hspeedm &&m_unoy_hspeedl && m_unoy_lspeedh&&m_unoy_lspeedm&&m_unoy_lspeedl))
		{
			AfxMessageBox("UNO Y轴还有速度没有填");
			checkres=false;
		}
	}
	((CComboBox *)GetDlgItem(IDC_COMBO9))->GetWindowTextA(temp);
	if(temp=="有")
	{
		realPin[6]=((CComboBox *)GetDlgItem(IDC_COMBO10))->GetCurSel();
		realPin[7]=((CComboBox *)GetDlgItem(IDC_COMBO11))->GetCurSel();
		realPin[8]=((CComboBox *)GetDlgItem(IDC_COMBO12))->GetCurSel();
		if(realPin[6]<0||realPin[7]<0||realPin[8]<0)
		{
			AfxMessageBox("UNO Z轴还有引脚没选择");
			checkres=false;
		}
		if(!(m_unoz_hspeedh && m_unoz_hspeedm &&m_unoz_hspeedl && m_unoz_lspeedh&&m_unoz_lspeedm&&m_unoz_lspeedl))
		{
			AfxMessageBox("UNO Z轴还有速度没有填");
			checkres=false;
		}
	}
	((CComboBox *)GetDlgItem(IDC_COMBO13))->GetWindowTextA(temp);
	if(temp=="有")
	{
		realPin[9]=((CComboBox *)GetDlgItem(IDC_COMBO14))->GetCurSel();
		realPin[10]=((CComboBox *)GetDlgItem(IDC_COMBO15))->GetCurSel();
		realPin[11]=((CComboBox *)GetDlgItem(IDC_COMBO16))->GetCurSel();
		if(realPin[9]<0||realPin[10]<0||realPin[11]<0)
		{
			AfxMessageBox("UNO K轴还有引脚没选择");
			checkres=false;
		}
		if(!(m_unok_hspeedh && m_unok_hspeedm &&m_unok_hspeedl && m_unok_lspeedh&&m_unok_lspeedm&&m_unok_lspeedl))
		{
			AfxMessageBox("UNO K轴还有速度没有填");
			checkres=false;
		}
	}
	((CComboBox *)GetDlgItem(IDC_COMBO26))->GetWindowTextA(temp);
	if(temp=="有")
	{
		realPin[12]=((CComboBox *)GetDlgItem(IDC_COMBO27))->GetCurSel();
		realPin[13]=((CComboBox *)GetDlgItem(IDC_COMBO28))->GetCurSel();
		realPin[14]=((CComboBox *)GetDlgItem(IDC_COMBO29))->GetCurSel();
		if(realPin[12]<0||realPin[13]<0||realPin[14]<0)
		{
			AfxMessageBox("UNO L轴还有引脚没选择");
			checkres=false;
		}
		if(!(m_unok_hspeedh && m_unok_hspeedm &&m_unok_hspeedl && m_unok_lspeedh&&m_unok_lspeedm&&m_unok_lspeedl))
		{
			AfxMessageBox("UNO L轴还有速度没有填");
			checkres=false;
		}
	}
	for(int i=0;i<12;i++)
	{
		if(realPin[i]>=0)
			pinArray[realPin[i]]++;
	}
	for(int i=0;i<14;i++)
	{
		if(pinArray[i]>1)
		{
			temp.Format("错误，引脚%d有%d个",i,pinArray[i]);
			AfxMessageBox(temp);
			checkres=false;

		}
	}


	return checkres;

}
void CUNITCHECKDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CUNITCHECKDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CUNITCHECKDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CUNITCHECKDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	m_unox_exist=((CComboBox *)GetDlgItem(IDC_COMBO1))->GetCurSel();
	CString temp;
	temp.Format(_T("%d"),m_unox_exist);
	::WritePrivateProfileString(_T("UNO"),_T("m_unox_exist"),temp,ini_filepath);
	if(m_unox_exist==1)
	{
		((CComboBox *)GetDlgItem(IDC_COMBO2))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO3))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO4))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO17))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT1))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT2))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT3))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT4))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT5))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT6))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON1))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON2))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON3))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON4))->EnableWindow(false);

		((CComboBox *)GetDlgItem(IDC_COMBO22))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT25))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT26))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON20))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON21))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON22))->EnableWindow(false);




	}
	else
	{
		((CComboBox *)GetDlgItem(IDC_COMBO2))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO3))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO4))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO17))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT1))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT2))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT3))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT4))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT5))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT6))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON1))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON2))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON3))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON4))->EnableWindow(true);

		((CComboBox *)GetDlgItem(IDC_COMBO22))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT25))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT26))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON20))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON21))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON22))->EnableWindow(true);
	}



}

void CUNITCHECKDlg::OnCbnSelchangeCombo5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_unoy_exist=((CComboBox *)GetDlgItem(IDC_COMBO5))->GetCurSel();
	CString temp;
	temp.Format(_T("%d"),m_unoy_exist);
	::WritePrivateProfileString(_T("UNO"),_T("m_unoy_exist"),temp,ini_filepath);
	if(((CComboBox *)GetDlgItem(IDC_COMBO5))->GetCurSel()==1)
	{
		((CComboBox *)GetDlgItem(IDC_COMBO6))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO7))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO8))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO18))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT7))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT8))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT9))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT10))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT11))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT12))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON5))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON6))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON7))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON8))->EnableWindow(false);

		((CComboBox *)GetDlgItem(IDC_COMBO23))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT27))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT28))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON23))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON24))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON25))->EnableWindow(false);



	}
	else
	{
		((CComboBox *)GetDlgItem(IDC_COMBO6))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO7))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO8))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO18))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT7))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT18))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT8))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT9))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT10))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT11))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT12))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON5))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON6))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON7))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON8))->EnableWindow(true);

		((CComboBox *)GetDlgItem(IDC_COMBO23))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT27))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT28))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON23))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON24))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON25))->EnableWindow(true);
	}
}

void CUNITCHECKDlg::OnCbnSelchangeCombo9()
{
	// TODO: 在此添加控件通知处理程序代码
	m_unoz_exist=((CComboBox *)GetDlgItem(IDC_COMBO9))->GetCurSel();
	CString temp;
	temp.Format(_T("%d"),m_unoz_exist);
	::WritePrivateProfileString(_T("UNO"),_T("m_unoz_exist"),temp,ini_filepath);
	if(((CComboBox *)GetDlgItem(IDC_COMBO9))->GetCurSel()==1)
	{
		((CComboBox *)GetDlgItem(IDC_COMBO10))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO11))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO12))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO19))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT13))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT14))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT15))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT16))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT17))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT18))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON9))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON10))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON11))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON12))->EnableWindow(false);

		((CComboBox *)GetDlgItem(IDC_COMBO24))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT29))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT30))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON26))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON27))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON28))->EnableWindow(false);



	}
	else
	{
		((CComboBox *)GetDlgItem(IDC_COMBO10))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO11))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO12))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO19))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT13))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT14))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT15))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT16))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT17))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT18))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON9))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON10))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON11))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON12))->EnableWindow(true);

		((CComboBox *)GetDlgItem(IDC_COMBO24))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT29))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT30))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON26))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON27))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON28))->EnableWindow(true);
	}
}

void CUNITCHECKDlg::OnCbnSelchangeCombo13()
{
	// TODO: 在此添加控件通知处理程序代码
	m_unok_exist=((CComboBox *)GetDlgItem(IDC_COMBO13))->GetCurSel();
	CString temp;
	temp.Format(_T("%d"),m_unok_exist);
	::WritePrivateProfileString(_T("UNO"),_T("m_unok_exist"),temp,ini_filepath);
	if(((CComboBox *)GetDlgItem(IDC_COMBO13))->GetCurSel()==1)
	{
		((CComboBox *)GetDlgItem(IDC_COMBO14))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO15))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO16))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO20))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT19))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT20))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT21))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT22))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT23))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT24))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON13))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON14))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON15))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON16))->EnableWindow(false);

		((CComboBox *)GetDlgItem(IDC_COMBO25))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT31))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT32))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON29))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON30))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON31))->EnableWindow(false);



	}
	else
	{
		((CComboBox *)GetDlgItem(IDC_COMBO14))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO15))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO16))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO20))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT19))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT20))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT20))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT21))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT22))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT23))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT24))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON13))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON14))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON15))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON16))->EnableWindow(true);

		((CComboBox *)GetDlgItem(IDC_COMBO25))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT31))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT32))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON29))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON30))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON31))->EnableWindow(true);
	}
}

void CUNITCHECKDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	UpdateData(true);
	CString temp;
	((CComboBox *)GetDlgItem(IDC_COMBO17))->GetWindowText(temp);

	if(!m_unox_hspeedh ||!m_unox_hspeedm ||!m_unox_hspeedl||!m_unox_lspeedh||!m_unox_lspeedm||!m_unox_lspeedl||temp=="")
	{
		AfxMessageBox("当前有选项为空，请先选择");
		return ;

	}
	else
	{

		temp.Format("{r%d:121=%d;}",uno_id,m_unox_hspeedh);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:122=%d;}",uno_id,m_unox_hspeedm);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:123=%d;}",uno_id,m_unox_hspeedl);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:124=%d;}",uno_id,m_unox_lspeedh);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:125=%d;}",uno_id,m_unox_lspeedm);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:126=%d;}",uno_id,m_unox_lspeedl);
		theApp.transfer.SendCmd(temp);
		Sleep(100);

		m_unox_speedmode =((CComboBox *)GetDlgItem(IDC_COMBO17))->GetCurSel();
		temp.Format("{r%d:117=%d;}",uno_id,m_unox_speedmode);
		theApp.transfer.SendCmd(temp);
		Sleep(100);

		temp.Format("{r%d:54=%d;}",uno_id,m_unox_speedmode);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format(_T("%d"),m_unox_speedmode);::WritePrivateProfileString(_T("UNO"),_T("m_unox_speedmode"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unox_hspeedh);::WritePrivateProfileString(_T("UNO"),_T("m_unox_hspeedh"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unox_hspeedm);::WritePrivateProfileString(_T("UNO"),_T("m_unox_hspeedm"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unox_hspeedl);::WritePrivateProfileString(_T("UNO"),_T("m_unox_hspeedl"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unox_lspeedl);::WritePrivateProfileString(_T("UNO"),_T("m_unox_lspeedl"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unox_lspeedm);::WritePrivateProfileString(_T("UNO"),_T("m_unox_lspeedm"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unox_lspeedh);::WritePrivateProfileString(_T("UNO"),_T("m_unox_lspeedh"),temp,ini_filepath);Sleep(100);
	}

}

void   CUNITCHECKDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码

	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	UpdateData(true);
	CString temp;
	((CComboBox *)GetDlgItem(IDC_COMBO18))->GetWindowText(temp);

	if(!m_unoy_hspeedh ||!m_unoy_hspeedm ||!m_unoy_hspeedl||!m_unoy_lspeedh||!m_unoy_lspeedm||!m_unoy_lspeedl||temp=="")
	{
		AfxMessageBox("当前有选项为空，请先选择");
		return ;

	}
	else
	{
		temp.Format("{r%d:127=%d;}",uno_id,m_unoy_hspeedh);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:128=%d;}",uno_id,m_unoy_hspeedm);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:129=%d;}",uno_id,m_unoy_hspeedl);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:130=%d;}",uno_id,m_unoy_lspeedh);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:131=%d;}",uno_id,m_unoy_lspeedm);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:132=%d;}",uno_id,m_unoy_lspeedl);
		theApp.transfer.SendCmd(temp);
		Sleep(100);

		m_unoy_speedmode=((CComboBox *)GetDlgItem(IDC_COMBO18))->GetCurSel();
		temp.Format("{r%d:118=%d;}",uno_id,m_unoy_speedmode);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:55=%d;}",uno_id,m_unoy_speedmode);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format(_T("%d"),m_unoy_speedmode);::WritePrivateProfileString(_T("UNO"),_T("m_unoy_speedmode"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoy_hspeedh);::WritePrivateProfileString(_T("UNO"),_T("m_unoy_hspeedh"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoy_hspeedm);::WritePrivateProfileString(_T("UNO"),_T("m_unoy_hspeedm"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoy_hspeedl);::WritePrivateProfileString(_T("UNO"),_T("m_unoy_hspeedl"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoy_lspeedl);::WritePrivateProfileString(_T("UNO"),_T("m_unoy_lspeedl"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoy_lspeedm);::WritePrivateProfileString(_T("UNO"),_T("m_unoy_lspeedm"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoy_lspeedh);::WritePrivateProfileString(_T("UNO"),_T("m_unoy_lspeedh"),temp,ini_filepath);Sleep(100);


	}


}

void   CUNITCHECKDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	UpdateData(true);
	CString temp;
	((CComboBox *)GetDlgItem(IDC_COMBO19))->GetWindowText(temp);
	if(!m_unoz_hspeedh ||!m_unoz_hspeedm ||!m_unoz_hspeedl||!m_unoz_lspeedh||!m_unoz_lspeedm||!m_unoz_lspeedl||temp=="")
	{
		AfxMessageBox("当前有选项为空，请先选择");
		return ;

	}
	else
	{

		temp.Format("{r%d:133=%d;}",uno_id,m_unoz_hspeedh);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:134=%d;}",uno_id,m_unoz_hspeedm);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:135=%d;}",uno_id,m_unoz_hspeedl);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:136=%d;}",uno_id,m_unoz_lspeedh);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:137=%d;}",uno_id,m_unoz_lspeedm);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:138=%d;}",uno_id,m_unoz_lspeedl);
		theApp.transfer.SendCmd(temp);
		Sleep(100);

		m_unoz_speedmode=((CComboBox *)GetDlgItem(IDC_COMBO19))->GetCurSel();
		temp.Format("{r%d:119=%d;}",uno_id,m_unoz_speedmode);
		theApp.transfer.SendCmd(temp);
		Sleep(100);

		temp.Format("{r%d:56=%d;}",uno_id,m_unoz_speedmode);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format(_T("%d"),m_unoz_speedmode);::WritePrivateProfileString(_T("UNO"),_T("m_unoz_speedmode"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoz_hspeedh);::WritePrivateProfileString(_T("UNO"),_T("m_unoz_hspeedh"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoz_hspeedm);::WritePrivateProfileString(_T("UNO"),_T("m_unoz_hspeedm"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoz_hspeedl);::WritePrivateProfileString(_T("UNO"),_T("m_unoz_hspeedl"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoz_lspeedl);::WritePrivateProfileString(_T("UNO"),_T("m_unoz_lspeedl"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoz_lspeedm);::WritePrivateProfileString(_T("UNO"),_T("m_unoz_lspeedm"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unoz_lspeedh);::WritePrivateProfileString(_T("UNO"),_T("m_unoz_lspeedh"),temp,ini_filepath);Sleep(100);


	}
}

void   CUNITCHECKDlg::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	UpdateData(true);
	CString temp;
	((CComboBox *)GetDlgItem(IDC_COMBO20))->GetWindowText(temp);

	if(!m_unok_hspeedh ||!m_unok_hspeedm ||!m_unok_hspeedl||!m_unok_lspeedh||!m_unok_lspeedm||!m_unok_lspeedl||temp=="")
	{
		AfxMessageBox("当前有选项为空，请先选择");
		return ;

	}
	else
	{

		temp.Format("{r%d:139=%d;}",uno_id,m_unok_hspeedh);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:140=%d;}",uno_id,m_unok_hspeedm);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:141=%d;}",uno_id,m_unok_hspeedl);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:142=%d;}",uno_id,m_unok_lspeedh);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:143=%d;}",uno_id,m_unok_lspeedm);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:144=%d;}",uno_id,m_unok_lspeedl);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		m_unok_speedmode=((CComboBox *)GetDlgItem(IDC_COMBO20))->GetCurSel();
		temp.Format("{r%d:120=%d;}",uno_id,m_unok_speedmode);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:57=%d;}",uno_id,m_unok_speedmode);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format(_T("%d"),m_unok_speedmode);::WritePrivateProfileString(_T("UNO"),_T("m_unok_speedmode"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unok_hspeedh);::WritePrivateProfileString(_T("UNO"),_T("m_unok_hspeedh"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unok_hspeedm);::WritePrivateProfileString(_T("UNO"),_T("m_unok_hspeedm"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unok_hspeedl);::WritePrivateProfileString(_T("UNO"),_T("m_unok_hspeedl"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unok_lspeedl);::WritePrivateProfileString(_T("UNO"),_T("m_unok_lspeedl"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unok_lspeedm);::WritePrivateProfileString(_T("UNO"),_T("m_unok_lspeedm"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unok_lspeedh);::WritePrivateProfileString(_T("UNO"),_T("m_unok_lspeedh"),temp,ini_filepath);Sleep(100);
	}
}

void   CUNITCHECKDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unox_pinmc=((CComboBox *)GetDlgItem(IDC_COMBO2))->GetCurSel();


	if(m_unox_pinmc==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:102=%d;}",uno_id,m_unox_pinmc);
		theApp.transfer.SendCmd(temp);
		temp.Format(_T("%d"),m_unox_pinmc);
		::WritePrivateProfileString(_T("UNO"),_T("m_unox_pinmc"),temp,ini_filepath);
		;
	}


}

void CUNITCHECKDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	endflag=true;
	Sleep(500);
	file.close();
	CDialog::OnClose();
}

void   CUNITCHECKDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unox_pinfx=((CComboBox *)GetDlgItem(IDC_COMBO3))->GetCurSel();
	if(m_unox_pinfx==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:103=%d;}",uno_id,m_unox_pinfx);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unox_pinfx);
		::WritePrivateProfileString(_T("UNO"),_T("m_unox_pinfx"),temp,ini_filepath);

	}
}

void   CUNITCHECKDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unox_pinzero=((CComboBox *)GetDlgItem(IDC_COMBO4))->GetCurSel();


	if(m_unox_pinzero==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:104=%d;}",uno_id,m_unox_pinzero);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unox_pinzero);
		::WritePrivateProfileString(_T("UNO"),_T("m_unox_pinzero"),temp,ini_filepath);
		;
	}
}

void CUNITCHECKDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unoy_pinmc=((CComboBox *)GetDlgItem(IDC_COMBO6))->GetCurSel();
	if(m_unoy_pinmc==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:106=%d;}",uno_id,m_unoy_pinmc);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unoy_pinmc);
		::WritePrivateProfileString(_T("UNO"),_T("m_unoy_pinmc"),temp,ini_filepath);
	}

}

void   CUNITCHECKDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unoy_pinfx=((CComboBox *)GetDlgItem(IDC_COMBO7))->GetCurSel();
	if(m_unoy_pinfx==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:107=%d;}",uno_id,m_unoy_pinfx);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unoy_pinfx);
		::WritePrivateProfileString(_T("UNO"),_T("m_unoy_pinfx"),temp,ini_filepath);

		;
	}
}

void   CUNITCHECKDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unoy_pinzero=((CComboBox *)GetDlgItem(IDC_COMBO8))->GetCurSel();
	if(m_unoy_pinzero==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:108=%d;}",uno_id,m_unoy_pinzero);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unoy_pinzero);
		::WritePrivateProfileString(_T("UNO"),_T("m_unoy_pinzero"),temp,ini_filepath);

		;
	}
}

void   CUNITCHECKDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unoz_pinmc=((CComboBox *)GetDlgItem(IDC_COMBO10))->GetCurSel();
	if(m_unoz_pinmc==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:110=%d;}",uno_id,m_unoz_pinmc);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unoz_pinmc);
		::WritePrivateProfileString(_T("UNO"),_T("m_unoz_pinmc"),temp,ini_filepath);

		;
	}
}

void   CUNITCHECKDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unoz_pinfx=((CComboBox *)GetDlgItem(IDC_COMBO11))->GetCurSel();
	if(m_unoz_pinfx==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:111=%d;}",uno_id,m_unoz_pinfx);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unoz_pinfx);
		::WritePrivateProfileString(_T("UNO"),_T("m_unoz_pinfx"),temp,ini_filepath);
		;
	}
}

void   CUNITCHECKDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unoz_pinzero=((CComboBox *)GetDlgItem(IDC_COMBO12))->GetCurSel();
	if(m_unoz_pinzero==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:112=%d;}",uno_id,m_unoz_pinzero);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unoz_pinzero);
		::WritePrivateProfileString(_T("UNO"),_T("m_unoz_pinzero"),temp,ini_filepath);
		;
	}
}

void   CUNITCHECKDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unok_pinmc=((CComboBox *)GetDlgItem(IDC_COMBO14))->GetCurSel();
	if(m_unok_pinmc==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:114=%d;}",uno_id,m_unok_pinmc);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unok_pinmc);
		::WritePrivateProfileString(_T("UNO"),_T("m_unok_pinmc"),temp,ini_filepath);
		;
	}
}

void CUNITCHECKDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unok_pinfx=((CComboBox *)GetDlgItem(IDC_COMBO15))->GetCurSel();
	if(m_unok_pinfx==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:115=%d;}",uno_id,m_unok_pinfx);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unok_pinfx);
		::WritePrivateProfileString(_T("UNO"),_T("m_unok_pinfx"),temp,ini_filepath);

		;
	}
}

void CUNITCHECKDlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unok_pinzero=((CComboBox *)GetDlgItem(IDC_COMBO16))->GetCurSel();
	if(m_unok_pinzero==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:116=%d;}",uno_id,m_unok_pinzero);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unok_pinzero);
		::WritePrivateProfileString(_T("UNO"),_T("m_unok_pinzero"),temp,ini_filepath);
		;
	}
}



void CUNITCHECKDlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!(pincheck()))
	{
		return;
	}
	CString temp;
	int mode=0;
	((CComboBox *)GetDlgItem(IDC_COMBO1))->GetWindowTextA(temp);
	if(temp=="有")
		mode=1;
	temp.Format("{r%d:101=%d;}",uno_id,mode);
	theApp.transfer.SendCmd(temp);
	mode=0;
	((CComboBox *)GetDlgItem(IDC_COMBO5))->GetWindowTextA(temp);
	if(temp=="有")
		mode=1;
	temp.Format("{r%d:105=%d;}",uno_id,mode);
	theApp.transfer.SendCmd(temp);

	mode=0;
	((CComboBox *)GetDlgItem(IDC_COMBO9))->GetWindowTextA(temp);
	if(temp=="有")
		mode=1;
	temp.Format("{r%d:109=%d;}",uno_id,mode);
	theApp.transfer.SendCmd(temp);

	mode=0;
	((CComboBox *)GetDlgItem(IDC_COMBO13))->GetWindowTextA(temp);
	if(temp=="有")
		mode=1;
	temp.Format("{r%d:113=%d;}",uno_id,mode);
	theApp.transfer.SendCmd(temp);

	mode=0;
	((CComboBox *)GetDlgItem(IDC_COMBO26))->GetWindowTextA(temp);
	if(temp=="有")
		mode=1;
	temp.Format("{r%d:151=%d;}",uno_id,mode);
	theApp.transfer.SendCmd(temp);

	temp.Format("{r%d:100=%d;}",uno_id,uno_id);
	theApp.transfer.SendCmd(temp);
	temp.Format(_T("%d"),uno_id);
	::WritePrivateProfileString(_T("UNO"),_T("uno_id"),temp,ini_filepath);

}

void CUNITCHECKDlg::OnBnClickedButton18()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!(pincheck()))
	{
		return;
	}
	CString temp;
	((CComboBox *)GetDlgItem(IDC_COMBO1))->GetWindowTextA(temp);
	if(temp=="有")
	{
		OnBnClickedButton1();
		Sleep(100);
		OnBnClickedButton2();
		Sleep(100);
		OnBnClickedButton3();
		Sleep(100);
		OnBnClickedButton4();
		Sleep(100);
	}
	else
	{


	}
	((CComboBox *)GetDlgItem(IDC_COMBO5))->GetWindowTextA(temp);
	if(temp=="有")
	{
		OnBnClickedButton5();
		Sleep(100);
		OnBnClickedButton6();
		Sleep(100);
		OnBnClickedButton7();
		Sleep(100);
		OnBnClickedButton8();
		Sleep(100);
	}
	((CComboBox *)GetDlgItem(IDC_COMBO9))->GetWindowTextA(temp);
	if(temp=="有")
	{
		OnBnClickedButton9();
		Sleep(100);
		OnBnClickedButton10();
		Sleep(100);
		OnBnClickedButton11();
		Sleep(100);
		OnBnClickedButton12();
		Sleep(100);
	}
	((CComboBox *)GetDlgItem(IDC_COMBO13))->GetWindowTextA(temp);
	if(temp=="有")
	{
		OnBnClickedButton13();
		Sleep(100);
		OnBnClickedButton14();
		Sleep(100);
		OnBnClickedButton15();
		Sleep(100);
		OnBnClickedButton16();
		Sleep(100);
	}
	((CComboBox *)GetDlgItem(IDC_COMBO26))->GetWindowTextA(temp);
	if(temp=="有")
	{
		OnBnClickedButton39();
		Sleep(100);
		OnBnClickedButton41();
		Sleep(100);
		OnBnClickedButton42();
		Sleep(100);
		OnBnClickedButton43();
		Sleep(100);
	}
	MessageBox("下载完成");

}

void CUNITCHECKDlg::OnBnClickedButton19()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	uno_id=::GetPrivateProfileInt(_T("UNO"),_T("uno_id"),0,ini_filepath);;
	m_unox_exist=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_exist"),0,ini_filepath);;
	m_unox_pinmc=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_pinmc"),0,ini_filepath);;
	m_unox_pinfx=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_pinfx"),0,ini_filepath);;
	m_unox_pinzero=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_pinzero"),0,ini_filepath);;
	m_unox_speedmode=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_speedmode"),0,ini_filepath);;
	((CComboBox *)GetDlgItem(IDC_COMBO1))->SetCurSel(m_unox_exist);
	((CComboBox *)GetDlgItem(IDC_COMBO2))->SetCurSel(m_unox_pinmc);
	((CComboBox *)GetDlgItem(IDC_COMBO3))->SetCurSel(m_unox_pinfx);
	((CComboBox *)GetDlgItem(IDC_COMBO4))->SetCurSel(m_unox_pinzero);
	((CComboBox *)GetDlgItem(IDC_COMBO17))->SetCurSel(m_unox_speedmode);

	m_unoy_exist=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_exist"),0,ini_filepath);;
	m_unoy_pinmc=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_pinmc"),0,ini_filepath);;
	m_unoy_pinfx=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_pinfx"),0,ini_filepath);;
	m_unoy_pinzero=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_pinzero"),0,ini_filepath);;
	m_unoy_speedmode=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_speedmode"),0,ini_filepath);;
	((CComboBox *)GetDlgItem(IDC_COMBO5))->SetCurSel(m_unoy_exist);
	((CComboBox *)GetDlgItem(IDC_COMBO6))->SetCurSel(m_unoy_pinmc);
	((CComboBox *)GetDlgItem(IDC_COMBO7))->SetCurSel(m_unoy_pinfx);
	((CComboBox *)GetDlgItem(IDC_COMBO8))->SetCurSel(m_unoy_pinzero);
	((CComboBox *)GetDlgItem(IDC_COMBO18))->SetCurSel(m_unoy_speedmode);
	m_unoz_exist=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_exist"),0,ini_filepath);;
	m_unoz_pinmc=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_pinmc"),0,ini_filepath);;
	m_unoz_pinfx=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_pinfx"),0,ini_filepath);;
	m_unoz_pinzero=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_pinzero"),0,ini_filepath);;
	m_unoz_speedmode=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_speedmode"),0,ini_filepath);;
	((CComboBox *)GetDlgItem(IDC_COMBO9))->SetCurSel(m_unoz_exist);
	((CComboBox *)GetDlgItem(IDC_COMBO10))->SetCurSel(m_unoz_pinmc);
	((CComboBox *)GetDlgItem(IDC_COMBO11))->SetCurSel(m_unoz_pinfx);
	((CComboBox *)GetDlgItem(IDC_COMBO12))->SetCurSel(m_unoz_pinzero);
	((CComboBox *)GetDlgItem(IDC_COMBO19))->SetCurSel(m_unoz_speedmode);
	m_unok_exist=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_exist"),0,ini_filepath);;
	m_unok_pinmc=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_pinmc"),0,ini_filepath);;
	m_unok_pinfx=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_pinfx"),0,ini_filepath);;
	m_unok_pinzero=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_pinzero"),0,ini_filepath);;
	m_unok_speedmode=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_speedmode"),0,ini_filepath);;
	((CComboBox *)GetDlgItem(IDC_COMBO13))->SetCurSel(m_unok_exist);
	((CComboBox *)GetDlgItem(IDC_COMBO14))->SetCurSel(m_unok_pinmc);
	((CComboBox *)GetDlgItem(IDC_COMBO15))->SetCurSel(m_unok_pinfx);
	((CComboBox *)GetDlgItem(IDC_COMBO16))->SetCurSel(m_unok_pinzero);
	((CComboBox *)GetDlgItem(IDC_COMBO20))->SetCurSel(m_unok_speedmode);
	m_unol_exist=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_exist"),0,ini_filepath);;
	m_unol_pinmc=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_pinmc"),0,ini_filepath);;
	m_unol_pinfx=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_pinfx"),0,ini_filepath);;
	m_unol_pinzero=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_pinzero"),0,ini_filepath);;
	m_unol_speedmode=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_speedmode"),0,ini_filepath);;
	((CComboBox *)GetDlgItem(IDC_COMBO26))->SetCurSel(m_unol_exist);
	((CComboBox *)GetDlgItem(IDC_COMBO27))->SetCurSel(m_unol_pinmc);
	((CComboBox *)GetDlgItem(IDC_COMBO28))->SetCurSel(m_unol_pinfx);
	((CComboBox *)GetDlgItem(IDC_COMBO29))->SetCurSel(m_unol_pinzero);
	((CComboBox *)GetDlgItem(IDC_COMBO30))->SetCurSel(m_unol_speedmode);
	m_unox_hspeedh=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_hspeedh"),0,ini_filepath);;
	m_unox_hspeedm=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_hspeedm"),0,ini_filepath);;
	m_unox_hspeedl=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_hspeedl"),0,ini_filepath);;
	m_unox_lspeedl=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_lspeedl"),0,ini_filepath);;
	m_unox_lspeedm=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_lspeedm"),0,ini_filepath);;
	m_unox_lspeedh=::GetPrivateProfileInt(_T("UNO"),_T("m_unox_lspeedh"),0,ini_filepath);;
	m_unoy_hspeedh=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_hspeedh"),0,ini_filepath);;
	m_unoy_hspeedm=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_hspeedm"),0,ini_filepath);;
	m_unoy_hspeedl=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_hspeedl"),0,ini_filepath);;
	m_unoy_lspeedl=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_lspeedl"),0,ini_filepath);;
	m_unoy_lspeedm=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_lspeedm"),0,ini_filepath);;
	m_unoy_lspeedh=::GetPrivateProfileInt(_T("UNO"),_T("m_unoy_lspeedh"),0,ini_filepath);;
	m_unoz_hspeedh=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_hspeedh"),0,ini_filepath);;
	m_unoz_hspeedm=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_hspeedm"),0,ini_filepath);;
	m_unoz_hspeedl=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_hspeedl"),0,ini_filepath);;
	m_unoz_lspeedl=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_lspeedl"),0,ini_filepath);;
	m_unoz_lspeedm=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_lspeedm"),0,ini_filepath);;
	m_unoz_lspeedh=::GetPrivateProfileInt(_T("UNO"),_T("m_unoz_lspeedh"),0,ini_filepath);;
	m_unok_hspeedh=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_hspeedh"),0,ini_filepath);;
	m_unok_hspeedm=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_hspeedm"),0,ini_filepath);;
	m_unok_hspeedl=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_hspeedl"),0,ini_filepath);;
	m_unok_lspeedl=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_lspeedl"),0,ini_filepath);;
	m_unok_lspeedm=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_lspeedm"),0,ini_filepath);;
	m_unok_lspeedh=::GetPrivateProfileInt(_T("UNO"),_T("m_unok_lspeedh"),0,ini_filepath);;
	m_unol_hspeedh=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_hspeedh"),0,ini_filepath);;
	m_unol_hspeedm=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_hspeedm"),0,ini_filepath);;
	m_unol_hspeedl=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_hspeedl"),0,ini_filepath);;
	m_unol_lspeedl=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_lspeedl"),0,ini_filepath);;
	m_unol_lspeedm=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_lspeedm"),0,ini_filepath);;
	m_unol_lspeedh=::GetPrivateProfileInt(_T("UNO"),_T("m_unol_lspeedh"),0,ini_filepath);;


	UpdateData(false);
	Invalidate();
	OnCbnSelchangeCombo1();
	OnCbnSelchangeCombo5();
	OnCbnSelchangeCombo9();
	OnCbnSelchangeCombo13();
	OnCbnSelchangeCombo26();

	MessageBox("上传完成");



}



void CUNITCHECKDlg::OnCbnSelchangeCombo21()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	uno_id=((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()+1;
	ini_filepath.Format(_T(".\\ini\\UNO_%d.ini"),uno_id);

	CFileFind find;
	if(!find.FindFile(".\\ini"))
	{
		::CreateDirectory(".\\ini",NULL);
	}
	if(!find.FindFile(ini_filepath))
	{
		if(MessageBox(ini_filepath+"不存在,是否新建？","是否新建",MB_YESNO)==IDYES)
		{
			fstream tempfile;
			tempfile.open(ini_filepath,ios::out);
			tempfile.close();
			AfxMessageBox(ini_filepath+"已创建");
			temp.Format(_T("%d"),uno_id);
			::WritePrivateProfileString(_T("UNO"),_T("uno_id"),temp,ini_filepath);



		}
		else
		{
			AfxMessageBox(ini_filepath+"未创建，请将配置文件放在ini文件夹中");


		}
	}
	else
	{
		temp.Format(_T("%d"),uno_id);
		::WritePrivateProfileString(_T("UNO"),_T("uno_id"),temp,ini_filepath);
		OnBnClickedButton19();
	}

}
void CUNITCHECKDlg::OnCbnSelchangeCombo22()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	int idx=((CComboBox *)GetDlgItem(IDC_COMBO22))->GetCurSel();
	sendCmd(uno_id,54,idx);




}

void CUNITCHECKDlg::sendCmd(int chipnum,int cmd,long val)
{

	theApp.transfer.SendCmd(chipnum,cmd,val);


}
void CUNITCHECKDlg::OnBnClickedButton20()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	UpdateData(true);
	if(m_a_x_step>0)
	{
	sendCmd(uno_id,50,1);
	sendCmd(uno_id,2,m_a_x_step);

	}
	else
	{
	sendCmd(uno_id,50,0);
	sendCmd(uno_id,2,-m_a_x_step);
	}
	
	m_a_x_pos+=m_a_x_step;
	if(m_a_x_pos<0)
	{
		m_a_x_pos=0;
	}
	UpdateData(false);



}

void CUNITCHECKDlg::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	UpdateData(true);
	if(m_a_x_step>0)
	{
		sendCmd(uno_id,3,m_a_x_step);

	}
	m_a_x_pos=m_a_x_step;

	UpdateData(false);
	//theApp.transfer.DelayFinish(uno_id,20000);
	//AfxMessageBox("DelayFinish OK");

}

void CUNITCHECKDlg::OnBnClickedButton22()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	theApp.transfer.SendCmd(uno_id,1,1);
	m_a_x_pos=0;
	UpdateData(false);

	



}

void CUNITCHECKDlg::OnBnClickedButton23()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	UpdateData(true);
	if(m_a_y_step>0)
	{
		sendCmd(uno_id,51,1);
		sendCmd(uno_id,5,m_a_y_step);

	}
	else
	{
		sendCmd(uno_id,51,0);
		sendCmd(uno_id,5,-m_a_y_step);

	}
	m_a_y_pos+=m_a_y_step;
	if(m_a_y_pos<0)
	{
		m_a_y_pos=0;
	}
	UpdateData(false);
}

void CUNITCHECKDlg::OnBnClickedButton24()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	UpdateData(true);
	if(m_a_y_step>0)
	{
		sendCmd(uno_id,6,m_a_y_step);

	}
	m_a_y_pos=m_a_y_step;

	UpdateData(false);
}

void CUNITCHECKDlg::OnCbnSelchangeCombo23()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	int idx=((CComboBox *)GetDlgItem(IDC_COMBO23))->GetCurSel();
	sendCmd(uno_id,55,idx);

}

void CUNITCHECKDlg::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	sendCmd(uno_id,4,1);
	m_a_y_pos=0;
	UpdateData(false);
}

void CUNITCHECKDlg::OnBnClickedButton26()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	UpdateData(true);
	if(m_a_z_step>0)
	{
		sendCmd(uno_id,52,1);
		sendCmd(uno_id,8,m_a_z_step);

	}
	else
	{
		sendCmd(uno_id,52,0);
		sendCmd(uno_id,8,-m_a_z_step);

	}
	m_a_z_pos+=m_a_z_step;
	if(m_a_z_pos<0)
	{
		m_a_z_pos=0;
	}
	UpdateData(false);


}

void CUNITCHECKDlg::OnBnClickedButton27()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	UpdateData(true);
	if(m_a_z_step>0)
	{
		sendCmd(uno_id,9,m_a_z_step);

	}
	m_a_z_pos=m_a_z_step;

	UpdateData(false);
}

void CUNITCHECKDlg::OnCbnSelchangeCombo24()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	int idx=((CComboBox *)GetDlgItem(IDC_COMBO24))->GetCurSel();
	sendCmd(uno_id,56,idx);
}

void CUNITCHECKDlg::OnBnClickedButton28()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	sendCmd(uno_id,7,1);
	m_a_z_pos=0;
	UpdateData(false);
}

void CUNITCHECKDlg::OnBnClickedButton29()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	UpdateData(true);
	if(m_a_k_step>0)
	{
		sendCmd(uno_id,53,1);
		sendCmd(uno_id,11,m_a_k_step);

	}
	else
	{
		sendCmd(uno_id,53,0);
		sendCmd(uno_id,11,-m_a_k_step);

	}
	m_a_k_pos+=m_a_k_step;
	if(m_a_k_pos<0)
	{
		m_a_k_pos=0;
	}
	UpdateData(false);
}

void CUNITCHECKDlg::OnBnClickedButton30()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	UpdateData(true);
	if(m_a_k_step>0)
	{
		sendCmd(uno_id,12,m_a_k_step);

	}
	m_a_k_pos=m_a_k_step;

	UpdateData(false);
}

void CUNITCHECKDlg::OnCbnSelchangeCombo25()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	int idx=((CComboBox *)GetDlgItem(IDC_COMBO25))->GetCurSel();
	sendCmd(uno_id,57,idx);

}

void CUNITCHECKDlg::OnBnClickedButton31()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	sendCmd(uno_id,10,1);
	m_a_k_pos=0;
	UpdateData(false);
}

void CUNITCHECKDlg::OnEnChangeEdit33()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CUNITCHECKDlg::OnBnClickedButton32()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	megafilepath=".\\ini\\MEGA_2560.ini";
	CFileFind find;
	if(!find.FindFile(megafilepath))
	{
		AfxMessageBox("找不到2560配置文件，请将配置文件放在ini目录下");
		return ;
	}
	int inputnum=0;
	int outputnum=0;
	memset(theApp.checkpin,-1,sizeof(int)*70);
	memset(theApp.outputpin,-1,sizeof(int)*70);
	CString tagname,outname,pinname;
	for(int i=0;i<70;i++)
	{
		tagname.Format("m_2560_checkTag%d",i+1);
		pinname.Format("m_2560_checkPin%d",i+1);
		::GetPrivateProfileString(_T("2560_tag"),tagname,"",temp.GetBuffer(255),255,megafilepath);
		temp.ReleaseBuffer();
		theApp.checktag[inputnum]=temp;
		
		theApp.checkpin[inputnum]=::GetPrivateProfileInt(_T("2560_pin"),pinname,-1,megafilepath);
		if(theApp.checkpin[i]<-1 ||theApp.checkpin[i]>69)
		{
			AfxMessageBox("引脚值超出范围");
			return ;
		}
		if(theApp.checkpin[i]!=-1)
		{
			inputnum++;
			((CButton *)GetDlgItem(IDC_CHECK1+i))->SetWindowTextA(theApp.checktag[i]);
			((CButton *)GetDlgItem(IDC_CHECK1+i))->ShowWindow(true);
		}

	}
	for(int i=0;i<theApp.chipnum;i++)
	{
		temp.Format("芯片%d状态",i+1);
		((CButton *)GetDlgItem(IDC_CHECK1+i+inputnum))->SetWindowTextA(temp);
		((CButton *)GetDlgItem(IDC_CHECK1+i+inputnum))->ShowWindow(true);

	}
	for(int i=0;i<70;i++)
	{

		outname.Format("m_2560_outPin%d",i+1);

		theApp.outputpin[outputnum]=::GetPrivateProfileInt(_T("2560_output"),outname,-1,megafilepath);
		if(theApp.outputpin[i]<-1 ||theApp.outputpin[i]>69)
		{
			AfxMessageBox("引脚值超出范围");
			return ;
		}
		if(theApp.outputpin[i]!=-1)
		{
			outputnum++;
		}


	}
	MessageBox("读配置成功");



}

void CUNITCHECKDlg::OnBnClickedButton33()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	int pin[70];
	memset(pin,-1,sizeof(int)*70);
	int inputnum=0;
	int outputnum=0;
	for(int i=0;i<70;i++)
	{
		if(theApp.checkpin[i]!=-1)
		{
			inputnum++;
			pin[theApp.checkpin[i]]++;
			temp.Format("{r0:1=%d;}",theApp.checkpin[i]*4+1);
			theApp.transfer.SendCmd(temp);
			Sleep(100);

		}
		if(theApp.outputpin[i]!=-1)
		{
			outputnum++;
			pin[theApp.outputpin[i]]++;
			temp.Format("{r0:1=%d;}",theApp.outputpin[i]*4+2);
			theApp.transfer.SendCmd(temp);
			Sleep(100);

		}

	}
	for(int i=0;i<70;i++)
	{
		if(pin[i]==-1)
		{
			temp.Format("{r0:1=%d;}",i*4);
			theApp.transfer.SendCmd(temp);
			Sleep(100);
		}
		else if(pin[i]>0)
		{
			temp.Format("引脚值%d重复",i);
			MessageBox(temp);

		}
	}
	temp.Format(_T("%d"),inputnum);::WritePrivateProfileString(_T("pinnum"),_T("inputnum"),temp,megafilepath);Sleep(100);
	temp.Format(_T("%d"),outputnum);::WritePrivateProfileString(_T("pinnum"),_T("outputnum"),temp,megafilepath);Sleep(100);
	theApp.transfer.SendCmd("{r0:0=1;}");
	Sleep(100);
	MessageBox("写配置成功");



}

//void CUNITCHECKDlg::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	CDialog::OnTimer(nIDEvent);
//	if(nIDEvent==1)
//	{
//		
//		
//	}
//}

void CUNITCHECKDlg::OnBnClickedButton34()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.PowerOn();


}

void CUNITCHECKDlg::OnBnClickedButton35()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.PowerOff();
}




void CUNITCHECKDlg::OnBnClickedButton39()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unol_pinmc=((CComboBox *)GetDlgItem(IDC_COMBO27))->GetCurSel();
	if(m_unol_pinmc==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:152=%d;}",uno_id,m_unol_pinmc);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unol_pinmc);
		::WritePrivateProfileString(_T("UNO"),_T("m_unol_pinmc"),temp,ini_filepath);
		;
	}
}



void CUNITCHECKDlg::OnCbnSelchangeCombo8()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CUNITCHECKDlg::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CUNITCHECKDlg::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CUNITCHECKDlg::OnCbnSelchangeCombo17()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	m_unox_speedmode =((CComboBox *)GetDlgItem(IDC_COMBO17))->GetCurSel();
	temp.Format("{r%d:54=%d;}",uno_id,m_unox_speedmode);
	theApp.transfer.SendCmd(temp);
}
void CUNITCHECKDlg::OnCbnSelchangeCombo18()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	m_unoy_speedmode =((CComboBox *)GetDlgItem(IDC_COMBO17))->GetCurSel();
	temp.Format("{r%d:55=%d;}",uno_id,m_unoy_speedmode);
	theApp.transfer.SendCmd(temp);
}

void CUNITCHECKDlg::OnCbnSelchangeCombo19()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	m_unoz_speedmode =((CComboBox *)GetDlgItem(IDC_COMBO17))->GetCurSel();
	temp.Format("{r%d:56=%d;}",uno_id,m_unoz_speedmode);
	theApp.transfer.SendCmd(temp);
}

void CUNITCHECKDlg::OnCbnSelchangeCombo20()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	m_unok_speedmode =((CComboBox *)GetDlgItem(IDC_COMBO17))->GetCurSel();
	temp.Format("{r%d:57=%d;}",uno_id,m_unok_speedmode);
	theApp.transfer.SendCmd(temp);
}

void CUNITCHECKDlg::OnCbnSelchangeCombo27()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CUNITCHECKDlg::OnCbnSelchangeCombo28()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CUNITCHECKDlg::OnCbnSelchangeCombo26()
{
	// TODO: 在此添加控件通知处理程序代码
	m_unok_exist=((CComboBox *)GetDlgItem(IDC_COMBO26))->GetCurSel();
	CString temp;
	temp.Format(_T("%d"),m_unok_exist);
	::WritePrivateProfileString(_T("UNO"),_T("m_unok_exist"),temp,ini_filepath);
	if(((CComboBox *)GetDlgItem(IDC_COMBO26))->GetCurSel()==1)
	{
		((CComboBox *)GetDlgItem(IDC_COMBO27))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO28))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO29))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_COMBO30))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT33))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT34))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT35))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT36))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT37))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT38))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON39))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON41))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON42))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON43))->EnableWindow(false);

		((CComboBox *)GetDlgItem(IDC_COMBO31))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT39))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_EDIT40))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON44))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON45))->EnableWindow(false);
		((CComboBox *)GetDlgItem(IDC_BUTTON46))->EnableWindow(false);



	}
	else
	{
		((CComboBox *)GetDlgItem(IDC_COMBO27))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO28))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO29))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_COMBO30))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT33))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT34))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT35))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT36))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT37))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT38))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON39))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON41))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON42))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON43))->EnableWindow(true);

		((CComboBox *)GetDlgItem(IDC_COMBO31))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT39))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_EDIT40))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON44))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON45))->EnableWindow(true);
		((CComboBox *)GetDlgItem(IDC_BUTTON46))->EnableWindow(true);
	}
}

void CUNITCHECKDlg::OnCbnSelchangeCombo29()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CUNITCHECKDlg::OnCbnSelchangeCombo14()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CUNITCHECKDlg::OnBnClickedButton41()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unol_pinfx=((CComboBox *)GetDlgItem(IDC_COMBO28))->GetCurSel();
	if(m_unol_pinfx==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:153=%d;}",uno_id,m_unol_pinfx);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unol_pinfx);
		::WritePrivateProfileString(_T("UNO"),_T("m_unol_pinfx"),temp,ini_filepath);

		;
	}
}

void CUNITCHECKDlg::OnBnClickedButton42()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	CString temp;
	m_unol_pinzero=((CComboBox *)GetDlgItem(IDC_COMBO29))->GetCurSel();
	if(m_unol_pinzero==-1)
	{
		AfxMessageBox("当前选项为空，请先选择");
		return ;
	}
	else
	{
		temp.Format("{r%d:154=%d;}",uno_id,m_unol_pinzero);
		theApp.transfer.SendCmd(temp);

		temp.Format(_T("%d"),m_unol_pinzero);
		::WritePrivateProfileString(_T("UNO"),_T("m_unol_pinzero"),temp,ini_filepath);
		;
	}
}

void CUNITCHECKDlg::OnCbnSelchangeCombo30()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	m_unol_speedmode =((CComboBox *)GetDlgItem(IDC_COMBO30))->GetCurSel();
	temp.Format("{r%d:63=%d;}",uno_id,m_unol_speedmode);
	theApp.transfer.SendCmd(temp);

}

void CUNITCHECKDlg::OnBnClickedButton43()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;
	}
	UpdateData(true);
	CString temp;
	((CComboBox *)GetDlgItem(IDC_COMBO30))->GetWindowText(temp);

	if(!m_unol_hspeedh ||!m_unol_hspeedm ||!m_unol_hspeedl||!m_unol_lspeedh||!m_unol_lspeedm||!m_unol_lspeedl||temp=="")
	{
		AfxMessageBox("当前有选项为空，请先选择");
		return ;

	}
	else
	{

		temp.Format("{r%d:145=%d;}",uno_id,m_unol_hspeedh);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:146=%d;}",uno_id,m_unol_hspeedm);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:147=%d;}",uno_id,m_unol_hspeedl);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:148=%d;}",uno_id,m_unol_lspeedh);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:149=%d;}",uno_id,m_unol_lspeedm);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:150=%d;}",uno_id,m_unol_lspeedl);
		theApp.transfer.SendCmd(temp);
		Sleep(100);

		m_unol_speedmode=((CComboBox *)GetDlgItem(IDC_COMBO30))->GetCurSel();
		temp.Format("{r%d:155=%d;}",uno_id,m_unol_speedmode);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format("{r%d:63=%d;}",uno_id,m_unol_speedmode);
		theApp.transfer.SendCmd(temp);
		Sleep(100);
		temp.Format(_T("%d"),m_unol_speedmode);::WritePrivateProfileString(_T("UNO"),_T("m_unol_speedmode"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unol_hspeedh);::WritePrivateProfileString(_T("UNO"),_T("m_unol_hspeedh"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unol_hspeedm);::WritePrivateProfileString(_T("UNO"),_T("m_unol_hspeedm"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unol_hspeedl);::WritePrivateProfileString(_T("UNO"),_T("m_unol_hspeedl"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unol_lspeedl);::WritePrivateProfileString(_T("UNO"),_T("m_unol_lspeedl"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unol_lspeedm);::WritePrivateProfileString(_T("UNO"),_T("m_unol_lspeedm"),temp,ini_filepath);Sleep(100);
		temp.Format(_T("%d"),m_unol_lspeedh);::WritePrivateProfileString(_T("UNO"),_T("m_unol_lspeedh"),temp,ini_filepath);Sleep(100);
	}
}

void CUNITCHECKDlg::OnCbnSelchangeCombo31()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	int idx=((CComboBox *)GetDlgItem(IDC_COMBO25))->GetCurSel();
	sendCmd(uno_id,63,idx);

}

void CUNITCHECKDlg::OnBnClickedButton44()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	UpdateData(true);
	if(m_a_l_step>0)
	{
		sendCmd(uno_id,65,1);
		sendCmd(uno_id,16,m_a_l_step);

	}
	else
	{
		sendCmd(uno_id,65,0);
		sendCmd(uno_id,16,-m_a_l_step);

	}
	m_a_l_pos+=m_a_l_step;
	if(m_a_l_pos<0)
	{
		m_a_l_pos=0;
	}
	UpdateData(false);
}

void CUNITCHECKDlg::OnBnClickedButton45()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	UpdateData(true);
	if(m_a_l_step>0)
	{
		sendCmd(uno_id,17,m_a_l_step);

	}
	m_a_l_pos=m_a_l_step;

	UpdateData(false);
}

void CUNITCHECKDlg::OnBnClickedButton46()
{
	// TODO: 在此添加控件通知处理程序代码
	if(((CComboBox *)GetDlgItem(IDC_COMBO21))->GetCurSel()==-1)
	{
		AfxMessageBox("请先选择UNO编号");return ;

	}
	sendCmd(uno_id,15,1);
	m_a_l_pos=0;
	UpdateData(false);
}

void CUNITCHECKDlg::OnBnClickedButton36()
{
	// TODO: 在此添加控件通知处理程序代码
}
