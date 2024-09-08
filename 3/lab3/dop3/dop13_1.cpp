#include <iostream>
#include <fstream>

using namespace std;

bool isVow(char* symbol) //������� ��� �������� �� �������
{
	char s = *symbol;
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') // ���� ������ �������
	{
		return true; // ���������� true
	}
	else
	{
		return false; // ����� ���������� false
	}
}

int findNumb(char* str) // ������� ������� ���������� ����� ������� �����
{
	int count = 0; // ���������� ��� �������� ���������� ������� � ������ �����
	int nowcount = 0; // ���������� ��� �������� ���������� ������� � ������� �����
	int bufnumbword = 0; // ���������� ��� �������� ���� ����
	int numbword = 0; // ���������� ��� �������� ������ ������� �����
	for (int i = 0;i < strlen(str);i++) // ����� �� ������
	{
		if (isVow(&str[i])) // ���� �������
		{
			nowcount++; // ����������� ��������
		}
		if (str[i] == ' ' || str[i + 1] == '\0') // ���� ����� �����������
		{
			bufnumbword++; //���������� ��������
			if (count < nowcount) // ���� � ������� ����� ������� ������, �� 
			{
				//��������� ��������
				count = nowcount;
				numbword = bufnumbword;
				
			}
			nowcount = 0;  // �������� ��������
		}
	}
	return numbword; // ���������� ����� �����
}


int main()
{
	setlocale(LC_ALL, "rus");
	ifstream file1("FILE1.txt"); // ��������� ���� ��� ������ 
	ofstream file2("FILE2.txt"); // ��������� ���� ��� ������
	char line[1000]; // ���������� ��� �������� ������
	int count = 0; // ������� ��������
	if (file1.fail()) // �������� �� �������� �����
	{
		cout << "\n ������ �������� ����� FILE1.txt";
		return 1;
	}
	if (file2.fail()) // �������� �� �������� �����
	{
		cout << "\n ������ �������� ����� FILE2.txt";
		return 1;
	}
	while (file1.getline(line, 1000)) // ���� ��� ������ ����� �� ����
	{
		for (int i = 0; i < strlen(line);i++) // ����� �� ������
		{
			if (line[i] == ' ') // ���� ���������� �� ������
			{
				count++; // ����������� ��������
			}
		}

		if (count > 1) // ���� �������� ������ 1, ������ ���� ������ ��� ���
		{
			file2 << line<< '\n'; // ������� ���������� � ����
			int numb = findNumb(line); // �������� ������� ��� ������ ������ ����� � ����������� � �������� numb
			cout << "����� �����: " << numb << endl; // ������� ����� �����
		}
		count = 0; // �������� �������
	}
	// ��������� �����
	file1.close();
	file2.close();
}