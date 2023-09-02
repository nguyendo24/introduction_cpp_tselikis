#include <iostream> // ’σκηση Κ.7.13
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	const int ROWS = 6;
	const int COLS = 8;
	int i, j, a, b, max, tmp, type, arr[ROWS][COLS];

	srand(time(NULL)); 
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			arr[i][j] = rand()%21; 
			cout << setw(5) << arr[i][j];
		}
		cout << '\n'; /* Χρησιμοποιείται για την εμφάνιση της κάθε γραμμής του πίνακα σε ξεχωριστή γραμμή. */
	}
	cout << "Enter swap type (1:rows): "; 
	cin >> type;
	if(type == 1)
		max = ROWS;
	else
		max = COLS;
	do
	{
		cout << "Enter dim_1[1-" << max << "]: "; 
		cin >> a;
	} while(a < 1 || a > max);

	do
	{
		cout << "Enter dim_2[1-" << max << "]: "; 
		cin >> b;
	} while(b < 1 || b > max);
		
	a--; // Αφαιρούμε 1, γιατί η αρίθμηση αρχίζει από το 0.
	b--;
	if(type == 1)
	{
		for(i = 0; i < COLS; i++)
		{
			tmp = arr[a][i];
			arr[a][i] = arr[b][i];
			arr[b][i] = tmp;
		}
	}
	else
	{
		for(i = 0; i < ROWS; i++)
		{
			tmp = arr[i][a];
			arr[i][a] = arr[i][b];
			arr[i][b] = tmp;
		}
	}
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
			cout << setw(5) << arr[i][j];
		cout << '\n'; 
	}
	return 0;
}

