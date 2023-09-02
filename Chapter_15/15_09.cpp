#include <iostream> // ’σκηση 15.9

#define max(a, b) ((a) > (b) ? (a) : (b)) 

int main()
{
	int i, j, k, l;

	std::cout << "Enter numbers: ";
	std::cin >> i >> j >> k >> l;
	std::cout << max(max(max(i, j), k), l) << '\n';
	return 0;
}

