#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
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
	char str[1000]; // переменная которая хранит строки
	while (file1.getline(str, 1000)) // цикл для записи строк из файла
	{
		int count = 0; // переменная для хранения количества пробелов
		for (int i = 0;i < strlen(str);i++) // цикл для пробега по всей строке
		{
			if (str[i] == ' ') // если нашли пробел
			{
				count++; // увеличваем значение
			}
		}
		if (count == 0) // если пробелов нет, значит строка состоит из одного слова
		{
			file2 << str << '\n'; // записываем её в файл
		}
	}
	// закрываем файлы
	file1.close();
	file2.close();

	ifstream file3("FILE2.txt"); //открываем файл для чтения
	if (file3.fail()) // проверка на открытие файла
	{
		cout << "\n Ошибка открытия FILE2.txt";
		return 1;
	}
	int count = 0; // переменная для подсчёта символов
	while (file3.getline(str, 1000)) // цикл для записи строк
	{
		count += strlen(str); // считаем количество символов
	}
	cout << "Количество символов: " << count; // выводим в консоль
	// закрываем файл
	file3.close();
	return 0;
}
