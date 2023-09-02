#include <iostream> // ’σκηση 11.32

int a = 4; 

int main()
{
	if(a == 0)
		return 0;
	else
	{
		std::cout << a-- << ' ';
		main();
	}
	return 0;
}

