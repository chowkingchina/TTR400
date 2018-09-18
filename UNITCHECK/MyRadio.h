#pragma once

class CMyRadio
{
public:
	CMyRadio(void);
	~CMyRadio(void);
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	Image * On;
	Image * Off;
	int state;
	bool visible;
	bool enable;
	CString textr1,textr2,kindstr;
	CRect gls,ks;
	void setPos(int x,int y,int w,int h);
	void setImage(CString onPath,CString offPath);
	void setText(CString text1,CString text2);
	void setKind(int kind);
	void setVisiable(bool visible);
	void setEnable(bool enable);
	void setState(int state);
	bool OnLButtonDown(CPoint &point);
	int   Writextring( Graphics& g ,int Size, CString content, CRect rc, bool xie = false,Color c =Color::Black ); 
	void DrawSelf(Graphics &g);
};
