// TPJ10.cpp : 实现文件
//

#include "stdafx.h"
#include "UNITCHECK.h"
#include "TPJ10.h"
#include "TPJ10Test.h"
#include "MyTimer.h"
#include "MyInput.h"

const Color glassColor[6]={Color(128,100,100,100),Color(128,150,150,150),Color(128,200,200,200),Color(128,250,250,0),Color(128,150,150,150),Color(128,250,0,250)};
const Color glsglassColor[7]={Color(128,100,100,100),Color(128,150,150,150),Color(128,200,200,200),Color(128,250,0,255),Color(128,150,150,150),Color(128,250,0,0),Color(128,250,255,0)};
DWORD WINAPI ExitProc(LPVOID param);
DWORD WINAPI UIThread(LPVOID param)
{
	CTPJ10 *pDlg=(CTPJ10 *)param;
	int tims=0;
	while(!theApp.mytools.endflag)
	{
		if(pDlg->rs.m_input.InPutOver && !pDlg->rs.m_input.beenget) //调用编号标志位
		{
			int temp=0;
			temp=pDlg->rs.m_input.GetNum();
			if(temp!=0)
			{
				theApp.mytools.samplecount=temp;
			}
			pDlg->rs.m_input.beenget=true;
		}
		for(int i=0;i<10;i++)
		{
			if(theApp.mytools.isSampleEmpty())
			{
				pDlg->rs.m_jiazi.HuiZhi=false;
			}
			else
			{
				pDlg->rs.m_jiazi.HuiZhi=true;

				if(theApp.mytools.sample[i].exist)
				{
					pDlg->rs.m_jiazi.Exist[i]=true;
					pDlg->rs.m_jiazi.num[i]=theApp.mytools.sample[i].num;

				}
				else
				{
					pDlg->rs.m_jiazi.Exist[i]=false;
					pDlg->rs.m_jiazi.num[i]=0;
				}
			}
			if(!theApp.mytools.isGlassEmpty())
			{
				for(int i=0;i<10;i++)
				{
					if(theApp.mytools.glass[i].exist)
					{
						pDlg->rs.m_bopian[i].HuiZhi=true;
						pDlg->rs.m_bopian[i].num=theApp.mytools.glass[i].num;
						if(theApp.mytools.glass[i].state<2)
						{
							pDlg->rs.m_bopian[i].INNER=false;

						}
						else
						{
							pDlg->rs.m_bopian[i].INNER=true;

						}
						pDlg->rs.m_bopian[i].SetInner(theApp.mytools.m_machineKind?glsglassColor[theApp.mytools.glass[i].state]:glassColor[theApp.mytools.glass[i].state]);

					}
					else
					{
						pDlg->rs.m_bopian[i].HuiZhi=false;

					}
				}
			}
			else
			{
				for(int i=0;i<10;i++)
				{
					pDlg->rs.m_bopian[i].HuiZhi=false;

				}

			}

		}
		if(!theApp.transfer.getPinMode(62))
		{
			if(!pDlg->rs.HCL.warning)
			{
				pDlg->rs.HCL.SetWarningOn();
				theApp.mytools.AlertVoice();
				theApp.mytools.m_d_2_hclpraynum=theApp.mytools.m_d_2_hclcanpray*0.8;
				theApp.mytools.WriteParam(theApp.mytools.m_d_2_hclpraynum,"m_d_2_hclpraynum");
				pDlg->rs.HCL.SetLiang(1.0*theApp.mytools.m_d_2_hclpraynum/theApp.mytools.m_d_2_hclcanpray);
			}

		}
		else
		{
			if(pDlg->rs.HCL.warning)
			{
				pDlg->rs.HCL.SetWarningOff();
				theApp.mytools.m_d_2_hclpraynum=0;
				theApp.mytools.WriteParam(theApp.mytools.m_d_2_hclpraynum,"m_d_2_hclpraynum");
				pDlg->rs.HCL.SetLiang(0);
			}
		}
		if(!theApp.transfer.getPinMode(63))
		{
			if(!pDlg->rs.KMNO4.warning)
			{
				pDlg->rs.KMNO4.SetWarningOn();
				theApp.mytools.AlertVoice();
				theApp.mytools.m_d_2_kmnopraynum=theApp.mytools.m_d_2_kmnocanpray*0.8;
				theApp.mytools.WriteParam(theApp.mytools.m_d_2_kmnopraynum,"m_d_2_kmnopraynum");
				pDlg->rs.KMNO4.SetLiang(1.0*theApp.mytools.m_d_2_kmnopraynum/theApp.mytools.m_d_2_kmnocanpray);
			}


		}
		else
		{
			if(pDlg->rs.KMNO4.warning)
			{
				pDlg->rs.KMNO4.SetWarningOff();
				theApp.mytools.m_d_2_kmnopraynum=0;
				theApp.mytools.WriteParam(theApp.mytools.m_d_2_kmnopraynum,"m_d_2_kmnopraynum");
				pDlg->rs.KMNO4.SetLiang(0);
			}

		}


		if(!theApp.transfer.getPinMode(64))
		{
			if(!pDlg->rs.JAO.warning)
			{
				pDlg->rs.JAO.SetWarningOn();
				theApp.mytools.AlertVoice();
				theApp.mytools.m_d_2_jaopraynum=theApp.mytools.m_d_2_jaocanpray*0.8;
				theApp.mytools.WriteParam(theApp.mytools.m_d_2_jaopraynum,"m_d_2_jaopraynum");
				pDlg->rs.JAO.SetLiang(1.0*theApp.mytools.m_d_2_jaopraynum/theApp.mytools.m_d_2_jaocanpray);
			}

		}
		else
		{
			if(pDlg->rs.JAO.warning)
			{
				pDlg->rs.JAO.SetWarningOff();
				theApp.mytools.m_d_2_jaopraynum=0;
				theApp.mytools.WriteParam(theApp.mytools.m_d_2_jaopraynum,"m_d_2_jaopraynum");
				pDlg->rs.JAO.SetLiang(0);
			}


		}
		if(!theApp.transfer.getPinMode(29))
		{
			if(!pDlg->rs.NH4OH.warning)
			{
				pDlg->rs.NH4OH.SetWarningOn();
				theApp.mytools.AlertVoice();
				theApp.mytools.m_d_2_gdjpraynum=theApp.mytools.m_d_2_gdjcanpray;
				theApp.mytools.WriteParam(theApp.mytools.m_d_2_gdjpraynum,"m_d_2_gdjpraynum");
				pDlg->rs.NH4OH.SetLiang(1.0*theApp.mytools.m_d_2_gdjpraynum/theApp.mytools.m_d_2_gdjcanpray);
			}

		}
		else
		{
			if(pDlg->rs.NH4OH.warning)
			{
				pDlg->rs.NH4OH.SetWarningOff();
				theApp.mytools.m_d_2_gdjpraynum=0;
				theApp.mytools.WriteParam(theApp.mytools.m_d_2_gdjpraynum,"m_d_2_gdjpraynum");
				pDlg->rs.NH4OH.SetLiang(0);
			}


		}
		//if(theApp.mytools.needjy)
		//{
		//	if(shutdowntimer.delay())
		//	{
		//		CreateThread(NULL,0,ExitProc,param,0,NULL);

		//	}
		//}
		//else
		//{
		//	shutdowntimer.clear();

		//}

		pDlg->Invalidate(FALSE);
		Sleep(40);


	}

	return -1;


}
DWORD WINAPI MainThread(LPVOID param)
{
	CTPJ10 *pDlg=(CTPJ10 *)param;
	int tims=0;
	CMyTimer timer_prehot(theApp.mytools.m_1_d_preHotMaxTime*1000);
	CMyTimer timer_beforeTp(theApp.mytools.m_1_d_minTimeBeforeTp*1000);
	bool initCloseHot=false;  //是否需要初始化长时间不操作关加热块
	while(!theApp.mytools.endflag)
	{
		if(initCloseHot)
		{
			if(timer_prehot.delay())
			{
				theApp.transfer.PullUp(30);
				initCloseHot=false;
			}

		}
		if(theApp.mytools.needhome)
		{
			if(theApp.mytools.allhome(pDlg->rs))
			{
				if(theApp.mytools.m_machineKind==0)
					theApp.mytools.GDJ();
				theApp.mytools.homedone=true;
				theApp.mytools.needhome=false;

				theApp.transfer.PullDown(32);//风扇
				theApp.transfer.PullDown(30);//加热
				initCloseHot=true;


				int prehot_num=0;
				int prehot_time=theApp.mytools.m_1_d_preHotTime;
				if(prehot_time==0)
					prehot_time=180;
				double stepchange=1.0*prehot_time*10/40;
				if(stepchange<1)
					stepchange=1;
				while(prehot_num<prehot_time*10)
				{
					if(theApp.transfer.end||theApp.mytools.endflag)
						break;
					prehot_num++;
					if(prehot_num%(int)stepchange==0)
						pDlg->rs.jdt.SetJinDu(60+prehot_num/stepchange,"正在预热加热块到指定温度");
					if(60+prehot_num/stepchange>100)
						int a=100;
					Sleep(100);

				}

				pDlg->rs.jdt.SetJinDu(100,"初始化完成");
				Sleep(1000);
				pDlg->rs.jdt.over();
				pDlg->rs.m_toolbar[1].Enable(true);
				timer_prehot.start();

			}
			else
			{
				theApp.mytools.needhome=false;
				pDlg->rs.m_toolbar[0].Enable(true);

			}
		}

		if(theApp.mytools.needjy && theApp.mytools.homedone)
		{
			initCloseHot=false;
			timer_prehot.clear();
			bool sampleexist=false;
			bool glassexist=false;
			//		sampleexist=theApp.mytools.SampleFrameExist();
			//		glassexist=theApp.mytools.GlassFrameExist();
			theApp.mytools.MachineHandAllZero();

			if(true/*sampleexist  && glassexist*/)//检测盒架都有
				//if(!theApp.transfer.getPinMode(31)||!theApp.transfer.getPinMode(33))
			{
				theApp.mytools.SampleInit();
				theApp.mytools.GlassInit();

				for(int i=0;i<10;i++)
				{
					pDlg->rs.m_jiazi.state[i]=0;
				}
				int sampleNum=0;
				//*******************************进样检测
				theApp.transfer.PullDown(30);//加热

				timer_beforeTp.start();//timer_beforeTp计时器开始
				if(theApp.mytools.m_methodKind==0)//涂染模式  进样检测 写样本 玻片字
				{

					for(int i=0;i<10;i++)
					{
						if(theApp.mytools.CheckSample(i))
						{
							sampleNum++;
							theApp.mytools.sample[i].exist=true;
							theApp.mytools.sample[i].num=theApp.mytools.samplecount+i;
							theApp.mytools.sample[i].state=0;
						}
						else
						{
							break;
						}

					}
					theApp.mytools.samplecount+=sampleNum;
					theApp.mytools.MachineHandAllZero();
					if(theApp.mytools.isSampleEmpty())
					{
						AfxMessageBox("标本架为空，请放入标本盒再进样",MB_SYSTEMMODAL);
						theApp.mytools.needjy=false;
						pDlg->rs.m_toolbar[1].Enable(true);
						continue;
					}

					//*******************************写盒

					for(int i=0;i<10;i++)
					{
						if(theApp.mytools.sample[i].exist)
						{
							theApp.mytools.WriteSample(i,theApp.mytools.sample[i].num);
							theApp.mytools.sample[i].state=1;
						}
						else
							break;
					}
					theApp.mytools.MachineHandAllZero();
					//*******************************写玻片
					for(int i=0;i<10;i++)
					{
						if(theApp.mytools.sample[i].exist)
						{
							theApp.mytools.WriteGlass(i,theApp.mytools.sample[i].num);
							theApp.mytools.glass[i].exist=true;
							theApp.mytools.glass[i].state=1;
							theApp.mytools.glass[i].num=theApp.mytools.sample[i].num;

						}
						else
							break;
					}
					theApp.mytools.MachineHandAllZero();
				}

				if(theApp.mytools.m_methodKind==0)//涂染模式 涂片
				{
					long timeleft=timer_beforeTp.get_time_left()/1000;
					timer_beforeTp.clear();


					if(timeleft>0)
						theApp.mytools.IvSleep(theApp.mytools.m_d_2_glassgdtime,pDlg->rs.jdt,"正在等待玻片加热到指定温度");

					//*******************************涂片
					for(int  i=0;i<10;i++)
					{
						if(theApp.mytools.sample[i].exist)
						{
							int retry_num=0;
							int retry_max=3;
							while(retry_num<retry_max)
							{
								if(!theApp.mytools.Kaigai(i))
								{
									retry_num++;

								}
								else
									break;
							}
							if(retry_num==3)
							{
								pDlg->rs.m_jiazi.state[i]=1;
								continue;
							}
							//motan
							int mtnum=pDlg->imageProcess();
							if(mtnum>0)
							{
								for(int j=0;j<mtnum;j++)
									theApp.mytools.Motan(i);
							}
							theApp.mytools.Tupian(i);
							theApp.mytools.glass[i].state=2;
							theApp.mytools.sample[i].state=2;
							retry_num=0;
							while(retry_num<retry_max)
							{
								if(!theApp.mytools.Guangai(i))
								{
									retry_num++;

								}
								else
									break;
							}
							if(retry_num==3)
							{
								theApp.transfer.Zhome(1);
								theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
								theApp.transfer.Xmoveto(1,theApp.mytools.glasspos[10]);
								theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
								theApp.transfer.Ymoveto(1,theApp.mytools.m_d_1_glassy);
								theApp.transfer.DelayFinish(1,MAX_DELAY_TIME);
								while(!theApp.transfer.getPinMode(44))
								{
									AfxMessageBox("关盖不成功，请手动关盖后点确定继续涂片",MB_SYSTEMMODAL);
								}
							}

						}
						else
							break;
					}

					theApp.mytools.MachineHandAllZero();

					theApp.transfer.Yhome(2);
					theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
					theApp.transfer.Ymoveto(2,theApp.mytools.m_d_2_zeroCorrected);
					theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);

				}

				if(theApp.mytools.m_methodKind==1)  //染色模式初始化玻片值 默认10个  编号 1-10
				{
					sampleNum=10;
					CMyInput input;
					if(IDOK==input.DoModal())
					{
						sampleNum=input.glassNum;
					}


					for(int i=0;i<sampleNum;i++)
					{
						theApp.mytools.glass[i].exist=true;
						theApp.mytools.glass[i].num=i+1;
						theApp.mytools.glass[i].state=2;

					}

					long timeleft=timer_beforeTp.get_time_left()/1000;
					timer_beforeTp.clear();


					if(timeleft>0)
						theApp.mytools.IvSleep(theApp.mytools.m_d_2_glassgdtime,pDlg->rs.jdt,"正在等待玻片加热到指定温度");
					
				}
				theApp.transfer.PullUp(30);//加热
                


				theApp.mytools.IvSleep(theApp.mytools.m_d_2_glassgdtime,pDlg->rs.jdt,"正在等待涂片固定");



				//*******************************染色
				theApp.mytools.SprayPenTou();
				for(int i=0;i<10;i++)
				{
					if(theApp.mytools.glass[i].exist && pDlg->rs.m_jiazi.state[i]!=1)
					{
						theApp.mytools.JAO(i);
						theApp.mytools.glass[i].state=3;
						theApp.mytools.m_d_2_jaopraynum++;
						theApp.mytools.WriteParam(theApp.mytools.m_d_2_jaopraynum,"m_d_2_jaopraynum");
						pDlg->rs.JAO.SetLiang(1.0*theApp.mytools.m_d_2_jaopraynum/theApp.mytools.m_d_2_jaocanpray);
					}
				}
				Sleep(theApp.mytools.m_d_2_homedelaytime);
				theApp.transfer.Xhome(2);
				theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);

				theApp.mytools.IvSleep(theApp.mytools.m_d_2_rswaittime,pDlg->rs.jdt,"正在等待染色完成");
				for(int i=0;i<theApp.mytools.m_d_2_rsWashTimes;i++)
				{
					theApp.mytools.WashSj(sampleNum);
				}

				//********************************媒染 卢戈氏碘液
				if(theApp.mytools.m_machineKind)
				{
					for(int t=0;t<theApp.mytools.m_d_2_glsmrNum;t++)
					{

						for(int i=0;i<10;i++)
						{
							if(theApp.mytools.glass[i].exist && pDlg->rs.m_jiazi.state[i]!=1)
							{
								theApp.mytools.MEIRAN(i);
								theApp.mytools.m_d_2_gdjpraynum++;
								theApp.mytools.WriteParam(theApp.mytools.m_d_2_gdjpraynum,"m_d_2_gdjpraynum");
								pDlg->rs.NH4OH.SetLiang(1.0*theApp.mytools.m_d_2_gdjpraynum/theApp.mytools.m_d_2_gdjcanpray);
								theApp.mytools.glass[i].state=6;
							}
						}
						Sleep(theApp.mytools.m_d_2_homedelaytime);
						theApp.transfer.Xhome(2);
						theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);

						if(t==0)
							theApp.mytools.IvSleep(theApp.mytools.m_d_2_glsmrwaitTime,pDlg->rs.jdt,"正在等待媒染完成");
						else
						{
							CString temp;
							temp.Format("正在等待第%d遍媒染完成",t+1);
							theApp.mytools.IvSleep(theApp.mytools.m_d_2_tswaittime,pDlg->rs.jdt,temp);
						}
						for(int i=0;i<theApp.mytools.m_d_2_glsmrWashNum;i++)
						{
							theApp.mytools.WashSj(sampleNum);
						}
					}

				}

				//*******************************脱色
				for(int t=0;t<theApp.mytools.m_d_2_tsnum;t++)
				{
					if(!theApp.mytools.m_machineKind)
					{
					theApp.mytools.GDJ();
					theApp.mytools.m_d_2_gdjpraynum++;
					theApp.mytools.WriteParam(theApp.mytools.m_d_2_gdjpraynum,"m_d_2_gdjpraynum");
					pDlg->rs.NH4OH.SetLiang(1.0*theApp.mytools.m_d_2_gdjpraynum/theApp.mytools.m_d_2_gdjcanpray);
					}

					for(int i=0;i<10;i++)
					{
						if(theApp.mytools.glass[i].exist && pDlg->rs.m_jiazi.state[i]!=1)
						{
							theApp.mytools.HCL(i);
							theApp.mytools.m_d_2_hclpraynum++;
							theApp.mytools.WriteParam(theApp.mytools.m_d_2_hclpraynum,"m_d_2_hclpraynum");
							pDlg->rs.HCL.SetLiang(1.0*theApp.mytools.m_d_2_hclpraynum/theApp.mytools.m_d_2_hclcanpray);
							theApp.mytools.glass[i].state=4;
						}
					}
					Sleep(theApp.mytools.m_d_2_homedelaytime);
					theApp.transfer.Xhome(2);
					theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);

					if(t==0)
						theApp.mytools.IvSleep(theApp.mytools.m_d_2_tswaittime,pDlg->rs.jdt,"正在等待脱色完成");
					else
					{
						CString temp;
						temp.Format("正在等待第%d遍脱色完成",t+1);
						theApp.mytools.IvSleep(theApp.mytools.m_d_2_tswaittime,pDlg->rs.jdt,temp);
					}
					for(int i=0;i<theApp.mytools.m_d_2_tsWashTimes;i++)
					{
						theApp.mytools.WashSj(sampleNum);
					}
				}
				//*******************************复染
				for(int t=0;t<theApp.mytools.m_d_2_frnum;t++)
				{
					for(int i=0;i<10;i++)
					{
						if(theApp.mytools.glass[i].exist && pDlg->rs.m_jiazi.state[i]!=1)
						{
							theApp.mytools.KMNO4(i);
							theApp.mytools.glass[i].state=5;
							theApp.mytools.m_d_2_kmnopraynum++;
							theApp.mytools.WriteParam(theApp.mytools.m_d_2_kmnopraynum,"m_d_2_kmnopraynum");
							pDlg->rs.KMNO4.SetLiang(1.0*theApp.mytools.m_d_2_kmnopraynum/theApp.mytools.m_d_2_kmnocanpray);
						}
					}
					Sleep(theApp.mytools.m_d_2_homedelaytime);
					theApp.transfer.Xhome(2);
					theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
					if(t==0)
						theApp.mytools.IvSleep(theApp.mytools.m_d_2_frwaittime,pDlg->rs.jdt,"正在等待复染完成");
					else
					{
						CString temp;
						temp.Format("正在等待第%d遍复染完成",t+1);
						theApp.mytools.IvSleep(theApp.mytools.m_d_2_frwaittime,pDlg->rs.jdt,temp);
					}
					for(int i=0;i<theApp.mytools.m_d_2_frWashTimes-1;i++)
					{
						theApp.mytools.WashSj(sampleNum);
					}
					if(t==theApp.mytools.m_d_2_frnum)
						theApp.mytools.WashSjLast(sampleNum);
					else
						theApp.mytools.WashSj(sampleNum);
				}
				theApp.mytools.Qingxi();
				theApp.mytools.AlertVoice();
				AfxMessageBox("已涂片完成，请取出标本架及玻片架",MB_SYSTEMMODAL);
				pDlg->rs.radio.setEnable(true);
				theApp.mytools.SampleInit();
				theApp.mytools.GlassInit();
				theApp.mytools.needjy=false;
				pDlg->rs.m_toolbar[1].Enable(true);

			}
			else
			{
				AfxMessageBox("未检测到玻片架或标本盒，请放入玻片架和标本盒",MB_SYSTEMMODAL);
			}


		}








		Sleep(2);

	}

	return -1;


}

