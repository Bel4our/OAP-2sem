#include <iostream>
#include <cstdarg>

using namespace std;

void mn(int n, ...) 
{
    va_list arg; // ��������� ������ ���� va_list ��� ������ � ����������� �����������
    va_start(arg, n); // �������� ������� �������� �� ������

    int min = va_arg(arg, int); // �������� ���������� ������ �������� �� ������
    for (int i = 1; i < n; ++i) 
    {
        int val;
        val = va_arg(arg, int); // �������� ������� �������� �� ������
        if (val < min) // ������� ��� ��������
        { 
            min = val;
        }
    }
    cout << "����������� ��������: " << min << endl;
    va_end(arg);  // ��������� ������ � �������� va_list

}

int main()
{
    setlocale(LC_ALL, "rus");
    //�������� ������� � ���������� ������ ����������
    mn(5, 10, 12, 4, 3, 9);
    mn(4, 15, 3,62, 1762);
    mn(6, 36520, 5234, 1448, 2276, 56,65);
}