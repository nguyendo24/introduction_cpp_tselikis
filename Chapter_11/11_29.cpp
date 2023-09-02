#include <iostream> // ’σκηση 11.29
int main(int argc, char *argv[])
{
	while(--argc)
		(argc > 1) ? std::cout << *++argv << ' ' : std::cout << *++argv << '\n'; 
	return 0;
}

