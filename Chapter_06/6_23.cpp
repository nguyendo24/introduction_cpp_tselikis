#include <iostream>  // ’σκηση 6.23
#include <cmath>
int main()
{
	int i, a;
	double x, sum, prev_term, cur_term;
	const double pi = 3.14, accuracy = 0.0001;

	std::cout << "Enter x in degrees: ";
	std::cin >> x;

	x = pi*x/180; // Μετατροπή μοιρών σε ακτίνια.
	sum = x;
	a = 1;
	cur_term = x;
	i = 2;
	do
	{
		a = -a;
		prev_term = cur_term;
		cur_term = prev_term * x*x/(i*(i+1)); 
		sum += cur_term * a;
		i += 2;
	} while(fabs(cur_term-prev_term) >= accuracy);

	std::cout << "Sum: " << sum << ' ' << "sin: " << sin(x) << '\n';
	return 0;
}

