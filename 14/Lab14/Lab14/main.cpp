#include "Hash_Chain.h"
#include <iostream>
using namespace std;
struct Client // структура клиента
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
int hf(void* d) // хэш-функция с исключающим ИЛИ
{
	Client* client = static_cast<Client*>(d);
	int str = client->key;
	int hash = 0;
	hash ^= str;
	return hash;
}
//-------------------------------
void Client_print(listx::Element* e) // вывод
{
	cout << ((Client*)e->data)->key << '-' << ((Client*)e->data)->mas << " / ";
}
//-------------------------------
int main() // главная функция
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 2: {	Client* a = new Client;
			char* str = new char[20];
			cout << "Введите номер счёта: " << endl;
			cin >> k;
			a->key = k;
			cout << "Введите ФИО" << endl;
			cin >> str;
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	Client* b = new Client;
			cout << "Введите номер счёта: " << endl;
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: Client * c = new Client;
			cout << "Введите номер счёта: " << endl;
			cin >> k;
			c->key = k;
			if (H.search(c) == NULL)
				cout << "Клиент не найден" << endl;
			else
			{
				cout << "Клиент с ключом: " << endl;
				Client_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}
