#include <iostream> // ’σκηση 22.1

void f(int num);

int main()
{
	int i;

	std::cout << "Enter number: ";
	std::cin >> i;

	try
	{
		f(i);
	}
	catch(int c)
	{
		std::cout << c << '\n';
	}
	return 0;
}

void f(int num)
{
	static int cnt = 0;

	cnt++;
	if(cnt == num)
		throw 10;
	f(num);
}

