// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#include "stdafx.h"
#include "TestApp.h"
#include "CPingDlg.h"

IMPLEMENT_DYNAMIC(CPingDlg, CDialogBase)

CPingDlg::CPingDlg(CWnd* pParent) : CDialogBase(IDD_PING_DIALOG, pParent)
{}

CPingDlg::~CPingDlg()
{}

void CPingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogBase::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPingDlg, CDialogBase)
	ON_BN_CLICKED(IDOK, &CPingDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CPingDlg::OnInitDialog()
{
	CDialogBase::OnInitDialog();

	SetValue(IDC_IP, L"172.217.17.78");
	SetValue(IDC_BUFFER_SIZE, L"32");
	SetValue(IDC_TTL, L"64");
	SetValue(IDC_TIMEOUT, L"5000");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CPingDlg::OnBnClickedOk()
{
	const auto bsize = GetSizeValue(IDC_BUFFER_SIZE);
	const auto ttl = GetSizeValue(IDC_TTL);

	if (IPAddress::TryParse(GetTextValue(IDC_IP).GetString(), m_IP))
	{
		if (bsize <= 255)
		{
			if (ttl <= 255)
			{
				m_BufferSize = static_cast<UInt8>(bsize);
				m_TTL = std::chrono::seconds(ttl);
				m_Timeout = std::chrono::milliseconds(GetSizeValue(IDC_TIMEOUT));

				CDialogBase::OnOK();
			}
			else AfxMessageBox(L"TTL should be between 0 and 255 seconds.", MB_ICONERROR);
		}
		else AfxMessageBox(L"Buffer size should be between 0 and 255 bytes.", MB_ICONERROR);
	}
	else AfxMessageBox(L"Invalid IP address.", MB_ICONERROR);
}
