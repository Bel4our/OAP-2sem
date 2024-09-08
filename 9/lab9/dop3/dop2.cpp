#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define SIZE 50

using namespace std;

struct Student {
	char surname[SIZE];
	char name[SIZE];
	char patronymic[SIZE];
	int day;
	int month;
	int year;
	int course;
	int group;
	float math;
	float physics;
	float english;
	float OAIP;
	float history;
	Student* next;
	Student* prev;
};

struct AverageScore {
	float math;
	float physics;
	float english;
	float OAIP;
	float history;
};

void insert(Student* e, Student** phead, Student** plast); //размещение
Student* setElement(); //ввод
void outputList(Student** phead, Student** plast); //вывод
void studentOld(Student** phead, Student** plast); // Поиск старшего
void studentYoung(Student** phead, Student** plast); // Поиск младшего
void outputFirstCourse(Student** phead, Student** plast); //Первый курс
void outputSecondCourse(Student** phead, Student** plast); // Второй курс
void outputThirdCourse(Student** phead, Student** plast); //Третий курс
void outputFourthCourse(Student** phead, Student** plast); //Четвёртый курс
void sortStudentsByCourse(Student** phead); // сортировка
void calculateAverageScores(Student** phead); // расчёт среднего значения

int main() {
	setlocale(LC_ALL, "rus");
	Student* head = nullptr;
	Student* last = nullptr;
	int choice;
	do {
		cout << "1. Ввод данных" << endl;
		cout << "2. Поиск старшего студента" << endl;
		cout << "3. Поиск младшего студента" << endl;
		cout << "4. Отсортировать студентов" << endl;
		cout << "5. Вывод всего" << endl;
		cout << "6. Первый курс" << endl;
		cout << "7. Второй курс" << endl;
		cout << "8. Третий курс" << endl;
		cout << "9. Четвёртый курс" << endl;
		cout << "10. Расчёт среднего балла по группам" << endl;
		cout << "11. Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			insert(setElement(), &head, &last);
			break;
		case 2:
			studentOld(&head, &last);
			break;
		case 3:
			studentYoung(&head, &last);
			break;
		case 4:
			sortStudentsByCourse(&head);
			break;
		case 5:
			outputList(&head, &last);
			break;
		case 6:
			outputFirstCourse(&head, &last);
			break;
		case 7:
			outputSecondCourse(&head, &last);
			break;
		case 8:
			outputThirdCourse(&head, &last);
			break;
		case 9:
			outputFourthCourse(&head, &last);
			break;

		case 10:
			calculateAverageScores(&head);
			break;
		}
	} while (choice != 11);

	return 0;
}

void insert(Student* e, Student** phead, Student** plast) //Добавление в конец списка
{
	if (*plast == nullptr) {
		*plast = e;
		*phead = e;
	}
	else {
		(*plast)->next = e;
		e->prev = *plast;
		*plast = e;
	}
}

Student* setElement()  // Создание элемента и ввод его значений с клавиатуры 
{
	Student* temp = new Student();
	if (!temp) {
		cerr << "Ошибка выделения памяти";
		return nullptr;
	}
	cout << "Введите фамилию: ";
	cin >> temp->surname;
	cout << "Введите имя: ";
	cin >> temp->name;
	cout << "Введите отчество: ";
	cin >> temp->patronymic;
	cout << "Введите дату рождения: " << endl;
	cin >> temp->day >> temp->month >> temp->year;
	cout << "Введите номер курса: ";
	cin >> temp->course;
	cout << "Введите номер группы: ";
	cin >> temp->group;
	cout << "Введите оценки по предметам: " << endl;
	cout << "Математика: ";
	cin >> temp->math;
	cout << "Физика: ";
	cin >> temp->physics;
	cout << "Английский язык: ";
	cin >> temp->english;
	cout << "ОАиП: ";
	cin >> temp->OAIP;
	cout << "История Беларуси: ";
	cin >> temp->history;
	temp->next = nullptr;
	temp->prev = nullptr;
	return temp;
}

void outputList(Student** phead, Student** plast) // выводим всех студентов
{
	Student* t = *phead;
	if (t == nullptr) {
		cout << "Список пуст!" << endl;
		return;
	}
	while (t != nullptr)
	{
		cout << "--------------------------------------------------" << endl;
		cout << "Фамилия:" << t->surname << endl;
		cout << "Имя:" << t->name << endl;
		cout << "Отчество:" << t->patronymic << endl;
		cout << "Дата рождения:" << t->day << "." << t->month << "." << t->year << endl;
		cout << "Курс:" << t->course << endl;
		cout << "Группа:" << t->group << endl;
		cout << "Оценки:" << endl;
		cout << "Математика:" << t->math << endl;
		cout << "Физика: " << t->physics << endl;
		cout << "Английский язык: " << t->english << endl;
		cout << "ОАиП:" << t->OAIP << endl;
		cout << "История Беларуси: " << t->history << endl;
		t = t->next;
	}
}

