#include "StdAfx.h"
#include "ToolBar.h"

ToolBar::ToolBar(void)
{
	img = NULL;
	Disable = NULL;
	State = 0;
}

ToolBar::~ToolBar(void)
{
	if (img != NULL)
	{
		::delete img;
		img = NULL;
	}
	if (Disable != NULL)
	{
		::delete Disable;
		img = NULL;
	}
}

void ToolBar::SetImage( CString src, CString gra )
{
	img = ::new Image(src.AllocSysString());
	Disable= ::new Image(gra.AllocSysString());
}

int ToolBar::WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ )
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
//	content.ReleaseBuffer();//
	delete w;
	return stringSize.Width;
}

void ToolBar::Setpos( int x, int y, int w, int h, int iw )
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_imagewidth = iw;
}

void ToolBar::DrawCGlass( Graphics &g )
{
	CRect rc;
	if (State == 0)
	{
		g.DrawImage(img,m_x+(m_width-m_imagewidth)/2,m_y,m_imagewidth,m_imagewidth);	
		rc.left = m_x+m_width/7;
		rc.top = m_y+m_imagewidth; 
		rc.right = m_x+m_width;
		rc.bottom = m_y+20;
	}
	if (State == 1)
	{
		g.DrawImage(Disable,m_x+(m_width-m_imagewidth)/2,m_y,m_imagewidth,m_imagewidth);
		rc.left = m_x+m_width/7;
		rc.top = m_y+m_imagewidth; 
		rc.right = m_x+m_width;
		rc.bottom = m_y+20;
	}
	if (State == 2)
	{
		g.DrawImage(img,m_x,m_y,m_width,m_height);
		rc.left = m_x+m_width/7;
		rc.top = m_y+m_width; 
		rc.right = m_x+m_width;
		rc.bottom = rc.top+20;
	}
	
	if (m_show != _T(""))
	{
		int w = WriteString(g, 20, m_show, rc, false);

		rc.left =  m_x+(m_width-w)/2;
		WriteString(g, 20, m_show, rc, true);
	}

}

void ToolBar::SetShow(CString Title)
{
	m_show = Title;
}	

bool ToolBar::SetState( CPoint p )
{
	if (State != 1)
	{
		CRect rc;
		rc.left = m_x;
		rc.top = m_y; 
		rc.right = m_x+m_width;
		rc.bottom = m_y+m_height;
		if (rc.PtInRect(p))
		{
			State = 2;
			return true;
		}else
		{
			State = 0;
			return false;
		}	
	}
	return false;
}

void ToolBar::Enable( bool En )
{
	if (En)
	{
		State = 0;
	}else
	{
		State = 1;
	}
}
