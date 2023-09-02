#include <iostream> // ’σκηση 8.17
int main()
{
	int a[] = {0, 0, 1, 2, 3}, b[] = {0, 0, 0, 4, 5, 6};
	int *ptr1 = a, *ptr2 = b;

	while(!*ptr1++ && !(*++ptr2))
		; 
	std::cout << *(b+(ptr1-a)) << ' ' << *(a+(ptr2-b)) << '\n';
	return 0;
}

