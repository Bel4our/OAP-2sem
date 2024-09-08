#define _CRT_SECURE_NO_WARNINGS // макрос для отключения предупреждений компилятора

#include <stdio.h>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    errno_t err1, err2, err3, err4;
    FILE* f1, * f2, *f3, *f4;
    // открываем 3 файла для чтения
    err1 = fopen_s(&f1, "NameA.txt", "r"); 
    err2 = fopen_s(&f2, "NameB.txt", "r");
    err3 = fopen_s(&f3, "NameC.txt", "r");
    // создаём пустой файл для записи
    err4 = fopen_s(&f4, "NameD.txt", "w");
 
    if (err1 != 0) // проверяем, открылся ли файл
    {
        perror("Невозможно открыть файл\n");
        return EXIT_FAILURE;
    }
    // создаём 3 массив для хранения цифр из файлов
    int numb1[1000];
    int numb2[1000];
    int numb3[1000];
    int i = 0;
    while (fscanf(f1, "%d", &numb1[i]) == 1 && fscanf(f2, "%d", &numb2[i]) == 1 && fscanf(f3, "%d", &numb3[i]) == 1) // записываем числа в массивы
    {
        i++;
    }
  
    for (int j = 0; j < i; j++)
    {
        if (numb1[j] >= numb2[j] && numb1[j] >= numb3[j]) // если число из первого массива больше
        {
            fprintf(f4, "%d ", numb1[j]); // записываем его в файл
            printf("%d ", numb1[j]); // выводим в консоль
        }
        else // иначе
        {
            if (numb2[j] >= numb1[j] && numb2[j] >= numb3[j]) // если число из второго массива больше 
            {
                fprintf(f4, "%d ", numb2[j]); // записываем файл
                printf("%d ", numb2[j]); // выводим его
            }
            else // иначе
            {
                fprintf(f4, "%d ", numb3[j]); // записываем число из 3 массива в файл
                printf("%d ", numb3[j]); // выводим его
            }
        }
    }
    // закрываем все файлы
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}