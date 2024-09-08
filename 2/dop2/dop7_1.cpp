#define _CRT_SECURE_NO_WARNINGS // ������ ��� ���������� �������������� �����������

#include <stdio.h>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    errno_t err1, err2, err3, err4;
    FILE* f1, * f2, *f3, *f4;
    // ��������� 3 ����� ��� ������
    err1 = fopen_s(&f1, "NameA.txt", "r"); 
    err2 = fopen_s(&f2, "NameB.txt", "r");
    err3 = fopen_s(&f3, "NameC.txt", "r");
    // ������ ������ ���� ��� ������
    err4 = fopen_s(&f4, "NameD.txt", "w");
 
    if (err1 != 0) // ���������, �������� �� ����
    {
        perror("���������� ������� ����\n");
        return EXIT_FAILURE;
    }
    // ������ 3 ������ ��� �������� ���� �� ������
    int numb1[1000];
    int numb2[1000];
    int numb3[1000];
    int i = 0;
    while (fscanf(f1, "%d", &numb1[i]) == 1 && fscanf(f2, "%d", &numb2[i]) == 1 && fscanf(f3, "%d", &numb3[i]) == 1) // ���������� ����� � �������
    {
        i++;
    }
  
    for (int j = 0; j < i; j++)
    {
        if (numb1[j] >= numb2[j] && numb1[j] >= numb3[j]) // ���� ����� �� ������� ������� ������
        {
            fprintf(f4, "%d ", numb1[j]); // ���������� ��� � ����
            printf("%d ", numb1[j]); // ������� � �������
        }
        else // �����
        {
            if (numb2[j] >= numb1[j] && numb2[j] >= numb3[j]) // ���� ����� �� ������� ������� ������ 
            {
                fprintf(f4, "%d ", numb2[j]); // ���������� ����
                printf("%d ", numb2[j]); // ������� ���
            }
            else // �����
            {
                fprintf(f4, "%d ", numb3[j]); // ���������� ����� �� 3 ������� � ����
                printf("%d ", numb3[j]); // ������� ���
            }
        }
    }
    // ��������� ��� �����
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}