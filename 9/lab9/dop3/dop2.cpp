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

void insert(Student* e, Student** phead, Student** plast); //����������
Student* setElement(); //����
void outputList(Student** phead, Student** plast); //�����
void studentOld(Student** phead, Student** plast); // ����� ��������
void studentYoung(Student** phead, Student** plast); // ����� ��������
void outputFirstCourse(Student** phead, Student** plast); //������ ����
void outputSecondCourse(Student** phead, Student** plast); // ������ ����
void outputThirdCourse(Student** phead, Student** plast); //������ ����
void outputFourthCourse(Student** phead, Student** plast); //�������� ����
void sortStudentsByCourse(Student** phead); // ����������
void calculateAverageScores(Student** phead); // ������ �������� ��������

int main() {
	setlocale(LC_ALL, "rus");
	Student* head = nullptr;
	Student* last = nullptr;
	int choice;
	do {
		cout << "1. ���� ������" << endl;
		cout << "2. ����� �������� ��������" << endl;
		cout << "3. ����� �������� ��������" << endl;
		cout << "4. ������������� ���������" << endl;
		cout << "5. ����� �����" << endl;
		cout << "6. ������ ����" << endl;
		cout << "7. ������ ����" << endl;
		cout << "8. ������ ����" << endl;
		cout << "9. �������� ����" << endl;
		cout << "10. ������ �������� ����� �� �������" << endl;
		cout << "11. �����" << endl;
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

void insert(Student* e, Student** phead, Student** plast) //���������� � ����� ������
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

Student* setElement()  // �������� �������� � ���� ��� �������� � ���������� 
{
	Student* temp = new Student();
	if (!temp) {
		cerr << "������ ��������� ������";
		return nullptr;
	}
	cout << "������� �������: ";
	cin >> temp->surname;
	cout << "������� ���: ";
	cin >> temp->name;
	cout << "������� ��������: ";
	cin >> temp->patronymic;
	cout << "������� ���� ��������: " << endl;
	cin >> temp->day >> temp->month >> temp->year;
	cout << "������� ����� �����: ";
	cin >> temp->course;
	cout << "������� ����� ������: ";
	cin >> temp->group;
	cout << "������� ������ �� ���������: " << endl;
	cout << "����������: ";
	cin >> temp->math;
	cout << "������: ";
	cin >> temp->physics;
	cout << "���������� ����: ";
	cin >> temp->english;
	cout << "����: ";
	cin >> temp->OAIP;
	cout << "������� ��������: ";
	cin >> temp->history;
	temp->next = nullptr;
	temp->prev = nullptr;
	return temp;
}

void outputList(Student** phead, Student** plast) // ������� ���� ���������
{
	Student* t = *phead;
	if (t == nullptr) {
		cout << "������ ����!" << endl;
		return;
	}
	while (t != nullptr)
	{
		cout << "--------------------------------------------------" << endl;
		cout << "�������:" << t->surname << endl;
		cout << "���:" << t->name << endl;
		cout << "��������:" << t->patronymic << endl;
		cout << "���� ��������:" << t->day << "." << t->month << "." << t->year << endl;
		cout << "����:" << t->course << endl;
		cout << "������:" << t->group << endl;
		cout << "������:" << endl;
		cout << "����������:" << t->math << endl;
		cout << "������: " << t->physics << endl;
		cout << "���������� ����: " << t->english << endl;
		cout << "����:" << t->OAIP << endl;
		cout << "������� ��������: " << t->history << endl;
		t = t->next;
	}
}

void studentOld(Student** phead, Student** plast) // ���� �������� ��������
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
			cout << "������� ������� = " << t->surname << endl;
		}
		t = t->next;
	}

}
void studentYoung(Student** phead, Student** plast) // ���� �������� ��������
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
			cout << "������� ������� = " << t->surname << endl;
		}
		t = t->next;
	}
}
void sortStudentsByCourse(Student** phead)  // ���������� ��������� �� ����� � �������
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

            // ���� ���� ���������� �������� ������ �������� ��� ������� ���������� ��� ��������� ����� ������ � ���������� ������� �� ������ �� �������
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

void outputFirstCourse(Student** phead, Student** plast) // ������ ����
{
	Student *t = *phead;
	float av = 0, temp;
	char bestud[SIZE];
	// ������� ��������
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	while (t)
	{
		if (t->course == 1)
		{
			temp = (t->math + t->physics + t->history + t->OAIP + t->english)/5;
			cout << "�������:" << t->surname << endl;
			cout << "���:" << t->name << endl;
			cout << "��������:" << t->patronymic << endl;
			cout << "���� ��������:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "����:" << t->course << endl;
			cout << "������:" << t->group << endl;
			cout << "������:" << endl;
			cout << "����������:" << t->math << endl;
			cout << "������:" << t->physics << endl;
			cout << "���������� ����:" << t->english << endl;
			cout << "����:" << t->OAIP << endl;
			cout << "������� ��������:" << t->history << endl<<endl;
			t = t->next;
			if (t != nullptr && temp > av)
			{
				av = temp;
				strcpy(bestud, t->surname); // �������� ������� ������� �������� � ������
			}
		}
		else
		{
			t = t->next;
		}
	}
	cout << endl << "������ �������: " << bestud<<endl;
}
void outputSecondCourse(Student** phead, Student** plast) // ������ ����
{
	Student* t = *phead;
	float av = 0, temp;
	char bestud[SIZE];
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	while (t)
	{
		if (t->course == 2)
		{
			temp = (t->math + t->physics + t->history + t->OAIP + t->english) / 5;
			cout << "�������:" << t->surname << endl;
			cout << "���:" << t->name << endl;
			cout << "��������:" << t->patronymic << endl;
			cout << "���� ��������:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "����:" << t->course << endl;
			cout << "������:" << t->group << endl;
			cout << "������:" << endl;
			cout << "����������:" << t->math << endl;
			cout << "������:" << t->physics << endl;
			cout << "���������� ����:" << t->english << endl;
			cout << "����:" << t->OAIP << endl;
			cout << "������� ��������:" << t->history << endl;
			t = t->next;
			if (t != nullptr && temp > av)
			{
				av = temp;
				strcpy(bestud, t->surname); // �������� ������� ������� �������� � ������
			}
		}
		else
			t = t->next;
	}
}

