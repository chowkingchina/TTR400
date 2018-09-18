// Photo.cpp : 实现文件
//

#include "stdafx.h"
#include "TPJ10.h"
#include "Photo.h"

// CPhoto 对话框

IMPLEMENT_DYNAMIC(CPhoto, CDialog)

CPhoto::CPhoto(CWnd* pParent /*=NULL*/)
	: CDialog(CPhoto::IDD, pParent)
{
	g_rcShowWin.left =0;
	g_rcShowWin.right =0;
	g_rcShowWin.top =0;
	g_rcShowWin.bottom =0;
	dwCard=0;




}

CPhoto::~CPhoto()
{
	delete DeviceInfo[dwCard].m_pWnd;

}

void CPhoto::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_photo, m_Photo);
}


BEGIN_MESSAGE_MAP(CPhoto, CDialog)
	ON_BN_CLICKED(IDOK, &CPhoto::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPhoto::OnBnClickedCancel)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CPhoto 消息处理程序

void CPhoto::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	::CreateDirectory("C:\\test",NULL);
	TakePhoto(0,_T("C:\\test\\testpic.jpg"));
}

void CPhoto::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	
	
}

BOOL CPhoto::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
// 	BOOL bInitSdk = VCAInitSdk(this->m_hWnd, PCI_MEMORY_VIDEOMEMORY);
// 
// 	if ( !bInitSdk )
// 	{
// 		::AfxMessageBox(_T("VC404卡驱动初始化失败！"));
// 		return FALSE;
// 	}
// 
// 	int m_dwDevNum = VCAGetDevNum(); //获得卡的通道数
// 	if ( !m_dwDevNum )
// 	{
// 		::AfxMessageBox(_T("请确定VC404卡驱动程序是否安装成功！"));
// 		return FALSE;
// 	}
// 
// 	CRect rc;
// 	GetClientRect(&rc);
// 	ClientToScreen(&rc);
// 	m_Photo.MoveWindow(rc.left,rc.top,720,480);
// 	BOOL m_b = VCAOpenDevice( 0, m_Photo.m_hWnd);
// 	VCASetVidPreviewSize(0, 720, 480);
// 	m_b = VCAStartVideoPreview(0);
	m_nDevNum=m_DeviceControl.InitDevice ();
	if(m_nDevNum==1) 
	{
		::MoveWindow(GetDlgItem(IDC_photo)->GetSafeHwnd(),0,0,DeviceInfo[dwCard].dwWidth,	DeviceInfo[dwCard].dwHeight,false);
	}
	m_Photo.GetClientRect (&g_rcShowWin);



	if(m_nDevNum<1)
	{
		::AfxMessageBox("摄像头检测失败！ ");
		return FALSE;
	}
	else
	{

		////////////////
		// 		if ( !- t() )
		// 		{
		// 			::AfxMessageBox(_T("Create windows class false"));
		// 			return FALSE;
		// 		}

		for (int j=0; j<m_nDevNum; j++)
		{
			OnCreateWindow( j );


		}

		for (int i=0; i<m_nDevNum; i++)
		{
			DeviceInfo[i].dwWidth =720;
			DeviceInfo[i].dwHeight =576;
			//yuv2 type
			DeviceInfo[i].dwColorspace=2;
			DeviceInfo[i].dwFrameRate=25;
			//pal =0x20  ntsc=0x01;
			DeviceInfo[i].dwVidStandard=32;
			//open device
			DeviceInfo[i].dwChannelHandle =m_DeviceControl.OpenDevice (i, &DeviceInfo[i].dwOpenDevState );



			if (DeviceInfo[i].dwOpenDevState!=0)
			{
				::AfxMessageBox("open device false");
				return FALSE;
			}
			else
			{

				//connect the device
				DeviceInfo[i].dwConnectState=m_DeviceControl.ConnectDevice(DeviceInfo[i].dwChannelHandle,
					DeviceInfo[i].dwVidStandard,
					DeviceInfo[i].dwColorspace,
					DeviceInfo[i].dwWidth,
					DeviceInfo[i].dwHeight,
					DeviceInfo[i].dwFrameRate);
				if (DeviceInfo[i].dwConnectState)
				{
					//start preview
					DeviceInfo[i].dwPrviewState=m_DeviceControl.StartPrview(DeviceInfo[i].dwChannelHandle,
						DeviceInfo[i].dwPrvHandle,
						&DeviceInfo[i].dwPrvRect ,
						0,
						true);	
					//设置隔行算法为标准

					m_DeviceControl.EnableDeinterlace(DeviceInfo[i].dwChannelHandle,1,true);

					//设置降噪算法
					DXEnableDenoise(DeviceInfo[i].dwChannelHandle,65);

				}


				if (!DeviceInfo[i].dwPrviewState)
				{
					::AfxMessageBox("Start Preview Flase");
					return FALSE;
				} 


			}

		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CPhoto::TakePhoto( int num, CString name )
{

// 	BOOL m_b = VCAOpenDevice( num, m_Photo.m_hWnd);
// 	VCASetVidPreviewSize(num, 720, 480);
// 	m_b = VCAStartVideoPreview(num);
// 	Sleep(100);
// 	BOOL h = VCASaveAsJpegFile(num, name);
// 	Sleep(80);
// 	h = VCASaveAsJpegFile(num, name);
// 	Sleep(80);
// 	h = VCASaveAsJpegFile(num, name);
// 	Sleep(80);
// 	h = VCASaveAsJpegFile(num, name);
// 	m_b =VCAStopVideoPreview(num);
// 	m_b = VCACloseDevice(num);
	if (DeviceInfo[dwCard].dwConnectState)
	{
		m_DeviceControl.SnapPicture(DeviceInfo[num].dwChannelHandle,_T(name.GetBuffer(name.GetLength())),1,NULL);
	}

}

BOOL CPhoto::CreateWindowClass()
{
	// 	wsprintf(m_strClassname, "DEMO_Window");
	// 	m_wc.cbSize        = sizeof(m_wc);
	// 	m_wc.style         = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW ;//CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW
	// 	m_wc.lpfnWndProc   = MainWndProc;
	// 	m_wc.hInstance     = AfxGetInstanceHandle();
	// 	m_wc.lpszClassName = m_strClassname;
	// 	m_wc.hbrBackground = CreateSolidBrush(RGB( 255, 0, 255 )  );
	// 	m_wc.hCursor       = LoadCursor( NULL, IDC_ARROW );//LoadCursor(g_Hinstance, MAKEINTRESOURCE (IDC_ARROW));
	// 	m_wc.cbClsExtra    = 0;
	// 	m_wc.cbWndExtra    = 0;
	// 	m_wc.hIcon         = NULL;
	// 	m_wc.hIconSm       = NULL;
	// 	m_wc.lpszMenuName  = NULL;
	// 
	// 	if ( 0 == RegisterClassEx( &m_wc ) &&
	// 		ERROR_CLASS_ALREADY_EXISTS != GetLastError() )
	// 		return FALSE;
	return TRUE;

}

void CPhoto::OnCreateWindow( DWORD dwCard )
{
	CRect rcShowWin;
	rcShowWin = g_rcShowWin;
	DWORD dwStyle	   = WS_VISIBLE | WS_CHILD;
	HWND hDeskopWnd    = m_Photo.m_hWnd;

	if ( DeviceInfo[dwCard].m_pWnd )
	{
		return;
	}

	if ( m_nDevNum == 1 )
	{


		DeviceInfo[dwCard].dwDispWidth = 720;
		DeviceInfo[dwCard].dwDispHeight = 576;

		DeviceInfo[dwCard].dwDispPosX = ( DWORD( dwCard % 2 ) ) * ( rcShowWin.Width() / 2 ) + 1; //+ (DWORD)rcShowWin.left;
		DeviceInfo[dwCard].dwDispPosY = ( DWORD( dwCard / 2 ) ) * ( rcShowWin.Height() / 2 );// + //(DWORD)rcShowWin.top;

	}

	if ( m_nDevNum > 1 && m_nDevNum <= 4 )
	{
		DeviceInfo[dwCard].dwDispWidth = (DWORD)rcShowWin.Width() / 2 ;
		DeviceInfo[dwCard].dwDispHeight = (DWORD)rcShowWin.Height() / 2;
		DeviceInfo[dwCard].dwDispPosX = ( DWORD( dwCard % 2 ) ) * ( rcShowWin.Width() / 2 ) + 1; //+ (DWORD)rcShowWin.left;
		DeviceInfo[dwCard].dwDispPosY = ( DWORD( dwCard / 2 ) ) * ( rcShowWin.Height() / 2 );// + //(DWORD)rcShowWin.top;

	}



	CRect rc(DeviceInfo[dwCard].dwDispPosX,
		DeviceInfo[dwCard].dwDispPosY,
		DeviceInfo[dwCard].dwDispPosX+DeviceInfo[dwCard].dwDispWidth,
		DeviceInfo[dwCard].dwDispPosY+	DeviceInfo[dwCard].dwDispHeight
		);


	CChannelWnd *pvw=new CChannelWnd;
	pvw->Create(100+dwCard,rc,this);

	DeviceInfo[dwCard].m_pWnd=pvw;
	DeviceInfo[dwCard].dwPrvHandle =pvw->m_hWnd;
	DeviceInfo[dwCard].m_pWnd->GetClientRect (& DeviceInfo[dwCard].dwPrvRect);
}
void CPhoto::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	ShowWindow(false);
	GetParent()->ShowWindow(true);


}
