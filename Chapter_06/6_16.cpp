#include <iostream> // ’σκηση 6.16 
int main()
{
	int num, sum, dig, cnt, tot_dig, search_dig, tmp;

	sum = tot_dig = cnt = 0;

	std::cout << "Enter number: ";
	std::cin >> num;

	std::cout << "Enter digit to search: ";
	std::cin >> search_dig;

	tmp = num; /* Αποθηκεύουμε την τιμή του αριθμού, γιατί θα αλλάξει στη συνέχεια. */
	if(num < 0)
		num = -num;

	if(num == 0)
		tot_dig = 1;
	else
	{
		while(num != 0)
		{
			dig = num % 10; /* Βρίσκουμε το τελευταίο ψηφίο του αριθμού. */
			sum += dig;
			num /= 10; /* Απομακρύνουμε το τελευταίο ψηφίο. */
			tot_dig++;
			if(dig == search_dig)
				cnt++;
		}
	}
	std::cout << "The number " << tmp << " contains " << tot_dig << " digits, their sum is " << sum <<  " and number " << search_dig << " appears " << cnt << " times\n";
	return 0;
}

