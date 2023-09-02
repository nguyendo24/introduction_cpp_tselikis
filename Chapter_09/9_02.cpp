#include <iostream> // ’σκηση 9.2
using namespace std;

int main()
{
	char ch1, ch2;

	cout << "Enter characters: ";
	cin >> noskipws >> ch1 >> ch2;

	if(ch1 < ch2)
	{
		ch1++;
		while(ch1 != ch2)
		{
			cout << ch1;
			ch1++;
		}
	}
	else
	{
		ch2++;
		while(ch2 != ch1)
		{
			cout << ch2;
			ch2++;
		}
	}
	return 0;
}

