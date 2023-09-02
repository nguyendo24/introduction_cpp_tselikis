#include <iostream> // ’σκηση 11.28
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;

const int ROWS = 4;
const int COLS = 4;

void init_board(int cards[][COLS]);
void shuffle_board(int cards[][COLS]);
void show_board(const int cards[][COLS], const int st[][COLS]);
void sel_card(int st[][COLS], int *row, int *col);

int main(void)
{
	int i, j, r1, c1, r2, c2, open, tries, cards[ROWS][COLS], status[ROWS][COLS] = {0}; /* Ο πίνακας status δηλώνει αν μία κάρτα είναι ανοικτή ή κλειστή (0 είναι για κλειστή). */

	open = tries = 0; 
	init_board(cards); // Αρχικοποίηση πίνακα. 
	shuffle_board(cards); /* Τώρα, ανακατεύουμε τις κάρτες, ώστε οι αριθμοί να τοποθετηθούν σε τυχαίες θέσεις. */
	while(1) 
	{
		if(open == ROWS*COLS) /* Το παιχνίδι τερματίζει όταν όλες οι κάρτες ανοίξουν. */
			break;

		sel_card(status, &r1, &c1);
		cout << "Card_1 = " << cards[r1][c1] << '\n';
		
		sel_card(status, &r2, &c2);
		cout << "Card_2 = " << cards[r2][c2] << '\n';

		for(i = 0; i < 20; i++) /* Κενές γραμμές για να διαγράψουμε το ιστορικό των προσπαθειών και να το κάνουμε δυσκολότερο για τον πάικτη να θυμηθεί τις θέσεις των καρτών. */
			cout << '\n';

		if(cards[r1][c1] == cards[r2][c2])
		{
			cout << "Cards matched !!!\n\n";
			open += 2;
		}
		else
		{
			cout << "Sorry. No match !!!\n";
			status[r1][c1] = status[r2][c2] = 0; /* Κλείνουμε πάλι τις κάρτες. */
		}
		tries++;
		show_board(cards, status);
	}
	cout << "Congrats: You did it in " << tries << " tries\n";
	return 0;
}

void init_board(int cards[][COLS])
{
	int i, j, r;

	for(i = r = 0; i < ROWS; i++) /* Εκχωρούμε τις τιμές 1 έως 8, διαδοχικά. */
	{
		for(j = 0; j < COLS; j+=2)
		{
			cards[i][j] = cards[i][j+1] = r+1;
			r++;
		}
	}
}

void shuffle_board(int cards[][COLS])
{
	int i, j, c, m, r;

	srand(time(NULL));
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			c = cards[i][j];
			m = rand()%ROWS;
			r = rand()%COLS;
			cards[i][j] = cards[m][r];
			cards[m][r] = c;
		}
	}
}

void show_board(const int cards[][COLS], const int st[][COLS])
{
	int i, j;
	
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			if(st[i][j] == 1)
				cout << cards[i][j] << ' ';
			else
				cout << "* ";
		}
		cout << '\n';
	}
}

void sel_card(int st[][COLS], int *row, int *col)
{
	while(1)
	{
		cout << "Enter row and column: ";
		cin >> *row >> *col;

		(*row)--; /* Αφαιρούμε το 1, γιατί η μέτρηση στους πίνακες αρχίζει από το 0. */
		(*col)--;
		if(*row >= ROWS  || *row < 0 || *col >= COLS || *col < 0)
		{
			cout << "Out of bound dimensions\n";
			continue;
		}
		if(st[*row][*col] == 1)
		{
			cout << "Error: This card is already flipped\n";
			continue;
		}
		st[*row][*col] = 1; // Ανοίγουμε την κάρτα. 
		return;
	}
}

