#include <iostream> // ’σκηση 10.23
#include <cstring> 
using std::cout;
using std::cin;

int main()
{
	const int LETTERS = 26;
	bool error;
	char str[100], key[LETTERS+1];
	int i, j, len;

	cout << "Enter text: ";
	cin.getline(str, sizeof(str));
	len = strlen(str);
	do
	{
		error = 0;
		cout << "Enter key (" << LETTERS << " different characters): ";
		cin.getline(key, sizeof(key));
		if(strlen(key) != LETTERS)
		{
			cout << "Error: Key must be of " << LETTERS << " characters\n";
			error = 1;
		}
		else
		{
			for(i = 0; i < LETTERS; i++)
			{
				for(j=i+1; j < LETTERS; j++)
				{
					if(key[i] == key[j])
					{
						error = 1;
						cout << "Key characters must be different\n";
						break;
					}
				}
				if(error == 1)
					break;
			}
		}
	} while(error != 0);

	for(i = 0; i < len; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = key[str[i]-'a'];
	}
	cout << "Encrypted text: " << str << '\n';
	for(i = 0; i < len; i++)
	{
		for(j = 0; j < LETTERS; j++)
		{
			if(str[i] == key[j])
			{
				str[i] = 'a'+j;
				break;
			}
		}
	}
	cout << "Original text: " << str << '\n';
	return 0;
}

