#include <iostream> // ’σκηση 21.2
using std::cout;

class A
{
public:
	A() {cout << "A()";}
	virtual ~A() {cout << " ~A()";}
};

class B
{
public:
	B() {cout << " B()";}
	virtual ~B() {cout << " ~B()";}
};

class C : virtual public A, virtual public B
{
public:
	C() {cout << " C()";}
	~C() {cout << " ~C()";}
};
class D : public C
{
public:
	D() {cout << " D()";}
	~D() {cout << " ~D()";}
};

class E : public C
{
public:
	E() {cout << " E()";}
	~E() {cout << " ~E()";}
};

class F : public D, public E  
{
public:
	F() {cout << " F()";}
	~F() {cout << "\n~F()";}
};

int main()
{
	F f;
	return 0;
}

