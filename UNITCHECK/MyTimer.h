#pragma once

class CMyTimer
{
public:
	CMyTimer(void);
	CMyTimer(long delaytime);

	~CMyTimer(void);
private:
	long timer;
	long delaytime;
	
public:
	void setDelaytime(long delaytime);
	bool delay(long &timer,long time);
	long get_time_left();
	bool delay();
	void wait();
	void start();
	void clear();

};
