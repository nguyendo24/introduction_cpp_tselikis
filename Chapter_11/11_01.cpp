#include <iostream> // ’σκηση 11.1

int square(int a);
int cube(int a);

int main()
{
	int i, j, k;

	std::cout << "Enter number: ";
	std::cin >> i;
	
	j = square(i);
	k = cube(i);
	std::cout << j+k << '\n'; /* Θα μπορούσαμε να μην χρησιμοποιήσουμε τις μεταβλητές j, k και να γράψουμε κατευθείαν cout << square(i)+cube(i); */
	return 0;
}

int square(int a)
{
	return a*a;
}

int cube(int a)
{
	return a*square(a); 
}

