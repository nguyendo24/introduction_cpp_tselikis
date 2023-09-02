#include <iostream> // ’σκηση 11.9
#include <cmath> 

unsigned long long int sum_cube(int n); 
double find_root(unsigned long long int n);

int main()
{
	int num;

	std::cout << "Enter number: ";
	std::cin >> num;

	std::cout << find_root(sum_cube(num)) << ' ' << num*(num+1)/2 << '\n';	return 0;
} 
unsigned long long int sum_cube(int n)
{
	int i;
	unsigned long long int sum; 

	sum = 0;
	for(i = 1; i <= n; i++)
		sum += i*i*i;
	return sum;
}

double find_root(unsigned long long int n)
{
	double old_r, new_r;

	old_r = n/2.0;
	while(1) 
	{
		new_r = 0.5*(old_r + n/old_r);
		if(fabs(new_r - old_r) < 0.0001)
			break;
		old_r = new_r;
  	}
	return new_r;
}

