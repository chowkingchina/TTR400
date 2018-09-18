#pragma once
#include <fstream>
using namespace std;

class CButtonPress;
class MyString
{
public:
	int len;
	char *data;
	MyString()
	{

		len=0;
		data=NULL;
	}
	MyString(MyString & str)
	{
		len=str.len;
		data=new char[len];
		for(int i=0;i<len;i++)
		{
			data[i]=str.data[i];
		}
	}
	MyString(char *a,int len)
	{
		this->len=len;
		data=new char[len];
		for(int i=0;i<len;i++)
		{
			data[i]=a[i];
		}
	}
	~MyString()
	{
		len=0;
		delete []data;
		data=NULL;
	}

	int GetLength()
	{
		return len;
	}
	bool isEmpty()
	{
		return !len;
	}
	bool equals(MyString str)
	{
		if(len!=str.len)
			return false;
		for(int i=0;i<len;i++)
		{
			if(data[i]!=str.data[i])
				return false;
		}
		return true;
	}
	void clear()
	{

		len=0;
		delete []data;
		data=NULL;

	}
	void append(char *a,int n)
	{
		char *tmp=new char[len+n];
		for(int i=0;i<len;i++)
		{
			tmp[i]=data[i];
		}
		for(int i=0;i<n;i++)
		{
			tmp[i+len]=a[i];
		}
		if(data!=NULL)
			delete [] data;
		data=tmp;
		len=len+n;

	}
	MyString Left(int n)
	{
		MyString dirstr;
//		dirstr.clear();
		dirstr.data=new char[n];
		dirstr.len=n;
		for(int i=0;i<n;i++)
		{
			dirstr.data[i]=data[i];
		}
		return dirstr;
	}
	MyString Mid(int start,int n)
	{
		MyString dirstr;
		if(len<start+1)
		{
			return dirstr;
		}
		else
		{
			dirstr.append(data+start,min(len-start,n));
			return dirstr;

		}

	}
	MyString Mid(int start)
	{
		MyString dirstr;
		if(len<start+1)
		{
			return dirstr;
		}
		else
		{
			dirstr.append(data+start,len-start);
			return dirstr;
		}

	}
	int  Find(char c)
	{
		for(int i=0;i<len;i++)
		{
			if(data[i]==c)
			{
				return i;
			}
		}
		return -1;

	}
	int  Find(int pos,char c)
	{
		for(int i=pos;i<len;i++)
		{
			if(data[i]==c)
			{
				return i;
			}
		}
		return -1;

	}
	void Replace(char orion,char rep)
	{
		for(int i=0;i<len;i++)
		{
			if(data[i]==orion)
			{
				data[i]=rep;
			}
		}

	}
	CString toCString()
	{
		CString str(data);
		return str;

	}
	void byte2Bit(byte val,bool *b)
	{
		for(int i=0;i<8;i++)
		{
			b[i]=(val>>i)& 0x01;
		}
	}
	CString bit2String(bool *b,int n)
	{
		CString str=_T("");
		for(int i=0;i<n;i++)
		{
			if(b[i]==0)
				str+=_T("0");
			else
				str+=_T("1");

		}
		return str;

	}
	CString toBitString()
	{
		CString str;
		bool bitarray[8];
		for(int i=0;i<len;i++)
		{
			byte2Bit(data[i],bitarray);
			str+=bit2String(bitarray,8);
		}
		return str;


	}
	MyString operator+(MyString & str)
	{
		char *tmp=new char[len+str.len];
		for(int i=0;i<len;i++)
		{
			tmp[i]=data[i];
		}
		for(int i=0;i<str.len;i++)
		{
			tmp[i+len]=str.data[i];
		}

		MyString nstr(tmp,len+str.len);
		delete [] tmp;
		tmp=NULL;
		return nstr;
	}
	MyString & operator=(MyString & str)
	{
		delete [] data;
		len=str.len;
		data=new char[len];
		for(int i=0;i<len;i++)
		{
			data[i]=str.data[i];
		}

		return *this;



	}
};

class CMyTransfer
{
public:
	CMyTransfer();
	CMyTransfer(bool *state,int *input,int zeropinnum ,int unonum);
	~CMyTransfer(void);
	void setStatus(bool *state,int *input,int zeropinnum ,int unonum);
	void setPowerpin(int pin);
	void start();
	void stop();
	void pause();
	void restart();
	bool InitCom(CString com,int boardrate);
	bool CloseCom();
	friend DWORD WINAPI recvThread(void * param);
	friend DWORD WINAPI sendThread(void * param);
	int WriteCom(CString buffer);
	int  ReadCom();
	bool CheckConnect();
	bool ReConnect();
	void SendCmd(CString cmd);
	void SendCmd(int chipnum,int cmd,int val);
	CString CreateCmd(int cmdType,int chipnum,int cmd,int val);
	void DelayFinish(int chipnum,int timemax);
	void GetStatus(MyString str);
	void byte2Bit(byte val,bool *b);
	byte bit2Byte(bool *b);

