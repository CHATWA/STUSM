#include "stdafx.h"
#include "Management.h"

Management::Management()
{
	Size = 100;
	Pstu = new Student[Size];
	SortM = NULL;
	SortC = NULL;
	Count = 0;
}

Management::~Management()
{
	delete[]Pstu;
	delete[]SortC;
	delete[]SortM;
	Size = 0;
	Count = 0;
}

int Management::GetCount()
{
	return Count;
}


//-----------------------�������Ĳ���----------------------
void Management::AddData(Student obj)
{
	Count++;
	if (Count > Size)
	{
		Student* temp = new Student[Size + 50];
		for (int i = 0; i < Size; i++)
			temp[i] = Pstu[i];
		Size += 50;
		delete[]Pstu;
		Pstu = temp;
	}
	Pstu[Count - 1] = obj;
}

void Management::DeleteData(int n)
{
	for (int i = n; i < Count; i++)
		Pstu[i] = Pstu[i + 1];
	Count--;
}

void Management::EditData(Student obj, int n)
{
	Pstu[n] = obj;
}

void Management::SortDataM()
{
	//Ϊ����ѧ�ɼ�������������ٿռ䣬������ԭ��������
	SortM = new Student[Count];
	for (int i = 0; i < Count; i++)
		SortM[i] = Pstu[i];

	//------------------ʹ��ð������---------------------
	for (int i = 0; i < Count - 1; i++)
	{
		int work = 1;	//���㣬�����ݱ��Ѿ�����ֱ�ӽ�������
		for (int k = 0; k < Count - i - 1; k++)
		{
			if (SortM[k].maths < SortM[k + 1].maths)
			{
				swap(SortM[k], SortM[k + 1]);
				work = 0;
			}
		}
		if (work)
			break;
	}
}

void Management::SortDataC()
{
	//Ϊ��CPP�ɼ�������������ٿռ䣬������ԭ��������
	SortC = new Student[Count];
	for (int i = 0; i < Count; i++)
		SortC[i] = Pstu[i];

	//------------------ʹ��ð������---------------------
	for (int i = 0; i < Count - 1; i++)
	{
		int work = 1;	//���㣬�����ݱ��Ѿ�����ֱ�ӽ�������
		for (int k = 0; k < Count - i - 1; k++)
		{
			if (SortC[k].CPP < SortC[k + 1].CPP)
			{
				swap(SortC[k], SortC[k + 1]);
				work = 0;
			}
		}
		if (work)
			break;
	}
}


//--------------------�����ݵ���Ч���ж�-------------------
BOOL Management::IsSame(Student obj)
{
	for (int i = 0; i < Count; i++)
	{
		if (obj.Num == Pstu[i].Num)
			return FALSE;
	}
	return TRUE;
}

BOOL Management::Iscorrect(Student obj)
{
	if (!IsSame(obj))							//��ѧ����Ч���ж�
		return FALSE;
	if (obj.maths < 0 || obj.CPP < 0)//�Գɼ���Ч���ж�
		return FALSE;
	else
		return TRUE;
}