#include <iostream> // ’σκηση 8.13 
int main()
{
	const int SIZE = 50;
	int *ptr, i, arr[SIZE];

	ptr = arr;
	for(i = 0; i < SIZE; i++)
	{
		std::cout << "Enter number: ";
		std::cin >> *ptr; 

		if(*ptr >= 30 && *ptr <= 40)
			ptr++;
	}
	std::cout << ptr-arr << " elements are stored\n";
	for(; ptr < arr+SIZE; ptr++)
		*ptr = -1;
	return 0;
}


