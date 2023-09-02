#include <iostream> // ’σκηση 8.9
using std::cout;
using std::cin;

int main()
{
	const int SIZE = 31;
	int i;
	double tmp, arr[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		cout << "Enter temperatures: ";
		cin >> *(arr+i); 
	}
	cout << "Enter temperature to check: ";
	cin >> tmp;
	for(i = 0; i < SIZE; i++)
	{ /* Τα άγκιστρα δεν χρειάζονται. Τα έβαλα για να διαβάζεται πιο εύκολα ο κώδικας. */
		if(*(arr+i) < tmp)
			break;
	}
	if(i == SIZE)
		cout << "No temperature less than " << tmp << '\n';
	else
		cout << "The first temperature less than " << tmp << " was " << *(arr+i) << " in day " << i+1 << '\n';
	return 0;
}

