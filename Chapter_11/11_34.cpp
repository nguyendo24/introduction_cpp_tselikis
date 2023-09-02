#include <iostream> // ’σκηση 11.34

int unknown(int arr[], int num);

int main()
{
	int arr[] = {10, 20, 30, 40};

	std::cout << unknown(arr, 4) << '\n';
	return 0;
}

int unknown(int arr[], int num)
{
	if(num == 1)
		return arr[0];
	else
		return arr[num-1] + unknown(arr, num-1);
}

