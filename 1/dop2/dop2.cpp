#include <iostream>
#include <cstdarg>

using namespace std;

void mn(int n, ...)
{
    va_list arg; // ��������� ������ ���� va_list ��� ������ � ����������� �����������
    va_start(arg, n); // �������� ������� �������� �� ������

    int max = va_arg(arg, int); // �������� ���������� ������ �������� �� ������
    for (int i = 1; i < n; ++i)
    {
        int val; 
        val = va_arg(arg, int); // �������� ������� �������� �� ������
        if (val > max)   // ������� ��� ��������
        {
            max = val;
        }
    }
    cout << "������������ ��������: " << max << endl;
    va_end(arg); // ��������� ������ � �������� va_list

}

int main()
{
    setlocale(LC_ALL, "rus");
    // �������� ������� � ���������� ������ ����������
    mn(3, 1560, 5126, 124523);
    mn(4, 15236, 36436, 7124, 12235);
    mn(5, 23250, 2575, 175478, 214322, 6345);
}