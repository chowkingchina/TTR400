#pragma once
class CBoBanJia
{
public:
	bool HuiZhi;//�������Ƿ����
	bool Exist[10];//6�������Ƿ����
	int num[10];//ÿ����������
	int state[10];
	CBoBanJia(void);
	~CBoBanJia(void);

	float m_x; 
	float m_y;
	float m_width;
	float m_height;


	Color shelf;
	Color box;
	void SetColor( Color s, Color b);
	void SetBoxColor(Color s);
	void Setpos(int x, int y, int w, int h);
	void Setpos();
	void Getpos();
	void DrawCGlass(Graphics &g);
	int   WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ );
	void DrawRoundRectange(Graphics &g, float x, float y, float Width, float Height, float arcSize, Color lineColor, float lineWidth, bool fillPath, Color fillColor);  
};
