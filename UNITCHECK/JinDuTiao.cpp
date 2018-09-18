#include "StdAfx.h"
#include "JinDuTiao.h"

CJinDuTiao::CJinDuTiao(void)
{
	m_x=520;
	m_y=350;
	m_width=300;
	m_height=50;
	percent=0;
	instruct="���������Ĺ����С���";
	visible=false;
	insrect=CRect(m_x+10,m_y+m_height/3,m_x+m_width-20,m_y+m_height*3/4-10);
	jdrect=CRect(m_x+10,m_y+m_height*9/10-10,m_x+m_width-20,m_y+m_height-10);
	perstrrect=CRect(jdrect.left+jdrect.Width()*percent/100-15,jdrect.top-5,jdrect.right,jdrect.bottom+10);
}

CJinDuTiao::~CJinDuTiao(void)
{

}
int   CJinDuTiao::WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ )
{
	FontFamily   fontFamily(L"���Ŀ���");
	SolidBrush brush(Color::Black);
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
		RectF r((int)rc.left, (int)rc.top, (int)/*rc.left+370+*/stringSize.Width+10, (int)/*rc.top+720+*/stringSize.Height);
		g.DrawString(w, len, &myFont, r, &fmt, &brush);
	}
	//content.ReleaseBuffer();//
	delete w;
	return stringSize.Width;
}
RectF CJinDuTiao::rect2F(CRect &rect)
{
	RectF rf;
	rf.X=rect.left;
	rf.Y=rect.top;
	rf.Width=rect.Width();
	rf.Height=rect.Height();
	return rf;

}
void CJinDuTiao::DrawRoundRectange( Graphics &g, float x, float y, float Width, float Height, float arcSize, Color lineColor, float lineWidth, bool fillPath, Color fillColor )
{
	// С���εİ��hew���Ͱ�ߣ�heh��  
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
void CJinDuTiao::Draw(Graphics &g)
{
	if(visible)
	{
		g.FillRectangle(&SolidBrush(Color(255,100,120,150)),m_x,m_y,m_width,m_height);
		g.DrawRectangle(&Pen(Color::Silver,4),m_x,m_y,m_width,m_height);
		RectF jdrectF=rect2F(jdrect);
		RectF perrectF=jdrectF;
		perrectF.Width=jdrectF.Width*percent/100;
//		g.FillEllipse(&SolidBrush(Color(255,100,120,150)),jdrectF);
		DrawRoundRectange(g,jdrectF.X,jdrectF.Y,jdrectF.Width,jdrectF.Height,2,Color::Silver,4,true,Color(255,100,120,150));
//		g.FillEllipse(&SolidBrush(Color(255,0,255,0)),perrectF);
		DrawRoundRectange(g,perrectF.X,perrectF.Y,perrectF.Width,perrectF.Height,2,Color::Silver,1,true,Color(255,0,255,0));
//		g.DrawEllipse(&Pen(Color::Silver,2),jdrectF);
		DrawRoundRectange(g,perrectF.X,perrectF.Y,perrectF.Width,perrectF.Height,2,Color::Silver,1,true,Color(255,0,255,0));
		int wd=WriteString(g,15,instruct,insrect,false);
		CRect rc=insrect;
		rc.left+=(rc.Width()-wd)/2;
		WriteString(g,15,instruct,rc,true);
		perstrrect=CRect(jdrect.left+jdrect.Width()*percent/100-15,jdrect.top-5,jdrect.right,jdrect.bottom+10);
		CString temp;
		temp.Format("%d%%",percent);
		WriteString(g,15,temp,perstrrect,true);

	}


}
void CJinDuTiao::SetJinDu(int per,CString inst)
{
	visible=true;
	percent=per;
	instruct=inst;

}
void CJinDuTiao::over()
{
	visible=false;
	percent=0;
	instruct="";
}
