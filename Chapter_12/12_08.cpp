#include <iostream> // ’σκηση 12.8
#include <iomanip>
#include <cstdlib>  
#include <ctime> 
using namespace std;

const int ROWS = 4;
const int COLS = 5;

void sort_rows(int arr[][COLS]);
void sort_cols(int arr[][COLS]);

int main()
{
	int i, j, type, arr[ROWS][COLS];

	srand(time(NULL)); 
	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
			arr[i][j] = rand();

	cout << "Enter sort type (1: rows): ";
	cin >> type;
	if(type == 1) // Καλούμε την αντίστοιχη συνάρτηση.
		sort_rows(arr);
	else
		sort_cols(arr);

	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
			cout << setw(10) << arr[i][j];
		cout << '\n';
	}
	return 0;
}

void sort_rows(int arr[][COLS])
{
	int i, j, k, tmp;

	for(i = 0; i < ROWS; i++)
	{ 
		for(j = 0; j < COLS-1; j++)
		{
			for(k = j+1; k < COLS; k++)
			{
				if(arr[i][j] > arr[i][k])
				{
					tmp = arr[i][j];
					arr[i][j] = arr[i][k];
					arr[i][k] = tmp;
				}
			}
		}
	}
}

void sort_cols(int arr[][COLS])
{
	int i, j, k, tmp;

	for(j = 0; j < COLS; j++)
	{ 
		for(i = 0; i < ROWS-1; i++)
		{
			for(k = i+1; k < ROWS; k++)
			{
				if(arr[i][j] < arr[k][j])
				{
					tmp = arr[i][j];
					arr[i][j] = arr[k][j];
					arr[k][j] = tmp;
				}
			}
		}
	}
}

