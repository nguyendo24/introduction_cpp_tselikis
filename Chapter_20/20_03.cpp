#include <iostream> // ’σκηση 20.3
#include <string>
using std::cout;
using std::string;

class A
{
private:
	string name;
public:
	A(const string& s) : name(s) {}
	virtual void show() const {cout << name << '\n';}
};

class B : public A 
{
private:
	string name;
public:
	B(const string& s1, const string& s2) : A(s2), name(s1) {}
	virtual void show() const {cout << name << '\n';}
};

class C : public B
{
private:
	string name;
public:
	C(const string& s1, const string& s2, const string& s3) : B(s2, s3), name(s1) {}
	virtual void show() const {cout << name << '\n';}
};

