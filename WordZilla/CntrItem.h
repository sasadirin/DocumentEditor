
// CntrItem.h : ��������� ������ CWordZillaCntrItem
//

#pragma once

class CWordZillaDoc;
class CWordZillaView;

class CWordZillaCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CWordZillaCntrItem)

// ������������
public:
	CWordZillaCntrItem(REOBJECT* preo = NULL, CWordZillaDoc* pContainer = NULL);
		// ����������. pContainer ����� ����� �������� NULL ��� ���������� IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE ������� ������� � ������ ������������ �
		//  ������� �����������. ������ �������� OLE ��������� �
		//  ����������� �� ��������, �� ������� NULL

// ��������
public:
	CWordZillaDoc* GetDocument()
		{ return reinterpret_cast<CWordZillaDoc*>(CRichEditCntrItem::GetDocument()); }
	CWordZillaView* GetActiveView()
		{ return reinterpret_cast<CWordZillaView*>(CRichEditCntrItem::GetActiveView()); }

// ����������
public:
	~CWordZillaCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

