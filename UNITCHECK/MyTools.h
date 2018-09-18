#pragma once
#include "Draw.h"

class Sample
{
public:
	bool exist;
	int num;
	int state;
	Sample()
	{
	init();
	}
	void init()
	{
		exist=0;
		num=0;
		state=0;
	}
	void SetValue(Sample &sample)
	{
		exist=sample.exist;
		num=sample.num;
		state=sample.state;
	}

};
class Glass
{
public:
	bool exist;
	int num;
	int state;
	Glass()
	{
		init();
	}
	void init()
	{
		exist=0;
		num=0;
		state=0;
	}
	void SetValue(Glass &glass)
	{
		exist=glass.exist;
		num=glass.num;
		state=glass.state;
	}
};
class CMyTools
{
public:
	CMyTools(void);
	~CMyTools(void);
public:
	void upload();
	void LiquidSpray(int pin,long time);
	void Write1(int num);
	void Write(int num,int x,int y,int z,int tibi);
	void WriteParam(long param,CString paramname);
	void ReadParam(long &param,CString paramname);
	void SampleInit();
	bool isSampleEmpty();
	bool isGlassEmpty();
	void GlassInit();
	void IvSleep(long delaytime);
	void IvSleep(long delaytime,CJinDuTiao &jdt,CString inst);
	bool allhome(CDraw &rs);
	void servoHome();
	void MachineHandAllZero();
	void Qingxi();
	void SprayPenTou();
	void WashSj(int Num);
	void WashSjLast(int Num);
	bool SampleFrameExist();
	bool GlassFrameExist();
	bool CheckSample(int Pos);
	void ToFrontDoor();
	void Huanbi();
	void WriteSample(int Pos,int Num);
	void WriteGlass(int Pos,int Num);
	bool Kaigai(int Pos);
	bool Guangai(int Pos);
	void Motan(int Pos);
	void Tupian(int Pos);
	void JAO(int Pos);
	void HCL(int Pos);
	void KMNO4(int Pos);
	void MEIRAN(int Pos);
	void GDJ();
	void AlertVoice();
	






public:
	long m_d_2_zeroCorrected;
	long m_d_2_homedelaytime;
	long m_reconnectEnable;
	long m_machineKind;
	long m_d_2_glsmrNum;
	long m_d_2_glsmrWashNum;
	long m_d_2_glsmrsprayTime;
	long m_d_2_glsmrQxptsprayTime;
	long m_d_2_glsmrwaitTime;
	long m_d_2_pianmr;
	long m_methodKind;
	long m_methodKindVisible;
	long m_1_d_preHotTime;
	long m_1_d_preHotMaxTime;
	long m_1_d_minTimeBeforeTp;
	long m_d_xiaodutime;
	long m_d_2_jaocanpray;
	long m_d_2_jaopraynum;
	long m_d_2_kmnocanpray;
	long m_d_2_kmnopraynum;
	long m_d_2_hclcanpray;
	long m_d_2_hclpraynum;
	long m_d_2_gdjcanpray;
	long m_d_2_gdjpraynum;



	long m_1_kggspeed;
	long m_1_huanbiy;
	long m_1_tpspeed;
	long m_d_1_samplex1;
	long m_d_1_samplex2;
	long m_d_1_samplex3;
	long m_d_1_samplex4;
	long m_d_1_samplex5;
	long m_d_1_samplex6;
	long m_d_1_samplex7;
	long m_d_1_samplex8;
	long m_d_1_samplex9;
	long m_d_1_samplex10;
	long m_d_1_glassx1;
	long m_d_1_glassx2;
	long m_d_1_glassx3;
	long m_d_1_glassx4;
	long m_d_1_glassx5;
	long m_d_1_glassx6;
	long m_d_1_glassx7;
	long m_d_1_glassx8;
	long m_d_1_glassx9;
	long m_d_1_glassx10;
	long m_d_2_sjpos1;
	long m_d_2_sjpos2;
	long m_d_2_sjpos3;
	long m_d_2_sjpos4;
	long m_d_2_sjpos5;
	long m_d_2_sjpos6;
	long m_d_2_sjpos7;
	long m_d_2_sjpos8;
	long m_d_2_sjpos9;
	long m_d_2_sjpos10;
	long m_d_1_sampley;
	long m_d_1_samplez;
	long m_d_1_glassy;
	long m_d_1_glassz;
	long m_d_2_qinxie;
	long m_d_1_smeark;
	long m_d_2_qingxih2o;
	long m_d_2_gdjspraytime;
	long  m_d_1_kgdown;
	long  m_d_1_kgzhuan;
	long  m_d_1_ggzhuan;
	long m_d_1_tplength;
	long m_d_1_tpwidth;
	long m_d_1_tpgong;
	long m_d_1_tpquan;
	long  m_d_2_pianrs;
	long  m_d_2_piants;
	long  m_d_2_pianfr;
	long  m_d_2_pianh2o;
	long  m_d_2_rswaittime;
	long  m_d_2_tswaittime;
	long  m_d_2_frwaittime;
	long  m_d_1_piansamplewritex;
	long  m_d_1_piansamplewritey;
	long  m_d_1_samplewritez;
	long  m_d_1_zilength;
	long  m_d_1_ziwidth;
	long  m_d_1_zige;
	long  m_d_1_piancheckx;
	long  m_d_1_pianchecky;
	long  m_d_1_piancheckz;
	long  m_d_1_piansmearx;
	long  m_d_1_piansmeary;
	long  m_d_1_piansmearz;
	long  m_d_1_pianglasswritex;
	long  m_d_1_pianglasswritey;
	long  m_d_1_glasswritez;
	long m_d_2_frnum;
	long m_d_2_tsnum;
	long  m_d_1_tibi;
	long  m_d_2_rsspraytime;
	long  m_d_2_tsspraytime;
	long  m_d_2_frspraytime;
	long m_d_2_glassgdtime;
	long m_d_2_rsWashTimes;
	long m_d_2_tsWashTimes;
	long m_d_2_frWashTimes;
	long m_d_2_rsQxptTime;
	long m_d_2_tsQxptTime;
	long m_d_2_frQxptTime;
public:
	CString m_version;
	long samplepos[10];
	long glasspos[10];
	long sjpos[10];

	bool endflag;
	int samplecount;
	bool needhome;
	bool homedone;
	bool needjy;
	bool jydone;


	Glass glass[10];
	Sample sample[10];
};
