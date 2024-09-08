#include "List.h"
using namespace std;

void print(char* carmodel, char* color, char* carnumb, char* daterealese, char* typecar, int  datetech, char* owner)
{
	cout << carmodel << "  " << color << "  " << carnumb<< "  " << daterealese<< "  " << typecar <<"  " << datetech<< "  " << owner << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	Object L1 = Create();
	do{
		cout << "�������� �������: " << endl;
		cout << "1. ������ ������� � ������ ������" << endl;
		cout << "2. �����" << endl;
		cout << "3. ����� ��������" << endl;
		cout << "4. �������� ��������" << endl;
		cout << "5. ������� ������" << endl;
		cout << "6. ������� ����� ��������� ������" << endl;
		cout << "7. �����" << endl;
		cin >> choice;
		switch (choice) 
		{
		case 1:
		{
			char Carmodel[50];
			char Color[50];
			char Carnumb[50];
			char Daterelease[50];
			char Typecar[50];
			int Datetech;
			char Owner[50];
			cout << "����� ����������: ";
			cin >> Carmodel;
			cout << "����: ";
			cin >> Color;
			cout << "��������� �����: ";
			cin >> Carnumb;
			cout << "���� �������: ";
			cin >> Daterelease;
			cout << "��� ������: ";
			cin >> Typecar;
			cout << "���� ����������: ";
			cin >> Datetech;
			cout << "��������: ";
			cin >> Owner;
			L1.Insert(Carmodel, Color, Carnumb, Daterelease, Typecar, Datetech, Owner);
			break;
		}
		case 2:
		{
			L1.PrintList(print);
			break;
		}
		case 3: 
		{
			char owner[50];
			cout << "������� ���������: ";
			cin >> owner;
			Element* e = L1.Search(owner);
			if (e == NULL) 
			{
				cout << "������� �� ������" << endl;
			}
			else 
			{
				cout << "������ �������= " << e->Carmodel <<" " << e->Color << " " << e->Carnumb <<	" "<< e->Daterelease << " " << e->Typecar<< " "<< e->Datetech << " " << e->Owner << endl;
			}
			break;
		}
		case 4: 
		{
			char carnumb[50];
			cout << "������� ��������� ��� ��������: ";
			cin >> carnumb;
			bool rc = L1.Delete(carnumb);
			if (rc == true) cout << "������ �������" << endl;
			break;
		}
		case 5: 
		{
			if (L1.DeleteList()) 
			{
				cout << "������ ������� �����" << endl;
			}
			else {
				cout << "������ ��������" << endl;
			}
			break;
		}
		case 6: {
			cout << "���������� ���������: " << L1.CountList() << endl;
			break;
		}
		}
	} while (choice != 7);
	return 0;
}
