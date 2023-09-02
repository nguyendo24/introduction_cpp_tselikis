#include <iostream> // ’σκηση 15.8

#define hide(t, r, a, p, i, n) p##a##r##t(i, n)

double show(int a, int b);

int main()
{
	std::cout << (int)hide(w, o, h, s, 1, 2) << '\n';
	return 0;
}

double show(int a, int b)
{
	return (a+b)/2.0;
}

