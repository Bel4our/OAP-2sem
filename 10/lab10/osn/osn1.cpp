#include <iostream>

using namespace std;

int func(int m, int n) //����������� �������
{
	if (n == 0 || m == 0) // ���� ����������� �������
	{
		return n + 1; // ����������
	}
	else // �����
	{
		return func(m - 1, func(m,n-1)); //����������
	}
}


int main()
{
	int F = func(1, 2); //����������� ��������
	cout << F; //�������

	return 0;
}