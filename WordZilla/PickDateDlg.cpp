
// PickDateDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "WordZilla.h"
#include "PickDateDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "WordZillaView.h"
#include "ChildFrm.h"
#include "CntrItem.h"
#include "WordZillaDoc.h"

// диалоговое окно PickDateDlg

IMPLEMENT_DYNAMIC(PickDateDlg, CDialogEx)

PickDateDlg::PickDateDlg(CWnd* pParent /*=NULL*/)
	: //CDialogEx(PickDateDlg::IDD, pParent),
	m_DateValue(COleDateTime::GetCurrentTime())
{

}

PickDateDlg::~PickDateDlg()
{
}

void PickDateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_DateValue);
}


BEGIN_MESSAGE_MAP(PickDateDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &PickDateDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &PickDateDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений PickDateDlg


void PickDateDlg::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	ShowWindow(SW_HIDE);
}


void PickDateDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	CMainFrame *pMain = (CMainFrame*)AfxGetMainWnd();
	CChildFrame * pChild = (CChildFrame*)pMain->GetActiveFrame();
	if(pChild == NULL){
		return;
	}
	CWordZillaView *pView = (CWordZillaView*)pChild->GetActiveView();
	if(pView == NULL){
		return;
	}
	CString sDate=m_DateValue.Format("%B %d %Y");
	pView->GetRichEditCtrl().ReplaceSel(sDate);
	pView->SetFocus();
}
