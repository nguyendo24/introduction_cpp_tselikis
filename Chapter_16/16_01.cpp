#include <iostream> // ’σκηση 16.1

void test(int *p, int& r, int a = 2);

int main()
{
	int i = 10, j = 50;

	test(&i, j);
	std::cout << i << ' ' << j << '\n';	
	return 0;
}

void test(int *p, int& r, int a)
{
	*p = r;
	p = &r;
	*p = a;
	r += 20;
}

