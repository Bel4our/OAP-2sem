#include <iostream>

using namespace std;

void shellSort(int arr[], int n) // функция сортировки
{
    
    for (int gap = n / 2; gap > 0; gap /= 2) {
      
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
      
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int arr[] = { 12, 45, 96, 32, 47, 5, 4, 213, 645, 32, 646, 23, 122, 4657, 235, 325, 32, 125, 66};
    int n = sizeof(arr) / 4;

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // вызов функции сортировки
    shellSort(arr, n);

    // вывод отсортированного массива
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
