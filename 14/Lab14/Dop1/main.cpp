#include <iostream>
#include <string>

using namespace std;

class Node  // ����� ��� ������
{
public:
    char key;
    int value;
    Node* next;

    Node(char _key, int _value) : key(_key), value(_value), next(nullptr) {}
};

class HashTable // ����� ���-�������
{
private:
    int size;
    Node** table;

    int hash(char key)  // ���-�������
    {
        return key % size;
    }

public:
    HashTable(int _size) : size(_size)  // ��������
    {
        table = new Node * [size];
        memset(table, 0, size * sizeof(Node*));
    }

    void insert(char key, int value)  // �������
    {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    int search(char key) // �����
    {
        int index = hash(key);
        Node* current = table[index];
        while (current)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    void displayTable()  // �����
    {
        for (int i = 0; i < size; i++)
        {
            Node* current = table[i];
            cout << i + 1 << ": ";
            while (current)
            {
                cout << "(" << current->key << "," << current->value << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() //������� �������
{
    setlocale(LC_ALL, "rus");
    string str;
    cout << "������� ������: ";
    getline(cin, str);

    HashTable hashTable(128); // ������ �������

    for (char letter : str)  // ������ ������
    {
        if (isalpha(letter))
        {
            hashTable.insert(letter, hashTable.search(letter) + 1);
        }
    }
    for (;;) // ����
    {
        int choice;
        cout << "�������� ��������:" << endl;
        cout << "1. ������� ��� ���-�������" << endl;
        cout << "2. ����� �����" << endl;
        cout << "3. �����" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            hashTable.displayTable();
            break;
        case 2: {
            char searchLetter;
            cout << "������� ����� ��� ������: ";
            cin >> searchLetter;

            int count = hashTable.search(searchLetter);
            if (count != -1) {
                cout << "����� '" << searchLetter << "' ����������� " << count + 1 << " ���" << endl;
            }
            else {
                cout << "����� '" << searchLetter << "' �� ������� � ������" << endl;
            }
            break;
        }
        case 3:
            return 0;
        default:
            cout << "������������ �����." << endl;
            break;
        }
    }
    return 0;
}
