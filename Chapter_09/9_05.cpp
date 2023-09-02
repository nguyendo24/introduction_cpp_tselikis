#include <iostream> // ’σκηση 9.5 
#include <cstdio>
using std::cout;
using std::cin;

int main()
{
	int ch, dig, arr[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9}; /* Δημιουργώ έναν πίνακα για να κάνω άμεσα τις αντιστοιχίσεις. */
	dig = 0;
	cout << "Enter digit or letter: ";
	while((ch = cin.get()) != '\n' && ch != EOF)
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			dig++;
			cout << arr[ch-'A']; /* Ανάλογα με την τιμή του ch εμφανίζεται το αντίστοιχο ψηφίο. Για παράδειγμα, αν ο χρήστης εισάγει 'I' θα εμφανιστεί το arr[73-65] = 4. */
		}
		else if(ch >= '0' && ch <= '9')
		{
			dig++;
			cout << (char)ch; /* Τα ψηφία εμφανίζονται όπως είναι. */
		}
		else
		{
			cout << "\nError: Not valid character\n";
			return 0;
		}
		if(dig == 10)
			break;
	}
	if(dig == 10)
		cout << "\nNumber completed\n";
	return 0;
}

