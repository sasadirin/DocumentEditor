
// WordZillaView.cpp : ���������� ������ CWordZillaView
//

#include "stdafx.h"
#include "PickDateDlg.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "WordZilla.h"
#endif

#include "WordZillaDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "WordZillaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWordZillaView

IMPLEMENT_DYNCREATE(CWordZillaView, CRichEditView)

BEGIN_MESSAGE_MAP(CWordZillaView, CRichEditView)
	ON_WM_DESTROY()
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWordZillaView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FONT_FORMAT, &CWordZillaView::OnFontFormat)
	ON_COMMAND(ID_COLOR, &CWordZillaView::OnColor)
	ON_COMMAND(ID_CHAR_BOLD, &CWordZillaView::OnCharBold)
	ON_UPDATE_COMMAND_UI(ID_CHAR_BOLD, &CWordZillaView::OnUpdateCharBold)
	ON_COMMAND(ID_CHAR_ITALIC, &CWordZillaView::OnCharItalic)
	ON_UPDATE_COMMAND_UI(ID_CHAR_ITALIC, &CWordZillaView::OnUpdateCharItalic)
	ON_COMMAND(ID_CHAR_UNDERLINE, &CWordZillaView::OnCharUnderline)
	ON_UPDATE_COMMAND_UI(ID_CHAR_UNDERLINE, &CWordZillaView::OnUpdateCharUnderline)
	ON_COMMAND(ID_PARA_CENTER, &CWordZillaView::OnParaCenter)
	ON_UPDATE_COMMAND_UI(ID_PARA_CENTER, &CWordZillaView::OnUpdateParaCenter)
	ON_COMMAND(ID_PARA_LEFT, &CWordZillaView::OnParaLeft)
	ON_UPDATE_COMMAND_UI(ID_PARA_LEFT, &CWordZillaView::OnUpdateParaLeft)
	ON_COMMAND(ID_PARA_RIGHT, &CWordZillaView::OnParaRight)
	ON_UPDATE_COMMAND_UI(ID_PARA_RIGHT, &CWordZillaView::OnUpdateParaRight)
	ON_COMMAND(ID_BULLET, &CWordZillaView::OnBullet)
	ON_UPDATE_COMMAND_UI(ID_BULLET, &CWordZillaView::OnUpdateBullet)

//	ON_COMMAND(ID_EDIT_PASTE_DATE, &CWordZillaView::OnEditPasteDate)
END_MESSAGE_MAP()

// ��������/����������� CWordZillaView

CWordZillaView::CWordZillaView()
	: m_PasteDate(COleDateTime::GetCurrentTime())
{
	// TODO: �������� ��� ��������

}

CWordZillaView::~CWordZillaView()
{
}

BOOL CWordZillaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CWordZillaView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();
	CHARFORMAT2A cfm;
	cfm.cbSize=sizeof(cfm);
	cfm.dwMask = CFM_FACE | CFM_SIZE | CFM_BOLD;

	strcpy_s(cfm.szFaceName,"Arial");
	cfm.yHeight=200;
	cfm.dwEffects= 0; 
	
	SetCharFormat(cfm);

	// ������� ������� ������ (720 ���� = 1/2 �����)
	SetMargins(CRect(720, 720, 720, 720));
}


// ������ CWordZillaView


void CWordZillaView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CWordZillaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}


void CWordZillaView::OnDestroy()
{
	// ������������� ������� ��� ��������; ��� �����
	// � ������ ������������� ������������� �����������
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CRichEditView::OnDestroy();
}


void CWordZillaView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWordZillaView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ����������� CWordZillaView

