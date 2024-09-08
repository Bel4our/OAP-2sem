#include <iostream>
#include <fstream>

using namespace std;

bool isVow(char* symbol) //функция для проверки на гласную
{
	char s = *symbol;
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') // если символ гласный
	{
		return true; // возвращаем true
	}
	else
	{
		return false; // иначе возвращаем false
	}
}

int findNumb(char* str) // функция которая определяет номер нужного слова
{
	int count = 0; // переменная для подсчёта количества гласных в нужном слове
	int nowcount = 0; // переменная для подсчёта количества гласных в текущем слове
	int bufnumbword = 0; // переменная для подсчёта всех слов
	int numbword = 0; // переменная для хранения номера нужного слова
	for (int i = 0;i < strlen(str);i++) // бежим по строке
	{
		if (isVow(&str[i])) // если гласная
		{
			nowcount++; // увеличиваем значение
		}
		if (str[i] == ' ' || str[i + 1] == '\0') // если слово закончилось
		{
			bufnumbword++; //увеличваем значение
			if (count < nowcount) // если в текущем слове гласных больше, то 
			{
				//обновляем значения
				count = nowcount;
				numbword = bufnumbword;
				
			}
			nowcount = 0;  // обнуляем значение
		}
	}
	return numbword; // возвращаем номер слова
}


int main()
{
	setlocale(LC_ALL, "rus");
	ifstream file1("FILE1.txt"); // открываем файл для чтения 
	ofstream file2("FILE2.txt"); // открываем файл для записи
	char line[1000]; // переменная для хранения строки
	int count = 0; // счётчик пробелов
	if (file1.fail()) // проверка на открытие файла
	{
		cout << "\n Ошибка открытия файла FILE1.txt";
		return 1;
	}
	if (file2.fail()) // проверка на открытие файла
	{
		cout << "\n Ошибка открытия файла FILE2.txt";
		return 1;
	}
	while (file1.getline(line, 1000)) // цикл для записи строк из фала
	{
		for (int i = 0; i < strlen(line);i++) // бежим по строке
		{
			if (line[i] == ' ') // если наткунлись на пробел
			{
				count++; // увеличиваем значение
			}
		}

		if (count > 1) // если пробелов больще 1, значит слов больше чем два
		{
			file2 << line<< '\n'; // поэтому записываем в файл
			int numb = findNumb(line); // вызываем функцию для поиска номера слова и присваиваем её значение numb
			cout << "Номер слова: " << numb << endl; // выводим номер слова
		}
		count = 0; // обнуляем счётчик
	}
	// закрываем файлы
	file1.close();
	file2.close();
}