#include <iostream>

using namespace std;

double firstEqua(double x) //������� ������������ ������ ���������
{
	return (sin(x) + x * x * x);
}

double secondEqua(double x) //������� ������������ ������ ���������
{

	return (0.4 * x * x * x); 
	
}

double useDichotomy(double(*funct)(double), double a, double b, double e) // ������� ���������� �������� ������ ���������
{
	double x,fx,fa;
	// �������� ���� �� ������������ ����� 9, 1 ��������
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
	cout << "������� a � b ��� ������� ���������: "; cin >> a >> b; // ������ ����������� �������� ��� ������� ���������
	cout << endl<< "x = " << useDichotomy(firstEqua, a, b, e) <<endl; // �������� ������� � ������� ���������

	cout << "������� a � b ��� ������� ���������: "; cin >> a >> b; // ������ ����������� ��������
	cout << endl<<"x = " << useDichotomy(secondEqua, a, b, e); // �������� ������� � ������� ���������
}