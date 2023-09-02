#include <iostream> // ’σκηση 8.21
int main()
{
	int *p, **pp, i = 10, j = 20;

	p = &i;
	pp = &p;
	**pp = j;

	p = &j;
	**pp += 10;
	std::cout << i+j << '\n';
	return 0;
}

