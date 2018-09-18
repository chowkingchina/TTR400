#include "StdAfx.h"
#include "InPutBox.h"

InPutBox::InPutBox(void)
{
	InPutOver = true;
	m_returnnum = 0;
	beenget=false;
	m_num = _T("0");
	CString temp;
	for (int i=0; i<10; i++)
	{
		temp.Format(_T("res/%d.png"), i);
		m_toolbar[i].SetImage(temp, temp);
	}
	m_toolbar[10].SetImage(_T("res/Del.png"), _T("res/Del.png"));
	m_toolbar[11].SetImage(_T("res/Ok.png"), _T("res/Ok.png"));
}	

InPutBox::~InPutBox(void)
{
}

void InPutBox::Setpos( int x, int y, int w, int h, int iw )
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = w;
	m_imagewidth = iw;
	for (int i=1; i<10; i++)
	{
		m_toolbar[i].Setpos(m_x+(w/3)*((i-1)%3),m_y+(w/3)*((i-1)/3),w/3,w/3,m_imagewidth);
	}
	m_toolbar[0].Setpos(m_x+(w/3)*((9)%3),m_y+(w/3)*((9)/3),w/3,w/3,m_imagewidth);
	m_toolbar[10].Setpos(m_x+(w/3)*((10)%3),m_y+(w/3)*((10)/3),w/3,w/3,m_imagewidth);
	m_toolbar[11].Setpos(m_x+(w/3)*((11)%3),m_y+(w/3)*((11)/3),w/3,w/3,m_imagewidth);
}	

void InPutBox::DrawCGlass( Graphics &g )
{
	if(!InPutOver)
	{
		for (int i=0; i<12; i++)
		{
			m_toolbar[i].DrawCGlass(g);
		}
		m_num.Format(_T("%d"), m_returnnum);
		CRect rc;
		rc.left = m_x+m_width/7;
		rc.top = m_y-80; 
		rc.right = m_x+m_width;
		rc.bottom = rc.top+60;
			
		int w = WriteString(g, 60, m_num, rc, false);

		rc.left =  m_x+(m_width-w)/2;
		WriteString(g, 60, m_num, rc, true);

		//w = WriteString(g, 60, _T("请输入密码"), rc, false);
		//rc.left =  m_x+(m_width-w)/2;
		//rc.top = rc.top-80; 
		//WriteString(g, 60, _T("请输入密码"), rc, true);
	}

}

int InPutBox::WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ )
{
	FontFamily   fontFamily(L"华文楷体");
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

void InPutBox::OnMouseMove( CPoint point )
{
	if(!InPutOver)
	{
	for (int i=0; i<12; i++)
	{
		m_toolbar[i].SetState(point);
	}
	}
}

void InPutBox::ONLBtnDown( CPoint point )
{
	if(!InPutOver)
	{
		for (int i=0; i<10; i++)
		{
			if (m_toolbar[i].SetState(point))
			{
				if (m_returnnum/100<1)
				{
					m_returnnum=m_returnnum*10+i;
				}
			}
		}
		if (m_toolbar[10].SetState(point))
		{
			m_returnnum=m_returnnum/10;
		}
		if (m_toolbar[11].SetState(point))
		{
			InPutOver = true;
		}
	}
}

int InPutBox::GetNum()
{
	return m_returnnum;
}
