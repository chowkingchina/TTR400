#include "StdAfx.h"
#include "TextStatic.h"

CTextStatic::CTextStatic(void)
{
	content="";
	m_x=0;
	m_y=0;
	m_width=0;
	m_height=0;
	textColor=Color::Black;
	size=20;
}

CTextStatic::~CTextStatic(void)
{
}
void CTextStatic::setText(CString text)
{
	content=text;

}
void CTextStatic::setPos(int x,int y,int w,int h)
{
	m_x=x;
	m_y=y;
	m_width=w;
	m_height=h;

}
void CTextStatic::setColor(Color c)
{
	textColor=c;
}
void CTextStatic::setSize(int s)
{
	size=s;

}
void CTextStatic::DrawSelf(Graphics &g)
{
	if(content!="")
	{
		int ziw=WriteString(g,size,content,CRect(m_x,m_y,m_x+m_width,m_y+m_height));
		WriteString(g,size,content,CRect(m_x+(m_width-ziw)/2,m_y,m_x+m_width,m_y+m_height),true,textColor);
	}

}
int   CTextStatic::WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/,Color col /*=Color::Black */)
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