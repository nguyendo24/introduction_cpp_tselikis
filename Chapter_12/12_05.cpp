#include <iostream> // ’σκηση 12.5

void sel_sort(double arr[]);

const int SIZE = 10;

int main()
{
	int i;
	double grd[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		std::cout << "Enter grade of stud_" << i+1 << ": ";
		std::cin >> grd[i];
	}
	sel_sort(grd);

	std::cout << "\n***** Sorted array *****\n";
	for(i = 0; i < SIZE; i++)
		std::cout << grd[i] << '\n';
	return 0;
}

void sel_sort(double arr[])
{
	int i, j; 
	double tmp;

	for(i = 0; i < SIZE-1; i++)
	{
		for(j = i+1; j < SIZE; j++)
		{
			if(arr[i] > arr[j])
			{
				// Αντιμετάθεση τιμών. 
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

