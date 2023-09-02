#include <iostream> // ’σκηση 11.16
using std::cout;
using std::cin;

int mcd(int a, int b);

int main()
{
	int num1, num2;

	do
	{
		cout << "Enter the first number: ";
		cin >> num1;

		cout << "Enter the second number (equal or less than the first one): ";
		cin >> num2;
	} while((num2 > num1) || (num1 <= 0) || (num2 <= 0));

	cout << "MCD of " << num1 << " and " << num2 << " is " << mcd(num1, num2) << '\n';
	return 0;
}

int mcd(int a, int b)
{
	int r;

	while(1)
	{
		r = a%b;
		if(r == 0)
			return b;
		else /* Σύμφωνα με τον αλγόριθμο, διαιρούμε τον b με τον r, οπότε αλλάζουμε τις τιμές των a και b αντίστοιχα. */
		{
			a = b;
			b = r;
		}
	}
}

