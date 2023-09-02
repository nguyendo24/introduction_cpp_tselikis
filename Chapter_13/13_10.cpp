#include <iostream> // ’σκηση 13.10
#include <cstdlib>  
#include <ctime> 
using std::cout;
using std::cin;

const int ROWS = 3;
const int COLS = 5;

struct Pixel // RGB μορφή (Red-Green-Blue). 
{
	unsigned char red; // Τιμή στο [0, 255]. 
	unsigned char green; 
	unsigned char blue; 
};

void rotate_right_90(const Pixel img[][COLS], Pixel tmp[][ROWS]);

int main()
{
	int i, j;
	Pixel img[ROWS][COLS], tmp[COLS][ROWS];

	srand(time(NULL));
	// Δημιουργία τυχαίων χρωμάτων.  
	for(i = 0; i < ROWS; i++) 
	{
		for(j = 0; j < COLS; j++) 
		{
			img[i][j].red = rand()%256;
			img[i][j].green = rand()%256;
			img[i][j].blue = rand()%256;
		}
	}
	cout << "*** Original Image ***\n\n";
	for(i = 0; i < ROWS; i++) 
	{
		for(j = 0; j < COLS; j++) 
		{
			cout << '(' << (int)img[i][j].red << ',' <<  (int)img[i][j].green << ',' <<  (int)img[i][j].blue << ") ";
		}
		cout << '\n';	
	}
	rotate_right_90(img, tmp); // Περιστροφή εικόνας.

	cout << "\n*** Rotated Image ***\n\n";
	for(i = 0; i < COLS; i++) 
	{
		for(j = 0; j < ROWS; j++) 
		{
			cout << '(' << (int)tmp[i][j].red << ',' <<  (int)tmp[i][j].green << ',' <<  (int)tmp[i][j].blue << ") ";
		}
		cout << '\n';
	}
	return 0;
}

void rotate_right_90(const Pixel img[][COLS], Pixel tmp[][ROWS])
{
	int i, j, k = 0;

	for(i = ROWS-1; i >= 0; i--)
	{
		for(j = 0; j < COLS; j++)
		{
			tmp[j][i] = img[k][j];
		}
		k++;
	}
}

