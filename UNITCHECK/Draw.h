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
	void IniAll();//ȫ����ʼ��
	CRect Rc;
	void SetRc(CRect src);
	bool Zanting;////������ͣ

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

	bool GetJAO();//��ȡ��o����
	bool GetHCL();//��ȡ����ƾ�����
	bool GetKMNO4();//��ȡ������ض���

	bool HotOne();
	bool HotTwo();

	bool SmearOne();

	void SetShiJiLiang(int pos, float liang);//����ĳ���Լ�ʣ�µ���
	void CloseBoPianState(int pos);//���ĳ����Ƭ���ڲ�״̬

	void SetBoPianNum(int pos, int num);//����ĳ����Ƭ����Ϣ

	void SetBoBanNum(int pos, int num,int sta=0 );//���������ܺ���

	void SetShiningOn(int pos);
	void SetShiningOff(int pos);

	

	void DrawRoundRectange(Graphics &g, float x, float y, float Width, float Height, float arcSize, Color lineColor, float lineWidth, bool fillPath, Color fillColor);  

	void setWarningOn(int i,CString msg);
	void setWarningOff(int i);
	void setMachineKind(int kind);

};
