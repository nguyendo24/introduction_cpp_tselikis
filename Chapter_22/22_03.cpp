#include <iostream> // ’σκηση 22.3 

class Circle
{
private:
	float rad;
public:
	Circle(float r) {rad = r;}
	virtual ~Circle() {}; 
	float get() const {return rad;}
	void set(float r) {rad = r;}
	virtual Circle& operator-(int n);
	virtual void show() const;
};

class Ellipse : public Circle
{
private:
	float axis;
public:
	Ellipse(float r, float a) : Circle(r), axis(a) {}
	virtual Ellipse& operator-(int n) override;
	virtual void show() const override;
};

void f(Circle& c, int n);

Circle& Circle::operator-(int n)
{
	rad -= n;
	if(rad < 0)
		throw 10; // Δημιουργούμε την εξαίρεση. 
	return *this;
}

void Circle::show() const
{
	std::cout << "R:" << rad << '\n';
}

Ellipse& Ellipse::operator-(int n)
{
	float rad;

	rad = get()-n;
	if(rad < 0)
		throw 10;
	set(rad);
	axis -= n;
	if(axis < 0)
		throw 20;
	return *this;
}

void Ellipse::show() const
{
	std::cout << "R:" << get() << " A:" << axis << '\n'; 
}

void f(Circle& c, int n)
{
	Circle& tmp = c-n;
	tmp.show();
}

int main()
{
	Circle cir(5);
	Ellipse ell(10, 6); 
	Circle &r1 = cir, &r2 = ell;

	try
	{
		f(r1, 3);
		f(r2, 1);
		f(r2, 10);
	} 
	catch(int a) // Ελέγχουμε την τιμή του ορίσματος. 
	{
		if(a == 10)
			std::cout << "Error: negative radius\n"; 
		else if(a == 20)
			std::cout << "Error: negative axis\n"; 
		return 0;
	}
	return 0;
}

