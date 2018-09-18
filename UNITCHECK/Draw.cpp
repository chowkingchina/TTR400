#include "StdAfx.h"
#include "Draw.h"
#include "UNITCHECK.h"
#
CDraw::CDraw(void)
{
	Zanting = false;
	CString temp;
	temp = _T("res/BGMWORK.jpg");
	able = ::new Image(temp.AllocSysString());
	temp = _T("res/BGM.jpg");
	Disable = ::new Image(temp.AllocSysString());

	IniAll();
}

CDraw::~CDraw(void)
{

	if (Disable != NULL)
	{
		::delete Disable;
		Disable = NULL;
	}
	if (able != NULL)
	{
		::delete able;
		able = NULL;
	}
}

void CDraw::Draw(Graphics& g)
{
	if (Zanting)
	{
		g.DrawImage(Disable,0,0,Rc.Width(),Rc.Height());
		for (int i=0; i<7; i++)
		{
			m_toolbar[i].DrawCGlass(g);
		}
		m_input.DrawCGlass(g);
		return;
	}
	g.DrawImage(able,0,0,Rc.Width(),Rc.Height());	
	

	if (m_input.InPutOver)
	{
		for(int i=0;i<4;i++)
		{
			m_biaotilan[i].DrawCGlass(g);

		}
		
		for (int i=0;i<10;i++)
		{
			m_bopian[i].DrawCGlass(g);
		}



		JAO.DrawCGlass(g);
		HCL.DrawCGlass(g);
		KMNO4.DrawCGlass(g);
		NH4OH.DrawCGlass(g);
		radio.DrawSelf(g);


		m_jiazi.DrawCGlass(g);
	}
	for (int i=0; i<8; i++)
	{
		m_toolbar[i].DrawCGlass(g);
	}
	m_input.DrawCGlass(g);
	msgbox.Draw(g);
	jdt.Draw(g);

}

void CDraw::IniAll()
{

	////////////////////////试剂打包初始化
	int CGlassGroupX = 90;
	int CGlassGroupY = 220;
	int CGlassGroupH = 0;
	int CGlassGroupZ = 130;
	
	JAO.SetLiang(0);
	HCL.SetLiang(0);
	KMNO4.SetLiang(0);
	NH4OH.SetLiang(0);
	radio.setImage(".\\res\\radioOn.jpg",".\\res\\radioOff.jpg");
	radio.setText("涂染","染色");
	radio.setPos(80,10,180,30);
	setMachineKind(theApp.mytools.m_machineKind);






	/////////////////////////进样架打包初始化

	int JiaGroupX = 330;
	int JiaGroupY =280;


	m_jiazi.Setpos(JiaGroupX, JiaGroupY, 720, 60);
	m_jiazi.SetColor(Color(255,48,48,48), Color(255,180,180,180));
	m_jiazi.HuiZhi = false;



	int BoGroupX = 310;
	int BoGroupY = 530;
	int BoGroupH = 80;


	for (int i=0; i<10; i++)
	{
		m_bopian[i].Setpos(BoGroupX+BoGroupH*i, BoGroupY, 50, 110);
		m_bopian[i].SetColor(Color(255,191,255,255), Color(255,48,48,48));
	}


///////////////////////////////////////////////标题栏初始化
	for (int i=0; i<4; i++)
	{
	m_biaotilan[i].SetColor(Color::White,Color(255, 255, 0, 0));
	}
	m_biaotilan[0].Setpos(25,140,1220,620);
	m_biaotilan[1].Setpos(80,190,80,520);
	m_biaotilan[1].m_title="试剂区";
	m_biaotilan[2].Setpos(JiaGroupX-90,JiaGroupY-60,900,180);
	m_biaotilan[2].m_title="标本架区";
	m_biaotilan[3].Setpos(BoGroupX-70,BoGroupY-40,900,180);
	m_biaotilan[3].m_title="玻片架区";




}

