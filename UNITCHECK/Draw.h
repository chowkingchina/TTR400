#pragma once

#include "Glass.h"
#include "BoBanJia.h"
#include "BoPian.h"
#include "BiaoTiLan.h"
#include "ToolBar.h"
#include "InPutBox.h"
#include "Message.h"
#include "JinDuTiao.h"
#include "TextStatic.h"
#include "MyRadio.h"
class CDraw
{
public:
	CDraw(void);
	~CDraw(void);
	void Draw(Graphics& g);
	void IniAll();//全部初始化
	CRect Rc;
	void SetRc(CRect src);
	bool Zanting;////界面暂停

	Image* able;
	Image* Disable;

public:
	CGlass JAO;
	CGlass HCL;
	CGlass KMNO4;
	CGlass NH4OH;
	CMessage msgbox;
	CJinDuTiao jdt;
	CMyRadio radio;

	CBoBanJia m_jiazi;
	CBoPian m_bopian[10];

	BiaoTiLan m_biaotilan[4];
	ToolBar m_toolbar[8];
	InPutBox m_input;

	bool GetJAO();//获取金胺o动画
	bool GetHCL();//获取盐酸酒精动画
	bool GetKMNO4();//获取高锰酸钾动画

	bool HotOne();
	bool HotTwo();

	bool SmearOne();

	void SetShiJiLiang(int pos, float liang);//设置某种试剂剩下的量
	void CloseBoPianState(int pos);//清除某个玻片的内部状态

	void SetBoPianNum(int pos, int num);//设置某个玻片的信息

	void SetBoBanNum(int pos, int num,int sta=0 );//设置样本架号码

	void SetShiningOn(int pos);
	void SetShiningOff(int pos);

	

	void DrawRoundRectange(Graphics &g, float x, float y, float Width, float Height, float arcSize, Color lineColor, float lineWidth, bool fillPath, Color fillColor);  

	void setWarningOn(int i,CString msg);
	void setWarningOff(int i);
	void setMachineKind(int kind);

};
