#include <iostream> // ’σκηση 14.6
#include <cstring>
using std::cout;
using std::cin;

const int SIZE = 100;

int main()
{
	char *ptr[SIZE], str[100];
	int i, pos, len, max_len; /* Η μεταβλητή pos δηλώνει το στοιχείο του πίνακα ptr που δείχνει στο μεγαλύτερο αλφαριθμητικό. Το μήκος του αποθηκεύεται στη μεταβλητή max_len. */
	pos = max_len = 0; 
	for(i = 0; i < SIZE; i++)
	{
		cout << "Enter text: ";
		cin.getline(str, sizeof(str));
		len = strlen(str);
		// Για κάθε δείκτη δεσμεύουμε την απαιτούμενη μνήμη.  
		ptr[i] = new char[len+1];
		/* Αποθήκευση του αλφαριθμητικού στη μνήμη που δεσμεύτηκε για τον αντίστοιχο δείκτη. */
		strcpy(ptr[i], str);
		/* Συγκρίνουμε το μήκος κάθε αλφαριθμητικού με την τιμή της max_len και αν βρεθεί ένα αλφαριθμητικό με μεγαλύτερο μήκος αποθηκεύουμε στην pos τη θέση του δείκτη και στην max_len το μήκος του. */
		if(len > max_len)
		{
			pos = i;
			max_len = len;
		}
	}
	cout << "Longer string: " << ptr[pos] << '\n';
	for(i = 0; i < SIZE; i++)
		delete[] ptr[i];
	return 0;
}

