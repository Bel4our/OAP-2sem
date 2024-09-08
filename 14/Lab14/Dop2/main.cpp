#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TABLE_SIZE = 128;

class Node // ячейка списка
{
public:
    string key;
    int value;
    Node* next;

    Node(const string& _key, int _value) : key(_key), value(_value), next(nullptr) {}
};

class HashTable  // класс хэш-таблицы
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
    HashTable()  // создание
    {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(const string& key, int value) { // вставка
        int index = hash(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    int search(const string& key)  // поиск
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

    void displayTable() //вывод
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

    void removeWordsStartingWith(char letter)  // удаление
    {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];
            Node* prev = nullptr;
            while (current) {
                if (current->key[0] == letter) {
                    // Удалить текущий узел
                    if (prev == nullptr) {
                        // Головной узел
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

int main() //главная
{
    setlocale(LC_ALL, "rus");

    HashTable hashTable;

    ifstream file("A.txt");
    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        hashTable.insert(word, hashTable.search(word) + 1);
    }

    int choice;
    do {
        cout << "Выберите действие:" << endl;
        cout << "1. Вывести всю хеш-таблицу" << endl;
        cout << "2. Поиск слова" << endl;
        cout << "3. Удалить слова, начинающиеся на указанную букву" << endl;
        cout << "4. Выход" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            hashTable.displayTable();
            break;
        case 2: {
            string searchWord;
            cout << "Введите слово для поиска: ";
            cin >> searchWord;
            int count = hashTable.search(searchWord);
            cout << "Слово '" << searchWord << "' встречается " << count << " раз" << endl;
            break;
        }
        case 3: {
            char letter;
            cout << "Введите букву: ";
            cin >> letter;
            hashTable.removeWordsStartingWith(letter);
            cout << "Слова, начинающиеся на букву '" << letter << "' удалены" << endl;
            break;
        }
        case 4:
            cout << "Выход из программы" << endl;
            break;
        default:
            cout << "Неправильный выбор." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
