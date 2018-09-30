#include "StdAfx.h"
#include "MyTools.h"
#include "UNITCHECK.h"
#include "math.h"


CMyTools::CMyTools(void)
{
	upload();
	samplepos[0]=m_d_1_samplex1;
	samplepos[1]=m_d_1_samplex2;
	samplepos[2]=m_d_1_samplex3;
	samplepos[3]=m_d_1_samplex4;
	samplepos[4]=m_d_1_samplex5;
	samplepos[5]=m_d_1_samplex6;
	samplepos[6]=m_d_1_samplex7;
	samplepos[7]=m_d_1_samplex8;
	samplepos[8]=m_d_1_samplex9;
	samplepos[9]=m_d_1_samplex10;

	glasspos[0]=m_d_1_glassx1;
	glasspos[1]=m_d_1_glassx2;
	glasspos[2]=m_d_1_glassx3;
	glasspos[3]=m_d_1_glassx4;
	glasspos[4]=m_d_1_glassx5;
	glasspos[5]=m_d_1_glassx6;
	glasspos[6]=m_d_1_glassx7;
	glasspos[7]=m_d_1_glassx8;
	glasspos[8]=m_d_1_glassx9;
	glasspos[9]=m_d_1_glassx10;

	sjpos[0]=m_d_2_sjpos1;
	sjpos[1]=m_d_2_sjpos2;
	sjpos[2]=m_d_2_sjpos3;
	sjpos[3]=m_d_2_sjpos4;
	sjpos[4]=m_d_2_sjpos5;
	sjpos[5]=m_d_2_sjpos6;
	sjpos[6]=m_d_2_sjpos7;
	sjpos[7]=m_d_2_sjpos8;
	sjpos[8]=m_d_2_sjpos9;
	sjpos[9]=m_d_2_sjpos10;
	char buffer[100];
	::GetPrivateProfileString("Ver","m_version","",buffer,100,"./Version.ini");
	m_version=buffer;

	endflag=false;
	samplecount=1;
	needhome=false;
	homedone=false;
	needjy=false;
	jydone=false;

}

