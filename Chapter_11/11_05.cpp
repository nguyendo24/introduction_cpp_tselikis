#include <iostream> // ’σκηση 11.5 

double avg(double a, double b, double c);

int main()
{
	double i, j, k, r;

	std::cout << "Enter numbers: ";
	std::cin >> i >> j >> k;

	r = avg(i, j, k);
	if(r == -1)
		std::cout << "No value in [1, 2]\n";
	else
		std::cout << "Avg:" << r << '\n';
	return 0;
}

double avg(double a, double b, double c)
{
	int k = 0; 
	double sum = 0; 

	if(a <= b && a <= c)
		std::cout << "Min:" << a << '\n';
	else if(b < a && b < c)
		std::cout << "Min:" << b << '\n';
	else
		std::cout << "Min:" << c << '\n';

	if(a >= 1 && a <= 2)
	{
		sum += a;
		k++;
	}
	if(b >= 1 && b <= 2)
	{
		sum += b;
		k++;
	}
	if(c >= 1 && c <= 2)
	{
		sum += c;
		k++;
	}
	if(k != 0)
		return sum/k;
	else
		return -1;
}

