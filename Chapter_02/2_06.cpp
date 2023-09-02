#include <iostream> // ’σκηση 2.6
int main()
{
	int k;
	float i = 3.9, j = 1.2;
	
	k = i + (int)j;
	std::cout << k - (int)((int)i + j) << '\n';
	return 0;
}

