
// WordZilla.h : ������� ���� ��������� ��� ���������� WordZilla
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CWordZillaApp:
// � ���������� ������� ������ ��. WordZilla.cpp
//

class CWordZillaApp : public CWinAppEx
{
public:
	CWordZillaApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWordZillaApp theApp;
