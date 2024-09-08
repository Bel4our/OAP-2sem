#include <iostream>

using namespace std;

double firstEqua(double x) //функция возвращающая первое уравнение
{
	return (sin(x) + x * x * x);
}

double secondEqua(double x) //функция возвращающая второе уравнение
{

	return (0.4 * x * x * x); 
	
}

double useDichotomy(double(*funct)(double), double a, double b, double e) // функция содержащая алгоритм метода дихотомии
{
	double x,fx,fa;
	// алгоритм взят из лабораторной номер 9, 1 семестра
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
	cout << "Введите a и b для первого уравнения: "; cin >> a >> b; // вводим необходимые значения для первого уравнения
	cout << endl<< "x = " << useDichotomy(firstEqua, a, b, e) <<endl; // вызываем функцию с методом дихотомии

	cout << "Введите a и b для второго уравнения: "; cin >> a >> b; // вводим необходимые значения
	cout << endl<<"x = " << useDichotomy(secondEqua, a, b, e); // вызываем функцию с методом дихотомии
}