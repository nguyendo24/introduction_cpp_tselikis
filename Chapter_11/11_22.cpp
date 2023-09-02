#include <iostream> // ’σκηση 11.22

void swap(const char *s1, const char *s2);

int main()
{
	const char *p[] = {"Shadow", "Play"};

	swap(p[0], p[1]);
	std::cout << p[0] << ' ' << p[1] << '\n';
	return 0;
}

void swap(const char *s1, const char *s2)
{
	const char *p;

	p = s1;
	s1 = s2;
	s2 = p;
}

