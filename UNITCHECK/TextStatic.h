#pragma once

class CTextStatic
{
public:
	CTextStatic(void);
	~CTextStatic(void);
	CString content;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	Color textColor;
	int size;
	void setText(CString text);
	void setPos(int x,int y,int w,int h);
	void setColor(Color c);
	void setSize(int s);
	void DrawSelf(Graphics &g);
	int   WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie = false,Color c =Color::Black ); 
	
};
