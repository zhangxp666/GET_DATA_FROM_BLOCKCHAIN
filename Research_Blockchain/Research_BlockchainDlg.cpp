
// Research_BlockchainDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Research_Blockchain.h"
#include "Research_BlockchainDlg.h"
#include "afxdialogex.h"
#include "factory.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CResearchBlockchainDlg 对话框



CResearchBlockchainDlg::CResearchBlockchainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RESEARCH_BLOCKCHAIN_DIALOG, pParent)
	, deal_type(0)

	, show_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CResearchBlockchainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, deal_type);
	DDX_Control(pDX, IDC_COMBO1, blockchain_name);
	DDX_Control(pDX, IDC_EDIT4, show);
	DDX_Control(pDX, IDC_EDIT1, num1);
	DDX_Control(pDX, IDC_EDIT2, num2);
	DDX_Control(pDX, IDC_EDIT3, num3);
	DDX_Text(pDX, IDC_EDIT4, show_str);
}

BEGIN_MESSAGE_MAP(CResearchBlockchainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CResearchBlockchainDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CResearchBlockchainDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CResearchBlockchainDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDOK, &CResearchBlockchainDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO4, &CResearchBlockchainDlg::OnBnClickedRadio4)
END_MESSAGE_MAP()


// CResearchBlockchainDlg 消息处理程序

BOOL CResearchBlockchainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	blockchain_name.SetCurSel(0);
	deal_type = 1;
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CResearchBlockchainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CResearchBlockchainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CResearchBlockchainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CResearchBlockchainDlg::OnBnClickedRadio1()
{
	deal_type = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void CResearchBlockchainDlg::OnBnClickedRadio2()
{
	deal_type = 2;
	// TODO: 在此添加控件通知处理程序代码
}


void CResearchBlockchainDlg::OnBnClickedRadio3()
{
	deal_type = 3;
	// TODO: 在此添加控件通知处理程序代码
}


void CResearchBlockchainDlg::OnBnClickedOk()
{
 	initLogger();

	int nIndex = blockchain_name.GetCurSel();//获取目标区块链名的编号
	if (nIndex == 0)
	{
		MessageBox(_T("未选择区块链"), _T("参数错误"), MB_OK);
		return;
	}

 	Blockchain* block = factory().create(nIndex);
	block->set_some_param();

	CString str1, str2, count;
	int start, end;
	std::string data;
	switch (deal_type)
	{
	case 1:
		num1.GetWindowText(str1);	
		if (str1 == "") {
			MessageBox(_T("目标区块值不能为空啊"), _T("参数错误"), MB_OK);
			break;
		}			
		start = _ttoi(str1);
		str1.ReleaseBuffer();
		block->read_block_data(start);
		data = block->get_data();
		show_str = data.c_str();
		UpdateData(FALSE);
		show.SetSel(-1, -1);
		show_str.ReleaseBuffer();
		break;
	case 2:
		num2.GetWindowText(str1);
		num3.GetWindowText(str2);
		if (str1 == ""||str2=="")
		{
			MessageBox(_T("参数不能为空啊"), _T("参数错误"), MB_OK);
			break;
		}
		start = _ttoi(str1);
		end = _ttoi(str2);
		str1.ReleaseBuffer();
		str2.ReleaseBuffer();
		for (int i = start; i <= end; i++)
		{

			block->read_block_data(i);
			block->block_into_db();
			LOG(INFO, "the block had into db:" + std::to_string(i));
			count.Format(_T("%d"), i);
			show_str += "the block had into db:";
			show_str += count;
			show_str += "\r\n";
			UpdateData(FALSE);
			show.SetSel(-1, -1);
		}

		show_str.ReleaseBuffer();
		break;
	case 3:
		start = block->get_block_num_in_db();
		end = block->get_block_num();
		count.Format(_T("%d"), start);
		show_str += "the block num in database is:";
		show_str += count;
		show_str += "\r\n";
		count.Format(_T("%d"), end);
		show_str += "the block num in net is:";
		show_str += count;
		show_str += "\r\n";

		UpdateData(FALSE);
		for (int i = start; i <= end; i++)
		{
			block->read_block_data(i);
			block->block_into_db();
			LOG(INFO, "the block had into db:" + std::to_string(i));
			count.Format(_T("%d"), i);
			show_str += "the block had into db:";
			show_str += count;
			show_str += "\r\n";
			UpdateData(FALSE);
			show.SetSel(-1, -1);
		}

		show_str.ReleaseBuffer();
		break;
	case 4:
		
		end = block->get_block_num();		
		count.Format(_T("%d"), end);
		show_str += "the block num in net is:";
		show_str += count;
		show_str += "\r\n";
		UpdateData(FALSE);
		show.SetSel(-1, -1);
		show_str.ReleaseBuffer();

		break;
	default:
		break;
	}
	delete block;
	endLogger();
	//show.SetWindowText(strCBText);
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CResearchBlockchainDlg::OnBnClickedRadio4()
{
	deal_type = 4;
	// TODO: 在此添加控件通知处理程序代码
}
