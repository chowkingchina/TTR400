#include "StdAfx.h"
#include "MyTimer.h"

CMyTimer::CMyTimer(void)
{
	timer=0;
	delaytime=0;
}
CMyTimer::CMyTimer(long delaytime)
{
	timer=0;
	this->delaytime=delaytime;

}

CMyTimer::~CMyTimer(void)
{

}
bool CMyTimer::delay(long &timer,long time)
{
	if(timer==0)
	{
		timer=clock();
		return false;
	}
	else
	{
		if(clock()-timer>=time)
		{
			timer=0;
			return true;
		}
		else
		{
			return false;
		}
	}

}
bool CMyTimer::delay()
{
	return delay(timer,delaytime);
}
void CMyTimer::setDelaytime(long delaytime)
{
	this->delaytime=delaytime;
}
void CMyTimer::wait()
{
	while(!delay(timer,delaytime))
	{
		Sleep(1);
	}
}
void CMyTimer::start()
{
	timer=clock();
}
void CMyTimer::clear()
{
	timer=0;
}
long CMyTimer::get_time_left()
{
	long lefttime=0;
	if(timer>0)
	{
		lefttime=delaytime-(clock()-timer);
		if(lefttime<0)
			lefttime=0;
	}
	else
		lefttime=0;
	return lefttime;
}
