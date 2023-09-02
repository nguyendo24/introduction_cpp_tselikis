#include <iostream> // ’σκηση 10.10
int main()
{
	const char *str = "Example";
	int *ptr = (int*)str;

	ptr++;
	std::cout << (char*)ptr+3;
	return 0;
}

