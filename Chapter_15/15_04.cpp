#include <iostream> // ’σκηση 15.4

#define CNT_POS

int main()
{
	int cnt = 0;
	double num = 1;

	while(num != 0)
	{
		std::cout << "Enter number: ";
		std::cin >> num;
		#ifdef CNT_POS
			if(num > 0)
				cnt++;
		#else
			if(num < 0)
				cnt++;
		#endif
	}
	std::cout << cnt << '\n';
	return 0;
}

