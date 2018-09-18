#pragma once

class ToolBar
{
public:
	ToolBar(void);
	~ToolBar(void);
	
	int State;

	float m_imagewidth;
	float m_x; 
	float m_y;
	float m_width;
	float m_height;

	Image* img;
	Image* Disable;
	CString m_show;//显示的信息

	void Enable(bool En);
	bool SetState(CPoint p);
	void SetShow(CString Title);
	void SetImage(CString src, CString gra);
	int   WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ ); 
	void Setpos(int x, int y, int w, int h, int iw);
	void  DrawCGlass(Graphics &g);
};
