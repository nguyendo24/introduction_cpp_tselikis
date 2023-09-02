#include <iostream> // ’σκηση 19.1 

class T
{
public:
	int a;
	T(int i) {a=i;}
	T(const T& t) {std::cout << t.a << ' ';}
};

void f(T p)
{
	p.a = 10;
}

int main()
{
	T *p1, *p2;

	p1 = new T(20);
	p2 = new T(30);

	T r(*p1);
	f(*p2);
      std::cout << '\n' << r.a << ' ' << p1->a << ' ' << p2->a << '\n';
	delete p1;
	delete p2;
	return 0;
}

