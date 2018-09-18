// TPJ10Test.cpp : 实现文件
//

#include "stdafx.h"
#include "UNITCHECK.h"
#include "UNITCHECKDlg.h"
#include "TPJ10Test.h"
#include "TPJ10.h"




// CTPJ10Test 对话框
DWORD WINAPI zeroCheck( LPVOID pParam )
{
	CTPJ10Test* pDlg=( CTPJ10Test*)pParam;
	while(!pDlg->endflag)
	{
		for(int i=0;i<theApp.inputnum;i++)
		{
			if(pDlg->endflag)
				break;
			((CButton *)(pDlg->GetDlgItem(IDC_CHECK71+i)))->SetCheck(theApp.status[i]);
		}

		Sleep(2);
	}
	return -1;
}

IMPLEMENT_DYNAMIC(CTPJ10Test, CDialog)

CTPJ10Test::CTPJ10Test(CWnd* pParent /*=NULL*/)
	: CDialog(CTPJ10Test::IDD, pParent)
	, m_a_1_xpos(0)
	, m_a_1_xstep(0)
	, m_a_1_ypos(0)
	, m_a_1_ystep(0)
	, m_a_1_zpos(0)
	, m_a_1_zstep(0)
	, m_a_1_kpos(0)
	, m_a_1_kstep(0)
	, m_a_1_lpos(0)
	, m_a_1_lstep(0)
	, m_a_2_xpos(0)
	, m_a_2_xstep(0)
	, m_d_1_samplex1(0)
	, m_d_1_samplex2(0)
	, m_d_1_samplex3(0)
	, m_d_1_samplex4(0)
	, m_d_1_samplex5(0)
	, m_d_1_samplex6(0)
	, m_d_1_samplex7(0)
	, m_d_1_samplex8(0)
	, m_d_1_samplex9(0)
	, m_d_1_samplex10(0)
	, m_d_1_glassx1(0)
	, m_d_1_glassx2(0)
	, m_d_1_glassx3(0)
	, m_d_1_glassx4(0)
	, m_d_1_glassx5(0)
	, m_d_1_glassx6(0)
	, m_d_1_glassx7(0)
	, m_d_1_glassx8(0)
	, m_d_1_glassx9(0)
	, m_d_1_glassx10(0)
	, m_d_2_sjpos1(0)
	, m_d_2_sjpos2(0)
	, m_d_2_sjpos3(0)
	, m_d_2_sjpos4(0)
	, m_d_2_sjpos5(0)
	, m_d_2_sjpos6(0)
	, m_d_2_sjpos7(0)
	, m_d_2_sjpos8(0)
	, m_d_2_sjpos9(0)
	, m_d_2_sjpos10(0)
	, m_d_1_sampley(0)
	, m_d_1_samplez(0)
	, m_d_1_glassy(0)
	, m_d_1_glassz(0)
	, m_a_2_ypos(0)
	, m_a_2_ystep(0)
	, m_d_2_qinxie(0)
	,  m_d_1_kgdown(0)
	,  m_d_1_kgzhuan(0)
	,  m_d_1_ggzhuan(0)
	, m_d_1_tplength(0)
	, m_d_1_tpwidth(0)
	, m_d_1_tpgong(0)
	, m_d_1_tpquan(0)
	,  m_d_2_pianrs(0)
	,  m_d_2_piants(0)
	,  m_d_2_pianfr(0)
	,  m_d_2_pianh2o(0)
	,  m_d_2_rswaittime(0)
	,  m_d_2_tswaittime(0)
	,  m_d_2_frwaittime(0)
	,  m_d_1_piansamplewritex(0)
	,  m_d_1_piansamplewritey(0)
	,  m_d_1_samplewritez(0)
	,  m_d_1_zilength(0)
	,  m_d_1_ziwidth(0)
	,  m_d_1_zige(0)
	,  m_d_1_piancheckx(0)
	,  m_d_1_pianchecky(0)
	,  m_d_1_piancheckz(0)
	,  m_d_1_piansmearx(0)
	,  m_d_1_piansmeary(0)
	,  m_d_1_piansmearz(0)
	,  m_d_1_pianglasswritex(0)
	,  m_d_1_pianglasswritey(0)
	,  m_d_1_glasswritez(0)
	, m_d_2_tsnum(0)
	, m_d_2_frnum(0)
	, m_a_1_num(0)
	,  m_d_1_smeark(0)
	, m_a_1_zinum(0)
	, m_d_1_tibi(0)
	, m_d_2_tsspraytime(0)
	, m_d_2_frspraytime(0)
	, m_d_2_rsspraytime(0)
	, m_a_2_tuoseh2o(0)
	, m_d_2_qingxih2o(0)
	, m_d_2_gdjspraytime(0)
	, m_d_2_glassgdtime(0)
	, m_d_2_rsWashTimes(1)
	, m_d_2_tsWashTimes(1)
	, m_d_2_frWashTimes(1)
	, m_1_kggspeed(0)
	, m_1_huanbiy(0)
	, m_1_tpspeed(0)
	, m_d_xiaodutime(0)
	, m_d_2_rsQxptTime(0)
	, m_d_2_tsQxptTime(0)
	, m_d_2_frQxptTime(0)
	, m_1_d_preHotTime(0)
	, m_1_d_preHotMaxTime(0)
	, m_1_d_minTimeBeforeTp(0)
	, m_d_2_glsmrNum(0)
	, m_d_2_glsmrWashNum(_T(0))
	, m_d_2_glsmrsprayTime(0)
	, m_d_2_glsmrQxptsprayTime(0)
	, m_d_2_pianmr(0)
	, m_d_2_glsmrwaitTime(0)
	, m_d_2_zeroCorrected(0)
	{
	endflag=false;
	beenupload=false;
}

CTPJ10Test::~CTPJ10Test()
{
}

void CTPJ10Test::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT25, m_a_1_xpos);
	DDX_Text(pDX, IDC_EDIT26, m_a_1_xstep);
	DDX_Text(pDX, IDC_EDIT27, m_a_1_ypos);
	DDX_Text(pDX, IDC_EDIT28, m_a_1_ystep);
	DDX_Text(pDX, IDC_EDIT29, m_a_1_zpos);
	DDX_Text(pDX, IDC_EDIT30, m_a_1_zstep);
	DDX_Text(pDX, IDC_EDIT31, m_a_1_kpos);
	DDX_Text(pDX, IDC_EDIT32, m_a_1_kstep);
	DDX_Text(pDX, IDC_EDIT39, m_a_1_lpos);
	DDX_Text(pDX, IDC_EDIT40, m_a_1_lstep);
	DDX_Text(pDX, IDC_EDIT41, m_a_2_xpos);
	DDX_Text(pDX, IDC_EDIT42, m_a_2_xstep);
	DDX_Text(pDX, IDC_EDIT1, m_d_1_samplex1);
	DDX_Text(pDX, IDC_EDIT43, m_d_1_samplex2);
	DDX_Text(pDX, IDC_EDIT44, m_d_1_samplex3);
	DDX_Text(pDX, IDC_EDIT45, m_d_1_samplex4);
	DDX_Text(pDX, IDC_EDIT5, m_d_1_samplex5);
	DDX_Text(pDX, IDC_EDIT46, m_d_1_samplex6);
	DDX_Text(pDX, IDC_EDIT47, m_d_1_samplex7);
	DDX_Text(pDX, IDC_EDIT48, m_d_1_samplex8);
	DDX_Text(pDX, IDC_EDIT49, m_d_1_samplex9);
	DDX_Text(pDX, IDC_EDIT50, m_d_1_samplex10);
	DDX_Text(pDX, IDC_EDIT9, m_d_1_glassx1);
	DDX_Text(pDX, IDC_EDIT51, m_d_1_glassx2);
	DDX_Text(pDX, IDC_EDIT52, m_d_1_glassx3);
	DDX_Text(pDX, IDC_EDIT53, m_d_1_glassx4);
	DDX_Text(pDX, IDC_EDIT54, m_d_1_glassx5);
	DDX_Text(pDX, IDC_EDIT55, m_d_1_glassx6);
	DDX_Text(pDX, IDC_EDIT56, m_d_1_glassx7);
	DDX_Text(pDX, IDC_EDIT57, m_d_1_glassx8);
	DDX_Text(pDX, IDC_EDIT58, m_d_1_glassx9);
	DDX_Text(pDX, IDC_EDIT59, m_d_1_glassx10);
	DDX_Text(pDX, IDC_EDIT60, m_d_2_sjpos1);
	DDX_Text(pDX, IDC_EDIT61, m_d_2_sjpos2);
	DDX_Text(pDX, IDC_EDIT62, m_d_2_sjpos3);
	DDX_Text(pDX, IDC_EDIT63, m_d_2_sjpos4);
	DDX_Text(pDX, IDC_EDIT64, m_d_2_sjpos5);
	DDX_Text(pDX, IDC_EDIT65, m_d_2_sjpos6);
	DDX_Text(pDX, IDC_EDIT66, m_d_2_sjpos7);
	DDX_Text(pDX, IDC_EDIT67, m_d_2_sjpos8);
	DDX_Text(pDX, IDC_EDIT68, m_d_2_sjpos9);
	DDX_Text(pDX, IDC_EDIT69, m_d_2_sjpos10);
	DDX_Text(pDX, IDC_EDIT70, m_d_1_sampley);
	DDX_Text(pDX, IDC_EDIT71, m_d_1_samplez);
	DDX_Text(pDX, IDC_EDIT72, m_d_1_glassy);
	DDX_Text(pDX, IDC_EDIT73, m_d_1_glassz);
	DDX_Text(pDX, IDC_EDIT103, m_a_2_ypos);
	DDX_Text(pDX, IDC_EDIT104, m_a_2_ystep);
	DDX_Text(pDX, IDC_EDIT105, m_d_2_qinxie);
	DDX_Text(pDX, IDC_EDIT90,  m_d_1_kgdown);
	DDX_Text(pDX, IDC_EDIT91,  m_d_1_kgzhuan);
	DDX_Text(pDX, IDC_EDIT92,  m_d_1_ggzhuan);
	DDX_Text(pDX, IDC_EDIT86, m_d_1_tplength);
	DDX_Text(pDX, IDC_EDIT87, m_d_1_tpwidth);
	DDX_Text(pDX, IDC_EDIT88, m_d_1_tpgong);
	DDX_Text(pDX, IDC_EDIT89, m_d_1_tpquan);
	DDX_Text(pDX, IDC_EDIT93,  m_d_2_pianrs);
	DDX_Text(pDX, IDC_EDIT94,  m_d_2_piants);
	DDX_Text(pDX, IDC_EDIT95,  m_d_2_pianfr);
	DDX_Text(pDX, IDC_EDIT96,  m_d_2_pianh2o);
	DDX_Text(pDX, IDC_EDIT100,  m_d_2_rswaittime);
	DDX_Text(pDX, IDC_EDIT101,  m_d_2_tswaittime);
	DDX_Text(pDX, IDC_EDIT102,  m_d_2_frwaittime);
	DDX_Text(pDX, IDC_EDIT74,  m_d_1_piansamplewritex);
	DDX_Text(pDX, IDC_EDIT75,  m_d_1_piansamplewritey);
	DDX_Text(pDX, IDC_EDIT76,  m_d_1_samplewritez);
	DDX_Text(pDX, IDC_EDIT83,  m_d_1_zilength);
	DDX_Text(pDX, IDC_EDIT84,  m_d_1_ziwidth);
	DDX_Text(pDX, IDC_EDIT85,  m_d_1_zige);
	DDX_Text(pDX, IDC_EDIT80,  m_d_1_piancheckx);
	DDX_Text(pDX, IDC_EDIT81,  m_d_1_pianchecky);
	DDX_Text(pDX, IDC_EDIT82,  m_d_1_piancheckz);
	DDX_Text(pDX, IDC_EDIT97,  m_d_1_piansmearx);
	DDX_Text(pDX, IDC_EDIT98,  m_d_1_piansmeary);
	DDX_Text(pDX, IDC_EDIT99,  m_d_1_piansmearz);
	DDX_Text(pDX, IDC_EDIT77,  m_d_1_pianglasswritex);
	DDX_Text(pDX, IDC_EDIT78,  m_d_1_pianglasswritey);
	DDX_Text(pDX, IDC_EDIT79,  m_d_1_glasswritez);
	DDX_Text(pDX, IDC_EDIT106, m_d_2_tsnum);
	DDX_Text(pDX, IDC_EDIT107, m_d_2_frnum);
	DDX_Text(pDX, IDC_EDIT108, m_a_1_num);
	DDX_Text(pDX, IDC_EDIT113,  m_d_1_smeark);
	DDX_Text(pDX, IDC_EDIT109, m_a_1_zinum);
	DDX_Text(pDX, IDC_EDIT114, m_d_1_tibi);
	DDX_Text(pDX, IDC_EDIT110, m_d_2_tsspraytime);
	DDX_Text(pDX, IDC_EDIT111, m_d_2_frspraytime);
	DDX_Text(pDX, IDC_EDIT112, m_d_2_rsspraytime);
	DDX_Text(pDX, IDC_EDIT115, m_a_2_tuoseh2o);
	DDX_Text(pDX, IDC_EDIT116, m_d_2_qingxih2o);
	DDX_Text(pDX, IDC_EDIT117, m_d_2_gdjspraytime);
	DDX_Text(pDX, IDC_EDIT118, m_d_2_glassgdtime);
	DDX_Text(pDX, IDC_EDIT119, m_d_2_rsWashTimes);
	DDX_Text(pDX, IDC_EDIT120, m_d_2_tsWashTimes);
	DDX_Text(pDX, IDC_EDIT121, m_d_2_frWashTimes);
	DDX_Text(pDX, IDC_EDIT122, m_1_kggspeed);
	DDX_Text(pDX, IDC_EDIT123, m_1_huanbiy);
	DDX_Text(pDX, IDC_EDIT124, m_1_tpspeed);
	DDX_Text(pDX, IDC_EDIT125, m_d_xiaodutime);
	DDV_MinMaxLong(pDX, m_d_2_rsWashTimes, 1, 3);
	DDV_MinMaxLong(pDX, m_d_2_tsWashTimes, 1, 3);
	DDV_MinMaxLong(pDX, m_1_kggspeed, 0, LONG_MAX);
	DDX_Text(pDX, IDC_EDIT126, m_d_2_rsQxptTime);
	DDX_Text(pDX, IDC_EDIT127, m_d_2_tsQxptTime);
	DDX_Text(pDX, IDC_EDIT128, m_d_2_frQxptTime);
	DDX_Text(pDX, IDC_EDIT129, m_1_d_preHotTime);
	DDX_Text(pDX, IDC_EDIT130, m_1_d_preHotMaxTime);
	DDX_Text(pDX, IDC_EDIT131, m_1_d_minTimeBeforeTp);
	DDX_Text(pDX, IDC_EDIT132, m_d_2_glsmrNum);
	DDX_Text(pDX, IDC_EDIT133, m_d_2_glsmrWashNum);
	DDX_Text(pDX, IDC_EDIT134, m_d_2_glsmrsprayTime);
	DDX_Text(pDX, IDC_EDIT135, m_d_2_glsmrQxptsprayTime);
	DDX_Text(pDX, IDC_EDIT136, m_d_2_pianmr);
	DDX_Text(pDX, IDC_EDIT137, m_d_2_glsmrwaitTime);
	DDX_Text(pDX, IDC_EDIT138, m_d_2_zeroCorrected);
	DDV_MinMaxLong(pDX, m_d_2_zeroCorrected, 0, 10);
	DDV_MinMaxLong(pDX, m_d_2_qinxie, 0, 180);
}