// CTPJ10 对话框

IMPLEMENT_DYNAMIC(CTPJ10, CDialog)

CTPJ10::CTPJ10(CWnd* pParent /*=NULL*/)
: CDialog(CTPJ10::IDD, pParent)
{
	px=::GetPrivateProfileInt(_T("PHO"),_T("px"),0,_T(".\\PHO.ini"));
	py=::GetPrivateProfileInt(_T("PHO"),_T("py"),0,_T(".\\PHO.ini"));
	px2=::GetPrivateProfileInt(_T("PHO"),_T("px2"),0,_T(".\\PHO.ini"));
	py2=::GetPrivateProfileInt(_T("PHO"),_T("py2"),0,_T(".\\PHO.ini"));
	huidu=::GetPrivateProfileInt(_T("PHO"),_T("huidu"),0,_T(".\\PHO.ini"));
	Fix=::GetPrivateProfileInt(_T("PHO"),_T("Fix"),0,_T(".\\PHO.ini"));
	FixMax=::GetPrivateProfileInt(_T("PHO"),_T("FixMax"),0,_T(".\\PHO.ini"));
	FixMin=::GetPrivateProfileInt(_T("PHO"),_T("FixMin"),0,_T(".\\PHO.ini"));
	PhotoT=0;

}

CTPJ10::~CTPJ10()
{
	delete m_p;
}

