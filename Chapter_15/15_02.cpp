#include <iostream> // ’σκηση 15.2

#define odd_even(a) (((a) % 2) != 0)

int main()
{
	int i;

	std::cout << "Enter number: ";
	std::cin >> i;
	if(odd_even(i))
		std::cout << "Odd\n";
	else
		std::cout << "Even\n";
	return 0;
}