BEGIN_MESSAGE_MAP(CTPJ10Test, CDialog)
	ON_BN_CLICKED(IDC_BUTTON20, &CTPJ10Test::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON23, &CTPJ10Test::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON26, &CTPJ10Test::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON29, &CTPJ10Test::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON44, &CTPJ10Test::OnBnClickedButton44)
	ON_BN_CLICKED(IDC_BUTTON21, &CTPJ10Test::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON24, &CTPJ10Test::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON27, &CTPJ10Test::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON30, &CTPJ10Test::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON45, &CTPJ10Test::OnBnClickedButton45)
	ON_BN_CLICKED(IDC_BUTTON22, &CTPJ10Test::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON25, &CTPJ10Test::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON28, &CTPJ10Test::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON31, &CTPJ10Test::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON46, &CTPJ10Test::OnBnClickedButton46)
	ON_CBN_SELCHANGE(IDC_COMBO22, &CTPJ10Test::OnCbnSelchangeCombo22)
	ON_CBN_SELCHANGE(IDC_COMBO23, &CTPJ10Test::OnCbnSelchangeCombo23)
	ON_CBN_SELCHANGE(IDC_COMBO24, &CTPJ10Test::OnCbnSelchangeCombo24)
	ON_CBN_SELCHANGE(IDC_COMBO25, &CTPJ10Test::OnCbnSelchangeCombo25)
	ON_CBN_SELCHANGE(IDC_COMBO31, &CTPJ10Test::OnCbnSelchangeCombo31)
	ON_BN_CLICKED(IDC_BUTTON48, &CTPJ10Test::OnBnClickedButton48)
	ON_BN_CLICKED(IDC_BUTTON47, &CTPJ10Test::OnBnClickedButton47)
	ON_BN_CLICKED(IDC_BUTTON49, &CTPJ10Test::OnBnClickedButton49)
	ON_BN_CLICKED(IDC_BUTTON114, &CTPJ10Test::OnBnClickedButton114)
	ON_BN_CLICKED(IDC_BUTTON115, &CTPJ10Test::OnBnClickedButton115)
	ON_BN_CLICKED(IDC_BUTTON116, &CTPJ10Test::OnBnClickedButton116)
	ON_BN_CLICKED(IDC_BUTTON1, &CTPJ10Test::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON77, &CTPJ10Test::OnBnClickedButton77)
	ON_BN_CLICKED(IDC_BUTTON78, &CTPJ10Test::OnBnClickedButton78)
	ON_BN_CLICKED(IDC_BUTTON79, &CTPJ10Test::OnBnClickedButton79)
	ON_BN_CLICKED(IDC_BUTTON80, &CTPJ10Test::OnBnClickedButton80)
	ON_BN_CLICKED(IDC_BUTTON2, &CTPJ10Test::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTPJ10Test::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON50, &CTPJ10Test::OnBnClickedButton50)
	ON_BN_CLICKED(IDC_BUTTON51, &CTPJ10Test::OnBnClickedButton51)
	ON_BN_CLICKED(IDC_BUTTON52, &CTPJ10Test::OnBnClickedButton52)
	ON_BN_CLICKED(IDC_BUTTON53, &CTPJ10Test::OnBnClickedButton53)
	ON_BN_CLICKED(IDC_BUTTON54, &CTPJ10Test::OnBnClickedButton54)
	ON_BN_CLICKED(IDC_BUTTON55, &CTPJ10Test::OnBnClickedButton55)
	ON_BN_CLICKED(IDC_BUTTON56, &CTPJ10Test::OnBnClickedButton56)
	ON_BN_CLICKED(IDC_BUTTON57, &CTPJ10Test::OnBnClickedButton57)
	ON_BN_CLICKED(IDC_BUTTON58, &CTPJ10Test::OnBnClickedButton58)
	ON_BN_CLICKED(IDC_BUTTON59, &CTPJ10Test::OnBnClickedButton59)
	ON_BN_CLICKED(IDC_BUTTON60, &CTPJ10Test::OnBnClickedButton60)
	ON_BN_CLICKED(IDC_BUTTON61, &CTPJ10Test::OnBnClickedButton61)
	ON_BN_CLICKED(IDC_BUTTON62, &CTPJ10Test::OnBnClickedButton62)
	ON_BN_CLICKED(IDC_BUTTON63, &CTPJ10Test::OnBnClickedButton63)
	ON_BN_CLICKED(IDC_BUTTON64, &CTPJ10Test::OnBnClickedButton64)
	ON_BN_CLICKED(IDC_BUTTON65, &CTPJ10Test::OnBnClickedButton65)
	ON_BN_CLICKED(IDC_BUTTON66, &CTPJ10Test::OnBnClickedButton66)
	ON_BN_CLICKED(IDC_BUTTON81, &CTPJ10Test::OnBnClickedButton81)
	ON_BN_CLICKED(IDC_BUTTON82, &CTPJ10Test::OnBnClickedButton82)
	ON_BN_CLICKED(IDC_BUTTON83, &CTPJ10Test::OnBnClickedButton83)
	ON_BN_CLICKED(IDC_BUTTON84, &CTPJ10Test::OnBnClickedButton84)
	ON_BN_CLICKED(IDC_BUTTON101, &CTPJ10Test::OnBnClickedButton101)
	ON_BN_CLICKED(IDC_BUTTON102, &CTPJ10Test::OnBnClickedButton102)
	ON_BN_CLICKED(IDC_BUTTON103, &CTPJ10Test::OnBnClickedButton103)
	ON_BN_CLICKED(IDC_BUTTON97, &CTPJ10Test::OnBnClickedButton97)
	ON_BN_CLICKED(IDC_BUTTON98, &CTPJ10Test::OnBnClickedButton98)
	ON_BN_CLICKED(IDC_BUTTON99, &CTPJ10Test::OnBnClickedButton99)
	ON_BN_CLICKED(IDC_BUTTON100, &CTPJ10Test::OnBnClickedButton100)
	ON_BN_CLICKED(IDC_BUTTON104, &CTPJ10Test::OnBnClickedButton104)
	ON_BN_CLICKED(IDC_BUTTON105, &CTPJ10Test::OnBnClickedButton105)
	ON_BN_CLICKED(IDC_BUTTON106, &CTPJ10Test::OnBnClickedButton106)
	ON_BN_CLICKED(IDC_BUTTON107, &CTPJ10Test::OnBnClickedButton107)
	ON_BN_CLICKED(IDC_BUTTON111, &CTPJ10Test::OnBnClickedButton111)
	ON_BN_CLICKED(IDC_BUTTON112, &CTPJ10Test::OnBnClickedButton112)
	ON_BN_CLICKED(IDC_BUTTON113, &CTPJ10Test::OnBnClickedButton113)
	ON_BN_CLICKED(IDC_BUTTON118, &CTPJ10Test::OnBnClickedButton118)
	ON_BN_CLICKED(IDC_BUTTON119, &CTPJ10Test::OnBnClickedButton119)
	ON_BN_CLICKED(IDC_BUTTON85, &CTPJ10Test::OnBnClickedButton85)
	ON_BN_CLICKED(IDC_BUTTON75, &CTPJ10Test::OnBnClickedButton75)
	ON_BN_CLICKED(IDC_BUTTON117, &CTPJ10Test::OnBnClickedButton117)
	ON_BN_CLICKED(IDC_BUTTON67, &CTPJ10Test::OnBnClickedButton67)
	ON_BN_CLICKED(IDC_BUTTON68, &CTPJ10Test::OnBnClickedButton68)
	ON_BN_CLICKED(IDC_BUTTON69, &CTPJ10Test::OnBnClickedButton69)
	ON_BN_CLICKED(IDC_BUTTON70, &CTPJ10Test::OnBnClickedButton70)
	ON_BN_CLICKED(IDC_BUTTON71, &CTPJ10Test::OnBnClickedButton71)
	ON_BN_CLICKED(IDC_BUTTON72, &CTPJ10Test::OnBnClickedButton72)
	ON_BN_CLICKED(IDC_BUTTON73, &CTPJ10Test::OnBnClickedButton73)
	ON_BN_CLICKED(IDC_BUTTON74, &CTPJ10Test::OnBnClickedButton74)
	ON_BN_CLICKED(IDC_BUTTON76, &CTPJ10Test::OnBnClickedButton76)
	ON_BN_CLICKED(IDC_BUTTON86, &CTPJ10Test::OnBnClickedButton86)
	ON_BN_CLICKED(IDC_BUTTON87, &CTPJ10Test::OnBnClickedButton87)
	ON_BN_CLICKED(IDC_BUTTON94, &CTPJ10Test::OnBnClickedButton94)
	ON_BN_CLICKED(IDC_BUTTON95, &CTPJ10Test::OnBnClickedButton95)
	ON_BN_CLICKED(IDC_BUTTON96, &CTPJ10Test::OnBnClickedButton96)
	ON_BN_CLICKED(IDC_BUTTON91, &CTPJ10Test::OnBnClickedButton91)
	ON_BN_CLICKED(IDC_BUTTON89, &CTPJ10Test::OnBnClickedButton89)
	ON_BN_CLICKED(IDC_BUTTON90, &CTPJ10Test::OnBnClickedButton90)
	ON_BN_CLICKED(IDC_BUTTON110, &CTPJ10Test::OnBnClickedButton110)
	ON_BN_CLICKED(IDC_BUTTON108, &CTPJ10Test::OnBnClickedButton108)
	ON_BN_CLICKED(IDC_BUTTON109, &CTPJ10Test::OnBnClickedButton109)
	ON_BN_CLICKED(IDC_BUTTON120, &CTPJ10Test::OnBnClickedButton120)
	ON_BN_CLICKED(IDC_BUTTON121, &CTPJ10Test::OnBnClickedButton121)
	ON_BN_CLICKED(IDC_BUTTON130, &CTPJ10Test::OnBnClickedButton130)
	ON_BN_CLICKED(IDC_BUTTON122, &CTPJ10Test::OnBnClickedButton122)
	ON_BN_CLICKED(IDC_BUTTON123, &CTPJ10Test::OnBnClickedButton123)
	ON_BN_CLICKED(IDC_BUTTON124, &CTPJ10Test::OnBnClickedButton124)
	ON_BN_CLICKED(IDC_BUTTON125, &CTPJ10Test::OnBnClickedButton125)
	ON_BN_CLICKED(IDC_BUTTON126, &CTPJ10Test::OnBnClickedButton126)
	ON_BN_CLICKED(IDC_BUTTON136, &CTPJ10Test::OnBnClickedButton136)
	ON_BN_CLICKED(IDC_BUTTON129, &CTPJ10Test::OnBnClickedButton129)
	ON_BN_CLICKED(IDC_BUTTON131, &CTPJ10Test::OnBnClickedButton131)
	ON_BN_CLICKED(IDC_BUTTON132, &CTPJ10Test::OnBnClickedButton132)
	ON_BN_CLICKED(IDC_BUTTON128, &CTPJ10Test::OnBnClickedButton128)
	ON_BN_CLICKED(IDC_BUTTON137, &CTPJ10Test::OnBnClickedButton137)
	ON_BN_CLICKED(IDC_BUTTON127, &CTPJ10Test::OnBnClickedButton127)
	ON_BN_CLICKED(IDC_BUTTON139, &CTPJ10Test::OnBnClickedButton139)
	ON_BN_CLICKED(IDC_BUTTON138, &CTPJ10Test::OnBnClickedButton138)
	ON_BN_CLICKED(IDC_BUTTON133, &CTPJ10Test::OnBnClickedButton133)
	ON_BN_CLICKED(IDC_BUTTON134, &CTPJ10Test::OnBnClickedButton134)
	ON_BN_CLICKED(IDC_BUTTON135, &CTPJ10Test::OnBnClickedButton135)
	ON_BN_CLICKED(IDC_BUTTON141, &CTPJ10Test::OnBnClickedButton141)
	ON_BN_CLICKED(IDC_BUTTON143, &CTPJ10Test::OnBnClickedButton143)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON140, &CTPJ10Test::OnBnClickedButton140)
	ON_BN_CLICKED(IDC_BUTTON144, &CTPJ10Test::OnBnClickedButton144)
	ON_BN_CLICKED(IDC_BUTTON92, &CTPJ10Test::OnBnClickedButton92)
	ON_BN_CLICKED(IDC_BUTTON93, &CTPJ10Test::OnBnClickedButton93)
	ON_BN_CLICKED(IDC_BUTTON88, &CTPJ10Test::OnBnClickedButton88)
	ON_BN_CLICKED(IDC_BUTTON142, &CTPJ10Test::OnBnClickedButton142)
	ON_BN_CLICKED(IDC_BUTTON145, &CTPJ10Test::OnBnClickedButton145)
	ON_BN_CLICKED(IDC_BUTTON146, &CTPJ10Test::OnBnClickedButton146)
	ON_BN_CLICKED(IDC_BUTTON147, &CTPJ10Test::OnBnClickedButton147)
	ON_BN_CLICKED(IDC_BUTTON148, &CTPJ10Test::OnBnClickedButton148)
	ON_BN_CLICKED(IDC_BUTTON149, &CTPJ10Test::OnBnClickedButton149)
	ON_BN_CLICKED(IDC_BUTTON150, &CTPJ10Test::OnBnClickedButton150)
	ON_BN_CLICKED(IDC_BUTTON151, &CTPJ10Test::OnBnClickedButton151)
	ON_BN_CLICKED(IDC_BUTTON152, &CTPJ10Test::OnBnClickedButton152)
	ON_BN_CLICKED(IDC_BUTTON153, &CTPJ10Test::OnBnClickedButton153)
	ON_BN_CLICKED(IDC_BUTTON154, &CTPJ10Test::OnBnClickedButton154)
	ON_CBN_SELCHANGE(IDC_COMBO32, &CTPJ10Test::OnCbnSelchangeCombo32)
	ON_CBN_SELCHANGE(IDC_COMBO33, &CTPJ10Test::OnCbnSelchangeCombo33)
	ON_BN_CLICKED(IDC_BUTTON155, &CTPJ10Test::OnBnClickedButton155)
	ON_BN_CLICKED(IDC_BUTTON156, &CTPJ10Test::OnBnClickedButton156)
	ON_BN_CLICKED(IDC_BUTTON157, &CTPJ10Test::OnBnClickedButton157)
	ON_BN_CLICKED(IDC_BUTTON158, &CTPJ10Test::OnBnClickedButton158)
	ON_BN_CLICKED(IDC_BUTTON159, &CTPJ10Test::OnBnClickedButton159)
	ON_BN_CLICKED(IDC_BUTTON160, &CTPJ10Test::OnBnClickedButton160)
	ON_BN_CLICKED(IDC_BUTTON161, &CTPJ10Test::OnBnClickedButton161)
	ON_BN_CLICKED(IDC_BUTTON162, &CTPJ10Test::OnBnClickedButton162)
	ON_BN_CLICKED(IDC_BUTTON163, &CTPJ10Test::OnBnClickedButton163)
	ON_BN_CLICKED(IDC_BUTTON164, &CTPJ10Test::OnBnClickedButton164)
	ON_BN_CLICKED(IDC_BUTTON165, &CTPJ10Test::OnBnClickedButton165)
	ON_BN_CLICKED(IDC_BUTTON166, &CTPJ10Test::OnBnClickedButton166)
	ON_BN_CLICKED(IDC_BUTTON167, &CTPJ10Test::OnBnClickedButton167)
	ON_BN_CLICKED(IDC_BUTTON168, &CTPJ10Test::OnBnClickedButton168)
	ON_BN_CLICKED(IDC_BUTTON169, &CTPJ10Test::OnBnClickedButton169)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CTPJ10Test::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CTPJ10Test::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO34, &CTPJ10Test::OnCbnSelchangeCombo34)
	ON_CBN_SELCHANGE(IDC_COMBO35, &CTPJ10Test::OnCbnSelchangeCombo35)
	ON_BN_CLICKED(IDC_BUTTON170, &CTPJ10Test::OnBnClickedButton170)
	ON_BN_CLICKED(IDC_BUTTON171, &CTPJ10Test::OnBnClickedButton171)
	ON_BN_CLICKED(IDC_BUTTON172, &CTPJ10Test::OnBnClickedButton172)
	ON_BN_CLICKED(IDC_BUTTON173, &CTPJ10Test::OnBnClickedButton173)
	ON_BN_CLICKED(IDC_BUTTON174, &CTPJ10Test::OnBnClickedButton174)
	ON_BN_CLICKED(IDC_BUTTON175, &CTPJ10Test::OnBnClickedButton175)
	ON_BN_CLICKED(IDC_BUTTON176, &CTPJ10Test::OnBnClickedButton176)
	END_MESSAGE_MAP()


