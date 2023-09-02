#include <iostream> // ’σκηση 4.2 
int main()
{
	int a = -2, b = 2, c;

	c = ((a+b) == !b);
	a = -((a < c) || (--b == c));
std::cout << (!(a != -c) && (b+a >= c) && ((a+c)%2 || (-a+c-b))) << '\n';
	return 0;
}

