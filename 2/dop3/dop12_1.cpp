#define _CRT_SECURE_NO_WARNINGS // макрос для отключения предупреждений компилятора

#include <stdio.h> 
#include <iostream>
int main() 
{
    setlocale(LC_ALL, "rus");
    FILE* f1, * f2;
    errno_t err1, err2;
    err1 = fopen_s(&f1, "file.txt", "r"); // открываем файл для чтения
    err2 = fopen_s(&f2, "file2.txt", "w"); // создаём пустой файл для записи
    if (err1 != 0 || err2 != 0) // проверяем, открылись ли файлы
    {
        perror("Невозможно открыть файл\n");
        return EXIT_FAILURE;
    }
    int n;
    fscanf(f1, "%d", &n); // определяем количество столбцов квадратной матрицы

    // создаём двумерный динамический массив
    float** arr = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) 
    {
        arr[i] = (float*)malloc(n * sizeof(float));
    }
    //создаём цикл для записи чисел из файла в массив
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            fscanf(f1, "%f", &arr[i][j]); // записываем число из файла в массив
            printf("%f ", arr[i][j]); // выводим в консоль
        }
        printf("\n");
    }
    int k;
    printf("Введите номер строки от 1 до %d: ", n); 
    // вводим номер строки
    scanf("%d", &k);
    if (k < 1 || k >5) // проверяем корректность введённого числа
    {
        printf("Вы ввели неправильное значение ");
        return 0;
    }
    // создаём цикл для записи k-ой строки матрицы
    for (int j = 0; j < n; j++) 
    {
        fprintf(f2, "%f ", arr[k - 1][j]);  // записываем число в файл
        printf("%f ", arr[k - 1][j]); // выводим число в консоль
    }
    // закрываем файлы
    fclose(f1);
    fclose(f2);
}
