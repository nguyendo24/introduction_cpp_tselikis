#include <iostream> // ’σκηση 3.4 
using std::cout;
using std::cin;

int main()
{
	int a1, a2, a3, tmp;

	cout << "Enter numbers: ";
	cin >> a1 >> a2 >> a3;

	tmp = a1;
	a1 = a2;
	a2 = tmp;

	tmp = a3;
	a3 = a1;
	a1 = tmp;
	cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
	return 0;
}

