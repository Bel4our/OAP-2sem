#include "List.h"
bool Object::Insert(char* carmodel, char* color, char* carnumb, char* daterealese, char* typecar, int  datetech, char* owner)           // Вставка в начало
{
	bool rc = 0;
	if (Head == NULL) // если список  пуст
	{
		Head = new Element(NULL, carmodel, color, carnumb, daterealese, typecar, datetech, owner, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(NULL, carmodel, color, carnumb, daterealese, typecar, datetech, owner, Head));
		rc = true;
	}
	return rc;
}
//-----------------------------------------------------------
Element* Object::Search(char* owner)    // Найти заданный элемент
{
	Element* rc = Head;
	while ((rc != NULL) && (strcmp(rc->Owner, owner)))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(char*, char*, char*, char*, char*, int, char*))     // Вывод // передача функции как аргумента
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e->Carmodel, e->Color, e->Carnumb, e->Daterelease, e->Typecar, e->Datetech, e->Owner); // использование формального аргумента функции для вывода элемента
		e = e->GetNext(); // получение указателя на следующий элемент с помощью метода
	};
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(char*, char*, char*, char*, char*, int, char*), Element* e)
{
	f(e->Carmodel, e->Color,e->Carnumb, e->Daterelease, e->Typecar,e->Datetech,e->Owner);
}
//-----------------------------------------------------------
bool  Object::Delete(Element* e)    // Удалить по ссылке
{
	bool rc = 0;
	if (rc = (e != NULL))
	{
		if (e->Next != NULL)
			e->Next->Prev = e->Prev;
		if (e->Prev != NULL)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}
//-----------------------------------------------------------
bool Object::Delete(char* owner)      // Удалить по значению
{
	return Delete(Search(owner));
};
//-----------------------------------------------------------
Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}
//-----------------------------------------------------------
Object Create()
{
	return *(new Object()); // разыменование имени конструктора с выделением памяти под объект, а также выполнение операций внутри конструктора
}

int Object::CountList()
{
	Element* p = Head;
	int counter = 0;
	while (p) {
		p = p->Next;
		counter++;
	}
	return counter;
}
bool Object::DeleteList()
{
	while (Head) {
		Element* p = Head;
		Head = Head->Next;
		delete[]p;
	}
	return Head == NULL ? 1 : 0;
}
