#include "StdAfx.h"
#include "BiaoTiLan.h"
#include <Mmsystem.h>            
#pragma comment(lib, "Winmm.lib")  

BiaoTiLan::BiaoTiLan(void)
{
	Warning = FALSE;
	Alpha = 60;
	dir = true;
	m_time=timeGetTime();
	m_lastTime = 1000;
	m_show="警示信息在此";
}

BiaoTiLan::~BiaoTiLan(void)
{
}

int BiaoTiLan::WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ )
{
	FontFamily  fontFamily(L"华文楷体");
	SolidBrush brush(box);
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

void BiaoTiLan::DrawCGlass( Graphics &g )
{
	SolidBrush sb(shelf);
	SolidBrush bc(box);

	int Jiange = (m_height-m_width*0.05*2)/15;

	if(Warning)
	{
// 		if(dir)
// 		{
// 			if(Alpha>127)
// 				dir = false;
// 			else
// 				Alpha += 5;
// 		}else
// 		{
// 			if(Alpha<60)
// 				dir = true;
// 			else
// 				Alpha -= 3;
// 		}
		if(dir)
		{
			Color temp(255, box.GetRed(), box.GetGreen(), box.GetBlue());
			DrawRoundRectange(g,m_x,m_y,m_width,m_height,4,temp,m_width*0.02,false, temp);
			CRect rc;
			rc.left = m_x+m_width/7;
			rc.top = m_y-40; 
			rc.right = m_x+m_width;
			rc.bottom = m_y+m_height;
			int w = WriteString(g, 30, m_show, rc, false);

			rc.left =  m_x+(m_width-w)/2;
			WriteString(g, 30, m_show, rc, true);
		}
		else
			DrawRoundRectange(g,m_x,m_y,m_width,m_height,4,shelf,8,false, box);
		if (ISTimeOver(m_lastTime))
		{
			m_time=timeGetTime();
			dir = !dir;
		}
	}else
		DrawRoundRectange(g,m_x,m_y,m_width,m_height,4,shelf,8,false, box);
	if(m_title!="")
	{
		CRect rc;
		rc.left = m_x+m_width/7;
		rc.top = m_y-35; 
		rc.right = m_x+m_width;
		rc.bottom = m_y+m_height;
		int w = WriteString(g, 25, m_show, rc, false);

		rc.left =  m_x+(m_width-w)/2;
		if(m_width-w<0)
			rc.left=m_x-5;
		WriteString(g, 25, m_title, rc, true);
	}

}

void BiaoTiLan::DrawRoundRectange( Graphics &g, float x, float y, float Width, float Height, float arcSize, Color lineColor, float lineWidth, bool fillPath, Color fillColor )
{
	// 小矩形的半宽（hew）和半高（heh）  
	float hew = Width/arcSize/2;  
	float heh = Height/arcSize/2;  

	// 圆角修正
	float bi=hew-heh;
	if (bi<0)
	{
		bi=-bi;
	}
	if(bi>10)  
	{  
		hew = heh = hew>heh ? heh : hew;  
	}  

	//设置画图时的滤波模式为消除锯齿现象  
	g.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);  


	// 绘图路径  
	GraphicsPath roundRectPath;  

	// 保存绘图路径  
	roundRectPath.AddLine(x+hew, y, x+Width-hew, y);  // 顶部横线  
	roundRectPath.AddArc(x+Width-2*hew, y, 2*hew, 2*heh, 270, 90); // 右上圆角  

	roundRectPath.AddLine(x+Width, y+heh, x+Width, y+Height-heh);  // 右侧竖线  
	roundRectPath.AddArc(x+Width-2*hew, y+Height-2*heh, 2*hew, 2*heh, 0, 90); // 右下圆角  

	roundRectPath.AddLine(x+Width-hew, y+Height, x+hew, y+Height);  // 底部横线  
	roundRectPath.AddArc(x, y+Height-2*heh, 2*hew, 2*heh, 90, 90); // 左下圆角  

	roundRectPath.AddLine(x, y+Height-heh, x, y+heh);  // 左侧竖线  
	roundRectPath.AddArc(x, y, 2*hew, 2*heh, 180, 90); // 左上圆角  

	//创建画笔  
	Pen pen(lineColor, lineWidth);  

	// 绘制矩形  
	g.DrawPath(&pen, &roundRectPath);  

	// 是否填充  
	if(!fillPath)  
	{  
		return;  
	}  
	else if(fillColor.GetAlpha() == 0)  
	{  
		fillColor = lineColor; // 若未指定填充色，则用线条色填充  
	}  

	// 创建画刷  
	SolidBrush brush(fillColor);  

	// 填充  
	g.FillPath(&brush, &roundRectPath);  
}

void BiaoTiLan::SetColor( Color s, Color b )
{
	shelf = s;
	box = b;
}

void BiaoTiLan::Setpos( int x, int y, int w, int h )
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
}

bool BiaoTiLan::ISTimeOver( long time )
{
	DWORD t2 = timeGetTime();
	return (t2-m_time)>time ? true: false;
}