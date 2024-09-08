#include <iostream>
#include <string> // для работы со строками
#include <windows.h> // для корректного отображения символов
#define size 10 //подключение макроса для длины массива

using namespace std;

void input(); //прототип функции ввода
void output(); // прототип функции вывода
void del(); // прототип функции для удаления
void find(); // прототип функции поиска

struct teacher // структура
{
	string name;
	string exam;
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 14;
};

teacher teachers[size];

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
	int day, month, year;
	int teach; // для хранения количества преподавателей
	cout << "Введите количество преподавателей: "; cin >> teach;
	for (int i = 0;i < teach;i++)
	{
		if (current_size < size) // условие для проверки наличия места
		{
			// заполнение информации
			cout << "Информация о " << i + 1 << " преподавателе: " << endl;
			cin.ignore();
			cout << endl << "ФИО преподавателя: " << endl;
			getline(cin, teachers[current_size].name);
			cout << "Название экзамена: " << endl;
			getline(cin, teachers[current_size].exam);
			cout << "Введите дату в формате ДД ММ ГГГГ: " << endl;
			cin >> day>>month>>year;
			teachers[current_size].day = day;
			teachers[current_size].month = month;
			teachers[current_size].year = year;
			current_size++;
		}
	}
}

void output() // функция вывода
{
	// вывод информации
	for (int i = 0; i < current_size;i++)
	{
		cout << "Информация о " << i + 1 << " преподавателе " << endl;
		cout << endl << "ФИО преподавателя: " << teachers[i].name <<endl;
		cout << "Название экзамена: " << teachers[i].exam <<endl;
		cout << "Дата экзамена: " << teachers[i].day <<" "<< teachers[i].month <<" " << teachers[i].year << endl;
	}
}

void del() // функция для удаления
{
	int d;
	bool f = false;
	int day, month, year;
	cout << "Введите дату экзамен которого хотите удалить в формате ДД ММ ГГГГ" << endl;
	cin >> day >> month >> year;
	cin.ignore();
	for (int i = 0;i < current_size;i++)  // ищем подходящее
	{
		if (day==teachers[i].day && month == teachers[i].month && year == teachers[i].year) // если нашли
		{
			d = i; // запоминаем
			f = true;
		}
	}
	if (f) // если нашли
	{
		for (int de1 = d; de1 < current_size; de1++) // цикл для удаления
		{
			teachers[de1] = teachers[de1 + 1];
		}
			current_size = current_size - 1;
		
		cout << "Информация удалена" << endl;
	}
	else
		cout << "Преподаватель не найден!" << endl; // иначе выводим что не нашли
}

void find() // функция поиска
{
	bool f=true;
	int day, month, year;
	cout << "Введите дату экзамен чтобы найти преподаватаеля в формате ДД ММ ГГГГ" << endl;
	cin >> day >> month >> year;
	cin.ignore();
	for (int i = 0;i < current_size;i++)
	{
		if (day == teachers[i].day && month == teachers[i].month && year == teachers[i].year) // если нашли выводим
		{
			cout << "Информация о " << i + 1 << " преподавателе: " << endl;
			cout << endl << "ФИО преподавателя: " << teachers[i].name<<endl;
			cout << "Название экзамена: " << teachers[i].exam<<endl;
			cout << "Дата экзамена: " << teachers[i].day <<" " << teachers[i].month <<" " << teachers[i].year << endl;
			f = false;
		}	}
	if (f)
	{
		cout << "Преподаватель не найден!" << endl;
	}
}