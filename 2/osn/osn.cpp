#define _CRT_SECURE_NO_WARNINGS // ������ ��� ���������� �������������� �����������

#include <stdio.h> 
#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");

    errno_t err;
    FILE* f;
    err = fopen_s(&f, "fileA.txt", "r"); // ��������� ���� ��� ������
    if (err != 0) // ���������, �������� �� ����
    {
        perror("���������� ������� ����\n");
        return EXIT_FAILURE;
    }
    float arifm; // ������ ���������� ��� �������� �������� ���������������
    int numb[100]; // ������ ������ ��� �������� �����
    int x;
    printf("������� ����� x: "); 
    scanf("%d", &x); // ������ ����� �
    int i = 0;
    // ���� ��� ������ ����� �� ����� 
    while (fscanf(f, "%d", &numb[i]) == 1) 
    {
        i++;
    }
    // ���� ��� ������ ����� �����
    for (int j = 0; j < i; j++) 
    {
        printf("%d ", numb[j]);
    }
    int fnumb, snumb; // ������ ���������� ��� �������� �����
    float val; // ������ ���������� ��� �������� ���������� �������� �������� �������������� � �
    arifm = (numb[0] + numb[1])/2; //������� ������ ������� ��������������
    val = abs(arifm - x); // ������� ��������� ��������
    // ������ ������� ���� ��� �������� �����
    for (int j = 0;j < i;j++)
    {
        for (int k = j + 1;k < i;k++)
        {
            arifm = (numb[j] + numb[k]) / 2; //������� ������� ��������������

            if (abs(arifm - x) <= val) // ������� ��� ������ ����� ���������� �����
            {
                //����������� ���������� ����� ��������
                val = abs(arifm-x); 
                fnumb = numb[j];
                snumb = numb[k];
            }
        }
    }
    printf("\n�����: %d, %d", fnumb, snumb); // ������� ���� �����
    fclose(f); // ��������� ����
}
