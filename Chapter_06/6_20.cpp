#include <iostream> // ’σκηση 6.20
using std::cout;
using std::cin;

int main()
{
	const int SEATS = 300;
	int sel, adults, tkts, rsvd_seats; 
	float cost, tot_cost; 

	rsvd_seats = 0;
	tot_cost = 0;
	while(1) 
	{
		cout << "\nMenu selections\n";
		cout << "---------------\n";

		cout << "1. Buy Ticket\n";
		cout << "2. Show Information\n";
		cout << "3. Exit\n";

		cout << "\nEnter choice: ";
		cin >> sel;
		switch(sel)
		{
			case 1:
				cout << "\nHow many tickets would you like to buy? ";
				cin >> tkts;
				if(tkts + rsvd_seats > SEATS)
				{
					cout << "\nSorry, the available seats are %d\n", SEATS - rsvd_seats;
					break;
				}
				while(1)
				{
					cout << "\nHow many adults? ";
					cin >> adults;

					if(adults <= tkts)
						break;
					else
						cout << "Error: Wrong number of persons\n";
				}
				cost = adults*15 + (tkts-adults)*10;
				if(tkts > 3)
					cost *= 0.9;
				tot_cost += cost;
				rsvd_seats += tkts;
				if(rsvd_seats == SEATS)
				{
					cout << "\nNot available seats. Income: " << tot_cost << '\n';
					return 0;
				}
			break;

			case 2:
				cout << "\nFree seats: " << SEATS-rsvd_seats << " Income: " << tot_cost << '\n' << '\n';
			break;

			case 3:
			return 0;

			default:
				cout << "\nWrong choice\n";
			break;
		}
	}
	return 0;
}

