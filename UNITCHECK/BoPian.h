#pragma once
//#include "LuJing.h"
class CBoPian
{
public:
	CBoPian(void);
	~CBoPian(void);
	bool HuiZhi;
	int num;
	float m_x; 
	float m_y;
	float m_width;
	float m_height;

	Color shelf;
	Color box;
	Color inner;//内在的颜色

	bool InnerShine;
	int InnerAlpha;
	bool INNER;
	int dir;
	void SetInner( Color i);
	void SetColor( Color s, Color b);
	void Setpos(int x, int y, int w, int h);
	void DrawCGlass(Graphics &g);
	int   WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ );
	void DrawRoundRectange(Graphics &g, float x, float y, float Width, float Height, float arcSize, Color lineColor, float lineWidth, bool fillPath, Color fillColor);  
};
