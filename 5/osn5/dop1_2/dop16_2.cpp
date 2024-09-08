#include <iostream>
#include <fstream> // ��� ������ � �������
#include <string> // ��� ������ �� ��������
#include <windows.h> // ��� ����������� ����������� ��������
#define size 10 //����������� ������� ��� ����� �������

using namespace std;

void input(); //�������� ������� �����
void output(); // �������� ������� ������
void inFile(); // �������� ������� ��� ������ � ����
void outFile(); // �������� ������� ��� ������ �� �����
void find(); // �������� ������� ������

union buf // �����������
{
	char fullname[50];
	char day[50];
	char spec[50];
	int gr;
	char fac[50];
	float av;
};

struct student // ���������
{
	buf full_name;
	buf entrday;
	buf speciality;
	buf group;
	buf facultyd;
	buf average;

};

student students[size];


int choice;
int current_size;

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
		cout << "3 - ������ ���������� � ����" << endl;
		cout << "4 - ������ ���������� �� �����" << endl;
		cout << "5 - ����� ����������" << endl;
		cout << "6 - ����� �� ���������" << endl;
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
			inFile();
			break;
		case 4:
			outFile();
			break;
		case 5:
			find();
			break;
		}
	} while (choice != 6);
	return 0;
}

void input() // ������� �����
{
	int numb; // ��� �������� ���������� 
	int choice; // ����� �� ������������
	cout << "������� ���������� ���������: "; cin >> numb;
	for (int i = 0;i < numb;i++)
	{
		if (current_size < size) // ������� ��� �������� ������� �����
		{
			// ���������� ����������
			cout << "���������� � " << i + 1 << " ��������: " << endl;
			cin.ignore();
			cout << endl << "���: " << endl;
			gets_s(students[current_size].full_name.fullname, 50);
			cout << "���� �����������: " << endl;
			gets_s(students[current_size].entrday.day, 50);
			cout << "�������������: " << endl;
			gets_s(students[current_size].speciality.spec, 50);
			cout << "������: " << endl;
			cin >> students[current_size].group.gr;
			cin.ignore();
			cout << "���������: " << endl;
			gets_s(students[current_size].facultyd.fac, 50);
			cout << "������� ����: " << endl;
			cin >> students[current_size].average.av;
			current_size++;
		}
	}
}

void output() // ������� ������
{
	// ����� ����������
	for (int i = 0; i < current_size;i++)
	{
		cout << "���������� � " << i + 1 << " ��������: " << endl;
		cout << endl << "���: " << students[i].full_name.fullname << endl;
		cout << "���� �����������: " << students[i].entrday.day << endl;
		cout << "�������������: " << students[i].speciality.spec << endl;
		cout << "������: " << students[i].group.gr << endl;
		cout << "���������: " << students[i].facultyd.fac << endl;
		cout << "������� ����: " << students[i].average.av << endl;
	}
}

void inFile() // ������� ������ � ����
{
	ofstream file1("FILE1.txt");
	if (file1)
	{
		for (int i = 0; i < current_size; i++)
		{
			file1 << "���������� � " << i + 1 << " ��������: " << endl;
			file1 << endl << "���: " << students[i].full_name.fullname << endl;
			file1 << "���� �����������: " << students[i].entrday.day << endl;
			file1 << "�������������: " << students[i].speciality.spec << endl;
			file1 << "������: " << students[i].group.gr << endl;
			file1 << "���������: " << students[i].facultyd.fac << endl;
			file1 << "������� ����: " << students[i].average.av << endl;
		}
		cout << "���������� �������� � ����!" << endl;
		file1.close();
	}
	else
		cout << "�� ������� ������� ����!" << endl;
}

void outFile() // ������� ������ �� �����
{
	ifstream file1("FILE1.txt");
	string line;
	while (getline(file1, line))
	{
		cout << line << endl;
	}
	file1.close();

}

void find() // ������� ������
{
	float aver;
	bool f = true;
	cout << "������� ������� ����: ";
	cin >> aver;
	for (int i = 0;i < current_size;i++)
	{
		if (aver == students[i].average.av)
		{
			cout << "���������� � " << i + 1 << " ��������: " << endl;
			cout << endl << "���: " << students[i].full_name.fullname << endl;
			cout << "���� �����������: " << students[i].entrday.day << endl;
			cout << "�������������: " << students[i].speciality.spec << endl;
			cout << "������: " << students[i].group.gr << endl;
			cout << "���������: " << students[i].facultyd.fac << endl;
			cout << "������� ����: " << students[i].average.av << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "���������� �� �������!" << endl;
	}
}