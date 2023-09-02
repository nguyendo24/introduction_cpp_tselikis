#include <iostream> // ’σκηση 10.11
#include <cstring> 
using std::cout;
using std::cin;

int main()
{
	char str1[100], str2[100];
	int k;

	cout << "Enter first text: ";
	cin.getline(str1, sizeof(str1));

	cout << "Enter second text: ";
	cin.getline(str2, sizeof(str2));

	k = strcmp(str1, str2);
	/* Θα μπορούσαμε να μην χρησιμοποιήσουμε τη μεταβλητή k και να γράψουμε if(strcmp(str1, str2) == 0) */
	if(k == 0)
		cout << "Same texts\n";
	else
	{
		cout << "Different texts\n";
		if(strncmp(str1, str2, 3) == 0)
			cout << "But the first 3 chars are the same\n";
	}
	return 0;
}

