#include <iostream> // ’σκηση 5.15
using std::cout;
using std::cin;

int main()
{
	int sex;
	float height;

	cout << "Enter sex (0:man - 1:woman): ";
	cin >> sex;

	cout << "Enter height in meters: ";
	cin >> height;

	switch(sex)
	{
		case 0:
			if(height < 1.70)
				cout << "Result: Short\n";
			else if(height < 1.85) /* Το else αντιστοιχεί στο ότι το height είναι >= 1.7 και το if ελέγχει αν το height είναι < 1.85. Δηλαδή, αυτό το else if ελέγχει εάν 1.7 <= height < 1.85. */
				cout << "Result: Normal\n";
			else
				cout << "Result: Tall\n";
		break;

		case 1:
			if(height < 1.60)
				cout << "Result: Short\n";
			else if(height < 1.75)
				cout << "Result: Normal\n";
			else
				cout << "Result: Tall\n";
		break;

		default:
			cout << "Error: Wrong input\n";
		break;
	}
	return 0;
}

