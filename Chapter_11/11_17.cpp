#include <iostream> // ’σκηση 11.17

int *test(int *p1, int *p2);

int main()
{
	int arr[] = {1, 2, 3, 4};

	*test(arr, arr+3) = 30;
	std::cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << arr[3] << '\n';
	return 0;
}

int *test(int *p1, int *p2)
{
	*(p1+1) = 10; 
	*(p2-1) = 20; 
	return p1+3;
}

