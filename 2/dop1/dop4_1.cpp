#define _CRT_SECURE_NO_WARNINGS // ������ ��� ���������� �������������� �����������

#include <stdio.h>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "rus");
    errno_t err1, err2;
    FILE* f1, *f2;
    err1 = fopen_s(&f1, "fileA.txt", "r"); // ��������� ���� ��� ������
    err2 = fopen_s(&f2, "fileB.txt", "w"); // ������ ������ ���� ��� ������
    // ���������, �������� �� ����
    if (err1 != 0)
    {
        perror("���������� ������� ����\n");
        return EXIT_FAILURE;
    }
    int numb[1000]; // ������ ������ ��� �������� �����
    int i = 0;
    // ������ ���� ��� ������ ����� �� ����� � ������
    while (fscanf(f1, "%d", &numb[i]) == 1)
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        if (numb[j]>0) // ���������, ��������� � ����� �������������
        {
            fprintf(f2, "%d ", numb[j]); // ���������� ����� � ����
            printf("%d ", numb[j]); // ������� ����� � �������
        }

    }
    // ��������� �����
    fclose(f1);
    fclose(f2);
}