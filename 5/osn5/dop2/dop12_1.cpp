#include <iostream>
#include <string> // ��� ������ �� ��������
#include <windows.h> // ��� ����������� ����������� ��������
#define size 10 //����������� ������� ��� ����� �������

using namespace std;

void input(); //�������� ������� �����
void output(); // �������� ������� ������
void del(); // �������� ������� ��� ��������
void find(); // �������� ������� ������

struct notebook // ���������
{
	string name;
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 14;
	string addr;
	string phonenumber;
};

notebook diary[size];

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
			cout << "���������� � " << i + 1 << " ������: " << endl;
			cin.ignore();
			cout << endl << "���: " << endl;
			getline(cin, diary[current_size].name);
			cout << "�����: " << endl;
			getline(cin, diary[current_size].addr);
			cout << "����� ��������: " << endl;
			getline(cin, diary[current_size].phonenumber);
			cout << "������� ���� � ������� �� �� ����: " << endl;
			cin >> day >> month >> year;
			diary[current_size].day = day;
			diary[current_size].month = month;
			diary[current_size].year = year;
			current_size++;
		}
	}
}

void output() // ������� ������
{
	// ����� ����������
	for (int i = 0; i < current_size;i++)
	{
		cout << "���������� � " << i + 1 << " �������� � �������� ������: " << endl;
		cout << endl << "���: " << diary[i].name << endl;
		cout << "������� ���� � ������� �� �� ����: " << endl;
		cout << "���� ��������: " << diary[i].day << " " << diary[i].month << " " << diary[i].year << endl;
		cout << "�����: " << diary[i].addr << endl;
		cout << "����� ��������: " << diary[i].phonenumber << endl;
	}
}

void del() // ������� ��� ��������
{
	int d;
	bool f = false;
	string line;
	cout << "������� ��� ��� �������� ����������" << endl;
	cin.ignore();
	getline(cin, line);
	for (int i = 0;i < current_size;i++)  // ���� ����������
	{
		if (line==diary[i].name) // ���� �����
		{
			d = i; // ����������
			f = true;
		}
	}
	if (f) // ���� �����
	{
		for (int de1 = d; de1 < current_size; de1++) // ���� ��� ��������
		{
			diary[de1] = diary[de1 + 1];
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
	string line;
	cout << "������� ��� ��� �������� ����������" << endl;
	cin.ignore();
	getline(cin, line);
	for (int i = 0;i < current_size;i++)
	{
		if (line == diary[i].name) // ���� ����� �������
		{
			cout << "���������� � " << i + 1 << " ������: " << endl;
			cout << endl << "���: " << diary[i].name << endl;
			cout << "������� ���� � ������� �� �� ����: " << endl;
			cout << "���� ��������: " << diary[i].day << " " << diary[i].month << " " << diary[i].year << endl;
			cout << "�����: " << diary[i].addr << endl;
			cout << "����� ��������: " << diary[i].phonenumber << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "���������� �� �������!" << endl;
	}
}