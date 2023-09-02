#include <iostream> // ’σκηση 18.2
#include <cstdlib> 
using namespace std;

class Complex_Num
{
private:
	double re;
	double im; 
public:
	Complex_Num(double r=0, double i=0) {re = r; im = i;}
	Complex_Num operator+(const Complex_Num& z) const;
	Complex_Num operator-(const Complex_Num& z) const;
	Complex_Num operator*(const Complex_Num& z) const;
	Complex_Num operator/(const Complex_Num& z) const;
	friend ostream& operator<<(ostream& out, const Complex_Num& z);
};

Complex_Num Complex_Num::operator+(const Complex_Num& z) const
{
	Complex_Num tmp;
	tmp.re = re + z.re;
	tmp.im = im + z.im;
	return tmp;
}

Complex_Num Complex_Num::operator-(const Complex_Num& z) const
{
	Complex_Num tmp;
	tmp.re = re - z.re;
	tmp.im = im - z.im;
	return tmp;
}

Complex_Num Complex_Num::operator*(const Complex_Num& z) const
{
	Complex_Num tmp;
	tmp.re = (re*z.re) - (im*z.im); 
	tmp.im = (im*z.re) + (re*z.im);
	return tmp;
}

Complex_Num Complex_Num::operator/(const Complex_Num& z) const
{
	if(z.re == 0 && z.im == 0)
	{
		cout << "Division by zero is not allowed\n";
		exit(EXIT_FAILURE); /* Τερματισμός προγράμματος. Υπάρχουν άλλες πιο ομαλές προσεγγίσεις για την διαχείριση του λάθους. Για παράδειγμα, να δημιουργήσουμε μία εξαίρεση όπως θα δούμε στο Κ.22. */
	}
	Complex_Num tmp;
	double div = (z.re*z.re) + (z.im*z.im);
	tmp.re = ((re*z.re) + (im*z.im))/div;
	tmp.im = ((im*z.re) - (re*z.im))/div;
	return tmp;
}

ostream& operator<<(ostream& out, const Complex_Num& z)
{
	out << showpos << "z = " << z.re << z.im << 'j' << '\n';
	return out;
}

