#include <iostream> // ’σκηση 10.13 
#include <cstring> 
using std::cout;
using std::cin;

int main()
{
	char ch, str[100];
	int i, len;

	do
	{
		cout << "Enter text (more than 2 chars): ";
		cin.getline(str, sizeof(str));
		len = strlen(str);
	} while(len < 3);

	cout << "Enter character: ";
	ch = cin.get();
	for(i = 0; i <= len-3; i++)
		if(str[i] == ch && str[i+1] == ch && str[i+2] == ch)
		{
			cout << "There are three successive " << ch << " in position " << i+1 << '\n';
			return 0;
		}
	cout << "There aren't three successive " << ch << '\n';
	return 0;
}

