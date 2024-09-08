#include <iostream>
#include <string> // для работы со строками
#include <windows.h> // для корректного отображения символов
#define size 10 //подключение макроса для длины массива

using namespace std;

void input(); //прототип функции ввода
void output(); // прототип функции вывода
void del(); // прототип функции для удаления
void find(); // прототип функции поиска

enum polity // перечисление
{
	монархия=1, республика
};

struct Country // структура
{
	string name;
	string capital;
	int number;
	int square;
	polity polyt;
};

Country countries[size];

int choice;
int current_size=0;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//меню выбора
	do
	{
		cout << "1 - Ввод элементов с клавиатуры" << endl;
		cout << "2 - Вывод элементов в консольное окно" << endl;
		cout << "3 - Удаление заданной структурированной переменной" << endl;
		cout << "4 - Поиск информации " << endl;
		cout << "5 - Выход из программы" << endl;
		cin >> choice;
		// анализируем choice
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
		}
	} while (choice != 5);
	return 0;
}

void input() // функция ввода
{
	int land; // для хранения количества стран
	int choice; // выбор из перечесления
	cout << "Введите количество государств: "; cin >> land;
	for (int i = 0;i < land;i++)
	{
		if (current_size < size) // условие для проверки наличия места
		{
			// заполнение информации
			cout << "Информация о " << i + 1 << " стране: " << endl;
			cin.ignore();
			cout << endl << "Название страны " << endl;
			getline(cin, countries[current_size].name);
			cout << "Название столицы: " << endl;
			getline(cin, countries[current_size].capital);
			cout << "Население: " << endl;
			cin >> countries[current_size].number;
			cout << "Площадь " << endl;
			cin >> countries[current_size].square;
			cout << "Форма правления (1 - монархия, 2 - республика): " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				countries[current_size].polyt = монархия;
				break;
			case 2:
				countries[current_size].polyt = республика;
				break;
			}
			current_size++;
		}
	}
}

void output() // функция вывода
{
	// вывод информации
	for (int i = 0; i < current_size;i++)
	{
		cout << "Информация о " << i + 1 << " стране: " << endl;
		cout << endl << "Название страны " <<countries[i].name<<endl;
		cout << "Название столицы: " << countries[i].capital << endl;
		cout << "Население: " <<countries[i].number<<endl;
		cout << "Площадь " <<  countries[i].square<<endl;
		cout << "Форма правления: ";
		if (countries[i].polyt == монархия)
		{
			cout << "монархия";
		}
		else 
			if (countries[i].polyt == республика)
		{
			cout << "республика";
		}
		cout << endl;
	}
}

void del() // функция удаления
{
	int d;
	bool f=false;
	string cap;
	cout << "Название столицы страны, которую хотите удалить" << endl; 
	cin.ignore();
	getline(cin, cap);
	for (int i = 0;i < current_size;i++) 
	{
		if (countries[i].capital == cap) // если нашли
		{
			d = i; // запоминаем
			f = true;
		}
	}
	if (f) // если нашли
	{
		for (int de1 = d; de1 < current_size; de1++) // цикл для удаления
			countries[de1] = countries[de1 + 1];
		current_size = current_size - 1; // уменьшаем текущее количество структур

		cout << "Информация удалена" << endl;
	}
	else // иначе выводим что не нашли
		cout << "Страна по столице не найдена" << endl;

}

void find() // функция поиска
{
	string cap;
	bool f = true;
	cout << "Название столицы " << endl;
	cin.ignore();
	getline(cin, cap);
	for (int i = 0;i < current_size;i++)
	{
		if (countries[i].capital == cap) // если нашли, то выводим
		{
			cout << endl << "Название страны " << countries[i].name << endl;
			cout << "Название столицы: " << countries[i].capital << endl;
			cout << "Население: " << countries[i].number << endl;
			cout << "Площадь " << countries[i].square << endl;
			cout << "Форма правления: ";
			if (countries[i].polyt == монархия)
			{
				cout << "монархия";
			}
			else
				if (countries[i].polyt == республика)
				{
					cout << "республика";
				}
			cout << endl;
			f = false;
		}
		
	}
	if (f) // если не нашли
	{
		cout << "Страна не найдена!" << endl; // выводим что не нашли
	}
}