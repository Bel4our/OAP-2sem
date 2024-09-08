#include <iostream>

using namespace std;

struct Queue
{
	int info;
	Queue* next;
};

void create(Queue** begin, Queue** end, int p); // ������� ���������� �������� � �������
void view(Queue* begin); // ������� ������
int fromFIFO(Queue** begin); // ������� ����������
void twoqueue(Queue** begin, Queue** end, Queue** begin1, Queue** end1, Queue** begin2, Queue** end2); //������� ��������� 1 ������� �� 2
void view2(Queue* begin1, Queue* begin2); //������� ������ 2 ��������

int main()
{
	setlocale(LC_ALL, "rus");
	int choice;
	//��������� �� ������ ������ �������
	Queue* begin = NULL, * end;
	Queue* begin1 = NULL, * end1;
	Queue* begin2 = NULL, * end2;
	int size;
	do
	{
		cout << "1 - ���������� ��������� � �������" << endl;
		cout << "2 - ���������� �������� �� �������" << endl;
		cout << "3 - ����� �������" << endl;
		cout << "4 - ������� ���������" << endl;
		cout << "5 - ������� ������ ����� ��������" << endl;
		cout << "6 - �����" << endl;
		cin >> choice;
		//����������� choice
		switch (choice)
		{
		case 1:
			int p;
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
				twoqueue(&begin, &end, &begin1, &end1, &begin2, &end2);
			break;
		case 5:
			cout << "������ �������: ";
			view(begin1);
			cout << "������ �������: ";
			view(begin2);
			break;
		}
	} while (choice != 6);
	return 0;
}

void create(Queue** begin, Queue** end, int p) //������������ ��������� �������
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

int fromFIFO(Queue** begin) // ���������� �������� �� �������
{
	Queue* t = *begin;
	int val = t->info;
	*begin = t->next;
	delete t;
	return val;
}
void twoqueue(Queue** begin, Queue** end, Queue** begin1, Queue** end1, Queue** begin2, Queue** end2) // ������� ��������� �������
{
    while (*begin != nullptr)
    {
        Queue* t = *begin;
        Queue* prev = nullptr;
        Queue* minNode = nullptr;
        Queue* maxNode = nullptr;
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        // ������� ����������� ������� � �������
        while (t != nullptr)
        {
            if (t->info < minVal)
            {
                minVal = t->info;
                minNode = t;
            }
            t = t->next;
        }

        // �������� ����������� ������� � Queue1
        if (minNode != nullptr)
        {
            create(begin1, end1, minNode->info);

            // ������� ����������� ������� �� �������
            if (*begin == minNode)
            {
                *begin = minNode->next;
            }
            else
            {
                prev = *begin;
                while (prev->next != minNode)
                {
                    prev = prev->next;
                }
                prev->next = minNode->next;
            }

            // ����������� ����
            delete minNode;
        }

        // ���������, ������� �� ������ �������
        if (*begin == nullptr)
            break;

        // ������� ������������ ������� � �������
        t = *begin;
        while (t != nullptr)
        {
            if (t->info > maxVal)
            {
                maxVal = t->info;
                maxNode = t;
            }
            t = t->next;
        }

        // �������� ������������ ������� � Queue2
        if (maxNode != nullptr)
        {
            create(begin2, end2, maxNode->info);

            // ������� ������������ ������� �� �������
            if (*begin == maxNode)
            {
                *begin = maxNode->next;
            }
            else
            {
                prev = *begin;
                while (prev->next != maxNode)
                {
                    prev = prev->next;
                }
                prev->next = maxNode->next;
            }

            // ����������� ����
            delete maxNode;
        }
    }
}
