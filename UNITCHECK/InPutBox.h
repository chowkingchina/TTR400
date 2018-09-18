#pragma once
#include "ToolBar.h"
class InPutBox
{
public:
	InPutBox(void);
	~InPutBox(void);
	ToolBar m_toolbar[12];
	float m_imagewidth;
	float m_x; 
	float m_y;
	float m_width;
	float m_height;

	bool InPutOver;// ‰»ÎÕÍ≥…
	bool beenget;
	int m_returnnum;
	CString m_num;
	void Setpos(int x, int y, int w, int h, int iw);
	void  DrawCGlass(Graphics &g);
	int   WriteString( Graphics& g ,int Size, CString content, CRect rc, bool xie /*= false*/ ); 
	void OnMouseMove(CPoint point);
	void ONLBtnDown(CPoint point);
	int GetNum();
};
