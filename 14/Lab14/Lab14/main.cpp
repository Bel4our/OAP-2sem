#include "Hash_Chain.h"
#include <iostream>
using namespace std;
struct Client // ��������� �������
{
	int key;
	char* mas;
	Client(int k, char* z)
	{
		key = k;
		mas = z;
	}
	Client()
	{
		key = 0;
		mas = nullptr;
	}
};
int hf(void* d) // ���-������� � ����������� ���
{
	Client* client = static_cast<Client*>(d);
	int str = client->key;
	int hash = 0;
	hash ^= str;
	return hash;
}
//-------------------------------
void Client_print(listx::Element* e) // �����
{
	cout << ((Client*)e->data)->key << '-' << ((Client*)e->data)->mas << " / ";
}
//-------------------------------
int main() // ������� �������
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "������� ������ ���-�������" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - ����� ���-�������" << endl;
		cout << "2 - ���������� ��������" << endl;
		cout << "3 - �������� ��������" << endl;
		cout << "4 - ����� ��������" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 2: {	Client* a = new Client;
			char* str = new char[20];
			cout << "������� ����� �����: " << endl;
			cin >> k;
			a->key = k;
			cout << "������� ���" << endl;
			cin >> str;
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	Client* b = new Client;
			cout << "������� ����� �����: " << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: Client * c = new Client;
			cout << "������� ����� �����: " << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "������ �� ������" << endl;
			else
			{
				cout << "������ � ������: " << endl;
				Client_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}
