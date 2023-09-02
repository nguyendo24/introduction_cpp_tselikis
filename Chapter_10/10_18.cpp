#include <iostream> // ’σκηση 10.18
#include <cstring> 
using std::cout;
using std::cin;

int main()
{
	const int ERROR_TRIES = 7;
	char ch, secret[30], hide[30] = {0};
	int i, found, len, error, correct;

	cout << "Enter secret word: ";
	cin.getline(secret, sizeof(secret));
	len = strlen(secret); 

	for(i = 0; i < len; i++)
		hide[i] = '_';

	error = correct = 0;
	while(error < ERROR_TRIES)
	{
		cout << "Enter character: ";
		ch = cin.get();
		found = 0;
		for(i = 0; i < len; i++)
		{
			if(secret[i] == ch)
			{
				hide[i] = ch;
				found = 1;
				correct++;
				if(correct == len)
				{
					cout << "Secret word is found !!!\n";
					return 0;
				}
			}
		}
		if(found == 0)
		{
			error++;
			cout << "Error, " << ch << " does not exist. You've got " << ERROR_TRIES - error << " more attempts\n";
		}
		else
			cout << hide << '\n';
		cin.get(); /* Εξάγουμε το '\n', από την προηγούμενη get(). */
	}
	cout << "Sorry, the secret word was " << secret << '\n';
	return 0;
}

