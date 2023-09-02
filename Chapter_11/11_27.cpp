#include <iostream> // ’σκηση 11.27 
#include <cstring>
using std::cout;
using std::cin;

const int NUM = 20;
const int SIZE = 100;

char *find_name(char name[][SIZE], char str[]);

int main()
{
	char *ptr, str[SIZE], name[NUM][SIZE]; /* Δήλωση πίνακα NUM γραμμών και SIZE στηλών, όπου στην κάθε γραμμή αποθηκεύονται οι χαρακτήρες του αντίστοιχου ονόματος. */ 
	int i;

	for(i = 0; i < NUM; i++)
	{
		cout << "Enter name: ";
		cin.getline(name[i], sizeof(name[i])); /* Χρησιμοποιούμε το name[i] σαν δείκτη προς την αντίστοιχη i γραμμή των SIZE χαρακτήρων. */
	}
	cout << "Enter name to search: ";
	cin.getline(str, sizeof(str));

	ptr = find_name(name, str);
	if(ptr == nullptr)
		cout << str << " is not contained\n";
	else
		cout << ptr << " is contained\n";
	return 0;
}

char *find_name(char name[][SIZE], char str[])
{
	int i;

	for(i = 0; i < NUM; i++)
		if(strcmp(name[i], str) == 0)
			return name[i]; /* Το name[i] δείχνει στον πρώτο χαρακτήρα της γραμμής που περιέχει το συγκεκριμένο όνομα. */
	return nullptr; /* Αν η εκτέλεση του κώδικα φτάσει σε αυτό το σημείο σημαίνει ότι το όνομα δεν βρέθηκε στον πίνακα. */
}