void CTPJ10::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTPJ10, CDialog)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_HOTKEY,&CTPJ10::OnHotKey)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CTPJ10 消息处理程序

void CTPJ10::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	CRect rc;
	GetClientRect(&rc);
	CDC mem_dc;
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc,rc.Width(),rc.Height());
	mem_dc.CreateCompatibleDC(&dc);
	mem_dc.SelectObject(&bitmap);
	Graphics g(mem_dc);
	rs.Draw(g);

	dc.BitBlt(0,0,rc.Width(),rc.Height(),&mem_dc,0,0,SRCCOPY);
	mem_dc.DeleteDC();
	CDialog::OnPaint();
}
int  CTPJ10::imageProcess()
{
	int mtnum=0;
	//下跟图像处理过程，产生 mtnum和tpnum值

	PhotoT++;
	CString str;
	str.Format(_T(".\\res\\capture\\%d.jpg"),PhotoT);
	m_p->TakePhoto(0,str);
	Sleep(200);
	int bc=PhotoTest(str);
	if(bc==3)
		mtnum=2;
	else if(bc==2)
		mtnum=1;
	else
		mtnum=0;
	return mtnum;

}
int  CTPJ10::PhotoTest(CString str)
{
	COLORREF color;
	int num=0;
	int gy=0;
	int nred=0;
	CImage Myimg;
	Myimg.Load(str);

	float v,h,s,minv,hp;
	if(!Myimg.IsNull())
	{
		for(int i=px;i<px2;i++)
		{
			for (int j=py;j<py2;j++)
			{
				color=Myimg.GetPixel(i,j);
				v=max(max(GetRValue(color),GetGValue(color)),GetBValue(color));
				minv=min(min(GetRValue(color),GetGValue(color)),GetBValue(color));
				s=(v-minv)/v;
				if (v!=minv)
				{
					if (v==GetRValue(color))
					{
						hp=(GetGValue(color)-GetBValue(color))/(v-minv);
					}
					if (v==GetGValue(color))
					{
						hp=2+(GetBValue(color)-GetRValue(color))/(v-minv);
					}
					if (v==GetBValue(color))
					{
						hp=4+(GetRValue(color)-GetGValue(color))/(v-minv);
					}
					if (hp>=0)
					{
						h=hp*60;
					}
					else
					{
						h=hp*60+360;
					}
				}
				else
				{
					h=-1;
				}

				if(h>80&&h<160&&s>0.2)//
				{
				}
				else
				{
					if ((h>0&&h<45)||(h>270))//hongse
					{
						nred++;
					}
					gy=(GetRValue(color)*30+GetGValue(color)*59+GetBValue(color)*11+50)/100;
					if(gy>120)
					{
						num++;
					}


				}
			}
		}
	}
	else
	{
		return 0;
	}
	if (nred>FixMin)
	{
		return 3;
	}
	if (num>FixMax)
	{
		return 3;
	}
	if (num>Fix)
	{
		return 2;
	}
	if (num>FixMin)
	{
		return 1;
	}

	return 0;
}

