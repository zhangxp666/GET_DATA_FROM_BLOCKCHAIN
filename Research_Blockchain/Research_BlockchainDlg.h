
// Research_BlockchainDlg.h: 头文件
//

#pragma once


// CResearchBlockchainDlg 对话框
class CResearchBlockchainDlg : public CDialogEx
{
// 构造
public:
	CResearchBlockchainDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESEARCH_BLOCKCHAIN_DIALOG };
#endif

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
	int deal_type;
	CComboBox blockchain_name;
	CEdit show;
	CEdit num1;
	CEdit num2;
	CEdit num3;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadio4();
	CString show_str;
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	CWinThread* m_pThread;

	//************************************
	// Method:    ThreadFunction
	// FullName:  CResearchBlockchainDlg::ThreadFunction
	// Access:    public static 
	// Returns:   UINT
	// Parameter: LPVOID pParam  对话框的指针
	// DO:        这是程序的执行线程函数，从界面获取参数之后在这个线程里执行
	//************************************
	static UINT ThreadFunction(LPVOID pParam);

	//一些程序必备的参数
	int blockchian_id;
	int start;
	int end;
};
