#include <iostream>
#include <cmath>

using namespace std;

double func(int n, double x) // ����������� �������
{
	if (n == 0) // ���� ����������� �������
	{
		return 0; // ����������
	}
	else //�����
	{
		return cos(n * x) + func(n - 1, x); //����������
	}
}

int main()
{
	double y = func(1, 3.14); //�����������
	cout << y; //�������

	return 0;
}
