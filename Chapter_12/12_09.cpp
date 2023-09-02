#include <iostream> // ’σκηση 12.9

const int SIZE = 5;

void insert_sort(int arr[]);

int main()
{
	int i, a[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		std::cout << "Enter number: ";
		std::cin >> a[i];
	}
	insert_sort(a);
	std::cout << "\n***** Sorted array *****\n";
	for(i = 0; i < SIZE; i++)
		std::cout << a[i] << '\n';
	return 0;
}

void insert_sort(int arr[])
{
	int i, j, tmp;
	for(i = 1; i < SIZE; i++)
	{
		tmp = arr[i];
        	j = i;
        	while((j > 0) && (arr[j-1] > tmp))
        	{
			arr[j] = arr[j-1]; /* Μετακίνηση του στοιχείου κατά μία θέση δεξιά. */
			j--;
        	}
        	arr[j] = tmp;
	}
}

