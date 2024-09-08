#include <iostream>
#include <Windows.h>
#include "myStack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice; int x;
	Stack* myStk = new Stack; //��������� ������ ��� �����
	myStk = NULL;             //������������� ������� ��������	
	do
	{
		cout << "1 - ���������� �������� � ����" << endl;
		cout << "2 - ���������� �������� �� �����" << endl;
		cout << "3 - ������ � ����" << endl;
		cout << "4 - ������ �� �����" << endl;
		cout << "5 - ����� �����" << endl;
		cout << "6 - ������� �����" << endl;
		cout << "7 - ����� �������� �� ���������" << endl;
		cout << "8 - �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� �������: " << endl;
			cin >> x;
			push(x, myStk); break;
		case 2: x = pop(myStk);
			if (x != -1)
				cout << "����������� �������: " << x << endl;
			break;
		case 3: toFile(myStk);  break;
		case 4: fromFile(myStk); break;
		case 5: cout << "���� ����: " << endl;
			show(myStk); break;
		case 6: clear(myStk); break;
		case 7: find(myStk); break;
		}
	} while (choice != 8);
	return 0;
}