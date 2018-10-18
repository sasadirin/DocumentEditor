#pragma once
#include "atlcomtime.h"
#include "resource.h"

// ���������� ���� PickDateDlg

class PickDateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PickDateDlg)

public:
	PickDateDlg(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~PickDateDlg();

// ������ ����������� ����
	enum { IDD = IDD_PICK_DATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	COleDateTime m_DateValue;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
