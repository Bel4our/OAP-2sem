#include <iostream>

using namespace std;

void bubbleSort(int a[], int n)
{
    int i, j, t;
    for (i = 1; i < n; i++)
        for (j = n - 1; j >= i; j--)
            if (a[j - 1] < a[j]) 
            {
                t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
}

void heapify(int A[], int pos, int n)
{
    int t, tm;
    while (2 * pos + 1 < n)
    {
        t = 2 * pos + 1;
        if (2 * pos + 2 < n && A[2 * pos + 2] < A[t])
            t = 2 * pos + 2;
        if (A[pos] > A[t]) 
        {
            tm = A[pos];
            A[pos] = A[t];
            A[t] = tm;
            pos = t;
        }
        else
            break;
    }
}

void piramSort(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, i, n);
    while (n > 0)
    {
        int tm = A[0];
        A[0] = A[n - 1];
        A[n - 1] = tm;
        n--;
        heapify(A, 0, n);
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int size;
    cout << "¬ведите размеры массивов: ";
    cin >> size;

    int* A = new int[size];
    int* B = new int[size];
    int* C = new int[size];
    int max = INT_MIN;

    //заполн€ем массивы 
    cout << "¬ведите элементы в массив ј: ";
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }
    cout << endl << "¬ведите элементы в массив B: ";
    for (int i = 0; i < size; i++)
    {
        cin >> B[i];
        if (max < B[i]) // ищем максимальный
            max = B[i];
    }

    int j = 0;

    for (int i = 0; i < size; i++)  // заполн€ем массив —
    {
        if (A[i] > max)
        {
            C[j] = A[i];
            j++;
        }
    }

    int* C1 = new int[j];

    for (int i = 0; i < j; i++) //дублируем массив дл€ второй сортировки
    {
        C1[i] = C[i];
    }

    for (int i = 0; i < j; i++) // выводим до сортировки пузырьком
    {
        cout << C[i] << " ";
    }
    cout << endl;

    bubbleSort(C, j); // сортируем пузырьком

    for (int i = 0; i < j; i++) // выводим после сортировки
    {
        cout << C[i] << " ";
    }
    cout << endl<<endl;

    for (int i = 0; i < j; i++) // выводим до сортировки
    {
        cout << C1[i] << " ";
    }
    cout << endl;

    piramSort(C1, j); // пирамидальна€ сортировка

    for (int i = 0; i < j; i++) // выводим после сортировки
    {
        cout << C1[i] << " ";
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] C;
    delete[] C1;

    return 0;
}
