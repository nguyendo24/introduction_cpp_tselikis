namespace A
{
	int add(int a, int b);
	int sub(int a, int b);
} 

// Αρχείο κώδικα
#include <iostream> // ’σκηση 25.2
#include "code.h" 

namespace A // Πρόσθεση ορισμών
{ 
	int add(int a, int b)
	{
		return a+b;
	}
	int sub(int a, int b)
	{
		return a-b;
	}
}

int main()
{
	int a, b;

	std::cin >> a >> b;
	std::cout << A::add(a, b) << ' ' << A::sub(a, b) << '\n';
	return 0;
}

