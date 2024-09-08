#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TABLE_SIZE = 128;

class Node // ячейка списка
{
public:
    int key;
    int value;
    Node* next;

    Node(int _key, int _value) : key(_key), value(_value), next(nullptr) {}
};

class HashTable  // класс хэш-таблицы
{
private:
    Node* table[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable()  // создание
    {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(int key, int value) { // вставка
        int index = hash(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    int search(int key)  // поиск
    {
        int index = hash(key);
        Node* current = table[index];
        int comparisons = 0;
        int occurrences = 0;
        while (current) {
            ++comparisons;
            if (current->key == key) {
                ++occurrences;
            }
            current = current->next;
        }
        return occurrences > 0 ? comparisons : -1;
    }
};

int main() //главная
{
    setlocale(LC_ALL, "rus");
    HashTable hashTable;

    ifstream file("numbers.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int number;
    while (file >> number) {
        hashTable.insert(number, 1); 
    }

    int searchNumber;
    cout << "Введите число для поиска: ";
    cin >> searchNumber;
    int comparisons = hashTable.search(searchNumber);
    if (comparisons > 0) {
        cout << "Число " << searchNumber << " найдено. Количество сравнений: " << comparisons << endl;
    }
    else {
        cout << "Число " << searchNumber << " не найдено." << endl;
    }

    return 0;
}
