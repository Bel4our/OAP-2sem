#include <iostream>
#include <string>
#include <Windows.h>
#define stud  30 // ������������ �������� ���������
#define size 6 // ������������ �������� ������� � ��������

using namespace std;

void input(); // ������� �����
void output(); // ������� ������
void charact(); // ������� ��� �������� ���� �� ������� �������� �� 4, 5
void sec(); // ������� ��� ���� ����� ������ ����� ������������

int choice = 0; // �����
int current_stud = 0; // ������� �������� �������

struct Student  // ��������� 
{
    string name; 
    int num_exams;
    int marks[size]; 
};

Student list_of_students[stud];

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	do
	{
		cout << "1 - ���� ��������� ��������� � ����������" << endl;
		cout << "2 - ����� ��������� ��������� � ���������� ����" << endl;
		cout << "3 - �������� �� ����������" << endl;
		cout << "4 - �������������� ������������" << endl;
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
			charact();
			break;
		case 4:
			sec();
			break;
		}
	} while (choice != 5);
    return 0;
}
void input() // ������� �����
{
	int numb;
	cout << "������� ���������� ���������" << endl; cin >> numb;
	for (int i = 0;i < numb;i++)
	{
		if (current_stud < stud)
		{		
			cin.ignore();
			cout << endl << "������� ��������: " << endl;
			getline(cin, list_of_students[current_stud].name);
			cout << "���������� ��������� " << endl;
			cin >> list_of_students[current_stud].num_exams;
			cout << "������ " << endl;
			for (int j = 0;j < list_of_students[current_stud].num_exams;j++) //���� ��� ������ ������
			{
				cout << "������� ������ �� " << j + 1 << " �������: ";
				cin >> list_of_students[current_stud].marks[j];
				cout << endl;
			}
			current_stud++;
		}
	}

}

void output() // ������� ������
{
	for (int i = 0;i < current_stud;i++)
	{
		cout << endl << "������� ��������: " << list_of_students[i].name << endl;
		cout << "���������� ��������� " << list_of_students[i].num_exams << endl;
		cout << "������: " << endl;
		for (int j = 0;j < list_of_students[i].num_exams;j++) 
		{
			cout << "������� ������ �� " << j + 1 << " �������: "<<list_of_students[i].marks[j] << endl;
		}
	}
}

void charact()  // ������� ��� �������� ���� �� ������� �������� �� 4, 5
{
	int count = 0;
	bool f = true;
	string surname;
	cout << "������� ������� ��������: "; 
	cin.ignore();
	getline(cin, surname);
	for (int i = 0; i < current_stud;i++)
	{
		if (list_of_students[i].name == surname)
		{
			for (int j = 0;j < list_of_students[i].num_exams;j++)
			{
				if (list_of_students[i].marks[j] >= 4)
				{
					count++; // ������� ������ 4 � 5 � ��������
				}
			}
			if (count == list_of_students[i].num_exams) // ���� �� ���������� ������� � ����������� ���������
			{
				cout << endl << "������� ���� ��� �������� �� 4, 5"<<endl; // ������ ������� �������

			}
			else
			{
				cout << endl << "������� �� ���� ��� �������� �� 4, 5"<<endl;
			}
			f = false;
		}
	}
	if (f) // ������� ���� � ��� �� ������� �������� � ����� ��������
	{
		cout << "�������� � ����� �������� �� �������!" << endl; 
	}
}

void sec() // ������� ��� ���� ����� ������ ����� ������������
{
	float secstud=0; // ���������� ��� �������� ��������� � ������� ������ ���� 4 
	for (int i = 0;i < current_stud;i++)
	{
		int count = 0;
		for (int j = 0;j < list_of_students[i].num_exams;j++)
		{
			if (list_of_students[i].marks[j] >= 4)
			{
				count++; // ������� ������ 4 � 5
			}
		}
		if (count == list_of_students[i].num_exams)
		{
			secstud++; // ����������� ��������
		}
	}
	float devide = secstud / current_stud*100; // ������� ����� ���������
	cout << "���������� �������� ��������� � ���������: " << devide << endl;
}

