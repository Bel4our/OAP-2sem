#include <iostream>
#include <fstream>
#include "myStack2.h"
using namespace std;

void push(int x, Stack*& myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� data 
	e->next = myStk;         //������� ������� �� ��������� ������� 
	myStk = e;               //����� ������� �� ������� ������
}

char pop(Stack*& myStk)   //���������� (��������) �������� �� �����
{
	if (myStk == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� (-1) 
	}
	else
	{
		Stack* e = myStk;        //�-���������� ��� �������� ������ ��������
		int x = myStk->data;    //������ �������� �� ���� data � �����. x 
		if (myStk)
			myStk = myStk->next;   //������� �������
		delete e;
		return x;
	}
}
void toFile(Stack*& myStk) //������ � ����
{
	Stack* e = myStk;
	Stack buf;
	ofstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (e)
	{
		buf = *e;
		frm.write((char*)&buf, sizeof(Stack));
		e = e->next;
	}
	frm.close();
	cout << "���� ������� � ���� mStack.dat\n";
}

void fromFile(Stack*& myStk) //���������� �� ����� � ����
{
	Stack buf, * p = nullptr, * e = nullptr;
	ifstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	frm.seekg(0);
	frm.read((char*)&buf, sizeof(Stack));
	while (!frm.eof())
	{
		push(buf.data, e);
		frm.read((char*)&buf, sizeof(Stack));
	}
	frm.close();
	while (e != NULL)
	{
		buf.data = pop(e);
		push(buf.data, p);
		myStk = p;
	}
	cout << "\n���� ������ �� ����� mStack.dat\n\n";
}
void show(Stack*& myStk)  //����� �����
{
	Stack* e = myStk;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		cout << e->data << " ";
		e = e->next;
	}
	cout << endl;
}

void clear(Stack*& myStk) // ������� �������
{
	Stack* e = myStk;
	if (e == NULL)
	{
		cout << "���� ����!" << endl;
		return;
	}
	else
	{
		while (e != NULL)
		{
			Stack* temp = e; // ��������� ������� �������
			e = e->next;     // ��������� � ���������� ��������
			delete temp;     // ����������� ������ �������� ��������
		}
		myStk = NULL;
		cout << "���� ������";
	}
	cout << endl;
}

void find(Stack*& myStk)  // ������� ������ � �������� ������� �������������� �������� � �����
{
	bool f = true;
	Stack* prev = NULL;
	Stack* e = myStk;
	while (e != NULL)
	{
		if (e->data < 0 && f)
		{
			if (prev == NULL) // ���� ������������� ������� - ������ � �����
			{
				myStk = e->next;
			}
			else
			{
				prev->next = e->next;
			}
			int x = e->data;
			delete e;
			cout << "�������� �������: " << x << endl;
			f = false;
			break; // ������� �� ����� ����� �������� ��������
		}
		prev = e;
		e = e->next;
	}
	if (f)
	{
		cout << endl << "������������� ��������� �� �������" << endl; // ���� �� ���� ������� �� ������� 
	}
}