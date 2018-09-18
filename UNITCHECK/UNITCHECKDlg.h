
// UNITCHECKDlg.h : 头文件
//

#pragma once
#include	<fstream>
using namespace std;

// CUNITCHECKDlg 对话框
class CUNITCHECKDlg : public CDialog
{
	// 构造
public:
	CUNITCHECKDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CUNITCHECKDlg();

	// 对话框数据
	enum { IDD = IDD_UNITCHECK_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	

	// 实现
protected:
	HICON m_hIcon;


	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	fstream file;
	HANDLE hThread;
	HANDLE hThread1;
	HANDLE hThread2;
	HANDLE hThread3;

	bool showthreaddone;
	bool endflag;

	bool initcheck;
	bool scpcheck;
	bool startcheck;
	bool changemodecheck;
	CString megafilepath;
	void GetStatus(MyString str);
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo5();
	afx_msg void OnCbnSelchangeCombo9();
	afx_msg void OnCbnSelchangeCombo13();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	bool pincheck();
	void sendCmd(int chipnum,int cmd,long val);
	int uno_id;
	CString ini_filepath;
	int  m_unox_exist;
	int  m_unox_pinmc;
	int  m_unox_pinfx;
	int  m_unox_pinzero;
	int  m_unoy_exist;
	int  m_unoy_pinmc;
	int  m_unoy_pinfx;
	int  m_unoy_pinzero;
	int  m_unoz_exist;
	int  m_unoz_pinmc;
	int  m_unoz_pinfx;
	int  m_unoz_pinzero;
	int  m_unok_exist;
	int  m_unok_pinmc;
	int  m_unok_pinfx;
	int  m_unok_pinzero;
	int  m_unol_exist;
	int  m_unol_pinmc;
	int  m_unol_pinfx;
	int  m_unol_pinzero;


	int m_unox_speedmode;
	int m_unox_hspeedh;
	int m_unox_hspeedm;
	int m_unox_hspeedl;
	int m_unox_lspeedh;
	int m_unox_lspeedm;
	int m_unox_lspeedl;


	int m_unoy_speedmode;
	int m_unoy_hspeedh;
	int m_unoy_hspeedm;
	int m_unoy_hspeedl;
	int m_unoy_lspeedl;
	int m_unoy_lspeedm;
	int m_unoy_lspeedh;


	int m_unoz_speedmode;
	int m_unoz_hspeedh;
	int m_unoz_hspeedm;
	int m_unoz_hspeedl;
	int m_unoz_lspeedl;
	int m_unoz_lspeedm;
	int m_unoz_lspeedh;

	int m_unok_speedmode;
	int m_unok_hspeedh;
	int m_unok_hspeedm;
	int m_unok_hspeedl;
	int m_unok_lspeedl;
	int m_unok_lspeedm;
	int m_unok_lspeedh;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnCbnSelchangeCombo18();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnCbnSelchangeCombo22();
	afx_msg void OnCbnSelchangeCombo21();
	long m_a_x_pos;
	long m_a_x_step;
	long m_a_y_pos;
	long m_a_y_step;
	long m_a_z_pos;
	long m_a_z_step;
	long m_a_k_pos;
	long m_a_k_step;
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnCbnSelchangeCombo23();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnCbnSelchangeCombo24();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnCbnSelchangeCombo25();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnEnChangeEdit33();
	afx_msg void OnBnClickedButton32();
	afx_msg void OnBnClickedButton33();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton34();
	afx_msg void OnBnClickedButton35();
	afx_msg void OnBnClickedButton39();
	afx_msg void OnCbnSelchangeCombo8();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnCbnSelchangeCombo17();
	afx_msg void OnCbnSelchangeCombo19();
	afx_msg void OnCbnSelchangeCombo20();
	afx_msg void OnCbnSelchangeCombo27();
	afx_msg void OnCbnSelchangeCombo28();
	afx_msg void OnCbnSelchangeCombo26();
	afx_msg void OnCbnSelchangeCombo29();
	afx_msg void OnCbnSelchangeCombo14();
	afx_msg void OnBnClickedButton41();
	afx_msg void OnBnClickedButton42();
	int m_unol_speedmode;
	long m_unol_hspeedh;
	long m_unol_lspeedh;
	long m_unol_hspeedm;
	long m_unol_lspeedm;
	long m_unol_hspeedl;
	long m_unol_lspeedl;
	afx_msg void OnCbnSelchangeCombo30();
	afx_msg void OnBnClickedButton43();
	long m_a_l_pos;
	long m_a_l_step;
	afx_msg void OnCbnSelchangeCombo31();
	afx_msg void OnBnClickedButton44();
	afx_msg void OnBnClickedButton45();
	afx_msg void OnBnClickedButton46();
	afx_msg void OnBnClickedButton36();
};

