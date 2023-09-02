#include <iostream> // ’σκηση 8.1
using std::cout;
using std::cin;

int main()
{
	float *ptr1, *ptr2, i, j, tmp;

	/* Oι δείκτες πρέπει να αρχικοποιηθούν πριν χρησιμοποιηθούν για το διάβασμα των τιμών. */
	ptr1 = &i;
	ptr2 = &j;

	cout << "Enter values: ";
	cin >> *ptr1 >> *ptr2; 

	tmp = *ptr2;
	*ptr2 = *ptr1;
	*ptr1 = tmp;

	if((*ptr1-*ptr2) > 0)
		cout << *ptr1-*ptr2 << '\n';
	else
		cout << -(*ptr1-*ptr2) << '\n';
	return 0;
}

