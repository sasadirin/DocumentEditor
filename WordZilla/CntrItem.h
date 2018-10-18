
// CntrItem.h : интерфейс класса CWordZillaCntrItem
//

#pragma once

class CWordZillaDoc;
class CWordZillaView;

class CWordZillaCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CWordZillaCntrItem)

// Конструкторы
public:
	CWordZillaCntrItem(REOBJECT* preo = NULL, CWordZillaDoc* pContainer = NULL);
		// Примечание. pContainer может иметь значение NULL для разрешения IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE требует наличия у класса конструктора с
		//  нулевым аргументами. Обычно элементы OLE создаются с
		//  указателями на документ, не равными NULL

// Атрибуты
public:
	CWordZillaDoc* GetDocument()
		{ return reinterpret_cast<CWordZillaDoc*>(CRichEditCntrItem::GetDocument()); }
	CWordZillaView* GetActiveView()
		{ return reinterpret_cast<CWordZillaView*>(CRichEditCntrItem::GetActiveView()); }

// Реализация
public:
	~CWordZillaCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

