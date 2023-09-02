#include <iostream> // ������ 10.25
#include <cstring> 
using std::cout;
using std::cin;

int main()
{
	const int SIZE = 20;
	char *tmp, *ptr[SIZE], str[SIZE][100];
	int i, j;

	for(i = 0; i < SIZE; i++)
	{
		cout << "Enter name: ";
		cin.getline(str[i], sizeof(str[i]));
		ptr[i] = str[i]; /* �� �������� ��� ������ ������� �������� ��� �������������. */
	}
	for(i = 0; i < SIZE-1; i++)
	{
		for(j = i+1; j < SIZE; j++)
		{
			/* �� �� ������������� ��� ����� ������� � ptr[j] ����� ��������� ��� �� ������������� ��� ����� ������� � ptr[i], ��������������� ���� ������������ �������. */
			if(strcmp(ptr[j], ptr[i]) < 0)
			{
				tmp = ptr[j];
				ptr[j] = ptr[i];
				ptr[i] = tmp;
			}	 
		}
	}
	for(i = 0; i < SIZE; i++)
		cout << ptr[i] << '\n';
	return 0;
}

