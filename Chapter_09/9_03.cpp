#include <iostream> // ’σκηση 9.3
using namespace std;
int main()
{
	char ch, last_ch; 
	int sum1, sum2;

	last_ch = sum1 = sum2 = 0;
	while(1)
	{
		cout << "Enter character: ";
		cin >> noskipws >> ch;

		if(last_ch == ':' && ch == 'q') /* Αν ο τελευταίος χαρακτήρας που εισήγαγε ο χρήστης είναι ο ':' και αυτός που εισήγαγε τώρα είναι ο 'q', η εισαγωγή χαρακτήρων τερματίζει. */
			break;
		else if(ch >= 'a' && ch <= 'z')
			cout << (char)(ch-32) << '\n'; /* Εμφάνιση αντίστοιχου κεφαλαίου χαρακτήρα. */
		else
			cout << ch << '\n';

		last_ch = ch; /* Στη μεταβλητή last_ch αποθηκεύεται ο τελευταίος χαρακτήρας που εισήγαγε ο χρήστης. */
		if(ch == 'w')
			sum1++;
		else if(ch == 'x')
			sum2++;
		cin.get(); /* Διαβάζουμε τον χαρακτήρα '\n' που έχει παραμείνει στην ουρά εισόδου όταν ο χρήστης πάτησε Enter. */
	}
	cout << "w:" << sum1 << " times and x:" << sum2 << " times\n";
	return 0;
}

