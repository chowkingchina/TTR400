
// UNITCHECK.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif
#define MAX_DELAY_TIME 100000
#include "resource.h"		// ������
#include "MyTransfer.h"
#include "MyTools.h"

// CUNITCHECKApp:
// �йش����ʵ�֣������ UNITCHECK.cpp
//

class CUNITCHECKApp : public CWinAppEx
{
public:
	CUNITCHECKApp();
	~CUNITCHECKApp();

// ��д
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


// ʵ��
	
	DECLARE_MESSAGE_MAP()
};

extern CUNITCHECKApp theApp;