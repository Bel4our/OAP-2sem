#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	// открываем 2 файла для записи
	ofstream file1("FILE1.txt"); 
	ofstream file2("FILE2.txt");
	
	char str[1000]; // переменная для хранения строки
	cout << "Введите строку: ";
	gets_s(str); // вводим строку
	if (file1.is_open()) // если файл открылся
	{
		file1 << str; // записываем в него строку
		file1.close(); // закрываем файл
	}
	else // иначе выводим ошибку
	{
		cout << "Не удалось открыть файл для записи.";
		return 1;
	}
	//открываем файл для чтения
	ifstream file3("FILE1.txt");
	if (file3.fail()) // проверка на открытие файла
	{
		cout << "\n Ошибка открытия FILE1.txt";
		return 1;
	}
	char word[100];  // переменная для хранения слова
	while (file3 >> word) // цикл для записи слов из файла
	{
		int i = 0;
		if (!(word[i]>='0' && word[i]<='9')) // если word не содержит цифру значит группа цифр
		{
			file2 << word << '\n'; // поэтому записываем в файл
			cout << word << " "; // выводим в консоль
		}
	}
	//закрываем файлы
	file2.close();
	file3.close();
	return 0;
}