#include <iostream> // ’σκηση 11.37

int unknown(int num1, int num2);

int main()
{
	int num1, num2, sign;

	std::cout << "Enter numbers: ";
	std::cin >> num1 >> num2;
	sign = 1;
	if((num1 < 0) && (num2 > 0))
	{
		num1 = -num1;
		sign = -1;
	}
	else if((num1 > 0) && (num2 < 0))
	{
		num2 = -num2;
		sign = -1;
	}
	else if((num1 < 0) && (num2 < 0))
	{
		num1 = -num1;
		num2 = -num2;
	}
	if(num1 > num2)
		std::cout << sign*unknown(num1, num2) << '\n';
	else
		std::cout << sign*unknown(num2, num1) << '\n';
	return 0;
}

int unknown(int n1, int n2)
{
	if(n2 == 1)
		return n1;
	else
		return n1 + unknown(n1, n2-1);
}

