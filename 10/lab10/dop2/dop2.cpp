#include <iostream>

const int MAX = 100;

using namespace std;


bool isSafe(int country, int graph[MAX][MAX], int group[], int currentGroup, int N) // ��������� ����� �� �������� ������ � ������
{
    for (int i = 0; i < N; ++i) {
        if (graph[country][i] && group[i] == currentGroup)
            return false;
    }
    return true;
}

bool partitionUtil(int graph[MAX][MAX], int group[], int country, int N) // ����������� ������� ��� ��������� ����� �� ��� ������
{
   
    if (country == N) // ���� ��� ������ ��������� �� ������, ���������� true
        return true;
    //������� �������� � ���� ������
    group[country] = 1;
    if (isSafe(country, graph, group, 1, N) && partitionUtil(graph, group, country + 1, N))
        return true;

    // ���� �� �������, ��������� �������� �� ������
    group[country] = 0;
    if (isSafe(country, graph, group, 0, N) && partitionUtil(graph, group, country + 1, N))
        return true;

    // ���� �� � ���� ������ �������� �� �������, ���������� false
    return false;
}


void partition(int graph[MAX][MAX], int N)  // ������� ��� ��������� ����� �� ��� ������
{
    int group[MAX] = { 0 };

    if (!partitionUtil(graph, group, 0, N)) 
    {
        cout << "���������� ������� ������ �� ��� ������" << endl;
        return;
    }

    cout << "������ 1: ";
    for (int i = 0; i < N; ++i) {
        if (group[i] == 1)
            cout << i << " ";
    }
    cout << endl;

    cout << "������ 2: ";
    for (int i = 0; i < N; ++i) {
        if (group[i] == 0)
            cout << i << " ";
    }
    cout << endl;
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int graph[MAX][MAX] = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}
    };
    int N = 4; // ���������� �����

    partition(graph, N);

    return 0;
}
