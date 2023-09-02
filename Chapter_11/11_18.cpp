#include <iostream> // ’σκηση 11.18

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
	unsigned int prev_sum, new_term, sum;

	if(num == 0)
		return 0;
	else if(num == 1)
		return 1;

	prev_sum = 1;
	new_term = 0;

	while(num > 1)
	{
		sum = prev_sum + new_term; // Υπολογίζουμε το άθροισμα.

		new_term = prev_sum;
		prev_sum = sum;

		num--;
	}
	return sum;
}

