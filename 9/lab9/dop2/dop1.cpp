#include "List.h"
using namespace std;

void print(char* carmodel, char* color, char* carnumb, char* daterealese, char* typecar, int  datetech, char* owner)
{
	cout << carmodel << "  " << color << "  " << carnumb<< "  " << daterealese<< "  " << typecar <<"  " << datetech<< "  " << owner << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	Object L1 = Create();
	do{
		cout << "Выберите вариант: " << endl;
		cout << "1. Внести элемент в начало списка" << endl;
		cout << "2. Вывод" << endl;
		cout << "3. Поиск элемента" << endl;
		cout << "4. Удаление элемента" << endl;
		cout << "5. Удалить список" << endl;
		cout << "6. Подсчёт число элементов списка" << endl;
		cout << "7. Выход" << endl;
		cin >> choice;
		switch (choice) 
		{
		case 1:
		{
			char Carmodel[50];
			char Color[50];
			char Carnumb[50];
			char Daterelease[50];
			char Typecar[50];
			int Datetech;
			char Owner[50];
			cout << "Марка автомобиля: ";
			cin >> Carmodel;
			cout << "Цвет: ";
			cin >> Color;
			cout << "Заводской номер: ";
			cin >> Carnumb;
			cout << "Дата выпуска: ";
			cin >> Daterelease;
			cout << "Тип кузова: ";
			cin >> Typecar;
			cout << "Дата техосмотра: ";
			cin >> Datetech;
			cout << "Владелец: ";
			cin >> Owner;
			L1.Insert(Carmodel, Color, Carnumb, Daterelease, Typecar, Datetech, Owner);
			break;
		}
		case 2:
		{
			L1.PrintList(print);
			break;
		}
		case 3: 
		{
			char owner[50];
			cout << "Введите Владельца: ";
			cin >> owner;
			Element* e = L1.Search(owner);
			if (e == NULL) 
			{
				cout << "Элемент не найден" << endl;
			}
			else 
			{
				cout << "Найден элемент= " << e->Carmodel <<" " << e->Color << " " << e->Carnumb <<	" "<< e->Daterelease << " " << e->Typecar<< " "<< e->Datetech << " " << e->Owner << endl;
			}
			break;
		}
		case 4: 
		{
			char carnumb[50];
			cout << "Введите владельца для удаления: ";
			cin >> carnumb;
			bool rc = L1.Delete(carnumb);
			if (rc == true) cout << "Удален элемент" << endl;
			break;
		}
		case 5: 
		{
			if (L1.DeleteList()) 
			{
				cout << "Список успешно удалён" << endl;
			}
			else {
				cout << "Ошибка удаления" << endl;
			}
			break;
		}
		case 6: {
			cout << "Количество элементов: " << L1.CountList() << endl;
			break;
		}
		}
	} while (choice != 7);
	return 0;
}
