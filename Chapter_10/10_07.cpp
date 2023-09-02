#include <iostream> // ’σκηση 10.7
using std::cout;
using std::cin;

int main()
{
	char *ptr[3], str[100];
	int i;

	for(i = 0; i < 3; i++)
	{
		cout << "Enter text: ";
		cin.getline(str, sizeof(str));
		ptr[i] = str;
	}
	for(i = 0; i < 3; i++)
		cout << *ptr[i] << '\n';
	return 0;
}

