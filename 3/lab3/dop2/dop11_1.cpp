#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream file1("FILE1.txt"); // ��������� ���� ��� ������
	ofstream file2("FILE2.txt"); // ��������� ���� ��� ������
	if (file1.fail()) // �������� �� �������� �����
	{
		cout << "\n ������ �������� FILE1.txt";
		return 1;
	}
	if (file2.fail()) // �������� �� �������� �����
	{
		cout << "\n ������ �������� FILE2.txt";
		return 1;
	}
	char str[1000]; // ���������� ������� ������ ������
	while (file1.getline(str, 1000)) // ���� ��� ������ ����� �� �����
	{
		int count = 0; // ���������� ��� �������� ���������� ��������
		for (int i = 0;i < strlen(str);i++) // ���� ��� ������� �� ���� ������
		{
			if (str[i] == ' ') // ���� ����� ������
			{
				count++; // ���������� ��������
			}
		}
		if (count == 0) // ���� �������� ���, ������ ������ ������� �� ������ �����
		{
			file2 << str << '\n'; // ���������� � � ����
		}
	}
	// ��������� �����
	file1.close();
	file2.close();

	ifstream file3("FILE2.txt"); //��������� ���� ��� ������
	if (file3.fail()) // �������� �� �������� �����
	{
		cout << "\n ������ �������� FILE2.txt";
		return 1;
	}
	int count = 0; // ���������� ��� �������� ��������
	while (file3.getline(str, 1000)) // ���� ��� ������ �����
	{
		count += strlen(str); // ������� ���������� ��������
	}
	cout << "���������� ��������: " << count; // ������� � �������
	// ��������� ����
	file3.close();
	return 0;
}
