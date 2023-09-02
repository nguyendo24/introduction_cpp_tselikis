#include <iostream> // ’σκηση 7.18
#include <cstdlib>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;

int main()
{
	const int ROWS = 30;
	const int COLS = 20;
	bool seats[ROWS][COLS] = {0}; /* Χρησιμοποιούμε τον πίνακα seats για να διαχειριστούμε τις θέσεις του κινηματογράφου. Αν η τιμή κάποιου στοιχείου είναι 0 σημαίνει ότι η θέση είναι ελεύθερη. */
	int i, j, sel, row, col, rsvd_seats, cost;

	rsvd_seats = cost = 0;
	while(1) 
	{
		cout << "\nMenu selections\n";
		cout << "---------------\n";
		cout << "1. Buy Ticket\n";
		cout << "2. Ticket Refund\n";
		cout << "3. Show Information\n";
		cout << "4. Exit\n";
		cout << "\nEnter choice: ";
		cin >> sel;
		switch(sel)
		{
			case 1:
				if(rsvd_seats == ROWS*COLS)
				{
					cout << "\nSorry, no free seats\n";
					break;
				}
				cout << "\nWould you like a specific seat (No: 0)? ";
				cin >> sel;
				if(sel == 0)
				{
					do
					{
						row = rand() % ROWS; /* Χρησιμοποιούμε την rand() για να επιλέξουμε μία τυχαία θέση. */
						col = rand() % COLS;
					} while(seats[row][col] == 1);
				}
				else
				{
					do
					{
						cout << "\nEnter row [1-" << ROWS << "]: "; 
						cin >> row;
					} while(row < 1 || row > ROWS);

					do
					{
						cout << "Enter seat [1-" << COLS << "]: ";
						cin >> col;
					} while(col < 1 || col > COLS);

					row--; /* Αφαιρούμε 1, γιατί η αρίθμηση αρχίζει από το 0. */
					col--;
				}
				if(seats[row][col] == 1)
					cout << "\nSorry, seat in row_" << row+1 << " and column_" << col+1 << " is reserved\n";
				else
				{
					seats[row][col] = 1;
					cost += 6;
					rsvd_seats++;
				}
			break;

			case 2:
				if(rsvd_seats == 0)
				{
					cout << "\nAll seats are free\n";
					break;
				}
				do
				{
				 cout << "\nEnter row [1-" << ROWS << "]: ";
					cin >> row;
				} while(row < 1 || row > ROWS);
				do
				{
				  cout << "Enter seat [1-" << COLS << "]: ";
					cin >> col;
				} while(col < 1 || col > COLS);

				row--;
				col--;
				if(seats[row][col] != 1)
					cout << "\nSeat in row_" << row+1 << " and column_" << col+1 << " is not reserved\n";
				else
				{
					seats[row][col] = 0;
					cost -= 5;
					rsvd_seats--;
				}
			break;

			case 3:
				cout << "\nFree seats: " << ROWS*COLS - rsvd_seats << " Income: " << cost << "\n\n";
				for(i = 0; i < ROWS; i++)
				{
					for(j = 0; j < COLS; j++)
					{					
						if(seats[i][j] == 1) /* Το X δηλώνει δεσμευμένη θέση. */
							cout << setw(2) << 'X'; 
						else
							cout << setw(2) << '#';
					}
					cout << '\n'; 
				}
			break;

			case 4:
			return 0;

			default:
				cout << "\nWrong choice\n";
			break;
		}
	}
	return 0;
}

