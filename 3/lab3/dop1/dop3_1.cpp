#include <iostream>
#include <fstream>

using namespace std;

bool isVow(char* symbol) // ������� ��� �������� ������� ����
{
	char s = *symbol;
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') // ���� ����� �������
	{
		return true; // ���������� true
	}
	else
	{
		return false; // ����� false
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
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

	int k; 
	char str[1000]; // ���������� ��� �������� ������
	cout << "������� k �� 1 �� 6: "; cin >> k; // ������ K
	if (k > 6 || k<1) // ��� ��� � ����� 9 ����� ������ ����� �������
	{
		cout << "�� ����� ������������ ��������! ";
		return 1;
	}

	int nk = k + 3; // ���������� ������� ������ �� ����� ������ �� ����� ��������
	int count = 1; // ������� �����
	while (file1.getline(str, 1000)) // ���� ��� ������ ����� �� �����
	{
		if (count >= k && count<=nk) // ���� ����������� �������
		{
			file2 << str<<"\n"; // ���������� ������ � ����
		}
		count++; // ����������� �������
	}
	// ��������� �����
	file1.close();
	file2.close();

	ifstream file3("FILE2.txt"); // ��������� ���� ��� ������
	if (file3.fail()) // �������� �� �������� �����
	{
		cout << "\n ������ �������� FILE2.txt";
		return 1;
	}
	count = 0; // �������� ������� ��� ����������� ������������� ��� �������� ������� ����
	while (file3.getline(str, 1000)) // ���� ��� ������ ����� �� �����
	{
		for (int i = 0; str[i] != '\0';i++) // ����� �� ������ 
		{
			if (isVow(&str[i])) // ������� ������� � ���� ������� ����������� 
			{
				count++; // �� ����������� ��������
			}
		}
	
	}
	cout << "���������� �������: " << count; // ������� ���������� � �������

	file3.close(); // ��������� ����
	return 0;
}