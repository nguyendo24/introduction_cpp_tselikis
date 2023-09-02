#include <iostream> // Άσκηση 12.7
using std::cout;
using std::cin;

void sel_sort(int arr[], int size);
void add_sort(int arr[], int size, int num);

const int SIZE = 10;
int main()
{
	int i, num, a[SIZE];

	for(i = 0; i < SIZE-1; i++) // Αποθήκευση 9 ακεραίων. 
	{
		cout << "Enter number: ";
		cin >> a[i];
	}
	sel_sort(a, SIZE-1); // Ταξινόμηση των 9 στοιχείων. 

	cout << "Insert number in sorted array: ";
	cin >> num;

	add_sort(a, SIZE-1, num); // Εισαγωγή του ακεραίου στον πίνακα.
	for(i = 0; i < SIZE; i++)
		cout << a[i] << '\n';
	return 0;
}

void add_sort(int arr[], int size, int num)
{
	int i, pos;

	if(num <= arr[0])
		pos = 0;
	else if(num >= arr[size-1]) /* Αν είναι μεγαλύτερος από τον τελευταίο ακέραιο, τον αποθηκεύουμε στην τελευταία θέση και η συνάρτηση επιστρέφει. */
	{
		arr[size] = num; 
		return;
	}
	else 
	{
		for(i = 0; i < size-1; i++)
		{
		/* Βρίσκουμε τη θέση που πρέπει να εισαχθεί ο νέος αριθμός, ελέγχοντας όλα τα διαδοχικά ζευγάρια μέχρι το τελευταίο ζευγάρι που βρίσκεται στις θέσεις [SIZE-3] και [SIZE-2]. */
			if(num >= arr[i] && num <= arr[i+1])
				break;
		}
		pos = i+1;
	}
	for(i = size; i > pos; i--)
		arr[i] = arr[i-1]; /* Οι τιμές των στοιχείων μετακινούνται μία θέση δεξιά, αρχίζοντας από την τελευταία θέση του πίνακα [SIZE-1] μέχρι τη θέση που θα εισαχθεί ο νέος αριθμός. Π.χ. στην τελευταία επανάληψη του βρόχου για i = pos+1, θα γίνει arr[pos+1] = arr[pos]. */
	arr[pos] = num; // Αποθήκευση του νέου αριθμού. 
}

void sel_sort(int arr[], int size)
{
	int i, j, tmp;

	for(i = 0; i < size-1; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				// Αντιμετάθεση τιμών. 
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

