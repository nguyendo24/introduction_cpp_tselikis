#include <iostream> // ’σκηση 8.2
int main()
{
	int *ptr1, *ptr2, *ptr3, i = 0, j = 1, k = 2;

	ptr1 = &i;
	i = *ptr1 ? 3 : 4;

	ptr2 = &j;
	j = *ptr2 + *ptr1;

	ptr3 = &k;
	k = *ptr3 + *ptr2;
	std::cout << *ptr1 << ' ' << *ptr2 << ' ' << *ptr3 << '\n';
	return 0;
}

