#define _CRT_SECURE_NO_WARNINGS // макрос для отключения предупреждений компилятора

#include <stdio.h> 
#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    errno_t err;
    FILE* f;
    err = fopen_s(&f, "fileA.txt", "r"); // открываем файл для чтения
    if (err != 0) // проверяем, открылся ли файл
    {
        perror("Невозможно открыть файл\n");
        return EXIT_FAILURE;
    }
    float arifm; // создаём переменную для хранения среднего арифмитического
    int numb[100]; // создаём массив для хранения чисел
    int x;
    printf("Введите число x: "); 
    scanf("%d", &x); // вводим число х
    int i = 0;
    // цикл для записи чисел из файла 
    while (fscanf(f, "%d", &numb[i]) == 1) 
    {
        i++;
    }
    // цикл для вывода наших чисел
    for (int j = 0; j < i; j++) 
    {
        printf("%d ", numb[j]);
    }
    int fnumb, snumb; // создаём переменные для хранения чисел
    float val; // создаём переменную для хранения ближайшего значения среднего арфметического к х
    arifm = (numb[0] + numb[1])/2; //считаем первое среднее арифметическое
    val = abs(arifm - x); // находим ближайшее значение
    // создаём двойной цикл для проверки чисел
    for (int j = 0;j < i;j++)
    {
        for (int k = j + 1;k < i;k++)
        {
            arifm = (numb[j] + numb[k]) / 2; //находим среднее арифметическое

            if (abs(arifm - x) <= val) // условие для поиска более подходящих чисел
            {
                //присваиваем переменным новые значения
                val = abs(arifm-x); 
                fnumb = numb[j];
                snumb = numb[k];
            }
        }
    }
    printf("\nЧисла: %d, %d", fnumb, snumb); // выводим наши числа
    fclose(f); // закрываем файл
}
