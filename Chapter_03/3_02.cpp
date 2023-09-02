#include <iostream> // ’σκηση 3.2 
using std::cout;
using std::cin;

int main()
{
	int i, div;
	double d;

	cout << "Enter positives float and int (#0): ";
	cin >> d >> i; 
	div = d/i; /* Έστω ότι ο χρήστης εισήγαγε τους αριθμούς 5.67 και 3. Αφού η div είναι ακέραια θα γίνει ίση με 1. */
	cout << d - div*i << '\n';
	return 0;
}

