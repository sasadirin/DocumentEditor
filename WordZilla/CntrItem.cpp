
// CntrItem.cpp : ���������� ������ CWordZillaCntrItem
//

#include "stdafx.h"
#include "WordZilla.h"

#include "WordZillaDoc.h"
#include "WordZillaView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� CWordZillaCntrItem

IMPLEMENT_SERIAL(CWordZillaCntrItem, CRichEditCntrItem, 0)

CWordZillaCntrItem::CWordZillaCntrItem(REOBJECT* preo, CWordZillaDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: �������� ��� ��� ������������ ������ ������������
}

CWordZillaCntrItem::~CWordZillaCntrItem()
{
	// TODO: �������� ��� �������
}


// ����������� CWordZillaCntrItem

#ifdef _DEBUG
void CWordZillaCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CWordZillaCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

