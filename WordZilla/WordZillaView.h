
// WordZillaView.h : интерфейс класса CWordZillaView
//

#pragma once
#include "atlcomtime.h"
#include "WordZillaDoc.h"
class CWordZillaCntrItem;

class CWordZillaView : public CRichEditView
{
protected: // создать только из сериализации
	CWordZillaView();
	DECLARE_DYNCREATE(CWordZillaView)

// Атрибуты
public:
	CWordZillaDoc* GetDocument() const ;
// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CWordZillaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFontFormat();
	afx_msg void OnColor();
	afx_msg void OnCharBold();
	afx_msg void OnUpdateCharBold(CCmdUI *pCmdUI);
	afx_msg void OnCharItalic();
	afx_msg void OnUpdateCharItalic(CCmdUI *pCmdUI);
	afx_msg void OnCharUnderline();
	afx_msg void OnUpdateCharUnderline(CCmdUI *pCmdUI);
	afx_msg void OnParaCenter();
	afx_msg void OnUpdateParaCenter(CCmdUI *pCmdUI);
	afx_msg void OnParaLeft();
	afx_msg void OnUpdateParaLeft(CCmdUI *pCmdUI);
	afx_msg void OnParaRight();
	afx_msg void OnUpdateParaRight(CCmdUI *pCmdUI);
	afx_msg void OnBullet();
	afx_msg void OnUpdateBullet(CCmdUI *pCmdUI);
//	afx_msg void OnEditPasteDate();
private:
	COleDateTime m_PasteDate;
};

#ifndef _DEBUG  // отладочная версия в WordZillaView.cpp
inline CWordZillaDoc* CWordZillaView::GetDocument() const
   { return reinterpret_cast<CWordZillaDoc*>(m_pDocument); }
#endif

