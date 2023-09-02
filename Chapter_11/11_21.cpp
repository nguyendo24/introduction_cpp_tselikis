#include <iostream> // ’σκηση 11.21
#include <cmath> 
using std::cout;
using std::cin;

double f(double x);

int main()
{
	int steps, max_steps;
	long double x0, x1, err, middle, mul, tmp;

	do
	{
		cout << "Enter x0: ";
		cin >> x0;

		cout << "Enter x1: ";
		cin >> x1;

		mul = f(x0)*f(x1);
	} while(mul >= 0);

	cout << "Enter positive tolerance: ";
	cin >> err;

	cout << "Enter maximum number of bisections: ";
	cin >> max_steps;

	if(x0 > x1)
	{
		tmp = x1;
		x1 = x0;
		x0 = tmp;
	}
	steps = 0;
	while(1)
	{
		steps++;
		middle = (x0+x1)/2;
		tmp = f(middle);
		if(fabs(tmp) <= err || x1-x0 <= 2*err || steps >= max_steps)
			break;

		mul = tmp * f(x0);
		if(mul < 0)
			x1 = middle; // Το x0 είναι το ίδιο.
		else if(mul > 0)
			x0 = middle; // Το x1 είναι το ίδιο.
	}
	if(steps >= max_steps)
		cout << "Maximum number of bisections is reached. ";
	cout << "Approximated root is " << middle << '\n';
	return 0;
}

double f(double x)
{
	return x*x*x + x - 1;
}