BOOL CTPJ10::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	RegisterHotKey(GetSafeHwnd(),WM_HOTKEY1,MOD_CONTROL|MOD_SHIFT,'F');
	RegisterHotKey(GetSafeHwnd(),WM_HOTKEY2,MOD_CONTROL|MOD_SHIFT,'P');
	RegisterHotKey(GetSafeHwnd(),WM_HOTKEY3,MOD_CONTROL|MOD_SHIFT,'V');

	/*
	for(int i=0;i<10;i++)
	{
	theApp.mytools.glass[i].exist=true;
	theApp.mytools.glass[i].num=i+1;
	theApp.mytools.glass[i].state=(i)%6;
	rs.SetShiningOn(i);


	}
	for(int i=0;i<6;i++)
	{
	theApp.mytools.sample[i].exist=true;
	theApp.mytools.sample[i].num=i+1;
	theApp.mytools.sample[i].state=(i)%3;

	}
	*/
	MoveWindow(0,0,1280, 800);
	m_p= new CPhoto(this);
	m_p->Create(IDD_PHOTO,this);
	m_p->ShowWindow(SW_HIDE);
	CRect rc;
	GetClientRect(&rc);
	rs.SetRc(rc);
	rs.HCL.SetLiang(1.0*theApp.mytools.m_d_2_hclpraynum/theApp.mytools.m_d_2_hclcanpray);
	rs.JAO.SetLiang(1.0*theApp.mytools.m_d_2_jaopraynum/theApp.mytools.m_d_2_jaocanpray);
	rs.KMNO4.SetLiang(1.0*theApp.mytools.m_d_2_kmnopraynum/theApp.mytools.m_d_2_kmnocanpray);
	rs.NH4OH.SetLiang(1.0*theApp.mytools.m_d_2_gdjpraynum/theApp.mytools.m_d_2_gdjcanpray);
	rs.radio.setState(theApp.mytools.m_methodKind);
	mypdlg=new CPWDDlg(this);
	mypdlg->Create(IDD_DIALOG1,this);
	mypdlg->MoveWindow(500,300,300,150);
	mypdlg->ShowWindow(SW_HIDE);
	CreateThread(NULL,0,UIThread,this,0,NULL);
	CreateThread(NULL,0,MainThread,this,0,NULL);
	theApp.transfer.start();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
