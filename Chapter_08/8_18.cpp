#include <iostream> // ’σκηση 8.18
int main()
{
	int *p[3], i, num;

	for(i = 0; i < 3; i++)
	{
		std::cout << "Enter number: ";
		std::cin >> num;
		p[i] = &num;
	}
	for(i = 0; i < 3; i++)
		std::cout << *p[i] << '\n';
	return 0;
}

