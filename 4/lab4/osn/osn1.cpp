#include <iostream>
#include <fstream> // библиотека для работы с файлами
#include <string> // для работы со строками
#include <windows.h> // для корректного отображения символов
#define size 30 //подключение макроса для длины массива

using namespace std;

void input(); //прототип функции ввода
void output(); // прототип функции вывода
void del(); // прототип функции для удаления
void find(); // прототип функции поиска
void inFile(); // прототип функции записи в файл
void outFile(); // прототип функции чтения из файла

struct Book // объявление структуры
{
	// обьявленние переменных структуры
	string carmodel; 
	string color;
	string carnumb;
	string daterelease;
	string typecar;
	int datetech;
	string owner;
};

Book list_of_cars[size]; // массив типа book для хранения информации
int current_size=0; // текущее заполнение массива
int cars; // количество машин
int choice; // выбор

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//меню выбора
	do
	{
		cout << "1 - Ввод элементов структуры с клавиатуры"<<endl;
		cout << "2 - Вывод элементов структуры в консольное окно" << endl;
		cout << "3 - Удаление заданной структурированной переменной" << endl;
		cout << "4 - Поиск информации по владельцу" << endl;
		cout << "5 - Запись информации в файл" << endl;
		cout << "6 - Чтение данных из файла" << endl;
		cout << "7 - Выход из программы" << endl;
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
		case 5:
			inFile();
			break;
		case 6:
			outFile();
			break;
		}
	} 
	while (choice!=7);

	return 0;
}

void input() // функция ввода
{
	cout << "Введите количество автомобилей: "; cin >> cars;
	for (int i = 0;i < cars;i++)
	{
		if (current_size < size) // условие для проверки наличия места
		{
			// заполнение информации
			cout << "Информация о " << i + 1 << " автомобиле: " << endl;
			cin.ignore();
			cout << endl << "Марка автомобиля " << endl;
			getline(cin, list_of_cars[current_size].carmodel);
			cout << "Цвет " << endl;
			getline(cin, list_of_cars[current_size].color);
			cout << "Дата выпуска " << endl;
			getline(cin, list_of_cars[current_size].daterelease);
			cout << "Заводской номер " << endl;
			getline(cin, list_of_cars[current_size].carnumb);
			cout << "Тип кузова " << endl;
			getline(cin, list_of_cars[current_size].typecar);
			cout << "Владелец " << endl;
			getline(cin, list_of_cars[current_size].owner);
			cout << "Дата техосмотра " << endl;
			cin >> list_of_cars[current_size].datetech;
			current_size++;
		}
	}
}

void output() // функция вывода
{
	for (int i = 0; i < current_size; i++) // цикл вывода информации
	{
		cout << "Информация о " << i + 1 << " автомобиле: " << endl;
		cout << endl << "Марка автомобиля " << list_of_cars[i].carmodel<<endl;
		cout << "Цвет " << list_of_cars[i].color<<endl;
		cout << "Дата выпуска " << list_of_cars[i].daterelease << endl;
		cout << "Заводской номер " << list_of_cars[i].carnumb << endl;
		cout << "Тип кузова " << list_of_cars[i].typecar << endl;
		cout << "Владелец " << list_of_cars[i].owner << endl;
		cout << "Дата техосмотра " << list_of_cars[i].datetech <<endl;
	}
}

void del() // функция удаления 
{
	int n;
	cout << "\nНомер автомобиля в каталоге, который надо удалить" << endl;  cin >> n;
	for (int de1 = (n - 1); de1 < current_size; de1++)
	{
		list_of_cars[de1] = list_of_cars[de1 + 1];
		current_size = current_size - 1;
	}
}

void find() // функция поиска по владельцу
{
	string findOwner;
	cin.ignore();
	bool f = true; // переменная для понимания нашли мы владельца или нет
	cout << "Введите данные об владельце: ";
	getline(cin, findOwner);
	for (int i = 0; i < current_size;i++)
	{
		if (findOwner == list_of_cars[i].owner)
		{
			cout << "Информация о " << i + 1 << " автомобиле: " << endl;
			cout << endl << "Марка автомобиля " << list_of_cars[i].carmodel << endl;
			cout << "Цвет " << list_of_cars[i].color << endl;
			cout << "Дата выпуска " << list_of_cars[i].daterelease << endl;
			cout << "Заводской номер " << list_of_cars[i].carnumb << endl;
			cout << "Тип кузова " << list_of_cars[i].typecar << endl;
			cout << "Владелец " << list_of_cars[i].owner << endl;
			cout << "Дата техосмотра " << list_of_cars[i].datetech << endl;
			f = false; // если нашли владельца false
		}
	}
	if (f) // если f == true значит мы не нашли владельца
	{
		cout << "Информация не найдена!"<<endl;
	}
}

void inFile() // функция записи в файл
{
	ofstream file1("FILE1.txt");
	if (file1)
	{
		for (int i = 0; i < current_size; i++)
		{
			file1 << "Информация о " << i + 1 << " автомобиле: " << endl;
			file1 << endl << "Марка автомобиля " << list_of_cars[i].carmodel << endl;
			file1 << "Цвет " << list_of_cars[i].color << endl;
			file1 << "Дата выпуска " << list_of_cars[i].daterelease << endl;
			file1 << "Заводской номер " << list_of_cars[i].carnumb << endl;
			file1 << "Тип кузова " << list_of_cars[i].typecar << endl;
			file1 << "Владелец " << list_of_cars[i].owner << endl;
			file1 << "Дата техосмотра " << list_of_cars[i].datetech << endl;
		}
		file1.close();
	}
	else
		cout << "Не удалось открыть файл!"<<endl;
}

void outFile() // функция чтения из файла
{
	ifstream file1("FILE1.txt");
	string line;
	while (getline(file1, line))
	{
		cout << line<<"\n";
	}
	file1.close();
}