bool CDraw::GetJAO()
{
	
	return false;
}

bool CDraw::GetHCL()
{
	return false;
}

bool CDraw::GetKMNO4()
{
		
	return false;
}

bool CDraw::HotOne()
{
	m_bopian[0].INNER = true;
	m_bopian[0].SetInner(Color(255, 243, 96, 33));
	m_bopian[0].InnerShine = true;
	if ((m_bopian[0].InnerAlpha+3)<255)
	{
		m_bopian[0].InnerAlpha+=3;
		return false;
	}else
	{
		m_bopian[0].InnerAlpha=127;
		return true;
	}

}
bool CDraw::SmearOne()
{
	m_bopian[1].INNER = true;
	m_bopian[1].SetInner(Color(255, 192, 192, 192));
	m_bopian[1].InnerShine = true;
	if ((m_bopian[1].InnerAlpha+3)<255)
	{
		m_bopian[1].InnerAlpha+=3;
		return false;
	}else
	{
		m_bopian[1].InnerAlpha=127;
		return true;
	}

}
bool CDraw::HotTwo()
{
	m_bopian[5].INNER = true;
	m_bopian[5].SetInner(Color(255, 243, 96, 33));
	m_bopian[5].InnerShine = true;
	if ((m_bopian[5].InnerAlpha+3)<255)
	{
		m_bopian[5].InnerAlpha+=3;
		return false;
	}else
	{
		m_bopian[5].InnerAlpha=127;
		return true;
	}
}

void CDraw::SetBoPianNum( int pos, int num )
{
	m_bopian[pos].num = num;
}

void CDraw::CloseBoPianState( int pos )
{
	m_bopian[pos].INNER = false;		
}	

void CDraw::SetShiJiLiang( int pos, float liang )
{
	if (pos == 0)
	{
		JAO.Liang = liang;
	}
	if (pos == 1)
	{
		HCL.Liang = liang;
	}
	if (pos == 2)
	{
		KMNO4.Liang = liang;
	}
}

void CDraw::SetBoBanNum( int pos, int num ,int sta)
{
	m_jiazi.Exist[pos] = true;
	m_jiazi.num[pos] = num;
	m_jiazi.state[pos] = sta;
}



void CDraw::SetRc( CRect src )
{
	Rc.left = src.left;
	Rc.top = src.top;
	Rc.right = src.right;
	Rc.bottom = src.bottom;

	///////////////////////////////////////////////////文本输入框初始化
	int EidtWidth = 80;
	int EidtGroupY = 250;
	int EidtGroupH = 300;
	int EidtGroupX = (Rc.Width()-EidtGroupH)/2;

	m_input.Setpos(EidtGroupX, EidtGroupY, EidtGroupH, EidtWidth, EidtWidth);



	///////////////////////////////////////////////工具栏初始化

	int ToolWidth = 70;
	int ToolGroupY = 0;
	int ToolGroupH = 95;
	int ToolGroupX = (Rc.Width()-ToolGroupH*8)/2;
	int ToolGroupZ = 35;
	for (int i=0; i<8; i++)
	{
		m_toolbar[i].Setpos(ToolGroupX+ToolGroupH*i,ToolGroupY,ToolGroupH,ToolGroupH,ToolWidth);
	}
	m_toolbar[0].SetImage(_T("res/ChuShiHua.png"), _T("res/ChuShiHuaD.png"));
	m_toolbar[0].SetShow(_T("初始化"));
	m_toolbar[1].SetImage(_T("res/KaiShi.png"), _T("res/KaiShiD.png"));
	m_toolbar[1].SetShow(_T("进样"));
	m_toolbar[1].Enable(false);
	m_toolbar[2].SetImage(_T("res/ZanTing.png"), _T("res/ZanTingD.png"));
	m_toolbar[2].SetShow(_T("暂停"));
	m_toolbar[3].SetImage(_T("res/SheZhi.png"), _T("res/SheZhiD.png"));
	m_toolbar[3].SetShow(_T("设置选项"));
	m_toolbar[4].SetImage(_T("res/BiaoHao.png"), _T("res/BiaoHaoD.png"));
	m_toolbar[4].SetShow(_T("编号设置"));
	m_toolbar[5].SetImage(_T("res/ChuPian.png"), _T("res/ChuPianD.png"));
	m_toolbar[5].SetShow(_T("打开试剂仓"));
	m_toolbar[6].SetImage(_T("res/pencil.png"), _T("res/pencilD.png"));
	m_toolbar[6].SetShow(_T("换笔"));
	m_toolbar[7].SetImage(_T("res/TuiChu.png"), _T("res/TuiChuD.png"));
	m_toolbar[7].SetShow(_T("退出"));

	m_toolbar[5].Enable(true);
	m_toolbar[3].Enable(false);
}




