#include <iostream> // ’σκηση 6.7
int main()
{
	int i, num, an, an1, an2, an3;

	for(;;) 
	{
		std::cout << "Enter number [> 2]: ";
		std::cin >> num;
		if(num > 2)
			break; 
	}
	an1 = 3;
	an2 = 2;
	an3 = 1;
	for(i = 3; i <= num; i++)
	{
		an = 2*an1 - an2 + an3;
		an3 = an2;
		an2 = an1;
		an1 = an;
	}
	std::cout << "a[" << num << "] = " << an << '\n';
	return 0;
}

