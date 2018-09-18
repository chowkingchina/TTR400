#include "StdAfx.h"
#include "MyTransfer.h"
#include "UNITCHECK.h"


byte CMyTransfer::bit2Byte(bool *b)   //bit[8] 转为Byte
{
	byte a=0;

	for(int i=0;i<8;i++)
	{
		a |=(b[i]<<i & 0xff);
	}
	return a;
}
void CMyTransfer::byte2Bit(byte val,bool *b)
{
	for(int i=0;i<8;i++)
	{
		b[i]=(val>>i)& 0x01;
	}
}
void CMyTransfer::GetStatus(MyString str)
{
	if(!oldstr.equals(str))
	{
		file<<"recv:"<<str.toBitString()<<endl;
		oldstr=str;
		slock=true;
		for(int i=0;i<syncBytenum;i++)
		{
			byte2Bit(str.data[i],status+i*8);

		}
		slock=false;

	}
	if(*(chip+2)==0)
	{
		send_sure=true;
		*(chip+2)=1;
	}
	if(button!=NULL)
	{
		for(int i=0;i<buttonnum;i++)
		{
			(*(button+i)).Check();
		}
	}
	if(powerpin!=-1)
	{
		if(!getPinMode(powerpin))
			poweron=true;
		else
		{
			if(poweron)
			{
				end=true;
			}
		}

	}


}
DWORD WINAPI recvThread(void * param)
{
	CMyTransfer* pDlg=( CMyTransfer*)param;
	pDlg->recvover=false;
	int pos = 0;
	MyString All,temp,temp1;
	char *buffer=pDlg->readBuffer;
	while(!pDlg->end)
	{

		if(pDlg->hCom!=NULL)
		{
			if(theApp.mytools.m_reconnectEnable)
			{
				if(pDlg->isPause)
				{
					if(pDlg->hCom!=NULL && !pDlg->isRead && !pDlg->isWrite)
					{
						pDlg->ReConnect();
						Sleep(100);
						continue;
					}
				}
			}
			while(pDlg->ispause)
			{
				if(pDlg->end)
					break;
				Sleep(5);
			}

			int num=pDlg->ReadCom();
			All.append(buffer,num);
			if(num<=0)
			{
				if(pDlg->CheckConnect())
				{

					if(theApp.mytools.m_reconnectEnable)
					{
						AfxMessageBox("串口连接异常，请点击确定后自动重连");
						if(!pDlg->ReConnect())
						{
							AfxMessageBox("串口重连失败，请检查USB连线");
							continue;

						}
					}
					else
					{
						AfxMessageBox("串口连接异常");

					}

				}
			}
			else
			{
				pDlg->hearttimer=0;
			}
			while(num>0)
			{
				if(pDlg->end)
					break;
				int le=temp.GetLength();
				num=pDlg->ReadCom();
				All.append(buffer,num);

			}

			pos=All.Find('}');
			char defchar=All.data[pos+1];
			while( -1 != pos)
			{
				if(pDlg->end)
					break;
				if(defchar=='$')
				{
					temp = All.Left(pos);
					All = All.Mid(pos+1);
					int posstart=temp.Find('{');
					if(!temp.isEmpty() && posstart!=-1)
					{
						temp=temp.Mid(posstart+1);
						if(temp.GetLength()==pDlg->syncBytenum)
						{
							pDlg->GetStatus(temp);

						}

					}
					temp1=temp;
					pos=All.Find('}');
					defchar=All.data[pos+1];
				}
				else
				{
					pos=All.Find(pos+1,'}');
					defchar=All.data[pos+1];
				}




			}
		}
		else
		{
			if(theApp.mytools.m_reconnectEnable)
			{

				if(!pDlg->ReConnect())
				{
					AfxMessageBox("串口重连失败，请检查USB连线");
				}
			}
		}
		Sleep(1);
	}
	pDlg->recvover=true;
	return 1;
}

