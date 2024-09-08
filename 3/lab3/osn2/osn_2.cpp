#include <iostream>
#include <fstream> // ��� ������ � �������
#include <string> // ��� ������ �� ��������

using namespace std;

bool containsP(const string& word) // ������� ��� ������ P � �����
{
    for(int i = 0; i < word.length(); i++) // ����� �� �����
    {
        if (word[i]== 'p' || word[i] == 'P') //���� ���� P 
        {
            return true; // �� ���������� true
        }
    }
    return false;// ���� ������ ��� P ���������� false
}

int main()
{
    setlocale(LC_ALL, "rus");

    string str;
    cout << "������� ������: ";
    getline(cin, str); // ������ ������
    cout << endl; // ������� �� ����� ������ � �������
    ofstream file("FILE.txt"); // ��������� ���� ��� ������
    if (file.is_open()) // �������� �� ��������
    {
        file << str; // ���������� ������ � ����
        file.close(); // ��������� ����
    }
    else // ����� ������� ������
    {
        cout << "�� ������� ������� ���� ��� ������.";
        return 1;
    }

    ifstream file1("FILE.txt"); // ��������� ���� ��� ������
    string word; // ���������� ��� �������� �������� �����
    if (file1.is_open()) // ���� ���� ������
    {
        while (file1 >> word) //���� ������� ���������� � word ����� �� �������, ���� �� ����� �� ����� �����
        {
            if (containsP(word)) // �������� ������� � ���� ������� �����������
            {
                cout << word << " "; // ������� �����
            }
        }
        file1.close(); // ��������� ����
    }
    else // ����� ������� ������
    {
        cout << "�� ������� ������� ���� ��� ������.";
        return 1;
    }

    return 0;
}
