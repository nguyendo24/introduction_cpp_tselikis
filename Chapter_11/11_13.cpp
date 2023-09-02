#include <iostream> // ’σκηση 11.13
using std::cout;
using std::cin;

int str_cmp(const char *str1, const char *str2);

int main()
{
	char str1[100], str2[100];
	int i;

	cout << "Enter first text: ";
	cin.getline(str1, sizeof(str1));

	cout << "Enter second text: ";
	cin.getline(str2, sizeof(str2));

	i = str_cmp(str1, str2);
	if(i == 0)
		cout << str1 << " = " << str2 << '\n';
	else if(i < 0)
		cout << str1 << " < " << str2 << '\n';
	else
		cout << str1 << " > " << str2 << '\n';
	return 0;
}

int str_cmp(const char *s1, const char *s2)
{
	while(*s1 == *s2)
	{
		if(*s1 == '\0') 
			return 0;
		s1++;
		s2++;
	}
	return *s1-*s2;
}

