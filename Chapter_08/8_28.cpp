#include <iostream> // ’σκηση 8.28
#include <iomanip>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::setw;
int main()
{
	const int ROWS = 3;
	const int COLS = 5;
	int i, j, min, max, arr[ROWS][COLS];

	srand(time(NULL)); 
	for(i = 0; i < ROWS; i++)
	{
		min = max = *arr[i] = rand();
		for(j = 1; j < COLS; j++)
		{
			*(arr[i]+j) = rand();
			if(*(arr[i]+j) < min) 
				min = *(arr[i]+j);
			if(*(arr[i]+j) > max) 
				max = *(arr[i]+j);
		}
		cout << "Row_" << i+1 << ": Min=" << min << " Max=" << max << '\n';
	}
	for(i = 0; i < COLS; i++)
	{
		min = max = *(arr[0]+i);
		for(j = 1; j < ROWS; j++)
		{
			if(*(arr[j]+i) < min) 
				min = *(arr[j]+i);
			if(*(arr[j]+i) > max) 
				max = *(arr[j]+i);
		}
		cout << "Col_" << i+1 << ": Min=" << min << " Max=" << max << '\n';	
	}
	// Εμφανίζουμε τον πίνακα για επαλήθευση των αποτελεσμάτων. 
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
			cout << setw(10) << *(arr[i]+j);
		cout << '\n'; 
	}
	return 0;
}

