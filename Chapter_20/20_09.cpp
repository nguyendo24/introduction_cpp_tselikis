#include <iostream> // ������ 20.9
#include <cstring>

class A
{
private:
	char *s;
public:
	explicit A(const char str[]); // �� ��������� �� explicit.
	A();
	virtual ~A();
	A(const A& a);
	A& operator=(const A& a);
	void show() const;
};

A::A(const char str[])
{
	s = new char[strlen(str)+1];
	strcpy(s, str);
}

A::A() 
{
	s = nullptr;
}

A::~A()
{
	delete[] s;
}

A& A::operator=(const A& a) 
{
	if(this == &a) 
		return *this;

	delete[] s;
	s = new char[strlen(a.s)+1];
	strcpy(s, a.s);
	return *this;
}

A::A(const A& a) 
{
	s = new char[strlen(a.s)+1];
	strcpy(s, a.s);
}

void A::show() const 
{
	std::cout << s << '\n';
}

class B : public A 
{
private:
	char *s;
public:
	explicit B(const char str[]);
	B();
	virtual ~B();
	B(const B& b);
	B& operator=(const B& b);
	void show() const;
};

B::B(const char str[]) : A(str)
{
	s = new char[strlen(str)+1];
	strcpy(s, str);
}

B::B() 
{
	s = nullptr;
}

B::~B()
{
	delete[] s;
}

B& B::operator=(const B& b) // �� ������ �� ��� ������ b3 = b2;
{
	if(this == &b) 
		return *this;
	
	A::operator=(b); // ��������� ��� ������� ���-������������.
	delete[] s;
	s = new char[strlen(b.s)+1];
	strcpy(s, b.s);
	return *this;
}

B::B(const B& b) : A(b) /* �� ������ �� ��� ������ B b2(b1). �������� � ������������� ���������� ��� ������� ������. */
{
	s = new char[strlen(b.s)+1];
	strcpy(s, b.s);
}

void B::show() const 
{
	std::cout << s << '\n';
	A::show();
}

