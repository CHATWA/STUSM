// MainDlg.cpp : ʵ���ļ�

#include "stdafx.h"
#include "STUSM.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "Student.h"
#include "Management.h"

//����ȫ�ֱ���
Management ManagerSystem;
CString STU = _T("0");
CString m_MathsD, m_MathsT;
CString m_CppD, m_CppT;

// MainDlg �Ի���

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MainDlg::IDD, pParent)
	, m_Num(_T(""))
	, m_Name(_T(""))
	, m_Class(_T(""))
	, m_MathsD(_T(""))
	, m_MathsT(_T(""))
	, m_CppD(_T(""))
	, m_CppT(_T(""))
	, m_STU(_T(""))
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Show, m_List);

	DDX_Text(pDX, IDC_EDIT_Num, m_Num);
	DDX_Text(pDX, IDC_EDIT_Name, m_Name);
	DDX_Text(pDX, IDC_EDIT_Class, m_Class);
	DDX_Text(pDX, IDC_EDIT_Mathsd, m_MathsD);
	DDX_Text(pDX, IDC_EDIT_Mathst, m_MathsT);
	DDX_Text(pDX, IDC_EDIT_Cppd, m_CppD);
	DDX_Text(pDX, IDC_EDIT_Cppt, m_CppT);
	DDX_Text(pDX, IDC_EDIT_STU, m_STU);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_ALL, &MainDlg::OnBnClickedButtonAll)
	ON_BN_CLICKED(IDC_BUTTON_Others, &MainDlg::OnBnClickedButtonOthers)
	ON_BN_CLICKED(IDC_MFCBUTTON_Add, &MainDlg::OnBnClickedMfcbuttonAdd)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_RADIO_Gra1, &MainDlg::OnBnClickedRadioGra1)
	ON_BN_CLICKED(IDC_RADIO_Gra2, &MainDlg::OnBnClickedRadioGra2)
	ON_BN_CLICKED(IDC_RADIO_Gra3, &MainDlg::OnBnClickedRadioGra3)
	ON_BN_CLICKED(IDC_RADIO_Gra4, &MainDlg::OnBnClickedRadioGra4)
	ON_BN_CLICKED(IDC_RADIO_maths, &MainDlg::OnBnClickedRadiomaths)
	ON_BN_CLICKED(IDC_RADIO_CPP, &MainDlg::OnBnClickedRadioCpp)
	ON_BN_CLICKED(IDC_RADIO_Man, &MainDlg::OnBnClickedRadioMan)
	ON_BN_CLICKED(IDC_RADIO_Woman, &MainDlg::OnBnClickedRadioWoman)
	ON_BN_CLICKED(IDC_BUTTON_Edit, &MainDlg::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_Delete, &MainDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_Sort, &MainDlg::OnBnClickedButtonSort)
	ON_BN_CLICKED(IDC_BUTTON_Save, &MainDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_Open, &MainDlg::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_StatisGraph, &MainDlg::OnBnClickedButtonStatisgraph)
END_MESSAGE_MAP()


// MainDlg ��Ϣ�������


void MainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(&rect);    //��ȡ�Ի��򳤿�      
	CDC   dcBmp;             //���岢����һ���ڴ��豸����
	dcBmp.CreateCompatibleDC(&dc);             //����������DC
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP_mainbg);    //������Դ��ͼƬ
	BITMAP   m_bitmap;                         //ͼƬ����               
	bmpBackground.GetBitmap(&m_bitmap);       //��ͼƬ����λͼ��
	//��λͼѡ����ʱ�ڴ��豸����
	CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
	//���ú�����ʾͼƬStretchBlt��ʾ��״�ɱ�
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
}


void MainDlg::OnClose()
{	

	//------------ʵ���Ӵ��ڹر�ʱ�������ڹر�------------
	CDialog*pdlg = (CDialog*)AfxGetMainWnd();
	pdlg->DestroyWindow();
	//----------------------------------------------------

	CDialogEx::OnClose();
}


