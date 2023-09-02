#include <iostream> // ’σκηση 7.17
using std::cout;
using std::cin;

int main()
{
	const int ROWS = 3;
	const int COLS = 3;
	int i, j, sum, tmp, arr[ROWS][COLS];

	sum = tmp = 0;
	for(i = 0; i < ROWS; i++)
	{
		// Βρίσκουμε τα αθροίσματα των στοιχείων των διαγωνίων. 
		for(j = 0; j < COLS; j++)
		{
			cout << "Enter element [" << i << "]" << "[" << j << "]: ";
			cin >> arr[i][j];
			if(i == j)
				sum += arr[i][j];
			if(i+j == ROWS-1) /* Ελέγχουμε αν το στοιχείο βρίσκεται στη δευτερεύουσα διαγώνιο. */
				tmp += arr[i][j];
		}
	}
	if(sum != tmp)
	{
		cout << "Not magic square -> Sum_main_diag: " << sum << "  Sum_sec_diag: " << tmp << '\n';
		return 0;
	}
	for(i = 0; i < ROWS; i++)
	{
		/* Αρχικοποίηση της μεταβλητής που υπολογίζει το άθροισμα των στοιχείων της κάθε γραμμής. */
		tmp = 0;
		for(j = 0; j < COLS; j++)
			tmp += arr[i][j];

		if(sum != tmp)
		{
			cout << "Not magic square -> Sum_row_" << i+1 << ": " << tmp << " Sum_diag: " << sum << '\n';
			return 0;
		}
	}
	for(i = 0; i < COLS; i++)
	{
		tmp = 0; /* Αρχικοποίηση της μεταβλητής που υπολογίζει το άθροισμα των στοιχείων της κάθε στήλης. */
		for(j = 0; j < ROWS; j++)
			tmp += arr[j][i];

		if(sum != tmp)
		{
			cout << "Not magic square -> Sum_col_" << i+1 << ": " << tmp << " Sum_diag: " << sum << '\n';
			return 0;
		}
	}
	cout << "Magic square !!!\n";
	return 0;
}

