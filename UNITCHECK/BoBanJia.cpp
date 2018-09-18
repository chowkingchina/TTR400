#include "StdAfx.h"
#include "BoBanJia.h"

CBoBanJia::CBoBanJia(void)
{
	for (int i=0; i<10; i++)
	{
		Exist[i] = true;
		num[i] = 0;
		state[i]=0;
	}
	HuiZhi = false;
}

CBoBanJia::~CBoBanJia(void)
{
}

void CBoBanJia::SetColor(Color s, Color b)
{
	shelf = s;
	box = b;
}
void CBoBanJia::SetBoxColor(Color s)
{
	box = s;

}

void CBoBanJia::Setpos( int x, int y, int w, int h )
{
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
}



void CBoBanJia::DrawCGlass( Graphics &g )
{
	if(HuiZhi)
	{
		SolidBrush sb(shelf);
		SolidBrush bx(box);
		DrawRoundRectange(g,m_x,m_y,m_width,m_height,2,shelf,m_width*0.02,true, shelf);
		for (int i=0; i<10; i++)
		{
			if (Exist[i])
			{
				if(state[i]==0)
					g.FillEllipse(&bx,m_x+m_width/10*i+m_width/120,m_y,m_width*5/60,m_height);
				else
					g.FillEllipse(&SolidBrush(Color::Red),m_x+m_width/10*i+m_width/120,m_y,m_width*5/60,m_height);
				CRect rc;
				rc.left = m_x+m_width/10*i+m_width/120;
				rc.top = m_y; 
				rc.right = m_x+m_width/10*i+m_width*11/120;
				rc.bottom = m_y+m_height;
				CString temp; 
				temp.Format(_T("%d"), num[i]);
				int w=WriteString(g, 20, temp, CRect(rc.left+rc.Width()/2-10,rc.top+rc.Height()/2-15,rc.right,rc.bottom), false);
				WriteString(g, 20, temp, CRect(rc.left+(rc.Width()-w)/2+5,rc.top+rc.Height()/2-15,rc.right,rc.bottom), true);


			}
		}
	}
}

int CBoBanJia::WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ )
{
	FontFamily  fontFamily(L"���Ŀ���");
	SolidBrush brush(shelf);
	Gdiplus::Font  myFont(&fontFamily, Size, FontStyleRegular, UnitPixel);
	StringFormat fmt;
	fmt.SetAlignment(StringAlignmentCenter);
	fmt.SetLineAlignment(StringAlignmentCenter);
	SizeF stringSize, strSize(1000,1000);
	//��������ַ�������Ҫ�ľ��οռ�
	//	CWideCharString txtOutW(txtOut);
		WCHAR *w;
		int len = MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)content, -1, NULL, 0);
		w = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)content, -1, w, len); 

	g.MeasureString(w, len, &myFont, strSize, &fmt, &stringSize);
	if (xie)
	{
//		RectF r((int)rc.left, (int)rc.top, (int)/*rc.left+370+*/stringSize.Width+10, (int)/*rc.top+720+*/stringSize.Height);
		RectF r((int)rc.left-6, (int)rc.top+6, (int)/*rc.left+370+*/stringSize.Width+10, (int)/*rc.top+720+*/stringSize.Height);
		g.DrawString(w, len, &myFont, r, &fmt, &brush);
	}
	//content.ReleaseBuffer();//
	delete w;
	return stringSize.Width;
}

void CBoBanJia::DrawRoundRectange( Graphics &g, float x, float y, float Width, float Height, float arcSize, Color lineColor, float lineWidth, bool fillPath, Color fillColor )
{
	float hew = Width/arcSize/2;  
	float heh = Height/arcSize/2;  

	// Բ������
	float bi=hew-heh;
	if (bi<0)
	{
		bi=-bi;
	}
	if(bi>10)  
	{  
		hew = heh = hew>heh ? heh : hew;  
	}  

	//���û�ͼʱ���˲�ģʽΪ�����������  
	g.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);  


	// ��ͼ·��  
	GraphicsPath roundRectPath;  

	// �����ͼ·��  
	roundRectPath.AddLine(x+hew, y, x+Width-hew, y);  // ��������  
	roundRectPath.AddArc(x+Width-2*hew, y, 2*hew, 2*heh, 270, 90); // ����Բ��  

	roundRectPath.AddLine(x+Width, y+heh, x+Width, y+Height-heh);  // �Ҳ�����  
	roundRectPath.AddArc(x+Width-2*hew, y+Height-2*heh, 2*hew, 2*heh, 0, 90); // ����Բ��  

	roundRectPath.AddLine(x+Width-hew, y+Height, x+hew, y+Height);  // �ײ�����  
	roundRectPath.AddArc(x, y+Height-2*heh, 2*hew, 2*heh, 90, 90); // ����Բ��  

	roundRectPath.AddLine(x, y+Height-heh, x, y+heh);  // �������  
	roundRectPath.AddArc(x, y, 2*hew, 2*heh, 180, 90); // ����Բ��  

	//��������  
	Pen pen(lineColor, lineWidth);  

	// ���ƾ���  
	g.DrawPath(&pen, &roundRectPath);  

	// �Ƿ����  
	if(!fillPath)  
	{  
		return;  
	}  
	else if(fillColor.GetAlpha() == 0)  
	{  
		fillColor = lineColor; // ��δָ�����ɫ����������ɫ���  
	}  

	// ������ˢ  
	SolidBrush brush(fillColor);  

	// ���  
	g.FillPath(&brush, &roundRectPath);  
}