CMyTools::~CMyTools(void)
{
}
void CMyTools::upload()
{
	
ReadParam(m_reconnectEnable,"m_reconnectEnable");
ReadParam(m_machineKind,"m_machineKind");
ReadParam(m_d_2_zeroCorrected,"m_d_2_zeroCorrected");
ReadParam(m_d_2_glsmrNum,"m_d_2_glsmrNum");
ReadParam(m_d_2_glsmrWashNum,"m_d_2_glsmrWashNum");
ReadParam(m_d_2_glsmrsprayTime,"m_d_2_glsmrsprayTime");
ReadParam(m_d_2_glsmrQxptsprayTime,"m_d_2_glsmrQxptsprayTime");
ReadParam(m_d_2_glsmrwaitTime,"m_d_2_glsmrwaitTime");
ReadParam(m_d_2_pianmr,"m_d_2_pianmr");
ReadParam(m_d_2_homedelaytime,"m_d_2_homedelaytime");
if(m_d_2_homedelaytime==0)
	m_d_2_homedelaytime=2000;



ReadParam(m_methodKind,"m_methodKind");
ReadParam(m_methodKindVisible,"m_methodKindVisible");
ReadParam(m_1_d_preHotTime,"m_1_d_preHotTime");
ReadParam(m_1_d_preHotMaxTime,"m_1_d_preHotMaxTime");
ReadParam(m_1_d_minTimeBeforeTp,"m_1_d_minTimeBeforeTp");
ReadParam(m_d_xiaodutime,"m_d_xiaodutime");
ReadParam(m_d_2_jaocanpray,"m_d_2_jaocanpray");
ReadParam(m_d_2_jaopraynum,"m_d_2_jaopraynum");
ReadParam(m_d_2_kmnocanpray,"m_d_2_kmnocanpray");
ReadParam(m_d_2_kmnopraynum,"m_d_2_kmnopraynum");
ReadParam(m_d_2_hclcanpray,"m_d_2_hclcanpray");
ReadParam(m_d_2_hclpraynum,"m_d_2_hclpraynum");
ReadParam(m_d_2_gdjcanpray,"m_d_2_gdjcanpray");
ReadParam(m_d_2_gdjpraynum,"m_d_2_gdjpraynum");

ReadParam(m_1_kggspeed," m_1_kggspeed");
ReadParam(m_1_huanbiy," m_1_huanbiy");
ReadParam(m_1_tpspeed," m_1_tpspeed");
ReadParam(m_d_2_rsWashTimes," m_d_2_rsWashTimes");
ReadParam(m_d_2_tsWashTimes," m_d_2_tsWashTimes");
ReadParam(m_d_2_frWashTimes," m_d_2_frWashTimes");
ReadParam(m_d_2_glassgdtime," m_d_2_glassgdtime");
ReadParam(m_d_2_rsQxptTime," m_d_2_rsQxptTime");
ReadParam(m_d_2_tsQxptTime," m_d_2_tsQxptTime");
ReadParam(m_d_2_frQxptTime," m_d_2_frQxptTime");
ReadParam(m_d_2_gdjspraytime," m_d_2_gdjspraytime");
ReadParam(m_d_2_qingxih2o,"m_d_2_qingxih2o");
ReadParam(m_d_1_samplex1,"m_d_1_samplex1");
ReadParam(m_d_1_samplex2,"m_d_1_samplex2");
ReadParam(m_d_1_samplex3,"m_d_1_samplex3");
ReadParam(m_d_1_samplex4,"m_d_1_samplex4");
ReadParam(m_d_1_samplex5,"m_d_1_samplex5");
ReadParam(m_d_1_samplex6,"m_d_1_samplex6");
ReadParam(m_d_1_samplex7,"m_d_1_samplex7");
ReadParam(m_d_1_samplex8,"m_d_1_samplex8");
ReadParam(m_d_1_samplex9,"m_d_1_samplex9");
ReadParam(m_d_1_samplex10,"m_d_1_samplex10");
ReadParam(m_d_1_glassx1,"m_d_1_glassx1");
ReadParam(m_d_1_glassx2,"m_d_1_glassx2");
ReadParam(m_d_1_glassx3,"m_d_1_glassx3");
ReadParam(m_d_1_glassx4,"m_d_1_glassx4");
ReadParam(m_d_1_glassx5,"m_d_1_glassx5");
ReadParam(m_d_1_glassx6,"m_d_1_glassx6");
ReadParam(m_d_1_glassx7,"m_d_1_glassx7");
ReadParam(m_d_1_glassx8,"m_d_1_glassx8");
ReadParam(m_d_1_glassx9,"m_d_1_glassx9");
ReadParam(m_d_1_glassx10,"m_d_1_glassx10");
ReadParam(m_d_2_sjpos1,"m_d_2_sjpos1");
ReadParam(m_d_2_sjpos2,"m_d_2_sjpos2");
ReadParam(m_d_2_sjpos3,"m_d_2_sjpos3");
ReadParam(m_d_2_sjpos4,"m_d_2_sjpos4");
ReadParam(m_d_2_sjpos5,"m_d_2_sjpos5");
ReadParam(m_d_2_sjpos6,"m_d_2_sjpos6");
ReadParam(m_d_2_sjpos7,"m_d_2_sjpos7");
ReadParam(m_d_2_sjpos8,"m_d_2_sjpos8");
ReadParam(m_d_2_sjpos9,"m_d_2_sjpos9");
ReadParam(m_d_2_sjpos10,"m_d_2_sjpos10");
ReadParam(m_d_1_sampley,"m_d_1_sampley");
ReadParam(m_d_1_samplez,"m_d_1_samplez");
ReadParam(m_d_1_glassy,"m_d_1_glassy");
ReadParam(m_d_1_glassz,"m_d_1_glassz");
ReadParam(m_d_2_qinxie,"m_d_2_qinxie");
ReadParam( m_d_1_kgdown," m_d_1_kgdown");
ReadParam( m_d_1_kgzhuan," m_d_1_kgzhuan");
ReadParam( m_d_1_ggzhuan," m_d_1_ggzhuan");
ReadParam(m_d_1_tplength,"m_d_1_tplength");
ReadParam(m_d_1_tpwidth,"m_d_1_tpwidth");
ReadParam(m_d_1_tpgong,"m_d_1_tpgong");
ReadParam(m_d_1_tpquan,"m_d_1_tpquan");
ReadParam( m_d_2_pianrs," m_d_2_pianrs");
ReadParam( m_d_2_piants," m_d_2_piants");
ReadParam( m_d_2_pianfr," m_d_2_pianfr");
ReadParam( m_d_2_pianh2o," m_d_2_pianh2o");
ReadParam( m_d_2_rswaittime," m_d_2_rswaittime");
ReadParam( m_d_2_tswaittime," m_d_2_tswaittime");
ReadParam( m_d_2_frwaittime," m_d_2_frwaittime");
ReadParam( m_d_1_piansamplewritex," m_d_1_piansamplewritex");
ReadParam( m_d_1_piansamplewritey," m_d_1_piansamplewritey");
ReadParam( m_d_1_samplewritez," m_d_1_samplewritez");
ReadParam( m_d_1_zilength," m_d_1_zilength");
ReadParam( m_d_1_ziwidth," m_d_1_ziwidth");
ReadParam( m_d_1_zige," m_d_1_zige");
ReadParam( m_d_1_piancheckx," m_d_1_piancheckx");
ReadParam( m_d_1_pianchecky," m_d_1_pianchecky");
ReadParam( m_d_1_piancheckz," m_d_1_piancheckz");
ReadParam( m_d_1_piansmearx," m_d_1_piansmearx");
ReadParam( m_d_1_piansmeary," m_d_1_piansmeary");
ReadParam( m_d_1_piansmearz," m_d_1_piansmearz");
ReadParam( m_d_1_smeark," m_d_1_smeark");
ReadParam( m_d_1_pianglasswritex," m_d_1_pianglasswritex");
ReadParam( m_d_1_pianglasswritey," m_d_1_pianglasswritey");
ReadParam( m_d_1_glasswritez," m_d_1_glasswritez");
ReadParam(m_d_2_frnum,"m_d_2_frnum");
ReadParam(m_d_2_tsnum,"m_d_2_tsnum");
ReadParam( m_d_1_tibi," m_d_1_tibi");
ReadParam(m_d_2_rsspraytime," m_d_2_rsspraytime");
ReadParam(m_d_2_tsspraytime," m_d_2_tsspraytime");
ReadParam(m_d_2_frspraytime," m_d_2_frspraytime");
}
void CMyTools::MachineHandAllZero()
{
	theApp.transfer.Lhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Zhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Yhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Xhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);


}
bool CMyTools::allhome(CDraw &rs)
{
	rs.jdt.SetJinDu(0,"正在软件上电");
	theApp.transfer.PowerOn();
	rs.jdt.SetJinDu(10,"正在回零机械手笔");
	theApp.transfer.Lhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	if(theApp.transfer.end)
		return false;

	rs.jdt.SetJinDu(20,"正在回零机械手Z轴");
	theApp.transfer.Zhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	if(!theApp.transfer.getPinMode(44))
	{
		ToFrontDoor();
		AfxMessageBox("机械手有笔或盖，请取下后重新初始化");
		rs.jdt.over();
		return false;
	}
	if(theApp.transfer.end)
		return false;
	rs.jdt.SetJinDu(30,"正在回零机械手Y轴");
	theApp.transfer.Yhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	if(theApp.transfer.end)
		return false;
	rs.jdt.SetJinDu(35,"正在回零机械手X轴");
	theApp.transfer.Xhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	if(theApp.transfer.end)
		return false;

    rs.jdt.SetJinDu(40,"正在回零加试剂X轴");
	theApp.transfer.Xhome(2);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	if(theApp.transfer.end)
		return false;
	rs.jdt.SetJinDu(50,"正在回零45度倾斜电机");
	theApp.transfer.Yhome(2);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(2,m_d_2_zeroCorrected);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	if(theApp.transfer.end)
		return false;
	theApp.transfer.Ymoveto(2,m_d_2_qinxie);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	if(theApp.transfer.end)
		return false;
	theApp.transfer.Ymoveto(2,m_d_2_zeroCorrected);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	rs.jdt.SetJinDu(55,"回零动作全部完成");
	return true;
}
void CMyTools::servoHome()
{
	theApp.transfer.Ymoveto(2,m_d_2_zeroCorrected);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
}
void CMyTools::WriteParam(long param,CString paramname)
{
	CString temp;
	temp.Format(_T("%d"),param);
	::WritePrivateProfileString(_T("Data"),paramname,temp,_T("./Param.ini"));
}
void CMyTools::ReadParam(long &param,CString paramname)
{
	param=::GetPrivateProfileInt("Data",paramname,0,"./Param.ini");
}
void CMyTools::LiquidSpray(int pin,long time)
{
	theApp.transfer.PullDown(pin);
	int delaytime=time/10;
	if(delaytime==0)
		delaytime=1;
	int i=0;
	while(i<delaytime)
	{
		i++;
		if(theApp.transfer.end||endflag)
		{
			theApp.transfer.PullUp(pin);
			break;
		} 
		Sleep(10);
	}
	theApp.transfer.PullUp(pin);
}
void CMyTools:: Write1(int num)
{
	if(num<0 || num>9)
		return;
	if( m_d_1_ziwidth==0 ||  m_d_1_zilength==0)
	{
		return;
	}
	int dxtime=10000;
	int dytime=10000;
	switch(num)
	{
	case 0:
		theApp.transfer.Ymove(1,m_d_1_zilength);
		theApp.transfer.DelayFinish(1,dytime);
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1,-m_d_1_zilength);
		theApp.transfer.DelayFinish(1,dytime);
		theApp.transfer.Xmove(1,m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		break;
	case 1:
		theApp.transfer.Ymove(1,m_d_1_zilength);
		theApp.transfer.DelayFinish(1,dytime);
		break;
	case 2:
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1,m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1,m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1,m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1,-m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		break;
	case 3:
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1,m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1,m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1, m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1, m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);

		break;
	case 4:
		theApp.transfer.Ymove(1,m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1, -m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Ymove(1,m_d_1_zilength);
		theApp.transfer.DelayFinish(1,dytime);
		break;
	case 5:

		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Xmove(1, m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1, m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1, m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1, m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		break;
	case 6:
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Xmove(1, m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1,m_d_1_zilength);
		theApp.transfer.DelayFinish(1,dytime);
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1, -m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1,m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		break;
	case 7:
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1, m_d_1_zilength);
		theApp.transfer.DelayFinish(1,dytime);
		break;
	case 8:
		theApp.transfer.Ymove(1,m_d_1_zilength);
		theApp.transfer.DelayFinish(1,dytime);
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1, -m_d_1_zilength);
		theApp.transfer.DelayFinish(1,dytime);
		theApp.transfer.Xmove(1, m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1,m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		break;
	case 9:
		theApp.transfer.Ymove(1, m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1, -m_d_1_zilength/2);
		theApp.transfer.DelayFinish(1,dytime/2);
		theApp.transfer.Xmove(1,m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Xmove(1, -m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);
		theApp.transfer.Ymove(1,m_d_1_zilength);
		theApp.transfer.DelayFinish(1,dytime);
		theApp.transfer.Xmove(1,m_d_1_ziwidth);
		theApp.transfer.DelayFinish(1,dxtime);

		break;

	}
	//tibi
}

void CMyTools::Write(int num,int x,int y,int z,int tibi)
{
	if(num<0||num>=1000)
		return;
	else
	{
		int len=(int)(log(1.0*num)/log(1.0*10))+1;
		switch(len)
		{
		case 1:
			theApp.transfer.Xmoveto(1,x- m_d_1_ziwidth);
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Ymoveto(1,y);
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Lmoveto(1,z);
			theApp.transfer.DelayFinish(1,60000);
			theApp.transfer.setYSpeedMode(1,2);
			Write1(num%10);

			break;
		case 2:
			theApp.transfer.Xmoveto(1,x- m_d_1_ziwidth/2);
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Ymoveto(1,y);
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Lmoveto(1,z);
			theApp.transfer.DelayFinish(1,60000);
			theApp.transfer.setYSpeedMode(1,2);
			Write1(num/10);
			num%=10;
			theApp.transfer.Lmove(1,-tibi);
			theApp.transfer.DelayFinish(1,10000);

			theApp.transfer.Xmoveto(1,x- m_d_1_ziwidth*3/2- m_d_1_zige);
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Ymoveto(1,y);
			theApp.transfer.DelayFinish(1,10000);
			theApp.transfer.Lmoveto(1,z);
			theApp.transfer.DelayFinish(1,20000);
			Write1(num);
			break;
		case 3:
			theApp.transfer.Xmoveto(1,x);
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Ymoveto(1,y);
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Lmoveto(1,z);
			theApp.transfer.DelayFinish(1,60000);
			theApp.transfer.setYSpeedMode(1,2);
			Write1(num/100);
			num%=100;
			theApp.transfer.Lmove(1,-tibi);
			theApp.transfer.DelayFinish(1,10000);
			theApp.transfer.Xmoveto(1,x-(m_d_1_ziwidth+ m_d_1_zige));
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Ymoveto(1,y);
			theApp.transfer.DelayFinish(1,10000);
			theApp.transfer.Lmoveto(1,z);
			theApp.transfer.DelayFinish(1,20000);
			Write1(num/10);
			num%=10;
			theApp.transfer.Lmove(1,-tibi);
			theApp.transfer.DelayFinish(1,10000);
			theApp.transfer.Xmoveto(1,x-( m_d_1_ziwidth+ m_d_1_zige)*2);
			theApp.transfer.DelayFinish(1,20000);
			theApp.transfer.Ymoveto(1,y);
			theApp.transfer.DelayFinish(1,10000);
			theApp.transfer.Lmoveto(1,z);
			theApp.transfer.DelayFinish(1,20000);
			Write1(num);
			break;
		}
		theApp.transfer.setYSpeedMode(1,0);
		theApp.transfer.Lmoveto(1,z*3/4);
		theApp.transfer.DelayFinish(1,20000);

	}
}
void CMyTools::Qingxi()
{
	theApp.transfer.Xhome(2);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	LiquidSpray(59,m_d_2_qingxih2o);


}
void CMyTools::SprayPenTou()
{
	theApp.mytools.LiquidSpray(57,m_d_2_rsQxptTime);
	theApp.mytools.LiquidSpray(56,m_d_2_tsQxptTime);
	theApp.mytools.LiquidSpray(55,m_d_2_frQxptTime);
	if(m_machineKind)
		theApp.mytools.LiquidSpray(54,m_d_2_glsmrQxptsprayTime);


}
void CMyTools::WashSj(int Num)
{
	int m_2_d_washpian=500;
	theApp.transfer.Ymoveto(2,m_d_2_qinxie);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);

	theApp.transfer.Xmoveto(2,sjpos[0]-m_2_d_washpian);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.PullDown(61);
	Sleep(500);

	for(int i=0;i<=Num-1;i++)
	{
		theApp.transfer.Xmoveto(2,sjpos[i]);
		theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
		Sleep(200);
	}
	theApp.transfer.Xmoveto(2,sjpos[Num-1]+m_2_d_washpian);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
		for(int i=Num-1;i>=0;i--)
	{
		theApp.transfer.Xmoveto(2,sjpos[i]);
		theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
		Sleep(200);
	}
	theApp.transfer.Xmoveto(2,sjpos[0]-m_2_d_washpian);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.PullUp(61);
	Sleep(m_d_2_homedelaytime);
	theApp.transfer.Xhome(2);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(2,m_d_2_zeroCorrected);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
}
void CMyTools::WashSjLast(int Num)
{
	int m_2_d_washpian=500;
	theApp.transfer.Ymoveto(2,m_d_2_qinxie);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.Xmoveto(2,sjpos[0]-m_2_d_washpian);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.PullDown(61);
	for(int i=0;i<=Num-1;i++)
	{
		theApp.transfer.Xmoveto(2,sjpos[i]);
		theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
		Sleep(200);
	}
	theApp.transfer.Xmoveto(2,sjpos[Num-1]+m_2_d_washpian);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	for(int i=Num-1;i>=0;i--)
	{
		theApp.transfer.Xmoveto(2,sjpos[i]);
		theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
		Sleep(200);
	}
	theApp.transfer.Xmoveto(2,sjpos[0]-m_2_d_washpian);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.PullUp(61);
	Sleep(m_d_2_homedelaytime);
	theApp.transfer.Xhome(2);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	IvSleep(10);
	theApp.transfer.Ymoveto(2,m_d_2_zeroCorrected);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(2,m_d_2_qinxie);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	IvSleep(2);
	theApp.transfer.Ymoveto(2,m_d_2_zeroCorrected);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
}
void  CMyTools::SampleInit()
{
	for(int i=0;i<10;i++)
		sample[i].init();
}
void  CMyTools::GlassInit()
{
	for(int i=0;i<10;i++)
		glass[i].init();
}
bool CMyTools::isSampleEmpty()
{
	for(int i=0;i<10;i++)
		if(sample[i].exist)
			return false;
	return true;

}
bool CMyTools::isGlassEmpty()
{
	for(int i=0;i<10;i++)
		if(glass[i].exist)
			return false;
	return true;


}
void CMyTools::IvSleep(long delaytime)
{
	int i=0;
	while(i<delaytime*10)
	{
		i++;
		if(theApp.transfer.end||endflag)
		{
			break;
		}
		Sleep(100);
	}
}
void CMyTools::IvSleep(long delaytime,CJinDuTiao &jdt,CString inst)
{
	int i=0;
	if(delaytime<=0)
		return;
	float perstep=1.0*delaytime/10;
	while(i<delaytime*10)
	{
		if(perstep<1)
			jdt.SetJinDu(int(i/perstep),inst);
		else
		{
			int perst=(int)perstep;
			if(i%(perst)==0)
				jdt.SetJinDu((int)(i/perstep),inst);

		}
			
		i++;
		if(theApp.transfer.end||endflag)
		{
			break;
		}
		Sleep(100);
	}
	jdt.over();

}
bool CMyTools::SampleFrameExist()
{
	theApp.transfer.Xmoveto(1,samplepos[0]+ m_d_1_piancheckx);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(1,m_d_1_sampley+ m_d_1_pianchecky);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Zmoveto(1,m_d_1_samplez+ m_d_1_piancheckz);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	if(!theApp.transfer.getPinMode(44))
	{
		Sleep(100);
		return !theApp.transfer.getPinMode(44);
	}
	else
	{
		return false;
	}
}
bool CMyTools::GlassFrameExist()
{
	theApp.transfer.Xmoveto(1,m_1_kggspeed);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(1,m_1_huanbiy);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Zmoveto(1,m_1_tpspeed);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	if(!theApp.transfer.getPinMode(44))
	{
		Sleep(100);
		return !theApp.transfer.getPinMode(44);
	}
	else
	{
		return false;
	}

}
bool  CMyTools::CheckSample(int Pos)
{
	theApp.transfer.Xmoveto(1,samplepos[Pos]+ m_d_1_piancheckx);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(1,m_d_1_sampley+ m_d_1_pianchecky);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Zmoveto(1,m_d_1_samplez+ m_d_1_piancheckz);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	if(!theApp.transfer.getPinMode(44))
	{
		Sleep(100);
		return !theApp.transfer.getPinMode(44);
	}
	else
	{
		return false;
	}
}
void CMyTools::ToFrontDoor()
{
	theApp.transfer.Yhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(1,m_d_1_glassy-9000);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Xhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Xmoveto(1,glasspos[9]);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);



}
void CMyTools::Huanbi()
{
	theApp.transfer.PowerOn();
	Sleep(500);
	theApp.transfer.Lhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Yhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Xhome(1);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Xmoveto(1,glasspos[9]);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(1,m_1_huanbiy);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Lmoveto(1,m_d_1_glasswritez/2);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Ymoveto(2,m_d_2_qinxie);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
}
void CMyTools::WriteSample(int Pos,int Num)
{
	if(Pos>=0 && Pos<=9 && Num>0 && Num<1000)
		//theApp.mytools.Write(Num,samplepos[Pos]+ m_d_1_piansamplewritex,m_d_1_sampley+ m_d_1_piansamplewritey,m_d_1_samplewritez,m_d_1_tibi);
	{
		theApp.transfer.Xmoveto(1,samplepos[Pos]+ m_d_1_piansamplewritex);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_sampley+ m_d_1_piansamplewritey);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Lmoveto(1,m_d_1_samplewritez);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.setXSpeedMode(1,2);
		theApp.transfer.setYSpeedMode(1,2);
		theApp.transfer.SendCmd(1,19,Num);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.setXSpeedMode(1,0);
		theApp.transfer.setYSpeedMode(1,0);
	}
}
void  CMyTools::WriteGlass(int Pos,int Num)
{
	if(Pos>=0 && Pos<=9 && Num>0 && Num<1000)
	//	theApp.mytools.Write(Num,glasspos[Pos]+ m_d_1_pianglasswritex,m_d_1_glassy+ m_d_1_pianglasswritey,m_d_1_glasswritez,m_d_1_tibi);
	{
		theApp.transfer.Xmoveto(1,glasspos[Pos]+ m_d_1_pianglasswritex);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Ymoveto(1,m_d_1_glassy+ m_d_1_pianglasswritey);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.Lmoveto(1,m_d_1_glasswritez);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.setXSpeedMode(1,2);
		theApp.transfer.setYSpeedMode(1,2);
		theApp.transfer.SendCmd(1,19,Num);
		theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
		theApp.transfer.setXSpeedMode(1,0);
		theApp.transfer.setYSpeedMode(1,0);
	}
		

}
bool  CMyTools::Kaigai(int Pos)
{
	theApp.transfer.Xmoveto(1,samplepos[Pos]);
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
		return false;
	}
	else
	{
		if(theApp.transfer.getPinMode(44))
			return false;
		else
		{
			if(theApp.transfer.getPinMode(42))//当开盖保护无 光纤信号有时，防止回零过程被开盖保护打断，但开盖成功（阻力较小，回弹），回零没完成现象
			{
				theApp.transfer.Zhome(1);
				theApp.transfer.DelayFinish(1,20000);

			}
			return true;
		}
	}

}
bool  CMyTools::Guangai(int Pos)
{
	theApp.transfer.Ymoveto(1,m_d_1_sampley);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Xmoveto(1,samplepos[Pos]);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	theApp.transfer.Zmoveto(1,m_d_1_samplez);
	theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
	//theApp.transfer.UnionMove(1,0,0, m_d_1_kgdown, -m_d_1_kgzhuan,0,1);
	//theApp.transfer.DelayFinish(1,20000);
	//theApp.transfer.UnionMove(1,0,0,- m_d_1_kgdown,-m_d_1_kgzhuan,0,1);
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
		return false;
	}
	else
	{
		if(!theApp.transfer.getPinMode(44))
			return false;
		else
			return true;
	}

}
void  CMyTools::Motan(int Pos)
{
	theApp.transfer.Zmoveto(1, m_d_1_samplez+m_d_1_piansmearz-2000);
	theApp.transfer.DelayFinish(1,10000);
	theApp.transfer.Xmoveto(1, samplepos[Pos]+m_d_1_piansmearx);
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
void  CMyTools::Tupian(int Pos)
{
	theApp.transfer.Xmoveto(1,glasspos[Pos]);
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
void  CMyTools::JAO(int Pos)
{
	theApp.transfer.Xmoveto(2,sjpos[Pos]+ m_d_2_pianrs);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.mytools.LiquidSpray(57,m_d_2_rsspraytime);

}
void  CMyTools::HCL(int Pos)
{
	theApp.transfer.Xmoveto(2,sjpos[Pos]+ m_d_2_piants);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.mytools.LiquidSpray(56,m_d_2_tsspraytime);

}
void  CMyTools::KMNO4(int Pos)
{
	theApp.transfer.Xmoveto(2,sjpos[Pos]+ m_d_2_pianfr);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.mytools.LiquidSpray(55,m_d_2_frspraytime);
}
void CMyTools::MEIRAN(int Pos)
{
	theApp.transfer.Xmoveto(2,sjpos[Pos]+ m_d_2_pianmr);
	theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
	theApp.mytools.LiquidSpray(54,m_d_2_glsmrsprayTime);

}
void CMyTools::GDJ()
{
	theApp.mytools.LiquidSpray(54,m_d_2_gdjspraytime);
}
void CMyTools::AlertVoice()
{
	theApp.transfer.PullDown(28);
	Sleep(3000);
	theApp.transfer.PullUp(28);
}
