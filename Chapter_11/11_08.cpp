#include <iostream> // ’σκηση 11.8

void test(int *p1, int *p2);

int main()
{
	int i = 10, j = 20;

	test(&i, &j);
	std::cout << i << ' ' << j << '\n'; 
	return 0;
}
void test(int *p1, int *p2)
{
	int m, *tmp;

	tmp = p1;
	p1 = &m;
	*p1 = 100;

	*p2 += m;
	p2 = tmp;
	*p2 = 100;
}

