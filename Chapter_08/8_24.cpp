#include <iostream> // ’σκηση 8.24
int main()
{
	int **p1, **p2, *p3, *p4, i, num, times;

	p3 = &num;
	p1 = &p3;

	p4 = &times;
	p2 = &p4;

	**p2 = 0;
	for(;;)
	{
		std::cout << "Enter number: ";
		std::cin >> **p1;
		if(**p1 == 0)
			break; 
		if(**p1 < 0)
			**p1 = -**p1;
		for(i = 0; i < **p1; i++)
			std::cout << "test\n";
		**p2 += **p1;
	}
	std::cout << "Total number is " << **p2 << '\n';
	return 0;
}

