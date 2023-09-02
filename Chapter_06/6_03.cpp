#include <iostream> // Άσκηση 6.3
using std::cout;
using std::cin;

int main()
{
	int i, num; 
	unsigned long long int fact;

	cout << "Enter number: ";
	cin >> num;

	if(num >= 0)
	{
		fact = 1; /* Θέτουμε αρχική τιμή ίση με το ένα, για να γίνει σωστά ο υπολογισμός του παραγοντικού. */
		for(i = 1; i <= num; i++)
			fact = fact*i;
		/* Σε περίπτωση που ο χρήστης εισάγει την τιμή 0, τότε ο βρόχος δεν θα εκτελεστεί, γιατί η συνθήκη (i <= num) είναι ψευδής (i=1 και num=0). Επομένως, η τιμή που θα εμφανιστεί θα είναι η αρχική τιμή της fact, δηλαδή 1, η οποία είναι και σωστή αφού 0! = 1. */
		cout << "Factorial of " << num << " is " << fact << '\n';
	}
	else
		cout << "Error: Number should be >= 0\n"; 
	return 0;
}

