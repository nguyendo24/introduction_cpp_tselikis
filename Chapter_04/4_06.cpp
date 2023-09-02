#include <iostream> // ’σκηση 4.6
using std::cout;
using std::cin;

int main()
{
	unsigned int num, pos;

	cout << "Enter number: ";
	cin >> num;

	cout << "Enter bit position [1-32]: ";
	cin >> pos;

	cout << "bit" << pos << " is " << ((num >> (pos-1)) & 1) << '\n';
	return 0;
}

