#include <iostream>
#include <string> // для работы со строками
#include <windows.h> // для корректного отображения символов
#define size 10 //подключение макроса для длины массива

using namespace std;

void input(); //прототип функции ввода
void output(); // прототип функции вывода
void del(); // прототип функции для удаления
void find(); // прототип функции поиска

struct notebook // структура
{
	string name;
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 14;
	string addr;
	string phonenumber;
};

notebook diary[size];

int choice;
int current_size = 0;

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
	int day, month, year;
	int numb; // для хранения количества 
	cout << "Введите количество записей: "; cin >> numb;
	for (int i = 0;i < numb;i++)
	{
		if (current_size < size) // условие для проверки наличия места
		{
			// заполнение информации
			cout << "Информация о " << i + 1 << " записи: " << endl;
			cin.ignore();
			cout << endl << "ФИО: " << endl;
			getline(cin, diary[current_size].name);
			cout << "Адрес: " << endl;
			getline(cin, diary[current_size].addr);
			cout << "Номер телефона: " << endl;
			getline(cin, diary[current_size].phonenumber);
			cout << "Введите дату в формате ДД ММ ГГГГ: " << endl;
			cin >> day >> month >> year;
			diary[current_size].day = day;
			diary[current_size].month = month;
			diary[current_size].year = year;
			current_size++;
		}
	}
}

void output() // функция вывода
{
	// вывод информации
	for (int i = 0; i < current_size;i++)
	{
		cout << "Информация о " << i + 1 << " человеке в записной книжке: " << endl;
		cout << endl << "ФИО: " << diary[i].name << endl;
		cout << "Введите дату в формате ДД ММ ГГГГ: " << endl;
		cout << "Дата рождения: " << diary[i].day << " " << diary[i].month << " " << diary[i].year << endl;
		cout << "Адрес: " << diary[i].addr << endl;
		cout << "Номер телефона: " << diary[i].phonenumber << endl;
	}
}

void del() // функция для удаления
{
	int d;
	bool f = false;
	string line;
	cout << "Введите ФИО для удаления информации" << endl;
	cin.ignore();
	getline(cin, line);
	for (int i = 0;i < current_size;i++)  // ищем подходящее
	{
		if (line==diary[i].name) // если нашли
		{
			d = i; // запоминаем
			f = true;
		}
	}
	if (f) // если нашли
	{
		for (int de1 = d; de1 < current_size; de1++) // цикл для удаления
		{
			diary[de1] = diary[de1 + 1];
		}
		current_size = current_size - 1;

		cout << "Информация удалена" << endl;
	}
	else
		cout << "Информация не найдена!" << endl; // иначе выводим что не нашли
}

void find() // функция поиска
{
	bool f = true;
	string line;
	cout << "Введите ФМО для удаления информации" << endl;
	cin.ignore();
	getline(cin, line);
	for (int i = 0;i < current_size;i++)
	{
		if (line == diary[i].name) // если нашли выводим
		{
			cout << "Информация о " << i + 1 << " записи: " << endl;
			cout << endl << "ФИО: " << diary[i].name << endl;
			cout << "Введите дату в формате ДД ММ ГГГГ: " << endl;
			cout << "Дата рождения: " << diary[i].day << " " << diary[i].month << " " << diary[i].year << endl;
			cout << "Адрес: " << diary[i].addr << endl;
			cout << "Номер телефона: " << diary[i].phonenumber << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "Информация не найдена!" << endl;
	}
}