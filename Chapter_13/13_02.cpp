#include <iostream> // ’σκηση 13.2
#include <string> 
using namespace std; 

const int SIZE = 100;

struct City
{
	string name; 
	string cntr; 
	int pop;
};

int main()
{
	bool found;
	int i, pop;
	string cntr;
	City *ptr, cities[SIZE]; 

	for(ptr = cities; ptr < cities+SIZE; ptr++) /* Με κάθε αύξηση, ο ptr δείχνει στο επόμενο στοιχείο του πίνακα, δηλαδή στην επόμενη δομή*/
	{
		cout << "\nCity: ";
		getline(cin, ptr->name);

		cout << "Country: ";
		cin >> ptr->cntr;

		cout << "Population: ";
		cin >> ptr->pop;
		cin.get(); 
	}
	cout << "\nEnter country to search: ";
	getline(cin, cntr);

	cout << "Population: ";
	cin >> pop;

	found = 0;	
	for(i = 0; i < SIZE; i++)
	{
		if((cities[i].cntr == cntr) && (cities[i].pop > pop))
		{
			found = 1;
			cout << cities[i].name << ' ' << cities[i].pop << '\n';
		}
	}
	if(found == 0)
		cout << "\nNone city is found\n";
	return 0;
}

