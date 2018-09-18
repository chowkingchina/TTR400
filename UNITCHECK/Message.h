#pragma once


class CMessage
{
public:
	CMessage(void);
	~CMessage(void);
public:
	CRect rect,rectok,rectcancel,rectconfirm;
	Image *imgbkg;
	Image *imgokon,*imgokoff,*imgcanceloff,*imgcancelon,*imgconfirmon,*imgconfirmoff;
	int showtime;
	long timer;
	bool visible;
	CString msg;
	int mode;
	int state;
	bool returnval;

	void setPos(CRect rect);
	void setMsg(CString title);
	void setShowTime(int time=60);
	void ShowWindow(bool visible);
	int   WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ ); 
	void Show(CString title,int time,int mode=0);
	void ShowBlock(CString title,int time,int mode=0);
	void Draw(Graphics &g);
	void onMouseMove(CPoint p);
	void onLButtonDown(CPoint p);



	
};
