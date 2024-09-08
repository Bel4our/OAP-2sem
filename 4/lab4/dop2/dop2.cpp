#include <iostream>
#include <string>
#include <Windows.h>

#define size 8

using namespace std;

void input(); // ������� ��� �����
void output(); // ������� ��� ������
void sortoftime(); // ������� ��� ������ ������� �������������� �� ������� ����� ��������� ����� � ����������

struct TRAIN
{
	string destination;
	int number;
	string time;
};

TRAIN trains[size];
int choice;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//���� ������
	do
	{
		cout << "1 - ���� ��������� ��������� � ����������" << endl;
		cout << "2 - ����� ��������� ��������� � ���������� ����" << endl;
		cout << "3 - ����� ��������� ����� ��������� �������" << endl;
		cout << "4 - ����� �� ���������" << endl;
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
			sortoftime();
			break;
		}
	} while (choice != 4);

	return 0;
}

void input() // ������� ��� �����
{
	for (int i = 0;i < 8;i++)
	{
		if (i < size)
		{
			// ���������� ����������
			cin.ignore();
			cout << "���������� � " << i + 1 << " ������: " << endl;
			cout << endl << "����� ���������� " << endl;
			getline(cin, trains[i].destination);
			cout << "����� ����������� " << endl;
			getline(cin, trains[i].time);
			cout << "����� ������ " << endl;
			cin >> trains[i].number;
		}
	}
	for (int i = 0;i < 8;i++) // ��������� ������ �� ������� ����������
	{
		for (int j = i + 1;j < 8;j++)
		{
			if(trains[i].destination > trains[j].destination)
			{
				TRAIN buff = trains[i];
				trains[i] = trains[j];
				trains[j] = buff;
			}
		}
	}
}

void output() // ������� ��� ������
{
	for (int i = 0;i < 8;i++)
	{
		cout << endl << "����� ���������� " << trains[i].destination << endl;
		cout << "����� ������ " << trains[i].number << endl;
		cout << "����� ����������� " << trains[i].time << endl;
	}
}

void sortoftime() // ������� ��� ������ ������� �������������� �� ������� ����� ��������� ����� � ����������

{
	string time;
	cout << "������� ����� �����������: ";
	cin.ignore();
	getline(cin, time);
	bool f=true;
	for (int i = 0;i < 8;i++)
	{
		if (trains[i].time > time)
		{
			cout << endl << "����� ���������� " << trains[i].destination << endl;
			cout << "����� ������ " << trains[i].number << endl;
			cout << "����� ����������� " << trains[i].time << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "������� �� �������" << endl;
	}
}