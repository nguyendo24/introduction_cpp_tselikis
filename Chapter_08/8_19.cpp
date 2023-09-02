#include <iostream> // ’σκηση 8.19
int main()
{
	int *p[3], i, arr[4] = {10, 20, 30, 40};

	for(i = 0; i < 3; i++)
	{
		p[i] = &arr[i]+1;
		std::cout << *p[i] << ' ';
	}
	return 0;
}

