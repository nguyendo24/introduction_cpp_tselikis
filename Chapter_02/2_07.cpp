#include <iostream> // ’σκηση 2.7
int main()
{
	int k;
	float i = 3.45, j = 6.78, dec;

	dec = i - static_cast<int>(i); // Βρίσκουμε το δεκαδικό μέρος. 
	k = static_cast<int>(i); /* Αποθηκεύουμε το υπάρχον ακέραιο μέρος, πριν αλλάξει η τιμή του. */
	i = static_cast<int>(j) + dec;

	dec = j - static_cast<int>(j);
	j = k + dec;
	std::cout << i << ' ' << j << '\n';
	return 0;
}

