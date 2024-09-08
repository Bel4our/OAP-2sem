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
	char birthday[50];
	char addres[50];
	char gender;
};

struct citizen // ���������
{
	buf full_name;
	buf birth;
	buf addr;
	buf gend;

};

citizen citizens[size];


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
		cout << "5 - ����� ���������� �� ����" << endl;
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
	int numb; // ��� �������� ���������� �������
	int choice; // ����� �� ������������
	cout << "������� ���������� �������: "; cin >> numb;
	for (int i = 0;i < numb;i++)
	{
		if (current_size < size) // ������� ��� �������� ������� �����
		{
			// ���������� ����������
			cout << "���������� � " << i + 1 << " ����������: " << endl;
			cin.ignore();
			cout << endl << "���: " << endl;
			gets_s(citizens[current_size].full_name.fullname, 50);
			cout << "���� ��������: " << endl;
			gets_s(citizens[current_size].birth.birthday, 50);
			cout << "�����: " << endl;
			gets_s(citizens[current_size].addr.addres, 50);
			cout << "���: " << endl;
			cin >> citizens[current_size].gend.gender;
			current_size++;
		}
		
	}
}

void output() // ������� ������
{
	// ����� ����������
	for (int i = 0; i < current_size;i++)
	{
		cout << "���������� � " << i + 1 << " ����������: " << endl;
		cout << endl << "���: " << citizens[i].full_name.fullname << endl;
		cout << "���� ��������: " << citizens[i].birth.birthday<< endl;
		cout << "�����: " << citizens[i].addr.addres << endl;
		cout << "���: " << citizens[i].gend.gender << endl;
	}
}

void inFile() // ������� ������ � ����
{
	ofstream file1("FILE1.txt");
	if (file1)
	{
		for (int i = 0; i < current_size; i++)
		{
			file1 << "���������� � " << i + 1 << " ����������: " << endl;
			file1 << endl << "���: " << citizens[i].full_name.fullname << endl;
			file1 << "���� ��������: " << citizens[i].birth.birthday << endl;
			file1 << "�����: " << citizens[i].addr.addres << endl;
			file1 << "���: " << citizens[i].gend.gender << endl;
		}
		cout << "���������� �������� � ����!"<<endl;
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
		cout << line<<endl;
	}
	file1.close();

}


void find() // ������� ������
{
	string date;
	bool f = true;
	cout << "������� ���� ��������: "; 
	cin.ignore();
	getline(cin, date);
	for (int i = 0;i < current_size;i++)
	{
		if (date == citizens[i].birth.birthday)
		{
			cout << "���������� � " << i + 1 << " ����������: " << endl;
			cout << endl << "���: " << citizens[i].full_name.fullname << endl;
			cout << "���� ��������: " << citizens[i].birth.birthday << endl;
			cout << "�����: " << citizens[i].addr.addres << endl;
			cout << "���: " << citizens[i].gend.gender << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "���������� �� �������!" << endl;
	}
}