#include <iostream>

using namespace std;

struct Queue
{
	double info;
	Queue* next;
};

void create(Queue** begin, Queue** end, double p); // фнукция добавления элемента в очередь
void view(Queue* begin); // функция вывода
double fromFIFO(Queue** begin); // функция извлечения
void cycle(Queue** begin, Queue** end); //функция циклического сдвига

int main()
{
	setlocale(LC_ALL, "rus");
	int choice;
	//указатели на начало каждой очереди
	Queue* begin = NULL, * end;
	int size;
	do
	{
		cout << "1 - Добавление элементов в очередь" << endl;
		cout << "2 - Извлечение элемента из очереди" << endl;
		cout << "3 - Вывод очереди" << endl;
		cout << "4 - Функция циклического сдвига" << endl;
		cout << "5 - Выход" << endl;
		cin >> choice;
		//анализируем choice
		switch (choice)
		{
		case 1:
			double p;
			cout << "Введите размер очереди: ";  cin >> size;
			for (int i = 0; i < size; i++)
			{
				cout << "Введите элемент: ";    cin >> p;
				create(&begin, &end, p);
			}
			break;
		case 2:
			if (begin == NULL)
				cout << "Очередь пуста" << endl;
			else
				cout << "Извлеченный элемент: " << fromFIFO(&begin) << endl;
			break;
		case 3:
			if (begin == NULL)   //вывод на экран
				cout << "No elements" << endl;
			else
				view(begin);
			break;
		case 4:
			if (begin == NULL)
				cout << "Очередь пуста" << endl;
			else
				cycle(&begin, &end);
			break;
		}
	} while (choice != 5);
	return 0;
}

void create(Queue** begin, Queue** end, double p) //Формирование элементов очереди
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

void view(Queue* begin) //Вывод элементов очереди 
{
	Queue* t = begin;
	while (t != NULL)
	{
		cout << t->info << " ";
		t = t->next;
	}
	cout << endl;
}

double fromFIFO(Queue** begin) // Извлечение элемента из очереди
{
	Queue* t = *begin;
	double val = t->info;
	*begin = t->next;
	delete t;
	return val;
}

void cycle(Queue** begin, Queue** end) // функция циклического сдвига
{
	Queue* t = *begin;
	Queue* MAX = NULL;

	int max = -DBL_MIN;
	while (t != NULL)
	{ 
		//ищем макисмальный элемент
		if (max < t->info)
		{
			max = t->info;
			MAX = t;
		}
		t = t->next;
	}
	if (MAX != nullptr)
	{
		// Перемещаем максимальный элемент в начало очереди
		while (*begin != MAX)
		{
			double element = fromFIFO(begin);
			create(begin, end, element);
		}
	}
}