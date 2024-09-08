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
	char fullname[50];
	char day[50];
	char spec[50];
	int gr;
	char fac[50];
	float av;
};

struct student // структура
{
	buf full_name;
	buf entrday;
	buf speciality;
	buf group;
	buf facultyd;
	buf average;

};

student students[size];


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
	cout << "Введите количество студентов: "; cin >> numb;
	for (int i = 0;i < numb;i++)
	{
		if (current_size < size) // условие для проверки наличия места
		{
			// заполнение информации
			cout << "Информация о " << i + 1 << " студенте: " << endl;
			cin.ignore();
			cout << endl << "ФИО: " << endl;
			gets_s(students[current_size].full_name.fullname, 50);
			cout << "Дата поступления: " << endl;
			gets_s(students[current_size].entrday.day, 50);
			cout << "Специальность: " << endl;
			gets_s(students[current_size].speciality.spec, 50);
			cout << "Группа: " << endl;
			cin >> students[current_size].group.gr;
			cin.ignore();
			cout << "Факультет: " << endl;
			gets_s(students[current_size].facultyd.fac, 50);
			cout << "Средний балл: " << endl;
			cin >> students[current_size].average.av;
			current_size++;
		}
	}
}

void output() // функция вывода
{
	// вывод информации
	for (int i = 0; i < current_size;i++)
	{
		cout << "Информация о " << i + 1 << " студенте: " << endl;
		cout << endl << "ФИО: " << students[i].full_name.fullname << endl;
		cout << "Дата поступления: " << students[i].entrday.day << endl;
		cout << "Специальность: " << students[i].speciality.spec << endl;
		cout << "Группа: " << students[i].group.gr << endl;
		cout << "Факультет: " << students[i].facultyd.fac << endl;
		cout << "Средний балл: " << students[i].average.av << endl;
	}
}

void inFile() // функция записи в файл
{
	ofstream file1("FILE1.txt");
	if (file1)
	{
		for (int i = 0; i < current_size; i++)
		{
			file1 << "Информация о " << i + 1 << " студенте: " << endl;
			file1 << endl << "ФИО: " << students[i].full_name.fullname << endl;
			file1 << "Дата поступления: " << students[i].entrday.day << endl;
			file1 << "Специальность: " << students[i].speciality.spec << endl;
			file1 << "Группа: " << students[i].group.gr << endl;
			file1 << "Факультет: " << students[i].facultyd.fac << endl;
			file1 << "Средний балл: " << students[i].average.av << endl;
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
	float aver;
	bool f = true;
	cout << "Введите средний балл: ";
	cin >> aver;
	for (int i = 0;i < current_size;i++)
	{
		if (aver == students[i].average.av)
		{
			cout << "Информация о " << i + 1 << " студенте: " << endl;
			cout << endl << "ФИО: " << students[i].full_name.fullname << endl;
			cout << "Дата поступления: " << students[i].entrday.day << endl;
			cout << "Специальность: " << students[i].speciality.spec << endl;
			cout << "Группа: " << students[i].group.gr << endl;
			cout << "Факультет: " << students[i].facultyd.fac << endl;
			cout << "Средний балл: " << students[i].average.av << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "Информация не найдена!" << endl;
	}
}