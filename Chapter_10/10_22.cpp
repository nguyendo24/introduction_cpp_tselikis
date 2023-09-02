#include <iostream> // ’σκηση 10.22
#include <string> 
using std::cout;
using std::cin;
using std::string;
int main()
{
	int i, words;
	string str;

	i = words = 0;
	cout << "Enter text: ";
	getline(cin, str);

	if(str[0] != ' ' && str[0] != '\t' && str[0] != '\0') /* Αν ο πρώτος χαρακτήρας δεν είναι κενός χαρακτήρας σημαίνει ότι αρχίζει μία λέξη, οπότε αυξάνεται η μεταβλητή words. */
		words++;

	while(str[i] != '\0')
	{
		if(str[i] == ' ' || str[i] == '\t')
		{
		/* Ελέγχουμε αν ο επόμενος χαρακτήρας, δηλαδή ο str[i+1], δεν είναι κενός χαρακτήρας, γιατί μπορεί να υπάρχουν περισσότεροι από ένας κενοί χαρακτήρες ανάμεσα στις λέξεις. Αν δεν είναι κενός χαρακτήρας, τότε σημαίνει ότι αρχίζει μία καινούργια λέξη, οπότε η μεταβλητή words αυξάνεται κατά ένα. */
			if(str[i+1] != ' ' && str[i+1] != '\t' && str[i+1] != '\0')
			{
				words++;
				cout << '\n';
			}
		}
		else
			cout << str[i];
		i++;
	}
	cout << "\nThe text contains " << words << " words\n";
	return 0;
}

