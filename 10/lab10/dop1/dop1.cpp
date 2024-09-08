#include <iostream>
#include <fstream>

using namespace std;

void generateNumbers(int arr[], int n, int A, ofstream& file, int k = 0) // рекурсивная функция для генерации всех возможных чисел
{
    if (k == n) // елси достигнута нужная длина числа
    { 
        for (int i = 0; i < n; i++) // выводим число в файл
        { 
            file << arr[i];
        }
        file << endl;
    }
    else 
    {
        for (int i = 1; i <= A; i++)  // для каждой цифры от 1 до A
        { 
            arr[k] = i; // записываем цифру на текущую позицию
            generateNumbers(arr, n, A, file, k + 1); // Рекурсивно генерируем оставшиеся цифры
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int A; 
    cout << "Введите число A: ";
    cin >> A;
    int *arr = new int[A]; // Массив для хранения текущего числа
    ofstream file("A.txt"); 

    generateNumbers(arr, A, A, file); // Генерируем все возможные числа

    file.close(); // Закрываем файл
    return 0;
}
