#pragma once

class BiaoTiLan
{
public:
	BiaoTiLan(void);
	~BiaoTiLan(void);

	DWORD  m_time;//存储的时间
	long m_lastTime;//

	float m_x; 
	float m_y;
	float m_width;
	float m_height;

	CString m_show;//显示的信息
	CString m_title;//显示的信息
	Color shelf;
	Color box;

	bool Warning;
	bool dir;
	int Alpha;
	bool ISTimeOver(long time);
	void Setpos(int x, int y, int w, int h);
	void SetColor( Color s, Color b);
	int   WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ );
	void  DrawCGlass(Graphics &g);
	void DrawRoundRectange(Graphics &g, float x, float y, float Width, float Height, float arcSize, Color lineColor, float lineWidth, bool fillPath, Color fillColor);  
};
