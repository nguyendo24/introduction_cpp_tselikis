#include <iostream> // ’σκηση 20.6
using std::cout;

class A
{
private:
	int k;
public:
	A() {k = 1;}
	void f() const {cout << k;}
	virtual void v() const {cout << " A.v() ";}
};

class B : public A
{
private:
	int k;
public:
	B() {k = 2;}
	void f() const {cout << k;}
	virtual void v() const override {cout << " B.v() ";}
};

void t1(A a)
{
	a.f();
	a.v();
}

void t2(A& r)
{
	r.f();
	r.v();
}

int main()
{
	B b;
	t1(b);
	t2(b);
	return 0;
}

