#include <iostream> // ’σκηση Κ.7.14
#include <iomanip>
#include <cstdlib>
#include <ctime>
using std::cout;

int main()
{
	const int ROWS = 5;
	int i, j, up_tr, down_tr, val, arr[ROWS][ROWS];

	val = 1; 
	up_tr = down_tr = 1;

	srand(time(NULL)); 
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < ROWS; j++)
		{
			arr[i][j] = rand()%7 - 3; /* Το αποτέλεσμα rand()%7 είναι ένας ακέραιος στο [0, 6]. Αφαιρώντας 3, ο ακέραιος που προκύπτει ανήκει στο [-3, 3]. */
			cout << std::setw(3) << arr[i][j];
			if(i == j) /* Ελέγχουμε αν το στοιχείο βρίσκεται στην κύρια διαγώνιο. */
				val *= arr[i][j]; 
		}
		cout << '\n'; 
	}
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < ROWS; j++)
		{
			if(i > j) 
			{
				if(arr[i][j] != 0) /* Στον άνω τριγωνικό πίνακα, τα στοιχεία κάτω από την κύρια διαγώνιο είναι μηδέν. */
					up_tr = 0;
			}
			else if(i < j) 
			{
				if(arr[i][j] != 0) /* Στον κάτω τριγωνικό πίνακα, τα στοιχεία πάνω από την κύρια διαγώνιο είναι μηδέν. */
					down_tr = 0;
			}
			if(up_tr == 0 && down_tr == 0) 
				break; /* Δεν χρειάζεται να συνεχίσουμε τον έλεγχο των στοιχείων. */
		}
	}
	if(up_tr && down_tr)
		cout << "\nDiagonal array\n";
	else if(up_tr)
		cout << "\nUpper triangular array\n";
	else if(down_tr)
		cout << "\nDown triangular array\n";
	else
		cout << "\nNo triangular array\n";

	cout << "Main diagonal: " << val << '\n';

	/* Αντιμετάθεση γραμμών και στηλών. */
	for(i = 0; i < ROWS; i++)
	{
		for(j = i; j < ROWS; j++)
		{
			val = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = val;
		}
	}
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < ROWS; j++)
			cout << std::setw(3) << arr[i][j];
		cout << '\n';
	}
	return 0;
}

