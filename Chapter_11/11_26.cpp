#include <iostream> // ’σκηση 11.26
using std::cout;
using std::cin;

const int ROWS = 3;
const int COLS = 4;

void find_sums(int arr1[][COLS], int arr2[], int arr3[]);

int main()
{
	int i, j, arr1[ROWS][COLS], arr2[ROWS], arr3[COLS];

	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
		{
			cout << "arr1[" << i << "][" << j << "] = ";
			cin >> arr1[i][j];
		}

	find_sums(arr1, arr2, arr3);
	for(i = 0; i < ROWS; i++)
		cout << "sum_line_" << i << " = " << arr2[i] << '\n';
	for(i = 0; i < COLS; i++)
		cout << "sum_col_" << i << " = " << arr3[i] << '\n';
	return 0;
}

void find_sums(int arr1[][COLS], int arr2[], int arr3[])
{
	int i, j, sum;

	for(i = 0; i < ROWS; i++)
	{
		sum = 0;
		for(j = 0; j < COLS; j++)
			sum += arr1[i][j];
		arr2[i] = sum;
	}
	for(i = 0; i < COLS; i++)
	{
		sum = 0;
		for(j = 0; j < ROWS; j++)
			sum += arr1[j][i];
		arr3[i] = sum;
	}
}

