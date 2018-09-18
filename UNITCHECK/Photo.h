#pragma once
#include "afxwin.h"
/*#include "Sa7134Capture.h"*/
#include "DeviceControl.h"


// CPhoto 对话框

class CPhoto : public CDialog
{
	DECLARE_DYNAMIC(CPhoto)

public:
	CPhoto(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPhoto();

// 对话框数据
	enum { IDD = IDD_PHOTO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	void TakePhoto( int num, CString name );
	virtual BOOL OnInitDialog();
	CStatic m_Photo;
	RECT			 g_rcShowWin;
	DWORD dwCard;
	WNDCLASSEX             m_wc;
	int 			m_nDevNum;
	DEVICE_INFO  DeviceInfo[23];
	DeviceControl m_DeviceControl;
	BOOL CreateWindowClass( );            //创建窗口类
	void OnCreateWindow( DWORD dwCard ); //创建预览子窗体
	afx_msg void OnClose();
};
