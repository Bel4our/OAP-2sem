#include <iostream>

using namespace std;

double firstEqua(double x)
{
	return (x * x*x + 3 * x - 1);
}

double secondEqua(double x)
{

	return (exp(x) - 4);

}

double useDichotomy(double(*funct)(double), double a, double b, double e)
{
	double x, fx, fa;
	do {
		x = (a + b) / 2;
		fx = funct(x);
		fa = funct(a);
		if (fx * fa <= 0)
			b = x;
		else
			a = x;
	} while (abs(a - b) > 2 * e);
	return(x);
}

int main()
{
	setlocale(LC_ALL, "rus");
	double a, b, e = 0.0001;
	cout << "Введите a и b для первого уравнения: "; cin >> a >> b;
	cout << endl << "x = " << useDichotomy(firstEqua, a, b, e) << endl;
	cout << "Введите a и b для второго уравнения: "; cin >> a >> b;
	cout << endl << "x = " << useDichotomy(secondEqua, a, b, e);
}