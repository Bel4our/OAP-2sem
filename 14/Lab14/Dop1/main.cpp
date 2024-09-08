#include <iostream>
#include <string>

using namespace std;

class Node  // класс для списка
{
public:
    char key;
    int value;
    Node* next;

    Node(char _key, int _value) : key(_key), value(_value), next(nullptr) {}
};

class HashTable // класс хэш-таблицы
{
private:
    int size;
    Node** table;

    int hash(char key)  // хэш-функция
    {
        return key % size;
    }

public:
    HashTable(int _size) : size(_size)  // создание
    {
        table = new Node * [size];
        memset(table, 0, size * sizeof(Node*));
    }

    void insert(char key, int value)  // вставка
    {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    int search(char key) // поиск
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

    void displayTable()  // вывод
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

int main() //главная функция
{
    setlocale(LC_ALL, "rus");
    string str;
    cout << "Введите строку: ";
    getline(cin, str);

    HashTable hashTable(128); // создаём таблицу

    for (char letter : str)  // вводим строку
    {
        if (isalpha(letter))
        {
            hashTable.insert(letter, hashTable.search(letter) + 1);
        }
    }
    for (;;) // меню
    {
        int choice;
        cout << "Выберите действие:" << endl;
        cout << "1. Вывести всю хеш-таблицу" << endl;
        cout << "2. Поиск буквы" << endl;
        cout << "3. Выход" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            hashTable.displayTable();
            break;
        case 2: {
            char searchLetter;
            cout << "Введите букву для поиска: ";
            cin >> searchLetter;

            int count = hashTable.search(searchLetter);
            if (count != -1) {
                cout << "Буква '" << searchLetter << "' встречается " << count + 1 << " раз" << endl;
            }
            else {
                cout << "Буква '" << searchLetter << "' не найдена в строке" << endl;
            }
            break;
        }
        case 3:
            return 0;
        default:
            cout << "Неправильный выбор." << endl;
            break;
        }
    }
    return 0;
}
