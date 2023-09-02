#include <iostream> // ’σκηση 20.8
using std::cout;

class A
{
public:
	A() {cout << "A ";}
	~A() {cout << "~A ";}
	void f() {cout << "A.f() ";}
	void v() {cout << "A.v() ";}
};

class B : public A
{
public:
	~B() {cout << "~B ";}
	virtual void f() {cout << "B.f() ";}
};

class C : public B
{
public:
	C() {cout << "C ";}
	virtual ~C() {cout << "~C ";}
	virtual void f() {cout << "C.f() ";}
	void v() {cout << "C.v() ";}
};

int main()
{
	B *p = new C;
	p->f(); 
	p->v(); 
	delete p;
	return 0;
}

