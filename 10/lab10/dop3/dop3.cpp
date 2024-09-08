#include <iostream>
using namespace std;

void swap(int& a, int& b) // меняем местами значение
{
    int temp = a;
    a = b;
    b = temp;
}

void perestanovka(int nums[], int st, int en) //рекурсивная функция для обмена
{
    if (st == en) //если дошли до конца массива
    {
        for (int i = 0; i <= en; i++)  //выводим строку
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    else //иначе
    {
        for (int i = st; i <= en; i++)  //пока не дойдём до конца массива
        {
            swap(nums[st], nums[i]); //меняем местами
            perestanovka(nums, st + 1, en); //рекурсивно вызываем функцию для генерации перестановок подмассива
            swap(nums[st], nums[i]); // возвращаем на место исходный порядок
        }
    }
}

int main()
{
    int n = 5;
    int numbers[] = { 1, 2, 3, 4, 5 };
    perestanovka(numbers, 0, n - 1); //вызываем функцию
    return 0;
}
