#include <iostream> // подключаем библиотеку для работы с вводом/выводом
#include <cstdarg>  // подключаем библиотеку для работы с функциями с произвольным количеством аргументов

using namespace std;

int findWord(int n, ...)  // функция для нахождения необходимого слова
{
    va_list args; // Объявляем объект типа va_list для работы с переменными аргументами
    va_start(args, n); // Получаем текущий аргумент из списка

    char word[100]; // массив для хранения текущего слова
    char strwords[600]; // массив для вывода отсортированной строки

    for (int i = 1; i <= n; i++)
    {
        memset(word, 0, sizeof(word));  // заполняем массив 0, чтобы не выводился мусор
        memset(strwords, 0, sizeof(strwords)); // заполняем массив 0, чтобы не выводился мусор
        int len = 0; // переменная для хранеия длины текущего слова
        const char* newstr = va_arg(args, const char*); // Получаем текущий аргумент из списка
        char symb = 'a'; // создаём переменную для проверки слов 
        int newsymb = symb; 
        bool f = true; 
        int len2 = 0; // переменная для контроля длины отсортированной строки
        int w = 0; 

        while (w < 5) // цикл для заполнения нашими словами строки
        {
            while (f) // цикл для нахождения необходимого слова
            {
                for (int j = 0;newstr[j] != '\0';j++) // цикл для того чтобы просмотреть всю строку
                {
                    if (newstr[j] == newsymb && newstr[j - 1] == ' ') // условие для нахождения необходимого слова
                    {
                        int m = j; // создаём переменную для того чтобы знать какие элементы массива нам необходимы
                        for (int k = 0;newstr[m] != ' ';k++, m++) // цикл для заполнения массива найденным словом
                        {
                            word[k] = newstr[m];
                        }
                        len = m;
                        f = false;
                    }
                }
                newsymb = newsymb + 1; // увеличиваем значение переменной для просмотра следующей буквы по алфавиту
            }

            for (int k = 0;k < len;k++, len2++) // цикл для заполнения строки найденным словом
            {
                strwords[len2] = word[k];
            }
            f = true;
            strwords[len2] = ' '; // добавляем пробел после слова
            len2++;
            w++;
        }
        cout << endl;
        for (int i = 0;i < len2;i++)
        {
            cout << strwords[i]; // выводим нашу строку
        }
        cout << endl;
    }
    cout << endl;

    va_end(args); // Завершаем работу с объектом va_list
    return 0;
}

int main()
{
    // создаем три массива содержащих строки
    char str1[] = " bghj agfj cdfa ehlhksgdh dldglhfd ";
    char str2[] = " ehgh bdggfj ajhkgs dhlkdfj cldkgjh ";
    char str3[] = " dhhhghj csgfdsgj edjgfa bgddkg ahf ";

    // вызываем функции
    findWord(2, str1, str2);
    findWord(3, str1, str2, str3);
    findWord(1, str1);

    return 0;
}
