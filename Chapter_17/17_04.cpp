#include <iostream> // ’σκηση 17.4

class B; /* Όπως στο παράδειγμα Κ.13.6 προσθέτουμε έναν ατελή ορισμό της κλάσης B, ο οποίος χρειάζεται για τη δήλωση της f() */  

class A
{
private:
	int data;
public:
	A(int i) {data = i;}
	friend int f(const A& a, const B& b);
};

class B
{
private:
	int data;
public:
	B(int i) {data = i;}
	friend int f(const A& a, const B& b);
};

int f(const A& a, const B& b)
{
	return a.data - b.data;
}

int main()
{
	A a(5);
	B b(3);
	std::cout << f(a, b) << '\n'; 
	return 0;
}

