#include <iostream> // ’σκηση 6.5 
int main()
{
	unsigned char i;

	for(i = 4; (i && i-2) ? i+1 : 0; i--)
		std::cout << (int)i << '\n';
	for(; ++i;)
		std::cout << (int)i << '\n';
	return 0;
}

