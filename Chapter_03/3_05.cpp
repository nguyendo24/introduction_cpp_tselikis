#include <iostream> // ’σκηση 3.5 
using std::cout;
using std::cin;

int main()
{
	int i;

	cout << "Enter number between 100 and 999: ";
	cin >> i;

	i = 100*(i%10) + 10*(i%100/10) + i/100;
	cout << i << '\n';
	return 0;
}

