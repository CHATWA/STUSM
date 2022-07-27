#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <cstring>
#include "afxdialogex.h"


// MainDlg �Ի���

class MainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MainDlg)

public:
	MainDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MainDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_Main };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	
	afx_msg void OnBnClickedButtonAll();
	afx_msg void OnBnClickedButtonOthers();
	afx_msg void OnBnClickedMfcbuttonAdd();
	afx_msg void OnPaint();

	// �꼶
	afx_msg void OnBnClickedRadioGra1();
	afx_msg void OnBnClickedRadioGra2();
	afx_msg void OnBnClickedRadioGra3();
	afx_msg void OnBnClickedRadioGra4();

	afx_msg void OnBnClickedRadiomaths();
	afx_msg void OnBnClickedRadioCpp();
	afx_msg void OnBnClickedRadioMan();
	afx_msg void OnBnClickedRadioWoman();
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonSort();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonStatisgraph();

	CListCtrl m_List;	// ��ʾѧ����ϸ�ɼ����б�

	CString m_STU;	// ��ǰ����ӵ�ѧ������

	CString m_Num;	//	��ѧ�������ı���

	CString m_Name;	// �����������ı���

	CString m_Class;	// �󶨰༶�����ı���

	CString m_Gra;		//	�꼶

	CString m_Sex;		//	�Ա�

	CString m_MathsD;	// �󶨸���ƽʱ�ɼ������ı���
	CString m_MathsT;	// �󶨸������Գɼ������ı���

	CString m_CppD;		//	��CPPƽʱ�ɼ������ı���
	CString m_CppT;		//	��CPP���Գɼ������ı���
};
