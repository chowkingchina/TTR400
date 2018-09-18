#pragma once

class CGlass
{
public:
	CGlass(void);
	~CGlass(void);
public:
	float Liang;
	float RealUsedLiang;
	float m_x; 
	float m_y;
	float m_width;
	float m_height;
	
	Color glass;
	Color water;
	CString name;

	bool warning;
	bool colordir;
	long timer;
	long sparktime;

	void setName(CString name);
	void SetColor(Color g, Color w);

	bool IsTimeOver(long time);
	void SetWarningOn();
	void SetWarningOff();
	int   WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ );
	void DrawCGlass(Graphics &g);
	void SetLiang(float liang);
	void Setpos(int x, int y, int w, int h);
	int GetX();
	int GetY();
};
