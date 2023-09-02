#include <iostream> // ’σκηση 4.3 
int main()
{
	float cost, a;

	std::cout << "Enter water consumption: ";
	std::cin >> a;

	cost = (a > 5 && a <= 30)*(a-5)*1.2 + (a > 30)*((a-30)*1.5 + 25*1.2);
	std::cout << "Cost: " << cost << '\n';
	return 0;
}