DWORD WINAPI SHIJIOpen(LPVOID param)
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
DWORD WINAPI ExitProc(LPVOID param)
{
	CTPJ10 *pDlg=(CTPJ10 *)param;



	theApp.transfer.PullDown(34);
	theApp.mytools.IvSleep(theApp.mytools.m_d_xiaodutime,pDlg->rs.jdt,"正在整机消毒");
	theApp.transfer.PullUp(34);
	Sleep(50);
	theApp.transfer.PowerOff();
	theApp.transfer.stop();
	Sleep(500);
	theApp.RunCmd("devcon disable \"USB\\VID_2341*\"",true);
	WinExec("shutdown -s -t 5 -c \"即将自动关闭电脑，请在显示器关闭后关闭机器电源\"",SW_HIDE);
	pDlg->PostMessage(WM_CLOSE,NULL,NULL);
	return 1;

}
void CTPJ10::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (rs.m_toolbar[0].SetState(point))
	{
		rs.Zanting = false;
		rs.m_toolbar[0].Enable(false);
		theApp.mytools.needhome=true;
		rs.m_toolbar[6].Enable(false);

	}
	if (rs.m_toolbar[1].SetState(point))
	{
		if(!theApp.transfer.getPinMode(29))
		{
			if(!theApp.mytools.m_machineKind)
			{
			AfxMessageBox("涂片缓冲液缺少，请更换后点确认。",MB_SYSTEMMODAL);
			theApp.mytools.GDJ();
			theApp.mytools.GDJ();
			AfxMessageBox("请重新进样",MB_SYSTEMMODAL);
			return;
			}
			else
			{
				AfxMessageBox("媒染剂缺少，请更换后点确认。",MB_SYSTEMMODAL);
				AfxMessageBox("请重新进样",MB_SYSTEMMODAL);
			}

		}
		if(!theApp.transfer.getPinMode(62))
		{
			AfxMessageBox("脱色剂缺少，请更换后点确认。",MB_SYSTEMMODAL);
			AfxMessageBox("请重新进样",MB_SYSTEMMODAL);
			return;

		}
		if(!theApp.transfer.getPinMode(63))
		{
			AfxMessageBox("复染剂剂缺少，请更换后点确认。",MB_SYSTEMMODAL);
			AfxMessageBox("请重新进样",MB_SYSTEMMODAL);
			return;

		}
		if(!theApp.transfer.getPinMode(64))
		{
			AfxMessageBox("染色剂缺少，请更换后点确认。",MB_SYSTEMMODAL);
			AfxMessageBox("请重新进样",MB_SYSTEMMODAL);
			return;

		}
		rs.m_toolbar[1].Enable(false);
		rs.m_toolbar[4].Enable(false);
		rs.radio.setEnable(false);
		theApp.mytools.needjy=true;

	}
	if (rs.m_toolbar[2].SetState(point))
	{
		rs.Zanting = !rs.Zanting;
		if(!rs.Zanting)
		{
			theApp.transfer.restart();
			rs.m_toolbar[2].SetShow("暂停");
		}
		else
		{
			theApp.transfer.pause();
			rs.m_toolbar[2].SetShow("重启");
		}
	}
	if (rs.m_toolbar[3].SetState(point))
	{
		//调出测试程序。
		rs.m_toolbar[3].Enable(false);
		CTPJ10Test dlg;
		dlg.SetOwner(this);
		ShowWindow(SW_HIDE);
		dlg.DoModal();
	}
	if (rs.m_toolbar[4].SetState(point))
	{
		rs.m_input.m_returnnum=0;
		rs.m_input.InPutOver=false;
		rs.m_input.beenget=false;

	}
	if (rs.m_toolbar[5].SetState(point))
	{
		CreateThread(NULL,0,SHIJIOpen,this,0,NULL);

	}
	if (rs.m_toolbar[6].SetState(point))
	{
		theApp.mytools.Huanbi();
		AfxMessageBox("请更换完笔芯后点击确定",MB_SYSTEMMODAL);
		theApp.mytools.MachineHandAllZero();
		theApp.transfer.Ymoveto(2,theApp.mytools.m_d_2_zeroCorrected);
		theApp.transfer.DelayFinish(2,MAX_DELAY_TIME);
		//CMyInput input;
		//if(IDOK==input.DoModal())
		//{
		//	int sampleNum=input.glassNum;
		//	char ast[100];
		//	sprintf(ast,"%d",sampleNum);
		//	AfxMessageBox(ast);
		//}
	}
	if (rs.m_toolbar[7].SetState(point))
	{
		int res=MessageBox("是否确认退出","退出",MB_YESNO|MB_SYSTEMMODAL);
		if(res==IDYES)
		{
			if(rs.Zanting)
			{
				rs.Zanting=false;
				theApp.transfer.restart();
				rs.m_toolbar[2].SetShow("暂停");
			}
			CreateThread(NULL,0,ExitProc,this,0,NULL);
		}


		//退出线程启动

	}
	rs.m_input.ONLBtnDown(point);
	if(rs.radio.OnLButtonDown(point))
	{
		theApp.mytools.m_methodKind=rs.radio.state;
		theApp.mytools.WriteParam(theApp.mytools.m_methodKind,"m_methodKind");
	}
	rs.msgbox.onLButtonDown(point);

	CDialog::OnLButtonDown(nFlags, point);
}

