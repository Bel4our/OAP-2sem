#include "Hash.h"
#include <iostream>
int HashFunction(int key, int size, int p)    //Хеш-функция
{
	// функция возвращает одно и то же, что абсолютно всегда приводит к колизии
	double key2 = (int)(size * (key * 0.6180339887499)) % 1; // доп вариант 3 
	
	return key2;
}
//-------------------------------


int Next_hash(int hash, int size, int p, int key)
{
	return (key % size + p * (1 + (key % size))); // доп вариант 15
	//return (hash + 1 * p + 2 * p * p) % size; // доп вариант 1
	//return (hash + p) % size; // изменили на линейную функию  Основной вариант 10
}
//-------------------------------
Object create(int size, int(*getkey)(void*)) // создание объекта хеш функции
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*)) //конструктор
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
bool Object::insert(void* d) //вставка элемента
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, i);
			i != size && !b;  j = Next_hash(j, size, ++i,t))
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
	return b;
}
//-------------------------------
int Object::searchInd(int key) //поиск элемента по ключу
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i))
			if (data[j] != DEL)

				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
//-------------------------------
void* Object::search(int key)  //поиск
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key) // удаление по ключу
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d) //удаление по значению
{
	return(deleteByKey(getKey(d)) != NULL);
}
//-------------------------------

void Object::scan(void(*f)(void*)) //просмотр содержимого хеш-таблицы
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				f((this->data)[i]);
	}
}
