#include <iostream> // ’σκηση 6.4 
using std::cout;
using std::cin;

int main()
{
	int i, n, sum;

	for(;;) // Δημιουργία ατέρμονου βρόχου.
	{
		cout << "Enter number > 0: ";
		cin >> n;
		if(n > 0)
			break; /* Αν ο χρήστης εισάγει θετικό ακέραιο ο ατέρμονος βρόχος τερματίζεται. */
	}
	sum = 0; /* Θέτουμε αρχική τιμή ίση με το μηδέν, για να γίνει σωστά ο υπολογισμός του αθροίσματος. */
	for(i = 1; i <= 2*n-1; i+=2)
		sum += i;
	if(sum == n*n)
		cout << "Verified\n";
	else
		cout << "Not Verified\n";
	return 0;
}

