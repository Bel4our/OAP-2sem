#include <iostream>

using namespace std;

int func(int m, int n) //рекурсивная функция
{
	if (n == 0 || m == 0) // если выполняется условие
	{
		return n + 1; // возвращаем
	}
	else // иначе
	{
		return func(m - 1, func(m,n-1)); //возвращаем
	}
}


int main()
{
	int F = func(1, 2); //присваиваем значение
	cout << F; //выводим

	return 0;
}