#ifdef _DEBUG
void CWordZillaView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CWordZillaView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CWordZillaDoc* CWordZillaView::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWordZillaDoc)));
	return (CWordZillaDoc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CWordZillaView


void CWordZillaView::OnFontFormat()
{
	OnFormatFont();
	// TODO: �������� ���� ��� ����������� ������
}


void CWordZillaView::OnColor()
{
	CColorDialog dlg(m_charformat.crTextColor);
	if(dlg.DoModal()==IDOK){
		m_charformat.dwMask=CFM_COLOR;
		m_charformat.dwEffects=NULL;
		m_charformat.crTextColor=dlg.GetColor();
		SetCharFormat(m_charformat);
	}

	// TODO: �������� ���� ��� ����������� ������
}


void CWordZillaView::OnCharBold()
{
	// TODO: �������� ���� ��� ����������� ������
	OnCharEffect(CFM_BOLD,CFE_BOLD);

}


void CWordZillaView::OnUpdateCharBold(CCmdUI *pCmdUI)
{
	// TODO: �������� ���� ��� ����������� �� ���������� ������
	OnUpdateCharEffect(pCmdUI,CFM_BOLD,CFE_BOLD);
}


void CWordZillaView::OnCharItalic()
{
	// TODO: �������� ���� ��� ����������� ������
	OnCharEffect(CFM_ITALIC,CFE_ITALIC);

}


void CWordZillaView::OnUpdateCharItalic(CCmdUI *pCmdUI)
{
	// TODO: �������� ���� ��� ����������� �� ���������� ������
	OnUpdateCharEffect(pCmdUI,CFM_ITALIC,CFE_ITALIC);

}


void CWordZillaView::OnCharUnderline()
{
	OnCharEffect(CFM_UNDERLINE,CFE_UNDERLINE);
	// TODO: �������� ���� ��� ����������� ������
}


void CWordZillaView::OnUpdateCharUnderline(CCmdUI *pCmdUI)
{
	// TODO: �������� ���� ��� ����������� �� ���������� ������
	OnUpdateCharEffect(pCmdUI,CFM_UNDERLINE,CFE_UNDERLINE);

}


void CWordZillaView::OnParaCenter()
{
	// TODO: �������� ���� ��� ����������� ������
	OnParaAlign(PFA_CENTER);
}


void CWordZillaView::OnUpdateParaCenter(CCmdUI *pCmdUI)
{
	// TODO: �������� ���� ��� ����������� �� ���������� ������

	OnUpdateParaAlign(pCmdUI,PFA_CENTER);
}


void CWordZillaView::OnParaLeft()
{
	// TODO: �������� ���� ��� ����������� ������
	OnParaAlign(PFA_LEFT);

}


void CWordZillaView::OnUpdateParaLeft(CCmdUI *pCmdUI)
{
	// TODO: �������� ���� ��� ����������� �� ���������� ������
	OnUpdateParaAlign(pCmdUI,PFA_LEFT);
}


void CWordZillaView::OnParaRight()
{
	// TODO: �������� ���� ��� ����������� ������
	OnParaAlign(PFA_RIGHT);
}


void CWordZillaView::OnUpdateParaRight(CCmdUI *pCmdUI)
{
	// TODO: �������� ���� ��� ����������� �� ���������� ������
	OnUpdateParaAlign(pCmdUI,PFA_RIGHT);
}


void CWordZillaView::OnBullet()
{
	// TODO: �������� ���� ��� ����������� ������
	CRichEditView::OnBullet();
}


void CWordZillaView::OnUpdateBullet(CCmdUI *pCmdUI)
{
	// TODO: �������� ���� ��� ����������� �� ���������� ������
	CRichEditView::OnUpdateBullet(pCmdUI);

}




//void CWordZillaView::OnEditPasteDate()
//{
//	// TODO: �������� ���� ��� ����������� ������
//	PickDateDlg dlg;
//	dlg.m_DateValue = m_PasteDate;
//	if(dlg.DoModal() == IDOK){
//		m_PasteDate = dlg.m_DateValue;
//		CString sDate = m_PasteDate.Format("%B %d %Y");
//		GetRichEditCtrl().ReplaceSel(sDate);
//
//	}
//
//
//}