void CDraw::setWarningOn(int i,CString msg)
{
	if(!m_biaotilan[i].Warning)
	{
	m_biaotilan[i].Warning=true;
	m_biaotilan[i].m_show=msg;
	}


}
void CDraw::setWarningOff(int i)
{
	if(m_biaotilan[i].Warning)
	{
	m_biaotilan[i].Warning=false;
	m_biaotilan[i].m_show="";
	}
}
void CDraw::setMachineKind(int kind)
{
	radio.setKind(kind);
	int CGlassGroupX = 90;
	int CGlassGroupY = 220;
	int CGlassGroupH = 0;
	int CGlassGroupZ = 130;
	if(kind==0)
	{

		JAO.Setpos(CGlassGroupX+CGlassGroupH, CGlassGroupY+CGlassGroupZ*0, 60, 72);
		HCL.Setpos(CGlassGroupX+CGlassGroupH, CGlassGroupY+CGlassGroupZ*1, 60, 72);
		KMNO4.Setpos(CGlassGroupX+CGlassGroupH, CGlassGroupY+CGlassGroupZ*2, 60, 72);
		NH4OH.Setpos(CGlassGroupX+CGlassGroupH, CGlassGroupY+CGlassGroupZ*3, 60, 72);
		JAO.setName("染色剂");
		HCL.setName("脱色剂");
		KMNO4.setName("复染剂");
		NH4OH.setName("缓冲液");
		JAO.SetColor(Color::White,Color(128,250,250,0));
		HCL.SetColor(Color::White, Color(128,150,150,150));
		KMNO4.SetColor(Color::White, Color(128,250,0,250));
		NH4OH.SetColor(Color::White, Color(128,100,100,100));
	}
	else
	{
		
		JAO.Setpos(CGlassGroupX+CGlassGroupH, CGlassGroupY+CGlassGroupZ*0, 60, 72);
		NH4OH.Setpos(CGlassGroupX+CGlassGroupH, CGlassGroupY+CGlassGroupZ*1, 60, 72);
		HCL.Setpos(CGlassGroupX+CGlassGroupH, CGlassGroupY+CGlassGroupZ*2, 60, 72);
		KMNO4.Setpos(CGlassGroupX+CGlassGroupH, CGlassGroupY+CGlassGroupZ*3, 60, 72);
		JAO.setName("染色剂");//结晶紫
		HCL.setName("脱色剂");//酒精
		KMNO4.setName("复染剂");//复红
		NH4OH.setName("媒染剂");//卢戈氏碘液
		JAO.SetColor(Color::White,Color(128,250,0,250));
		HCL.SetColor(Color::White, Color(128,150,150,150));
		KMNO4.SetColor(Color::White, Color(128,230,30,30));
		NH4OH.SetColor(Color::White,Color(128,250,250,0));

	}
	

}
void CDraw::SetShiningOn(int pos)
{
	m_bopian[pos].InnerShine=true;

}
void CDraw::SetShiningOff(int pos)
{
	m_bopian[pos].InnerShine=false;

}