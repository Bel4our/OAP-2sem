#include "Heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //������� ���������
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - ����� 1 ���� �� �����" << endl;
		cout << "2 - �������� ������� � 1 ����" << endl;
		cout << "3 - ����� 2 ���� �� �����" << endl;
		cout << "4 - �������� ������� � 2 ����" << endl;
		cout << "5 - ����������� 2 ���" << endl;
		cout << "6 - ������� ����������� ������� 1 ����" << endl;
		cout << "7 - ������� i-� ������� 1 ����" << endl;
		cout << "8 - ����� ����� ������" << endl; // ������� 10
		cout << "9 - ���������� �������" << endl; // ������� 7
		cout << "10 - ����� �������� �������" << endl;  // ������� 16
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl; cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 1: h1.scan(0);
			break;
		case 2:
		{AAA* a = new AAA;
		cout << "������� ����" << endl; cin >> k;
		a->x = k;
		h1.insert(a);
		}
		break;
		case 3: h2.scan(0);
			break;
		case 4:
		{AAA* a = new AAA;
		cout << "������� ����" << endl; cin >> k;
		a->x = k;
		h2.insert(a);
		h1.insert(a);
		}
		break;
		case 5:
			h1.scan(0);
			break;
		case 6: h1.extractMin();
			break;
		case 7: h1.extractI();
			break;
		case 8: cout<<"����� ������: " << h1.sumVertices() << endl;
			break;
		case 9: cout << "���������� �������: " << h1.countLeaves() << endl;
			break;
		case 10: cout << "����� �������� �������: " << h1.sumLeaves() << endl;
			break;
		default: cout << endl << "������� �������� �������!" << endl;
		}
	} return 0;
}
