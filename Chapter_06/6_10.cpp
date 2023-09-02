#include <iostream> // ’σκηση 6.10
using std::cout;
using std::cin;

int main()
{
	int i, num; 

	cout << "Enter number (>1): ";
	cin >> num;

	if(num > 1)
	{
		if(num % 2 == 0)
		{
			if(num == 2)
				cout << num << " is prime\n";
			else
				cout << num << " is not prime\n";
			return 0; 
		}
		for(i = 3; i <= num/2; i+=2)
		{
			if(num % i == 0)
			{
				cout << num << " is not prime\n";
				return 0; /* Αφού βρήκαμε έναν διαιρέτη, δεν χρειάζεται να ψάξουμε και για άλλους διαιρέτες, οπότε το πρόγραμμα τερματίζεται άμεσα. */
			}
		}
		cout << num << " is prime\n";
	}
	else
		cout << "Error: Not valid number\n"; 
	return 0;
}

