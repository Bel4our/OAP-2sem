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
	char capital[50];
	int people;
	int square;
	char prezident[50];
};

struct country // ���������
{
	buf nam;
	buf cap;
	buf peop;
	buf sq;
	buf pr;
};

country countries[size];


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
			cout << "���������� � " << i + 1 << " ������: " << endl;
			cout << endl << "��������: " << endl;
			gets_s(countries[current_size].nam.name, 50);
			cout << "�������: " << endl;
			gets_s(countries[current_size].cap.capital, 50);
			cout << "������� ����������: " << endl;
			gets_s(countries[current_size].pr.prezident, 50);
			cout << "�����������: " << endl;
			cin >> countries[current_size].peop.people;
			cout << "�������: " << endl;
			cin >> countries[current_size].sq.square;
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
		cout << endl << "��������: " << countries[i].nam.name << endl;
		cout << "�������: " << countries[i].cap.capital << endl;
		cout << "�����������: " << countries[i].peop.people << endl;
		cout << "�������: " << countries[i].sq.square << endl;
		cout << "������� ����������: " << countries[i].pr.prezident << endl;
	}
}

void inFile() // ������� ������ � ����
{
	ofstream file1("FILE1.txt");
	if (file1)
	{
		for (int i = 0; i < current_size; i++)
		{
			file1 << "���������� � " << i + 1 << " ������: " << endl;
			file1 << endl << "��������: " << countries[i].nam.name << endl;
			file1 << "�������: " << countries[i].cap.capital << endl;
			file1 << "�����������: " << countries[i].peop.people << endl;
			file1 << "�������: " << countries[i].sq.square << endl;
			file1 << "������� ����������: " << countries[i].pr.prezident << endl;
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
	cout << "������� ������� ����������: ";
	cin.ignore();
	getline(cin, line);
	for (int i = 0;i < current_size;i++)
	{
		if (line == countries[i].pr.prezident)
		{
			cout << "���������� � " << i + 1 << " ������: " << endl;
			cout << endl << "��������: " << countries[i].nam.name << endl;
			cout << "�������: " << countries[i].cap.capital << endl;
			cout << "�����������: " << countries[i].peop.people << endl;
			cout << "�������: " << countries[i].sq.square << endl;
			cout << "������� ����������: " << countries[i].pr.prezident << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "���������� �� �������!" << endl;
	}
}