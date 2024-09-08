#pragma once
#include <iostream>
struct Element                   // Ёлемент списка 
{
	Element* Prev;                // указатель на предыдущий элемент 
	Element* Next;                // указатель на следующий элемент 
	char Carmodel[50];
	char Color[50];
	char Carnumb[50];
	char Daterelease[50];
	char Typecar[50];
	int Datetech;
	char Owner[50];          //  данные  
	Element(Element* prev, char* carmodel, char *color, char* carnumb, char* daterealese, char* typecar,int  datetech, char * owner, Element* next) // конструктор дл€ создани€ элемента
	{
		Prev = prev;
		strcpy_s(Carmodel,carmodel);
		strcpy_s(Color, color);
		strcpy_s(Carnumb, carnumb);
		strcpy_s(Daterelease, daterealese);
		strcpy_s(Typecar, typecar);
		Datetech = datetech;
		strcpy_s(Owner, owner);
		Next = next;
	}
	Element* GetNext()            // получить следующий
	{
		return Next;
	};
	Element* GetPrev()            // получить предыдущий  
	{
		return Prev;
	};
};
//-----------------------------------------------------------
struct Object                     // Ѕлок управлени€ списком 
{
	Element* Head;                 // указатель на начало списка
	Object()
	{
		Head = NULL;
	};
	Element* GetFirst()            // получить первый элемент списка
	{
		return Head;
	};
	Element* GetLast();            // получить последний элемент списка
	Element* Search(char*);   // найти  первый элемент по данным 
	bool Insert(char*, char*, char*, char*, char*, int, char*);       // добавить элемент в начало
	bool InsertEnd(char *, char*, char*, char*, char*, int, char*);    // добавить в конец 
	bool Delete(Element* e);       // удалить по адресу элемента 
	bool Delete(char*);       // удалить первый по данным
	bool DeleteList();		    // очистить список 
	void PrintList(void(*f)(char*, char*, char*, char*, char*, int, char*));
	void PrintList(void(*f)(char*, char*, char*, char*, char*, int, char*), Element*);
	int CountList();
	bool  DeleteDouble();
};
Object Create();