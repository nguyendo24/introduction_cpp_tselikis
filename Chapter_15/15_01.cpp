#include <iostream> // ’σκηση 15.1 

#define abs(a) ((a) >= 0 ? (a) : -(a))

int main()
{
	int i;

	std::cout << "Enter number: ";
	std::cin >> i;
	std::cout << abs(i) << '\n';
	return 0;
}