void CTPJ10::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	for (int i=0; i<8; i++)
	{
		if (rs.m_toolbar[i].SetState(point) && rs.Zanting)
		{
			CRect rc;
			rc.left = rs.m_toolbar[0].m_x;
			rc.top = rs.m_toolbar[0].m_y; 
			rc.right =  rs.m_toolbar[0].m_x+rs.m_toolbar[0].m_width*6;
			rc.bottom = rs.m_toolbar[0].m_y+ rs.m_toolbar[0].m_height;
			InvalidateRect(rc, FALSE);
		}
	}
	if(!rs.m_input.InPutOver)
	{
		rs.m_input.OnMouseMove(point);
		Invalidate(FALSE);
	}
	if(!rs.msgbox.visible)
	{
		rs.msgbox.onMouseMove(point);
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CTPJ10::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	theApp.mytools.endflag=true;

	if(mypdlg!=NULL)
		delete mypdlg;

	CDialog::OnClose();


}
LRESULT  CTPJ10::OnHotKey(WPARAM wParam,LPARAM lParam)
{ 

	if(wParam==WM_HOTKEY1)
	{
		mypdlg->ShowWindow(SW_SHOW);
	}
	else if(wParam==WM_HOTKEY2)
	{
		ShowWindow(SW_HIDE);
		m_p->ShowWindow(SW_SHOW);
	}
	else if(wParam==WM_HOTKEY3)
	{
		rs.msgbox.Show("本机版本号："+theApp.mytools.m_version,10);
	}
	return 1;
}

BOOL CTPJ10::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	//	if(pMsg->message==WM_KEYDOWN)
	//	{
	//		CString temp;
	//		temp.Format("%d",pMsg->wParam);
	//		AfxMessageBox(temp);
	//	}
	//	else
	return CDialog::PreTranslateMessage(pMsg);
}
