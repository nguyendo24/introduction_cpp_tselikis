#include <iostream> // ’σκηση 15.5
int main()
{
#if !defined(VER_1) && !defined(VER_2)
	std::cout << "One\n";
#elif defined(VER_3) || defined(VER_4)
	std::cout << "Two\n";
#else
	std::cout << "Three\n";
#endif
	return 0;
}

