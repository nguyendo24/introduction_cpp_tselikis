#include <iostream> // ’σκηση 5.11
int main()
{
	int a = 1, b = !a;

	if((b ? a : -a) <= 10)
		std::cout << "One " << -a << '\n';
	else
		std::cout << "Two " << -a << '\n';
	return 0;
}

