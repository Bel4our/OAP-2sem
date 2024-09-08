#include <iostream>
#include <fstream>

using namespace std;

void generateNumbers(int arr[], int n, int A, ofstream& file, int k = 0) // ����������� ������� ��� ��������� ���� ��������� �����
{
    if (k == n) // ���� ���������� ������ ����� �����
    { 
        for (int i = 0; i < n; i++) // ������� ����� � ����
        { 
            file << arr[i];
        }
        file << endl;
    }
    else 
    {
        for (int i = 1; i <= A; i++)  // ��� ������ ����� �� 1 �� A
        { 
            arr[k] = i; // ���������� ����� �� ������� �������
            generateNumbers(arr, n, A, file, k + 1); // ���������� ���������� ���������� �����
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int A; 
    cout << "������� ����� A: ";
    cin >> A;
    int *arr = new int[A]; // ������ ��� �������� �������� �����
    ofstream file("A.txt"); 

    generateNumbers(arr, A, A, file); // ���������� ��� ��������� �����

    file.close(); // ��������� ����
    return 0;
}