CMyTransfer::CMyTransfer(bool *state,int *inputpin,int zeropinnum ,int unonum)
{
	sendover=false;
	recvover=false;
	end=false;
	isRead=false;
	isWrite=false;
	slock=false;
	wlock=false;//写内存锁
	this->status=state;
	this->input=inputpin;
	this->inputnum=zeropinnum;
	this->chipnum=unonum;
	syncBytenum=(inputnum+chipnum+7)/8;
	button=NULL;
	buttonnum=0;
	hearttimer=0;
	disconnect_limittime=10000;
	comName="COM5";
	boardRate=57600;
	CFileFind find;
	if(!find.FindFile(_T("logfile")))
		::CreateDirectory(_T("logfile"),NULL);
	file.open(_T("logfile/log.txt"),ios::out|ios::trunc);
}
CMyTransfer::CMyTransfer()
{
	sendover=true;
	recvover=true;
	poweron=false;
	powerpin=-1;
	end=false;
	slock=false;
	isRead=false;
	isWrite=false;
	button=NULL;
	buttonnum=0;
	hCom=NULL;
	CFileFind find;
	if(!find.FindFile(_T("logfile")))
		::CreateDirectory(_T("logfile"),NULL);
	file.open(_T("logfile/log.txt"),ios::out|ios::trunc);
}
CMyTransfer::~CMyTransfer(void)
{
	stop();
}
void CMyTransfer::setStatus(bool *state,int *inputpin,int zeropinnum ,int unonum)
{
	sendover=true;
	recvover=true;
	end=false;
	send_sure=false;
	isPause=false;
	isRead=false;
	isWrite=false;
	slock=false;
	this->status=state;
	this->input=inputpin;
	chip=state+zeropinnum;
	this->inputnum=zeropinnum;
	hearttimer=0;
	disconnect_limittime=10000;
	this->chipnum=unonum;
	for(int i=0;i<zeropinnum+zeropinnum;i++)
	{
		*(status+i)=1;
	}
	syncBytenum=(inputnum+chipnum+7)/8;
	button=NULL;
	buttonnum=0;

}
void CMyTransfer::setPowerpin(int pin)
{
	powerpin=pin;
}
void CMyTransfer::setButtonNum(int num)
{


	buttonnum=num;
	button=new CButtonPress[4];

}
void CMyTransfer::setButtonPress(int i,int lightpin,int presspin,bool *outcheckstate,int lightmode,int presstime,int sparktime)
{
	if(button!=NULL && i<=buttonnum)
	{
		(*(button+i-1)).SetButtonPress(this,lightpin,presspin,outcheckstate,lightmode,presstime,sparktime);
	}
}
CButtonPress * CMyTransfer::getButton(int i)
{
	if(button!=NULL && i<=buttonnum)
	{
		return (button+i-1);

	}
	else
		return NULL;

}
void CMyTransfer::start()
{
	ThreadRecv=CreateThread(NULL,0,recvThread,this,0,NULL);
}
void CMyTransfer::stop()
{
	end=true;
	while(!(sendover &&recvover))
	{
		Sleep(10);
	}
	if(button==NULL)
		delete button;
	CloseCom();
	file.close();

}
void CMyTransfer::pause()
{
	ispause=true;


}
void CMyTransfer::restart()
{
	ispause=false;
}
bool CMyTransfer::InitCom(CString comName,int boardrate)
{
	this->comName=comName;
	this->boardRate=boardrate;
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
	dcb.BaudRate=boardrate; //波特率为9600  
	dcb.ByteSize=8; //每个字节有8位  
	dcb.Parity=NOPARITY; //无奇偶校验位  
	dcb.StopBits=1; //两个停止位  
	SetCommState(hCom, &dcb);  
	PurgeComm(hCom, PURGE_TXCLEAR|PURGE_RXCLEAR); 
	return true;
}
bool CMyTransfer::CloseCom()
{
	end=true;
	if(hCom!=NULL)
		CloseHandle(hCom);
	hCom=NULL;
	return true;
}

