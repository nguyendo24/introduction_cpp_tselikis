#include <iostream> // ’σκηση 5.10
using std::cout;
using std::cin;

int main()
{
	char ch;
	int a1, a2, a3, a4, b1, b2, b3, b4;

	cout << "Enter first IP address: ";
	cin >> a1 >> ch >> a2 >> ch >> a3 >> ch >> a4;

	cout << "Enter second IP address: ";
	cin >> b1 >> ch >> b2 >> ch >> b3 >> ch >> b4;

	if(a1 < 128)
	{
		if(a1 == b1)
			cout << "Same network\n";
		else
			cout << "Different networks\n";
	}
	else if(a1 < 192)
	{
		if(a1 == b1 && a2 == b2)
			cout << "Same network\n";
		else
			cout << "Different networks\n";
	}
	else if(a1 < 256)
	{
		if(a1 == b1 && a2 == b2 && a3 == b3)
			cout << "Same network\n";
		else
			cout << "Different networks\n";
	}
	return 0;
}

