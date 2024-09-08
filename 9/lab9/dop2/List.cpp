#include "List.h"
bool Object::Insert(char* carmodel, char* color, char* carnumb, char* daterealese, char* typecar, int  datetech, char* owner)           // ������� � ������
{
	bool rc = 0;
	if (Head == NULL) // ���� ������  ����
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
Element* Object::Search(char* owner)    // ����� �������� �������
{
	Element* rc = Head;
	while ((rc != NULL) && (strcmp(rc->Owner, owner)))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(char*, char*, char*, char*, char*, int, char*))     // ����� // �������� ������� ��� ���������
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e->Carmodel, e->Color, e->Carnumb, e->Daterelease, e->Typecar, e->Datetech, e->Owner); // ������������� ����������� ��������� ������� ��� ������ ��������
		e = e->GetNext(); // ��������� ��������� �� ��������� ������� � ������� ������
	};
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(char*, char*, char*, char*, char*, int, char*), Element* e)
{
	f(e->Carmodel, e->Color,e->Carnumb, e->Daterelease, e->Typecar,e->Datetech,e->Owner);
}
//-----------------------------------------------------------
bool  Object::Delete(Element* e)    // ������� �� ������
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
bool Object::Delete(char* owner)      // ������� �� ��������
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
	return *(new Object()); // ������������� ����� ������������ � ���������� ������ ��� ������, � ����� ���������� �������� ������ ������������
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
