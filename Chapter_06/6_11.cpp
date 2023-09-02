#include <iostream> // ’σκηση 6.11
int main()
{
	int i, j, k;

	for(i = 0; i < 2; i++)
	{
		std::cout << "? ";
		for(j = i+1; j; j--)
		{
			std::cout << "! ";
			for(k = i; k < j+1; k++)
				std::cout << "* ";
		}
	}
	return 0;
}

