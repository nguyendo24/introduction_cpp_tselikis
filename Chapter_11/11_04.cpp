#include <iostream> // ’σκηση 11.4

int f(int a);

int main()
{
	int i = 10;

	std::cout << f(3-f(2*f(i+1))) << '\n';
	return 0;
}

int f(int a)
{
	return a+1;
}

