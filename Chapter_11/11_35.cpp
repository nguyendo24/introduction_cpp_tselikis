#include <iostream> // ’σκηση 11.35

unsigned long long int fact(int num);

int main()
{
	int num;

	do
	{
		std::cout << "Enter a positive integer: ";
		std::cin >> num;
	} while(num < 0);

	std::cout << "Factorial of " << num << " is " << fact(num) << '\n';
	return 0;
}

unsigned long long int fact(int num)
{
	if((num == 0) || (num == 1))
		return 1;
	else
		return num * fact(num-1);
}

