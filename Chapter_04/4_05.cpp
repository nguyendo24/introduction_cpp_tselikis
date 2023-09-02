#include <iostream> // ’σκηση 4.5 
using std::cout;

int main()
{
	unsigned int i = ~(~0 << 3);

	if(i >> 3)
		cout << "One\n";
	else
		cout << "Two\n";

	if((i << 2) == 28)
		cout << "One\n";
	else
		cout << "Two\n";

	cout << i << '\n';
	return 0;
}

