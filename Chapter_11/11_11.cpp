#include <iostream> // ’σκηση 11.11
using std::cout;
using std::cin;

double f(double x);

int main()
{
	int i, a, b, n;
	double step, x, area;

	do
	{
		cout << "Enter number of intervals: ";
		cin >> n;
	} while(n <= 0);

	do
	{
		cout << "Enter low and up limit (a < b): ";
		cin >> a >> b;
	} while(a >= b); 

	step = (double)(b-a)/n;
	x = a;
	area = 0;
	for(i = 0; i < n; i++) 
	{
		area += 0.5*step*(f(x)+f(x+step));
		x += step;
	}
	cout << "Calculus = " << area << '\n';
	return 0;
}

double f(double x) /* Χρησιμοποιούμε συνάρτηση ώστε αν χρειαστεί να υπολογίσουμε το ολοκλήρωμα μίας άλλης συνάρτησης να μπορούμε εύκολα να την αλλάξουμε. */
{
	return x*x;
}