	void Xmove(int chipnum,int value);
	void Xmoveto(int chipnum,int value);
	void Xhome(int chipnum);
	void setXSpeedMode(int chipnum,int value);
	void Ymove(int chipnum,int value);
	void Ymoveto(int chipnum,int value);
	void Yhome(int chipnum);
	void setYSpeedMode(int chipnum,int value);
	void Zmove(int chipnum,int value);
	void Zmoveto(int chipnum,int value);
	void Zhome(int chipnum);
	void setZSpeedMode(int chipnum,int value);
	void Kmove(int chipnum,int value);
	void Kmoveto(int chipnum,int value);
	void Khome(int chipnum);
	void setKSpeedMode(int chipnum,int value);
	void Lmove(int chipnum,int value);
	void LmoveWithoutReturn(int chipnum,int value);
	void Lmoveto(int chipnum,int value);
	void Lhome(int chipnum);
	void setLSpeedMode(int chipnum,int value);
	void UnionMove(int chipnum,int x,int y,int z ,int k,int l,int speed);
	void Smove(int chipnum);
	void PullUNOUp(int chipnum,int pin);
	void PullUNODown(int chipnum,int pin);
	void PullUp(int pin);
	void PullDown(int pin);
	void PowerOn();
	void PowerOff();
	int getPinMode(int zeropin);
	void setButtonNum(int num);
	void setButtonPress(int i,int lightpin,int presspin,bool *outcheckstate,int lightmode=0,int presstime=200,int sparktime=1000);
	CButtonPress * getButton(int i);
	

	
public:
	HANDLE hCom,ThreadSend,ThreadRecv;
	fstream file;
	
	bool end;
	bool isRead;
	bool isWrite;
	bool isPause;
	bool ispause;

	long hearttimer;
	long disconnect_limittime;
	CString comName;
	int boardRate;
	bool poweron;
	
	bool sendover,recvover;
	bool slock;
	bool *status;
	bool *chip;
	int *input;
	int inputnum;
	int chipnum;
	int powerpin;
	int syncBytenum;
	MyString oldstr;
	bool wlock;
    CButtonPress *button;
	int buttonnum;
	bool send_sure;
	char readBuffer[512];  
	

};

class CButtonPress
{
public:
	CMyTransfer *tf;
    bool *checkstate;
	bool canstate;
	bool pressstate;
	int lightpin;
	int presspin;
	long presstimer;
	int presstime;
	long sparktimer;
	int sparktime;
	int lightmode;
	bool lightstate;
	
	CButtonPress()
	{
		canstate=false;
		pressstate=false;
	}
	void SetButtonPress(CMyTransfer * tf,int lightpin,int presspin,bool *outcheckstate,int lightmode=0,int presstime=200,int sparktime=1000)
	{
		this->tf=tf;
		canstate=false;
		checkstate=outcheckstate;
		lightstate=false;
		this->lightpin=lightpin;
		this->presspin=presspin;
		this->presstime=presstime;
		this->lightmode=lightmode;
		this->sparktime=sparktime;
		presstimer=0;
		sparktimer=0;

	}
	void SetCanState(bool state)
	{
		canstate=state;
		if(state==false)
		{
			pressstate=false;
			presstimer=0;
			tf->PullUp(lightpin);
			lightstate=false;
		}
		else
		{
			*checkstate=false;//重置使能位，结果也重置以便接受新按压信号。
			tf->PullDown(lightpin);
			lightstate=true;

		}

	}
	void Check()  //输出按键点击标志位
	{
		if(!canstate)
			return;
		if(lightmode==0)
		{
			if(!lightstate)
			{
				lightstate=true;
				tf->PullDown(lightpin);
			}
			
		}
		else
		{
			spark();
		}
		if(!pressstate)
		{
			if(tf->getPinMode(presspin)==0)
			{
				pressstate=true;
				Delay(presstimer,presstime);
			}
		}
		else
		{
			if(Delay(presstimer,presstime))
			{
				if(tf->getPinMode(presspin)==0)
				{
				*checkstate=true;
				SetCanState(false);
				}
				else
				{
					pressstate=false;
					presstimer=0;
				}
			}
			else
			{
				if(tf->getPinMode(presspin)==1)
				{
				pressstate=false;
				presstimer=0;
				}

			}
		}

	}
	bool Delay(long &timer,int time)
	{
		if(timer==0)
		{
			timer=clock();
			return false;
		}
		else
		{
			if(clock()-timer>time)
			{
				timer=0;
				return true;
			}
			else
				return false;
		}

	}
	void spark()
	{
		if(Delay(sparktimer,sparktime))
		{
			if(!lightstate)
				tf->PullDown(lightpin);
			else
				tf->PullUp(lightpin);
			lightstate=!lightstate;

		}
	}	
};