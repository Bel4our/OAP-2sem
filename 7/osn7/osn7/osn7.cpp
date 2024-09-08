#include <iostream>
#include <Windows.h>
#include "myStack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice; int x;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk = NULL;             //инициализация первого элемента	
	do
	{
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Запись в файл" << endl;
		cout << "4 - Чтение из файла" << endl;
		cout << "5 - Вывод стека" << endl;
		cout << "6 - Очистка стека" << endl;
		cout << "7 - Поиск элемента из диапазона" << endl;
		cout << "8 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> x;
			push(x, myStk); break;
		case 2: x = pop(myStk);
			if (x != -1)
				cout << "Извлеченный элемент: " << x << endl;
			break;
		case 3: toFile(myStk);  break;
		case 4: fromFile(myStk); break;
		case 5: cout << "Весь стек: " << endl;
			show(myStk); break;
		case 6: clear(myStk); break;
		case 7: find(myStk); break;
		}
	} while (choice != 8);
	return 0;
}