#include <iostream> // ’σκηση 3.6 
using std::cout;
using std::cin;

int main()
{
	int i;
	float j;

	cout << "Enter positive number: ";
	cin >> i;

	i = i+5;
	j = i/10.0; /* Διαιρούμε με το 10.0 και όχι με το 10, ώστε το δεκαδικό μέρος να μην αποκοπεί. */
	i = (int)j * 10; // Αποκόπτουμε το δεκαδικό ψηφίο. 
	cout << i << '\n';
	return 0;
}

