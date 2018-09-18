#include "StdAfx.h"
#include "Message.h"

CMessage::CMessage(void)
{
	setPos(CRect(500,300,750,450));
	imgbkg=NULL;
	imgokon=NULL;
	imgokoff=NULL;
	imgcancelon=NULL;
	imgcanceloff=NULL;
	imgconfirmon=NULL;
	imgconfirmoff=NULL;
	showtime=60;
	timer=0;
	visible=false;
	msg="提示信息";
	state=0;
}

CMessage::~CMessage(void)
{
	if(imgbkg!=NULL)
		delete imgbkg;
	if(imgokon!=NULL)
		delete imgokon;
	if(imgokoff!=NULL)
		delete imgokoff;
}
void CMessage::setPos(CRect rect)
{
	this->rect=rect;
	this->rectconfirm=CRect(rect.left+rect.Width()*2/5,rect.top+rect.Height()*4/5,rect.left+rect.Width()*3/5,rect.bottom-rect.Height()/10);
	this->rectok=CRect(rect.left+rect.Width()*1/5,rect.top+rect.Height()*4/5,rect.left+rect.Width()*2/5,rect.bottom-rect.Height()/10);
	this->rectcancel=CRect(rect.left+rect.Width()*3/5,rect.top+rect.Height()*4/5,rect.left+rect.Width()*4/5,rect.bottom-rect.Height()/10);
}
void CMessage::setMsg(CString title)
{
	this->msg=title;

}
void CMessage::Show(CString title,int time,int mode)
{
	setShowTime(time);
	setMsg(title);
	this->mode=mode;
	ShowWindow(true);
}
void CMessage::ShowBlock(CString title,int time,int mode)
{
	setShowTime(time);
	setMsg(title);
	this->mode=mode;
	ShowWindow(true);
	while(visible)
	{
		Sleep(50);
	}
}
void CMessage::setShowTime(int time)
{
	this->showtime=time;

}
void CMessage::ShowWindow(bool visible)
{
	this->visible=visible;
}


