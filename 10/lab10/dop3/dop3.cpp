#include <iostream>
using namespace std;

void swap(int& a, int& b) // ������ ������� ��������
{
    int temp = a;
    a = b;
    b = temp;
}

void perestanovka(int nums[], int st, int en) //����������� ������� ��� ������
{
    if (st == en) //���� ����� �� ����� �������
    {
        for (int i = 0; i <= en; i++)  //������� ������
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    else //�����
    {
        for (int i = st; i <= en; i++)  //���� �� ����� �� ����� �������
        {
            swap(nums[st], nums[i]); //������ �������
            perestanovka(nums, st + 1, en); //���������� �������� ������� ��� ��������� ������������ ����������
            swap(nums[st], nums[i]); // ���������� �� ����� �������� �������
        }
    }
}

int main()
{
    int n = 5;
    int numbers[] = { 1, 2, 3, 4, 5 };
    perestanovka(numbers, 0, n - 1); //�������� �������
    return 0;
}
