#include <iostream> // ’σκηση 6.6 
int main()
{
	int i, j, min, max, sum; 

	std::cout << "Enter numbers: ";
	std::cin >> i >> j;

	if(i < j)
	{
		min = i;
		max = j;
	}
	else
	{
		min = j;
		max = i;
	}
	sum = 0;
	for(i = min+1; i < max; i++)
		sum += i;

	std::cout << "Sum: " << sum << '\n'; 
	return 0;
}

