#include <iostream> // ’σκηση 3.3 
using std::cout;
using std::cin;
int main()
{
	double i, j;

	cout << "Enter two positives: ";
	cin >> i >> j;
	cout << (int)i+(int)j << ' ' << (i-(int)i) + (j-(int)j) << '\n';
	return 0;
}

