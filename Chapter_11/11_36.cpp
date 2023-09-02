#include <iostream> // ’σκηση 11.36

unsigned int fib(int num);

int main()
{
	int num;

	do
	{
		std::cout << "Enter a number between 0 and 40: ";
		std::cin >> num;
	} while(num < 0 || num > 40);

	std::cout << "Fib(" << num << ") = " << fib(num) << '\n';
	return 0;
}

unsigned int fib(int num)
{
	if(num == 0)
		return 0;
	else if(num == 1)
		return 1;
	else
		return fib(num-1) + fib(num-2);
}