BOOL MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//----------------------���ô��ڱ���-------------------------
	CString Title = _T("STUSM ѧ���ɼ�����ϵͳ-��ǰ�û����ƿ�212 ��Τ�� 32116160100");
	SetWindowText(Title);

	//---------------------�б�(��ͷ)��ʼ��-----------------------
	m_List.InsertColumn(0, _T("ѧ��"), LVCFMT_CENTER, 150);
	m_List.InsertColumn(1, _T("�꼶"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(2, _T("�༶"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(3, _T("����"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(4, _T("�Ա�"), LVCFMT_CENTER, 80);
	m_List.InsertColumn(5, _T("�ߵ���ѧ"), LVCFMT_CENTER, 100);
	m_List.InsertColumn(6, _T("�������������"), LVCFMT_CENTER, 135);

	//-------------------------------------------------------------
	m_List.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);

	SetDlgItemText(IDC_EDIT_STU, STU);

	////-----------------------������������--------------------------
	//CString num = _T("321161601");
	//CString nj = _T("��һ");
	//CString sex = _T("��");	
	//CString classna = _T("�ƿ�212");
	//CString name = _T("��Τ��");
	//CString math = _T("100");
	//CString cpp = _T("100");

	//for (int i = 0; i < 20; i++)
	//{
	//	num.Format(_T("3211616010%d"), i);
	//	m_List.InsertItem(i, num);
	//	m_List.SetItemText(i, 1, nj);
	//	m_List.SetItemText(i, 2, classna);
	//	m_List.SetItemText(i, 3, name);
	//	m_List.SetItemText(i, 4, sex);
	//	m_List.SetItemText(i, 5, math);
	//	m_List.SetItemText(i, 6, cpp);
	//}
	
	//����ѧ������
	STU.Format(_T("%d"),m_List.GetItemCount());
	SetDlgItemText(IDC_EDIT_STU, STU);

	return TRUE;	// return TRUE unless you set the focus to a control
						// �쳣:  OCX ����ҳӦ���� FALSE
}

//�����ȫѡ����ť
void MainDlg::OnBnClickedButtonAll()
{
	for (int i = 0; i < m_List.GetItemCount(); i++)
		m_List.SetCheck(i, TRUE);
}

//�������ѡ����ť
void MainDlg::OnBnClickedButtonOthers()
{
	for (int i = 0; i < m_List.GetItemCount(); i++)
		m_List.SetCheck(i, !m_List.GetCheck(i));
}


CString T_G;//��ʾ�꼶
void MainDlg::OnBnClickedRadioGra1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	T_G = _T("��һ");
}
void MainDlg::OnBnClickedRadioGra2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
		T_G = _T("���");
}
void MainDlg::OnBnClickedRadioGra3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	T_G = _T("����");
}
void MainDlg::OnBnClickedRadioGra4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	T_G = _T("����");
}


CString T_sex;
void MainDlg::OnBnClickedRadioMan()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	T_sex = _T("��");
}
void MainDlg::OnBnClickedRadioWoman()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	T_sex = _T("Ů");
}


void MainDlg::OnBnClickedMfcbuttonAdd()///�������ӡ���ť
{
	Student temp;
	CString T_temp;

	//--------------�ӱ༭���ȡ����------------------
	UpdateData(TRUE);
	double maths =0.4* _tcstod(m_MathsD, NULL) + 0.6*_tcstod(m_MathsT, NULL);
	double cpp =0.4* _tcstod(m_CppD, NULL) + 0.6*_tcstod(m_CppT, NULL);


	//-------------�ж��Ƿ��ȡ�˿�����---------------
	if (m_Name && m_Num && m_CppD && m_CppT && m_MathsD && m_MathsT)
	{
		MessageBox(_T("���ݲ���Ϊ�գ���������"), _T("��ʾ"), MB_ICONWARNING);
		return;
	}

	temp.Num = m_Num;
	temp.Grade = T_G;
	temp.Name = m_Name;
	temp.Sex = T_sex;
	temp.Class = m_Class;
	temp.CPP = cpp;
	temp.maths = maths;

	//�����ݼ������Ժ�Ž�Managerment�Ķ���ManagerSystem��
	if (ManagerSystem.Iscorrect(temp))
	{
		//���������������
		ManagerSystem.AddData(temp);
		int nCount = m_List.GetItemCount();

		//�ڽ����б�ؼ����������
		m_List.InsertItem(nCount, m_Num);
		m_List.SetItemText(nCount, 1, T_G);
		m_List.SetItemText(nCount, 2, m_Class);
		m_List.SetItemText(nCount, 3, m_Name);
		m_List.SetItemText(nCount, 4, T_sex);
		//��������תΪcstring��
		T_temp.Format(_T("%.1f"), maths);
		m_List.SetItemText(nCount, 5, T_temp);
		T_temp.Format(_T("%.1f"), cpp);
		m_List.SetItemText(nCount, 6, T_temp);

		//����ѧ������
		STU.Format("%d", nCount+1);
		SetDlgItemText(IDC_EDIT_STU, STU);
	}
	else
	{
		MessageBox(_T("ѧ����ͬ��ɼ����������������"), _T("��ʾ"), MB_ICONWARNING);
	}
}

