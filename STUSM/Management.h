#pragma once
#include "afxdialogex.h"
#include "Student.h"
#include <fstream>
#include <string>

using namespace std;			//�����ʹ�ñ�׼�����ռ� swap������Ҫע��std::

//----------------------------------------------------Management������---------------------------------------------------
class Management
{
public:
	Management();				//����
	~Management();				//����

	int GetCount();				//�����������Ѿ���ӵ�����

	//-----------------------�������Ĳ���----------------------
	void AddData(Student);					//ѧ���ɼ����ݵ�����
	void DeleteData(int n);					//ѧ���ɼ����ݵ�ɾ��
	void EditData(Student obj, int n);	//ѧ���ɼ����ݵ��޸�
	void SortDataM();							//ѧ���ɼ����ݵ�����(������)
	void SortDataC();								//ѧ���ɼ����ݵ�����(���������)


	//--------------------�����ݵ���Ч���ж�-------------------
	BOOL IsSame(Student obj);				//�ж��������Ƿ��Ѿ�������ͬѧ�ŵ���
	BOOL Iscorrect(Student obj);			//�ж��������ݵ���Ч��


	//-----------------------�������ݳ�Ա----------------------
public:
	Student* Pstu;									//ָ���������������ָ��
	Student* SortM;								//ָ�򰴸����ɼ�����������ָ��
	Student* SortC;								//ָ���������ɼ�����������ָ��

private:
	int Count;											//����ͳ���������Ѿ���ӵ�����
	int Size;											//������������
};