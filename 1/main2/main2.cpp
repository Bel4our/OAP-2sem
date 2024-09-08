#include <iostream> // ���������� ���������� ��� ������ � ������/�������
#include <cstdarg>  // ���������� ���������� ��� ������ � ��������� � ������������ ����������� ����������

using namespace std;

int findWord(int n, ...)  // ������� ��� ���������� ������������ �����
{
    va_list args; // ��������� ������ ���� va_list ��� ������ � ����������� �����������
    va_start(args, n); // �������� ������� �������� �� ������

    char word[100]; // ������ ��� �������� �������� �����
    char strwords[600]; // ������ ��� ������ ��������������� ������

    for (int i = 1; i <= n; i++)
    {
        memset(word, 0, sizeof(word));  // ��������� ������ 0, ����� �� ��������� �����
        memset(strwords, 0, sizeof(strwords)); // ��������� ������ 0, ����� �� ��������� �����
        int len = 0; // ���������� ��� ������� ����� �������� �����
        const char* newstr = va_arg(args, const char*); // �������� ������� �������� �� ������
        char symb = 'a'; // ������ ���������� ��� �������� ���� 
        int newsymb = symb; 
        bool f = true; 
        int len2 = 0; // ���������� ��� �������� ����� ��������������� ������
        int w = 0; 

        while (w < 5) // ���� ��� ���������� ������ ������� ������
        {
            while (f) // ���� ��� ���������� ������������ �����
            {
                for (int j = 0;newstr[j] != '\0';j++) // ���� ��� ���� ����� ����������� ��� ������
                {
                    if (newstr[j] == newsymb && newstr[j - 1] == ' ') // ������� ��� ���������� ������������ �����
                    {
                        int m = j; // ������ ���������� ��� ���� ����� ����� ����� �������� ������� ��� ����������
                        for (int k = 0;newstr[m] != ' ';k++, m++) // ���� ��� ���������� ������� ��������� ������
                        {
                            word[k] = newstr[m];
                        }
                        len = m;
                        f = false;
                    }
                }
                newsymb = newsymb + 1; // ����������� �������� ���������� ��� ��������� ��������� ����� �� ��������
            }

            for (int k = 0;k < len;k++, len2++) // ���� ��� ���������� ������ ��������� ������
            {
                strwords[len2] = word[k];
            }
            f = true;
            strwords[len2] = ' '; // ��������� ������ ����� �����
            len2++;
            w++;
        }
        cout << endl;
        for (int i = 0;i < len2;i++)
        {
            cout << strwords[i]; // ������� ���� ������
        }
        cout << endl;
    }
    cout << endl;

    va_end(args); // ��������� ������ � �������� va_list
    return 0;
}

int main()
{
    // ������� ��� ������� ���������� ������
    char str1[] = " bghj agfj cdfa ehlhksgdh dldglhfd ";
    char str2[] = " ehgh bdggfj ajhkgs dhlkdfj cldkgjh ";
    char str3[] = " dhhhghj csgfdsgj edjgfa bgddkg ahf ";

    // �������� �������
    findWord(2, str1, str2);
    findWord(3, str1, str2, str3);
    findWord(1, str1);

    return 0;
}
