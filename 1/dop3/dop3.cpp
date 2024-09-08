#include <iostream>
#include <cstdarg>

using namespace std;

void mn(int n, ...) 
{
    va_list arg; // Объявляем объект типа va_list для работы с переменными аргументами
    va_start(arg, n); // Получаем текущий аргумент из списка

    int min = va_arg(arg, int); // Присваем переменной первый аргумент из списка
    for (int i = 1; i < n; ++i) 
    {
        int val;
        val = va_arg(arg, int); // Получаем текущий аргумент из списка
        if (val < min) // условие для проверки
        { 
            min = val;
        }
    }
    cout << "Минимальное значение: " << min << endl;
    va_end(arg);  // Завершаем работу с объектом va_list

}

int main()
{
    setlocale(LC_ALL, "rus");
    //вызываем функции с переменным числом параметров
    mn(5, 10, 12, 4, 3, 9);
    mn(4, 15, 3,62, 1762);
    mn(6, 36520, 5234, 1448, 2276, 56,65);
}