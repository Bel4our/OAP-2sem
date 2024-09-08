#pragma once
#include <iostream>
struct Element                   // ������� ������ 
{
	Element* Prev;                // ��������� �� ���������� ������� 
	Element* Next;                // ��������� �� ��������� ������� 
	char Carmodel[50];
	char Color[50];
	char Carnumb[50];
	char Daterelease[50];
	char Typecar[50];
	int Datetech;
	char Owner[50];          //  ������  
	Element(Element* prev, char* carmodel, char *color, char* carnumb, char* daterealese, char* typecar,int  datetech, char * owner, Element* next) // ����������� ��� �������� ��������
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
	Element* GetNext()            // �������� ���������
	{
		return Next;
	};
	Element* GetPrev()            // �������� ����������  
	{
		return Prev;
	};
};
//-----------------------------------------------------------
struct Object                     // ���� ���������� ������� 
{
	Element* Head;                 // ��������� �� ������ ������
	Object()
	{
		Head = NULL;
	};
	Element* GetFirst()            // �������� ������ ������� ������
	{
		return Head;
	};
	Element* GetLast();            // �������� ��������� ������� ������
	Element* Search(char*);   // �����  ������ ������� �� ������ 
	bool Insert(char*, char*, char*, char*, char*, int, char*);       // �������� ������� � ������
	bool InsertEnd(char *, char*, char*, char*, char*, int, char*);    // �������� � ����� 
	bool Delete(Element* e);       // ������� �� ������ �������� 
	bool Delete(char*);       // ������� ������ �� ������
	bool DeleteList();		    // �������� ������ 
	void PrintList(void(*f)(char*, char*, char*, char*, char*, int, char*));
	void PrintList(void(*f)(char*, char*, char*, char*, char*, int, char*), Element*);
	int CountList();
	bool  DeleteDouble();
};
Object Create();