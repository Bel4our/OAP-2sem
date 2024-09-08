#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) // функция сортировки
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int arr[] = { 6, 4, 25, 52, 7, 132, 6, 34, 76, 34, 76, 3473, 7457, 23, 46, 23, 4, 6 };
    int n = sizeof(arr) / 4;

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // вызов функции сортировки
    insertionSort(arr, n);
    // вывод отсортированного массива
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
