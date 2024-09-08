#include <iostream>

using namespace std;

struct Queue
{
	double info;
	Queue* next;
};

void create(Queue** begin, Queue** end, double p); // ������� ���������� �������� � �������
void view(Queue* begin); // ������� ������
double fromFIFO(Queue** begin); // ������� ����������
void cycle(Queue** begin, Queue** end); //������� ������������ ������

int main()
{
	setlocale(LC_ALL, "rus");
	int choice;
	//��������� �� ������ ������ �������
	Queue* begin = NULL, * end;
	int size;
	do
	{
		cout << "1 - ���������� ��������� � �������" << endl;
		cout << "2 - ���������� �������� �� �������" << endl;
		cout << "3 - ����� �������" << endl;
		cout << "4 - ������� ������������ ������" << endl;
		cout << "5 - �����" << endl;
		cin >> choice;
		//����������� choice
		switch (choice)
		{
		case 1:
			double p;
			cout << "������� ������ �������: ";  cin >> size;
			for (int i = 0; i < size; i++)
			{
				cout << "������� �������: ";    cin >> p;
				create(&begin, &end, p);
			}
			break;
		case 2:
			if (begin == NULL)
				cout << "������� �����" << endl;
			else
				cout << "����������� �������: " << fromFIFO(&begin) << endl;
			break;
		case 3:
			if (begin == NULL)   //����� �� �����
				cout << "No elements" << endl;
			else
				view(begin);
			break;
		case 4:
			if (begin == NULL)
				cout << "������� �����" << endl;
			else
				cycle(&begin, &end);
			break;
		}
	} while (choice != 5);
	return 0;
}

void create(Queue** begin, Queue** end, double p) //������������ ��������� �������
{
	Queue* t = new Queue;
	t->info = p;
	t->next = NULL;
	if (*begin == NULL)
		*begin = *end = t;
	else
	{
		(*end)->next = t;
		*end = t;
	}
}

void view(Queue* begin) //����� ��������� ������� 
{
	Queue* t = begin;
	while (t != NULL)
	{
		cout << t->info << " ";
		t = t->next;
	}
	cout << endl;
}

double fromFIFO(Queue** begin) // ���������� �������� �� �������
{
	Queue* t = *begin;
	double val = t->info;
	*begin = t->next;
	delete t;
	return val;
}

void cycle(Queue** begin, Queue** end) // ������� ������������ ������
{
	Queue* t = *begin;
	Queue* MAX = NULL;

	int max = -DBL_MIN;
	while (t != NULL)
	{ 
		//���� ������������ �������
		if (max < t->info)
		{
			max = t->info;
			MAX = t;
		}
		t = t->next;
	}
	if (MAX != nullptr)
	{
		// ���������� ������������ ������� � ������ �������
		while (*begin != MAX)
		{
			double element = fromFIFO(begin);
			create(begin, end, element);
		}
	}
}