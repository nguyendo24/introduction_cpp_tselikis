#include <iostream> // ’σκηση 16.4

double* test(double *p1, double *p2); 
double& test(double& r1, double& r2); 

int main()
{
	double a = 1.2, b = 3.4;

	*test(&a, &b) = 5.6;
	std::cout << a << ' ' << b << '\n'; 

	test(a, b) = 7.8;
	std::cout << a << ' ' << b << '\n'; 
	return 0;
}

double* test(double *p1, double *p2)
{
	if(*p1 < *p2)
		return p1;
	else
		return p2;
}

double& test(double& r1, double& r2)
{
	if(r1 < r2)
		return r1;
	else
		return r2;
}

