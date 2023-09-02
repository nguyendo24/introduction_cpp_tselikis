#include <iostream> // ’σκηση 7.4
using std::cout;
using std::cin;

int main()
{
	bool flag;
	int i, dig_times[10] = {0}; /* Σε αυτόν τον πίνακα αποθηκεύεται ο αριθμός εμφανίσεων κάθε ψηφίου. Για παράδειγμα, το dig_times[0] δηλώνει πόσες φορές εμφανίζεται το ψηφίο 0. */
	cout << "Enter number: ";
	cin >> i;
	if(i == 0) // Ελέγχουμε αν ο χρήστης εισήγαγε το 0.
		dig_times[0] = 1;
	else if(i < 0) 
		i = -i;
	while(i != 0)
	{
		dig_times[i%10]++;
		i /= 10;
	}
	flag = 0;
	for(i = 0; i < 10; i++)
	{
		if(dig_times[i] > 1)
		{
			cout << "Digit " << i <<  " appears " << dig_times[i] <<  " times\n";
			flag = 1;
		}
	}
	if(flag == 0)
		cout << "No digit appears multiple times\n";
	return 0;
}

