#include <iostream> // ’σκηση 12.2
using std::cout;
using std::cin;

const int SIZE = 10;

int num_occurs(const int arr[]);

int main()
{
	int i, arr[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		cout << "Enter number: ";
		cin >> arr[i];
	}
	cout << "\nMax occurrences is " << num_occurs(arr) << '\n';
	return 0;
}

int num_occurs(const int arr[])
{
	int i, j, k, max_times;

	max_times = 1;
	for(i = 0; i < SIZE; i++)
	{
		k = 1; // Κάθε αριθμός εμφανίζεται μία φορά τουλάχιστον.
		for(j = i+1; j < SIZE; j++) /* Συγκρίνουμε το arr[i] με τα υπόλοιπα στοιχεία του πίνακα. */
		{
			if(arr[i] == arr[j]) 
				k++; 
		}
		if(k > max_times)
			max_times = k;
	}
	return max_times;
}

