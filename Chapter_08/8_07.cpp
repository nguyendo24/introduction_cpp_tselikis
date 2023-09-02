#include <iostream> // ’σκηση 8.7
int main()
{
	int *p1, *p2, *p3, i, j, sum;

	p1 = &i;
	p2 = &j;
	p3 = &sum;
	*p3 = 0;
	do
	{
		std::cout << "Enter two numbers (a < b < 100): ";
		std::cin >> *p1 >> *p2;
	} while(*p1 >= *p2 || *p2 > 100);

	(*p1)++;
	while(*p1 < *p2)
	{
		*p3 += *p1;
		(*p1)++;
	}
	std::cout << "Sum: " << *p3 << '\n';
	return 0;
}