void studentOld(Student** phead, Student** plast) // ищем старшего студента
{
	int old = 0;
	Student* tmp = *phead;
	old = tmp->year;
	while (tmp)
	{

		if (tmp->year < old)
		{
			old = tmp->year;
		}
		tmp = tmp->next;

	}
	Student* t = *phead;
	while (t)
	{
		if (t->year == old)
		{
			cout << "Старший студент = " << t->surname << endl;
		}
		t = t->next;
	}

}
void studentYoung(Student** phead, Student** plast) // ищем младшего студента
{
	int young = 0;
	Student* tmp = *phead;
	young = tmp->year;
	while (tmp)
	{

		if (tmp->year > young)
		{
			young = tmp->year;
		}
		tmp = tmp->next;

	}
	Student* t = *phead;
	while (t)
	{
		if (t->year == young)
		{
			cout << "Младший студент = " << t->surname << endl;
		}
		t = t->next;
	}
}
void sortStudentsByCourse(Student** phead)  // Сротировка студентов по курсу и фамилии
{
    Student* current = *phead;
    int swapped;
    Student* temp;
    if (current == NULL || current->next == NULL) 
	{
        return;
    }

    do {
        swapped = 0;
        current = *phead;

        while (current->next != nullptr)
		{

            // Если курс следующего студента меньше текущего или фамилия следующего при однаковом курсе раньше в алфавитном порядке то меняем их местами
            if (current->course > current->next->course || (current->course == current->next->course && strcmp(current->surname, current->next->surname) > 0)) 
			{
                temp = current->next;
                current->next = temp->next;
                temp->next = current;
                if (current->prev != NULL)
				{
                    current->prev->next = temp;
                }
                temp->prev = current->prev;
                current->prev = temp;
                if (current == *phead) 
				{
                    *phead = temp;
                }
                if (current->next != NULL) 
				{
                    current->next->prev = current;
                }
                swapped = 1;
            } 
			else 
			{
                current = current->next;
            }
        }
    } while (swapped);
}

void outputFirstCourse(Student** phead, Student** plast) // первый курс
{
	Student *t = *phead;
	float av = 0, temp;
	char bestud[SIZE];
	// среднее значение
	if (t == NULL)
	{
		cout << "Список пуст!" << endl;
	}
	while (t)
	{
		if (t->course == 1)
		{
			temp = (t->math + t->physics + t->history + t->OAIP + t->english)/5;
			cout << "Фамилия:" << t->surname << endl;
			cout << "Имя:" << t->name << endl;
			cout << "Отчество:" << t->patronymic << endl;
			cout << "Дата рождения:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "Курс:" << t->course << endl;
			cout << "Группа:" << t->group << endl;
			cout << "Оценки:" << endl;
			cout << "Математика:" << t->math << endl;
			cout << "Физика:" << t->physics << endl;
			cout << "Английский язык:" << t->english << endl;
			cout << "ОАиП:" << t->OAIP << endl;
			cout << "История Беларуси:" << t->history << endl<<endl;
			t = t->next;
			if (t != nullptr && temp > av)
			{
				av = temp;
				strcpy(bestud, t->surname); // Копируем фамилию лучшего студента в массив
			}
		}
		else
		{
			t = t->next;
		}
	}
	cout << endl << "Лучший студент: " << bestud<<endl;
}
void outputSecondCourse(Student** phead, Student** plast) // второй курс
{
	Student* t = *phead;
	float av = 0, temp;
	char bestud[SIZE];
	if (t == NULL)
	{
		cout << "Список пуст!" << endl;
	}
	while (t)
	{
		if (t->course == 2)
		{
			temp = (t->math + t->physics + t->history + t->OAIP + t->english) / 5;
			cout << "Фамилия:" << t->surname << endl;
			cout << "Имя:" << t->name << endl;
			cout << "Отчество:" << t->patronymic << endl;
			cout << "Дата рождения:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "Курс:" << t->course << endl;
			cout << "Группа:" << t->group << endl;
			cout << "Оценки:" << endl;
			cout << "Математика:" << t->math << endl;
			cout << "Физика:" << t->physics << endl;
			cout << "Английский язык:" << t->english << endl;
			cout << "ОАиП:" << t->OAIP << endl;
			cout << "История Беларуси:" << t->history << endl;
			t = t->next;
			if (t != nullptr && temp > av)
			{
				av = temp;
				strcpy(bestud, t->surname); // Копируем фамилию лучшего студента в массив
			}
		}
		else
			t = t->next;
	}
}

