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
	char capital[50];
	int people;
	int square;
	char prezident[50];
};

struct country // структура
{
	buf nam;
	buf cap;
	buf peop;
	buf sq;
	buf pr;
};

country countries[size];


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
			cout << "Информация о " << i + 1 << " стране: " << endl;
			cout << endl << "Название: " << endl;
			gets_s(countries[current_size].nam.name, 50);
			cout << "Столица: " << endl;
			gets_s(countries[current_size].cap.capital, 50);
			cout << "Фамилия президента: " << endl;
			gets_s(countries[current_size].pr.prezident, 50);
			cout << "Численность: " << endl;
			cin >> countries[current_size].peop.people;
			cout << "Площадь: " << endl;
			cin >> countries[current_size].sq.square;
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
		cout << endl << "Название: " << countries[i].nam.name << endl;
		cout << "Столица: " << countries[i].cap.capital << endl;
		cout << "Численность: " << countries[i].peop.people << endl;
		cout << "Площадь: " << countries[i].sq.square << endl;
		cout << "Фамилия президента: " << countries[i].pr.prezident << endl;
	}
}

void inFile() // функция записи в файл
{
	ofstream file1("FILE1.txt");
	if (file1)
	{
		for (int i = 0; i < current_size; i++)
		{
			file1 << "Информация о " << i + 1 << " стране: " << endl;
			file1 << endl << "Название: " << countries[i].nam.name << endl;
			file1 << "Столица: " << countries[i].cap.capital << endl;
			file1 << "Численность: " << countries[i].peop.people << endl;
			file1 << "Площадь: " << countries[i].sq.square << endl;
			file1 << "Фамилия президента: " << countries[i].pr.prezident << endl;
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
	cout << "Введите фамилию президента: ";
	cin.ignore();
	getline(cin, line);
	for (int i = 0;i < current_size;i++)
	{
		if (line == countries[i].pr.prezident)
		{
			cout << "Информация о " << i + 1 << " стране: " << endl;
			cout << endl << "Название: " << countries[i].nam.name << endl;
			cout << "Столица: " << countries[i].cap.capital << endl;
			cout << "Численность: " << countries[i].peop.people << endl;
			cout << "Площадь: " << countries[i].sq.square << endl;
			cout << "Фамилия президента: " << countries[i].pr.prezident << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "Информация не найдена!" << endl;
	}
}