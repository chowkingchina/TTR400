
// UNITCHECK.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif
#define MAX_DELAY_TIME 100000
#include "resource.h"		// 主符号
#include "MyTransfer.h"
#include "MyTools.h"

// CUNITCHECKApp:
// 有关此类的实现，请参阅 UNITCHECK.cpp
//

class CUNITCHECKApp : public CWinAppEx
{
public:
	CUNITCHECKApp();
	~CUNITCHECKApp();

// 重写
	public:
	virtual BOOL InitInstance();
	bool InitCom(CString comName);
	int WriteData(char* buffer);
	int ReadData();
	void WriteQueue(CString str);
	void RunCmd(CString cmd,bool wait);
public:
	HANDLE	hCom;
	ULONG_PTR m_Ptr;
	CMyTransfer transfer;
	CMyTools mytools;
	CStringArray SendArray;
	bool slock;
	bool endflag;
	char readBuffer[512];  
	bool status[100];
	CString checktag[70];
	CString megafilepath;
	int checkpin[70];
	int outputpin[70];
	int inputnum;
	int chipnum;
	int outputnum;
	int syncbitnum;
	int syncBytenum;
	bool *chip;


// 实现
	
	DECLARE_MESSAGE_MAP()
};

extern CUNITCHECKApp theApp;