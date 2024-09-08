#include <iostream>
#include <string>
#include <Windows.h>
#define stud  30 // максимальное значение студентов
#define size 6 // максимальное занчение массива с оценками

using namespace std;

void input(); // функция ввода
void output(); // функция вывода
void charact(); // функция для проверки сдал ли студент экзамены на 4, 5
void sec(); // функция для того чтобы узнать общую успеваемость

int choice = 0; // выбор
int current_stud = 0; // текущее значение массива

struct Student  // стркутура 
{
    string name; 
    int num_exams;
    int marks[size]; 
};

Student list_of_students[stud];

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	do
	{
		cout << "1 - Ввод элементов структуры с клавиатуры" << endl;
		cout << "2 - Вывод элементов структуры в консольное окно" << endl;
		cout << "3 - Проверка на успешность" << endl;
		cout << "4 - Характеристика успеваемости" << endl;
		cout << "5 - Выход из программы" << endl;
		cin >> choice;
		// анализируем choice
		switch (choice)
		{
		case 1:
			input();
			break;
		case 2:
			output();
			break;
		case 3:
			charact();
			break;
		case 4:
			sec();
			break;
		}
	} while (choice != 5);
    return 0;
}
void input() // функция ввода
{
	int numb;
	cout << "Введите количество студентов" << endl; cin >> numb;
	for (int i = 0;i < numb;i++)
	{
		if (current_stud < stud)
		{		
			cin.ignore();
			cout << endl << "Фамилия студента: " << endl;
			getline(cin, list_of_students[current_stud].name);
			cout << "Количество экзаменов " << endl;
			cin >> list_of_students[current_stud].num_exams;
			cout << "Оценки " << endl;
			for (int j = 0;j < list_of_students[current_stud].num_exams;j++) //цикл для записи оценок
			{
				cout << "Введите оценку за " << j + 1 << " экзамен: ";
				cin >> list_of_students[current_stud].marks[j];
				cout << endl;
			}
			current_stud++;
		}
	}

}

void output() // функция вывода
{
	for (int i = 0;i < current_stud;i++)
	{
		cout << endl << "Фамилия студента: " << list_of_students[i].name << endl;
		cout << "Количество экзаменов " << list_of_students[i].num_exams << endl;
		cout << "Оценки: " << endl;
		for (int j = 0;j < list_of_students[i].num_exams;j++) 
		{
			cout << "Введите оценку за " << j + 1 << " экзамен: "<<list_of_students[i].marks[j] << endl;
		}
	}
}

void charact()  // функция для проверки сдал ли студент экзамены на 4, 5
{
	int count = 0;
	bool f = true;
	string surname;
	cout << "Введите фамилию студента: "; 
	cin.ignore();
	getline(cin, surname);
	for (int i = 0; i < current_stud;i++)
	{
		if (list_of_students[i].name == surname)
		{
			for (int j = 0;j < list_of_students[i].num_exams;j++)
			{
				if (list_of_students[i].marks[j] >= 4)
				{
					count++; // считаем оценки 4 и 5 у студента
				}
			}
			if (count == list_of_students[i].num_exams) // если их количество совпало с количеством экзаменов
			{
				cout << endl << "Студент сдал все экзамены на 4, 5"<<endl; // значит студент молодец

			}
			else
			{
				cout << endl << "Студент не сдал все экзамены на 4, 5"<<endl;
			}
			f = false;
		}
	}
	if (f) // условие если у нас не найдено студента с такой фамилией
	{
		cout << "Студента с такой фамилией не найдено!" << endl; 
	}
}

void sec() // функция для того чтобы узнать общую успеваемость
{
	float secstud=0; // переменная для хранения студентов у которых оценки выше 4 
	for (int i = 0;i < current_stud;i++)
	{
		int count = 0;
		for (int j = 0;j < list_of_students[i].num_exams;j++)
		{
			if (list_of_students[i].marks[j] >= 4)
			{
				count++; // считаем оценки 4 и 5
			}
		}
		if (count == list_of_students[i].num_exams)
		{
			secstud++; // увеличиваем значение
		}
	}
	float devide = secstud / current_stud*100; // считаем наших студентов
	cout << "Количество успешных студентов в процентах: " << devide << endl;
}

