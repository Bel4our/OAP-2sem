#include <iostream>
#include <fstream>

using namespace std;

bool isBracket(char* str) // функция для поиска скобок
{
	char c = *str;
	if ( c == '('|| c == ')' || c=='['|| c == ']' || c == '{' || c == '}') // если текущий символ скобка
	{
		return true; // возвращаем true
	}
	else
	{
		return false; // иначе возвращаем false
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream file1("FILE1.txt"); // открываем файл для записи
	if (file1.fail()) // проверка на открытие файла
	{
		cout << "\n Ошибка открытия файла FILE1.txt";
		return 1;
	}
	char str[1000]; // переменная для хранения строки
	cout << "Введите строку: ";
	gets_s(str); // вводим строку
	file1 << str; // записываем в файл
	file1.close(); // закрываем файл
	ifstream file2("FILE1.txt"); // открываем файл для чтения
	if (file2.fail()) // проверка на открытие файла
	{
		cout << "\n Ошибка открытия файла FILE1.txt";
		return 1;
	}
	char newstr[1000]; // переменная для хранения новой строки
	file2.getline(newstr, 1000); // записываем строку из файла
	int count=0; // счётчик скобок
	for (int i = 0; i < strlen(newstr);i++) // бежим по строке
	{
		if (isBracket(&newstr[i])) // если скобка
		{
			count++; // увеличиваем значение
		}
	}
	cout << "Количество скобок: " << count; // выводим значение
	file2.close(); // закрываем файл
}