void MainDlg::OnBnClickedButtonEdit()//���"�༭"��ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Student temp;
	int i;
	for (i = 0; i < m_List.GetItemCount(); i++)
	{
		if (m_List.GetCheck(i))
			break;
	}
	if (i == m_List.GetItemCount())
	{
		return;
	}
	CString m_Name, m_Num, m_Class, T_temp;
	//--------------�ӱ༭���ȡ����------------------
	GetDlgItemText(IDC_EDIT_Name, m_Name);
	GetDlgItemText(IDC_EDIT_Num, m_Num);
	GetDlgItemText(IDC_EDIT_Class, m_Class);

	GetDlgItemText(IDC_EDIT_Mathsd, m_MathsD);
	GetDlgItemText(IDC_EDIT_Mathst, m_MathsT);
	double maths = 0.4 * _tcstod(m_MathsD, NULL) + 0.6 * _tcstod(m_MathsT, NULL);

	GetDlgItemText(IDC_EDIT_Cppd, m_CppD);
	GetDlgItemText(IDC_EDIT_Cppt, m_CppT);
	double cpp = 0.4 * _tcstod(m_CppD, NULL) + 0.6 * _tcstod(m_CppT, NULL);

	//-------------�ж��Ƿ��ȡ�˿�����---------------
	if (m_Name == "" && m_Num && m_CppD && m_CppT && m_MathsD && m_MathsT)
	{
		MessageBox(_T("���ݲ���Ϊ�գ���������"), _T("��ʾ"), MB_ICONWARNING);
		return;
	}

	//��ȡ���ݷ������
	temp.Num = m_Num;
	temp.Grade = T_G;
	temp.Name = m_Name;
	temp.Sex = T_sex;
	temp.Class = m_Class;
	temp.CPP = cpp;
	temp.maths = maths;

	ManagerSystem.EditData(temp, i);
	
	m_List.DeleteItem(i);
	m_List.InsertItem(i, m_Num);
	m_List.SetItemText(i, 1, T_G);
	m_List.SetItemText(i, 2, m_Class);
	m_List.SetItemText(i, 3, m_Name);
	m_List.SetItemText(i, 4, T_sex);
	//��������תΪcstring��
	T_temp.Format(_T("%.1f"), maths);
	m_List.SetItemText(i, 5, T_temp);
	T_temp.Format(_T("%.1f"), cpp);
	m_List.SetItemText(i, 6, T_temp);
}

void MainDlg::OnBnClickedButtonDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < m_List.GetItemCount(); i++)
	{
		if (m_List.GetCheck(i))
		{
			ManagerSystem.DeleteData(i);
			m_List.DeleteItem(i);
			i--;
		}
	}
	//����ѧ������
	int nCount = m_List.GetItemCount();
	STU.Format(_T("%d"), nCount);
	SetDlgItemText(IDC_EDIT_STU, STU);
}

int s;
void MainDlg::OnBnClickedRadiomaths()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	s = 0;
}
void MainDlg::OnBnClickedRadioCpp()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	s = 1;
}

void MainDlg::OnBnClickedButtonSort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_List.DeleteAllItems();
	int nCount = ManagerSystem.GetCount();
	CString temp;
	switch (s)
	{
	case 0:
		ManagerSystem.SortDataM();
		
		for (int i = 0; i < nCount; i++)
		{
			m_List.InsertItem(i, ManagerSystem.SortM[i].Num);
			m_List.SetItemText(i, 1, ManagerSystem.SortM[i].Grade);
			m_List.SetItemText(i, 2, ManagerSystem.SortM[i].Class);
			m_List.SetItemText(i, 3, ManagerSystem.SortM[i].Name);
			m_List.SetItemText(i, 4, ManagerSystem.SortM[i].Sex);
			temp.Format(_T("%.1f"), ManagerSystem.SortM[i].maths);
			m_List.SetItemText(i, 5, temp);
			temp.Format(_T("%.1f"), ManagerSystem.SortM[i].CPP);
			m_List.SetItemText(i, 6, temp);
		}
		//����ѧ������
		STU.Format(_T("%d"), m_List.GetItemCount());
		SetDlgItemText(IDC_EDIT_STU, STU);
		break;
	case 1:
		ManagerSystem.SortDataC();

		for (int i = 0; i < nCount; i++)
		{
			m_List.InsertItem(i, ManagerSystem.SortC[i].Num);
			m_List.SetItemText(i, 1, ManagerSystem.SortC[i].Grade);
			m_List.SetItemText(i, 2, ManagerSystem.SortC[i].Class);
			m_List.SetItemText(i, 3, ManagerSystem.SortC[i].Name);
			m_List.SetItemText(i, 4, ManagerSystem.SortC[i].Sex);
			temp.Format(_T("%.1f"), ManagerSystem.SortC[i].maths);
			m_List.SetItemText(i, 5, temp);
			temp.Format(_T("%.1f"), ManagerSystem.SortC[i].CPP);
			m_List.SetItemText(i, 6, temp);
		}
		//����ѧ������
		STU.Format(_T("%d"), m_List.GetItemCount());
		SetDlgItemText(IDC_EDIT_STU, STU);
		break;
	default:
		break;
	}
}

