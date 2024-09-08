#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TABLE_SIZE = 128;

class Node // ������ ������
{
public:
    int key;
    int value;
    Node* next;

    Node(int _key, int _value) : key(_key), value(_value), next(nullptr) {}
};

class HashTable  // ����� ���-�������
{
private:
    Node* table[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable()  // ��������
    {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(int key, int value) { // �������
        int index = hash(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    int search(int key)  // �����
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

int main() //�������
{
    setlocale(LC_ALL, "rus");
    HashTable hashTable;

    ifstream file("numbers.txt");
    if (!file.is_open()) {
        cout << "������ �������� �����!" << endl;
        return 1;
    }

    int number;
    while (file >> number) {
        hashTable.insert(number, 1); 
    }

    int searchNumber;
    cout << "������� ����� ��� ������: ";
    cin >> searchNumber;
    int comparisons = hashTable.search(searchNumber);
    if (comparisons > 0) {
        cout << "����� " << searchNumber << " �������. ���������� ���������: " << comparisons << endl;
    }
    else {
        cout << "����� " << searchNumber << " �� �������." << endl;
    }

    return 0;
}
