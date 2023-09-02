#include <iostream> // ’σκηση 13.8
using namespace std;

struct Complex
{
	double re; // Το πραγματικό μέρος του μιγαδικού αριθμού. 
	double im; // Το φανταστικό μέρος του μιγαδικού αριθμού. 
};

Complex operation(Complex a1, Complex a2, char sign); 

int main()
{
	char sign;
	Complex z1, z2, z;
	
	cout << "Enter real and imaginary part of the first complex number: ";
	cin >> z1.re >> z1.im;
	cout << showpos << "z1 = " << z1.re << z1.im << 'j' << '\n';

	cout << "Enter real and imaginary part of the second complex number: ";
	cin >> z2.re >> z2.im;
	cout << "z2 = " << z2.re << z2.im << 'j' << '\n';

	cout << "Enter sign (+, -, *, /): ";
	cin >> sign; 

	if(sign == '+' || sign == '-' || sign == '*' || sign == '/')
	{
		if(sign == '/' && z2.re == 0 && z2.im == 0)
			cout << "Division by zero is not allowed\n";
		else
		{
			z = operation(z1, z2, sign);
			cout << "z = z1" << sign << "z2 = " << z.re << z.im << 'j' << '\n';
		}
	}
	else
		cout << "Wrong sign\n";
	return 0;
}

Complex operation(Complex a1, Complex a2, char sign) /* Μεταβίβαση δομών. */
{
	double div;
	Complex a;

	switch(sign)
	{
		case '+':
			a.re = a1.re + a2.re;
			a.im = a1.im + a2.im;
		break;

		case '-':
			a.re = a1.re - a2.re;
			a.im = a1.im - a2.im;
		break;

		case '*':
			a.re = (a1.re*a2.re) - (a1.im*a2.im); 
			a.im = (a1.im*a2.re) + (a1.re*a2.im);
		break;

		case '/':
			div = (a2.re*a2.re) + (a2.im*a2.im);
			a.re = ((a1.re*a2.re) + (a1.im*a2.im))/div;
			a.im = ((a1.im*a2.re) - (a1.re*a2.im))/div;
		break;
	}
	return a;
}

