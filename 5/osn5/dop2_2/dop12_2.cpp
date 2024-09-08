#include <iostream>
#include <fstream> // для работы с файлами
#include <string> // для работы со строками
#include <windows.h> // для корректного отображения символов
#define size 10 //подключение макроса для длины массива

using namespace std;

void input(); //прототип функции ввода
void output(); // прототип функции вывода
void inFile(); // прототип функции для записи в файл
void outFile(); // прототип функции для чтения из файла
void find(); // прототип функции поиска

union buf // объединение
{
	char name[50];
	char date[50];
	char addr[50];
	char phonenumber[50];
	char job[50];
	char position[50];
};

struct notebook // структура
{
	buf fullname;
	buf birthday;
	buf add;
	buf phone;
	buf pljob;
	buf pos;
};

notebook diary[size];


int choice;
int current_size;

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
		cout << "3 - Запись информации в файл" << endl;
		cout << "4 - Чтение информации из файла" << endl;
		cout << "5 - Поиск информации" << endl;
		cout << "6 - Выход из программы" << endl;
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
			inFile();
			break;
		case 4:
			outFile();
			break;
		case 5:
			find();
			break;
		}
	} while (choice != 6);
	return 0;
}

void input() // функция ввода
{
	int numb; // для хранения количества 
	int choice; // выбор из перечесления
	cout << "Введите количество записей: "; cin >> numb;
	for (int i = 0;i < numb;i++)
	{
		if (current_size < size) // условие для проверки наличия места
		{
			// заполнение информации
			cin.ignore();
			cout << "Информация о " << i + 1 << " человеке: " << endl;
			cout << endl << "ФИО: " << endl;
			gets_s(diary[current_size].fullname.name, 50);
			cout << "Дата рождения: " << endl;
			gets_s(diary[current_size].birthday.date, 50);
			cout << "Адрес: " << endl;
			gets_s(diary[current_size].add.addr, 50);
			cout << "Телефон: " << endl;
			gets_s(diary[current_size].phone.phonenumber, 50);
			cout << "Место работы или учёбы: " << endl;
			gets_s(diary[current_size].pljob.job, 50);
			cout << "Должность: " << endl;
			gets_s(diary[current_size].pos.position, 50);
			current_size++;
		}
	}
}

void output() // функция вывода
{
	// вывод информации
	for (int i = 0; i < current_size;i++)
	{
		cout << "Информация о " << i + 1 << " человеке: " << endl;
		cout << endl << "ФИО: " << diary[i].fullname.name << endl;
		cout << "Дата рождения: " << diary[i].birthday.date << endl;
		cout << "Адрес: " << diary[i].add.addr << endl;
		cout << "Телефон: " << diary[i].phone.phonenumber << endl;
		cout << "Место работы или учёбы: " << diary[i].pljob.job << endl;
		cout << "Должность: " << diary[i].pos.position << endl;
	}
}

void inFile() // функция записи в файл
{
	ofstream file1("FILE1.txt");
	if (file1)
	{
		for (int i = 0; i < current_size; i++)
		{
			file1 << "Информация о " << i + 1 << " человеке: " << endl;
			file1 << endl << "ФИО: " << diary[i].fullname.name << endl;
			file1 << "Дата рождения: " << diary[i].birthday.date << endl;
			file1 << "Адрес: " << diary[i].add.addr << endl;
			file1 << "Телефон: " << diary[i].phone.phonenumber << endl;
			file1 << "Место работы или учёбы: " << diary[i].pljob.job << endl;
			file1 << "Должность: " << diary[i].pos.position << endl;
		}
		cout << "Информация записана в файл!" << endl;
		file1.close();
	}
	else
		cout << "Не удалось открыть файл!" << endl;
}

void outFile() // функция чтения из файла
{
	ifstream file1("FILE1.txt");
	string line;
	while (getline(file1, line))
	{
		cout << line << endl;
	}
	file1.close();

}

void find() // функция поиска
{
	string line;
	bool f = true;
	cout << "Введите ФИО: ";
	cin.ignore();
	getline(cin, line);
	for (int i = 0;i < current_size;i++)
	{
		if (line == diary[i].fullname.name)
		{
			cout << "Информация о " << i + 1 << " человеке: " << endl;
			cout << endl << "ФИО: " << diary[i].fullname.name << endl;
			cout << "Дата рождения: " << diary[i].birthday.date << endl;
			cout << "Адрес: " << diary[i].add.addr << endl;
			cout << "Телефон: " << diary[i].phone.phonenumber << endl;
			cout << "Место работы или учёбы: " << diary[i].pljob.job << endl;
			cout << "Должность: " << diary[i].pos.position << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "Информация не найдена!" << endl;
	}
}