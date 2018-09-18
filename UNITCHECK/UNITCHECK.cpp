
// UNITCHECK.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "UNITCHECK.h"
#include "TPJ10.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUNITCHECKApp

BEGIN_MESSAGE_MAP(CUNITCHECKApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CUNITCHECKApp ����

CUNITCHECKApp::CUNITCHECKApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

CUNITCHECKApp::~CUNITCHECKApp()
{
	GdiplusShutdown(m_Ptr);
	transfer.stop();
	
}
// Ψһ��һ�� CUNITCHECKApp ����

CUNITCHECKApp theApp;



// CUNITCHECKApp ��ʼ��

BOOL CUNITCHECKApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	GdiplusStartupInput m_gdiplusstartupinput;
	GdiplusStartup( &m_Ptr,&m_gdiplusstartupinput,NULL);
	RunCmd("devcon enable \"USB\\VID_2341*\"",true);
	
	if(!transfer.InitCom("com5",57600))
	{
		AfxMessageBox("���ڴ�ʧ�ܣ�"); 
		transfer.end=true;
		return false;
	}

	megafilepath=".\\ini\\MEGA_2560.ini";
	CString temp,tagname,pinname;
	CFileFind find;
	if(!find.FindFile(megafilepath))
	{
		AfxMessageBox("�Ҳ���2560�����ļ����뽫�����ļ�����iniĿ¼��");
		return false;
	}	

	chipnum=::GetPrivateProfileInt(_T("pinnum"),_T("chipnum"),0,megafilepath);
	inputnum=::GetPrivateProfileInt(_T("pinnum"),_T("inputnum"),0,megafilepath);
	outputnum=::GetPrivateProfileInt(_T("pinnum"),_T("outputnum"),0,megafilepath);
	syncBytenum=(inputnum+chipnum+7)/8;
	memset(status,-1,sizeof(bool)*theApp.syncBytenum*8);
	chip=status+inputnum;
	memset(theApp.status,1,sizeof(bool)*100);
	memset(theApp.checkpin,-1,sizeof(int)*70);
	memset(theApp.outputpin,-1,sizeof(int)*70);
	for(int i=0;i<70;i++)
	{
		tagname.Format("m_2560_checkTag%d",i+1);
		pinname.Format("m_2560_checkPin%d",i+1);
		::GetPrivateProfileString(_T("2560_tag"),tagname,"",temp.GetBuffer(255),255,megafilepath);
		checktag[i]=temp;
		temp.ReleaseBuffer();
		checkpin[i]=::GetPrivateProfileInt(_T("2560_pin"),pinname,-1,megafilepath);
		pinname.Format("m_2560_outPin%d",i+1);
		outputpin[i]=::GetPrivateProfileInt(_T("2560_output"),pinname,-1,megafilepath);
	}
	transfer.setStatus(status,checkpin,inputnum,chipnum);
	CTPJ10 dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
bool CUNITCHECKApp::InitCom( CString comName )
{
	hCom = CreateFile(comName,//COM5��  
		GENERIC_READ|GENERIC_WRITE, //�������д  
		0, //��ռ��ʽ  
		NULL,  
		OPEN_EXISTING, //�򿪶����Ǵ���  
		0, //ͬ����ʽ  
		NULL);  
	if(hCom == (HANDLE)-1)  
	{  
		hCom=NULL;
		return FALSE;  
	}  
	SetupComm(hCom,100,100); //���뻺����������������Ĵ�С����100  
	COMMTIMEOUTS TimeOuts;  
	//�趨����ʱ  
	TimeOuts.ReadIntervalTimeout=MAXDWORD;  
	TimeOuts.ReadTotalTimeoutMultiplier=0;  
	TimeOuts.ReadTotalTimeoutConstant=0;  
	//�ڶ�һ�����뻺���������ݺ���������������أ�  
	//�������Ƿ������Ҫ����ַ���  
	//�趨д��ʱ  
	TimeOuts.WriteTotalTimeoutMultiplier=100;  
	TimeOuts.WriteTotalTimeoutConstant=500;  
	SetCommTimeouts(hCom,&TimeOuts); //���ó�ʱ  

	DCB dcb;  
	GetCommState(hCom, &dcb);  
	dcb.BaudRate=57600; //������Ϊ9600  
	dcb.ByteSize=8; //ÿ���ֽ���8λ  
	dcb.Parity=NOPARITY; //����żУ��λ  
	dcb.StopBits=1; //����ֹͣλ  
	SetCommState(hCom, &dcb);  
	PurgeComm(hCom, PURGE_TXCLEAR|PURGE_RXCLEAR); 
	return true;
}
int CUNITCHECKApp::WriteData( char* buffer )
{
	if(hCom==NULL)
		return -1;
	unsigned long dwBytesWrite;  
	COMSTAT ComStat;  
	DWORD dwErrorFlags;  
	BOOL bWriteStat;  
	ClearCommError(hCom, &dwErrorFlags, &ComStat);  
	dwBytesWrite = strlen(buffer);  
	bWriteStat=WriteFile(hCom, buffer, dwBytesWrite, &dwBytesWrite, NULL);  
	if(!bWriteStat)  
	{  
		AfxMessageBox("д������ʧ��");
		return -1;  
	}  
	return 0;  
}

int CUNITCHECKApp::ReadData()
{
	if(hCom==NULL)
		return -1;
	memset(readBuffer, 0, 512);  
	DWORD wCount= 512;//��ȡ���ֽ���  
	BOOL bReadStat;  
	bReadStat = ReadFile(hCom, readBuffer, wCount, &wCount, NULL);  
 	if(!bReadStat)  
	{  
		AfxMessageBox("��ȡ����ʧ��");
		return -1;  
	}  
	//strcpy(buffer, readBuffer);  
	return wCount;
}
void CUNITCHECKApp::WriteQueue( CString str )
{
	while (slock)
	{
		Sleep(5);
	}
	slock = true;
	for (int i=0; i<SendArray.GetSize(); i++)
	{
		if(SendArray.GetAt(i) == str)
		{
			slock = false;
			return ;
		} 

	}
	SendArray.Add(str);
	slock = false;
}
void CUNITCHECKApp::RunCmd(CString cmd,bool wait=false)
{
	PROCESS_INFORMATION ProcessInfo;
	STARTUPINFO StartupInfo; //This is an [in] parameter
	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
	StartupInfo.cb = sizeof(StartupInfo); //Only compulsory field
	StartupInfo.dwFlags = STARTF_USESHOWWINDOW;
	StartupInfo.wShowWindow=false;
	if(CreateProcess(NULL,(LPSTR)(LPCSTR)cmd, 
		NULL,NULL,FALSE,0,NULL,
		NULL,&StartupInfo,&ProcessInfo))
	{
		if(wait)
		{
			WaitForSingleObject(ProcessInfo.hProcess,INFINITE);
			CloseHandle(ProcessInfo.hThread);
			CloseHandle(ProcessInfo.hProcess);
		}
	}  
	else
	{
		AfxMessageBox("The process could not be started...");
	}



}
