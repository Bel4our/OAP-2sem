#include <iostream>
#include <string> // ��� ������ �� ��������
#include <windows.h> // ��� ����������� ����������� ��������
#define size 10 //����������� ������� ��� ����� �������

using namespace std;

void input(); //�������� ������� �����
void output(); // �������� ������� ������
void del(); // �������� ������� ��� ��������
void find(); // �������� ������� ������

struct teacher // ���������
{
	string name;
	string exam;
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 14;
};

teacher teachers[size];

int choice;
int current_size=0;

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
	int teach; // ��� �������� ���������� ��������������
	cout << "������� ���������� ��������������: "; cin >> teach;
	for (int i = 0;i < teach;i++)
	{
		if (current_size < size) // ������� ��� �������� ������� �����
		{
			// ���������� ����������
			cout << "���������� � " << i + 1 << " �������������: " << endl;
			cin.ignore();
			cout << endl << "��� �������������: " << endl;
			getline(cin, teachers[current_size].name);
			cout << "�������� ��������: " << endl;
			getline(cin, teachers[current_size].exam);
			cout << "������� ���� � ������� �� �� ����: " << endl;
			cin >> day>>month>>year;
			teachers[current_size].day = day;
			teachers[current_size].month = month;
			teachers[current_size].year = year;
			current_size++;
		}
	}
}

void output() // ������� ������
{
	// ����� ����������
	for (int i = 0; i < current_size;i++)
	{
		cout << "���������� � " << i + 1 << " ������������� " << endl;
		cout << endl << "��� �������������: " << teachers[i].name <<endl;
		cout << "�������� ��������: " << teachers[i].exam <<endl;
		cout << "���� ��������: " << teachers[i].day <<" "<< teachers[i].month <<" " << teachers[i].year << endl;
	}
}

void del() // ������� ��� ��������
{
	int d;
	bool f = false;
	int day, month, year;
	cout << "������� ���� ������� �������� ������ ������� � ������� �� �� ����" << endl;
	cin >> day >> month >> year;
	cin.ignore();
	for (int i = 0;i < current_size;i++)  // ���� ����������
	{
		if (day==teachers[i].day && month == teachers[i].month && year == teachers[i].year) // ���� �����
		{
			d = i; // ����������
			f = true;
		}
	}
	if (f) // ���� �����
	{
		for (int de1 = d; de1 < current_size; de1++) // ���� ��� ��������
		{
			teachers[de1] = teachers[de1 + 1];
		}
			current_size = current_size - 1;
		
		cout << "���������� �������" << endl;
	}
	else
		cout << "������������� �� ������!" << endl; // ����� ������� ��� �� �����
}

void find() // ������� ������
{
	bool f=true;
	int day, month, year;
	cout << "������� ���� ������� ����� ����� �������������� � ������� �� �� ����" << endl;
	cin >> day >> month >> year;
	cin.ignore();
	for (int i = 0;i < current_size;i++)
	{
		if (day == teachers[i].day && month == teachers[i].month && year == teachers[i].year) // ���� ����� �������
		{
			cout << "���������� � " << i + 1 << " �������������: " << endl;
			cout << endl << "��� �������������: " << teachers[i].name<<endl;
			cout << "�������� ��������: " << teachers[i].exam<<endl;
			cout << "���� ��������: " << teachers[i].day <<" " << teachers[i].month <<" " << teachers[i].year << endl;
			f = false;
		}	}
	if (f)
	{
		cout << "������������� �� ������!" << endl;
	}
}