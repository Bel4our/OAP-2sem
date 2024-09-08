#include <iostream>
#include <fstream> // для работы с файлами
#include <string> // для работы со строками

using namespace std;

bool containsP(const string& word) // функция для поиска P в слове
{
    for(int i = 0; i < word.length(); i++) // бежим по слову
    {
        if (word[i]== 'p' || word[i] == 'P') //если есть P 
        {
            return true; // то возвращаем true
        }
    }
    return false;// если вслове нет P возвращаем false
}

int main()
{
    setlocale(LC_ALL, "rus");

    string str;
    cout << "Введите строку: ";
    getline(cin, str); // вводим строку
    cout << endl; // переход на новую строку в консоли
    ofstream file("FILE.txt"); // открываем файл для записи
    if (file.is_open()) // проверка на открытие
    {
        file << str; // записываем строку в файл
        file.close(); // закрываем файл
    }
    else // иначе выводим ошибку
    {
        cout << "Не удалось открыть файл для записи.";
        return 1;
    }

    ifstream file1("FILE.txt"); // открываем файл для чтения
    string word; // переменная для хранения текущего слова
    if (file1.is_open()) // если файл открыт
    {
        while (file1 >> word) //цикл который записывает в word слова по очереди, пока не дойдёт до конца файла
        {
            if (containsP(word)) // вызываем функцию и если условие выполняется
            {
                cout << word << " "; // выводим слово
            }
        }
        file1.close(); // закрываем файл
    }
    else // иначе выводим ошибку
    {
        cout << "Не удалось открыть файл для чтения.";
        return 1;
    }

    return 0;
}
