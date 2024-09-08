#define _CRT_SECURE_NO_WARNINGS // макрос для отключения предупреждений компилятора

#include <stdio.h>
#include <iostream>
int main()
{
    setlocale(LC_ALL, "rus");
    errno_t err1, err2;
    FILE* f1, * f2;

    err1 = fopen_s(&f1, "f.txt", "r"); // открываем файл для чтения
    err2 = fopen_s(&f2, "g.txt", "w");  // создаём пустой файл для записи
    // проверяем, открылся ли файл
    if (err1 != 0)
    {
        perror("Невозможно открыть файл\n");
        return EXIT_FAILURE;
    }
    int x;
    int numb[1000]; // создаём массив для хранения наших цисел
    int i = 0;
    // вводим число 
    printf("Введите число x: "); 
    scanf("%d", &x); 
    while (fscanf(f1, "%d", &numb[i]) == 1) // записываем числыа из файла в массив
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        if (numb[j] > x) // проверяем, является ли число больше числа введённого с клавиатуры
        {
            fprintf(f2, "%d ", numb[j]); // записываем число в файл
            printf("%d ", numb[j]); // выводим число в консоль
        }

    }
    // закрываем файлы
    fclose(f1);
    fclose(f2);
}