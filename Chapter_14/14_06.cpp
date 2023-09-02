#include <iostream> // ������ 14.6
#include <cstring>
using std::cout;
using std::cin;

const int SIZE = 100;

int main()
{
	char *ptr[SIZE], str[100];
	int i, pos, len, max_len; /* � ��������� pos ������� �� �������� ��� ������ ptr ��� ������� ��� ���������� �������������. �� ����� ��� ������������ ��� ��������� max_len. */
	pos = max_len = 0; 
	for(i = 0; i < SIZE; i++)
	{
		cout << "Enter text: ";
		cin.getline(str, sizeof(str));
		len = strlen(str);
		// ��� ���� ������ ���������� ��� ����������� �����.  
		ptr[i] = new char[len+1];
		/* ���������� ��� �������������� ��� ����� ��� ���������� ��� ��� ���������� ������. */
		strcpy(ptr[i], str);
		/* ����������� �� ����� ���� �������������� �� ��� ���� ��� max_len ��� �� ������ ��� ������������� �� ���������� ����� ������������ ���� pos �� ���� ��� ������ ��� ���� max_len �� ����� ���. */
		if(len > max_len)
		{
			pos = i;
			max_len = len;
		}
	}
	cout << "Longer string: " << ptr[pos] << '\n';
	for(i = 0; i < SIZE; i++)
		delete[] ptr[i];
	return 0;
}

