#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	// ��������� 2 ����� ��� ������
	ofstream file1("FILE1.txt"); 
	ofstream file2("FILE2.txt");
	
	char str[1000]; // ���������� ��� �������� ������
	cout << "������� ������: ";
	gets_s(str); // ������ ������
	if (file1.is_open()) // ���� ���� ��������
	{
		file1 << str; // ���������� � ���� ������
		file1.close(); // ��������� ����
	}
	else // ����� ������� ������
	{
		cout << "�� ������� ������� ���� ��� ������.";
		return 1;
	}
	//��������� ���� ��� ������
	ifstream file3("FILE1.txt");
	if (file3.fail()) // �������� �� �������� �����
	{
		cout << "\n ������ �������� FILE1.txt";
		return 1;
	}
	char word[100];  // ���������� ��� �������� �����
	while (file3 >> word) // ���� ��� ������ ���� �� �����
	{
		int i = 0;
		if (!(word[i]>='0' && word[i]<='9')) // ���� word �� �������� ����� ������ ������ ����
		{
			file2 << word << '\n'; // ������� ���������� � ����
			cout << word << " "; // ������� � �������
		}
	}
	//��������� �����
	file2.close();
	file3.close();
	return 0;
}