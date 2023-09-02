#include <iostream> // ’σκηση 12.10

const int SIZE = 5;

void bubble_sort(int arr[]);

int main()
{
	int i, a[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		std::cout << "Enter number: ";
		std::cin >> a[i];
	}
	bubble_sort(a);

	std::cout << "\n***** Sorted array *****\n";
	for(i = 0; i < SIZE; i++)
		std::cout << a[i] << '\n';
	return 0;
}

void bubble_sort(int arr[])
{
	bool reorder;
	int i, j, tmp;

	for(i = 1; i < SIZE; i++)
	{
		reorder = 0;
		for(j = SIZE-1; j >= i; j--)
		{
			if(arr[j] < arr[j-1])
			{
				// Αντιμετάθεση τιμών. 
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
				reorder = 1;
			}
		}
		if(reorder == 0)
			return;
	}
}

