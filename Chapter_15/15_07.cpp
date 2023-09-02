#include <iostream> // ’σκηση 15.7

#define max(a, b, c) ((a) >= (b) && (a) >= (c) ? (a) : \
(b) > (a) && (b) > (c) ? (b) : (c))

int main()
{
	double i, j, k;

	std::cout << "Enter numbers: ";
	std::cin >> i >> j >> k;
	std::cout << max(i, j, k) << '\n';
	return 0;
}

