#include <iostream> // ’σκηση 12.1 
using std::cout;
using std::cin;

const int SIZE = 100;

int linear_search(const double arr[], int size, double num, int *t);

int main()
{
	int i, times, pos;
	double num, arr[SIZE];

	for(i = 0; i < SIZE; i++)
	{
		cout << "Enter number: ";
		cin >> num;
		if(num == -1)
			break;
		arr[i] = num;
	}
	cout << "Enter number to search: ";
	cin >> num;

	pos = linear_search(arr, i, num, &times); /* Η μεταβλητή i δηλώνει τον αριθμό των στοιχείων του πίνακα. */
	if(pos == -1)
		cout << num << "isn't found\n";
	else
		cout << num << " appears " << times << " times (first pos = " << pos << ")\n"; 
	return 0;
}

int linear_search(const double arr[], int size, double num, int *t)
{
	int i, pos;

	pos = -1;
	*t = 0;
	for(i = 0; i < size; i++)
	{
		if(arr[i] == num)
		{
			(*t)++;
			if(pos == -1) // Αποθήκευση της πρώτης εμφάνισης.
				pos = i;
		}
	}
	return pos;
}

