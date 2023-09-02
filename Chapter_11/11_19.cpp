#include <iostream> // ������ 11.19
using std::cout;
using std::cin;

char *find(char str[], char ch, int f); 

int main()
{
	char *ptr, ch, str[100];
	int flag;

	cout << "Enter text: ";
	cin.getline(str, sizeof(str));

	cout << "Enter character to search: ";
	ch = cin.get();

	cout << "Enter choice (0-first, other-last): ";
	cin >> flag;

	ptr = find(str, ch, flag);
	if(ptr == nullptr)
		cout << ch << "is not included in the text\n";
	else
		cout << "The rest string is " << ptr << '\n';
	return 0;
}

char *find(char str[], char ch, int f)
{
	char *tmp = nullptr; /* ������ ���� �� ��������� ��� ��� ������ � ����������. */
	while(*str != '\0') 
	{
		if(*str == ch) 
		{
			tmp = str;
			if(f == 0) /* �� ������ � ���������� ��� � ������� ����� 0, � ������ ������������ ��� � ��������� ���������� ��� ������. ������, � tmp ������� ���� ��������� ���� ��������� ��� ���������. */
				break;
		}
		str++;  
	}
	return tmp; 
}

