#include <iostream> // ’σκηση Κ.11.38

void f(int num);

int main()
{
	f(3);
	return 0; 
}

void f(int num)
{
	int i;

	if(num >= 1)
	{
		std::cout << '\n';
		for(i = 0; i < num; i++)
			std::cout << "One ";
		f(num/2);
		std::cout << "\n***";
		f(num/2);
	}
}

