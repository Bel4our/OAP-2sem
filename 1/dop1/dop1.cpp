#include <iostream>
#include <cstdarg>

using namespace std;

void fmin(int n, ...)
{
    va_list arg; // Объявляем объект типа va_list для работы с переменными аргументами
    va_start(arg, n); // Получаем текущий аргумент из списка

    int min = va_arg(arg, int);  // Присваем переменной первый аргумент из списка
    for (int i = 1; i < n; i++)
    {
        int val;
        val = va_arg(arg, int); // Получаем текущий аргумент из списка
        if (val < min) // условие для проверки
        {
            min = val;
        }
    } 
    cout <<"Минимальное значение: " << min << endl;
    va_end(arg); // Завершаем работу с объектом va_list
 
}

int main() 
{
    setlocale(LC_ALL, "rus");
    //вызываем функции с переменным числом параметров
    fmin(5, 10,12,4, 3, 9);
    fmin(4, 15, 3, 2, 12);
    fmin(6, 320, 52, 148, 22,34, 30);
}