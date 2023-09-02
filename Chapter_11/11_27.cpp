#include <iostream> // ������ 11.27 
#include <cstring>
using std::cout;
using std::cin;

const int NUM = 20;
const int SIZE = 100;

char *find_name(char name[][SIZE], char str[]);

int main()
{
	char *ptr, str[SIZE], name[NUM][SIZE]; /* ������ ������ NUM ������� ��� SIZE ������, ���� ���� ���� ������ ������������� �� ���������� ��� ����������� ��������. */ 
	int i;

	for(i = 0; i < NUM; i++)
	{
		cout << "Enter name: ";
		cin.getline(name[i], sizeof(name[i])); /* �������������� �� name[i] ��� ������ ���� ��� ���������� i ������ ��� SIZE ����������. */
	}
	cout << "Enter name to search: ";
	cin.getline(str, sizeof(str));

	ptr = find_name(name, str);
	if(ptr == nullptr)
		cout << str << " is not contained\n";
	else
		cout << ptr << " is contained\n";
	return 0;
}

char *find_name(char name[][SIZE], char str[])
{
	int i;

	for(i = 0; i < NUM; i++)
		if(strcmp(name[i], str) == 0)
			return name[i]; /* �� name[i] ������� ���� ����� ��������� ��� ������� ��� �������� �� ������������ �����. */
	return nullptr; /* �� � �������� ��� ������ ������ �� ���� �� ������ �������� ��� �� ����� ��� ������� ���� ������. */
}

