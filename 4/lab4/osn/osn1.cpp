#include <iostream>
#include <fstream> // ���������� ��� ������ � �������
#include <string> // ��� ������ �� ��������
#include <windows.h> // ��� ����������� ����������� ��������
#define size 30 //����������� ������� ��� ����� �������

using namespace std;

void input(); //�������� ������� �����
void output(); // �������� ������� ������
void del(); // �������� ������� ��� ��������
void find(); // �������� ������� ������
void inFile(); // �������� ������� ������ � ����
void outFile(); // �������� ������� ������ �� �����

struct Book // ���������� ���������
{
	// ����������� ���������� ���������
	string carmodel; 
	string color;
	string carnumb;
	string daterelease;
	string typecar;
	int datetech;
	string owner;
};

Book list_of_cars[size]; // ������ ���� book ��� �������� ����������
int current_size=0; // ������� ���������� �������
int cars; // ���������� �����
int choice; // �����

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//���� ������
	do
	{
		cout << "1 - ���� ��������� ��������� � ����������"<<endl;
		cout << "2 - ����� ��������� ��������� � ���������� ����" << endl;
		cout << "3 - �������� �������� ����������������� ����������" << endl;
		cout << "4 - ����� ���������� �� ���������" << endl;
		cout << "5 - ������ ���������� � ����" << endl;
		cout << "6 - ������ ������ �� �����" << endl;
		cout << "7 - ����� �� ���������" << endl;
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
		case 5:
			inFile();
			break;
		case 6:
			outFile();
			break;
		}
	} 
	while (choice!=7);

	return 0;
}

void input() // ������� �����
{
	cout << "������� ���������� �����������: "; cin >> cars;
	for (int i = 0;i < cars;i++)
	{
		if (current_size < size) // ������� ��� �������� ������� �����
		{
			// ���������� ����������
			cout << "���������� � " << i + 1 << " ����������: " << endl;
			cin.ignore();
			cout << endl << "����� ���������� " << endl;
			getline(cin, list_of_cars[current_size].carmodel);
			cout << "���� " << endl;
			getline(cin, list_of_cars[current_size].color);
			cout << "���� ������� " << endl;
			getline(cin, list_of_cars[current_size].daterelease);
			cout << "��������� ����� " << endl;
			getline(cin, list_of_cars[current_size].carnumb);
			cout << "��� ������ " << endl;
			getline(cin, list_of_cars[current_size].typecar);
			cout << "�������� " << endl;
			getline(cin, list_of_cars[current_size].owner);
			cout << "���� ���������� " << endl;
			cin >> list_of_cars[current_size].datetech;
			current_size++;
		}
	}
}

void output() // ������� ������
{
	for (int i = 0; i < current_size; i++) // ���� ������ ����������
	{
		cout << "���������� � " << i + 1 << " ����������: " << endl;
		cout << endl << "����� ���������� " << list_of_cars[i].carmodel<<endl;
		cout << "���� " << list_of_cars[i].color<<endl;
		cout << "���� ������� " << list_of_cars[i].daterelease << endl;
		cout << "��������� ����� " << list_of_cars[i].carnumb << endl;
		cout << "��� ������ " << list_of_cars[i].typecar << endl;
		cout << "�������� " << list_of_cars[i].owner << endl;
		cout << "���� ���������� " << list_of_cars[i].datetech <<endl;
	}
}

void del() // ������� �������� 
{
	int n;
	cout << "\n����� ���������� � ��������, ������� ���� �������" << endl;  cin >> n;
	for (int de1 = (n - 1); de1 < current_size; de1++)
	{
		list_of_cars[de1] = list_of_cars[de1 + 1];
		current_size = current_size - 1;
	}
}

void find() // ������� ������ �� ���������
{
	string findOwner;
	cin.ignore();
	bool f = true; // ���������� ��� ��������� ����� �� ��������� ��� ���
	cout << "������� ������ �� ���������: ";
	getline(cin, findOwner);
	for (int i = 0; i < current_size;i++)
	{
		if (findOwner == list_of_cars[i].owner)
		{
			cout << "���������� � " << i + 1 << " ����������: " << endl;
			cout << endl << "����� ���������� " << list_of_cars[i].carmodel << endl;
			cout << "���� " << list_of_cars[i].color << endl;
			cout << "���� ������� " << list_of_cars[i].daterelease << endl;
			cout << "��������� ����� " << list_of_cars[i].carnumb << endl;
			cout << "��� ������ " << list_of_cars[i].typecar << endl;
			cout << "�������� " << list_of_cars[i].owner << endl;
			cout << "���� ���������� " << list_of_cars[i].datetech << endl;
			f = false; // ���� ����� ��������� false
		}
	}
	if (f) // ���� f == true ������ �� �� ����� ���������
	{
		cout << "���������� �� �������!"<<endl;
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
			file1 << endl << "����� ���������� " << list_of_cars[i].carmodel << endl;
			file1 << "���� " << list_of_cars[i].color << endl;
			file1 << "���� ������� " << list_of_cars[i].daterelease << endl;
			file1 << "��������� ����� " << list_of_cars[i].carnumb << endl;
			file1 << "��� ������ " << list_of_cars[i].typecar << endl;
			file1 << "�������� " << list_of_cars[i].owner << endl;
			file1 << "���� ���������� " << list_of_cars[i].datetech << endl;
		}
		file1.close();
	}
	else
		cout << "�� ������� ������� ����!"<<endl;
}

void outFile() // ������� ������ �� �����
{
	ifstream file1("FILE1.txt");
	string line;
	while (getline(file1, line))
	{
		cout << line<<"\n";
	}
	file1.close();
}