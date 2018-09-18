
// UNITCHECK.cpp : 定义应用程序的类行为。
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


// CUNITCHECKApp 构造

CUNITCHECKApp::CUNITCHECKApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

CUNITCHECKApp::~CUNITCHECKApp()
{
	GdiplusShutdown(m_Ptr);
	transfer.stop();
	
}
// 唯一的一个 CUNITCHECKApp 对象

CUNITCHECKApp theApp;



// CUNITCHECKApp 初始化

BOOL CUNITCHECKApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	GdiplusStartupInput m_gdiplusstartupinput;
	GdiplusStartup( &m_Ptr,&m_gdiplusstartupinput,NULL);
	RunCmd("devcon enable \"USB\\VID_2341*\"",true);
	
	if(!transfer.InitCom("com5",57600))
	{
		AfxMessageBox("串口打开失败！"); 
		transfer.end=true;
		return false;
	}

	megafilepath=".\\ini\\MEGA_2560.ini";
	CString temp,tagname,pinname;
	CFileFind find;
	if(!find.FindFile(megafilepath))
	{
		AfxMessageBox("找不到2560配置文件，请将配置文件放在ini目录下");
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
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}
bool CUNITCHECKApp::InitCom( CString comName )
{
	hCom = CreateFile(comName,//COM5口  
		GENERIC_READ|GENERIC_WRITE, //允许读和写  
		0, //独占方式  
		NULL,  
		OPEN_EXISTING, //打开而不是创建  
		0, //同步方式  
		NULL);  
	if(hCom == (HANDLE)-1)  
	{  
		hCom=NULL;
		return FALSE;  
	}  
	SetupComm(hCom,100,100); //输入缓冲区和输出缓冲区的大小都是100  
	COMMTIMEOUTS TimeOuts;  
	//设定读超时  
	TimeOuts.ReadIntervalTimeout=MAXDWORD;  
	TimeOuts.ReadTotalTimeoutMultiplier=0;  
	TimeOuts.ReadTotalTimeoutConstant=0;  
	//在读一次输入缓冲区的内容后读操作就立即返回，  
	//而不管是否读入了要求的字符。  
	//设定写超时  
	TimeOuts.WriteTotalTimeoutMultiplier=100;  
	TimeOuts.WriteTotalTimeoutConstant=500;  
	SetCommTimeouts(hCom,&TimeOuts); //设置超时  

	DCB dcb;  
	GetCommState(hCom, &dcb);  
	dcb.BaudRate=57600; //波特率为9600  
	dcb.ByteSize=8; //每个字节有8位  
	dcb.Parity=NOPARITY; //无奇偶校验位  
	dcb.StopBits=1; //两个停止位  
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
		AfxMessageBox("写入数据失败");
		return -1;  
	}  
	return 0;  
}

int CUNITCHECKApp::ReadData()
{
	if(hCom==NULL)
		return -1;
	memset(readBuffer, 0, 512);  
	DWORD wCount= 512;//读取的字节数  
	BOOL bReadStat;  
	bReadStat = ReadFile(hCom, readBuffer, wCount, &wCount, NULL);  
 	if(!bReadStat)  
	{  
		AfxMessageBox("读取数据失败");
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