void outputThirdCourse(Student** phead, Student** plast) //третий курс
{
	Student* t = *phead;
	float av = 0, temp;
	char bestud[SIZE];
	if (t == NULL)
	{
		cout << "Список пуст!" << endl;
	}
	while (t)
	{
		if (t->course == 3)
		{
			temp = (t->math + t->physics + t->history + t->OAIP + t->english) / 5;
			cout << "Фамилия:" << t->surname << endl;
			cout << "Имя:" << t->name << endl;
			cout << "Отчество:" << t->patronymic << endl;
			cout << "Дата рождения:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "Курс:" << t->course << endl;
			cout << "Группа:" << t->group << endl;
			cout << "Оценки:" << endl;
			cout << "Математика:" << t->math << endl;
			cout << "Физика:" << t->physics << endl;
			cout << "Английский язык:" << t->english << endl;
			cout << "ОАиП:" << t->OAIP << endl;
			cout << "История Беларуси:" << t->history << endl;
			t = t->next;
			if (t != nullptr && temp > av)
			{
				av = temp;
				strcpy(bestud, t->surname); // Копируем фамилию лучшего студента в массив
			}
		}
		else
			t = t->next;
	}
}
void outputFourthCourse(Student** phead, Student** plast) //четвёртый курс
{
	Student* t = *phead;
	float av = 0, temp;
	char bestud[SIZE];
	if (t == NULL)
	{
		cout << "Список пуст!" << endl;
	}
	while (t)
	{
		if (t->course == 4)
		{
			temp = (t->math + t->physics + t->history + t->OAIP + t->english) / 5;
			cout << "Фамилия:" << t->surname << endl;
			cout << "Имя:" << t->name << endl;
			cout << "Отчество:" << t->patronymic << endl;
			cout << "Дата рождения:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "Курс:" << t->course << endl;
			cout << "Группа:" << t->group << endl;
			cout << "Оценки:" << endl;
			cout << "Математика:" << t->math << endl;
			cout << "Физика:" << t->physics << endl;
			cout << "Английский язык:" << t->english << endl;
			cout << "ОАиП:" << t->OAIP << endl;
			cout << "История Беларуси:" << t->history << endl;
			t = t->next;
			if (t != nullptr && temp > av)
			{
				av = temp;
				strcpy(bestud, t->surname); // Копируем фамилию лучшего студента в массив
			}
		}
		else
			t = t->next;
	}
}
void calculateAverageScores(Student** phead) // Расчет средних баллов по каждому предмету для каждой группы
{
	const int MAX_GROUPS = 10; 
	int numStudents[MAX_GROUPS] = { 0 }; // Массив для хранения количества студентов в каждой группе
	float math[MAX_GROUPS] = { 0 }, physics[MAX_GROUPS] = { 0 }, totalEnglish[MAX_GROUPS] = { 0 }, totalOAIP[MAX_GROUPS] = { 0 }, totalHistory[MAX_GROUPS] = { 0 };

	// Проходим по списку студентов и суммируем оценки по каждому предмету для каждой группы
	Student* current = *phead;
	while (current != nullptr)
	{
		int groupIndex = current->group - 1; // Индекс группы в массиве
		numStudents[groupIndex]++;
		math[groupIndex] += current->math;
		physics[groupIndex] += current->physics;
		totalEnglish[groupIndex] += current->english;
		totalOAIP[groupIndex] += current->OAIP;
		totalHistory[groupIndex] += current->history;
		current = current->next;
	}

	// Вычисляем средний балл по каждому предмету для каждой группы
	for (int i = 0; i < MAX_GROUPS; i++) 
	{
		if (numStudents[i] != 0) {
			float averageMath = math[i] / numStudents[i];
			float averagePhysics = physics[i] / numStudents[i];
			float averageEnglish = totalEnglish[i] / numStudents[i];
			float averageOAIP = totalOAIP[i] / numStudents[i];
			float averageHistory = totalHistory[i] / numStudents[i];

			// Выводим результаты для каждой группы
			cout << "Группа " << i + 1 << ":" << endl;
			cout << "Средний балл по Математике: " << averageMath << endl;
			cout << "Средний балл по Физике: " << averagePhysics << endl;
			cout << "Средний балл по Английскому языку: " << averageEnglish << endl;
			cout << "Средний балл по ОАиПу: " << averageOAIP << endl;
			cout << "Средний балл по Истории Беларуси: " << averageHistory << endl;
		}
	}
}