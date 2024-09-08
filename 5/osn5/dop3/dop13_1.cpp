#include <iostream>
#include <string> // для работы со строками
#include <windows.h> // для корректного отображения символов
#define size 10 //подключение макроса для длины массива

using namespace std;

void input(); //прототип функции ввода
void output(); // прототип функции вывода
void del(); // прототип функции для удаления
void find(); // прототип функции поиска

enum faculty // перечисление
{
	ФИТ = 1, не_ФИТ
};
struct student // структура
{
	char name[50];
	char speciality[50];
	int group;
	float average;
	faculty fac;
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 14;
};

student students[size];

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
			cout << "Информация о " << i + 1 << " студенте: " << endl;
			cin.ignore();
			cout << endl << "ФИО: " << endl;
			gets_s(students[current_size].name,50);
			cout << "Специальность: "<<endl;
			gets_s(students[current_size].speciality, 50);
			cout << "Введите дату поступления в формате ДД ММ ГГГГ: " << endl;
			cin >> day >> month >> year;
			students[current_size].day = day;
			students[current_size].month = month;
			students[current_size].year = year;
			cout << "Факультет (1 - ФИТ, 2 - не ФИТ): " << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				students[current_size].fac = ФИТ;
				break;
			case 2:
				students[current_size].fac = не_ФИТ;
				break;
			}
			cout << "Группа: " << endl;
			cin >> students[current_size].group;
			cout << "Средний балл: " << endl;
			cin >> students[current_size].average;
			current_size++;
		}
	}
}

void output() // функция вывода
{
	// вывод информации
	for (int i = 0; i < current_size;i++)
	{
		cout << endl << "ФИО: " << students[i].name << endl;
		cout << "Дата поступления: " << students[i].day << students[i].month << students[i].year <<endl;
		cout << "Специальность: " << students[i].speciality<< endl;
		cout << "Группа: " << students[i].group << endl;
		cout << "Факультет: ";
		if (students[i].fac == ФИТ)
		{
			cout << "ФИТ";
		}
		else
			if (students[i].fac == не_ФИТ)
			{
				cout << " не ФИТ";
			}
		cout << endl;
		cout << "Средний балл: " << students[i].average << endl;
	}
}

void del() // функция для удаления
{
	int d;
	bool f = false;
	float av;
	cout << "Введите средний балл для удаления информации" << endl;
	cin >> av;
	for (int i = 0;i < current_size;i++)  // ищем подходящее
	{
		if (av == students[i].average) // если нашли
		{
			d = i; // запоминаем
			f = true;
		}
	}
	if (f) // если нашли
	{
		for (int de1 = d; de1 < current_size; de1++) // цикл для удаления
		{
			students[de1] = students[de1 + 1];
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
	float av;
	cout << "Введите средний балл для поиска информации: " << endl;
	cin >> av;
	for (int i = 0;i < current_size;i++)
	{
		if (av == students[i].average) // если нашли выводим
		{
			cout << endl << "ФИО: " << students[i].name << endl;
			cout << "Дата поступления: " << students[i].day <<" " << students[i].month << " " << students[i].year << endl;
			cout << "Специальность: " << students[i].speciality << endl;
			cout << "Группа: " << students[i].group << endl;
			cout << "Факультет: ";
			if (students[i].fac == ФИТ)
			{
				cout << "ФИТ";
			}
			else
				if (students[i].fac == не_ФИТ)
				{
					cout << "не ФИТ";
				}
			cout << endl;
			cout << "Средний балл: " << students[i].average << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "Информация не найдена!" << endl;
	}
}