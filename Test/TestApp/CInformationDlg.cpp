// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#include "stdafx.h"
#include "CInformationDlg.h"

IMPLEMENT_DYNAMIC(CInformationDlg, CDialogBase)

CInformationDlg::CInformationDlg(CWnd* pParent) : CDialogBase(IDD_INFO_DIALOG, pParent)
{}

CInformationDlg::~CInformationDlg()
{}

void CInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogBase::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CInformationDlg, CDialogBase)
END_MESSAGE_MAP()

BOOL CInformationDlg::OnInitDialog()
{
	CDialogBase::OnInitDialog();

	SetWindowText(m_WindowTitle);
	SetValue(IDC_INFO_TEXT, m_InfoText);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
