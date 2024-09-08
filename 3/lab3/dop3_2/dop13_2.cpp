#include <iostream>
#include <fstream>

using namespace std;

bool isBracket(char* str) // ������� ��� ������ ������
{
	char c = *str;
	if ( c == '('|| c == ')' || c=='['|| c == ']' || c == '{' || c == '}') // ���� ������� ������ ������
	{
		return true; // ���������� true
	}
	else
	{
		return false; // ����� ���������� false
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	ofstream file1("FILE1.txt"); // ��������� ���� ��� ������
	if (file1.fail()) // �������� �� �������� �����
	{
		cout << "\n ������ �������� ����� FILE1.txt";
		return 1;
	}
	char str[1000]; // ���������� ��� �������� ������
	cout << "������� ������: ";
	gets_s(str); // ������ ������
	file1 << str; // ���������� � ����
	file1.close(); // ��������� ����
	ifstream file2("FILE1.txt"); // ��������� ���� ��� ������
	if (file2.fail()) // �������� �� �������� �����
	{
		cout << "\n ������ �������� ����� FILE1.txt";
		return 1;
	}
	char newstr[1000]; // ���������� ��� �������� ����� ������
	file2.getline(newstr, 1000); // ���������� ������ �� �����
	int count=0; // ������� ������
	for (int i = 0; i < strlen(newstr);i++) // ����� �� ������
	{
		if (isBracket(&newstr[i])) // ���� ������
		{
			count++; // ����������� ��������
		}
	}
	cout << "���������� ������: " << count; // ������� ��������
	file2.close(); // ��������� ����
}