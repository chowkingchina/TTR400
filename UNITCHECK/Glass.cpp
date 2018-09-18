#include "StdAfx.h"
#include "Glass.h"
using namespace Gdiplus;
CGlass::CGlass(void)
{
	warning=false;
	colordir=false;
	sparktime=1000;
	timer=0;
	RealUsedLiang=0;
	name="";
}

CGlass::~CGlass(void)
{
}
bool CGlass::IsTimeOver(long time)
{
	if(timer==0)
	{
		timer=clock();
		return false;
	}
	else
	{
		long inteval=clock()-timer;

		if(inteval<time)
		{
			return false;
		}
		else
		{
			timer=0;
			return true;
		}
	}


}
int CGlass::WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ )
{
	FontFamily  fontFamily(L"华文楷体");
	SolidBrush brush(Color::Black);
	Gdiplus::Font  myFont(&fontFamily, Size, FontStyleRegular, UnitPixel);
	StringFormat fmt;
	fmt.SetAlignment(StringAlignmentCenter);
	fmt.SetLineAlignment(StringAlignmentCenter);
	SizeF stringSize, strSize(1000,1000);
	//测量输出字符串所需要的矩形空间
	//CWideCharString txtOutW(txtOut);
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
void CGlass::DrawCGlass( Graphics &graphics )
{
///////////////////////////////////////画瓶口
	if(warning)
	{
		if(IsTimeOver(sparktime))
		{
			colordir=!colordir;
			glass=colordir?Color::White:Color::Red;
		}

	}
	else
	{
		glass=Color::White;

	}
	Pen pen(glass,m_width*0.15);
	Point points[] =
	{
		Point(m_x+m_width*0.25,m_y+m_height*0.025),
		Point(m_x+m_width*0.75,m_y+m_height*0.025),
		Point(m_x+m_width*0.75,m_y+m_height*0.1),
		Point(m_x+m_width*0.25,m_y+m_height*0.1),

	};
	float a=sizeof(points)/sizeof(Point);
	graphics.DrawClosedCurve(&pen, points, sizeof(points)/sizeof(Point), 0.2);
/////////////////////////////////////////画瓶身
	Point points1[] =
	{
		Point(m_x+m_width*0.3,m_y+m_height*0.11),
		Point(m_x+m_width*0.3,m_y+m_height*0.288),
		Point(m_x+m_width*0,m_y+m_height*0.88),
		Point(m_x+m_width*0.1,m_y+m_height*1),
		Point(m_x+m_width*0.9,m_y+m_height*1),
		Point(m_x+m_width*1,m_y+m_height*0.88),
		Point(m_x+m_width*0.7,m_y+m_height*0.288),
		Point(m_x+m_width*0.7,m_y+m_height*0.11),
	};
	 a=sizeof(points1)/sizeof(Point);
	graphics.DrawClosedCurve(&pen, points1, sizeof(points1)/sizeof(Point), 0.2);


	HatchStyle style=(HatchStyle)32;
	HatchBrush brush_tmp(style, glass, water);

	// 创建路径

	if (Liang<0.22)
	{
		Point points2[] =
		{
			Point(m_x+m_width*0.3,m_y+m_height*0.11+m_height*0.9*Liang),
			Point(m_x+m_width*0.3,m_y+m_height*0.288),
			Point(m_x+m_width*0,m_y+m_height*0.88),
			Point(m_x+m_width*0.1,m_y+m_height*1),
			Point(m_x+m_width*0.9,m_y+m_height*1),
			Point(m_x+m_width*1,m_y+m_height*0.88),
			Point(m_x+m_width*0.7,m_y+m_height*0.288),
			Point(m_x+m_width*0.7,m_y+m_height*0.11+m_height*0.9*Liang),
		};
		GraphicsPath path;
		//在路径中加入直线
		path.AddCurve(points2, sizeof(points2)/sizeof(Point), 0.2);
		//填充路径
		graphics.FillPath(&brush_tmp, &path);
	}
	if (Liang>=0.22 && Liang<0.8)
	{
		Point points2[] =
		{
			Point(m_x+m_width*0.3-m_width*Liang*0.4,m_y+m_height*0.288+m_height*0.9*Liang),
			Point(m_x+m_width*0,m_y+m_height*0.88),
			Point(m_x+m_width*0.1,m_y+m_height*1),
			Point(m_x+m_width*0.9,m_y+m_height*1),
			Point(m_x+m_width*1,m_y+m_height*0.88),
			Point(m_x+m_width*0.7+m_width*Liang*0.4,m_y+m_height*0.288+m_height*0.9*Liang),
		};
		GraphicsPath path;
		//在路径中加入直线
		path.AddCurve(points2, sizeof(points2)/sizeof(Point), 0.2);
		//填充路径
		graphics.FillPath(&brush_tmp, &path);
	}
	//CString temp;
	//temp.Format("%d%%",(int)((1-RealUsedLiang)*100));
	//int ziwidth=WriteString(graphics,20,temp,CRect(m_x,m_y+m_height+5,m_x+m_width,m_y+m_height+50),false);
	//WriteString(graphics,20,temp,CRect(m_x+(m_height-ziwidth)/2-5,m_y+m_height+5,m_x+m_width,m_y+m_height+500),true);
	if(name!="")
	{
		int ziw=WriteString(graphics,20,name,CRect(m_x,m_y-25,m_x+m_width/2,m_y+m_height),false);
		WriteString(graphics,20,name,CRect(m_x+(m_width-ziw)/2,m_y-25,m_x+m_width,m_y+m_height),true);


	}
}

void CGlass::SetLiang( float liang )
{
	liang = liang;
	RealUsedLiang=liang;
	if (liang<0.22)
	{
		Liang = liang;
	}else
	{
		Liang = liang*0.78;
	}
}

void CGlass::Setpos( int x, int y, int w, int h )
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
}	
void CGlass::setName(CString name)
{
	this->name=name;
}
void CGlass::SetColor( Color g, Color w)
{
	glass = g;
	water = w;
}	
void CGlass::SetWarningOn()
{
	warning=true;
	colordir=1;

}
void CGlass::SetWarningOff()
{
	warning=false;
	colordir=0;


}
int CGlass::GetX()
{
	return m_x+m_width/2;
}

int CGlass::GetY()
{
	return m_y;
}
