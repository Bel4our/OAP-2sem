#include <iostream>
#include <cstdarg>

using namespace std;

void mn(int n, ...)
{
    va_list arg; // Объявляем объект типа va_list для работы с переменными аргументами
    va_start(arg, n); // Получаем текущий аргумент из списка

    int max = va_arg(arg, int); // Присваем переменной первый аргумент из списка
    for (int i = 1; i < n; ++i)
    {
        int val; 
        val = va_arg(arg, int); // Получаем текущий аргумент из списка
        if (val > max)   // Условие для проверки
        {
            max = val;
        }
    }
    cout << "Максимальное значение: " << max << endl;
    va_end(arg); // Завершаем работу с объектом va_list

}

int main()
{
    setlocale(LC_ALL, "rus");
    // Вызываем функции с переменным числом параметров
    mn(3, 1560, 5126, 124523);
    mn(4, 15236, 36436, 7124, 12235);
    mn(5, 23250, 2575, 175478, 214322, 6345);
}