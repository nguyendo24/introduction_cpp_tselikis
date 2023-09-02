#include <iostream> // ’σκηση 6.1
int main()
{
	int i = 2;
	unsigned int j = 2;

	for(i > j; i && (i+j == 4); i--, j++)
		std::cout << i << ' ';
		std::cout << j << ' ';

	for(j = i; j >= 0; j--)
		std::cout << "\nOne";
	return 0;
}