// CTPJ10Test 消息处理程序
void CTPJ10Test::upload()
{
	((CComboBox *)GetDlgItem(IDC_COMBO1))->SetCurSel(theApp.mytools.m_methodKind);
	((CComboBox *)GetDlgItem(IDC_COMBO2))->SetCurSel(theApp.mytools.m_methodKindVisible);
	((CComboBox *)GetDlgItem(IDC_COMBO34))->SetCurSel(theApp.mytools.m_reconnectEnable);
	((CComboBox *)GetDlgItem(IDC_COMBO35))->SetCurSel(theApp.mytools.m_machineKind);
	theApp.mytools.ReadParam(theApp.mytools.m_machineKind,"m_machineKind");
	theApp.mytools.ReadParam(m_d_2_glsmrNum,"m_d_2_glsmrNum");
	theApp.mytools.ReadParam(m_d_2_glsmrWashNum,"m_d_2_glsmrWashNum");
	theApp.mytools.ReadParam(m_d_2_glsmrsprayTime,"m_d_2_glsmrsprayTime");
	theApp.mytools.ReadParam(m_d_2_glsmrQxptsprayTime,"m_d_2_glsmrQxptsprayTime");
	theApp.mytools.ReadParam(m_d_2_glsmrwaitTime,"m_d_2_glsmrwaitTime");
	theApp.mytools.ReadParam(m_d_2_pianmr,"m_d_2_pianmr");
	theApp.mytools.ReadParam(m_1_d_preHotTime,"m_1_d_preHotTime");
	theApp.mytools.ReadParam(m_1_d_preHotMaxTime,"m_1_d_preHotMaxTime");
	theApp.mytools.ReadParam(m_1_d_minTimeBeforeTp,"m_1_d_minTimeBeforeTp");
	theApp.mytools.ReadParam(m_d_xiaodutime,"m_d_xiaodutime");
	theApp.mytools.ReadParam(m_1_kggspeed,"m_1_kggspeed");
	theApp.mytools.ReadParam(m_1_huanbiy,"m_1_huanbiy");
	theApp.mytools.ReadParam(m_1_tpspeed,"m_1_tpspeed");
	theApp.mytools.ReadParam(m_d_1_samplex1,"m_d_1_samplex1");
	theApp.mytools.ReadParam(m_d_1_samplex2,"m_d_1_samplex2");
	theApp.mytools.ReadParam(m_d_1_samplex3,"m_d_1_samplex3");
	theApp.mytools.ReadParam(m_d_1_samplex4,"m_d_1_samplex4");
	theApp.mytools.ReadParam(m_d_1_samplex5,"m_d_1_samplex5");
	theApp.mytools.ReadParam(m_d_1_samplex6,"m_d_1_samplex6");
	theApp.mytools.ReadParam(m_d_1_samplex7,"m_d_1_samplex7");
	theApp.mytools.ReadParam(m_d_1_samplex8,"m_d_1_samplex8");
	theApp.mytools.ReadParam(m_d_1_samplex9,"m_d_1_samplex9");
	theApp.mytools.ReadParam(m_d_1_samplex10,"m_d_1_samplex10");
	theApp.mytools.ReadParam(m_d_1_glassx1,"m_d_1_glassx1");
	theApp.mytools.ReadParam(m_d_1_glassx2,"m_d_1_glassx2");
	theApp.mytools.ReadParam(m_d_1_glassx3,"m_d_1_glassx3");
	theApp.mytools.ReadParam(m_d_1_glassx4,"m_d_1_glassx4");
	theApp.mytools.ReadParam(m_d_1_glassx5,"m_d_1_glassx5");
	theApp.mytools.ReadParam(m_d_1_glassx6,"m_d_1_glassx6");
	theApp.mytools.ReadParam(m_d_1_glassx7,"m_d_1_glassx7");
	theApp.mytools.ReadParam(m_d_1_glassx8,"m_d_1_glassx8");
	theApp.mytools.ReadParam(m_d_1_glassx9,"m_d_1_glassx9");
	theApp.mytools.ReadParam(m_d_1_glassx10,"m_d_1_glassx10");
	theApp.mytools.ReadParam(m_d_2_sjpos1,"m_d_2_sjpos1");
	theApp.mytools.ReadParam(m_d_2_sjpos2,"m_d_2_sjpos2");
	theApp.mytools.ReadParam(m_d_2_sjpos3,"m_d_2_sjpos3");
	theApp.mytools.ReadParam(m_d_2_sjpos4,"m_d_2_sjpos4");
	theApp.mytools.ReadParam(m_d_2_sjpos5,"m_d_2_sjpos5");
	theApp.mytools.ReadParam(m_d_2_sjpos6,"m_d_2_sjpos6");
	theApp.mytools.ReadParam(m_d_2_sjpos7,"m_d_2_sjpos7");
	theApp.mytools.ReadParam(m_d_2_sjpos8,"m_d_2_sjpos8");
	theApp.mytools.ReadParam(m_d_2_sjpos9,"m_d_2_sjpos9");
	theApp.mytools.ReadParam(m_d_2_sjpos10,"m_d_2_sjpos10");
	theApp.mytools.ReadParam(m_d_1_sampley,"m_d_1_sampley");
	theApp.mytools.ReadParam(m_d_1_samplez,"m_d_1_samplez");
	theApp.mytools.ReadParam(m_d_1_glassy,"m_d_1_glassy");
	theApp.mytools.ReadParam(m_d_1_glassz,"m_d_1_glassz");
	theApp.mytools.ReadParam(m_d_2_qinxie,"m_d_2_qinxie");
	theApp.mytools.ReadParam( m_d_1_kgdown," m_d_1_kgdown");
	theApp.mytools.ReadParam( m_d_1_kgzhuan," m_d_1_kgzhuan");
	theApp.mytools.ReadParam( m_d_1_ggzhuan," m_d_1_ggzhuan");
	theApp.mytools.ReadParam(m_d_1_tplength,"m_d_1_tplength");
	theApp.mytools.ReadParam(m_d_1_tpwidth,"m_d_1_tpwidth");
	theApp.mytools.ReadParam(m_d_1_tpgong,"m_d_1_tpgong");
	theApp.mytools.ReadParam(m_d_1_tpquan,"m_d_1_tpquan");
	theApp.mytools.ReadParam( m_d_2_pianrs," m_d_2_pianrs");
	theApp.mytools.ReadParam( m_d_2_piants," m_d_2_piants");
	theApp.mytools.ReadParam( m_d_2_pianfr," m_d_2_pianfr");
	theApp.mytools.ReadParam( m_d_2_pianh2o," m_d_2_pianh2o");
	theApp.mytools.ReadParam( m_d_2_rswaittime," m_d_2_rswaittime");
	theApp.mytools.ReadParam( m_d_2_tswaittime," m_d_2_tswaittime");
	theApp.mytools.ReadParam( m_d_2_frwaittime," m_d_2_frwaittime");
	theApp.mytools.ReadParam( m_d_1_piansamplewritex," m_d_1_piansamplewritex");
	theApp.mytools.ReadParam( m_d_1_piansamplewritey," m_d_1_piansamplewritey");
	theApp.mytools.ReadParam( m_d_1_samplewritez," m_d_1_samplewritez");
	theApp.mytools.ReadParam( m_d_1_zilength," m_d_1_zilength");
	theApp.mytools.ReadParam( m_d_1_ziwidth," m_d_1_ziwidth");
	theApp.mytools.ReadParam( m_d_1_zige," m_d_1_zige");
	theApp.mytools.ReadParam( m_d_1_piancheckx," m_d_1_piancheckx");
	theApp.mytools.ReadParam( m_d_1_pianchecky," m_d_1_pianchecky");
	theApp.mytools.ReadParam( m_d_1_piancheckz," m_d_1_piancheckz");
	theApp.mytools.ReadParam( m_d_1_piansmearx," m_d_1_piansmearx");
	theApp.mytools.ReadParam( m_d_1_piansmeary," m_d_1_piansmeary");
	theApp.mytools.ReadParam( m_d_2_qingxih2o," m_d_2_qingxih2o");
	theApp.mytools.ReadParam( m_d_1_piansmearz," m_d_1_piansmearz");
	theApp.mytools.ReadParam( m_d_1_smeark," m_d_1_smeark");
	theApp.mytools.ReadParam( m_d_1_pianglasswritex," m_d_1_pianglasswritex");
	theApp.mytools.ReadParam( m_d_1_pianglasswritey," m_d_1_pianglasswritey");
	theApp.mytools.ReadParam( m_d_1_glasswritez," m_d_1_glasswritez");
	theApp.mytools.ReadParam(m_d_2_frnum,"m_d_2_frnum");
	theApp.mytools.ReadParam(m_d_2_tsnum,"m_d_2_tsnum");
	theApp.mytools.ReadParam( m_d_1_tibi," m_d_1_tibi");
	theApp.mytools.ReadParam(m_d_2_rsspraytime," m_d_2_rsspraytime");
	theApp.mytools.ReadParam(m_d_2_tsspraytime," m_d_2_tsspraytime");
	theApp.mytools.ReadParam(m_d_2_frspraytime," m_d_2_frspraytime");
	theApp.mytools.ReadParam(m_d_2_gdjspraytime," m_d_2_gdjspraytime");
	theApp.mytools.ReadParam(m_d_2_rsWashTimes," m_d_2_rsWashTimes");
	theApp.mytools.ReadParam(m_d_2_tsWashTimes," m_d_2_tsWashTimes");
	theApp.mytools.ReadParam(m_d_2_frWashTimes," m_d_2_frWashTimes");
	theApp.mytools.ReadParam(m_d_2_glassgdtime," m_d_2_glassgdtime");
	theApp.mytools.ReadParam(m_d_2_rsQxptTime,"m_d_2_rsQxptTime");
	theApp.mytools.ReadParam(m_d_2_tsQxptTime,"m_d_2_tsQxptTime");
	theApp.mytools.ReadParam(m_d_2_frQxptTime,"m_d_2_frQxptTime");
	theApp.mytools.ReadParam(m_d_2_zeroCorrected,"m_d_2_zeroCorrected");
	UpdateData(FALSE);
	AfxMessageBox("上传完成");
}
void CTPJ10Test::download()
{
	UpdateData();
	theApp.mytools.WriteParam(m_d_2_zeroCorrected,"m_d_2_zeroCorrected");
	theApp.mytools.WriteParam(m_d_2_glsmrNum,"m_d_2_glsmrNum");
	theApp.mytools.WriteParam(m_d_2_glsmrWashNum,"m_d_2_glsmrWashNum");
	theApp.mytools.WriteParam(m_d_2_glsmrsprayTime,"m_d_2_glsmrsprayTime");
	theApp.mytools.WriteParam(m_d_2_glsmrQxptsprayTime,"m_d_2_glsmrQxptsprayTime");
	theApp.mytools.WriteParam(m_d_2_glsmrwaitTime,"m_d_2_glsmrwaitTime");
	theApp.mytools.WriteParam(m_d_2_pianmr,"m_d_2_pianmr");
	theApp.mytools.WriteParam(m_1_d_preHotTime,"m_1_d_preHotTime");
	theApp.mytools.WriteParam(m_1_d_preHotMaxTime,"m_1_d_preHotMaxTime");
	theApp.mytools.WriteParam(m_1_d_minTimeBeforeTp,"m_1_d_minTimeBeforeTp");
	theApp.mytools.WriteParam(m_d_2_rsQxptTime,"m_d_2_rsQxptTime");
	theApp.mytools.WriteParam(m_d_2_tsQxptTime,"m_d_2_tsQxptTime");
	theApp.mytools.WriteParam(m_d_2_frQxptTime,"m_d_2_frQxptTime");
	theApp.mytools.WriteParam(m_d_xiaodutime,"m_d_xiaodutime");
	theApp.mytools.WriteParam(m_1_kggspeed,"m_1_kggspeed");
	theApp.mytools.WriteParam(m_1_huanbiy,"m_1_huanbiy");
	theApp.mytools.WriteParam(m_1_tpspeed,"m_1_tpspeed");
	theApp.mytools.WriteParam(m_d_2_rsWashTimes," m_d_2_rsWashTimes");
	theApp.mytools.WriteParam(m_d_2_tsWashTimes," m_d_2_tsWashTimes");
	theApp.mytools.WriteParam(m_d_2_frWashTimes," m_d_2_frWashTimes");
	theApp.mytools.WriteParam(m_d_2_glassgdtime," m_d_2_glassgdtime");
	theApp.mytools.WriteParam(m_d_2_gdjspraytime," m_d_2_gdjspraytime");
	theApp.mytools.WriteParam(m_d_1_samplex1,"m_d_1_samplex1");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_samplex2,"m_d_1_samplex2");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_samplex3,"m_d_1_samplex3");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_samplex4,"m_d_1_samplex4");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_samplex5,"m_d_1_samplex5");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_samplex6,"m_d_1_samplex6");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_samplex7,"m_d_1_samplex7");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_samplex8,"m_d_1_samplex8");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_samplex9,"m_d_1_samplex9");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_samplex10,"m_d_1_samplex10");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassx1,"m_d_1_glassx1");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassx2,"m_d_1_glassx2");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassx3,"m_d_1_glassx3");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassx4,"m_d_1_glassx4");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassx5,"m_d_1_glassx5");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassx6,"m_d_1_glassx6");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassx7,"m_d_1_glassx7");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassx8,"m_d_1_glassx8");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassx9,"m_d_1_glassx9");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassx10,"m_d_1_glassx10");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_sjpos1,"m_d_2_sjpos1");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_sjpos2,"m_d_2_sjpos2");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_sjpos3,"m_d_2_sjpos3");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_sjpos4,"m_d_2_sjpos4");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_sjpos5,"m_d_2_sjpos5");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_sjpos6,"m_d_2_sjpos6");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_sjpos7,"m_d_2_sjpos7");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_sjpos8,"m_d_2_sjpos8");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_sjpos9,"m_d_2_sjpos9");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_sjpos10,"m_d_2_sjpos10");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_sampley,"m_d_1_sampley");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_samplez,"m_d_1_samplez");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassy,"m_d_1_glassy");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_glassz,"m_d_1_glassz");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_qinxie,"m_d_2_qinxie");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_kgdown," m_d_1_kgdown");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_kgzhuan," m_d_1_kgzhuan");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_ggzhuan," m_d_1_ggzhuan");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_tplength,"m_d_1_tplength");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_tpwidth,"m_d_1_tpwidth");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_tpgong,"m_d_1_tpgong");Sleep(30);
	theApp.mytools.WriteParam(m_d_1_tpquan,"m_d_1_tpquan");Sleep(30);
	theApp.mytools.WriteParam( m_d_2_pianrs," m_d_2_pianrs");Sleep(30);
	theApp.mytools.WriteParam( m_d_2_piants," m_d_2_piants");Sleep(30);
	theApp.mytools.WriteParam( m_d_2_pianfr," m_d_2_pianfr");Sleep(30);
	theApp.mytools.WriteParam( m_d_2_pianh2o," m_d_2_pianh2o");Sleep(30);
	theApp.mytools.WriteParam( m_d_2_rswaittime," m_d_2_rswaittime");Sleep(30);
	theApp.mytools.WriteParam( m_d_2_tswaittime," m_d_2_tswaittime");Sleep(30);
	theApp.mytools.WriteParam( m_d_2_frwaittime," m_d_2_frwaittime");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_piansamplewritex," m_d_1_piansamplewritex");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_piansamplewritey," m_d_1_piansamplewritey");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_samplewritez," m_d_1_samplewritez");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_zilength," m_d_1_zilength");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_ziwidth," m_d_1_ziwidth");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_zige," m_d_1_zige");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_piancheckx," m_d_1_piancheckx");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_pianchecky," m_d_1_pianchecky");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_piancheckz," m_d_1_piancheckz");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_piansmearx," m_d_1_piansmearx");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_piansmeary," m_d_1_piansmeary");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_piansmearz," m_d_1_piansmearz");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_smeark," m_d_1_smeark");;Sleep(30);
	theApp.mytools.WriteParam( m_d_1_pianglasswritex," m_d_1_pianglasswritex");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_pianglasswritey," m_d_1_pianglasswritey");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_glasswritez," m_d_1_glasswritez");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_frnum,"m_d_2_frnum");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_tsnum,"m_d_2_tsnum");Sleep(30);
	theApp.mytools.WriteParam( m_d_1_tibi," m_d_1_tibi");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_rsspraytime," m_d_2_rsspraytime");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_tsspraytime," m_d_2_tsspraytime");Sleep(30);
	theApp.mytools.WriteParam(m_d_2_frspraytime," m_d_2_frspraytime");Sleep(30);
	theApp.mytools.WriteParam( m_d_2_qingxih2o," m_d_2_qingxih2o");
	theApp.transfer.SendCmd(1,157,m_d_1_zilength);
	Sleep(30);
	theApp.transfer.SendCmd(1,158,m_d_1_zige);
	Sleep(30);
	theApp.transfer.SendCmd(1,156,m_d_1_ziwidth);
	Sleep(30);
	theApp.transfer.SendCmd(1,159,m_d_1_kgdown);
	Sleep(30);
	theApp.transfer.SendCmd(1,160,m_d_1_kgzhuan);
	Sleep(30);
	theApp.transfer.SendCmd(1,164,m_d_1_tpquan);
	Sleep(30);
	theApp.transfer.SendCmd(1,163,m_d_1_tpgong);
	Sleep(30);
	theApp.transfer.SendCmd(1,162,m_d_1_tplength);
	Sleep(30);
	theApp.transfer.SendCmd(1,161,m_d_1_tpwidth);
	Sleep(30);
	theApp.transfer.SendCmd(1,165,m_1_kggspeed);
	Sleep(30);
	theApp.transfer.SendCmd(1,166,m_1_tpspeed);




	AfxMessageBox("下载完成");


}

