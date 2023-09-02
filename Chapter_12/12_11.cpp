#include <iostream> // ’σκηση 12.11
#include <cstring>
using std::cout;
using std::cin;

const int CNTRS = 50;
const int MONTHS = 12;

void bubble_sort(char str[][100], int arr[]);

int main()
{
	bool flag;
	char cntr[CNTRS][100], str[100];
	int i, j, tmp, tour[CNTRS] = {0};

	for(i = 0; i < CNTRS; i++)
	{
		cout << "Enter name of country_" << i+1 << ": ";
		cin.getline(cntr[i], sizeof(cntr[i]));

		for(j = 0; j < MONTHS; j++)
		{
			cout << "Enter tourists of month_" << j+1 << ": ";
			cin >> tmp;
			tour[i] += tmp; /* Σε αυτόν τον πίνακα αποθηκεύουμε τον συνολικό αριθμό των τουριστών που επισκέφτηκαν το κάθε κράτος. */
		}
		cin.get();
	}
	cout << "Enter country to search: ";
	cin.getline(str, sizeof(str));

	flag = 0;
	for(i = 0; i < CNTRS; i++)
	{
		if(strcmp(str, cntr[i]) == 0)
		{
			flag = 1;
			cout << tour[i] << " tourists visited " << str << '\n';
			break;
		}
	}
	if(flag == 0)
		cout << str << " not registered\n";

	bubble_sort(cntr, tour); /* Ταξινόμηση του πίνακα με τον αριθμό των τουριστών και παράλληλη ενημέρωση του πίνακα με τα ονόματα των κρατών. */			
	cout << "\n***** Tourists in decrease order *****\n";
	for(i = 0; i < 5; i++)
		cout << i+1 << '.' << cntr[i] << '\t' << tour[i] << '\n';

	/* Ελέγχουμε αν υπάρχουν και άλλα κράτη που να έχουν τον ίδιο αριθμό τουριστών με αυτό που βρίσκεται στην πέμπτη θέση. */
	while((tour[i] == tour[4]) && i < CNTRS)
	{
		cout << i+1 << '.' << cntr[i] << '\t' << tour[i] << '\n';
		i++;
	}
	return 0;
}

void bubble_sort(char str[][100], int arr[])
{
	bool reorder;
	char tmp[100];
	int i, j, k;

	for(i = 1; i < CNTRS; i++)
	{
		reorder = 0;
		for(j = CNTRS-1; j >= i; j--)
		{
			if((arr[j] > arr[j-1]) || 
				(arr[j] == arr[j-1] && strcmp(str[j], str[j-1]) < 0)) /* Παράλληλη αντιμετάθεση του αριθμού των τουριστών και των αντίστοιχων χωρών. Χώρες με τον ίδιο αριθμό τουριστών ταξινομούνται σε αλφαβητική σειρά. */
			{
				k = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = k;
				strcpy(tmp, str[j]); 
				strcpy(str[j], str[j-1]);
				strcpy(str[j-1], tmp);
				reorder = 1;
			}
		}
		if(reorder == 0)
			return;
	}
}

