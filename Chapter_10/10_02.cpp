#include <iostream> // ’σκηση 10.2
int main()
{
	char str[53];
	int i;

	for(i = 0; i < 26; i++)
	{
		str[i] = 'a'+i; 
		str[26+i] = 'A'+i; 
	}
	str[52] = '\0'; /* Στο τέλος, προσθέτουμε τον τερματικό χαρακτήρα. */
	std::cout << str << '\n';
	return 0;
}

