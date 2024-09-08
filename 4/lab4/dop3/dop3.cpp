#include <iostream>
#include <string>
#include <Windows.h>

#define size 10

using namespace std;

void input(); // функция для ввода
void output(); // функция для вывода
void search(); // функция для поиска

struct Sanatorium
{
	string name;
	string location;
	string profile;
	int tickets;
};

Sanatorium sanat[size];
Sanatorium buff;
int current_size = 0;
int choice;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//меню выбора
	do
	{
		cout << "1 - Ввод элементов структуры с клавиатуры" << endl;
		cout << "2 - Вывод элементов структуры в консольное окно" << endl;
		cout << "3 - Поиск элементов" << endl;
		cout << "4 - Выход из программы" << endl;
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
			search();
			break;
		}
	} while (choice != 4);


	return 0;
}

void input()
{
	int s;
	cout << "Сколько санаториев вы хотите ввести? ";
	cin >> s;
	for (int i = 0;i < s;i++)
	{
		// заполнение информации
		if (current_size < size)
		{
			cin.ignore();
			cout << "Информация о " << i + 1 << " санатории: " << endl;
			cout << endl << "Название санатория " << endl;
			getline(cin, sanat[i].name);
			cout << "Место расположения " << endl;
			getline(cin, sanat[i].location);
			cout << "Лечебный профиль " << endl;
			getline(cin, sanat[i].profile);
			cout << "Количество путёвок " << endl;
			cin >> sanat[i].tickets;
			current_size++;
		}
	}
}

void output()
{
	for (int i = 0; i < current_size; i++)  // сортируем
	{
		for (int j = i + 1; j < current_size; j++) 
		{
			if (sanat[i].profile > sanat[j].profile || (sanat[i].profile == sanat[j].profile && sanat[i].name > sanat[j].name))
			{
				buff = sanat[i];
				sanat[i] = sanat[j];
				sanat[j] = buff;
			}
		}
	}
	for (int i = 0; i < current_size; i++) // выводим
	{
		cout << "Название: " << sanat[i].name << ", Место: " << sanat[i].location << ", Профиль: " << sanat[i].profile << ", Количество путёвок: " << sanat[i].tickets << endl;
	}
}

void search() // функция для поиска
{
	string profile;
	bool f=true;
	cout << "Введите профиль для поиска: ";
	cin.ignore();
	getline(cin, profile);
	for (int i = 0; i < current_size; i++) 
	{
		if (sanat[i].profile == profile) 
		{
			cout << "Название: " << sanat[i].name << ", Место: " << sanat[i].location << ", Профиль: " << sanat[i].profile << ", Количество путёвок: " << sanat[i].tickets << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "Санаторий не найден!" << endl;
	}
}
