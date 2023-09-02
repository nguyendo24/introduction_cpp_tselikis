#include <iostream> // ’σκηση 8.4
int main()
{
	int *ptr1, *ptr2, i = 10, j = 20;
	
	ptr1 = &i;
	ptr2 = &j;

	ptr2 = ptr1;
	*ptr1 = *ptr1 + *ptr2;
	*ptr2 *= 2;
	std::cout << *ptr1 + *ptr2 << '\n';
	return 0;
}

