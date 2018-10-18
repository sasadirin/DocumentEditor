
// WordZillaDoc.cpp : ���������� ������ CWordZillaDoc
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "WordZilla.h"
#endif

#include "WordZillaDoc.h"
#include "CntrItem.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWordZillaDoc

IMPLEMENT_DYNCREATE(CWordZillaDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CWordZillaDoc, CRichEditDoc)
	// �������� ���������� ���������� OLE
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_POPUP, &CWordZillaDoc::OnUpdateObjectVerbPopup)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()


// ��������/����������� CWordZillaDoc

CWordZillaDoc::CWordZillaDoc()
{
	// ����������� ������������ ����� OLE
	EnableCompoundFile();

	// TODO: �������� ��� ��� ������������ ������ ������������

}

CWordZillaDoc::~CWordZillaDoc()
{
}

BOOL CWordZillaDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: �������� ��� ��������� �������������
	// (��������� SDI ����� �������� ������������ ���� ��������)

	return TRUE;
}

CRichEditCntrItem* CWordZillaDoc::CreateClientItem(REOBJECT* preo) const
{
	return new CWordZillaCntrItem(preo, const_cast<CWordZillaDoc*>(this));
}




// ������������ CWordZillaDoc

void CWordZillaDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �������� ��� ����������
	}
	else
	{
		// TODO: �������� ��� ��������
	}

	// ����� �������� ������ CRichEditDoc �������� ������������
	//  �������� COleClientItem ��������� ����������.
	// TODO: ������� CRichEditDoc::m_bRTF = FALSE � ������ ������������ ��� ������
	CRichEditDoc::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ��������� ��� �������
void CWordZillaDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �������� ���� ��� ��� ����������� ������ ���������
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ��������� ������������ ������
void CWordZillaDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������� ���������� ������ �� ������ ���������. 
	// ����� ����������� ������ ����������� ������ � ������� ";"

	// ��������:  strSearchContent = _T("�����;�������������;����;������ ole;");
	SetSearchContent(strSearchContent);
}

void CWordZillaDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// ����������� CWordZillaDoc

#ifdef _DEBUG
void CWordZillaDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CWordZillaDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG


// ������� CWordZillaDoc
