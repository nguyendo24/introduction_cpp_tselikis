#include <iostream> // ’σκηση 11.15

double *f(double ptr[]);

int main()
{
	int i;
	double a[8] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};

	std::cout << *f(f(f(a))) << '\n';
	for(i = 0; i < 8; i++)
		std::cout << a[i] << '\n';
	return 0;
}

double *f(double ptr[]) 
{
	(*ptr)++;
	return ptr+2;
}

