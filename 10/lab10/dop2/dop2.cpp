#include <iostream>

const int MAX = 100;

using namespace std;


bool isSafe(int country, int graph[MAX][MAX], int group[], int currentGroup, int N) // проверяем можно ли добавить страну в группу
{
    for (int i = 0; i < N; ++i) {
        if (graph[country][i] && group[i] == currentGroup)
            return false;
    }
    return true;
}

bool partitionUtil(int graph[MAX][MAX], int group[], int country, int N) // Рекурсивная функция для разбиения стран на две группы
{
   
    if (country == N) // Если все страны разделены на группы, возвращаем true
        return true;
    //пробуем добавить в одну группу
    group[country] = 1;
    if (isSafe(country, graph, group, 1, N) && partitionUtil(graph, group, country + 1, N))
        return true;

    // Если не удалось, попробуем добавить во вторую
    group[country] = 0;
    if (isSafe(country, graph, group, 0, N) && partitionUtil(graph, group, country + 1, N))
        return true;

    // Если ни в одну группу добавить не удалось, возвращаем false
    return false;
}


void partition(int graph[MAX][MAX], int N)  // Функция для разбиения стран на две группы
{
    int group[MAX] = { 0 };

    if (!partitionUtil(graph, group, 0, N)) 
    {
        cout << "Невозможно разбить страны на две группы" << endl;
        return;
    }

    cout << "Группа 1: ";
    for (int i = 0; i < N; ++i) {
        if (group[i] == 1)
            cout << i << " ";
    }
    cout << endl;

    cout << "Группа 2: ";
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
    int N = 4; // Количество стран

    partition(graph, N);

    return 0;
}
