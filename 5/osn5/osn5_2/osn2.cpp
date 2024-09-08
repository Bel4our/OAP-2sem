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
	char birthday[50];
	char addres[50];
	char gender;
};

struct citizen // структура
{
	buf full_name;
	buf birth;
	buf addr;
	buf gend;

};

citizen citizens[size];


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
		cout << "5 - Поиск информации по дате" << endl;
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
	int numb; // для хранения количества горожан
	int choice; // выбор из перечесления
	cout << "Введите количество горожан: "; cin >> numb;
	for (int i = 0;i < numb;i++)
	{
		if (current_size < size) // условие для проверки наличия места
		{
			// заполнение информации
			cout << "Информация о " << i + 1 << " горожанине: " << endl;
			cin.ignore();
			cout << endl << "ФИО: " << endl;
			gets_s(citizens[current_size].full_name.fullname, 50);
			cout << "Дата рождения: " << endl;
			gets_s(citizens[current_size].birth.birthday, 50);
			cout << "Адрес: " << endl;
			gets_s(citizens[current_size].addr.addres, 50);
			cout << "Пол: " << endl;
			cin >> citizens[current_size].gend.gender;
			current_size++;
		}
		
	}
}

void output() // функция вывода
{
	// вывод информации
	for (int i = 0; i < current_size;i++)
	{
		cout << "Информация о " << i + 1 << " горожанине: " << endl;
		cout << endl << "ФИО: " << citizens[i].full_name.fullname << endl;
		cout << "Дата рождения: " << citizens[i].birth.birthday<< endl;
		cout << "Адрес: " << citizens[i].addr.addres << endl;
		cout << "Пол: " << citizens[i].gend.gender << endl;
	}
}

void inFile() // функция записи в файл
{
	ofstream file1("FILE1.txt");
	if (file1)
	{
		for (int i = 0; i < current_size; i++)
		{
			file1 << "Информация о " << i + 1 << " горожанине: " << endl;
			file1 << endl << "ФИО: " << citizens[i].full_name.fullname << endl;
			file1 << "Дата рождения: " << citizens[i].birth.birthday << endl;
			file1 << "Адрес: " << citizens[i].addr.addres << endl;
			file1 << "Пол: " << citizens[i].gend.gender << endl;
		}
		cout << "Информация записана в файл!"<<endl;
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
		cout << line<<endl;
	}
	file1.close();

}


void find() // функция поиска
{
	string date;
	bool f = true;
	cout << "Введите дату рождения: "; 
	cin.ignore();
	getline(cin, date);
	for (int i = 0;i < current_size;i++)
	{
		if (date == citizens[i].birth.birthday)
		{
			cout << "Информация о " << i + 1 << " горожанине: " << endl;
			cout << endl << "ФИО: " << citizens[i].full_name.fullname << endl;
			cout << "Дата рождения: " << citizens[i].birth.birthday << endl;
			cout << "Адрес: " << citizens[i].addr.addres << endl;
			cout << "Пол: " << citizens[i].gend.gender << endl;
			f = false;
		}
	}
	if (f)
	{
		cout << "Информация не найдена!" << endl;
	}
}