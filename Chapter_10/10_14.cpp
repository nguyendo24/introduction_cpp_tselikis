#include <iostream> // ’σκηση 10.14 
#include <string> 
using std::cout;
using std::cin;
using std::string;

int main()
{
	string str;
	int i, len;

	cout << "Enter text: ";
	getline(cin, str);
	len = str.size();

	for(i = 0; i < len; i++)
	{
		if(str[i] == 'a')
			str[i] = ' ';
		else 
			break;
	}
	for(i = len-1; i >= 0; i--)
	{
		if(str[i] == 'a')
			str[i] = ' ';
		else 
			break;
	}
	cout << "New text: " << str << '\n';
	return 0;
}

