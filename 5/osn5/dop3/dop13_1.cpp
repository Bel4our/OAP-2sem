#include <iostream>
#include <string> // ��� ������ �� ��������
#include <windows.h> // ��� ����������� ����������� ��������
#define size 10 //����������� ������� ��� ����� �������

using namespace std;

void input(); //�������� ������� �����
void output(); // �������� ������� ������
void del(); // �������� ������� ��� ��������
void find(); // �������� ������� ������

enum faculty // ������������
{
	��� = 1, ��_���
};
struct student // ���������
{
	char name[50];
	char speciality[50];
	int group;
	float average;
	faculty fac;
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 14;
};

student students[size];

int choice;
int current_size = 0;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//���� ������
	do
	{
		cout << "1 - ���� ��������� � ����������" << endl;
		cout << "2 - ����� ��������� � ���������� ����" << endl;
		cout << "3 - �������� �������� ����������������� ����������" << endl;
		cout << "4 - ����� ���������� " << endl;
		cout << "5 - ����� �� ���������" << endl;
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
			del();
			break;
		case 4:
			find();
			break;
		}
	} while (choice != 5);
	return 0;
}

void input() // ������� �����
{
	int day, month, year;
	int numb; // ��� �������� ���������� 
	cout << "������� ���������� �������: "; cin >> numb;
	for (int i = 0;i < numb;i++)
	{
		if (current_size < size) // ������� ��� �������� ������� �����
		{
			// ���������� ����������
			cout << "���������� � " << i + 1 << " ��������: " << endl;
			cin.ignore();
			cout << endl << "���: " << endl;
			gets_s(students[current_size].name,50);
			cout << "�������������: "<<endl;
			gets_s(students[current_size].speciality, 50);
			cout << "������� ���� ����������� � ������� �� �� ����: " << endl;
			cin >> day >> month >> year;
			students[current_size].day = day;
			students[current_size].month = month;
			students[current_size].year = year;
			cout << "��������� (1 - ���, 2 - �� ���): " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				students[current_size].fac = ���;
				break;
			case 2:
				students[current_size].fac = ��_���;
				break;
			}
			cout << "������: " << endl;
			cin >> students[current_size].group;
			cout << "������� ����: " << endl;
			cin >> students[current_size].average;
			current_size++;
		}
	}
}

void output() // ������� ������
{
	// ����� ����������
	for (int i = 0; i < current_size;i++)
	{
		cout << endl << "���: " << students[i].name << endl;
		cout << "���� �����������: " << students[i].day << students[i].month << students[i].year <<endl;
		cout << "�������������: " << students[i].speciality<< endl;
		cout << "������: " << students[i].group << endl;
		cout << "���������: ";
		if (students[i].fac == ���)
		{
			cout << "���";
		}
		else
			if (students[i].fac == ��_���)
			{
				cout << " �� ���";
			}
		cout << endl;
		cout << "������� ����: " << students[i].average << endl;
	}
}

void del() // ������� ��� ��������
{
	int d;
	bool f = false;
	float av;
	cout << "������� ������� ���� ��� �������� ����������" << endl;
	cin >> av;
	for (int i = 0;i < current_size;i++)  // ���� ����������
	{
		if (av == students[i].average) // ���� �����
		{
			d = i; // ����������
			f = true;
		}
	}
	if (f) // ���� �����
	{
		for (int de1 = d; de1 < current_size; de1++) // ���� ��� ��������
		{
			students[de1] = students[de1 + 1];
		}
		current_size = current_size - 1;

		cout << "���������� �������" << endl;
	}
	else
		cout << "���������� �� �������!" << endl; // ����� ������� ��� �� �����
}

void find() // ������� ������
{
	bool f = true;
	float av;
	cout << "������� ������� ���� ��� ������ ����������: " << endl;
	cin >> av;
	for (int i = 0;i < current_size;i++)
	{
		if (av == students[i].average) // ���� ����� �������
		{
			cout << endl << "���: " << students[i].name << endl;
			cout << "���� �����������: " << students[i].day <<" " << students[i].month << " " << students[i].year << endl;
			cout << "�������������: " << students[i].speciality << endl;
			cout << "������: " << students[i].group << endl;
			cout << "���������: ";
			if (students[i].fac == ���)
			{
				cout << "���";
			}
			else
				if (students[i].fac == ��_���)
				{
					cout << "�� ���";
				}
			cout << endl;
			cout << "������� ����: " << students[i].average << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "���������� �� �������!" << endl;
	}
}