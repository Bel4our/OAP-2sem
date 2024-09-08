#define _CRT_SECURE_NO_WARNINGS // ������ ��� ���������� �������������� �����������

#include <stdio.h> 
#include <iostream>
int main() 
{
    setlocale(LC_ALL, "rus");
    FILE* f1, * f2;
    errno_t err1, err2;
    err1 = fopen_s(&f1, "file.txt", "r"); // ��������� ���� ��� ������
    err2 = fopen_s(&f2, "file2.txt", "w"); // ������ ������ ���� ��� ������
    if (err1 != 0 || err2 != 0) // ���������, ��������� �� �����
    {
        perror("���������� ������� ����\n");
        return EXIT_FAILURE;
    }
    int n;
    fscanf(f1, "%d", &n); // ���������� ���������� �������� ���������� �������

    // ������ ��������� ������������ ������
    float** arr = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) 
    {
        arr[i] = (float*)malloc(n * sizeof(float));
    }
    //������ ���� ��� ������ ����� �� ����� � ������
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            fscanf(f1, "%f", &arr[i][j]); // ���������� ����� �� ����� � ������
            printf("%f ", arr[i][j]); // ������� � �������
        }
        printf("\n");
    }
    int k;
    printf("������� ����� ������ �� 1 �� %d: ", n); 
    // ������ ����� ������
    scanf("%d", &k);
    if (k < 1 || k >5) // ��������� ������������ ��������� �����
    {
        printf("�� ����� ������������ �������� ");
        return 0;
    }
    // ������ ���� ��� ������ k-�� ������ �������
    for (int j = 0; j < n; j++) 
    {
        fprintf(f2, "%f ", arr[k - 1][j]);  // ���������� ����� � ����
        printf("%f ", arr[k - 1][j]); // ������� ����� � �������
    }
    // ��������� �����
    fclose(f1);
    fclose(f2);
}
