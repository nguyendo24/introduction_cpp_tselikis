#include <iostream> // ’σκηση 7.7
using std::cout;
using std::cin;

int main()
{
	const int SIZE = 50;
	bool found;
	int i, j, pos, num, code[SIZE];

	pos = 0;
	while(pos < SIZE)
	{
		cout << "Enter code: ";
		cin >> num;
		if(num == -1)
			break;

		found = 0;
		/* Η μεταβλητή pos μετράει πόσοι κωδικοί έχουν καταχωρηθεί στον πίνακα, οπότε ο επόμενος βρόχος ελέγχει αν ο εισαγόμενος κωδικός υπάρχει ήδη στον πίνακα. Αν υπάρχει, η μεταβλητή found γίνεται 1 και ο βρόχος τερματίζεται. */
		for(j = 0; j < pos; j++)
		{
			if(code[j] == num)
			{
				cout << "Error: Code " << num << " exists.\n";
				found = 1;
				break; 
			}
		}
		/* Αν ο κωδικός δεν υπάρχει στον πίνακα, τον αποθηκεύουμε και αυξάνουμε τον δείκτη θέσης κατά ένα. */
		if(found == 0)
		{
			code[pos] = num;
			pos++;
		}
	}
	cout << "\nCodes: ";
	for(i = 0; i < pos; i++)
		cout << code[i] << '\n';
	return 0;
}

