struct Stack
{
	int data;     //информационный элемент
	Stack* next;	 //указатель на следующий элемент
};
void show(Stack*& myStk); // функция вывода
char pop(Stack*& myStk); // функция извлечения элемента
void push(int x, Stack*& myStk); // функция ввода
void toFile(Stack*& myStk); // функция записи в файл
void fromFile(Stack*& myStk); // функция чтения из файла в стек
void clear(Stack*& myStk); // функция очистки
void find(Stack*& myStk); // функция поиска в стека из заданного диапазона