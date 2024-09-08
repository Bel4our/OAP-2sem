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
	char name[50];
	char date[50];
	char addr[50];
	char phonenumber[50];
	char job[50];
	char position[50];
};

struct notebook // ���������
{
	buf fullname;
	buf birthday;
	buf add;
	buf phone;
	buf pljob;
	buf pos;
};

notebook diary[size];


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
	cout << "������� ���������� �������: "; cin >> numb;
	for (int i = 0;i < numb;i++)
	{
		if (current_size < size) // ������� ��� �������� ������� �����
		{
			// ���������� ����������
			cin.ignore();
			cout << "���������� � " << i + 1 << " ��������: " << endl;
			cout << endl << "���: " << endl;
			gets_s(diary[current_size].fullname.name, 50);
			cout << "���� ��������: " << endl;
			gets_s(diary[current_size].birthday.date, 50);
			cout << "�����: " << endl;
			gets_s(diary[current_size].add.addr, 50);
			cout << "�������: " << endl;
			gets_s(diary[current_size].phone.phonenumber, 50);
			cout << "����� ������ ��� �����: " << endl;
			gets_s(diary[current_size].pljob.job, 50);
			cout << "���������: " << endl;
			gets_s(diary[current_size].pos.position, 50);
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
		cout << endl << "���: " << diary[i].fullname.name << endl;
		cout << "���� ��������: " << diary[i].birthday.date << endl;
		cout << "�����: " << diary[i].add.addr << endl;
		cout << "�������: " << diary[i].phone.phonenumber << endl;
		cout << "����� ������ ��� �����: " << diary[i].pljob.job << endl;
		cout << "���������: " << diary[i].pos.position << endl;
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
			file1 << endl << "���: " << diary[i].fullname.name << endl;
			file1 << "���� ��������: " << diary[i].birthday.date << endl;
			file1 << "�����: " << diary[i].add.addr << endl;
			file1 << "�������: " << diary[i].phone.phonenumber << endl;
			file1 << "����� ������ ��� �����: " << diary[i].pljob.job << endl;
			file1 << "���������: " << diary[i].pos.position << endl;
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
	string line;
	bool f = true;
	cout << "������� ���: ";
	cin.ignore();
	getline(cin, line);
	for (int i = 0;i < current_size;i++)
	{
		if (line == diary[i].fullname.name)
		{
			cout << "���������� � " << i + 1 << " ��������: " << endl;
			cout << endl << "���: " << diary[i].fullname.name << endl;
			cout << "���� ��������: " << diary[i].birthday.date << endl;
			cout << "�����: " << diary[i].add.addr << endl;
			cout << "�������: " << diary[i].phone.phonenumber << endl;
			cout << "����� ������ ��� �����: " << diary[i].pljob.job << endl;
			cout << "���������: " << diary[i].pos.position << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "���������� �� �������!" << endl;
	}
}