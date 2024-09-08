#include <iostream>
#include <fstream>

using namespace std;

bool isVow(char* symbol) // функция для подсчёта гласных букв
{
	char s = *symbol;
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') // если буква гласная
	{
		return true; // возвращаем true
	}
	else
	{
		return false; // иначе false
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	ifstream file1("FILE1.txt"); // открываем файл для чтения
	ofstream file2("FILE2.txt"); // открываем файл для записи

	if (file1.fail()) // проверка на открытие файла
	{
		cout << "\n Ошибка открытия FILE1.txt";
		return 1;
	}
	if (file2.fail()) // проверка на открытие файла
	{
		cout << "\n Ошибка открытия FILE2.txt";
		return 1;
	}

	int k; 
	char str[1000]; // переменная для хранения строки
	cout << "Введите k от 1 до 6: "; cin >> k; // вводим K
	if (k > 6 || k<1) // так как в файле 9 строк ставим такое условие
	{
		cout << "Вы ввели неправильное значение! ";
		return 1;
	}

	int nk = k + 3; // переменная которая хранит по какую строку мы будем выводить
	int count = 1; // счтётчик строк
	while (file1.getline(str, 1000)) // цикл для записи строк из файла
	{
		if (count >= k && count<=nk) // если выполняется условие
		{
			file2 << str<<"\n"; // записываем строку в файл
		}
		count++; // увеличиваем знаение
	}
	// закрываем файлы
	file1.close();
	file2.close();

	ifstream file3("FILE2.txt"); // открываем файл для чтения
	if (file3.fail()) // проверка на открытие файла
	{
		cout << "\n Ошибка открытия FILE2.txt";
		return 1;
	}
	count = 0; // обнуляем счётчик для дальнейшего сипользования при подсчёте гласных букв
	while (file3.getline(str, 1000)) // цикл для записи строк из файла
	{
		for (int i = 0; str[i] != '\0';i++) // бежим по строке 
		{
			if (isVow(&str[i])) // вызваем функцию и если условие выполняется 
			{
				count++; // то увеличиваем значение
			}
		}
	
	}
	cout << "Количество гласных: " << count; // выводим количество в консоль

	file3.close(); // закрываем файл
	return 0;
}