void CTPJ10Test::OnBnClickedButton20()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Xmove(1,m_a_1_xstep);
	m_a_1_xpos+=m_a_1_xstep;
	if(m_a_1_xpos<0)
		m_a_1_xpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton23()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Ymove(1,m_a_1_ystep);
	m_a_1_ypos+=m_a_1_ystep;
	if(m_a_1_ypos<0)
		m_a_1_ypos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton26()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Zmove(1,m_a_1_zstep);
	m_a_1_zpos+=m_a_1_zstep;
	if(m_a_1_zpos<0)
		m_a_1_zpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton29()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Kmove(1,m_a_1_kstep);
	m_a_1_kpos+=m_a_1_kstep;
	if(m_a_1_kpos<0)
		m_a_1_kpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton44()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Lmove(1,m_a_1_lstep);
	m_a_1_lpos+=m_a_1_lstep;
	if(m_a_1_lpos<0)
		m_a_1_lpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Xmoveto(1,m_a_1_xstep);
	m_a_1_xpos=m_a_1_xstep;
	if(m_a_1_xpos<0)
		m_a_1_xpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton24()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Ymoveto(1,m_a_1_ystep);
	m_a_1_ypos=m_a_1_ystep;
	if(m_a_1_ypos<0)
		m_a_1_ypos=0;
		

	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton27()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Zmoveto(1,m_a_1_zstep);
	m_a_1_zpos=m_a_1_zstep;
	if(m_a_1_zpos<0)
		m_a_1_zpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton30()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Kmoveto(1,m_a_1_kstep);
	m_a_1_kpos=m_a_1_kstep;
	if(m_a_1_kpos<0)
		m_a_1_kpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton45()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Lmoveto(1,m_a_1_lstep);
	m_a_1_lpos=m_a_1_lstep;
	if(m_a_1_lpos<0)
		m_a_1_lpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton22()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.Xhome(1);
	m_a_1_xpos=0;
	UpdateData(false);

}

