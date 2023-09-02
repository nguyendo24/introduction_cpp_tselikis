#include <iostream> // ’σκηση 18.6
#include <cstdlib>
using std::cout;

class Triangle
{
private:
	int a;
	int b;
	int c;
public:
	Triangle(int dim1, int dim2, int dim3);
	bool operator!=(const Triangle& t) const;
	int& operator[](int dim);
	void show() const;
};

Triangle::Triangle(int dim1, int dim2, int dim3) 
{
	a = dim1;
	b = dim2;
	c = dim3;
}

bool Triangle::operator!=(const Triangle& t) const
{
	if(a+b+c != t.a+t.b+t.c)
		return true;
	else
		return false;
}

int& Triangle::operator[](int dim) 
{
	if(dim == 0)
		return a;
	else if(dim == 1)
		return b;
	else if(dim == 2)
		return c;
	else
	{
		cout << "Error: Wrong index\n";
		exit(EXIT_FAILURE); // Τερματισμός προγράμματος.
	}
}

void Triangle::show() const
{
	cout << a << ' ' << b << ' ' << c << '\n';
}

int main()
{	
	Triangle t1(1, 2, 3), t2(4, 1, 1);
	
	if(t1 != t2) // if(t1.operator!=(t2))
		cout << "Different perimeters\n";
	else
		cout << "Same perimeters\n";

	t1[0] = 4; // t1.operator[](0);
	t1[1] = 5;
	t1[2] = 6;
	t1.show();
	return 0;
}