int   CMessage::WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ )
{
	FontFamily  fontFamily(L"华文楷体");
	SolidBrush brush(Color::Black);
	Gdiplus::Font  myFont(&fontFamily, Size, FontStyleRegular, UnitPixel);
	StringFormat fmt;
	fmt.SetAlignment(StringAlignmentCenter);
	fmt.SetLineAlignment(StringAlignmentCenter);
	SizeF stringSize, strSize(1000,1000);
	//测量输出字符串所需要的矩形空间
	//	CWideCharString txtOutW(txtOut);
	WCHAR *w;
	int len = MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)content, -1, NULL, 0);
	w = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)content, -1, w, len); 

	g.MeasureString(w, len, &myFont, strSize, &fmt, &stringSize);
	if (xie)
	{
		RectF r((int)rc.left, (int)rc.top, (int)/*rc.left+370+*/stringSize.Width+10, (int)/*rc.top+720+*/stringSize.Height);
		g.DrawString(w, len, &myFont, r, &fmt, &brush);
	}
	//content.ReleaseBuffer();//
	delete w;
	return stringSize.Width;
}
void CMessage::Draw(Graphics &g)
{
	if(visible)
	{
		int timeleft=0;
		if(timer==0)
		{
			timer=clock();
			timeleft=showtime;

		}
		else
		{
			timeleft=showtime-(clock()-timer)/1000;
			if(timeleft<=0)
			{
				timer=0;
				timeleft=0;
				visible=false;
			}
		}
		if(imgbkg!=NULL)
		{
			g.DrawImage(imgbkg,rect.left,rect.top,rect.Width(),rect.Height());
		}
		else
		{
			g.DrawRectangle(&Pen(Color::Silver,4),rect.left,rect.top,rect.Width(),rect.Height());
			g.FillRectangle(&SolidBrush(Color(150,60,70,200)),rect.left,rect.top,rect.Width(),rect.Height());
		}
		if(mode==0)
		{
			Image *imgconfirm;


			if(state==0)
			{
				imgconfirm=imgconfirmon;
			}
			else
			{
				imgconfirm=imgconfirmoff;
			}
			if(imgconfirm!=NULL)
			{
				g.DrawImage(imgconfirm,rectconfirm.left,rectconfirm.top,rectconfirm.Width(),rectconfirm.Height());

			}
			else
			{
				g.DrawRectangle(&Pen(Color::Silver,2),rectconfirm.left,rectconfirm.top,rectconfirm.Width(),rectconfirm.Height());
				g.FillRectangle(&SolidBrush(state==0?Color(150,100,100,200):Color(150,150,150,200)),rectconfirm.left,rectconfirm.top,rectconfirm.Width(),rectconfirm.Height());
			}
			WriteString(g,15,"确定",rectconfirm,true);
		}
		else
		{
			Image *imgok,*imgcancel;
			if(state==2)
			{
				imgok=imgokon;

			}
			else
			{
				imgok=imgokoff;
			}
			if(state==3)
			{
				imgcancel=imgcancelon;
			}
			else
			{
				imgcancel=imgcanceloff;
			}
			if(imgok!=NULL)
			{
				g.DrawImage(imgok,rectok.left,rectok.top,rectok.Width(),rectok.Height());

			}
			else
			{
				g.DrawRectangle(&Pen(Color::Silver,2),rectok.left,rectok.top,rectok.Width(),rectok.Height());
				g.FillRectangle(&SolidBrush(state!=2?Color(150,100,100,200):Color(150,150,150,200)),rectok.left,rectok.top,rectok.Width(),rectok.Height());

			}
			if(imgcancel!=NULL)
			{
				g.DrawImage(imgcancel,rectcancel.left,rectcancel.top,rectcancel.Width(),rectcancel.Height());

			}
			else
			{
				g.DrawRectangle(&Pen(Color::Silver,2),rectcancel.left,rectcancel.top,rectcancel.Width(),rectcancel.Height());
				g.FillRectangle(&SolidBrush(state!=3?Color(150,100,100,200):Color(150,150,150,200)),rectcancel.left,rectcancel.top,rectcancel.Width(),rectcancel.Height());

			}
			WriteString(g,15,"确定",rectok,true);
			WriteString(g,15,"取消",rectcancel,true);


		}
		
		CString temp;
		temp.Format("倒计时结束还有%d秒",timeleft);
		CRect rc1=CRect(rect.left,rect.top+rect.Height()*2/4,rect.right,rect.top+rect.Height()*3/4);
		CRect rc2=CRect(rect.left,rect.top+rect.Height()*1/4,rect.right,rect.top+rect.Height()*2/4);
		int wd1=WriteString(g,20,temp,rc1,false);
		int wd2=WriteString(g,20,msg,rc2,false);
		rc1.left=rc1.left+(rc1.Width()-wd1)/2;
		rc2.left=rc2.left+(rc2.Width()-wd2)/2;
		WriteString(g,20,temp,rc1,true);
		WriteString(g,20,msg,rc2,true);


	}
}
void CMessage::onMouseMove(CPoint p)
{
	if(visible)
	{
		if(rectconfirm.PtInRect(p) && mode==0)
		{
			state=1;
		}
		else if(rectok.PtInRect(p) && mode==1)
		{
			state=2;
		}
		else if(rectcancel.PtInRect(p) && mode==1)
		{
			state=3;
		}
		else
		{
			state=0;
		}
	}
}
void CMessage::onLButtonDown(CPoint p)
{
	if(visible)
	{
		if(mode==0)
		{
			if(rectconfirm.PtInRect(p))
			{
				timer=0;
				visible=false;

			}
		}
		else if(mode==1)
		{
			if(rectok.PtInRect(p))
			{
				timer=0;
				visible=false;
				returnval=true;

			}
			else if(rectcancel.PtInRect(p))
			{
				timer=0;
				visible=false;
				returnval=false;

			}


		}
	}

}
