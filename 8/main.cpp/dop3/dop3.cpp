#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
	char data;
	Node* next;
};

struct Queue
{

	// указатели на начало и конец очереди 
	Node* head;
	Node* tail;
};

void CreateQueue(Queue* q) // создаём пустую очередь
{
	q->head = NULL;
	q->tail = NULL;
}

void Enqueue(Queue* q, char data) //функция для добавления элемента в конец очрееди
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	if (q->tail == NULL)
	{
		q->head = newNode;
		q->tail = newNode;
	}
	else
	{
		q->tail->next = newNode;
		q->tail = newNode;
	}
}

void Symbol(Queue* Letter, Queue* Number) // функция для отеделения цифр
{
	ifstream f("f.txt"); //открываем файл для чтения
	ofstream g("g.txt"); // открываем файл для записи
	string line;
	char symbol;
	getline(f, line);
	cout << "Исходная строка: " << line << endl;
	for (int i = 0; i < line.length(); i++)
	{
		symbol = line[i];
		if (symbol >= 48 && symbol <= 57)  // если символ цифра
		{
			Enqueue(Number, symbol); // в конец очереди с цифрами
		}
		else //иначе 
		{
			Enqueue(Letter, symbol); // в конец очереди с буквами
		}
		
	}

	Node* line1 = Letter->head;
	Node* line2 = Number->head;
	cout << "Буквы: " << endl;
	while (line1) 
	{
		// вывод букв и запись в файл
		cout << line1->data;
		g << line1->data;
		line1 = line1->next;
	}
	cout << endl;
	cout << "Цифры: " << endl;
	while (line2) 
	{
		// вывод цифр и запись в файл
		cout << line2->data;
		g << line2->data;
		line2 = line2->next;
	}
	cout << endl;

	f.close();
	g.close();
}

int main()
{
	setlocale(LC_ALL, "RU");
	// создаём очереди для букв и цифр
	Queue Letter;
	Queue Number;
	CreateQueue(&Letter);
	CreateQueue(&Number);
	Symbol(&Letter, &Number); // функция разделения на буквы и цифры
	return 0;
}