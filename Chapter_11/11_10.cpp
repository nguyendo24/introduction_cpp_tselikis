#include <iostream> // ’σκηση 11.10
#include <cmath>
using std::cout;
using std::cin;

void find_roots(double a, double b, double c, double *r1, double *r2, int *code);

int main()
{
	int code;
	double a, b, c, r1, r2;

	do
	{
		cout << "Enter coefficients (a<>0): ";
		cin >> a >> b >> c;
	} while(a == 0);

	find_roots(a, b, c, &r1, &r2, &code);
	if(code == 2)
		cout << "Two roots: " << r1 << ' ' << r2 << '\n';
	else if(code == 1)
		cout << "One root: " << r1 << '\n';
	else
		cout << "Not real roots\n";
	return 0;
}

void find_roots(double a, double b, double c, double *r1, double *r2, int *code) // Επιστροφές τιμών μέσω δεικτών.
{
	double d;
	
	d = b*b-4*a*c;
	if(d > 0)
	{
		*code = 2;
		*r1 = (-b+sqrt(d))/(2*a);
		*r2 = (-b-sqrt(d))/(2*a);
	}
	else if(d == 0)
	{
		*code = 1;
		*r1 = *r2 = -b/(2*a);
	}
	else
		*code = 0;
}

