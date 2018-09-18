#pragma once

class CJinDuTiao
{
public:
	CJinDuTiao(void);
	~CJinDuTiao(void);
	void Draw(Graphics &g);
	RectF rect2F(CRect &rect);
	void DrawRoundRectange( Graphics &g, float x, float y, float Width, float Height, float arcSize, Color lineColor, float lineWidth, bool fillPath, Color fillColor);
	int WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ );
	void SetJinDu(int per,CString inst);
	void over();
public:
	CRect insrect,jdrect,perstrrect;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int percent;
	CString instruct;
	bool visible;

};
