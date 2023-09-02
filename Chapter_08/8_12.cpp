#include <iostream> // ’σκηση 8.12
int main()
{
	const int SIZE = 50;
	float *ptr, arr[SIZE];

	ptr = arr;
	while(ptr < arr+SIZE)
	{
		std::cout << "Enter grade: ";
		std::cin >> *ptr;
		ptr++;
	}
	ptr--;
	while(ptr >= arr)
	{
		std::cout << *ptr << '\n';
		ptr--;
	}
	return 0;
}

