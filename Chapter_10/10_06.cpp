#include <iostream> // ’σκηση 10.6
int main()
{
	char *p, *q, s[] = "play";

	p = s+1;
	q = s;
	p[1] = 'x';
	*s = 'a';
	std::cout << *q+2 << " " << *(q+2) << '\n';
	return 0;
}

