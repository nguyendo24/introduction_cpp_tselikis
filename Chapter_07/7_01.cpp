#include <iostream> // ’σκηση 7.1
int main()
{
	int i, sum, a[] = {-1, 5, 7}, b[] = {5, 4, -1}; 
	double c[] = {4.1, 0.5, 1.8}; 

	for(i = 0; i < 3; i++)
		a[a[i]-b[2-i]]++;
	for(--i; a[i]; i--)
		std::cout << a[i] << '\n';
	sum = 0;
	for(i = 0; a[i] = c[i]; i++)
		sum += a[i];
	std::cout << sum << '\n';
	return 0;
}

