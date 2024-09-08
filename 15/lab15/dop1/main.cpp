#include <iostream>

using namespace std;

void swap(int& a, int& b) // ������� ��� ������ �������
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n) // ������� ���������� 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        // ����� ����������
        swap(arr[i], arr[minIndex]);
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int arr[] = { 123, 2565, 1672, 3422, 611, 76, 34, 67, 23457, 547345, 5574, 235, 4 };
    int n = sizeof(arr) / 4;

    cout << "�������� ������: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ����� ������� ����������
    selectionSort(arr, n);

    // ����� ���������������� �������
    cout << "��������������� ������: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
