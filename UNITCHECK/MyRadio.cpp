#include "StdAfx.h"
#include "MyRadio.h"

CMyRadio::CMyRadio(void)
{
	m_x=0;
	m_y=0;
	m_width=0;
	m_height=0;
	On=NULL;
	Off=NULL;
	state=0;
	visible=true;
	enable=true;
	textr1="radio1";
	textr2="radio2";
	kindstr="类型";

}

CMyRadio::~CMyRadio(void)
{
	if(On!=NULL)
	{
		::delete On;
		On=NULL;
	}
	if(Off!=NULL)
	{
		::delete Off;
		Off=NULL;

	}
}
void CMyRadio::setPos(int x,int y,int w,int h)
{
	m_x=x;
	m_y=y;
	m_width=w;
	m_height=h;
	ks=CRect(m_x+3,m_y+2,m_x+3+(m_height-4),m_y+2+(m_height-4));
	gls=CRect(m_x+m_width/2+3,m_y+2,m_x+m_width/2+3+(m_height-4),m_y+2+(m_height-4));
}
void CMyRadio::setImage(CString onPath,CString offPath)
{
	On=::new Image(onPath.AllocSysString());
	Off=::new Image(offPath.AllocSysString());
}
void CMyRadio::setText(CString text1,CString text2)
{
	textr1=text1;
	textr2=text2;
}
void CMyRadio::setVisiable(bool visible)
{
	this->visible=visible;

}
void CMyRadio::setEnable(bool enable)
{
	this->enable=enable;

}
void CMyRadio::setState(int state)
{
	this->state=state;

}
void CMyRadio::setKind(int kind)
{
	if(kind==0)
		kindstr="抗酸";
	else if(kind==1)
		kindstr="革兰氏";
}
bool CMyRadio::OnLButtonDown(CPoint &point)
{
	if(visible && enable)
	{
		if(gls.PtInRect(point))
		{
			state=1;
			return true;
		}
		else  if(ks.PtInRect(point))
		{
			state=0;
			return true;
		}
	}
	return false;
}
int   CMyRadio::Writextring( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/,Color col /*=Color::Black */)
{
	FontFamily  fontFamily(L"华文楷体");
	SolidBrush brush(col);
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
	//	content.ReleaseBuffer();//
	delete w;
	return stringSize.Width;
}
void CMyRadio::DrawSelf(Graphics &g)
{
	if(visible)
	{
		Pen pen(Color::Silver,1.5);
		SolidBrush en(Color(56,176,200));
		SolidBrush disen(Color(156,156,156));
		g.FillRectangle(&(enable?en:disen),m_x,m_y,m_width,m_height);
		g.DrawRectangle(&pen,m_x,m_y,m_width,m_height);


		Writextring(g ,20,textr1, CRect(ks.right-6,ks.top+2,m_x+m_width/2,m_y+m_height),true);
		Writextring(g ,20,textr2, CRect(gls.right-8,gls.top+2,m_x+m_width,m_y+m_height),true);
		Writextring(g,20,kindstr,CRect(m_x-70,m_y+4,m_x,m_y+m_height),true);
		if(On!=NULL && Off!=NULL)
		{
			if(state==0)
			{
				g.DrawImage(On,ks.left,ks.top,ks.Width(),ks.Height());
				g.DrawImage(Off,gls.left,gls.top,gls.Width(),gls.Height());

			}
			else
			{
				g.DrawImage(Off,ks.left,ks.top,ks.Width(),ks.Height());
				g.DrawImage(On,gls.left,gls.top,gls.Width(),gls.Height());
			}
		}
	}
}
