#include <iostream> // ’σκηση 9.6 
using std::cout;
using std::cin;

int main()
{
	char chk_dig;
	int i, ch, sum, tmp;
	sum = 0;	
	cout << "Enter IMEI (15 digits): ";
	for(i = 1; i < 15; i++) // Διαβάζουμε τα 14 πρώτα ψηφία.
	{
		ch = cin.get();
		if((i & 1) == 1) /* Ελέγχουμε αν η θέση του ψηφίου είναι μονή. */
			sum += ch-'0'; /* Για να βρούμε την αριθμητική τιμή του κάθε ψηφίου αφαιρούμε την ASCII τιμή του 0. */
		else // H θέση του ψηφίου είναι άρτια. 
		{
			tmp = 2*(ch-'0');
			if(tmp >= 10)
				tmp = (tmp/10) + (tmp%10); /* Αν ο αριθμός μετά τον διπλασιασμό είναι διψήφιος υπολογίζουμε το άθροισμα των ψηφίων του. */
			sum += tmp;
		}	
	}
	ch = cin.get(); /* Διαβάζουμε και το τελευταίο ψηφίο, δηλαδή το Luhn digit. */
	ch = ch-'0'; 
	chk_dig = sum%10;
	if(chk_dig != 0)
		chk_dig = 10-chk_dig;

	if(ch == chk_dig)
		cout << "*** Valid IMEI ***\n";
	else
		cout << "*** Invalid IMEI ***\n";
	return 0;
}

