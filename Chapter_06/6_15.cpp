#include <iostream> // ’σκηση 6.15 
int main()
{
	int i = 4, j = 3;

	while(i >> 1)
	{
		i--;
		while(!(j%i))
		{
			std::cout << "One ";
			j--;
			if(i == 1)
				break;			
		}
		j += 2;
	}
	std::cout << j << '\n';
	return 0;
}

