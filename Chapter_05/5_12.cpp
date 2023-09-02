#include <iostream> // ’σκηση 5.12
int main()
{
	float i, j, k; 

	std::cout << "Enter prices: ";
	std::cin >> i >> j >> k;

	std::cout << "Max: " << ((i >= j && i >= k) ? i : (j > i && j > k) ? j : k) << '\n';
	return 0;
}

