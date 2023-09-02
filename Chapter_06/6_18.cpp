#include <iostream> // ’σκηση 6.18 
#include <cmath> 
int main()
{
	int i, terms;
	double a, val, sum, final;
	const double pi = 3.14, accuracy = 0.001;

	terms = sum = 0;
	a = 1;
	i = 1;
	final = pi/4;
	while(1)
	{
		terms++;
		sum += a/i;
		if(fabs(sum-final) < accuracy)
			break;
		a = -a;
		i += 2;
	} 
	std::cout << "Sum: " << sum << ' ' << "Terms: " << terms << '\n';
	return 0;
}

