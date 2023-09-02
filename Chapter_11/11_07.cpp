#include <iostream> // ������ 11.7
using std::cout;
using std::cin;

double power(double a, int b);

int main()
{
	int exp;
	double base;

	cout << "Enter base: ";
	cin >> base;
	cout << "Enter exponent: ";
	cin >> exp;
	cout << base << " power " << exp << " = " << power(base, exp) << '\n';
	return 0;
}

double power(double a, int b)
{
	int i, exp;
	double val;

	val = 1; // ���������� ������ ����. 
	exp = b;
	if(exp < 0) /* �� ��������� ��� � ������� ����� ��������� ��� ������� ������. */
		exp = -exp;
	for(i = 0; i < exp; i++)
		val *= a;  
	if(b < 0)
		val = 1/val;
	return val;
}

