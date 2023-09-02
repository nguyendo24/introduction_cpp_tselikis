#include <iostream> // ’σκηση 8.20
using std::cout;
using std::cin;

int main()
{
	int a, b, c, *p[3] = {&a, &b, &c};
	
	cout << "Enter length_a and length_b: ";
	cin >> *p[0] >> *p[1];
	do
	{
		cout << "Enter length_c: ";
		cin >> *p[2];
	} while((*p[2] <= *p[0]) || (*p[2] <= *p[1]));

	if((*p[0])*(*p[0]) + (*p[1])*(*p[1]) == (*p[2])*(*p[2]))
		cout << "Right triangle\n";
	else if((*p[0])*(*p[0]) + (*p[1])*(*p[1]) > (*p[2])*(*p[2]))
		cout << "Acute triangle\n";
	else
		cout << "Obtuse triangle\n";
	return 0;
}

