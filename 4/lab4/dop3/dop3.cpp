#include <iostream>
#include <string>
#include <Windows.h>

#define size 10

using namespace std;

void input(); // ������� ��� �����
void output(); // ������� ��� ������
void search(); // ������� ��� ������

struct Sanatorium
{
	string name;
	string location;
	string profile;
	int tickets;
};

Sanatorium sanat[size];
Sanatorium buff;
int current_size = 0;
int choice;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//���� ������
	do
	{
		cout << "1 - ���� ��������� ��������� � ����������" << endl;
		cout << "2 - ����� ��������� ��������� � ���������� ����" << endl;
		cout << "3 - ����� ���������" << endl;
		cout << "4 - ����� �� ���������" << endl;
		cin >> choice;
		// ����������� choice
		switch (choice)
		{
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			search();
			break;
		}
	} while (choice != 4);


	return 0;
}

void input()
{
	int s;
	cout << "������� ���������� �� ������ ������? ";
	cin >> s;
	for (int i = 0;i < s;i++)
	{
		// ���������� ����������
		if (current_size < size)
		{
			cin.ignore();
			cout << "���������� � " << i + 1 << " ���������: " << endl;
			cout << endl << "�������� ��������� " << endl;
			getline(cin, sanat[i].name);
			cout << "����� ������������ " << endl;
			getline(cin, sanat[i].location);
			cout << "�������� ������� " << endl;
			getline(cin, sanat[i].profile);
			cout << "���������� ������ " << endl;
			cin >> sanat[i].tickets;
			current_size++;
		}
	}
}

void output()
{
	for (int i = 0; i < current_size; i++)  // ���������
	{
		for (int j = i + 1; j < current_size; j++) 
		{
			if (sanat[i].profile > sanat[j].profile || (sanat[i].profile == sanat[j].profile && sanat[i].name > sanat[j].name))
			{
				buff = sanat[i];
				sanat[i] = sanat[j];
				sanat[j] = buff;
			}
		}
	}
	for (int i = 0; i < current_size; i++) // �������
	{
		cout << "��������: " << sanat[i].name << ", �����: " << sanat[i].location << ", �������: " << sanat[i].profile << ", ���������� ������: " << sanat[i].tickets << endl;
	}
}

void search() // ������� ��� ������
{
	string profile;
	bool f=true;
	cout << "������� ������� ��� ������: ";
	cin.ignore();
	getline(cin, profile);
	for (int i = 0; i < current_size; i++) 
	{
		if (sanat[i].profile == profile) 
		{
			cout << "��������: " << sanat[i].name << ", �����: " << sanat[i].location << ", �������: " << sanat[i].profile << ", ���������� ������: " << sanat[i].tickets << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "��������� �� ������!" << endl;
	}
}
