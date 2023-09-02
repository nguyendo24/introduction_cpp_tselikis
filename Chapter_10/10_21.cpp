#include <iostream> // ’σκηση 10.21
#include <cstring> 
using std::cout;
using std::cin;

int main()
{
	char str[100];
	int i, len, cnt;

	cout << "Original text: ";
	cin.getline(str, sizeof(str));
	len = strlen(str);

	cout << "Compressed text: ";
	i = 0;
	while(i < len)
	{
		cnt = 1;
		if(str[i] < '0' || str[i] > '9') /* Σύμφωνα με την εκφώνηση να μην γίνεται συμπίεση ψηφίων. */
		{
			while(str[i+cnt] == str[i]) /* Έλεγχος αν ο συγκεκριμένος χαρακτήρας, δηλαδή ο str[i], επαναλαμβάνεται στις επόμενες θέσεις. */
				cnt++;

			if(cnt == 1)
				cout << str[i];
			else
				cout << cnt << str[i];
		}
		else
			cout << str[i];

		i += cnt;
	}
	return 0;
}

