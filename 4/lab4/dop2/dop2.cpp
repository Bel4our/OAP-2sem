#include <iostream>
#include <string>
#include <Windows.h>

#define size 8

using namespace std;

void input(); // функция для ввода
void output(); // функция для вывода
void sortoftime(); // функция для вывода поездов отправляющихся по времени после введённого числа с клавиатуры

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
	//меню выбора
	do
	{
		cout << "1 - Ввод элементов структуры с клавиатуры" << endl;
		cout << "2 - Вывод элементов структуры в консольное окно" << endl;
		cout << "3 - Вывод элементов после введённого времени" << endl;
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
			sortoftime();
			break;
		}
	} while (choice != 4);

	return 0;
}

void input() // функция для ввода
{
	for (int i = 0;i < 8;i++)
	{
		if (i < size)
		{
			// заполнение информации
			cin.ignore();
			cout << "Информация о " << i + 1 << " поезде: " << endl;
			cout << endl << "Пункт назначения " << endl;
			getline(cin, trains[i].destination);
			cout << "Время отправления " << endl;
			getline(cin, trains[i].time);
			cout << "Номер поезда " << endl;
			cin >> trains[i].number;
		}
	}
	for (int i = 0;i < 8;i++) // сортируем массив по пунктам назначения
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

void output() // функция для вывода
{
	for (int i = 0;i < 8;i++)
	{
		cout << endl << "Пункт назначения " << trains[i].destination << endl;
		cout << "Номер поезда " << trains[i].number << endl;
		cout << "Время отправления " << trains[i].time << endl;
	}
}

void sortoftime() // функция для вывода поездов отправляющихся по времени после введённого числа с клавиатуры

{
	string time;
	cout << "Введите время отправления: ";
	cin.ignore();
	getline(cin, time);
	bool f=true;
	for (int i = 0;i < 8;i++)
	{
		if (trains[i].time > time)
		{
			cout << endl << "Пункт назначения " << trains[i].destination << endl;
			cout << "Номер поезда " << trains[i].number << endl;
			cout << "Время отправления " << trains[i].time << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "Поездов не найдено" << endl;
	}
}