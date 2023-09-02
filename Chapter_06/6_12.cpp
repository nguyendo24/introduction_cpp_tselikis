#include <iostream> // ’σκηση 6.12 
using std::cout;
using std::cin;

int main()
{
	int i, j, lines;

	cout << "Enter lines: ";
	cin >> lines;

	for(i = 0; i < lines; i++)
	{
		for(j = 0; j < i; j++)
			cout << ' '; 
		for(j = lines; j > i; j--)
			cout << '*';
		cout << '\n'; 
	}
	return 0;
}