void outputThirdCourse(Student** phead, Student** plast) //������ ����
{
	Student* t = *phead;
	float av = 0, temp;
	char bestud[SIZE];
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	while (t)
	{
		if (t->course == 3)
		{
			temp = (t->math + t->physics + t->history + t->OAIP + t->english) / 5;
			cout << "�������:" << t->surname << endl;
			cout << "���:" << t->name << endl;
			cout << "��������:" << t->patronymic << endl;
			cout << "���� ��������:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "����:" << t->course << endl;
			cout << "������:" << t->group << endl;
			cout << "������:" << endl;
			cout << "����������:" << t->math << endl;
			cout << "������:" << t->physics << endl;
			cout << "���������� ����:" << t->english << endl;
			cout << "����:" << t->OAIP << endl;
			cout << "������� ��������:" << t->history << endl;
			t = t->next;
			if (t != nullptr && temp > av)
			{
				av = temp;
				strcpy(bestud, t->surname); // �������� ������� ������� �������� � ������
			}
		}
		else
			t = t->next;
	}
}
void outputFourthCourse(Student** phead, Student** plast) //�������� ����
{
	Student* t = *phead;
	float av = 0, temp;
	char bestud[SIZE];
	if (t == NULL)
	{
		cout << "������ ����!" << endl;
	}
	while (t)
	{
		if (t->course == 4)
		{
			temp = (t->math + t->physics + t->history + t->OAIP + t->english) / 5;
			cout << "�������:" << t->surname << endl;
			cout << "���:" << t->name << endl;
			cout << "��������:" << t->patronymic << endl;
			cout << "���� ��������:" << t->day << "." << t->month << "." << t->year << endl;
			cout << "����:" << t->course << endl;
			cout << "������:" << t->group << endl;
			cout << "������:" << endl;
			cout << "����������:" << t->math << endl;
			cout << "������:" << t->physics << endl;
			cout << "���������� ����:" << t->english << endl;
			cout << "����:" << t->OAIP << endl;
			cout << "������� ��������:" << t->history << endl;
			t = t->next;
			if (t != nullptr && temp > av)
			{
				av = temp;
				strcpy(bestud, t->surname); // �������� ������� ������� �������� � ������
			}
		}
		else
			t = t->next;
	}
}
void calculateAverageScores(Student** phead) // ������ ������� ������ �� ������� �������� ��� ������ ������
{
	const int MAX_GROUPS = 10; 
	int numStudents[MAX_GROUPS] = { 0 }; // ������ ��� �������� ���������� ��������� � ������ ������
	float math[MAX_GROUPS] = { 0 }, physics[MAX_GROUPS] = { 0 }, totalEnglish[MAX_GROUPS] = { 0 }, totalOAIP[MAX_GROUPS] = { 0 }, totalHistory[MAX_GROUPS] = { 0 };

	// �������� �� ������ ��������� � ��������� ������ �� ������� �������� ��� ������ ������
	Student* current = *phead;
	while (current != nullptr)
	{
		int groupIndex = current->group - 1; // ������ ������ � �������
		numStudents[groupIndex]++;
		math[groupIndex] += current->math;
		physics[groupIndex] += current->physics;
		totalEnglish[groupIndex] += current->english;
		totalOAIP[groupIndex] += current->OAIP;
		totalHistory[groupIndex] += current->history;
		current = current->next;
	}

	// ��������� ������� ���� �� ������� �������� ��� ������ ������
	for (int i = 0; i < MAX_GROUPS; i++) 
	{
		if (numStudents[i] != 0) {
			float averageMath = math[i] / numStudents[i];
			float averagePhysics = physics[i] / numStudents[i];
			float averageEnglish = totalEnglish[i] / numStudents[i];
			float averageOAIP = totalOAIP[i] / numStudents[i];
			float averageHistory = totalHistory[i] / numStudents[i];

			// ������� ���������� ��� ������ ������
			cout << "������ " << i + 1 << ":" << endl;
			cout << "������� ���� �� ����������: " << averageMath << endl;
			cout << "������� ���� �� ������: " << averagePhysics << endl;
			cout << "������� ���� �� ����������� �����: " << averageEnglish << endl;
			cout << "������� ���� �� �����: " << averageOAIP << endl;
			cout << "������� ���� �� ������� ��������: " << averageHistory << endl;
		}
	}
}