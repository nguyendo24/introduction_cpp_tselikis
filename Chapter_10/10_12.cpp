#include <iostream> // ’σκηση 10.12
#include <string> 
using std::cout;
using std::cin;
using std::string;

int main()
{
	int i, diff, len;
	string str;

	cout << "Enter text: ";
	getline(cin, str);
	len = str.size();

	diff = 0;
	for(i = 0; i < len/2; i++)
	{
		if(str[i] != str[len-1-i]) /* Αν δύο χαρακτήρες δεν είναι ίδιοι ο βρόχος τερματίζεται. */
		{
			diff = 1;
			break;
		}
	}
	if(diff == 1)
		cout << str << " is not a palindrome\n";
	else
		cout << str << " is a palindrome\n";
	return 0;
}

