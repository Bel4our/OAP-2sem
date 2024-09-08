#include "Heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

void AAA::print()
{
	cout << x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*)) // создание кучи
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)  // получение левого элемента
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix) // получение правого элемента
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix) // получение родительского узла
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j) // меняем местами
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix) //восстанавливаем кучу
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}

	
	void Heap::insert(void* x) // вставляем элемент в кучу
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax() // удаляем максимальное значение из кучи
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}

	

	void Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		int probel = 20;
		cout << '\n';
		if (size == 0)
			cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			cout << setw(probel + 10) << setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		cout << '\n';
	}

	void Heap::extractI() // удаление i-го элемента
	{
		int i;
		cout << "Введите i:";
		cin >> i;
		cout << endl;
		if (!isEmpty())
		{
			for (int j = i; j < size - 1; j++)
			{
				storage[j] = storage[j + 1];
			}
			size--;
			heapify(0);
		}
	}

	void Heap::extractMin() // удаление минимального
	{
		int min = 100, a;
		int** A = (int**)storage;
		void* rc = nullptr;
		if (!isEmpty())
		{
			for (int i = 0; i < size; i++)
			{
				if (*A[i] < min)
				{
					min = *A[i];
					a = i;
				}
			}
			int i = parent(a);
			for (int i = a; i < size - 1; i++)
			{
				storage[i] = storage[i + 1];
			}
			size--;
			heapify(0);
		}

	}

	void Heap::unionHeap(void* x) // объединение двух куч в одну
	{
		int i;
		for (i = 0; i < size - 1; i++)
		{
			storage[i] = storage[i + 1];
		}
		heapify(0);

		storage[i = ++size - 1] = x;
		while (i > 0 && isLess(storage[parent(i)], storage[i]))
		{
			swap(parent(i), i);
			i = parent(i);
		}
	}

	int Heap::sumVertices() // функция для подсчета суммы всех вершин кучи  Доп вариант 10
	{
		int sum = 0; 
		for (int i = 0; i < size; i++) 
		{
			sum += *((int*)storage[i]);
		}
		return sum; // возвращаем сумму
	}

	int Heap::countLeaves() // количество листьев     Доп вариант 7
	{
		// за листья будем считать элементы без потомков
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (left(i) == -1 && right(i) == -1) // Проверяем отсутствие и левого, и правого потомков
			{
				count++;
			}
		}
		return count;
	}

	int Heap::sumLeaves() // сумма значений листьев    Доп вариант 16
	{
		int sum = 0;
		for (int i = 0; i < size;i++)
		{
			if (left(i) == -1 && right(i) == -1)
			{
				sum+= *((int*)storage[i]);
			}
		}

		return sum;
	}
}
