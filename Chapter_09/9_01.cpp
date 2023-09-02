#include <iostream> // ’σκηση 9.1
using namespace std;

int main()
{
	char ch1, ch2, ch3;

	cout << "Enter characters: ";
	cin >> noskipws >> ch1 >> ch2 >> ch3;

	if((ch1+1 == ch2) && (ch2+1 == ch3))
		cout << "Consecutive\n";
	else
		cout << "Not Consecutive\n";
	return 0;
}

