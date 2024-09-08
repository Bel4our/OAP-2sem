#include <iostream>
#include <cstdarg>

using namespace std;

void fmin(int n, ...)
{
    va_list arg; // ��������� ������ ���� va_list ��� ������ � ����������� �����������
    va_start(arg, n); // �������� ������� �������� �� ������

    int min = va_arg(arg, int);  // �������� ���������� ������ �������� �� ������
    for (int i = 1; i < n; i++)
    {
        int val;
        val = va_arg(arg, int); // �������� ������� �������� �� ������
        if (val < min) // ������� ��� ��������
        {
            min = val;
        }
    } 
    cout <<"����������� ��������: " << min << endl;
    va_end(arg); // ��������� ������ � �������� va_list
 
}

int main() 
{
    setlocale(LC_ALL, "rus");
    //�������� ������� � ���������� ������ ����������
    fmin(5, 10,12,4, 3, 9);
    fmin(4, 15, 3, 2, 12);
    fmin(6, 320, 52, 148, 22,34, 30);
}