
// WordZilla.h : главный файл заголовка для приложения WordZilla
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CWordZillaApp:
// О реализации данного класса см. WordZilla.cpp
//

class CWordZillaApp : public CWinAppEx
{
public:
	CWordZillaApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWordZillaApp theApp;
