#include <iostream> // ’σκηση 22.4
#include <string>
using namespace std;

class Err_Rpt
{
public:
	string msg;
	Err_Rpt(const char *m) : msg(m) {}
};

class Fraction
{
private:
	int a;
	int b;
public:
	Fraction() {}
	Fraction(int a, int b);
	int& operator()(int pos);
	Fraction operator*(const Fraction& fr) const;
	Fraction operator+(const Fraction& fr) const;
	friend ostream& operator<<(ostream& out, const Fraction& fr);
};

Fraction::Fraction(int a, int b)
{
	if(b == 0) 
		throw Err_Rpt("Error: Constructor failed\n"); /* Ο παρονομαστής πρέπει να είναι διαφορετικός από 0. */
	this->a = a;
	this->b = b;
}

int& Fraction::operator()(int pos)
{
	if(pos == 0) 
		return a;
	else if(pos == 1) 
		return b;
	else 
		throw Err_Rpt("Error: Wrong index\n");
}

Fraction Fraction::operator*(const Fraction& fr) const
{
	Fraction tmp;

	tmp.a = a * fr.a; 
	tmp.b = b * fr.b; 
	return tmp;
}

Fraction Fraction::operator+(const Fraction& fr) const
{
	int lcd, min, max;
	Fraction tmp;

	if(b > fr.b)
	{
		max = b;
		min = fr.b;
	}
	else
	{
		max = fr.b;
		min = b;
	}
	lcd = max;
	while(1)
	{
		if(lcd % min == 0)
			break;
		lcd += max;
	}
	tmp.a = a*(lcd/b) + fr.a*(lcd/fr.b);
	tmp.b = lcd;
	return tmp;
}
ostream& operator<<(ostream& out, const Fraction& fr)
{
	out << fr.a << '/' << fr.b << '\n';
	return out;
}

