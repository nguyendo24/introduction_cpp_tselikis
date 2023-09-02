#include <iostream> // ’σκηση 10.17
#include <string> 
using std::cout;
using std::cin;
using std::string;

int main()
{
	char ch, max_ch;
	int i, max_times, low_let[26] = {0}; /* Το μέγεθος του πίνακα είναι 26 θέσεις, όσα και τα πεζά γράμματα του λατινικού αλφαβήτου. Σε αυτόν τον πίνακα αποθηκεύονται οι αριθμοί εμφανίσεων του κάθε γράμματος. Για παράδειγμα, το low_let[0] δηλώνει τον αριθμό εμφανίσεων του 'a', ενώ το low_let[25] τις εμφανίσεις του 'z'. */
	int dig[10] = {0}; /* Παρόμοια, το dig[0] δηλώνει τον αριθμό εμφανίσεων του ψηφίου 0, ενώ το dig[9] τις εμφανίσεις του 9. */
	string str;

	cout << "Enter text: ";
	getline(cin, str);

	max_ch = max_times = 0;
	for(i = 0; i < str.size(); i++) 
	{
		if((str[i] >= 'a') && (str[i] <= 'z'))
		{
			ch = str[i]-'a';
			low_let[ch]++; /* Για παράδειγμα, αν ο χαρακτήρας είναι το 'a', η τιμή low_let['a'-'a'] = low_let[0], η οποία δηλώνει τις εμφανίσεις του 'a', θα αυξηθεί κατά ένα. */
			if(low_let[ch] > max_times)
			{
				max_times = low_let[ch];
				max_ch = str[i];
			}
		}
		else if((str[i] >= '0') && (str[i] <= '9'))
			dig[str[i]-'0']++; 
	}
	cout << "***** Lower case letters appearances\n"; 
	for(i = 0; i < 26; i++)
		if(low_let[i] != 0) /* Έλεγχος για το αν υπάρχει μία τουλάχιστον εμφάνιση του γράμματος. */
			cout << "Letter " << (char)('a'+i) << " appeared " << low_let[i] << " times\n";

	cout << "***** Digits appearances\n"; 
	for(i = 0; i < 10; i++)
		if(dig[i] != 0)
			cout << "Digit " << i << " appeared " << dig[i] << " times\n";
	if(max_times != 0)
		cout << max_ch << " appears " << max_times << " times\n";
	return 0;
}

