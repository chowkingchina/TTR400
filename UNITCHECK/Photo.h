#pragma once
#include "afxwin.h"
/*#include "Sa7134Capture.h"*/
#include "DeviceControl.h"


// CPhoto �Ի���

class CPhoto : public CDialog
{
	DECLARE_DYNAMIC(CPhoto)

public:
	CPhoto(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPhoto();

// �Ի�������
	enum { IDD = IDD_PHOTO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	BOOL CreateWindowClass( );            //����������
	void OnCreateWindow( DWORD dwCard ); //����Ԥ���Ӵ���
	afx_msg void OnClose();
};
