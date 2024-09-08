#include <iostream>
#include <string> // ��� ������ �� ��������
#include <windows.h> // ��� ����������� ����������� ��������
#define size 10 //����������� ������� ��� ����� �������

using namespace std;

void input(); //�������� ������� �����
void output(); // �������� ������� ������
void del(); // �������� ������� ��� ��������
void find(); // �������� ������� ������

enum polity // ������������
{
	��������=1, ����������
};

struct Country // ���������
{
	string name;
	string capital;
	int number;
	int square;
	polity polyt;
};

Country countries[size];

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
	int land; // ��� �������� ���������� �����
	int choice; // ����� �� ������������
	cout << "������� ���������� ����������: "; cin >> land;
	for (int i = 0;i < land;i++)
	{
		if (current_size < size) // ������� ��� �������� ������� �����
		{
			// ���������� ����������
			cout << "���������� � " << i + 1 << " ������: " << endl;
			cin.ignore();
			cout << endl << "�������� ������ " << endl;
			getline(cin, countries[current_size].name);
			cout << "�������� �������: " << endl;
			getline(cin, countries[current_size].capital);
			cout << "���������: " << endl;
			cin >> countries[current_size].number;
			cout << "������� " << endl;
			cin >> countries[current_size].square;
			cout << "����� ��������� (1 - ��������, 2 - ����������): " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				countries[current_size].polyt = ��������;
				break;
			case 2:
				countries[current_size].polyt = ����������;
				break;
			}
			current_size++;
		}
	}
}

void output() // ������� ������
{
	// ����� ����������
	for (int i = 0; i < current_size;i++)
	{
		cout << "���������� � " << i + 1 << " ������: " << endl;
		cout << endl << "�������� ������ " <<countries[i].name<<endl;
		cout << "�������� �������: " << countries[i].capital << endl;
		cout << "���������: " <<countries[i].number<<endl;
		cout << "������� " <<  countries[i].square<<endl;
		cout << "����� ���������: ";
		if (countries[i].polyt == ��������)
		{
			cout << "��������";
		}
		else 
			if (countries[i].polyt == ����������)
		{
			cout << "����������";
		}
		cout << endl;
	}
}

void del() // ������� ��������
{
	int d;
	bool f=false;
	string cap;
	cout << "�������� ������� ������, ������� ������ �������" << endl; 
	cin.ignore();
	getline(cin, cap);
	for (int i = 0;i < current_size;i++) 
	{
		if (countries[i].capital == cap) // ���� �����
		{
			d = i; // ����������
			f = true;
		}
	}
	if (f) // ���� �����
	{
		for (int de1 = d; de1 < current_size; de1++) // ���� ��� ��������
			countries[de1] = countries[de1 + 1];
		current_size = current_size - 1; // ��������� ������� ���������� ��������

		cout << "���������� �������" << endl;
	}
	else // ����� ������� ��� �� �����
		cout << "������ �� ������� �� �������" << endl;

}

void find() // ������� ������
{
	string cap;
	bool f = true;
	cout << "�������� ������� " << endl;
	cin.ignore();
	getline(cin, cap);
	for (int i = 0;i < current_size;i++)
	{
		if (countries[i].capital == cap) // ���� �����, �� �������
		{
			cout << endl << "�������� ������ " << countries[i].name << endl;
			cout << "�������� �������: " << countries[i].capital << endl;
			cout << "���������: " << countries[i].number << endl;
			cout << "������� " << countries[i].square << endl;
			cout << "����� ���������: ";
			if (countries[i].polyt == ��������)
			{
				cout << "��������";
			}
			else
				if (countries[i].polyt == ����������)
				{
					cout << "����������";
				}
			cout << endl;
			f = false;
		}
		
	}
	if (f) // ���� �� �����
	{
		cout << "������ �� �������!" << endl; // ������� ��� �� �����
	}
}