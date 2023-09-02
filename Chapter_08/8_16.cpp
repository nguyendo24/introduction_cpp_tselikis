#include <iostream> // ’σκηση 8.16
using std::cout;
using std::cin;

int main()
{
	const int SIZE = 100;
	int *p1, *p2, arr[SIZE];

	p1 = arr; 
	while(p1 < arr+SIZE)
	{
		cout << "Enter code_" << p1-arr+1 << ": ";
		cin >> *p1;
		if(*p1 == -1)
			break;

		for(p2 = arr; p2 < p1; p2++) /* Ξεκινώντας από την αρχή του πίνακα, ελέγχουμε αν ο κωδικός έχει ήδη αποθηκευτεί. */
		{
			if(*p1 == *p2)
			{
				cout << "Error: Code " << *p1 << " exists " << '\n';
				break;
			}
		}
		/* Αν ο κωδικός δεν υπάρχει στον πίνακα αυξάνουμε τον δείκτη. */
		if(p2 == p1)
			p1++;
	}
	// Εμφάνιση κωδικών. 
	for(p2 = arr; p2 < p1; p2++)
		cout << "C:" << *p2 << '\n';
	return 0;
}

