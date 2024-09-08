#include <iostream>
#include <fstream>

using namespace std;

struct list
{
    int number;
    list* next;
};

void input(list*&, int); //������� ���������� ��������, ���������� ����� ������ � ������, ������� ����������� 
void output(list*); //������� ������
float del(list*&, int); //������� ��������, ���������� ����� ������ � ������, ������� ��������� 
int isEmpty(list*); //�������, ������� ���������, ���� �� ������
void toFile(list*& p); //������ � ����
void fromFile(list*& p); //���������� �� �����
void sumpos2(list*); //������� �������� ����� ������������� ����� ������� 2
void find(list*); //������� ������

int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice;
    int value;
    do
    {
        cout << "1 - ���� ��������� � ����������" << endl;
        cout << "2 - ����� ��������� � ���������� ����" << endl;
        cout << "3 - �������� �������� ����������" << endl;
        cout << "4 - ����� ����������" << endl;
        cout << "5 - ������ ���������� � ����" << endl;
        cout << "6 - ������ ������ �� �����" << endl;
        cout << "7 - ���������� �����" << endl;
        cout << "8 - ����� �� ���������" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int n;
            cout << "������� ����� �� ������ ������?" << endl;
            cin >> n;
            for (int i = 0;i < n;i++)
            {
                cout << "������� ����� "; // �������� ����� � ������
                cin >> value;
                input(first, value);
            }
            break;
        case 2:
            output(first);
            break;
        case 3:
            if (!isEmpty(first)) // ������� ����� �� ������
            {
                cout << "������� ��������� ����� ";
                cin >> value;
                if (del(first, value))
                {
                    cout << "������� ����� " << value << endl;
                    output(first);
                }
                else
                    cout << "����� �� �������" << endl;
            }
            else
                cout << "������ ����" << endl;
            break;
        case 4:
            find(first);
            break;
        case 5:
            toFile(first);
            break;
        case 6:
            fromFile(first);
            break;
        case 7:
            sumpos2(first);	// ���������� ������������
            break;
        }
    } while (choice != 8);
    return 0;
}

void input(list*& first, int value) //���������� ����� value � ������ 
{
    list* newfirst = new list;
    if (newfirst != NULL) //���� �� �����?  
    {
        newfirst->number = value; // ����������� � ���� ��������
        newfirst->next = first; // ����� ���� ��������� �� �������� ������ ����
        first = newfirst; // ��������� �� ������ ������� ������ ������ ��������� �� ����� ����
    }
    else
        cout << "�������� ���������� �� ���������" << endl;
}

float del(list*& p, int value)  // �������� ����� 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // ����������� ���� 
        delete temp;      //���������� ������������� ���� 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // ������� � ���������� 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            delete(temp);
            return value;
        }
    }
    return 0;
}

int isEmpty(list* p) //������ ������? (1-��, 0-���) 
{
    return p == NULL;
}

void output(list* p)  //����� ������ 
{
    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        cout << "������:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void sumpos2(list* p)  // ������� ����� ������������� ����� ������� 2  
{
    int sum = 0;
    if (p == NULL)
        cout << "������ ����" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < 0 && p->number % 2 == 0)
                sum = sum + (p->number);
            p = p->next;
        }
        if (sum < 0)
            cout << "����� = " << sum << endl;
        else
            cout << "������������� ����� ������� 2 - ���" << endl;
    }
}

void toFile(list*& p)
{
    list* temp = p;
    list buf;
    ofstream frm("FILE1.dat");
    if (frm.fail())
    {
        cout << "\n ������ �������� �����";
        exit(1);
    }
    while (temp)
    {
        buf = *temp;
        frm.write((char*)&buf, sizeof(list));
        temp = temp->next;
    }
    frm.close();
    cout << "������ ������� � ���� FILE1.dat\n";
}

void fromFile(list*& p) //���������� �� �����
{
    list buf, * first = nullptr;
    ifstream frm("FILE1.dat");
    if (frm.fail())
    {
        cout << "\n ������ �������� �����";
        exit(1);
    }
    frm.read((char*)&buf, sizeof(list));
    while (!frm.eof())
    {
        input(first, buf.number);
        cout << "-->" << buf.number;
        frm.read((char*)&buf, sizeof(list));
    }
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    cout << "\n������ ������ �� ����� FILE1.dat\n";
}

void find(list* p)
{
    int value;
    cout << "������� ����� ��� ������ ";
    cin >> value;
    while (p != NULL)
    {
        if (p->number == value)
        {
            cout << "����� " << value << " ������� � ������" << endl;
            return;
        }
        p = p->next;
    }
    cout << "����� �� ������� � ������" << endl;
}