void CTPJ10Test::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.Yhome(1);
	m_a_1_ypos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton28()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.Zhome(1);
	m_a_1_zpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton31()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.Khome(1);
	m_a_1_kpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton46()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.Lhome(1);
	m_a_1_lpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnCbnSelchangeCombo22()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	int speedmode =((CComboBox *)GetDlgItem(IDC_COMBO22))->GetCurSel();
	theApp.transfer.SendCmd(1,54,speedmode);
}

void CTPJ10Test::OnCbnSelchangeCombo23()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	int speedmode =((CComboBox *)GetDlgItem(IDC_COMBO23))->GetCurSel();
	theApp.transfer.SendCmd(1,55,speedmode);
}

void CTPJ10Test::OnCbnSelchangeCombo24()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	int speedmode =((CComboBox *)GetDlgItem(IDC_COMBO24))->GetCurSel();
	theApp.transfer.SendCmd(1,56,speedmode);
}

void CTPJ10Test::OnCbnSelchangeCombo25()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	int speedmode =((CComboBox *)GetDlgItem(IDC_COMBO25))->GetCurSel();
	theApp.transfer.SendCmd(1,57,speedmode);
}

void CTPJ10Test::OnCbnSelchangeCombo31()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	int speedmode =((CComboBox *)GetDlgItem(IDC_COMBO31))->GetCurSel();
	theApp.transfer.SendCmd(1,63,speedmode);
}

void CTPJ10Test::OnBnClickedButton48()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Xmoveto(2,m_a_2_xstep);
	m_a_2_xpos=m_a_2_xstep;
	if(m_a_2_xpos<0)
		m_a_2_xpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton47()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Xmove(2,m_a_2_xstep);
	m_a_2_xpos+=m_a_2_xstep;
	if(m_a_2_xpos<0)
		m_a_2_xpos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton49()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.Xhome(2);
	m_a_2_xpos=0;
	UpdateData(false);

}

void CTPJ10Test::OnBnClickedButton114()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Ymove(2,m_a_2_ystep);
	m_a_2_ypos+=m_a_2_ystep;
	if(m_a_2_ypos<0)
		m_a_2_ypos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton115()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	theApp.transfer.Ymoveto(2,m_a_2_ystep);
	m_a_2_ypos=m_a_2_ystep;
	if(m_a_2_ypos<0)
		m_a_2_ypos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton116()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.Yhome(2);
	m_a_2_ypos=0;
	UpdateData(false);
}

void CTPJ10Test::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_samplex1);
	theApp.mytools.WriteParam(m_d_1_samplex1,"m_d_1_samplex1");

}

void CTPJ10Test::OnBnClickedButton77()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.PowerOn();
}

void CTPJ10Test::OnBnClickedButton78()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.PowerOff();
}

void CTPJ10Test::OnBnClickedButton79()
{
	// TODO: 在此添加控件通知处理程序代码
	beenupload=true;
	upload();
}

void CTPJ10Test::OnBnClickedButton80()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!beenupload)
	{
		AfxMessageBox("请先上传再下载",MB_SYSTEMMODAL);
		return;
	}
	download();
}

void CTPJ10Test::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_samplex2);
	theApp.mytools.WriteParam(m_d_1_samplex2,"m_d_1_samplex2");
}

void CTPJ10Test::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_samplex3);
	theApp.mytools.WriteParam(m_d_1_samplex3,"m_d_1_samplex3");
}

void CTPJ10Test::OnBnClickedButton50()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_samplex4);
	theApp.mytools.WriteParam(m_d_1_samplex4,"m_d_1_samplex4");
}

void CTPJ10Test::OnBnClickedButton51()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_samplex5);
	theApp.mytools.WriteParam(m_d_1_samplex5,"m_d_1_samplex5");
}

void CTPJ10Test::OnBnClickedButton52()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_samplex6);
	theApp.mytools.WriteParam(m_d_1_samplex6,"m_d_1_samplex6");
}

void CTPJ10Test::OnBnClickedButton53()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_samplex7);
	theApp.mytools.WriteParam(m_d_1_samplex7,"m_d_1_samplex7");
}

void CTPJ10Test::OnBnClickedButton54()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_samplex8);
	theApp.mytools.WriteParam(m_d_1_samplex8,"m_d_1_samplex8");
}

void CTPJ10Test::OnBnClickedButton55()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_samplex9);
	theApp.mytools.WriteParam(m_d_1_samplex9,"m_d_1_samplex9");
}

void CTPJ10Test::OnBnClickedButton56()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_samplex10);
	theApp.mytools.WriteParam(m_d_1_samplex10,"m_d_1_samplex10");
}

void CTPJ10Test::OnBnClickedButton57()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_glassx1);
	theApp.mytools.WriteParam(m_d_1_glassx1,"m_d_1_glassx1");
}

void CTPJ10Test::OnBnClickedButton58()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_glassx2);
	theApp.mytools.WriteParam(m_d_1_glassx2,"m_d_1_glassx2");
}

void CTPJ10Test::OnBnClickedButton59()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_glassx3);
	theApp.mytools.WriteParam(m_d_1_glassx3,"m_d_1_glassx3");
}

void CTPJ10Test::OnBnClickedButton60()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_glassx4);
	theApp.mytools.WriteParam(m_d_1_glassx4,"m_d_1_glassx4");

}

void CTPJ10Test::OnBnClickedButton61()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_glassx5);
	theApp.mytools.WriteParam(m_d_1_glassx5,"m_d_1_glassx5");
}

void CTPJ10Test::OnBnClickedButton62()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_glassx6);
	theApp.mytools.WriteParam(m_d_1_glassx6,"m_d_1_glassx6");
}

void CTPJ10Test::OnBnClickedButton63()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_glassx7);
	theApp.mytools.WriteParam(m_d_1_glassx7,"m_d_1_glassx7");

}

void CTPJ10Test::OnBnClickedButton64()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_glassx8);
	theApp.mytools.WriteParam(m_d_1_glassx8,"m_d_1_glassx8");
}

void CTPJ10Test::OnBnClickedButton65()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
		theApp.transfer.Xmoveto(1,m_d_1_glassx9);
	theApp.mytools.WriteParam(m_d_1_glassx9,"m_d_1_glassx9");
}

void CTPJ10Test::OnBnClickedButton66()
{
	UpdateData();
	theApp.transfer.Xmoveto(1,m_d_1_glassx10);
	theApp.mytools.WriteParam(m_d_1_glassx10,"m_d_1_glassx10");
}

void CTPJ10Test::OnBnClickedButton81()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Ymoveto(1,m_d_1_sampley);
	theApp.mytools.WriteParam(m_d_1_sampley,"m_d_1_sampley");

}

void CTPJ10Test::OnBnClickedButton82()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Zmoveto(1,m_d_1_samplez);
	theApp.mytools.WriteParam(m_d_1_samplez,"m_d_1_samplez");
}

void CTPJ10Test::OnBnClickedButton83()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.transfer.Ymoveto(1,m_d_1_glassy);
	theApp.mytools.WriteParam(m_d_1_glassy,"m_d_1_glassy");
}

void CTPJ10Test::OnBnClickedButton84()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Zmoveto(1,m_d_1_glassz);
	theApp.mytools.WriteParam(m_d_1_glassz,"m_d_1_glassz");
}

void CTPJ10Test::OnBnClickedButton101()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_kgdown," m_d_1_kgdown");
	theApp.transfer.SendCmd(1,159,m_d_1_kgdown);

}

void CTPJ10Test::OnBnClickedButton102()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Kmove(1, m_d_1_kgzhuan);
	theApp.mytools.WriteParam( m_d_1_kgzhuan," m_d_1_kgzhuan");
	theApp.transfer.SendCmd(1,160,m_d_1_kgzhuan);
}

