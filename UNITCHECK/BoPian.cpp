#include "StdAfx.h"
#include "BoPian.h"

CBoPian::CBoPian(void)
{
	HuiZhi=false;
	num = 0;
	INNER = true;
	InnerAlpha = 125;
	InnerShine = false;
	dir=1;
}

CBoPian::~CBoPian(void)
{
}

int CBoPian::WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ )
{
	FontFamily  fontFamily(L"华文楷体");
	SolidBrush brush(box);
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

void CBoPian::SetColor( Color s, Color b )
{
	shelf = s;
	box = b;
}

void CBoPian::Setpos( int x, int y, int w, int h )
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
}

void CBoPian::DrawCGlass( Graphics &g )
{
	if(HuiZhi)
	{
		Pen blackPen(shelf, m_width*0.05);  
		SolidBrush sb(shelf);
		SolidBrush bx(box);
		DrawRoundRectange(g,m_x,m_y,m_width,m_height,2,shelf,m_width*0.05,false, shelf);
		DrawRoundRectange(g,m_x,m_y,m_width,m_height*0.25,2,shelf,m_width*0.02,true, shelf);

		DrawRoundRectange(g,m_x+m_width*0.1,m_y+m_height*0.5,m_width*0.8,m_height*0.4,2,shelf,m_width*0.05,false, shelf);
		if (INNER)
		{
			if (!InnerShine)
			{
				InnerAlpha = 255;
			}
			else
			{

				InnerAlpha+=dir*8;
				if(InnerAlpha>=255)
				{
					dir=-1;
					InnerAlpha=255;

				}
				else if(InnerAlpha<=0)
				{
					dir=1;
					InnerAlpha=0;

				}

			}
			Color c(InnerAlpha, inner.GetRed(), inner.GetGreen(), inner.GetBlue());
			inner = c;
			DrawRoundRectange(g,m_x+m_width*0.1,m_y+m_height*0.5,m_width*0.8,m_height*0.4,2,shelf,m_width*0.05,true, inner);
		}
		CRect rc;
		rc.left = m_x;
		rc.top = m_y; 
		rc.right = m_x+m_width;
		rc.bottom = m_y+m_height*0.25;
		if(true)//num!=0)
		{
			CString temp; 
			temp.Format(_T("%d"), num);
			WriteString(g, m_width*0.5, temp, rc, true);
		}
	}
}

void CBoPian::DrawRoundRectange( Graphics &g, float x, float y, float Width, float Height, float arcSize, Color lineColor, float lineWidth, bool fillPath, Color fillColor )
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

void CBoPian::SetInner( Color i )
{
	inner = i;
}