int CMyTransfer::WriteCom(CString buffer)
{
	if(hCom==NULL)
		return -1;
	isWrite=true;
	unsigned long dwBytesWrite;  
	COMSTAT ComStat;  
	DWORD dwErrorFlags;  
	BOOL bWriteStat;  
	ClearCommError(hCom, &dwErrorFlags, &ComStat);


	//dwBytesWrite = strlen(buffer);  
	bWriteStat=WriteFile(hCom, buffer, buffer.GetLength(), &dwBytesWrite, NULL);  
	isWrite=false;
	Sleep(10);
	if(!bWriteStat)  
	{  
		return -1;  
	}  
	return 0;  
}
int  CMyTransfer::ReadCom()
{
	if(hCom==NULL)
		return -1;
	isRead=true;
	memset(readBuffer, 0, 512);  
	DWORD wCount= 512;//读取的字节数  
	BOOL bReadStat;  
	bReadStat = ReadFile(hCom, readBuffer, wCount, &wCount, NULL);  
	isRead=false;
	if(!bReadStat)  
	{  
		AfxMessageBox(_T("读取数据失败"));
		return -1;  
	}  
	return wCount;
}
bool CMyTransfer::CheckConnect()
{
	if(hearttimer==0)
	{
		hearttimer=clock();
		return false;

	}
	else
	{
		if(clock()-hearttimer>disconnect_limittime)
		{
			hearttimer=0;
			return true;
		}
		else
		{
			return false;
		}
	}

}
bool CMyTransfer::ReConnect()
{
	while(isRead||isWrite)
	{
		if(end)
			break;
		Sleep(5);
	}
	isPause=true;
	COMSTAT ComStat;  
	DWORD dwErrorFlags; 
	ClearCommError(hCom, &dwErrorFlags, &ComStat);
	PurgeComm(hCom, PURGE_TXCLEAR|PURGE_RXCLEAR); 
	if(hCom!=NULL)
	{
		int rescode=CloseHandle(hCom);
		if(rescode==0)//关串口失败
		{
			int ecode=::GetLastError();
			int a=0;
		}
		else
			hCom=NULL;
	}
	system(_T("devcon restart =ports"));
	bool res= InitCom(comName,boardRate);
	if(res)
	{
		isPause=false;

	}
	else
		hCom=NULL;
	Sleep(100);//串口重启后，延时
	return res;




}
CString CMyTransfer::CreateCmd(int cmdType,int chipnum,int cmd,int val)
{
	CString temp;
	if(cmdType>4 || chipnum>99 || cmd>999 || val>999999)
	{
		AfxMessageBox("CreateCmd参数错误");
		return "";
	}
	temp.Format("%d%02d%03d%06d",cmdType,chipnum,cmd,val);
	char *cmdstr=temp.GetBuffer(temp.GetLength());
	temp.ReleaseBuffer();
	char cs='C';
	for(int i=0;i<12;i++)
	{
		cs^=*(cmdstr+i);
	}
	temp="{"+temp+cs+"}";
	return temp;

}
void CMyTransfer::SendCmd(int chipnum,int cmd,int val)
{
	//	CString *temp_pstr=new CString;
	//	temp_pstr->Format(_T("%d:%d=%d;"),chipnum,cmd,val);
	//	SendCmd(*temp_pstr);
	//	delete temp_pstr;
	SendCmd(CreateCmd(0,chipnum,cmd,val));

	if(cmd<20)  //命令参数等回传
	{
		int limit=300;
		int times=0;
		while(chip[chipnum-1])
		{
			Sleep(1);
			if(end)
				break;
			times++;
			if(times>=limit)
				break;
		}
	}
	else
	{
		Sleep(20);
	}

}
void CMyTransfer::DelayFinish(int chipnum,int timemax)
{
	long timer=clock();
	while(!chip[chipnum-1])
	{
		if(end)
			break;
		if(clock()-timer>timemax)
			break;
		Sleep(1);
	}

}
void CMyTransfer::SendCmd(CString cmd)
{
	if(end)
		return;
	while(isPause||ispause)
	{
		if(end)
			break;
		Sleep(5);
	}
	while (wlock||slock)
	{
		if(end)
			break;
		Sleep(5);
	}
	wlock = true;
	bool been_send=false;
	int send_retry=0;//最大传3次
	while(!been_send && send_retry<3)
	{
		if(end)
			break;
		while(isPause)
		{
			if(end)
				break;
			Sleep(5);
		}
		send_retry++;
		send_sure=false;
		int res=WriteCom(cmd);
		if(res!=-1)
			file<<"send:"<<cmd<<endl;
		else
		{
			file<<" send: "<<cmd<<" failure!"<<endl;
			isPause=true; 
			send_retry=0;
			continue;
		}
		if(!(cmd.Mid(1,1)=="0" && atoi(cmd.Mid(4,3))<=20))
			break;
		if(end)
			break;
		int numi=0;  //超时250ms
		Sleep(30);
		while(!send_sure && numi<50)
		{
			if(end)
				break;
			numi++;
			Sleep(5);
		}
		if(numi<50)
		{
			send_sure=false;
			break;

		}
		else
		{
			send_sure=false;
			//	AfxMessageBox("PC发2560超时，错误！");
		}
	}
	//if(send_retry==3)
	//{
	//	ReConnect();
	//}
	wlock = false;
}
void CMyTransfer::Xmove(int chipnum,int value)
{
	if(value==0)
		return;
	else if(value>0)
	{
		SendCmd(chipnum,50,1);
		SendCmd(chipnum,2,value);
	}
	else
	{
		SendCmd(chipnum,50,0);
		SendCmd(chipnum,2,-value);

	}

}
void CMyTransfer::Xmoveto(int chipnum,int value)
{
	if(value<=0)
	{
		Xhome(chipnum);

	}
	else if(value>0)
	{
		SendCmd(chipnum,3,value);

	}
}
void CMyTransfer::Xhome(int chipnum)
{
	SendCmd(chipnum,1,1);
}
void CMyTransfer::setXSpeedMode(int chipnum,int value)
{
	SendCmd(chipnum,54,value);
}
void CMyTransfer::Ymove(int chipnum,int value)
{
	if(value==0)
	{
		return;

	}
	else if(value>0)
	{
		SendCmd(chipnum,51,1);
		SendCmd(chipnum,5,value);
	}
	else
	{
		SendCmd(chipnum,51,0);
		SendCmd(chipnum,5,-value);

	}
}
void CMyTransfer::Ymoveto(int chipnum,int value)
{
	if(value<=0)
	{
		Yhome(chipnum);

	}
	else
		SendCmd(chipnum,6,value);
}
void CMyTransfer::Yhome(int chipnum)
{
	SendCmd(chipnum,4,1);
}
void CMyTransfer::setYSpeedMode(int chipnum,int value)
{
	SendCmd(chipnum,55,value);
}
void CMyTransfer::Zmove(int chipnum,int value)
{
	if(value==0)
	{
		return;

	}
	else if(value>0)
	{
		SendCmd(chipnum,52,1);
		SendCmd(chipnum,8,value);
	}
	else
	{
		SendCmd(chipnum,52,0);
		SendCmd(chipnum,8,-value);

	}
}
void CMyTransfer::Zmoveto(int chipnum,int value)
{
	if(value<=0)
		Zhome(chipnum);
	else
		SendCmd(chipnum,9,value);
}
void CMyTransfer::Zhome(int chipnum)
{
	SendCmd(chipnum,7,1);
}
void CMyTransfer::setZSpeedMode(int chipnum,int value)
{
	SendCmd(chipnum,56,value);
}
void CMyTransfer::Kmove(int chipnum,int value)
{
	if(value==0)
	{
		return ;

	}
	else if(value>0)
	{
		SendCmd(chipnum,53,1);
		SendCmd(chipnum,11,value);
	}
	else
	{
		SendCmd(chipnum,53,0);
		SendCmd(chipnum,11,-value);

	}
}
void CMyTransfer::Kmoveto(int chipnum,int value)
{
	if(value<=0)
		Khome(chipnum);
	else
		SendCmd(chipnum,12,value);
}
void CMyTransfer::Khome(int chipnum)
{
	SendCmd(chipnum,10,1);
}
void CMyTransfer::setKSpeedMode(int chipnum,int value)
{
	SendCmd(chipnum,57,value);
}
void CMyTransfer::Lmove(int chipnum,int value)
{
	if(value==0)
	{
		return ;

	}
	else if(value>0)
	{
		SendCmd(chipnum,65,1);
		SendCmd(chipnum,16,value);
	}
	else
	{
		SendCmd(chipnum,65,0);
		SendCmd(chipnum,16,-value);

	}

}
void CMyTransfer::LmoveWithoutReturn(int chipnum,int value)
{
	if(value>=0)
	{
		SendCmd(chipnum,65,1);
		CString temp;
		temp.Format("%d:%d=%d;",chipnum,16,value);
		SendCmd(temp);
	}
	else
	{
		SendCmd(chipnum,65,0);
		CString temp;
		temp.Format("%d:%d=%d;",chipnum,16,-value);
		SendCmd(temp);
	}
}
void CMyTransfer::Lmoveto(int chipnum,int value)
{
	if(value<=0)
		Lhome(chipnum);
	else
		SendCmd(chipnum,17,value);


}
void CMyTransfer::Lhome(int chipnum)
{
	SendCmd(chipnum,15,1);

}
void CMyTransfer::setLSpeedMode(int chipnum,int value)
{
	SendCmd(chipnum,63,value);
}
void CMyTransfer::UnionMove(int chipnum,int x,int y,int z ,int k,int l,int speed)
{
	if(x>=0)
	{
		SendCmd(chipnum,50,1);
		SendCmd(chipnum,58,x);
	}
	else
	{
		SendCmd(chipnum,50,0);
		SendCmd(chipnum,58,-x);
	}
	if(y>=0)
	{
		SendCmd(chipnum,51,1);
		SendCmd(chipnum,59,y);
	}
	else
	{
		SendCmd(chipnum,51,0);
		SendCmd(chipnum,59,-y);
	}
	if(z>=0)
	{
		SendCmd(chipnum,52,1);
		SendCmd(chipnum,60,z);
	}
	else
	{
		SendCmd(chipnum,52,0);
		SendCmd(chipnum,60,-z);
	}
	if(k>=0)
	{
		SendCmd(chipnum,53,1);
		SendCmd(chipnum,61,k);
	}
	else
	{
		SendCmd(chipnum,53,0);
		SendCmd(chipnum,61,-k);
	}
	if(l>=0)
	{
		SendCmd(chipnum,65,1);
		SendCmd(chipnum,64,l);
	}
	else
	{
		SendCmd(chipnum,65,0);
		SendCmd(chipnum,61,-l);
	}

	SendCmd(chipnum,62,speed);
	SendCmd(chipnum,13,1);
}
void CMyTransfer::Smove(int chipnum)
{
	SendCmd(chipnum,14,1);	
}
void CMyTransfer::PullUNOUp(int chipnum,int pin)
{
	SendCmd(chipnum,21,pin*2+2);

}
void CMyTransfer::PullUNODown(int chipnum,int pin)
{
	SendCmd(chipnum,21,pin*2+1);
}
void CMyTransfer::PullUp(int pin)
{
	SendCmd(CreateCmd(1,0,pin,1));

}
void CMyTransfer::PullDown(int pin)
{
	SendCmd(CreateCmd(1,0,pin,0));
	//CString temp;
	//temp.Format(_T("%d:lw"),pin);
	//SendCmd(temp);
}
void CMyTransfer::PowerOn()
{
	SendCmd(CreateCmd(3,0,1,1));


}
void CMyTransfer::PowerOff()
{
	SendCmd(CreateCmd(3,0,17,1));
}
int CMyTransfer::getPinMode(int zeropin)
{
	int i=0;
	for(i=0;i<inputnum;i++)
	{
		if(zeropin==input[i])
			break;
	}
	if(i==inputnum)
		return -1;
	else
		return (int)(status[i]);
}