void CTPJ10Test::OnBnClickedButton103()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.transfer.Kmove(1,- m_d_1_ggzhuan);
	theApp.mytools.WriteParam( m_d_1_ggzhuan," m_d_1_ggzhuan");

}

void CTPJ10Test::OnBnClickedButton97()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_1_tplength,"m_d_1_tplength");
	theApp.transfer.SendCmd(1,162,m_d_1_tplength);
}

void CTPJ10Test::OnBnClickedButton98()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_1_tpwidth,"m_d_1_tpwidth");
	theApp.transfer.SendCmd(1,161,m_d_1_tpwidth);
}

void CTPJ10Test::OnBnClickedButton99()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_1_tpgong,"m_d_1_tpgong");
	theApp.transfer.SendCmd(1,163,m_d_1_tpgong);

}

void CTPJ10Test::OnBnClickedButton100()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_1_tpquan,"m_d_1_tpquan");
	theApp.transfer.SendCmd(1,164,m_d_1_tpquan);

	
}

void CTPJ10Test::OnBnClickedButton104()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_2_pianrs," m_d_2_pianrs");
}

void CTPJ10Test::OnBnClickedButton105()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_2_piants," m_d_2_piants");
}

void CTPJ10Test::OnBnClickedButton106()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_2_pianfr," m_d_2_pianfr");
}

void CTPJ10Test::OnBnClickedButton107()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_2_pianh2o," m_d_2_pianh2o");
}

void CTPJ10Test::OnBnClickedButton111()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_2_rswaittime," m_d_2_rswaittime");
}

void CTPJ10Test::OnBnClickedButton112()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_2_tswaittime," m_d_2_tswaittime");

}

void CTPJ10Test::OnBnClickedButton113()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_2_frwaittime," m_d_2_frwaittime");

}

void CTPJ10Test::OnBnClickedButton118()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_2_tsnum,"m_d_2_tsnum");
}

void CTPJ10Test::OnBnClickedButton119()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_2_frnum,"m_d_2_frnum");
}

void CTPJ10Test::OnBnClickedButton85()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_piansamplewritex," m_d_1_piansamplewritex");

}

void CTPJ10Test::OnBnClickedButton75()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.transfer.Xmoveto(2,m_d_2_sjpos9);
	theApp.mytools.WriteParam(m_d_2_sjpos9,"m_d_2_sjpos9");
}

void CTPJ10Test::OnBnClickedButton117()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Ymoveto(2,m_d_2_qinxie);
	theApp.mytools.WriteParam(m_d_2_qinxie,"m_d_2_qinxie");
}

void CTPJ10Test::OnBnClickedButton67()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(2,m_d_2_sjpos1);
	theApp.mytools.WriteParam(m_d_2_sjpos1,"m_d_2_sjpos1");
}


void CTPJ10Test::OnBnClickedButton68()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(2,m_d_2_sjpos2);
	theApp.mytools.WriteParam(m_d_2_sjpos2,"m_d_2_sjpos2");
}

void CTPJ10Test::OnBnClickedButton69()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(2,m_d_2_sjpos3);
	theApp.mytools.WriteParam(m_d_2_sjpos3,"m_d_2_sjpos3");
}

void CTPJ10Test::OnBnClickedButton70()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(2,m_d_2_sjpos4);
	theApp.mytools.WriteParam(m_d_2_sjpos4,"m_d_2_sjpos4");
}

void CTPJ10Test::OnBnClickedButton71()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(2,m_d_2_sjpos5);
	theApp.mytools.WriteParam(m_d_2_sjpos5,"m_d_2_sjpos5");

}

void CTPJ10Test::OnBnClickedButton72()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.transfer.Xmoveto(2,m_d_2_sjpos6);
	theApp.mytools.WriteParam(m_d_2_sjpos6,"m_d_2_sjpos6");
}

void CTPJ10Test::OnBnClickedButton73()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(2,m_d_2_sjpos7);
	theApp.mytools.WriteParam(m_d_2_sjpos7,"m_d_2_sjpos7");
}

void CTPJ10Test::OnBnClickedButton74()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(2,m_d_2_sjpos8);
	theApp.mytools.WriteParam(m_d_2_sjpos8,"m_d_2_sjpos8");
}

void CTPJ10Test::OnBnClickedButton76()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(2,m_d_2_sjpos10);
	theApp.mytools.WriteParam(m_d_2_sjpos10,"m_d_2_sjpos10");
}

void CTPJ10Test::OnBnClickedButton86()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.mytools.WriteParam( m_d_1_piansamplewritey," m_d_1_piansamplewritey");
}

void CTPJ10Test::OnBnClickedButton87()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_samplewritez," m_d_1_samplewritez");
}

void CTPJ10Test::OnBnClickedButton94()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_zilength," m_d_1_zilength");
	theApp.transfer.SendCmd(1,157,m_d_1_zilength);
}

void CTPJ10Test::OnBnClickedButton95()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.mytools.WriteParam( m_d_1_ziwidth," m_d_1_ziwidth");
	theApp.transfer.SendCmd(1,156,m_d_1_ziwidth);
}

void CTPJ10Test::OnBnClickedButton96()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_zige," m_d_1_zige");
	theApp.transfer.SendCmd(1,158,m_d_1_zige);

}

void CTPJ10Test::OnBnClickedButton91()
{
	// TODO: 在此添加控件通知处理程序代码 m_d_1_piancheckx
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_piancheckx," m_d_1_piancheckx");
}

void CTPJ10Test::OnBnClickedButton89()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.mytools.WriteParam( m_d_1_pianglasswritey," m_d_1_pianglasswritey");
}

void CTPJ10Test::OnBnClickedButton90()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_glasswritez," m_d_1_glasswritez");
}



void CTPJ10Test::OnBnClickedButton108()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_piansmearx," m_d_1_piansmearx");
}

void CTPJ10Test::OnBnClickedButton109()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_piansmeary," m_d_1_piansmeary");
}
void CTPJ10Test::OnBnClickedButton110()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_piansmearz," m_d_1_piansmearz");
}

void CTPJ10Test::OnBnClickedButton120()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 || m_a_1_num<11)
	{
		long samplepos[10]={m_d_1_samplex1,m_d_1_samplex2,m_d_1_samplex3,m_d_1_samplex4,m_d_1_samplex5,
			m_d_1_samplex6,m_d_1_samplex7,m_d_1_samplex8,m_d_1_samplex9,m_d_1_samplex10};
		theApp.transfer.Xmoveto(1,samplepos[m_a_1_num-1]+ m_d_1_piansamplewritex);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_sampley+ m_d_1_piansamplewritey);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Lmoveto(1,m_d_1_samplewritez);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	}
	else
	{
		AfxMessageBox("位置编号有错误");
	}

}

void CTPJ10Test::OnBnClickedButton121()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 || m_a_1_num<11)
	{
		long glasspos[10]={m_d_1_glassx1,m_d_1_glassx2,m_d_1_glassx3,m_d_1_glassx4,m_d_1_glassx5,
			m_d_1_glassx6,m_d_1_glassx7,m_d_1_glassx8,m_d_1_glassx9,m_d_1_glassx10};
		theApp.transfer.Xmoveto(1,glasspos[m_a_1_num-1]+ m_d_1_pianglasswritex);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_glassy+ m_d_1_pianglasswritey);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Lmoveto(1,m_d_1_glasswritez);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	}
	else
	{
		AfxMessageBox("位置编号有错误");
	}
}

void CTPJ10Test::OnBnClickedButton130()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 && m_a_1_num<11)
	{
		long samplepos[10]={m_d_1_samplex1,m_d_1_samplex2,m_d_1_samplex3,m_d_1_samplex4,m_d_1_samplex5,
			m_d_1_samplex6,m_d_1_samplex7,m_d_1_samplex8,m_d_1_samplex9,m_d_1_samplex10};
		theApp.transfer.Xmoveto(1,samplepos[m_a_1_num-1]);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_sampley);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Zmoveto(1,m_d_1_samplez);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	}
	else
	{
		AfxMessageBox("第几个有错误");
	}
}

void CTPJ10Test::OnBnClickedButton122()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 && m_a_1_num<11)
	{
		long glasspos[10]={m_d_1_glassx1,m_d_1_glassx2,m_d_1_glassx3,m_d_1_glassx4,m_d_1_glassx5,
			m_d_1_glassx6,m_d_1_glassx7,m_d_1_glassx8,m_d_1_glassx9,m_d_1_glassx10};
		theApp.transfer.Xmoveto(1,glasspos[m_a_1_num-1]);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_glassy);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Zmoveto(1,m_d_1_glassz);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	}
	else
	{
		AfxMessageBox("第几个有错误");
	}
}

void CTPJ10Test::OnBnClickedButton123()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 && m_a_1_num<11)
	{
		long samplepos[10]={m_d_1_samplex1,m_d_1_samplex2,m_d_1_samplex3,m_d_1_samplex4,m_d_1_samplex5,
			m_d_1_samplex6,m_d_1_samplex7,m_d_1_samplex8,m_d_1_samplex9,m_d_1_samplex10};
		theApp.transfer.Xmoveto(1,samplepos[m_a_1_num-1]+ m_d_1_piancheckx);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_sampley+ m_d_1_pianchecky);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Zmoveto(1,m_d_1_samplez+ m_d_1_piancheckz);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	}
	else
	{
		AfxMessageBox("第几个有错误");
	}

}

void CTPJ10Test::OnBnClickedButton124()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 && m_a_1_num<11)
	{
		long sjpos[10]={ m_d_2_sjpos1, m_d_2_sjpos2, m_d_2_sjpos3, m_d_2_sjpos4, m_d_2_sjpos5,
			 m_d_2_sjpos6, m_d_2_sjpos7, m_d_2_sjpos8, m_d_2_sjpos9, m_d_2_sjpos10};
		theApp.transfer.Xmoveto(2,sjpos[m_a_1_num-1]+ m_d_2_pianrs);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	}
	else
	{
		AfxMessageBox("第几个有错误");
	}

}

void CTPJ10Test::OnBnClickedButton125()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 && m_a_1_num<11)
	{
		long sjpos[10]={ m_d_2_sjpos1, m_d_2_sjpos2, m_d_2_sjpos3, m_d_2_sjpos4, m_d_2_sjpos5,
			m_d_2_sjpos6, m_d_2_sjpos7, m_d_2_sjpos8, m_d_2_sjpos9, m_d_2_sjpos10};
		theApp.transfer.Xmoveto(2,sjpos[m_a_1_num-1]+ m_d_2_piants);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	}
	else
	{
		AfxMessageBox("第几个有错误");
	}
}

void CTPJ10Test::OnBnClickedButton126()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 && m_a_1_num<11)
	{
		long sjpos[10]={ m_d_2_sjpos1, m_d_2_sjpos2, m_d_2_sjpos3, m_d_2_sjpos4, m_d_2_sjpos5,
			m_d_2_sjpos6, m_d_2_sjpos7, m_d_2_sjpos8, m_d_2_sjpos9, m_d_2_sjpos10};
		theApp.transfer.Xmoveto(2,sjpos[m_a_1_num-1]+ m_d_2_pianfr);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	}
	else
	{
		AfxMessageBox("第几个有错误");
	}
}

void CTPJ10Test::OnBnClickedButton136()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Ymoveto(2,m_d_2_qinxie);
}

void CTPJ10Test::OnBnClickedButton129()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 && m_a_1_num<11)
	{
		long glasspos[10]={m_d_1_glassx1,m_d_1_glassx2,m_d_1_glassx3,m_d_1_glassx4,m_d_1_glassx5,
			m_d_1_glassx6,m_d_1_glassx7,m_d_1_glassx8,m_d_1_glassx9,m_d_1_glassx10};
		theApp.transfer.Xmoveto(1,glasspos[m_a_1_num-1]);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_glassy);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Zmoveto(1,m_d_1_glassz);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.SendCmd(1,14,1);
		theApp.transfer.DelayFinish(1,20000);

		theApp.transfer.Zhome(1);
		theApp.transfer.DelayFinish(1,20000);
	}
	else
	{
		AfxMessageBox("第几个有错误");
	}
	

}

