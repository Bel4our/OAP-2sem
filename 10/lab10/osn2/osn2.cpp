#include <iostream>
#include <cmath>

using namespace std;

double func(int n, double x) // рекурсивная функция
{
	if (n == 0) // если выполняется условие
	{
		return 0; // возвращаем
	}
	else //иначе
	{
		return cos(n * x) + func(n - 1, x); //возвращаем
	}
}

int main()
{
	double y = func(1, 3.14); //присваиваем
	cout << y; //выводим

	return 0;
}
