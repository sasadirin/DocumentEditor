
// CntrItem.cpp : реализация класса CWordZillaCntrItem
//

#include "stdafx.h"
#include "WordZilla.h"

#include "WordZillaDoc.h"
#include "WordZillaView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// реализация CWordZillaCntrItem

IMPLEMENT_SERIAL(CWordZillaCntrItem, CRichEditCntrItem, 0)

CWordZillaCntrItem::CWordZillaCntrItem(REOBJECT* preo, CWordZillaDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: добавьте код для одноразового вызова конструктора
}

CWordZillaCntrItem::~CWordZillaCntrItem()
{
	// TODO: добавьте код очистки
}


// диагностика CWordZillaCntrItem

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