void CTPJ10Test::OnBnClickedButton131()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 && m_a_1_num<11)
	{
		long samplepos[10]={m_d_1_samplex1,m_d_1_samplex2,m_d_1_samplex3,m_d_1_samplex4,m_d_1_samplex5,
			m_d_1_samplex6,m_d_1_samplex7,m_d_1_samplex8,m_d_1_samplex9,m_d_1_samplex10};
		theApp.transfer.Xmoveto(1,samplepos[m_a_1_num-1]);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_sampley);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Zmoveto(1,m_d_1_samplez);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		//theApp.transfer.UnionMove(1,0,0, m_d_1_kgdown, m_d_1_kgzhuan,0,1);
		//theApp.transfer.DelayFinish(1,20000);
		//theApp.transfer.UnionMove(1,0,0,- m_d_1_kgdown, m_d_1_kgzhuan,0,1);
		//theApp.transfer.DelayFinish(1,20000);
		//theApp.transfer.Zhome(1);
		//theApp.transfer.DelayFinish(1,20000);
		theApp.transfer.SendCmd(1,18,1);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		if(!theApp.transfer.getPinMode(48))
		{
			theApp.transfer.Kmove(1,-20000);
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Zhome(1);
			theApp.transfer.DelayFinish(1,20000);
		}
	}
	else
	{
		AfxMessageBox("第几个有错误");
	}
	

}

void CTPJ10Test::OnBnClickedButton132()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 && m_a_1_num<11)
	{
		long samplepos[10]={m_d_1_samplex1,m_d_1_samplex2,m_d_1_samplex3,m_d_1_samplex4,m_d_1_samplex5,
			m_d_1_samplex6,m_d_1_samplex7,m_d_1_samplex8,m_d_1_samplex9,m_d_1_samplex10};
		
		theApp.transfer.Ymoveto(1,m_d_1_sampley);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Xmoveto(1,samplepos[m_a_1_num-1]);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Zmoveto(1,m_d_1_samplez);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		//theApp.transfer.UnionMove(1,0,0, m_d_1_kgdown,-m_d_1_kgzhuan,0,1);
		//theApp.transfer.DelayFinish(1,20000);
		//theApp.transfer.UnionMove(1,0,0,- m_d_1_kgdown, -m_d_1_kgzhuan,0,1);
		//theApp.transfer.DelayFinish(1,20000);
		//theApp.transfer.Zhome(1);
		//theApp.transfer.DelayFinish(1,20000);
		theApp.transfer.SendCmd(1,18,2);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		if(!theApp.transfer.getPinMode(48))
		{
			theApp.transfer.Kmove(1,-20000);
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Zhome(1);
			theApp.transfer.DelayFinish(1,20000);
		}
	}
	else
	{
		AfxMessageBox("第几个有错误");
	}
}

void CTPJ10Test::OnBnClickedButton128()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 && m_a_1_num<11)
	{
		long samplepos[10]={m_d_1_samplex1,m_d_1_samplex2,m_d_1_samplex3,m_d_1_samplex4,m_d_1_samplex5,
			m_d_1_samplex6,m_d_1_samplex7,m_d_1_samplex8,m_d_1_samplex9,m_d_1_samplex10};

		theApp.transfer.Zmoveto(1, m_d_1_samplez+m_d_1_piansmearz-2000);
	theApp.transfer.DelayFinish(1,10000);
	theApp.transfer.Xmoveto(1, samplepos[m_a_1_num-1]+m_d_1_piansmearx);
	theApp.transfer.DelayFinish(1,10000);
	theApp.transfer.setYSpeedMode(1,2);
	theApp.transfer.Ymoveto(1, m_d_1_sampley+m_d_1_piansmeary);
	theApp.transfer.DelayFinish(1,10000);
	theApp.transfer.Zmoveto(1, m_d_1_samplez+m_d_1_piansmearz);
	theApp.transfer.DelayFinish(1,10000);
	theApp.transfer.setYSpeedMode(1,0);
	theApp.transfer.Zmoveto(1, m_d_1_samplez+m_d_1_piansmearz);
	theApp.transfer.DelayFinish(1,10000);
	theApp.transfer.Kmove(1, m_d_1_smeark);
	theApp.transfer.DelayFinish(1,10000);
	theApp.transfer.Zhome(1);
	theApp.transfer.DelayFinish(1,10000);
	}
	else
	{
		AfxMessageBox("第几个有错误");
	}
	
}

void CTPJ10Test::OnBnClickedButton137()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_smeark," m_d_1_smeark");
}

void CTPJ10Test::OnBnClickedButton127()
{
	// TODO: 在此添加控件通知处理程序代码m_a_1_zinum
	UpdateData();
	if(m_a_1_num>0||m_a_1_num<11 || m_a_1_zinum<1 || m_a_1_zinum>999)
	{
		long samplepos[10]={m_d_1_samplex1,m_d_1_samplex2,m_d_1_samplex3,m_d_1_samplex4,m_d_1_samplex5,
			m_d_1_samplex6,m_d_1_samplex7,m_d_1_samplex8,m_d_1_samplex9,m_d_1_samplex10};
		theApp.transfer.Xmoveto(1,samplepos[m_a_1_num-1]+ m_d_1_piansamplewritex);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_sampley+ m_d_1_piansamplewritey);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Lmoveto(1,m_d_1_samplewritez);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.setXSpeedMode(1,2);
		theApp.transfer.setYSpeedMode(1,2);
		theApp.transfer.SendCmd(1,19,m_a_1_zinum);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.setXSpeedMode(1,0);
		theApp.transfer.setYSpeedMode(1,0);
//		theApp.mytools.Write(m_a_1_zinum,samplepos[m_a_1_num-1]+ m_d_1_piansamplewritex,m_d_1_sampley+ m_d_1_piansamplewritey,m_d_1_samplewritez,m_d_1_tibi);
	}
	else
	{
		AfxMessageBox("位置或字编号有错误");
	}
}

void CTPJ10Test::OnBnClickedButton139()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_tibi," m_d_1_tibi");
}

void CTPJ10Test::OnBnClickedButton138()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_a_1_num>0 || m_a_1_num<11)
	{
		long glasspos[10]={m_d_1_glassx1,m_d_1_glassx2,m_d_1_glassx3,m_d_1_glassx4,m_d_1_glassx5,
			m_d_1_glassx6,m_d_1_glassx7,m_d_1_glassx8,m_d_1_glassx9,m_d_1_glassx10};
		theApp.transfer.Xmoveto(1,glasspos[m_a_1_num-1]+ m_d_1_pianglasswritex);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_glassy+ m_d_1_pianglasswritey);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Lmoveto(1,m_d_1_glasswritez);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.setXSpeedMode(1,2);
		theApp.transfer.setYSpeedMode(1,2);
		theApp.transfer.SendCmd(1,19,m_a_1_zinum);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.setXSpeedMode(1,0);
		theApp.transfer.setYSpeedMode(1,0);
//		theApp.mytools.Write(m_a_1_zinum,glasspos[m_a_1_num-1]+ m_d_1_pianglasswritex,m_d_1_glassy+ m_d_1_pianglasswritey,m_d_1_glasswritez,m_d_1_tibi);
	}
	else
	{
		AfxMessageBox("位置编号有错误");
	}
}

void CTPJ10Test::OnBnClickedButton133()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.LiquidSpray(56,m_d_2_tsspraytime);
	theApp.mytools.WriteParam( m_d_2_tsspraytime," m_d_2_tsspraytime");

}

void CTPJ10Test::OnBnClickedButton134()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.LiquidSpray(55,m_d_2_frspraytime);
	theApp.mytools.WriteParam( m_d_2_frspraytime," m_d_2_frspraytime");
}

void CTPJ10Test::OnBnClickedButton135()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.LiquidSpray(57,m_d_2_rsspraytime);
	theApp.mytools.WriteParam(m_d_2_rsspraytime," m_d_2_rsspraytime");
}

void CTPJ10Test::OnBnClickedButton141()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.LiquidSpray(61,m_a_2_tuoseh2o);
}

void CTPJ10Test::OnBnClickedButton143()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.LiquidSpray(59,m_d_2_qingxih2o);
	theApp.mytools.WriteParam(m_d_2_qingxih2o," m_d_2_qingxih2o");
}

BOOL CTPJ10Test::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
 for(int i=0;i<theApp.inputnum;i++)
 {
	 	((CButton *)GetDlgItem(IDC_CHECK71+i))->SetWindowTextA(theApp.checktag[i]);
		((CButton *)GetDlgItem(IDC_CHECK71+i))->ShowWindow(true);
 }
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

	((CComboBox *)GetDlgItem(IDC_COMBO31))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO31))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO31))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO31))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO32))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO32))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO32))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO32))->SetCurSel(2);

	((CComboBox *)GetDlgItem(IDC_COMBO33))->InsertString(-1,"高速");
	((CComboBox *)GetDlgItem(IDC_COMBO33))->InsertString(-1,"中速");
	((CComboBox *)GetDlgItem(IDC_COMBO33))->InsertString(-1,"低速");
	((CComboBox *)GetDlgItem(IDC_COMBO33))->SetCurSel(2);


	((CComboBox *)GetDlgItem(IDC_COMBO1))->InsertString(-1,"涂染");
	((CComboBox *)GetDlgItem(IDC_COMBO1))->InsertString(-1,"染色");

	((CComboBox *)GetDlgItem(IDC_COMBO1))->SetCurSel(theApp.mytools.m_methodKind);

	((CComboBox *)GetDlgItem(IDC_COMBO2))->InsertString(-1,"隐藏");
	((CComboBox *)GetDlgItem(IDC_COMBO2))->InsertString(-1,"可见");

	((CComboBox *)GetDlgItem(IDC_COMBO2))->SetCurSel(theApp.mytools.m_methodKindVisible);

	((CComboBox *)GetDlgItem(IDC_COMBO34))->InsertString(-1,"不可重连");
	((CComboBox *)GetDlgItem(IDC_COMBO34))->InsertString(-1,"可重连");

	((CComboBox *)GetDlgItem(IDC_COMBO34))->SetCurSel(theApp.mytools.m_reconnectEnable);

	((CComboBox *)GetDlgItem(IDC_COMBO35))->InsertString(-1,"抗酸");
	((CComboBox *)GetDlgItem(IDC_COMBO35))->InsertString(-1,"革兰氏");

	((CComboBox *)GetDlgItem(IDC_COMBO35))->SetCurSel(theApp.mytools.m_machineKind);

	((CEdit *)GetDlgItem(IDC_EDIT117))->ShowWindow(!theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON144))->ShowWindow(!theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT132))->ShowWindow(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT133))->ShowWindow(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT134))->ShowWindow(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT135))->ShowWindow(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT136))->ShowWindow(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT137))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON170))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON171))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON172))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON173))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON174))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON175))->ShowWindow(theApp.mytools.m_machineKind);
	upload();


	CreateThread(NULL,0,zeroCheck,this,0,NULL);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CTPJ10Test::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	endflag=true;
	GetOwner()->ShowWindow(true);
	theApp.mytools.upload();

	CDialog::OnClose();
}

void CTPJ10Test::OnBnClickedButton140()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CUNITCHECKDlg unitdlg;
	unitdlg.DoModal();

}

void CTPJ10Test::OnBnClickedButton144()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.mytools.LiquidSpray(54,m_d_2_gdjspraytime);
	theApp.mytools.WriteParam(m_d_2_gdjspraytime," m_d_2_gdjspraytime");
}

void CTPJ10Test::OnBnClickedButton92()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_pianchecky," m_d_1_pianchecky");

}

void CTPJ10Test::OnBnClickedButton93()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_piancheckz," m_d_1_piancheckz");
}

void CTPJ10Test::OnBnClickedButton88()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam( m_d_1_pianglasswritex," m_d_1_pianglasswritex");
}

