#include <iostream>
#include <fstream>
#include "myStack2.h"
using namespace std;

void push(int x, Stack*& myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле data 
	e->next = myStk;         //перенос вершины на следующий элемент 
	myStk = e;               //сдвиг вершины на позицию вперед
}

char pop(Stack*& myStk)   //Извлечение (удаление) элемента из стека
{
	if (myStk == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;               //если стек пуст - возврат (-1) 
	}
	else
	{
		Stack* e = myStk;        //е-переменная для хранения адреса элемента
		int x = myStk->data;    //запись элемента из поля data в перем. x 
		if (myStk)
			myStk = myStk->next;   //перенос вершины
		delete e;
		return x;
	}
}
void toFile(Stack*& myStk) //Запись в файл
{
	Stack* e = myStk;
	Stack buf;
	ofstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (e)
	{
		buf = *e;
		frm.write((char*)&buf, sizeof(Stack));
		e = e->next;
	}
	frm.close();
	cout << "Стек записан в файл mStack.dat\n";
}

void fromFile(Stack*& myStk) //Считывание из файла в стек
{
	Stack buf, * p = nullptr, * e = nullptr;
	ifstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	frm.seekg(0);
	frm.read((char*)&buf, sizeof(Stack));
	while (!frm.eof())
	{
		push(buf.data, e);
		frm.read((char*)&buf, sizeof(Stack));
	}
	frm.close();
	while (e != NULL)
	{
		buf.data = pop(e);
		push(buf.data, p);
		myStk = p;
	}
	cout << "\nСтек считан из файла mStack.dat\n\n";
}
void show(Stack*& myStk)  //Вывод стека
{
	Stack* e = myStk;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		cout << e->data << " ";
		e = e->next;
	}
	cout << endl;
}

void clear(Stack*& myStk) // функция очистки
{
	Stack* e = myStk;
	if (e == NULL)
	{
		cout << "Стек пуст!" << endl;
		return;
	}
	else
	{
		while (e != NULL)
		{
			Stack* temp = e; // сохраняем текущий элемент
			e = e->next;     // переходим к следующему элементу
			delete temp;     // освобождаем память текущего элемента
		}
		myStk = NULL;
		cout << "Стек очищен";
	}
	cout << endl;
}

void find(Stack*& myStk)  // функция поиска и удаления первого отрицательного элемента в стеке
{
	bool f = true;
	Stack* prev = NULL;
	Stack* e = myStk;
	while (e != NULL)
	{
		if (e->data < 0 && f)
		{
			if (prev == NULL) // если отрицательный элемент - первый в стеке
			{
				myStk = e->next;
			}
			else
			{
				prev->next = e->next;
			}
			int x = e->data;
			delete e;
			cout << "Извлечён элемент: " << x << endl;
			f = false;
			break; // выходим из цикла после удаления элемента
		}
		prev = e;
		e = e->next;
	}
	if (f)
	{
		cout << endl << "Отрицательных элементов не найдено" << endl; // Если ни один элемент не нашелся 
	}
}