void MainDlg::OnBnClickedButtonSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog fDlg(FALSE, ".dat", "save", OFN_OVERWRITEPROMPT, "�����ļ�(*.dat)|*.dat", NULL);
	if (fDlg.DoModal()==IDOK)
	{
		CString sPath = fDlg.GetPathName();
		//�����ļ�����
		CStdioFile file(sPath, CFile::modeWrite | CFile::modeCreate);
		CString temp;
		for (int i = 0; i < m_List.GetItemCount(); i++)
		{
			temp += m_List.GetItemText(i, 0) + "#";
			temp += m_List.GetItemText(i, 1) + "#";
			temp += m_List.GetItemText(i, 2) + "#";
			temp += m_List.GetItemText(i, 3) + "#";
			temp += m_List.GetItemText(i, 4) + "#";
			temp += m_List.GetItemText(i, 5) + "#";
			temp += m_List.GetItemText(i, 6) + "#\n";

			file.WriteString(temp);
		}

		file.Close();
	}
	
}

void MainDlg::OnBnClickedButtonOpen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog fDlg(TRUE, ".dat", "save", OFN_OVERWRITEPROMPT, "�����ļ�(*.dat)|*.dat", NULL);
	if (fDlg.DoModal() == IDOK)
	{
		CStdioFile file(fDlg.GetPathName(), CFile::modeRead);
		CString temp;
		CString m_Name, m_Num, m_Class, T_temp, T_maths, T_cpp;
		Student Stemp;
		int i = 0;
		while (file.ReadString(temp))
		{

			int x = temp.Find("#");
			int x2 = temp.Find("#", x + 1);
			int x3 = temp.Find("#", x2 + 1);
			int x4 = temp.Find("#", x3 + 1);
			int x5 = temp.Find("#", x4 + 1);
			int x6 = temp.Find("#", x5 + 1);
			int x7 = temp.Find("#", x6 + 1);

			Stemp.Num = temp.Left(x);
			Stemp.Grade = temp.Mid(x + 1, x2 - x - 1);
			Stemp.Class = temp.Mid(x2 + 1, x3 - x2 - 1);
			Stemp.Name = temp.Mid(x3 + 1, x4 - x3 - 1);
			Stemp.Sex = temp.Mid(x4 + 1, x5 - x4 - 1);
			Stemp.maths = _tcstod(temp.Mid(x5 + 1, x4 - x3 - 1), NULL);
			Stemp.CPP = _tcstod(temp.Mid(x6 + 1, x7 - x6 - 1), NULL);
			ManagerSystem.AddData(Stemp);

			m_List.InsertItem(i, Stemp.Num);
			m_List.SetItemText(i, 1, Stemp.Grade);
			m_List.SetItemText(i, 2, Stemp.Class);
			m_List.SetItemText(i, 3, Stemp.Name);
			m_List.SetItemText(i, 4, Stemp.Sex);
			CString Format_Gra;
			Format_Gra.Format("%.1f", Stemp.maths);
			m_List.SetItemText(i, 5, Format_Gra);
			Format_Gra.Format("%.1f", Stemp.CPP);
			m_List.SetItemText(i, 6, Format_Gra);

			i++;
		}
		
	}

	//����ѧ������
	int nCount = m_List.GetItemCount();
	STU.Format(_T("%d"), nCount);
	SetDlgItemText(IDC_EDIT_STU, STU);
}

void MainDlg::OnBnClickedButtonStatisgraph()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
