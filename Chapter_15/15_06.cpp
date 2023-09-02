#include <iostream> // ’σκηση 15.6
#include <cstring>

#define f(text) std::cout << text; if(strlen(text) < 5) return 0;

int main()
{
	f("One");
	f("Two");
	f("Three");
	return 0;
}

