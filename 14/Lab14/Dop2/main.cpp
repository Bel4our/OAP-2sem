#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TABLE_SIZE = 128;

class Node // ������ ������
{
public:
    string key;
    int value;
    Node* next;

    Node(const string& _key, int _value) : key(_key), value(_value), next(nullptr) {}
};

class HashTable  // ����� ���-�������
{
private:
    Node* table[TABLE_SIZE];

    int hash(const string& key) {
        int hashValue = 0;
        for (char c : key) {
            hashValue += static_cast<int>(c);
        }
        return hashValue % TABLE_SIZE;
    }

public:
    HashTable()  // ��������
    {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(const string& key, int value) { // �������
        int index = hash(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    int search(const string& key)  // �����
    {
        int index = hash(key);
        Node* current = table[index];
        while (current) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return 0;
    }

    void displayTable() //�����
    {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];
            cout << i << ": ";
            while (current) {
                cout << "(" << current->key << "," << current->value << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void removeWordsStartingWith(char letter)  // ��������
    {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];
            Node* prev = nullptr;
            while (current) {
                if (current->key[0] == letter) {
                    // ������� ������� ����
                    if (prev == nullptr) {
                        // �������� ����
                        table[i] = current->next;
                    }
                    else {
                        prev->next = current->next;
                    }
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
                else {
                    prev = current;
                    current = current->next;
                }
            }
        }
    }
};

int main() //�������
{
    setlocale(LC_ALL, "rus");

    HashTable hashTable;

    ifstream file("A.txt");
    if (!file.is_open()) {
        cout << "������ �������� �����!" << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        hashTable.insert(word, hashTable.search(word) + 1);
    }

    int choice;
    do {
        cout << "�������� ��������:" << endl;
        cout << "1. ������� ��� ���-�������" << endl;
        cout << "2. ����� �����" << endl;
        cout << "3. ������� �����, ������������ �� ��������� �����" << endl;
        cout << "4. �����" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            hashTable.displayTable();
            break;
        case 2: {
            string searchWord;
            cout << "������� ����� ��� ������: ";
            cin >> searchWord;
            int count = hashTable.search(searchWord);
            cout << "����� '" << searchWord << "' ����������� " << count << " ���" << endl;
            break;
        }
        case 3: {
            char letter;
            cout << "������� �����: ";
            cin >> letter;
            hashTable.removeWordsStartingWith(letter);
            cout << "�����, ������������ �� ����� '" << letter << "' �������" << endl;
            break;
        }
        case 4:
            cout << "����� �� ���������" << endl;
            break;
        default:
            cout << "������������ �����." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
