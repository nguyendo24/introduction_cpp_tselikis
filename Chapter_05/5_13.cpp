#include <iostream> // ’σκηση 5.13
int main()
{
	float grd;

	std::cout << "Enter grade: ";
	std::cin >> grd;
	std::cout << ((grd >= 7.5 && grd <= 10) ? "A" : (grd >= 5 && grd < 7.5) ? "B" : (grd >= 0 && grd < 5) ? "Next time" : "Grade should be within [0-10]") << '\n';
	return 0;
}

