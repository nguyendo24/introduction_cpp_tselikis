#include <iostream> // ’σκηση 10.20 
#include <cstring> 
using std::cout;
using std::cin;

int main()
{
	char upc[100];
	int i, len, flag, chk_dig, sum;

	while(1)
	{
		cout << "Enter UPC (12 digits): ";
		cin.getline(upc, sizeof(upc));
		len = strlen(upc); 
		if(len != 12)
		{
			cout << "Error: wrong length\n";
			continue;
		}
		flag = 1;
		for(i = 0; i < 12; i++)
		{
			if(upc[i] < '0' || upc[i] > '9')
			{
				cout << "Error: only digits allowed\n";
				flag = 0;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	sum = 0;
	for(i = 0; i < 11; i+=2)
		sum += upc[i]-'0'; /* Αφαιρούμε το '0' για να βρούμε την αριθμητική τιμή του χαρακτήρα-ψηφίου. */
	sum *= 3;
	for(i = 1; i < 11; i+=2)
		sum += upc[i]-'0';

	chk_dig = 10-(sum%10);
	if(chk_dig == 10)
		chk_dig = 0;

	if(chk_dig == (upc[11]-'0'))
		cout << "Valid barcode\n";
	else
		cout << "Wrong check digit. The correct is " << chk_dig << '\n';
	return 0;
}