void CTPJ10Test::OnBnClickedButton142()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.PullDown(32);
	Sleep(3000);
	theApp.transfer.PullUp(32);

}

void CTPJ10Test::OnBnClickedButton145()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.PullDown(34);
	Sleep(3000);
	theApp.transfer.PullUp(34);
}
DWORD WINAPI SJCOpen(LPVOID param)
{
	theApp.transfer.PullDown(37);
	Sleep(1000);
	int i=0;
	while(i<300)
	{
		if(!theApp.transfer.getPinMode(35))
		{
			Sleep(100);
			i++;
			if(!theApp.transfer.getPinMode(35))
			{
				theApp.transfer.PullUp(37);
				break;
			}
		}
		if(theApp.transfer.end || theApp.mytools.endflag)
		{
			theApp.transfer.PullUp(37);
			break;
		}
		i++;
		Sleep(100);
	}
	theApp.transfer.PullUp(37);
	return -1;
}
bool dir=0;
void CTPJ10Test::OnBnClickedButton146()
{
	// TODO: 在此添加控件通知处理程序代码
	CreateThread(NULL,0,SJCOpen,this,0,NULL);


//if(dir)
//{
//	theApp.transfer.PullDown(37);
//
//
//}
//else
//{
//	theApp.transfer.PullUp(37);
//
//}
//dir=!dir;
}

void CTPJ10Test::OnBnClickedButton147()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.mytools.WashSjLast(10);

}

void CTPJ10Test::OnBnClickedButton148()
{
	// TODO: 在此添加控件通知处理程序代码

	theApp.transfer.Lhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);

	theApp.transfer.Zhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	if(!theApp.transfer.getPinMode(44))
	{
		theApp.mytools.ToFrontDoor();
		AfxMessageBox("机械手有笔或盖，请取下后重新初始化");
		return ;
	}
	theApp.transfer.Yhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Xhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);

	theApp.transfer.Xhome(2);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(2,m_d_2_zeroCorrected);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(2,m_d_2_qinxie);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(2,m_d_2_zeroCorrected);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	AfxMessageBox("全回零完成");
}

void CTPJ10Test::OnBnClickedButton149()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.mytools.AlertVoice();

}

void CTPJ10Test::OnBnClickedButton150()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.mytools.upload();
	theApp.mytools.SprayPenTou();

}

void CTPJ10Test::OnBnClickedButton151()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_2_glassgdtime," m_d_2_glassgdtime");

}

void CTPJ10Test::OnBnClickedButton152()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_2_rsWashTimes," m_d_2_rsWashTimes");


}

void CTPJ10Test::OnBnClickedButton153()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData();
	theApp.mytools.WriteParam(m_d_2_tsWashTimes," m_d_2_tsWashTimes");

}

void CTPJ10Test::OnBnClickedButton154()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_2_frWashTimes," m_d_2_frWashTimes");
	

}

void CTPJ10Test::OnCbnSelchangeCombo32()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	int speedmode =((CComboBox *)GetDlgItem(IDC_COMBO32))->GetCurSel();
	theApp.transfer.SendCmd(2,54,speedmode);
}

void CTPJ10Test::OnCbnSelchangeCombo33()
{
	// TODO: 在此添加控件通知处理程序代码
		CString temp;
	int speedmode =((CComboBox *)GetDlgItem(IDC_COMBO33))->GetCurSel();
	theApp.transfer.SendCmd(2,55,speedmode);
}

void CTPJ10Test::OnBnClickedButton155()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Xmoveto(1,m_1_kggspeed);
	theApp.mytools.WriteParam(m_1_kggspeed,"m_1_kggspeed");
	if(m_1_kggspeed>0);
	theApp.transfer.SendCmd(1,165,m_1_kggspeed);




}

void CTPJ10Test::OnBnClickedButton156()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.transfer.Ymoveto(1,m_1_huanbiy);
	theApp.mytools.WriteParam(m_1_huanbiy,"m_1_huanbiy");
	theApp.mytools.ReadParam(m_1_huanbiy,"m_1_huanbiy");



}

void CTPJ10Test::OnBnClickedButton157()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.transfer.Zmoveto(1,m_1_tpspeed);
	theApp.mytools.WriteParam(m_1_tpspeed,"m_1_tpspeed");
	if(m_1_tpspeed>0);
	theApp.transfer.SendCmd(1,166,m_1_tpspeed);

}

void CTPJ10Test::OnBnClickedButton158()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_xiaodutime,"m_d_xiaodutime");
}

void CTPJ10Test::OnBnClickedButton159()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.mytools.Huanbi();
}

void CTPJ10Test::OnBnClickedButton160()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	if(!beenupload)
	{
		AfxMessageBox("请先上传再备份",MB_SYSTEMMODAL);
		return;
	}
	CFileFind find;
	if(!find.FindFile("d:/tpj10backup"))
	{
		::CreateDirectory("d:/tpj10backup",0);
	}

	WinExec("cmd /c copy \".\\Param.ini\"  \"d:\\tpj10backup\\Param.ini\"",SW_HIDE);
	WinExec("cmd /c copy \".\\/PHO.ini\"  \"d:\\tpj10backup\\PHO.ini\"",SW_HIDE);
	AfxMessageBox("备份完成");

}

void CTPJ10Test::OnBnClickedButton161()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileFind find;
	if(!find.FindFile("d:/tpj10backup")||!find.FindFile("d:/tpj10backup/Param.ini")||!find.FindFile("d:/tpj10backup/PHO.ini"))
	{
		AfxMessageBox("备份文件缺失，无法完成还原操作");
	}
	else
	{
		int res=MessageBox("确定还原吗？还原后数据将被备份覆盖","确认",MB_SYSTEMMODAL|MB_OKCANCEL);
		if(res==IDOK)
		{

			WinExec("cmd /c copy    \"d:\\tpj10backup\\Param.ini\"  \".\\Param.ini\" ",SW_HIDE);
			WinExec("cmd /c copy  \"d:\\tpj10backup\\PHO.ini\"  \".\\PHO.ini\"  ",SW_HIDE);
			AfxMessageBox("还原完成");
		}
	}
	upload();
	theApp.mytools.upload();

}

void CTPJ10Test::OnBnClickedButton162()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.PullDown(30);

}

void CTPJ10Test::OnBnClickedButton163()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.transfer.PullUp(30);
}

void CTPJ10Test::OnBnClickedButton164()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_2_rsQxptTime,"m_d_2_rsQxptTime");
}

void CTPJ10Test::OnBnClickedButton165()
{
	// TODO: 在此添加控件通知处理程序代码
		UpdateData();
	theApp.mytools.WriteParam(m_d_2_tsQxptTime,"m_d_2_tsQxptTime");
}

void CTPJ10Test::OnBnClickedButton166()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_2_frQxptTime,"m_d_2_frQxptTime");
}

void CTPJ10Test::OnBnClickedButton167()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData();
	theApp.mytools.WriteParam(m_1_d_preHotTime,"m_1_d_preHotTime");
}

void CTPJ10Test::OnBnClickedButton168()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_1_d_preHotMaxTime,"m_1_d_preHotMaxTime");
}

void CTPJ10Test::OnBnClickedButton169()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_1_d_minTimeBeforeTp,"m_1_d_minTimeBeforeTp");
}

void CTPJ10Test::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.mytools.m_methodKind=((CComboBox *)GetDlgItem(IDC_COMBO1))->GetCurSel();
	theApp.mytools.WriteParam(theApp.mytools.m_methodKind,"m_methodKind");
	((CTPJ10 *) GetParent())->rs.radio.state=theApp.mytools.m_methodKind;


}

void CTPJ10Test::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.mytools.m_methodKindVisible=((CComboBox *)GetDlgItem(IDC_COMBO2))->GetCurSel();
	theApp.mytools.WriteParam(theApp.mytools.m_methodKindVisible,"m_methodKindVisible");
	((CTPJ10 *) GetParent())->rs.radio.setVisiable(theApp.mytools.m_methodKindVisible);

}

void CTPJ10Test::OnCbnSelchangeCombo34()
{
	// TODO: 在此添加控件通知处理程序代码
		theApp.mytools.m_reconnectEnable=((CComboBox *)GetDlgItem(IDC_COMBO34))->GetCurSel();
	theApp.mytools.WriteParam(theApp.mytools.m_reconnectEnable,"m_reconnectEnable");
}

void CTPJ10Test::OnCbnSelchangeCombo35()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.mytools.m_machineKind=((CComboBox *)GetDlgItem(IDC_COMBO35))->GetCurSel();
	theApp.mytools.WriteParam(theApp.mytools.m_machineKind,"m_machineKind");
	((CTPJ10 *) GetParent())->rs.setMachineKind(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT117))->ShowWindow(!theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON144))->ShowWindow(!theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT132))->ShowWindow(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT133))->ShowWindow(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT134))->ShowWindow(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT135))->ShowWindow(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT136))->ShowWindow(theApp.mytools.m_machineKind);
	((CEdit *)GetDlgItem(IDC_EDIT137))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON170))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON171))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON172))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON173))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON174))->ShowWindow(theApp.mytools.m_machineKind);
	((CButton *)GetDlgItem(IDC_BUTTON175))->ShowWindow(theApp.mytools.m_machineKind);


}

void CTPJ10Test::OnBnClickedButton170()
{
	// TODO: 在此添加控件通知处理程序代码
	if(theApp.mytools.m_machineKind==0)
		AfxMessageBox("革兰氏类型机器专用，请先选类型");
	else
	{
		UpdateData();
		theApp.mytools.WriteParam(m_d_2_glsmrNum,"m_d_2_glsmrNum");
	}
}

void CTPJ10Test::OnBnClickedButton171()
{
	// TODO: 在此添加控件通知处理程序代码
	if(theApp.mytools.m_machineKind==0)
		AfxMessageBox("革兰氏类型机器专用，请先选类型");
	else
	{
		UpdateData();
		theApp.mytools.WriteParam(m_d_2_glsmrWashNum,"m_d_2_glsmrWashNum");
	}
}

void CTPJ10Test::OnBnClickedButton172()
{
	// TODO: 在此添加控件通知处理程序代码
	if(theApp.mytools.m_machineKind==0)
		AfxMessageBox("革兰氏类型机器专用，请先选类型");
	else
	{
		UpdateData();
		theApp.mytools.LiquidSpray(54,m_d_2_glsmrsprayTime);
		theApp.mytools.WriteParam(m_d_2_glsmrsprayTime,"m_d_2_glsmrsprayTime");
	}
}

void CTPJ10Test::OnBnClickedButton173()
{
	// TODO: 在此添加控件通知处理程序代码
	if(theApp.mytools.m_machineKind==0)
		AfxMessageBox("革兰氏类型机器专用，请先选类型");
	else
	{
		UpdateData();
		theApp.mytools.LiquidSpray(54,m_d_2_glsmrQxptsprayTime);
		theApp.mytools.WriteParam(m_d_2_glsmrQxptsprayTime,"m_d_2_glsmrQxptsprayTime");
	}
}

void CTPJ10Test::OnBnClickedButton174()
{
	// TODO: 在此添加控件通知处理程序代码
	if(theApp.mytools.m_machineKind==0)
		AfxMessageBox("革兰氏类型机器专用，请先选类型");
	else
	{
		UpdateData();
		theApp.mytools.WriteParam(m_d_2_pianmr,"m_d_2_pianmr");
	}
}

void CTPJ10Test::OnBnClickedButton175()
{
	// TODO: 在此添加控件通知处理程序代码
	if(theApp.mytools.m_machineKind==0)
		AfxMessageBox("革兰氏类型机器专用，请先选类型");
	else
	{
		UpdateData();
		theApp.mytools.WriteParam(m_d_2_glsmrwaitTime,"m_d_2_glsmrwaitTime");
	}
}

void CTPJ10Test::OnBnClickedButton176()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	theApp.mytools.WriteParam(m_d_2_zeroCorrected,"m_d_2_zeroCorrected");
	theApp.transfer.Ymoveto(2,m_d_2_zeroCorrected);
}
