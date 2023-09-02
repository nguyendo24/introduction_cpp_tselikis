#include <iostream> // ’σκηση 11.31
#include <cstdarg> 

double find_max(int num, ...);

int main()
{
	double i, j, k;

	std::cout << "Enter numbers: ";
	std::cin >> i >> j >> k;

	std::cout << "Max = " << find_max(3, i, j, k) << '\n';
	return 0;
}

double find_max(int num, ...)
{
	int i;
	double max, tmp;
	va_list arg_ptr;

	va_start(arg_ptr, num); 
	max = va_arg(arg_ptr, double);
	for(i = 1; i < num; i++)
	{
		tmp = va_arg(arg_ptr, double); 
		if(max < tmp)
			max = tmp;
	}
	va_end(arg_ptr); 
	return max;
}

