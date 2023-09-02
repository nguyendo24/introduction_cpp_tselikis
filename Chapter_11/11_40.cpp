#include <iostream> // ’σκηση 11.40

int collatz(int n);

int main()
{
	int a;

	do
	{
		std::cout << "Enter a positive integer: ";
		std::cin >> a;
	} while(a <= 0);
	
	std::cout << "The result is " << collatz(a) << " indeed!!!\n";
	return 0;
}

int collatz(int n) 
{
	std::cout << n << '\n';
	if(n == 1) 
		return 1;
	else if(n & 1) // Αν ο n είναι περιττός. 
		return collatz(3*n+1);
	else // Αν ο n είναι άρτιος. 
		return collatz(n/2);
}

