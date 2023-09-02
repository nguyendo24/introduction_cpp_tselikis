#include <iostream> // ’σκηση 7.9
#include <cstdlib>
#include <ctime>
int main()
{
	const int SIZE = 10;
	int i, j, k, size, arr[SIZE];

	srand(time(NULL)); 
	for(i = 0; i < SIZE; i++)
		arr[i] = rand()%16+5; 

	size = SIZE;
	for(i = 0; i < size; i++)
	{
		j = i+1;
		while(j < size)
		{
			if(arr[i] == arr[j])
			{
				for(k = j; k < size-1; k++)
 					arr[k] = arr[k+1]; /* Μετακίνηση των στοιχείων μία θέση αριστερά. */
				size--; /* Αφού διαγράφηκε το στοιχείο, μειώνουμε τον αριθμό τους. */
			}
			else
				j++;
		}
	}	
	for(i = size; i < SIZE; i++)
		arr[i] = -1;
	for(i = 0; i < SIZE; i++)
		std::cout << arr[i] << ' ';
	return 0;
}

